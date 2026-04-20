#!/usr/bin/env python3
"""
关节模组PN/SN码批量读取工具
基于管理员权限参数读写接口0x1601协议
关节二为1602...1606
支持批量读取多个模组
"""

import subprocess
import threading
import time
import re
import struct
import sys

class CANParameterReader:
    def __init__(self, interface='can0'):
        self.interface = interface
        
        # DEBUG参数表地址映射
        self.PARAM_ADDRESS_MAP = {
            'pn_3': 0x0002,                # 产品PN码3
            'pn_2': 0x0003,                # 产品PN码2
            'pn_1': 0x0004,                # 产品PN码1
            'pn_0': 0x0005,                # 产品PN码0
            'sn_3': 0x0006,                # 产品SN码3
            'sn_2': 0x0007,                # 产品SN码2
            'sn_1': 0x0008,                # 产品SN码1
            'sn_0': 0x0009,                # 产品SN码0
        }
        
        # CAN ID定义 - 管理员权限
        self.PARAM_READ_ID = 0x1601        # DEBUG参数读接口
        self.PARAM_RESPONSE_ID = 0x1701    # DEBUG参数响应接口
        self.OPERATION_READ = 0x01

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

    def read_parameter_int32(self, device_id, param_address, use_canfd=True):
        """
        读取int32参数
        :param device_id: 设备ID (1-6)
        :param param_address: 参数地址
        :return: (success, value_string)
        """
        # 根据设备ID计算CAN ID
        # 关节1: 0x1601/0x1701
        # 关节2: 0x1602/0x1702
        # 关节3: 0x1603/0x1703
        # ...
        send_can_id = self.PARAM_READ_ID + (device_id - 1)
        response_can_id = self.PARAM_RESPONSE_ID + (device_id - 1)

        can_id = f"{send_can_id:X}"

        # 构建数据帧: 数据长度(03) + 操作方式(01) + 参数地址(2字节)
        data_length = 0x03
        operation = self.OPERATION_READ
        param_addr_bytes = struct.pack('>H', param_address)

        data_bytes = bytes([data_length, operation]) + param_addr_bytes
        data_hex = data_bytes.hex().upper()

        print(f"\n读取参数:")
        print(f"  关节ID: {device_id}")
        print(f"  发送CAN ID: 0x{send_can_id:04X}")
        print(f"  响应CAN ID: 0x{response_can_id:04X}")
        print(f"  参数地址: 0x{param_address:04X}")
        print(f"  数据帧: {data_hex}")

        # 响应 ID
        response_id = response_can_id

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
            return False, None

        # 等待响应
        print(f"  等待响应 (ID=0x{response_id:08X})...", end=" ")
        listen_thread.join(timeout=2.0)

        if candump_process[0]:
            candump_process[0].terminate()

        if response_data[0]:
            try:
                # 解析响应数据
                response_hex = response_data[0]
                print(f"收到响应: {response_hex}")

                # 响应格式: 08 01 参数地址(2字节) 01 参数数据(4字节) 填充(3字节)
                # 例如: 08010002014C483430000000
                #       ^^ ^^ ^^^^ ^^ ^^^^^^^^ ^^^^^^
                #       0  2  4    8  10      18    24
                # 数据长度、操作、地址、类型、参数数据、填充
                if len(response_hex) >= 18:
                    # 提取参数数据部分 (从位置10开始，8个十六进制字符 = 4字节)
                    param_data_hex = response_hex[10:18]
                    param_bytes = bytes.fromhex(param_data_hex)

                    # 解析为ASCII字符串，去除空字节
                    value_str = param_bytes.decode('ascii', errors='ignore').strip('\x00').strip()
                    print(f"✓ 读取成功: '{value_str}'")
                    return True, value_str
                else:
                    print(f"✗ 响应数据长度不足: {len(response_hex)}")
                    return True, None
            except Exception as e:
                print(f"✗ 解析响应数据错误: {e}")
                return True, None
        else:
            print(f"✗ 无响应")
            return False, None

    def read_pn_codes(self, device_id):
        """
        读取产品PN码
        :param device_id: 设备ID
        :return: (pn_code, pn_parts)
        """
        print(f"\n读取设备 {device_id} PN码:")
        print("-" * 50)
        
        pn_parts = []
        pn_addresses = [
            self.PARAM_ADDRESS_MAP['pn_3'],
            self.PARAM_ADDRESS_MAP['pn_2'], 
            self.PARAM_ADDRESS_MAP['pn_1'],
            self.PARAM_ADDRESS_MAP['pn_0']
        ]
        
        part_names = ['PN码3', 'PN码2', 'PN码1', 'PN码0']
        
        for i, addr in enumerate(pn_addresses):
            success, value = self.read_parameter_int32(device_id, addr)
            if success and value:
                pn_parts.append(value)
                print(f"  ✓ {part_names[i]}: '{value}'")
            else:
                pn_parts.append("")
                print(f"  ✗ {part_names[i]}: 读取失败")
            
            time.sleep(0.2)
        
        # 组合PN码: pn_3 + pn_2 + pn_1 + pn_0
        pn_code = "".join(pn_parts).strip()
        print(f"  完整PN码: '{pn_code}'")
        
        return pn_code, pn_parts

    def read_sn_codes(self, device_id):
        """
        读取产品SN码
        :param device_id: 设备ID
        :return: (sn_code, sn_parts)
        """
        print(f"\n读取设备 {device_id} SN码:")
        print("-" * 50)
        
        sn_parts = []
        sn_addresses = [
            self.PARAM_ADDRESS_MAP['sn_3'],
            self.PARAM_ADDRESS_MAP['sn_2'],
            self.PARAM_ADDRESS_MAP['sn_1'], 
            self.PARAM_ADDRESS_MAP['sn_0']
        ]
        
        part_names = ['SN码3', 'SN码2', 'SN码1', 'SN码0']
        
        for i, addr in enumerate(sn_addresses):
            success, value = self.read_parameter_int32(device_id, addr)
            if success and value:
                sn_parts.append(value)
                print(f"  ✓ {part_names[i]}: '{value}'")
            else:
                sn_parts.append("")
                print(f"  ✗ {part_names[i]}: 读取失败")
            
            time.sleep(0.2)
        
        # 组合SN码: sn_3 + sn_2 + sn_1 + sn_0
        sn_code = "".join(sn_parts).strip()
        print(f"  完整SN码: '{sn_code}'")
        
        return sn_code, sn_parts



def get_user_input():
    """
    获取用户输入，配置要读取的设备
    """
    print("=" * 80)
    print("关节模组PN/SN码批量读取工具")
    print("=" * 80)

    # 主菜单
    print("\n请选择操作模式:")
    print("  1. 批量模式 - 读取所有模组(ID 1-6)的PN/SN码 (默认)")
    print("  2. 单设备模式 - 读取指定模组的PN/SN码")

    mode_choice = input("\n请输入选项 (1/2, 回车默认为1): ").strip()
    if mode_choice == "":
        mode_choice = "1"

    device_ids = []

    if mode_choice == "1":
        # 批量模式 - 读取所有设备
        device_ids = [1, 2, 3, 4, 5, 6]
        print(f"\n✓ 已选择批量模式 - 将读取所有设备(ID 1-6)")

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
                    device_ids = [device_id]
                    break
                else:
                    print("✗ 设备ID必须在1-6之间，请重新输入")
            except ValueError:
                print("✗ 请输入有效的数字")
    else:
        print(f"✗ 无效选项，使用默认批量模式")
        device_ids = [1, 2, 3, 4, 5, 6]

    return device_ids


def main():
    """
    主函数：批量读取PN/SN码
    """
    # 获取用户配置
    device_ids = get_user_input()

    print(f"\n目标设备: {device_ids}")
    print("=" * 80)

    # 创建参数读取器
    reader = CANParameterReader('can0')

    # 等待用户确认
    print("\n按回车键开始读取，或按Ctrl+C取消...")
    try:
        input()
    except KeyboardInterrupt:
        print("\n操作已取消")
        return

    total_devices = len(device_ids)
    successful_devices = 0
    results = {}

    # 批量处理所有设备
    for idx, device_id in enumerate(device_ids, 1):
        print("\n" + "=" * 80)
        print(f"关节 {device_id} [{idx}/{total_devices}]")
        print("=" * 80)

        try:
            # 读取PN码
            pn_code, pn_parts = reader.read_pn_codes(device_id)

            # 读取SN码
            sn_code, sn_parts = reader.read_sn_codes(device_id)

            # 保存结果
            results[device_id] = {
                'pn_code': pn_code,
                'sn_code': sn_code,
                'pn_parts': pn_parts,
                'sn_parts': sn_parts,
                'success': True
            }

            successful_devices += 1
            print(f"\n✓ 关节 {device_id} 读取完成")

        except Exception as e:
            print(f"\n✗ 关节 {device_id} 读取失败: {e}")
            results[device_id] = {
                'error': str(e),
                'success': False
            }

        # 设备间延迟
        if idx < total_devices:
            time.sleep(0.5)

    # 总总结
    print("\n" + "=" * 80)
    print("批量读取完成")
    print("=" * 80)
    print(f"设备总数: {total_devices}")
    print(f"成功读取: {successful_devices}")
    print(f"读取失败: {total_devices - successful_devices}")

    # 打印详细结果
    print(f"\n详细结果:")
    print("-" * 80)
    for device_id, result in results.items():
        print(f"\n关节 {device_id}:")
        if result.get('success', False):
            print(f"  PN码: {result['pn_code']}")
            print(f"  SN码: {result['sn_code']}")
        else:
            print(f"  错误: {result.get('error', '未知错误')}")

    print("=" * 80)

    # 自动保存结果到文件
    filename = f"joint_modules_pn_sn_{time.strftime('%Y%m%d_%H%M%S')}.txt"
    with open(filename, 'w', encoding='utf-8') as f:
        f.write("关节模组PN/SN码读取结果\n")
        f.write(f"读取时间: {time.strftime('%Y-%m-%d %H:%M:%S')}\n")
        f.write("=" * 60 + "\n\n")

        for device_id in sorted(results.keys()):
            result = results[device_id]
            if result.get('success', False):
                f.write(f"关节 {device_id}:  PN码: {result['pn_code']}  SN码: {result['sn_code']}\n")
            else:
                f.write(f"关节 {device_id}:  读取失败\n")

    print(f"\n✓ 结果已自动保存到: {filename}\n")


if __name__ == "__main__":
    main()