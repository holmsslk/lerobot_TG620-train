import struct
from enum import IntEnum

# ========== 常量定义 ==========
FRAME_HEAD_TX = 0x55  # 上位机发来的控制帧
FRAME_HEAD_RX = 0xAA  # 机械臂发出的状态帧

# ========== 操作码定义 ==========
class OpCode(IntEnum):
    BACKTOSTART    = 0
    DISABLE        = 1
    JOINTCONTROL   = 2
    CARTESIAN      = 3
    MOVEJ          = 4
    MOVEL          = 5
    MOVEC          = 6
    TEACH          = 7
    TEACHREPEAT    = 8
    BACKTOINITIAL  = 9
    GRIPPERCONTROL = 10

JOINT_CONTROL_MAP = {
    'joint1+': 41,
    'joint1-': 42,
    'joint2+': 43,
    'joint2-': 44,
    'joint3+': 45,
    'joint3-': 46,
    'joint4+': 47,
    'joint4-': 48,
    'joint5+': 49,
    'joint5-': 50,
    'joint6+': 51,
    'joint6-': 52,
    'stop': 255
}

CARTESIAN_CONTROL_MAP = {
    'forward': 55,
    'backward': 56,
    'left': 57,
    'right': 58,
    'up': 59,
    'down': 60,
    'roll_cw': 61,
    'roll_ccw': 62,
    'pitch_up': 63,
    'pitch_down': 64,
    'yaw_left': 65,
    'yaw_right': 66,
    'stop': 255
}

# ========== 公共工具函数 ==========

def _checksum(data: bytes) -> int:
    """计算校验和（低8位）"""
    return sum(data) & 0xFF

# ========== 上位机 → 机械臂（控制指令帧） ==========

def try_parse_command_frame(buf: bytes):
    """
    尝试解析一帧上位机发来的控制指令。
    返回 (opcode: int, payload: bytes)，由上层进一步解析 payload。
    """
    if len(buf) < 5:  # 帧头 + 长度2B + opcode + 校验
        raise ValueError("frame too short")
    if buf[0] != FRAME_HEAD_TX:
        raise ValueError("invalid header")

    data_len = struct.unpack('>H', buf[1:3])[0]
    expected_len = 1 + 2 + data_len + 1  # head + len + body + chk
    if len(buf) != expected_len:
        raise ValueError("length mismatch")

    body = buf[3:-1]
    chk = buf[-1]
    if _checksum(buf[1:-1]) != chk:
        raise ValueError("checksum mismatch")

    opcode = body[0]
    payload = body[1:]
    return opcode, payload

# ========== 机械臂 → 上位机（状态帧） ==========

_STATUS_FRAME_LEN = 1 + 96 + 1  # 帧头 + 6*4*4 (4块float[6]) + 校验

def build_status_frame(positions, velocities, currents, pose):
    """
    构造一帧机械臂状态反馈帧。
    - positions/velocities/currents/pose: tuple/list of 6 float
    """
    payload = struct.pack('>6f6f6f6f', *positions, *velocities, *currents, *pose)
    chk = _checksum(payload)
    return struct.pack('>B', FRAME_HEAD_RX) + payload + struct.pack('>B', chk)

def try_parse_status_frame(buf: bytes):
    """
    尝试解析机械臂状态帧（由上位机调用）。
    要求调用方一次读满 _STATUS_FRAME_LEN 字节。
    """
    if len(buf) != _STATUS_FRAME_LEN:
        raise ValueError("invalid status frame length")
    if buf[0] != FRAME_HEAD_RX:
        raise ValueError("invalid frame header")

    payload = buf[1:-1]
    chk = buf[-1]
    if _checksum(payload) != chk:
        raise ValueError("checksum mismatch")

    unpack = lambda offset: struct.unpack('>6f', payload[offset:offset+24])
    return {
        'positions':  unpack(0),
        'velocities': unpack(24),
        'currents':   unpack(48),
        'pose':       unpack(72),
    }


def build_frame(opcode: int, data: bytes) -> bytes:
    header = b'\x55'
    length = len(data) + 1  # 操作码 + 数据内容
    length_bytes = length.to_bytes(2, 'big')
    checksum = (sum(length_bytes) + opcode + sum(data)) & 0xFF
    return header + length_bytes + bytes([opcode]) + data + bytes([checksum])


def parse_frame(frame: bytes) -> tuple[int, bytes]:
    if len(frame) < 5:
        raise ValueError("Frame too short")
    if frame[0] != 0x55:
        raise ValueError("Invalid header")
    
    length = int.from_bytes(frame[1:3], 'big')
    if len(frame) != length + 4:
        raise ValueError(f"Length mismatch: expected {length + 4}, got {len(frame)}")

    opcode = frame[3]
    data = frame[4:-1]
    checksum = frame[-1]

    expected_checksum = (sum(frame[1:3]) + opcode + sum(data)) & 0xFF
    if checksum != expected_checksum:
        raise ValueError("Checksum mismatch")

    return opcode, data
