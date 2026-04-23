import argparse
import base64
import importlib
import io
import json
import os
import sys
import time
from pathlib import Path

import numpy as np
import zmq
from PIL import Image

ARM_JOINT_ORDER = ("joint1", "joint2", "joint3", "joint4", "joint5", "joint6")
ARM_JOINT_LIMITS_RAD: dict[str, tuple[float, float]] = {
    "joint1": (-2.967, 2.967),
    "joint2": (-1.5708, 1.5708),
    "joint3": (-1.5708, 1.5708),
    "joint4": (-2.967, 2.967),
    "joint5": (-1.5708, 1.5708),
    "joint6": (-2.967, 2.967),
}

GRIPPER_JOINT_ORDER = ("hand_narrow_loop_joint", "hand_wide_loop_joint")

# Converted from 150 deg/s and 150 deg/s^2
DEFAULT_MAX_VEL_RAD_S = 2.61799
DEFAULT_MAX_ACC_RAD_S2 = 2.61799


class _ClassicMujocoRenderer:
    def __init__(self, mujoco_module, model, width: int, height: int):
        self._mujoco = mujoco_module
        self._model = model
        self._width = int(width)
        self._height = int(height)

        self._gl_context = self._mujoco.GLContext(self._width, self._height)
        self._gl_context.make_current()

        self._scene = self._mujoco.MjvScene(model, maxgeom=10000)
        self._camera = self._mujoco.MjvCamera()
        self._option = self._mujoco.MjvOption()
        self._perturb = self._mujoco.MjvPerturb()
        self._context = self._mujoco.MjrContext(model, self._mujoco.mjtFontScale.mjFONTSCALE_150)
        self._viewport = self._mujoco.MjrRect(0, 0, self._width, self._height)

        self._rgb = np.zeros((self._height, self._width, 3), dtype=np.uint8)
        self._depth = np.zeros((self._height, self._width), dtype=np.float32)

    def update_scene(self, data, camera: str) -> None:
        cam_id = self._mujoco.mj_name2id(self._model, self._mujoco.mjtObj.mjOBJ_CAMERA, camera)
        if cam_id < 0:
            raise ValueError(f"Camera not found in model: {camera}")

        self._camera.type = self._mujoco.mjtCamera.mjCAMERA_FIXED
        self._camera.fixedcamid = cam_id
        self._mujoco.mjv_updateScene(
            self._model,
            data,
            self._option,
            self._perturb,
            self._camera,
            self._mujoco.mjtCatBit.mjCAT_ALL,
            self._scene,
        )

    def render(self) -> np.ndarray:
        self._gl_context.make_current()
        self._mujoco.mjr_render(self._viewport, self._scene, self._context)
        self._mujoco.mjr_readPixels(self._rgb, self._depth, self._viewport, self._context)
        return np.flipud(self._rgb)

    def close(self) -> None:
        if hasattr(self, "_gl_context") and hasattr(self._gl_context, "free"):
            self._gl_context.free()


class TGArm620MujocoSim:
    def __init__(self, args: argparse.Namespace):
        self.args = args

        self._configure_mujoco_env(args)
        self._mujoco = self._import_mujoco(args.mujoco_gl)
        self._mujoco_viewer = self._import_mujoco_viewer()

        self._model_path = self._resolve_model_path(args.model_path)
        self._mesh_root = self._resolve_mesh_root(args.mesh_root, self._model_path)
        self.model = self._load_model(self._model_path, self._mesh_root)
        self.data = self._mujoco.MjData(self.model)

        self._control_hz = float(args.control_hz)
        self._max_vel = float(args.max_vel_rad_s)
        self._max_acc = float(args.max_acc_rad_s2)

        self._gripper_open_joint = {
            GRIPPER_JOINT_ORDER[0]: float(args.gripper_open_joint_1),
            GRIPPER_JOINT_ORDER[1]: float(args.gripper_open_joint_2),
        }
        self._gripper_close_joint = {
            GRIPPER_JOINT_ORDER[0]: float(args.gripper_close_joint_1),
            GRIPPER_JOINT_ORDER[1]: float(args.gripper_close_joint_2),
        }
        self._gripper_max_delta_rad = float(args.gripper_max_delta_rad)
        self._gripper_min_pos = float(args.gripper_min_pos)
        self._gripper_max_pos = float(args.gripper_max_pos)
        self._gripper_type = int(args.gripper_type)
        self._gripper_speed = float(args.gripper_speed)
        self._gripper_effort = float(args.gripper_effort)

        self._zmq_context = zmq.Context()
        self._cmd_socket = self._zmq_context.socket(zmq.PULL)
        self._cmd_socket.setsockopt(zmq.CONFLATE, 1)
        self._cmd_socket.setsockopt(zmq.LINGER, 0)
        self._cmd_socket.bind(f"tcp://*:{args.cmd_port}")

        self._state_socket = self._zmq_context.socket(zmq.PUB)
        self._state_socket.setsockopt(zmq.SNDHWM, 10)
        self._state_socket.setsockopt(zmq.LINGER, 0)
        self._state_socket.bind(f"tcp://*:{args.state_port}")

        self._camera_configs = {
            "front": {
                "camera_name": str(args.front_camera_name),
                "port": int(args.front_camera_port),
                "fps": float(args.front_camera_fps),
                "width": int(args.front_camera_width),
                "height": int(args.front_camera_height),
                "jpeg_quality": int(args.front_camera_jpeg_quality),
            },
            "side": {
                "camera_name": str(args.side_camera_name),
                "port": int(args.side_camera_port),
                "fps": float(args.side_camera_fps),
                "width": int(args.side_camera_width),
                "height": int(args.side_camera_height),
                "jpeg_quality": int(args.side_camera_jpeg_quality),
            },
        }

        self._camera_publishers: dict[str, zmq.Socket] = {}
        self._camera_renderers: dict[str, object] = {}
        self._next_camera_publish_time: dict[str, float] = {}

        if args.enable_cameras:
            self._init_cameras()

        self._joint_qpos_addr = {joint: self._joint_qpos_address(joint) for joint in ARM_JOINT_ORDER}
        self._gripper_qpos_addr = {joint: self._joint_qpos_address(joint) for joint in GRIPPER_JOINT_ORDER}

        self._actuator_id = {
            "joint1": self._actuator_id_by_name("act_joint1"),
            "joint2": self._actuator_id_by_name("act_joint2"),
            "joint3": self._actuator_id_by_name("act_joint3"),
            "joint4": self._actuator_id_by_name("act_joint4"),
            "joint5": self._actuator_id_by_name("act_joint5"),
            "joint6": self._actuator_id_by_name("act_joint6"),
            "hand_narrow_loop_joint": self._actuator_id_by_name("act_gripper_narrow"),
            "hand_wide_loop_joint": self._actuator_id_by_name("act_gripper_wide"),
        }

        self._arm_joint_state = {joint: self._read_joint_pos(joint) for joint in ARM_JOINT_ORDER}
        self._target_arm_joint_state = self._arm_joint_state.copy()
        self._last_applied_arm_joint_state = self._arm_joint_state.copy()
        self._last_arm_velocity = {joint: 0.0 for joint in ARM_JOINT_ORDER}

        self._gripper_joint_state = {joint: self._read_joint_pos(joint) for joint in GRIPPER_JOINT_ORDER}
        self._last_applied_gripper_joint_state = self._gripper_joint_state.copy()
        self._target_gripper_pos = self._gripper_joints_to_pos(self._gripper_joint_state)

        self._sim_dt = float(self.model.opt.timestep)
        self._steps_per_cycle = max(1, int(round((1.0 / self._control_hz) / self._sim_dt)))

        self._last_loop_time = time.monotonic()
        print(
            "TG MuJoCo sim started. "
            f"model={self._model_path}, cmd_port={args.cmd_port}, state_port={args.state_port}, "
            f"hz={self._control_hz:.1f}, sim_dt={self._sim_dt:.4f}, steps_per_cycle={self._steps_per_cycle}, "
            f"gripper_type={self._gripper_type}, speed={self._gripper_speed:.1f}, effort={self._gripper_effort:.1f}, "
            f"mesh_root={self._mesh_root}",
            flush=True,
        )

    @staticmethod
    def _configure_mujoco_env(args: argparse.Namespace) -> None:
        if args.mujoco_gl:
            os.environ.setdefault("MUJOCO_GL", str(args.mujoco_gl))

        if args.mujoco_home:
            home = Path(args.mujoco_home).expanduser().resolve()
            if home.exists():
                os.environ.setdefault("MUJOCO_HOME", str(home))
                ld_paths: list[str] = []
                for subdir in ("bin", "lib"):
                    candidate = home / subdir
                    if candidate.exists():
                        ld_paths.append(str(candidate))
                if ld_paths:
                    current = os.environ.get("LD_LIBRARY_PATH", "")
                    merged = ":".join(ld_paths + ([current] if current else []))
                    os.environ["LD_LIBRARY_PATH"] = merged

    @staticmethod
    def _import_mujoco(preferred_backend: str):
        tried_backends: list[str] = []
        for backend in (preferred_backend, "egl", "osmesa", "glfw"):
            if backend and backend not in tried_backends:
                tried_backends.append(backend)

        last_exc: Exception | None = None
        for backend in tried_backends:
            os.environ["MUJOCO_GL"] = backend
            try:
                # Clear partially imported modules after a failed backend init.
                for mod in list(sys.modules):
                    if mod == "mujoco" or mod.startswith("mujoco."):
                        del sys.modules[mod]
                importlib.invalidate_caches()

                import mujoco

                print(f"[INFO] MuJoCo GL backend: {backend}", flush=True)
                return mujoco
            except Exception as exc:
                last_exc = exc
                print(f"[WARN] MuJoCo backend '{backend}' failed: {exc}", flush=True)

        raise RuntimeError(
            "Failed to initialize mujoco runtime on all attempted GL backends "
            f"{tried_backends}. Please verify OpenGL/EGL/OSMesa runtime setup."
        ) from last_exc

    @staticmethod
    def _import_mujoco_viewer():
        try:
            import mujoco.viewer

            return mujoco.viewer
        except Exception:
            return None

    @staticmethod
    def _resolve_model_path(model_path_arg: str | None) -> Path:
        if model_path_arg:
            path = Path(model_path_arg).expanduser().resolve()
            if not path.exists():
                raise FileNotFoundError(f"MuJoCo model path not found: {path}")
            return path

        try:
            from ament_index_python.packages import get_package_share_directory

            share_dir = Path(get_package_share_directory("tg_lerobot_bridge"))
            path = share_dir / "models" / "arm620_omnipicker_mujoco.xml"
            if path.exists():
                return path
        except Exception:
            pass

        local_fallback = Path(__file__).resolve().parents[1] / "models" / "arm620_omnipicker_mujoco.xml"
        if local_fallback.exists():
            return local_fallback

        raise FileNotFoundError("Could not locate arm620_omnipicker_mujoco.xml")

    @staticmethod
    def _resolve_mesh_root(mesh_root_arg: str | None, model_path: Path) -> Path:
        if mesh_root_arg:
            path = Path(mesh_root_arg).expanduser().resolve()
            if not path.exists():
                raise FileNotFoundError(f"Mesh root path not found: {path}")
            return path

        candidates: list[Path] = []
        try:
            from ament_index_python.packages import get_package_share_directory

            candidates.append(Path(get_package_share_directory("robot_description")) / "meshes")
        except Exception:
            pass

        # Common install layout:
        # <ws>/install/tg_lerobot_bridge/share/tg_lerobot_bridge/models/model.xml
        for parent in model_path.parents:
            candidates.append(parent / "robot_description" / "share" / "robot_description" / "meshes")
            candidates.append(parent / "src" / "robot_description" / "meshes")

        for candidate in candidates:
            if candidate.exists():
                return candidate.resolve()

        raise FileNotFoundError(
            "Could not locate robot_description meshes directory. "
            "Please pass --mesh-root explicitly."
        )

    def _load_model(self, model_path: Path, mesh_root: Path):
        xml = model_path.read_text(encoding="utf-8")
        mesh_token = "__ROBOT_DESCRIPTION_MESH_ROOT__"
        if mesh_token in xml:
            xml = xml.replace(mesh_token, str(mesh_root).replace("\\", "/"))
            return self._mujoco.MjModel.from_xml_string(xml)
        return self._mujoco.MjModel.from_xml_path(str(model_path))

    @staticmethod
    def _clamp(value: float, low: float, high: float) -> float:
        return max(low, min(high, value))

    def _joint_qpos_address(self, joint_name: str) -> int:
        j_id = self._mujoco.mj_name2id(self.model, self._mujoco.mjtObj.mjOBJ_JOINT, joint_name)
        if j_id < 0:
            raise ValueError(f"Joint not found in model: {joint_name}")
        return int(self.model.jnt_qposadr[j_id])

    def _actuator_id_by_name(self, actuator_name: str) -> int:
        act_id = self._mujoco.mj_name2id(self.model, self._mujoco.mjtObj.mjOBJ_ACTUATOR, actuator_name)
        if act_id < 0:
            raise ValueError(f"Actuator not found in model: {actuator_name}")
        return act_id

    def _read_joint_pos(self, joint_name: str) -> float:
        qpos_addr = self._joint_qpos_address(joint_name)
        return float(self.data.qpos[qpos_addr])

    def _refresh_joint_state(self) -> None:
        for joint in ARM_JOINT_ORDER:
            self._arm_joint_state[joint] = float(self.data.qpos[self._joint_qpos_addr[joint]])
        for joint in GRIPPER_JOINT_ORDER:
            self._gripper_joint_state[joint] = float(self.data.qpos[self._gripper_qpos_addr[joint]])

    def _gripper_pos_to_joint_targets(self, gripper_pos: float) -> dict[str, float]:
        pos = self._clamp(gripper_pos, self._gripper_min_pos, self._gripper_max_pos)
        span = max(self._gripper_max_pos - self._gripper_min_pos, 1e-6)
        ratio = (pos - self._gripper_min_pos) / span

        target: dict[str, float] = {}
        for joint in GRIPPER_JOINT_ORDER:
            close_angle = self._gripper_close_joint[joint]
            open_angle = self._gripper_open_joint[joint]
            target[joint] = close_angle + ratio * (open_angle - close_angle)
        return target

    def _gripper_joints_to_pos(self, gripper_joint_state: dict[str, float]) -> float:
        span = max(self._gripper_max_pos - self._gripper_min_pos, 1e-6)
        estimates: list[float] = []

        for joint in GRIPPER_JOINT_ORDER:
            close_angle = self._gripper_close_joint[joint]
            open_angle = self._gripper_open_joint[joint]
            den = open_angle - close_angle
            if abs(den) < 1e-6:
                continue
            ratio = (gripper_joint_state[joint] - close_angle) / den
            pos = self._gripper_min_pos + ratio * span
            estimates.append(self._clamp(pos, self._gripper_min_pos, self._gripper_max_pos))

        if not estimates:
            return self._gripper_min_pos
        return sum(estimates) / len(estimates)

    def _drain_latest_command(self) -> None:
        latest_raw: str | None = None
        while True:
            try:
                latest_raw = self._cmd_socket.recv_string(flags=zmq.NOBLOCK)
            except zmq.Again:
                break

        if latest_raw is None:
            return

        try:
            payload = json.loads(latest_raw)
        except json.JSONDecodeError:
            print("[WARN] Received malformed command JSON; ignoring packet", flush=True)
            return

        if not isinstance(payload, dict):
            print("[WARN] Received non-dict command payload; ignoring packet", flush=True)
            return

        for joint in ARM_JOINT_ORDER:
            key = f"{joint}.pos"
            if key not in payload:
                continue
            try:
                self._target_arm_joint_state[joint] = float(payload[key])
            except (TypeError, ValueError):
                print(f"[WARN] Invalid command value for {key}; keeping previous target", flush=True)

        if "gripper.pos" in payload:
            try:
                requested = float(payload["gripper.pos"])
                self._target_gripper_pos = self._clamp(
                    requested,
                    self._gripper_min_pos,
                    self._gripper_max_pos,
                )
            except (TypeError, ValueError):
                print("[WARN] Invalid command value for gripper.pos", flush=True)

    def _compute_arm_joint_command(self, dt_s: float) -> dict[str, float]:
        safe_dt = max(dt_s, 1e-3)

        target = self._target_arm_joint_state.copy()
        prev_q = self._last_applied_arm_joint_state.copy()
        prev_v = self._last_arm_velocity.copy()

        command: dict[str, float] = {}
        next_velocity: dict[str, float] = {}

        for joint in ARM_JOINT_ORDER:
            low, high = ARM_JOINT_LIMITS_RAD[joint]
            q_target = self._clamp(target[joint], low, high)

            q_prev = prev_q[joint]
            v_prev = prev_v[joint]

            v_desired = (q_target - q_prev) / safe_dt
            v_desired = self._clamp(v_desired, -self._max_vel, self._max_vel)

            dv_limit = self._max_acc * safe_dt
            v_next = self._clamp(v_desired, v_prev - dv_limit, v_prev + dv_limit)

            step = v_next * safe_dt
            remaining = q_target - q_prev
            if abs(step) > abs(remaining):
                step = remaining
                v_next = step / safe_dt

            q_next = self._clamp(q_prev + step, low, high)
            if (q_next <= low and v_next < 0) or (q_next >= high and v_next > 0):
                v_next = 0.0

            command[joint] = q_next
            next_velocity[joint] = v_next

        self._last_applied_arm_joint_state = command.copy()
        self._last_arm_velocity = next_velocity

        return command

    def _compute_gripper_command(self) -> dict[str, float]:
        target_pos = self._target_gripper_pos
        prev_q = self._last_applied_gripper_joint_state.copy()

        target_q = self._gripper_pos_to_joint_targets(target_pos)
        command: dict[str, float] = {}
        for joint in GRIPPER_JOINT_ORDER:
            prev = prev_q[joint]
            tgt = target_q[joint]
            q_next = self._clamp(tgt, prev - self._gripper_max_delta_rad, prev + self._gripper_max_delta_rad)
            command[joint] = q_next

        self._last_applied_gripper_joint_state = command.copy()
        return command

    def _apply_joint_commands(self, arm_command: dict[str, float], gripper_command: dict[str, float]) -> None:
        for joint in ARM_JOINT_ORDER:
            act_id = self._actuator_id[joint]
            self.data.ctrl[act_id] = arm_command[joint]

        for joint in GRIPPER_JOINT_ORDER:
            act_id = self._actuator_id[joint]
            self.data.ctrl[act_id] = gripper_command[joint]

    def _build_state_payload(self) -> dict[str, float]:
        payload: dict[str, float] = {f"{joint}.pos": self._arm_joint_state[joint] for joint in ARM_JOINT_ORDER}
        payload["gripper.pos"] = self._gripper_joints_to_pos(self._gripper_joint_state)
        payload["timestamp"] = time.time()
        return payload

    def _publish_state(self) -> None:
        payload = self._build_state_payload()
        try:
            self._state_socket.send_string(json.dumps(payload), flags=zmq.NOBLOCK)
        except zmq.Again:
            pass

    def _init_cameras(self) -> None:
        for key, cfg in self._camera_configs.items():
            socket = self._zmq_context.socket(zmq.PUB)
            socket.setsockopt(zmq.SNDHWM, 20)
            socket.setsockopt(zmq.LINGER, 0)
            socket.bind(f"tcp://*:{cfg['port']}")
            self._camera_publishers[key] = socket
            self._next_camera_publish_time[key] = time.monotonic()

            try:
                if hasattr(self._mujoco, "Renderer"):
                    renderer = self._mujoco.Renderer(
                        self.model,
                        height=cfg["height"],
                        width=cfg["width"],
                    )
                else:
                    renderer = _ClassicMujocoRenderer(
                        self._mujoco,
                        self.model,
                        width=cfg["width"],
                        height=cfg["height"],
                    )
                self._camera_renderers[key] = renderer
                print(
                    f"Camera '{cfg['camera_name']}' started on tcp://*:{cfg['port']} @ {cfg['fps']:.1f}fps",
                    flush=True,
                )
            except Exception as exc:
                self._camera_renderers[key] = None
                print(
                    f"[WARN] Failed to initialize renderer for camera {cfg['camera_name']}: {exc}. "
                    "This camera stream will publish blank images.",
                    flush=True,
                )

    @staticmethod
    def _encode_jpeg_base64(image_rgb: np.ndarray, quality: int) -> str:
        img = Image.fromarray(image_rgb, mode="RGB")
        buf = io.BytesIO()
        img.save(buf, format="JPEG", quality=int(quality))
        return base64.b64encode(buf.getvalue()).decode("utf-8")

    def _render_camera(self, key: str) -> np.ndarray:
        cfg = self._camera_configs[key]
        renderer = self._camera_renderers.get(key)
        if renderer is None:
            return np.zeros((cfg["height"], cfg["width"], 3), dtype=np.uint8)

        renderer.update_scene(self.data, camera=cfg["camera_name"])
        frame = renderer.render()
        if frame.dtype != np.uint8:
            frame = np.clip(frame, 0, 255).astype(np.uint8)
        return frame

    def _publish_cameras(self, now: float) -> None:
        for key, cfg in self._camera_configs.items():
            interval = 1.0 / max(cfg["fps"], 1.0)
            if now < self._next_camera_publish_time[key]:
                continue

            frame = self._render_camera(key)
            try:
                encoded = self._encode_jpeg_base64(frame, cfg["jpeg_quality"])
            except Exception as exc:
                print(f"[WARN] Camera encode failed for {cfg['camera_name']}: {exc}", flush=True)
                self._next_camera_publish_time[key] = now + interval
                continue

            payload = {
                "timestamps": {cfg["camera_name"]: time.time()},
                "images": {cfg["camera_name"]: encoded},
            }

            try:
                self._camera_publishers[key].send_string(json.dumps(payload), flags=zmq.NOBLOCK)
            except zmq.Again:
                pass

            self._next_camera_publish_time[key] = now + interval

    def run(self) -> None:
        period_s = 1.0 / max(self._control_hz, 1.0)

        try:
            if self.args.enable_viewer:
                if self._mujoco_viewer is None:
                    raise RuntimeError("mujoco.viewer is unavailable in this environment.")
                with self._mujoco_viewer.launch_passive(self.model, self.data) as viewer:
                    print("[INFO] MuJoCo viewer enabled. Close the viewer window to stop simulation.", flush=True)
                    while viewer.is_running():
                        self._run_one_cycle(period_s)
                        viewer.sync()
            else:
                while True:
                    self._run_one_cycle(period_s)
        except KeyboardInterrupt:
            print("TG MuJoCo sim interrupted, shutting down.", flush=True)
        finally:
            self.close()

    def _run_one_cycle(self, period_s: float) -> None:
        start = time.monotonic()
        dt_s = start - self._last_loop_time
        self._last_loop_time = start

        self._drain_latest_command()

        arm_command = self._compute_arm_joint_command(dt_s)
        gripper_command = self._compute_gripper_command()
        self._apply_joint_commands(arm_command, gripper_command)

        for _ in range(self._steps_per_cycle):
            self._mujoco.mj_step(self.model, self.data)

        self._refresh_joint_state()
        self._publish_state()

        if self.args.enable_cameras:
            self._publish_cameras(start)

        elapsed = time.monotonic() - start
        sleep_s = max(0.0, period_s - elapsed)
        if sleep_s > 0:
            time.sleep(sleep_s)

    def close(self) -> None:
        for renderer in self._camera_renderers.values():
            if renderer is not None:
                try:
                    renderer.close()
                except Exception:
                    pass

        for socket in self._camera_publishers.values():
            socket.close()

        self._cmd_socket.close()
        self._state_socket.close()
        self._zmq_context.term()


def build_arg_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(description="TG arm620 MuJoCo simulation bridge for LeRobot")

    def _str2bool(value: str) -> bool:
        return str(value).strip().lower() in ("1", "true", "yes", "on")

    parser.add_argument("--model-path", type=str, default=None)
    parser.add_argument("--mesh-root", type=str, default="")
    parser.add_argument("--mujoco-home", type=str, default="/home/holms/Projects/mujoco/mujoco-3.3.0")
    parser.add_argument("--mujoco-gl", type=str, default=os.environ.get("MUJOCO_GL", "egl"))

    parser.add_argument("--cmd-port", type=int, default=6001)
    parser.add_argument("--state-port", type=int, default=6002)
    parser.add_argument("--control-hz", type=float, default=30.0)

    parser.add_argument("--max-vel-rad-s", type=float, default=DEFAULT_MAX_VEL_RAD_S)
    parser.add_argument("--max-acc-rad-s2", type=float, default=DEFAULT_MAX_ACC_RAD_S2)

    parser.add_argument("--gripper-open-joint-1", type=float, default=0.025)
    parser.add_argument("--gripper-close-joint-1", type=float, default=0.0)
    parser.add_argument("--gripper-open-joint-2", type=float, default=0.025)
    parser.add_argument("--gripper-close-joint-2", type=float, default=0.0)
    parser.add_argument("--gripper-max-delta-rad", type=float, default=0.08)
    parser.add_argument("--gripper-min-pos", type=float, default=0.0)
    parser.add_argument("--gripper-max-pos", type=float, default=100.0)
    parser.add_argument("--gripper-type", type=int, default=1)
    parser.add_argument("--gripper-speed", type=float, default=40.0)
    parser.add_argument("--gripper-effort", type=float, default=100.0)

    parser.add_argument("--enable-cameras", dest="enable_cameras", action="store_true")
    parser.add_argument("--disable-cameras", dest="enable_cameras", action="store_false")
    parser.set_defaults(enable_cameras=True)
    parser.add_argument("--viewer", type=_str2bool, default=False)

    parser.add_argument("--front-camera-name", type=str, default="front_camera")
    parser.add_argument("--front-camera-port", type=int, default=5555)
    parser.add_argument("--front-camera-fps", type=float, default=30.0)
    parser.add_argument("--front-camera-width", type=int, default=640)
    parser.add_argument("--front-camera-height", type=int, default=480)
    parser.add_argument("--front-camera-jpeg-quality", type=int, default=80)

    parser.add_argument("--side-camera-name", type=str, default="side_front_camera")
    parser.add_argument("--side-camera-port", type=int, default=5556)
    parser.add_argument("--side-camera-fps", type=float, default=30.0)
    parser.add_argument("--side-camera-width", type=int, default=640)
    parser.add_argument("--side-camera-height", type=int, default=480)
    parser.add_argument("--side-camera-jpeg-quality", type=int, default=80)

    return parser


def main() -> None:
    parser = build_arg_parser()
    args, unknown = parser.parse_known_args()
    if unknown:
        print(f"[INFO] Ignoring extra CLI args: {unknown}", flush=True)

    args.enable_viewer = bool(args.viewer)

    sim = TGArm620MujocoSim(args)
    sim.run()


if __name__ == "__main__":
    main()
