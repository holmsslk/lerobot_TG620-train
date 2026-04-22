import json
import threading
import time

import rclpy
import zmq
from rcl_interfaces.msg import ParameterDescriptor
from rclpy.node import Node
from sensor_msgs.msg import JointState
from std_msgs.msg import Float64MultiArray

ARM_JOINT_ORDER = ("joint1", "joint2", "joint3", "joint4", "joint5", "joint6")
ARM_JOINT_LIMITS_RAD: dict[str, tuple[float, float]] = {
    "joint1": (-2.967, 2.967),
    "joint2": (-1.5708, 1.5708),
    "joint3": (-1.5708, 1.5708),
    "joint4": (-2.967, 2.967),
    "joint5": (-1.5708, 1.5708),
    "joint6": (-2.967, 2.967),
}

# Converted from 150 deg/s and 150 deg/s^2
DEFAULT_MAX_VEL_RAD_S = 2.61799
DEFAULT_MAX_ACC_RAD_S2 = 2.61799


class TGArm620SimControlBridge(Node):
    def __init__(self):
        super().__init__("tg_arm620_sim_control_bridge")

        dyn = ParameterDescriptor(dynamic_typing=True)
        self.declare_parameter("cmd_port", 6001, dyn)
        self.declare_parameter("state_port", 6002, dyn)
        self.declare_parameter("control_hz", 30.0, dyn)
        self.declare_parameter("max_vel_rad_s", DEFAULT_MAX_VEL_RAD_S, dyn)
        self.declare_parameter("max_acc_rad_s2", DEFAULT_MAX_ACC_RAD_S2, dyn)
        self.declare_parameter("command_topic", "/arm_position_controller/commands", dyn)
        self.declare_parameter("joint_state_topic", "/joint_states", dyn)

        self.declare_parameter("gripper_command_topic", "/gripper_position_controller/commands", dyn)
        self.declare_parameter("gripper_joint_1", "hand_narrow_loop_joint", dyn)
        self.declare_parameter("gripper_joint_2", "hand_wide_loop_joint", dyn)
        self.declare_parameter("gripper_open_joint_1", -0.75, dyn)
        self.declare_parameter("gripper_close_joint_1", 0.15, dyn)
        self.declare_parameter("gripper_open_joint_2", 0.75, dyn)
        self.declare_parameter("gripper_close_joint_2", -0.15, dyn)
        self.declare_parameter("gripper_max_delta_rad", 0.08, dyn)
        self.declare_parameter("gripper_min_pos", 0.0, dyn)
        self.declare_parameter("gripper_max_pos", 100.0, dyn)
        self.declare_parameter("gripper_type", 1, dyn)
        self.declare_parameter("gripper_speed", 40.0, dyn)
        self.declare_parameter("gripper_effort", 100.0, dyn)

        self._cmd_port = int(self.get_parameter("cmd_port").value)
        self._state_port = int(self.get_parameter("state_port").value)
        self._control_hz = float(self.get_parameter("control_hz").value)
        self._max_vel = float(self.get_parameter("max_vel_rad_s").value)
        self._max_acc = float(self.get_parameter("max_acc_rad_s2").value)
        self._command_topic = str(self.get_parameter("command_topic").value)
        self._joint_state_topic = str(self.get_parameter("joint_state_topic").value)

        self._gripper_command_topic = str(self.get_parameter("gripper_command_topic").value)
        self._gripper_joint_order = (
            str(self.get_parameter("gripper_joint_1").value),
            str(self.get_parameter("gripper_joint_2").value),
        )
        self._gripper_open_joint = {
            self._gripper_joint_order[0]: float(self.get_parameter("gripper_open_joint_1").value),
            self._gripper_joint_order[1]: float(self.get_parameter("gripper_open_joint_2").value),
        }
        self._gripper_close_joint = {
            self._gripper_joint_order[0]: float(self.get_parameter("gripper_close_joint_1").value),
            self._gripper_joint_order[1]: float(self.get_parameter("gripper_close_joint_2").value),
        }
        self._gripper_max_delta_rad = float(self.get_parameter("gripper_max_delta_rad").value)
        self._gripper_min_pos = float(self.get_parameter("gripper_min_pos").value)
        self._gripper_max_pos = float(self.get_parameter("gripper_max_pos").value)
        self._gripper_type = int(self.get_parameter("gripper_type").value)
        self._gripper_speed = float(self.get_parameter("gripper_speed").value)
        self._gripper_effort = float(self.get_parameter("gripper_effort").value)

        self._lock = threading.Lock()
        self._has_joint_state = False
        self._arm_joint_state = {joint: 0.0 for joint in ARM_JOINT_ORDER}
        self._target_arm_joint_state = self._arm_joint_state.copy()
        self._last_applied_arm_joint_state = self._arm_joint_state.copy()
        self._last_arm_velocity = {joint: 0.0 for joint in ARM_JOINT_ORDER}
        self._gripper_joint_state = {joint: 0.0 for joint in self._gripper_joint_order}
        self._last_applied_gripper_joint_state = self._gripper_joint_state.copy()
        self._target_gripper_pos = self._gripper_min_pos
        self._latest_gripper_pos = self._gripper_min_pos
        self._last_loop_time = time.monotonic()

        self._joint_sub = self.create_subscription(
            JointState, self._joint_state_topic, self._on_joint_state, 10
        )
        self._arm_cmd_pub = self.create_publisher(Float64MultiArray, self._command_topic, 10)
        self._gripper_cmd_pub = self.create_publisher(Float64MultiArray, self._gripper_command_topic, 10)

        self._zmq_context = zmq.Context()
        self._cmd_socket = self._zmq_context.socket(zmq.PULL)
        self._cmd_socket.setsockopt(zmq.CONFLATE, 1)
        self._cmd_socket.setsockopt(zmq.LINGER, 0)
        self._cmd_socket.bind(f"tcp://*:{self._cmd_port}")

        self._state_socket = self._zmq_context.socket(zmq.PUB)
        self._state_socket.setsockopt(zmq.SNDHWM, 10)
        self._state_socket.setsockopt(zmq.LINGER, 0)
        self._state_socket.bind(f"tcp://*:{self._state_port}")

        period_s = 1.0 / max(self._control_hz, 1.0)
        self._timer = self.create_timer(period_s, self._on_timer)

        self.get_logger().info(
            "TG sim bridge started. "
            f"cmd_port={self._cmd_port}, state_port={self._state_port}, hz={self._control_hz:.1f}, "
            f"arm_cmd_topic={self._command_topic}, gripper_cmd_topic={self._gripper_command_topic}, "
            f"gripper_type={self._gripper_type}, speed={self._gripper_speed:.1f}, effort={self._gripper_effort:.1f}"
        )

    @staticmethod
    def _clamp(value: float, low: float, high: float) -> float:
        return max(low, min(high, value))

    def _gripper_pos_to_joint_targets(self, gripper_pos: float) -> dict[str, float]:
        pos = self._clamp(gripper_pos, self._gripper_min_pos, self._gripper_max_pos)
        span = max(self._gripper_max_pos - self._gripper_min_pos, 1e-6)
        ratio = (pos - self._gripper_min_pos) / span

        target: dict[str, float] = {}
        for joint in self._gripper_joint_order:
            close_angle = self._gripper_close_joint[joint]
            open_angle = self._gripper_open_joint[joint]
            target[joint] = close_angle + ratio * (open_angle - close_angle)
        return target

    def _gripper_joints_to_pos(self, gripper_joint_state: dict[str, float]) -> float:
        span = max(self._gripper_max_pos - self._gripper_min_pos, 1e-6)
        estimates: list[float] = []

        for joint in self._gripper_joint_order:
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

    def _on_joint_state(self, msg: JointState) -> None:
        name_to_pos = {name: pos for name, pos in zip(msg.name, msg.position, strict=False)}
        with self._lock:
            for joint in ARM_JOINT_ORDER:
                if joint in name_to_pos:
                    self._arm_joint_state[joint] = float(name_to_pos[joint])

            for joint in self._gripper_joint_order:
                if joint in name_to_pos:
                    self._gripper_joint_state[joint] = float(name_to_pos[joint])

            self._latest_gripper_pos = self._gripper_joints_to_pos(self._gripper_joint_state)
            if not self._has_joint_state:
                self._target_arm_joint_state = self._arm_joint_state.copy()
                self._last_applied_arm_joint_state = self._arm_joint_state.copy()
                self._last_applied_gripper_joint_state = self._gripper_joint_state.copy()
                self._target_gripper_pos = self._latest_gripper_pos
                self._has_joint_state = True

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
            self.get_logger().warning("Received malformed command JSON; ignoring packet")
            return

        if not isinstance(payload, dict):
            self.get_logger().warning("Received non-dict command payload; ignoring packet")
            return

        with self._lock:
            for joint in ARM_JOINT_ORDER:
                key = f"{joint}.pos"
                if key not in payload:
                    continue
                try:
                    self._target_arm_joint_state[joint] = float(payload[key])
                except (TypeError, ValueError):
                    self.get_logger().warning(f"Invalid command value for {key}, keeping previous target")

            if "gripper.pos" in payload:
                try:
                    requested = float(payload["gripper.pos"])
                    self._target_gripper_pos = self._clamp(
                        requested, self._gripper_min_pos, self._gripper_max_pos
                    )
                except (TypeError, ValueError):
                    self.get_logger().warning("Invalid command value for gripper.pos")

    def _compute_arm_joint_command(self, dt_s: float) -> dict[str, float]:
        safe_dt = max(dt_s, 1e-3)

        with self._lock:
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

        with self._lock:
            self._last_applied_arm_joint_state = command.copy()
            self._last_arm_velocity = next_velocity

        return command

    def _compute_gripper_command(self) -> dict[str, float]:
        with self._lock:
            target_pos = self._target_gripper_pos
            prev_q = self._last_applied_gripper_joint_state.copy()

        target_q = self._gripper_pos_to_joint_targets(target_pos)
        command: dict[str, float] = {}
        for joint in self._gripper_joint_order:
            prev = prev_q[joint]
            tgt = target_q[joint]
            q_next = self._clamp(tgt, prev - self._gripper_max_delta_rad, prev + self._gripper_max_delta_rad)
            command[joint] = q_next

        with self._lock:
            self._last_applied_gripper_joint_state = command.copy()

        return command

    def _publish_arm_joint_command(self, command: dict[str, float]) -> None:
        msg = Float64MultiArray()
        msg.data = [command[joint] for joint in ARM_JOINT_ORDER]
        self._arm_cmd_pub.publish(msg)

    def _publish_gripper_command(self, command: dict[str, float]) -> None:
        msg = Float64MultiArray()
        msg.data = [command[joint] for joint in self._gripper_joint_order]
        self._gripper_cmd_pub.publish(msg)

    def _build_state_payload(self) -> dict[str, float]:
        with self._lock:
            arm_source = self._arm_joint_state if self._has_joint_state else self._last_applied_arm_joint_state
            gripper_source = (
                self._gripper_joint_state
                if self._has_joint_state
                else self._last_applied_gripper_joint_state
            )

        payload: dict[str, float] = {f"{joint}.pos": arm_source[joint] for joint in ARM_JOINT_ORDER}
        payload["gripper.pos"] = self._gripper_joints_to_pos(gripper_source)
        payload["timestamp"] = time.time()
        return payload

    def _on_timer(self) -> None:
        now = time.monotonic()
        dt_s = now - self._last_loop_time
        self._last_loop_time = now

        self._drain_latest_command()
        arm_command = self._compute_arm_joint_command(dt_s)
        gripper_command = self._compute_gripper_command()
        self._publish_arm_joint_command(arm_command)
        self._publish_gripper_command(gripper_command)

        state_payload = self._build_state_payload()
        try:
            self._state_socket.send_string(json.dumps(state_payload), flags=zmq.NOBLOCK)
        except zmq.Again:
            pass

    def destroy_node(self) -> bool:
        self._timer.cancel()

        if getattr(self, "_cmd_socket", None) is not None:
            self._cmd_socket.close()
        if getattr(self, "_state_socket", None) is not None:
            self._state_socket.close()
        if getattr(self, "_zmq_context", None) is not None:
            self._zmq_context.term()

        return super().destroy_node()


def main(args=None) -> None:
    rclpy.init(args=args)
    node = TGArm620SimControlBridge()

    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        if rclpy.ok():
            rclpy.shutdown()


if __name__ == "__main__":
    main()
