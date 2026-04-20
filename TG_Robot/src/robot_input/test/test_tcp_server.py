import socket
import struct
import time
from robot_input.common.protocol import build_frame, OpCode, JOINT_CONTROL_MAP, CARTESIAN_CONTROL_MAP

def test_backtostart_command_publish_periodic():
    client = socket.create_connection(("127.0.0.1", 8899))
    print("[TEST] Connected to server on 127.0.0.1:8899")

    try:
        payload = B''
        frame = build_frame(OpCode.BACKTOSTART, payload)
        client.send(frame)
        time.sleep(1)
    finally:
        client.close()
        print("[TEST] Client closed.")

def test_jointctrl_command_publish_periodic():
    client = socket.create_connection(("127.0.0.1", 8899))
    print("[TEST] Connected to server on 127.0.0.1:8899")

    try:
        joint_control_command = JOINT_CONTROL_MAP['joint1-']
        elapsed = 0.0
        start_time = time.time()

        # 模拟“按住”：连续发送 is_pressed=True，每 100ms，持续 2秒
        while elapsed < 2.0:
            payload = struct.pack('BB', joint_control_command, 1)  # 1 = True
            frame = build_frame(OpCode.JOINTCONTROL, payload)
            client.sendall(frame)
            print(f"[TEST] Sent press: key_code={joint_control_command:#02x}, is_pressed=1")
            time.sleep(0.1)
            elapsed = time.time() - start_time

        # 模拟“松开”：只发送一次 is_pressed=False
        payload = struct.pack('BB', joint_control_command, 0)  # 0 = False
        frame = build_frame(OpCode.JOINTCONTROL, payload)
        client.sendall(frame)
        print(f"[TEST] Sent release: key_code={joint_control_command:#02x}, is_pressed=0")

    finally:
        client.close()
        print("[TEST] Client closed.")

def test_cartesian_command_publish_periodic():
    client = socket.create_connection(("127.0.0.1", 8899))
    print("[TEST] Connected to server on 127.0.0.1:8899")
    try:
        cartesian_control_command = JOINT_CONTROL_MAP['forward']
        elapsed = 0.0
        start_time = time.time()

        """模拟“按住”：连续发送 is_pressed=True，每 100ms，持续 2秒"""
        while elapsed < 2.0:
            payload = struct.pack('BB', cartesian_control_command, 1)  # 1 = True
            frame = build_frame(OpCode.CARTESIAN, payload)
            client.sendall(frame)
            print(f"[TEST] Sent press: key_code={cartesian_control_command:#02x}, is_pressed=1")
            time.sleep(0.1)
            elapsed = time.time() - start_time

        # 模拟“松开”：只发送一次 is_pressed=False
        payload = struct.pack('BB', cartesian_control_command, 0)  # 0 = False
        frame = build_frame(OpCode.CARTESIAN, payload)
        client.sendall(frame)
        print(f"[TEST] Sent release: key_code={cartesian_control_command:#02x}, is_pressed=0")

    finally:
        client.close()
        print("[TEST] Client closed.")
    

def test_disable_command_publish_periodic():
    client = socket.create_connection(("127.0.0.1", 8899))
    print("[TEST] Connected to server on 127.0.0.1:8899")

    try:
        payload = B''
        frame = build_frame(OpCode.DISABLE, payload)
        
        client.sendall(frame)
        print("[TEST] Sent disable command")

        time.sleep(1)  # 等待一段时间，以便服务器处理命令
    finally:
        client.close()
        print("[TEST] Client closed.")
    
        
def test_movej_command_publish_periodic():
    client = socket.create_connection(("127.0.0.1", 8899))
    print("[TEST] Connected to server on 127.0.0.1:8899")

    try:
        for i in range(5):  # 模拟发送5次
            movej_data = [10.0 + i, 20.0 + i, 30.0, 40.0, 50.0, 60.0]
            payload = struct.pack('>6f', *movej_data)
            frame = build_frame(OpCode.MOVEJ, payload)

            client.sendall(frame)
            print(f"[TEST] Sent MOVEJ frame {i + 1}: {movej_data}")
            time.sleep(1.0)
    finally:
        client.close()
        print("[TEST] Client closed.")

def test_movec_command_publish_periodic():
    client = socket.create_connection(("127.0.0.1", 8899))
    print("[TEST] Connected to server on 127.0.0.1:8899")

    try:
        for i in range(5):  # 模拟发送5次
            movec_data = [10.0 + i, 20.0 + i, 30.0, 40.0, 50.0, 60.0, 70.0 + i, 80.0 + i, 90.0, 100.0, 110.0, 120.0]
            payload = struct.pack('>12f', *movec_data)
            frame = build_frame(OpCode.MOVEC, payload)

            client.sendall(frame)
            print(f"[TEST] Sent MOVEC frame {i + 1}: {movec_data}")
            time.sleep(1.0)
    finally:
        client.close()
        print("[TEST] Client closed.")

def test_teach_command_publish():
    client = socket.create_connection(("127.0.0.1", 8899))
    print("[TEST] Connected to server on 127.0.0.1:8899")

    try:
        begin_teach_command = 1
        payload = struct.pack('B', begin_teach_command)
        frame = build_frame(OpCode.TEACH, payload)

        client.sendall(frame)
        print(f"[TEST] Sent TEACH frame: {begin_teach_command:#02x}")
        time.sleep(3.0)

        stop_teach_command = 2
        payload = struct.pack('B', stop_teach_command)
        frame = build_frame(OpCode.TEACH, payload)

        client.sendall(frame)
        print(f"[TEST] Sent TEACH frame: {stop_teach_command:#02x}")
        time.sleep(1.0)
    finally:
        client.close()
        print("[TEST] Client closed.")

def test_teachrepeat_command_publish():
    client = socket.create_connection(("127.0.0.1", 8899))
    print("[TEST] Connected to server on 127.0.0.1:8899")

    try:
        payload = B''
        frame = build_frame(OpCode.TEACHREPEAT, payload)

        client.send(frame)
        time.sleep(1.0)
    finally:
        client.close()
        print("[TEST] Client closed.")
        
def test_backtoinitial_command_publish_periodic():
    client = socket.create_connection(("127.0.0.1", 8899))
    print("[TEST] Connected to server on 127.0.0.1:8899")

    try:
        payload = B''
        frame = build_frame(OpCode.BACKTOINITIAL, payload)
        client.send(frame)
        time.sleep(1)
    finally:
        client.close()
        print("[TEST] Client closed.")
