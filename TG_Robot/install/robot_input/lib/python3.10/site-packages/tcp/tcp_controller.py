import socket
import threading
import struct
import time
import rclpy
from rclpy.node import Node
from rclpy.qos import QoSProfile, ReliabilityPolicy
from common.protocol import try_parse_command_frame, build_status_frame, OpCode, JOINT_CONTROL_MAP, CARTESIAN_CONTROL_MAP
from typing import Tuple
from std_msgs.msg import UInt8, Float64MultiArray, String, Bool
from robot_interfaces.msg import MoveCAction, StateAction, KeyPressedAction


RECV_FRAME_TIMEOUT = 1.0
MAX_FRAME_SIZE = 1024  # 适配不同指令长度

class IncompleteFrameError(Exception):
    pass

class TcpControllerNode(Node):
    def __init__(self):
        super().__init__('tcp_server_node')
        self.get_logger().info('TCP Server Node Started')

        self.host = '0.0.0.0'
        self.port = 8899
        self.server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.server_socket.bind((self.host, self.port))
        self.server_socket.listen(1)

        self._init_publishers()

        # self.client_socket = None
        # self.client_thread = None
        msg = UInt8()
        msg.data = OpCode.DISABLE
        self.current_mode = msg.data
        self.mode_pub_.publish(msg)

        self.running = True
        threading.Thread(target=self._accept_thread, daemon=True).start()

    def _init_publishers(self):
        qos = QoSProfile(depth=10, reliability=ReliabilityPolicy.RELIABLE)
        self.mode_pub_ = self.create_publisher(UInt8, 'robotic_arm_control_mode', qos)
        self.jointctrl_pub_ = self.create_publisher(KeyPressedAction, 'jointctrl_action', qos)
        self.cartesian_pub_ = self.create_publisher(KeyPressedAction, 'cartesian_action', qos)
        self.movej_pub_ = self.create_publisher(Float64MultiArray, 'movej_action', qos)
        self.movel_pub_ = self.create_publisher(Float64MultiArray, 'movel_action', qos)
        self.movec_pub_ = self.create_publisher(MoveCAction, 'movec_action', qos)
        self.teach_pub_ = self.create_publisher(String, 'teach_action', qos)
        self.teachrepeat_pub_ = self.create_publisher(String, 'teachrepeat_action', qos)
        time.sleep(1)

    def _accept_thread(self):
        while self.running:
            self.get_logger().info(f'🔌 Waiting for client at {self.host}:{self.port}...')
            try:
                client_socket, addr = self.server_socket.accept()
                self.get_logger().info(f'✅ Client connected from {addr}')
                self._handle_client(client_socket)
            except Exception as e:
                self.get_logger().error(f'Accept error: {e}')

    def _handle_client(self, client_socket):
        buffer = b''
        try:
            while self.running:
                data = client_socket.recv(1024)
                self.get_logger().info(f'Raw data: {data}')
                if not data:
                    break
                buffer += data

                while True:
                    try:
                        frame, remaining = self.try_extract_complete_frame(buffer)
                        opcode, payload = self.try_parse_command_frame(frame)
                        self.get_logger().info(f"Received opcode: {opcode}")
                        self._handle_command(opcode, payload)
                        buffer = remaining
                    except IncompleteFrameError:
                        break  # 等待下一轮 recv 补全
                    except Exception as e:
                        self.get_logger().warn(f'Parse error: {e}')
                        buffer = b''  # 丢弃当前 buffer，避免死循环
                        break
        finally:
            client_socket.close()
            self.get_logger().info('Client disconnected')

    def try_extract_complete_frame(self, buf: bytes) -> Tuple[bytes, bytes]:
        if len(buf) < 4:
            raise IncompleteFrameError()
        if buf[0] != 0x55:
            raise ValueError('Invalid header')

        length = int.from_bytes(buf[1:3], 'big')  # payload+opcode
        total_len = 1 + 2 + length + 1  # header + len + data + checksum

        if len(buf) < total_len:
            raise IncompleteFrameError()

        frame = buf[:total_len]
        remaining = buf[total_len:]
        return frame, remaining


    def try_parse_command_frame(self, buf: bytes) -> Tuple[int, bytes]:
        if buf[0] != 0x55:
            raise ValueError("Invalid header")
        length = int.from_bytes(buf[1:3], 'big')
        if len(buf) != 1 + 2 + length + 1:
            raise ValueError(f"Length mismatch: expected {1+2+length+1}, got {len(buf)}")

        opcode = buf[3]
        payload = buf[4:-1]
        checksum = buf[-1]
        computed_checksum = (sum(buf[1:3]) + opcode + sum(payload)) & 0xFF
        if checksum != computed_checksum:
            raise ValueError("Checksum mismatch")
        return opcode, payload

    def _handle_command(self, opcode, payload):
        msg = UInt8()
        msg.data = opcode
        self.mode_pub_.publish(msg)

        if opcode == OpCode.BACKTOSTART:
            self.get_logger().info(f'Publishd BACKTOSTART command')
        elif opcode == OpCode.DISABLE:
            self.get_logger().info(f'Publishd DISABLE command')
        elif opcode == OpCode.JOINTCONTROL:
            joint_control_command, is_pressed = struct.unpack('BB', payload)
            self.get_logger().info(f"Received JOINTCONTROL command: key_code={joint_control_command}, is_pressed={is_pressed}")

            if joint_control_command in JOINT_CONTROL_MAP.values():
                msg = KeyPressedAction()
                msg.key_code = joint_control_command
                msg.is_pressed = bool(is_pressed)

                self.jointctrl_pub_.publish(msg)
                action = "pressed" if is_pressed else "released"
                self.get_logger().info(f"Published joint control: key_code={joint_control_command}, {action}")
            else:
                self.get_logger().warn(f"Unknown joint control key_code: {joint_control_command}")
        elif opcode == OpCode.CARTESIAN:
            cartesian_command, is_pressed = struct.unpack('BB', payload)
            self.get_logger().info(f"Received CARTESIAN command: key_code={cartesian_command}, is_pressed={is_pressed}")

            if cartesian_command in CARTESIAN_CONTROL_MAP.values():
                msg = KeyPressedAction()
                msg.key_code = cartesian_command
                msg.is_pressed = bool(is_pressed)

                self.jointctrl_pub_.publish(msg)
                action = "pressed" if is_pressed else "released"
                self.get_logger().info(f"Published joint control: key_code={cartesian_command}, {action}")
            else:
                self.get_logger().warn(f"Unknown joint control key_code: {cartesian_command}")
                                                                
        elif opcode == OpCode.MOVEJ:
            joint_angles = struct.unpack('>6f', payload)
            self.get_logger().info(f'Payload length: {len(payload)} bytes')

            msg = Float64MultiArray()
            msg.data = list(map(float, joint_angles))
            self.movej_pub_.publish(msg)
            self.get_logger().info(f'Published MOVEJ: {msg.data}')
        elif opcode == OpCode.MOVEL:
            ee_pose = struct.unpack('>6f', payload)
            self.get_logger().info(f'Payload length: {len(payload)} bytes')

            msg = Float64MultiArray()
            msg.data = list(map(float, ee_pose))
            self.movel_pub_.publish(msg)
            self.get_logger().info(f'Published MOVEL: {msg.data}')
        elif opcode == OpCode.MOVEC:
            middle_pose = struct.unpack('>6f', payload[:24])  # First 6 floats (24 bytes)
            target_pose = struct.unpack('>6f', payload[24:])  # Next 6 floats (24 bytes)
            self.get_logger().info(f'Payload length: {len(payload)} bytes')

            msg = Float64MultiArray()
            msg.data = list(map(float, middle_pose)) + list(map(float, target_pose))

            movec_action_msg = MoveCAction()
            movec_action_msg.pose_array = msg
            movec_action_msg.must_pass_through_middle = True

            self.movec_pub_.publish(movec_action_msg)
            self.get_logger().info(f'Published MOVEC: {movec_action_msg.pose_array.data}')
        elif opcode == OpCode.TEACH:
            teach_command = struct.unpack('B', payload)[0]
            self.get_logger().info(f"Received TEACH command: {teach_command:#02x}")

            msg = String()
            if teach_command == 1:
                msg.data = 'tcp_teach_trajectory'
            elif teach_command == 2:
                msg.data = 'stop'

            self.teach_pub_.publish(msg)
            self.get_logger().info(f'Published TEACH: {msg.data}')
        elif opcode == OpCode.TEACHREPEAT:
            self.get_logger().info(f'Publishd TEACHREPEAT command')
            msg = String()
            msg.data = 'tcp_teach_trajectory'
            self.teachrepeat_pub_.publish(msg)
        elif opcode == OpCode.BACKTOINITIAL:
            self.get_logger().info(f'Publishd BACKTOINITIAL command')
        elif opcode == OpCode.GRIPPERCONTROL:
            gripper_type, pos, vel, eff = struct.unpack('BBBB', payload)

            msg = Float64MultiArray()
            msg.data = [gripper_type, pos, vel, eff]
            self.gripper_pub_.publish(msg)
            self.get_logger().info(f'Published GRIPPERCONTROL: {msg.data}')            
        else:
            self.get_logger().warn(f'Unhandled opcode: {opcode:#04x}')

    def publish_status(self):
        """构造机械臂状态并发送给上位机"""
        if not self.client_socket:
            return

        # TODO: 实际从你的控制器获取这些值（示例用假数据）
        dummy_floats = [0.0] * 6
        frame = build_status_frame(dummy_floats, dummy_floats, dummy_floats, dummy_floats)
        try:
            self.client_socket.sendall(frame)
        except Exception as e:
            self.get_logger().warn(f'🔌 Failed to send status: {e}')

    def destroy_node(self):
        self.running = False
        if self.client_socket:
            self.client_socket.close()
        self.server_socket.close()
        super().destroy_node()

def main():
    rclpy.init()
    node = TcpControllerNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
