import pytest
import struct
from robot_input.common.protocol import try_parse_command_frame, OpCode

def build_movej_frame(joint_values):
    """
    构造一帧合法的 MOVEJ 控制帧，用于测试。
    joint_values: list of 6 floats
    """
    assert len(joint_values) == 6
    opcode = OpCode.MOVEJ
    payload = struct.pack('>B6f', opcode, *joint_values)  # opcode + 6 float32
    data_len = len(payload)
    header = b'\x55' + struct.pack('>H', data_len)
    checksum = (sum(header[1:] + payload) & 0xFF).to_bytes(1, 'big')
    return header + payload + checksum


def test_parse_movej_command():
    """测试 MOVEJ 指令帧能否被正确解析"""
    joint_values = [10.0, 20.0, 30.0, 40.0, 50.0, 60.0]
    frame = build_movej_frame(joint_values)
    opcode, parsed_joint_values = try_parse_command_frame(frame)
    assert opcode == OpCode.MOVEJ
    parsed_values = struct.unpack('>6f', parsed_joint_values)
    assert pytest.approx(parsed_values) == joint_values

