import json
import time
from pathlib import Path

import rclpy
from rcl_interfaces.msg import ParameterDescriptor
from rclpy.node import Node
from sensor_msgs.msg import JointState
from std_msgs.msg import Float64MultiArray


class TGArm620GripperScan(Node):
    def __init__(self):
        super().__init__("tg_arm620_gripper_scan")
        dyn = ParameterDescriptor(dynamic_typing=True)

        self.declare_parameter("command_topic", "/gripper_position_controller/commands", dyn)
        self.declare_parameter("joint_state_topic", "/joint_states", dyn)
        self.declare_parameter("joint_1", "hand_narrow_loop_joint", dyn)
        self.declare_parameter("joint_2", "hand_wide_loop_joint", dyn)
        self.declare_parameter("min_angle", -1.0, dyn)
        self.declare_parameter("max_angle", 1.0, dyn)
        self.declare_parameter("step", 0.05, dyn)
        self.declare_parameter("dwell_s", 0.35, dyn)
        self.declare_parameter("output_file", "", dyn)

        self._command_topic = str(self.get_parameter("command_topic").value)
        self._joint_state_topic = str(self.get_parameter("joint_state_topic").value)
        self._joint_1 = str(self.get_parameter("joint_1").value)
        self._joint_2 = str(self.get_parameter("joint_2").value)
        self._min_angle = float(self.get_parameter("min_angle").value)
        self._max_angle = float(self.get_parameter("max_angle").value)
        self._step = abs(float(self.get_parameter("step").value))
        self._dwell_s = float(self.get_parameter("dwell_s").value)
        self._output_file = str(self.get_parameter("output_file").value)

        if self._step <= 1e-6:
            raise ValueError("`step` must be > 0")
        if self._max_angle <= self._min_angle:
            raise ValueError("`max_angle` must be greater than `min_angle`")
        if self._dwell_s <= 0:
            raise ValueError("`dwell_s` must be > 0")

        self._joint_values = {self._joint_1: 0.0, self._joint_2: 0.0}
        self._has_joint_1 = False
        self._has_joint_2 = False

        self._joint_sub = self.create_subscription(
            JointState, self._joint_state_topic, self._on_joint_state, 10
        )
        self._cmd_pub = self.create_publisher(Float64MultiArray, self._command_topic, 10)

    def _on_joint_state(self, msg: JointState) -> None:
        for name, pos in zip(msg.name, msg.position, strict=False):
            if name == self._joint_1:
                self._joint_values[self._joint_1] = float(pos)
                self._has_joint_1 = True
            elif name == self._joint_2:
                self._joint_values[self._joint_2] = float(pos)
                self._has_joint_2 = True

    def _publish(self, joint_1_cmd: float, joint_2_cmd: float) -> None:
        msg = Float64MultiArray()
        msg.data = [joint_1_cmd, joint_2_cmd]
        self._cmd_pub.publish(msg)

    def _hold_command(self, joint_1_cmd: float, joint_2_cmd: float, hold_s: float) -> None:
        end_t = time.monotonic() + hold_s
        while rclpy.ok() and time.monotonic() < end_t:
            self._publish(joint_1_cmd, joint_2_cmd)
            rclpy.spin_once(self, timeout_sec=0.02)
            time.sleep(0.02)

    def _wait_joint_feedback(self, timeout_s: float = 8.0) -> bool:
        deadline = time.monotonic() + timeout_s
        while rclpy.ok() and time.monotonic() < deadline:
            if self._has_joint_1 and self._has_joint_2:
                return True
            rclpy.spin_once(self, timeout_sec=0.05)
        return False

    def _build_scan_targets(self) -> list[float]:
        targets: list[float] = []
        val = self._min_angle
        while val <= self._max_angle + 1e-9:
            targets.append(round(val, 6))
            val += self._step
        return targets

    def run_scan(self) -> None:
        self.get_logger().info(
            f"Scanning gripper joints [{self._joint_1}, {self._joint_2}] on {self._command_topic}"
        )
        if not self._wait_joint_feedback():
            raise RuntimeError("Timed out waiting for gripper joints in /joint_states")

        targets = self._build_scan_targets()
        records: list[dict[str, float | str]] = []

        for phase, phase_targets in (
            ("forward", targets),
            ("reverse", list(reversed(targets))),
        ):
            for joint_1_target in phase_targets:
                joint_2_target = -joint_1_target
                self._hold_command(joint_1_target, joint_2_target, self._dwell_s)
                sample_1 = self._joint_values[self._joint_1]
                sample_2 = self._joint_values[self._joint_2]
                records.append(
                    {
                        "phase": phase,
                        "joint_1_target": float(joint_1_target),
                        "joint_2_target": float(joint_2_target),
                        "joint_1_actual": float(sample_1),
                        "joint_2_actual": float(sample_2),
                    }
                )

        joint_1_actual = [float(x["joint_1_actual"]) for x in records]
        joint_2_actual = [float(x["joint_2_actual"]) for x in records]

        rec = {
            "gripper_close_joint_1": min(joint_1_actual),
            "gripper_open_joint_1": max(joint_1_actual),
            "gripper_close_joint_2": max(joint_2_actual),
            "gripper_open_joint_2": min(joint_2_actual),
        }

        self.get_logger().info("=== Gripper scan recommended mapping ===")
        self.get_logger().info(f"gripper_close_joint_1={rec['gripper_close_joint_1']:.6f}")
        self.get_logger().info(f"gripper_open_joint_1={rec['gripper_open_joint_1']:.6f}")
        self.get_logger().info(f"gripper_close_joint_2={rec['gripper_close_joint_2']:.6f}")
        self.get_logger().info(f"gripper_open_joint_2={rec['gripper_open_joint_2']:.6f}")

        if self._output_file:
            payload = {
                "joint_1": self._joint_1,
                "joint_2": self._joint_2,
                "recommendation": rec,
                "records": records,
            }
            output_path = Path(self._output_file)
            output_path.parent.mkdir(parents=True, exist_ok=True)
            output_path.write_text(json.dumps(payload, indent=2), encoding="utf-8")
            self.get_logger().info(f"Scan report saved to {output_path}")

        # Return to a neutral command after scanning.
        self._hold_command(0.0, 0.0, 0.5)


def main(args=None) -> None:
    rclpy.init(args=args)
    node = TGArm620GripperScan()
    try:
        node.run_scan()
    finally:
        node.destroy_node()
        if rclpy.ok():
            rclpy.shutdown()


if __name__ == "__main__":
    main()
