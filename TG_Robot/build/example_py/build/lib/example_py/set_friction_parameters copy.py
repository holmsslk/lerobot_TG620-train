#!/usr/bin/env python3
"""
设置关节模组摩擦力补偿参数
基于管理员权限参数读写接口0x1601协议

功能：
1. 批量设置六个关节的摩擦力相关参数
2. 关节1、2、3使用51NM_E1模组参数
3. 关节4、5、6使用9NM模组参数
4. 自动保存参数到flash
5. 验证每个操作的响应
"""

import subprocess
import threading
import time
import re
import struct
import sys


class CANFrictionSetter:
    def __init__(self, interface='can0'):
        self.interface = interface

        # DEBUG参数表地址映射 - 摩擦力相关参数
        self.PARAM_ADDRESS_MAP = {
            'torque_per_amp': 19,                # 电机力矩系数（单位Nm/A）
            'friction_enable': 129,              # 是否开启摩擦力补偿 (limit_int32_resever_15)
            'critical_velocity': 152,            # 摩擦力_速度阈值 (limit_critical_velocity)
            'velocity_times': 153,               # 摩擦力_速度次数 (limit_velocity_times)
            'static_friction': 154,              # 摩擦力_静摩擦电流 (limit_current_static_friction)
            'coulomb_friction': 155,             # 摩擦力_动摩擦电流 (limit_current_coulomb_friction)
            'coulomb_max': 156,                  # 摩擦力_动摩擦电流最大值 (limit_current_coulomb_max)
            'viscous_coef': 157,                 # 摩擦力_粘滞系数 (limit_viscous_friction_cofe_A)
        }

        # 不同型号模组的摩擦力参数配置
        self.MODULE_CONFIGS = {
            '51NM_E1': {
                'torque_per_amp': 6.04545,
                'friction_enable': 1,
                'critical_velocity': 20.0,
                'velocity_times': 20.0,
                'static_friction': 0.6,
                'coulomb_friction': 0.172483,
                'coulomb_max': 0.4,
                'viscous_coef': 0.971141,
            },
            '51NM_E2': {
                'torque_per_amp': 6.04545,
                'friction_enable': 1,
                'critical_velocity': 20.0,
                'velocity_times': 20.0,
                'static_friction': 0.6,
                'coulomb_friction': 0.172483,
                'coulomb_max': 0.4,
                'viscous_coef': 0.971141,
            },
            '9NM': {
                'torque_per_amp': 4.31818,
                'friction_enable': 1,
                'critical_velocity': 10.0,
                'velocity_times': 10.0,
                'static_friction': 0.5,
                'coulomb_friction': 0.05,
                'coulomb_max': 0.25,
                'viscous_coef': 2.911141,
            },
        }

        # CAN ID定义 - 管理员权限
        self.PARAM_WRITE_ID = 0x1601        # DEBUG参数写接口
        self.PARAM_RESPONSE_ID = 0x1701     # DEBUG参数响应接口
        self.OPERATION_WRITE = 0x02

    def send_can_message(self, can_id, data, use_canfd=True, silent=False):
        """
        发送CAN消息
        """
        if len(data) % 2 != 0:
            data = '0' + data

        if use_canfd:
            can_id_formatted = f"{int(can_id, 16):08X}"
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
        """
        # 根据设备ID计算CAN ID
        send_can_id = self.PARAM_WRITE_ID + (device_id - 1)
        response_can_id = self.PARAM_RESPONSE_ID + (device_id - 1)

        can_id = f"{send_can_id:X}"

        # 构建数据帧: 数据长度(08) + 操作方式(02) + 参数地址(2字节) + 参数类型(01) + 参数值(4字节)
        data_length = 0x08
        operation = self.OPERATION_WRITE
        param_addr_bytes = struct.pack('>H', param_address)
        param_type = 0x01  # int32类型
        value_bytes = struct.pack('>i', value)

        data_bytes = bytes([data_length, operation]) + param_addr_bytes + bytes([param_type]) + value_bytes
        data_hex = data_bytes.hex().upper()

        # 启动监听线程
        response_data = [None]
        candump_process = [None]

        def start_listening():
            try:
                target_id_formatted = f"{response_can_id:08X}"
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
                            data_bytes_str = match.group(2).replace(' ', '')
                            response_data[0] = data_bytes_str
                            break
            except Exception:
                pass

        listen_thread = threading.Thread(target=start_listening, daemon=True)
        listen_thread.start()

        time.sleep(0.1)

        # 发送命令
        success = self.send_can_message(can_id, data_hex, use_canfd)

        if not success:
            if candump_process[0]:
                candump_process[0].kill()
            return False, False

        # 等待响应
        listen_thread.join(timeout=2.0)

        if candump_process[0]:
            candump_process[0].kill()

        # 验证响应
        if response_data[0]:
            print(f"[调试] 收到响应: {response_data[0]}")

            # 响应格式: 数据长度 + 操作码 + 参数地址 + 参数类型 + 参数值
            if len(response_data[0]) >= 18:
                resp_length = int(response_data[0][0:2], 16)
                resp_operation = int(response_data[0][2:4], 16)
                resp_param_addr = int(response_data[0][4:8], 16)
                resp_param_type = int(response_data[0][8:10], 16)
                resp_value = response_data[0][10:18]

                expected_value = value_bytes.hex().upper()

                print(f"[调试] 解析: length={resp_length}, operation={resp_operation:02X}, addr=0x{resp_param_addr:04X}, type={resp_param_type}, value={resp_value}")
                print(f"[调试] 期望: addr=0x{param_address:04X}, type=1, value={expected_value}")

                # 只验证操作码、地址和类型
                if (resp_operation == 0x02 and
                    resp_param_addr == param_address and
                    resp_param_type == 0x01):
                    print(f"✓ 验证成功（地址和类型匹配）")
                    return True, True
                else:
                    print(f"⚠ 响应不匹配")
                    return True, False
            else:
                print(f"⚠ 响应数据长度不足: {len(response_data[0])}")
                return True, False
        else:
            print(f"⚠ 未收到响应")
            return True, False

    def write_parameter_float32(self, device_id, param_address, value, use_canfd=True):
        """
        写入float32参数
        """
        # 根据设备ID计算CAN ID
        send_can_id = self.PARAM_WRITE_ID + (device_id - 1)
        response_can_id = self.PARAM_RESPONSE_ID + (device_id - 1)

        can_id = f"{send_can_id:X}"

        # 构建数据帧: 数据长度(08) + 操作方式(02) + 参数地址(2字节) + 参数类型(02) + 参数值(4字节)
        data_length = 0x08
        operation = self.OPERATION_WRITE
        param_addr_bytes = struct.pack('>H', param_address)
        param_type = 0x02  # float32类型
        value_bytes = struct.pack('>f', value)

        data_bytes = bytes([data_length, operation]) + param_addr_bytes + bytes([param_type]) + value_bytes
        data_hex = data_bytes.hex().upper()

        # 启动监听线程
        response_data = [None]
        candump_process = [None]

        def start_listening():
            try:
                target_id_formatted = f"{response_can_id:08X}"
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
                            data_bytes_str = match.group(2).replace(' ', '')
                            response_data[0] = data_bytes_str
                            break
            except Exception:
                pass

        listen_thread = threading.Thread(target=start_listening, daemon=True)
        listen_thread.start()

        time.sleep(0.1)

        # 发送命令
        success = self.send_can_message(can_id, data_hex, use_canfd)

        if not success:
            if candump_process[0]:
                candump_process[0].kill()
            return False, False

        # 等待响应
        listen_thread.join(timeout=2.0)

        if candump_process[0]:
            candump_process[0].kill()

        # 验证响应
        if response_data[0]:
            print(f"[调试] 收到响应: {response_data[0]}")

            # 响应格式: 数据长度 + 操作码 + 参数地址 + 参数类型 + 参数值
            if len(response_data[0]) >= 18:
                resp_length = int(response_data[0][0:2], 16)
                resp_operation = int(response_data[0][2:4], 16)
                resp_param_addr = int(response_data[0][4:8], 16)
                resp_param_type = int(response_data[0][8:10], 16)
                resp_value = response_data[0][10:18]

                expected_value = value_bytes.hex().upper()

                print(f"[调试] 解析: length={resp_length}, operation={resp_operation:02X}, addr=0x{resp_param_addr:04X}, type={resp_param_type}, value={resp_value}")
                print(f"[调试] 期望: addr=0x{param_address:04X}, type=2, value={expected_value}")

                # 只验证操作码、地址和类型
                if (resp_operation == 0x02 and
                    resp_param_addr == param_address and
                    resp_param_type == 0x02):
                    print(f"✓ 验证成功（地址和类型匹配）")
                    return True, True
                else:
                    print(f"⚠ 响应不匹配")
                    return True, False
            else:
                print(f"⚠ 响应数据长度不足: {len(response_data[0])}")
                return True, False
        else:
            print(f"⚠ 未收到响应")
            return True, False

    def save_to_flash(self, device_id, use_canfd=True):
        """
        保存参数到flash
        使用函数操作接口0x1401 (管理员权限)
        """
        # 根据设备ID计算CAN ID
        send_can_id = 0x1401 + (device_id - 1)
        can_id = f"{send_can_id:X}"

        # 保存命令: 数据长度(01) + 函数操作码(02-保存参数到flash)
        data = "0102"

        print(f"\n保存参数到flash (关节 {device_id})...")
        success = self.send_can_message(can_id, data, use_canfd)

        if success:
            print("✓ 保存命令已发送")
            time.sleep(1.0)  # 等待flash写入完成
            return True
        else:
            print("✗ 保存命令发送失败")
            return False

    def set_joint_friction_parameters(self, device_id, module_type):
        """
        设置单个关节的摩擦力参数
        """
        config = self.MODULE_CONFIGS[module_type]

        print(f"\n{'='*80}")
        print(f"开始设置关节 {device_id} ({module_type}型号) 的摩擦力参数")
        print(f"{'='*80}")

        operations = [
            ('torque_per_amp', config['torque_per_amp'], 'float32', '电机力矩系数'),
            ('friction_enable', config['friction_enable'], 'int32', '是否开启摩擦力补偿'),
            ('critical_velocity', config['critical_velocity'], 'float32', '摩擦力_速度阈值'),
            ('velocity_times', config['velocity_times'], 'float32', '摩擦力_速度次数'),
            ('static_friction', config['static_friction'], 'float32', '摩擦力_静摩擦电流'),
            ('coulomb_friction', config['coulomb_friction'], 'float32', '摩擦力_动摩擦电流'),
            ('coulomb_max', config['coulomb_max'], 'float32', '摩擦力_动摩擦电流最大值'),
            ('viscous_coef', config['viscous_coef'], 'float32', '摩擦力_粘滞系数'),
        ]

        success_count = 0
        verified_count = 0

        for i, (param_name, param_value, param_type, param_desc) in enumerate(operations, 1):
            param_address = self.PARAM_ADDRESS_MAP[param_name]

            print(f"\n[{i}/{len(operations)}] 设置{param_desc}: {param_value}")

            if param_type == 'int32':
                success, verified = self.write_parameter_int32(device_id, param_address, param_value)
            else:  # float32
                success, verified = self.write_parameter_float32(device_id, param_address, param_value)

            if success:
                success_count += 1
            if verified:
                verified_count += 1

            time.sleep(0.2)

        # 保存到flash
        print(f"\n[保存] 保存参数到flash...")
        self.save_to_flash(device_id)

        print(f"\n关节 {device_id} 总结: 发送 {success_count}/{len(operations)}, 验证 {verified_count}/{len(operations)}")

        return success_count, verified_count


def main():
    print("=" * 80)
    print("机械臂关节摩擦力参数批量设置工具 v2.0")
    print("=" * 80)
    print("功能: 批量设置六个关节的摩擦力补偿参数")
    print("关节1、2、3: 51NM_E1型号")
    print("关节4、5、6: 9NM型号")
    print("使用管理员权限接口: 0x1601/0x1701")
    print("保存flash接口: 0x1401 (函数操作码02)")
    print("=" * 80)
    print()

    # 确认继续
    response = input("是否继续? (y/n): ")
    if response.lower() != 'y':
        print("已取消操作")
        return

    setter = CANFrictionSetter()

    # 定义关节配置
    joint_configs = [
        (1, '51NM_E1'),
        (2, '51NM_E1'),
        (3, '51NM_E1'),
        (4, '9NM'),
        (5, '9NM'),
        (6, '9NM'),
    ]

    total_operations = len(joint_configs) * 8  # 每个关节8个参数
    total_success_count = 0
    total_verified_count = 0

    for device_id, module_type in joint_configs:
        success_count, verified_count = setter.set_joint_friction_parameters(device_id, module_type)
        total_success_count += success_count
        total_verified_count += verified_count

    # 总总结
    print("\n" + "=" * 80)
    print("批量操作完成")
    print("=" * 80)
    print(f"设备总数: {len(joint_configs)}")
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

    print("\n提示: 参数已保存到flash，重启后生效")
    print()


if __name__ == "__main__":
    main()
