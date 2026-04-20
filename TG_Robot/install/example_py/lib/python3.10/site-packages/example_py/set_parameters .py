#!/usr/bin/env python3
"""
设置关节模组位置限位参数
根据 joint_pro标准对外接口协议-V0.0.1.5

功能：
1. 设置位置上限
2. 设置位置下限
3. 开启限位功能
4. 设置运动参数（电流、加减速度）
5. 保存参数到flash
6. 验证每个操作的响应
7. 支持批量模式和单设备模式
"""

import subprocess
import threading
import time
import re
import struct
import sys


class CANParameterSetter:
    def __init__(self, interface='can0'):
        self.interface = interface

    def send_can_message(self, can_id, data, use_canfd=True, silent=False):
        """
        发送CAN消息
        :param can_id: CAN ID (十六进制字符串，如 '601')
        :param data: 数据内容 (十六进制字符串)
        :param use_canfd: 是否使用CAN FD
        :param silent: 是否静默模式
        """
        # 验证数据长度（必须是偶数）
        if len(data) % 2 != 0:
            data = '0' + data

        # 格式化CAN ID为8位（CAN FD）或3位（标准CAN）
        if use_canfd:
            can_id_formatted = f"{int(can_id, 16):08X}"
            # CAN FD格式需要flags标志，设为0（无特殊标志）
            cmd = f"cansend {self.interface} {can_id_formatted}##0{data}"
        else:
            can_id_formatted = f"{int(can_id, 16):03X}"
            cmd = f"cansend {self.interface} {can_id_formatted}#{data}"

        if not silent:
            print(f"发送: {cmd}")

        try:
            result = subprocess.run(cmd, shell=True, capture_output=True, text=True, timeout=1)
            if result.returncode == 0:
                if not silent:
                    print("✓ 发送成功")
                return True
            else:
                print(f"✗ 发送失败: {result.stderr}")
                return False
        except Exception as e:
            print(f"✗ 发送出错: {e}")
            return False

    def write_parameter_int32(self, device_id, param_address, value, use_canfd=True):
        """
        写入int32参数
        :param device_id: 设备ID (1-254)
        :param param_address: 参数地址
        :param value: int32值
        :return: (success, verified)
        """
        # CAN ID = 0x600 + device_id
        can_id = f"{0x600 + device_id:X}"

        # 构建数据帧（CAN FD格式）
        data_length = 0x08
        operation = 0x02
        param_addr_bytes = struct.pack('>H', param_address)
        param_type = 0x01
        value_bytes = struct.pack('>i', value)

        data_bytes = bytes([data_length, operation]) + param_addr_bytes + bytes([param_type]) + value_bytes
        data_hex = data_bytes.hex().upper()

        print(f"\n设置参数 (int32):")
        print(f"  设备ID: {device_id}")
        print(f"  参数地址: {param_address}")
        print(f"  参数值: {value}")
        print(f"  数据帧: {data_hex}")

        # 响应 ID = 0x700 + device_id
        response_id = 0x700 + device_id
        expected_response = data_hex

        # 启动监听线程
        response_data = [None]
        candump_process = [None]

        def start_listening():
            try:
                target_id_formatted = f"{response_id:08X}"
                process = subprocess.Popen(
                    ['candump', self.interface],
                    stdout=subprocess.PIPE,
                    stderr=subprocess.PIPE,
                    text=True,
                    bufsize=1
                )
                candump_process[0] = process

                for line in process.stdout:
                    line = line.strip()
                    if target_id_formatted in line:
                        match = re.search(r'\[(\d+)\]\s+((?:[0-9A-Fa-f]{2}\s*)+)', line)
                        if match:
                            data_bytes = match.group(2).replace(' ', '')
                            response_data[0] = data_bytes
                            break
            except Exception:
                pass

        listen_thread = threading.Thread(target=start_listening, daemon=True)
        listen_thread.start()
        time.sleep(0.3)

        # 发送命令
        if not self.send_can_message(can_id, data_hex, use_canfd=use_canfd):
            if candump_process[0]:
                candump_process[0].terminate()
            return False, False

        # 等待响应
        print(f"  等待响应 (ID=0x{response_id:08X})...", end=" ")
        listen_thread.join(timeout=2.0)

        if candump_process[0]:
            candump_process[0].terminate()

        if response_data[0]:
            response_upper = response_data[0].upper()
            expected_upper = expected_response.upper()
            if response_upper.startswith(expected_upper):
                print(f"✓ 验证成功")
                return True, True
            else:
                print(f"✗ 响应不匹配: {response_data[0]}")
                return True, False
        else:
            print(f"✗ 无响应")
            return True, False

    def write_parameter_float32(self, device_id, param_address, value, use_canfd=True):
        """
        写入float32参数
        :param device_id: 设备ID (1-254)
        :param param_address: 参数地址
        :param value: float32值
        :return: (success, verified)
        """
        # CAN ID = 0x600 + device_id
        can_id = f"{0x600 + device_id:X}"

        # 构建数据帧（CAN FD格式）
        data_length = 0x08
        operation = 0x02
        param_addr_bytes = struct.pack('>H', param_address)
        param_type = 0x02
        value_bytes = struct.pack('>f', value)

        data_bytes = bytes([data_length, operation]) + param_addr_bytes + bytes([param_type]) + value_bytes
        data_hex = data_bytes.hex().upper()

        print(f"\n设置参数 (float32):")
        print(f"  设备ID: {device_id}")
        print(f"  参数地址: {param_address}")
        print(f"  参数值: {value}")
        print(f"  数据帧: {data_hex}")

        # 响应 ID = 0x700 + device_id
        response_id = 0x700 + device_id
        expected_response = data_hex

        # 启动监听线程
        response_data = [None]
        candump_process = [None]

        def start_listening():
            try:
                target_id_formatted = f"{response_id:08X}"
                process = subprocess.Popen(
                    ['candump', self.interface],
                    stdout=subprocess.PIPE,
                    stderr=subprocess.PIPE,
                    text=True,
                    bufsize=1
                )
                candump_process[0] = process

                for line in process.stdout:
                    line = line.strip()
                    if target_id_formatted in line:
                        match = re.search(r'\[(\d+)\]\s+((?:[0-9A-Fa-f]{2}\s*)+)', line)
                        if match:
                            data_bytes = match.group(2).replace(' ', '')
                            response_data[0] = data_bytes
                            break
            except Exception:
                pass

        listen_thread = threading.Thread(target=start_listening, daemon=True)
        listen_thread.start()
        time.sleep(0.3)

        # 发送命令
        if not self.send_can_message(can_id, data_hex, use_canfd=use_canfd):
            if candump_process[0]:
                candump_process[0].terminate()
            return False, False

        # 等待响应
        print(f"  等待响应 (ID=0x{response_id:08X})...", end=" ")
        listen_thread.join(timeout=2.0)

        if candump_process[0]:
            candump_process[0].terminate()

        if response_data[0]:
            response_upper = response_data[0].upper()
            expected_upper = expected_response.upper()
            if response_upper.startswith(expected_upper):
                print(f"✓ 验证成功")
                return True, True
            else:
                print(f"✗ 响应不匹配: {response_data[0]}")
                return True, False
        else:
            print(f"✗ 无响应")
            return True, False

    def save_to_flash(self, device_id, use_canfd=True):
        """
        保存参数到flash
        函数操作接口: CAN ID = 0x400 + device_id
        操作码 = 0x02
        响应: ID = 0x500 + device_id, 数据 = "020201" (成功)
        :return: (success, verified)
        """
        # CAN ID = 0x400 + device_id
        can_id = f"{0x400 + device_id:X}"

        # 构建数据帧（CAN FD格式）
        data_length = 0x01
        function_code = 0x02

        data_bytes = bytes([data_length, function_code])
        data_hex = data_bytes.hex().upper()

        print(f"\n执行函数操作:")
        print(f"  设备ID: {device_id}")
        print(f"  函数: 参数保存到flash")
        print(f"  操作码: 0x{function_code:02X}")
        print(f"  数据帧: {data_hex}")

        # 响应 ID = 0x500 + device_id
        response_id = 0x500 + device_id
        expected_response = "020201"

        # 启动监听线程
        response_data = [None]
        candump_process = [None]

        def start_listening():
            try:
                target_id_formatted = f"{response_id:08X}"
                process = subprocess.Popen(
                    ['candump', self.interface],
                    stdout=subprocess.PIPE,
                    stderr=subprocess.PIPE,
                    text=True,
                    bufsize=1
                )
                candump_process[0] = process

                for line in process.stdout:
                    line = line.strip()
                    if target_id_formatted in line:
                        match = re.search(r'\[(\d+)\]\s+((?:[0-9A-Fa-f]{2}\s*)+)', line)
                        if match:
                            data_bytes = match.group(2).replace(' ', '')
                            response_data[0] = data_bytes
                            break
            except Exception:
                pass

        listen_thread = threading.Thread(target=start_listening, daemon=True)
        listen_thread.start()
        time.sleep(0.3)

        # 发送命令
        if not self.send_can_message(can_id, data_hex, use_canfd=use_canfd):
            if candump_process[0]:
                candump_process[0].terminate()
            return False, False

        # 等待响应
        print(f"  等待响应 (ID=0x{response_id:08X})...", end=" ")
        listen_thread.join(timeout=2.0)

        if candump_process[0]:
            candump_process[0].terminate()

        if response_data[0]:
            response_upper = response_data[0].upper()
            expected_upper = expected_response.upper()
            if response_upper.startswith(expected_upper):
                print(f"✓ 保存成功")
                return True, True
            else:
                print(f"✗ 保存失败，响应: {response_data[0]}")
                return True, False
        else:
            print(f"✗ 无响应")
            return True, False


def get_user_input():
    """
    获取用户输入，配置要修改的设备和参数
    """
    print("=" * 80)
    print("关节模组位置限位设置工具")
    print("=" * 80)

    # 主菜单
    print("\n请选择操作模式:")
    print("  1. 批量模式 - 对所有模组(ID 1-6)进行参数修改 (默认)")
    print("  2. 单设备模式 - 对指定模组进行参数修改")

    mode_choice = input("\n请输入选项 (1/2, 回车默认为1): ").strip()
    if mode_choice == "":
        mode_choice = "1"

    device_configs = []
    batch_mode = False

    if mode_choice == "1":
        # 批量模式 - 使用预设配置
        batch_mode = True
        device_configs = [
            {'id': 1, 'pos_min': -170.0, 'pos_max': 170.0, 'enable_limit': 1},
            {'id': 2, 'pos_min': -90.0,  'pos_max': 90.0,  'enable_limit': 1},
            {'id': 3, 'pos_min': -90.0,  'pos_max': 90.0,  'enable_limit': 1},
            {'id': 4, 'pos_min': -170.0, 'pos_max': 170.0, 'enable_limit': 1},
            {'id': 5, 'pos_min': -90.0,  'pos_max': 90.0,  'enable_limit': 1},
            {'id': 6, 'pos_min': -170.0, 'pos_max': 170.0, 'enable_limit': 1},
        ]
        print(f"\n✓ 已选择批量模式 - 将对所有设备(ID 1-6)进行默认配置")

    elif mode_choice == "2":
        # 单设备模式
        print("\n" + "=" * 80)
        print("单设备模式")
        print("=" * 80)

        # 获取设备ID
        while True:
            device_id_str = input("\n请输入设备ID (1-6): ").strip()
            try:
                device_id = int(device_id_str)
                if 1 <= device_id <= 6:
                    break
                else:
                    print("✗ 设备ID必须在1-6之间，请重新输入")
            except ValueError:
                print("✗ 请输入有效的数字")

        # 选择要修改的参数类型
        print("\n请选择要修改的参数 (可多选，用逗号分隔，例如: 1,2,3):")
        print("  1. 位置限位 (上限、下限、限位开关)")
        print("  2. 最大电流")
        print("  3. 最大加速度")
        print("  4. 最大减速度")
        print("  5. 最大速度")
        print("  6. 全部参数 (默认)")

        param_choice = input("\n请输入选项 (回车默认为6): ").strip()
        if param_choice == "":
            param_choice = "6"

        # 解析选择
        selected_params = set()
        if "5" in param_choice:
            selected_params = {1, 2, 3, 4, 5}
        else:
            for choice in param_choice.split(','):
                choice = choice.strip()
                if choice in ['1', '2', '3', '4', '5']:
                    selected_params.add(int(choice))

        # 初始化配置
        config = {'id': device_id}

        # 根据选择获取参数值
        if 1 in selected_params:
            print("\n" + "-" * 80)
            print("位置限位参数")
            print("-" * 80)
            pos_min = float(input("请输入位置下限 (度): ").strip())
            pos_max = float(input("请输入位置上限 (度): ").strip())
            enable_limit_str = input("是否开启限位 (1=开启, 0=关闭, 默认1): ").strip()
            enable_limit = 1 if enable_limit_str == "" else int(enable_limit_str)
            config['pos_min'] = pos_min
            config['pos_max'] = pos_max
            config['enable_limit'] = enable_limit

        if 2 in selected_params:
            print("\n" + "-" * 80)
            print("最大电流参数")
            print("-" * 80)
            max_current_str = input("请输入最大电流 (A, 默认10.0): ").strip()
            config['max_current'] = 10.0 if max_current_str == "" else float(max_current_str)

        if 3 in selected_params:
            print("\n" + "-" * 80)
            print("最大加速度参数")
            print("-" * 80)
            max_acc_str = input("请输入最大加速度 (°/s², 默认150.0): ").strip()
            config['max_acceleration'] = 150.0 if max_acc_str == "" else float(max_acc_str)

        if 4 in selected_params:
            print("\n" + "-" * 80)
            print("最大减速度参数")
            print("-" * 80)
            max_dec_str = input("请输入最大减速度 (°/s², 默认150.0): ").strip()
            config['max_deceleration'] = 150.0 if max_dec_str == "" else float(max_dec_str)

        if 5 in selected_params:
            print("\n" + "-" * 80)
            print("最大速度参数")
            print("-" * 80)
            max_dec_str = input("请输入最大速度 (°/s², 默认150.0): ").strip()
            config['max_velocity'] = 150.0 if max_vel_str == "" else float(max_vel_str)

        config['selected_params'] = selected_params
        device_configs = [config]
        batch_mode = False

    else:
        print(f"✗ 无效选项，使用默认批量模式")
        batch_mode = True
        device_configs = [
            {'id': 1, 'pos_min': -170.0, 'pos_max': 170.0, 'enable_limit': 1},
            {'id': 2, 'pos_min': -90.0,  'pos_max': 90.0,  'enable_limit': 1},
            {'id': 3, 'pos_min': -90.0,  'pos_max': 90.0,  'enable_limit': 1},
            {'id': 4, 'pos_min': -170.0, 'pos_max': 170.0, 'enable_limit': 1},
            {'id': 5, 'pos_min': -90.0,  'pos_max': 90.0,  'enable_limit': 1},
            {'id': 6, 'pos_min': -170.0, 'pos_max': 170.0, 'enable_limit': 1},
        ]

    return device_configs, batch_mode


def main():
    """
    主函数：设置位置限位参数
    """
    # 获取用户配置
    device_configs, batch_mode = get_user_input()

    # 运动参数配置（批量模式下设备1、2、3、4使用默认值）
    devices_need_motion_params = [1, 2, 3, 4]
    default_max_current = 10.0
    default_max_acceleration = 150.0
    default_max_deceleration = 150.0
    default_max_velocity = 150.0

    print(f"\n当前配置:")
    if batch_mode:
        print(f"  批量模式 - 设备配置:")
        for config in device_configs:
            limit_info = f"    设备{config['id']}: {config['pos_min']:>6.1f}° ~ {config['pos_max']:>6.1f}° (限位: {'开启' if config['enable_limit'] else '关闭'})"
            if config['id'] in devices_need_motion_params:
                limit_info += f" + 电流:{default_max_current}A, 加速度:{default_max_acceleration}°/s², 减速度:{default_max_deceleration}°/s²,速度:{default_max_velocity}°/s²"
            print(limit_info)
    else:
        # 单设备模式
        config = device_configs[0]
        selected_params = config.get('selected_params', {1, 2, 3, 4, 5})
        print(f"  单设备模式 - 设备{config['id']}配置:")
        if 1 in selected_params:
            print(f"    位置下限: {config.get('pos_min', 'N/A')}°")
            print(f"    位置上限: {config.get('pos_max', 'N/A')}°")
            print(f"    限位开关: {'开启' if config.get('enable_limit', 1) else '关闭'}")
        if 2 in selected_params:
            print(f"    最大电流: {config.get('max_current', default_max_current)} A")
        if 3 in selected_params:
            print(f"    最大加速度: {config.get('max_acceleration', default_max_acceleration)}°/s²")
        if 4 in selected_params:
            print(f"    最大减速度: {config.get('max_deceleration', default_max_deceleration)}°/s²")
        if 5 in selected_params:
            print(f"    最大速度: {config.get('max_velocity', default_max_velotion)}°/s²")
    print("=" * 80)

    # 创建参数设置器
    setter = CANParameterSetter('can0')

    # 等待用户确认
    print("\n" + "!" * 80)
    print("⚠ 重要提示：在执行参数修改前请确保模组失能，否则会导致写入失败")
    print("!" * 80)
    print("\n按回车键继续，或按Ctrl+C取消...")
    try:
        input()
    except KeyboardInterrupt:
        print("\n操作已取消")
        return

    # 参数地址（来自用户参数表）
    PARAM_LIMIT_FLAG = 3
    PARAM_POS_MAX = 8
    PARAM_POS_MIN = 9
    PARAM_MAX_VELOCITY_MAX = 11
    PARAM_MAX_VELOCITY_ACC = 12
    PARAM_MAX_CURRENT = 13
    PARAM_MAX_VELOCITY_DEC = 15

    total_success_count = 0
    total_verified_count = 0

    # 计算总操作数
    total_operations = 0
    for config in device_configs:
        if batch_mode:
            # 批量模式
            operations_per_device = 4  # 位置上限、下限、限位开关、保存flash
            if config['id'] in devices_need_motion_params:
                operations_per_device += 3  # 电流、加速度、减速度
        else:
            # 单设备模式：根据选择的参数计算
            selected_params = config.get('selected_params', {1, 2, 3, 4, 5})
            operations_per_device = 0
            if 1 in selected_params:
                operations_per_device += 3  # 位置上限、下限、限位开关
            if 2 in selected_params:
                operations_per_device += 1  # 电流
            if 3 in selected_params:
                operations_per_device += 1  # 加速度
            if 4 in selected_params:
                operations_per_device += 1  # 减速度
            if 5 in selected_params:
                operations_per_device += 1  # 速度
            operations_per_device += 1  # 保存flash
        config['operations_per_device'] = operations_per_device
        total_operations += operations_per_device

    # 批量处理所有设备
    for idx, config in enumerate(device_configs, 1):
        device_id = config['id']
        operations_per_device = config['operations_per_device']

        # 初始化变量
        pos_min = 0.0
        pos_max = 0.0
        enable_limit = 0
        max_current = default_max_current
        max_acceleration = default_max_acceleration
        max_deceleration = default_max_deceleration
        max_velocity =default_max_velocity

        # 获取选择的参数（单设备模式）或使用默认（批量模式）
        if batch_mode:
            selected_params = {1, 2, 3, 4, 5}
            include_motion_params = device_id in devices_need_motion_params
            pos_min = config['pos_min']
            pos_max = config['pos_max']
            enable_limit = config['enable_limit']
            max_current = default_max_current
            max_acceleration = default_max_acceleration
            max_deceleration = default_max_deceleration
            max_velocity =default_max_velocity
        else:
            selected_params = config.get('selected_params', {1, 2, 3, 4, 5})
            include_motion_params = any(p in selected_params for p in [2, 3, 4])
            pos_min = config.get('pos_min')
            pos_max = config.get('pos_max')
            enable_limit = config.get('enable_limit')
            max_current = config.get('max_current', default_max_current)
            max_acceleration = config.get('max_acceleration', default_max_acceleration)
            max_deceleration = config.get('max_deceleration', default_max_deceleration)
            max_velocity = config.get('max_velocity', default_max_velocity)

        print("\n" + "=" * 80)
        if batch_mode:
            print(f"设备 {device_id} [{idx}/{len(device_configs)}] - 限位: {pos_min}° ~ {pos_max}°")
        else:
            params_desc = []
            if 1 in selected_params:
                params_desc.append("限位")
            if 2 in selected_params:
                params_desc.append("电流")
            if 3 in selected_params:
                params_desc.append("加速度")
            if 4 in selected_params:
                params_desc.append("减速度")
            if 5 in selected_params:
                params_desc.append("速度")
            print(f"设备 {device_id} - 修改参数: {', '.join(params_desc)}")
        print("=" * 80)

        device_success = 0
        device_verified = 0
        step_num = 1

        # 1-3. 设置位置限位参数（如果选择）
        if 1 in selected_params:
            # 1. 设置位置上限
            print("\n" + "-" * 80)
            print(f"[{step_num}/{operations_per_device}] 设置位置上限")
            print("-" * 80)
            sent, verified = setter.write_parameter_float32(device_id, PARAM_POS_MAX, pos_max, use_canfd=True)
            if sent:
                device_success += 1
                total_success_count += 1
                if verified:
                    device_verified += 1
                    total_verified_count += 1
            time.sleep(0.2)
            step_num += 1

            # 2. 设置位置下限
            print("\n" + "-" * 80)
            print(f"[{step_num}/{operations_per_device}] 设置位置下限")
            print("-" * 80)
            sent, verified = setter.write_parameter_float32(device_id, PARAM_POS_MIN, pos_min, use_canfd=True)
            if sent:
                device_success += 1
                total_success_count += 1
                if verified:
                    device_verified += 1
                    total_verified_count += 1
            time.sleep(0.2)
            step_num += 1

            # 3. 设置限位开关
            print("\n" + "-" * 80)
            print(f"[{step_num}/{operations_per_device}] 设置限位开关")
            print("-" * 80)
            sent, verified = setter.write_parameter_int32(device_id, PARAM_LIMIT_FLAG, enable_limit, use_canfd=True)
            if sent:
                device_success += 1
                total_success_count += 1
                if verified:
                    device_verified += 1
                    total_verified_count += 1
            time.sleep(0.2)
            step_num += 1

        # 设置运动参数（批量模式下只针对设备1、2、3，或单设备模式下选择了这些参数）
        if (batch_mode and include_motion_params) or (not batch_mode and include_motion_params):
            # 设置最大电流
            if 2 in selected_params:
                print("\n" + "-" * 80)
                print(f"[{step_num}/{operations_per_device}] 设置最大电流")
                print("-" * 80)
                sent, verified = setter.write_parameter_float32(device_id, PARAM_MAX_CURRENT, max_current, use_canfd=True)
                if sent:
                    device_success += 1
                    total_success_count += 1
                    if verified:
                        device_verified += 1
                        total_verified_count += 1
                time.sleep(0.2)
                step_num += 1

            # 设置最大加速度
            if 3 in selected_params:
                print("\n" + "-" * 80)
                print(f"[{step_num}/{operations_per_device}] 设置最大加速度")
                print("-" * 80)
                sent, verified = setter.write_parameter_float32(device_id, PARAM_MAX_VELOCITY_ACC, max_acceleration, use_canfd=True)
                if sent:
                    device_success += 1
                    total_success_count += 1
                    if verified:
                        device_verified += 1
                        total_verified_count += 1
                time.sleep(0.2)
                step_num += 1

            # 设置最大减速度
            if 4 in selected_params:
                print("\n" + "-" * 80)
                print(f"[{step_num}/{operations_per_device}] 设置最大减速度")
                print("-" * 80)
                sent, verified = setter.write_parameter_float32(device_id, PARAM_MAX_VELOCITY_DEC, max_deceleration, use_canfd=True)
                if sent:
                    device_success += 1
                    total_success_count += 1
                    if verified:
                        device_verified += 1
                        total_verified_count += 1
                time.sleep(0.2)
                step_num += 1

            # 设置最大速度
            if 5 in selected_params:
                print("\n" + "-" * 80)
                print(f"[{step_num}/{operations_per_device}] 设置最大减速度")
                print("-" * 80)
                sent, verified = setter.write_parameter_float32(device_id, PARAM_MAX_VELOCITY_DEC, max_velocity, use_canfd=True)
                if sent:
                    device_success += 1
                    total_success_count += 1
                    if verified:
                        device_verified += 1
                        total_verified_count += 1
                time.sleep(0.2)
                step_num += 1

        # 最后：保存到flash
        print("\n" + "-" * 80)
        print(f"[{step_num}/{operations_per_device}] 保存参数到flash")
        print("-" * 80)
        sent, verified = setter.save_to_flash(device_id, use_canfd=True)
        if sent:
            device_success += 1
            total_success_count += 1
            if verified:
                device_verified += 1
                total_verified_count += 1
        time.sleep(0.2)

        # 设备总结
        print(f"\n设备 {device_id} 总结: 发送 {device_success}/{operations_per_device}, 验证 {device_verified}/{operations_per_device}")

    # 总总结
    print("\n" + "=" * 80)
    print("批量操作完成")
    print("=" * 80)
    print(f"设备总数: {len(device_configs)}")
    print(f"总操作数: {total_operations}")
    print(f"发送成功: {total_success_count}/{total_operations}")
    print(f"验证成功: {total_verified_count}/{total_operations}")
    if total_verified_count == total_operations:
        print("✓ 所有操作均已验证成功")
    elif total_success_count == total_operations:
        print(f"⚠ 所有命令已发送，但有 {total_operations - total_verified_count} 个未收到正确响应")
    else:
        print(f"✗ 有 {total_operations - total_success_count} 个命令发送失败")
    print("=" * 80)

    # 提示：使用can_query.py验证
    print("\n提示: 使用以下命令验证参数是否设置成功:")
    print(f"  python3 can_query.py")
    print("  选择选项1（简易批量查询）查看所有设备参数")
    print()


if __name__ == "__main__":
    main()
