#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
CAN总线通信和批量查询工具
功能：发送CAN消息，接收响应并解析数据，支持批量查询多个设备
"""

import subprocess
import struct
import time
import re
import threading
import sys


class CANCommunicator:
    """CAN通信类"""

    def __init__(self, interface='can0'):
        """
        初始化CAN通信
        :param interface: CAN接口名称，默认为can0
        """
        self.interface = interface

    def send_can_message(self, can_id, data, use_canfd=True, silent=False):
        """
        发送CAN消息
        :param can_id: CAN ID (例如: '601')
        :param data: 数据部分 (例如: '03010004')
        :param use_canfd: 是否使用CAN FD格式（默认True）
        :param silent: 是否静默模式（不打印信息）
        :return: 发送是否成功
        """
        try:
            # 确保CAN ID格式正确
            # CAN FD使用8位EFF格式，标准CAN使用3位SFF格式
            if use_canfd:
                can_id_formatted = f"{int(can_id, 16):08X}"
            else:
                can_id_formatted = f"{int(can_id, 16):03X}"

            # 验证数据格式（必须是偶数个十六进制字符）
            if len(data) % 2 != 0:
                if not silent:
                    print(f"警告: 数据长度为奇数({len(data)}个字符)，将在前面补0")
                data = '0' + data

            if use_canfd:
                # CAN FD格式: cansend can0 00000601##003010004
                # flags设为0（无特殊标志）
                cmd = f"cansend {self.interface} {can_id_formatted}##0{data}"
            else:
                # 标准CAN格式: cansend can0 601#03010004
                cmd = f"cansend {self.interface} {can_id_formatted}#{data}"

            if not silent:
                print(f"发送CAN消息: {cmd}")

            result = subprocess.run(cmd, shell=True, capture_output=True, text=True, timeout=1)
            if result.returncode == 0:
                if not silent:
                    print("消息发送成功")
                return True
            else:
                if not silent:
                    print(f"消息发送失败")
                    if result.stderr:
                        # 只显示错误的第一行，避免显示整个帮助信息
                        error_line = result.stderr.split('\n')[0]
                        print(f"错误: {error_line}")
                return False
        except Exception as e:
            if not silent:
                print(f"发送消息时出错: {e}")
            return False

    def parse_data(self, data_hex):
        """
        解析CAN数据
        :param data_hex: 十六进制数据字符串 (例如: '080100040100000000' 或 '08010004010000000000000')
        """
        if not data_hex or len(data_hex) < 18:
            print(f"警告: 数据长度不足，至少需要9字节 (当前: {len(data_hex)//2}字节)")
            if not data_hex:
                return

        print(f"\n========== 数据解析 ==========")
        print(f"原始数据: {data_hex}")

        # 将十六进制字符串转换为字节
        data_bytes = bytes.fromhex(data_hex)

        # 打印所有字节
        print(f"字节数: {len(data_bytes)}")
        for i, byte in enumerate(data_bytes, 1):
            print(f"第{i}字节: 0x{byte:02X} ({byte})")

        # 确保至少有5个字节才能解析
        if len(data_bytes) < 5:
            print("错误: 数据太短，无法解析")
            return

        # 解析第3-4字节
        byte3 = data_bytes[2]
        byte4 = data_bytes[3]
        print(f"\n第3-4字节: 0x{byte3:02X}{byte4:02X}")
        self.interpret_bytes_3_4(byte3, byte4)

        # 解析第5字节（数据类型）
        byte5 = data_bytes[4]
        print(f"\n第5字节（数据类型）: 0x{byte5:02X}")

        # 获取第6-9字节的数据（如果存在）
        if len(data_bytes) >= 9:
            data_value_bytes = data_bytes[5:9]
            print(f"第6-9字节（数据值）: {data_value_bytes.hex().upper()}")
        else:
            print(f"警告: 数据不足9字节，无法提取完整的数据值")
            return

        if byte5 == 0x01:
            # int32类型（大端序）
            print("数据类型: INT32")
            value = struct.unpack('>i', data_value_bytes)[0]
            print(f"▶ 解析结果（十进制）: {value}")
            print(f"▶ 第6-9字节十进制值: {value}")
        elif byte5 == 0x02:
            # float32类型（大端序）
            print("数据类型: FLOAT32")
            value = struct.unpack('>f', data_value_bytes)[0]
            print(f"▶ 解析结果（十进制）: {value}")
            print(f"▶ 第6-9字节十进制值: {value}")
        else:
            print(f"未知的数据类型: 0x{byte5:02X}")

        print("=" * 30 + "\n")

    def interpret_bytes_3_4(self, byte3, byte4):
        """
        根据第3-4字节的值打印不同的信息
        你可以根据实际协议修改这个函数
        """
        value = (byte3 << 8) | byte4

        # 示例：根据不同的值打印不同信息
        if value == 0x0004:
            print("→ 这是参数查询响应")
        elif value == 0x0001:
            print("→ 这是状态查询响应")
        elif value == 0x0002:
            print("→ 这是配置响应")
        else:
            print(f"→ 未定义的命令类型: 0x{value:04X}")

    def query_device(self, device_id, command_data='03010004', use_canfd=True, param_name=None):
        """
        查询设备信息（完整流程）
        :param device_id: 设备ID (1-255)
        :param command_data: 命令数据（十六进制字符串，例如'03010004'）
        :param use_canfd: 是否使用CAN FD格式
        :param param_name: 参数名称（可选，用于显示）
        """
        # 构造CAN ID (0x600 + device_id)
        can_id_send = f"{0x600 + device_id:X}"  # 例如: 601
        can_id_receive = f"{0x700 + device_id:X}"  # 例如: 701

        print(f"\n{'='*50}")
        print(f"查询设备ID: {device_id}")
        if param_name:
            print(f"查询参数: {param_name}")
        print(f"发送CAN ID: {can_id_send} (0x{can_id_send})")
        print(f"期望接收CAN ID: {can_id_receive} (0x{can_id_receive})")
        print(f"命令数据: {command_data}")
        print(f"使用CAN FD: {'是' if use_canfd else '否'}")
        print(f"{'='*50}\n")

        # 先启动candump监听，再发送消息
        response_data = [None]  # 使用列表以便在线程中修改
        candump_process = [None]

        def start_listening():
            """在单独线程中启动监听"""
            try:
                # 格式化目标ID
                if use_canfd:
                    target_id_formatted = f"{int(can_id_receive, 16):08X}"
                else:
                    target_id_formatted = f"{int(can_id_receive, 16):03X}"

                print(f"启动监听，等待ID为{target_id_formatted}的响应...")

                # 启动candump
                process = subprocess.Popen(
                    ['candump', self.interface],
                    stdout=subprocess.PIPE,
                    stderr=subprocess.PIPE,
                    text=True,
                    bufsize=1
                )
                candump_process[0] = process

                # 逐行读取
                for line in process.stdout:
                    line = line.strip()
                    if target_id_formatted in line:
                        print(f"收到原始数据: {line}")

                        # 解析数据
                        match = re.search(r'\[(\d+)\]\s+((?:[0-9A-Fa-f]{2}\s*)+)', line)
                        if match:
                            data_len = int(match.group(1))
                            data_bytes = match.group(2).replace(' ', '')
                            print(f"数据长度: {data_len} 字节")
                            print(f"接收到CAN消息 (ID={target_id_formatted}): {data_bytes}")
                            response_data[0] = data_bytes
                            break
            except Exception as e:
                print(f"监听出错: {e}")

        # 启动监听线程
        listen_thread = threading.Thread(target=start_listening, daemon=True)
        listen_thread.start()

        # 等待监听就绪
        time.sleep(0.3)

        # 发送消息
        if self.send_can_message(can_id_send, command_data, use_canfd=use_canfd):
            # 等待响应
            listen_thread.join(timeout=3)

            # 终止candump进程
            if candump_process[0]:
                candump_process[0].terminate()

            if response_data[0]:
                # 解析数据
                self.parse_data(response_data[0])
            else:
                print("未收到设备响应")
        else:
            print("发送消息失败")
            if candump_process[0]:
                candump_process[0].terminate()

    def batch_query_simple(self, device_id, command_data, use_canfd=True):
        """
        简化的查询方法（不显示详细调试信息）
        用于批量查询
        :return: (success, value, data_type) 或 (False, None, None)
        """
        can_id_send = f"{0x600 + device_id:X}"
        can_id_receive = f"{0x700 + device_id:X}"

        response_data = [None]
        candump_process = [None]

        def start_listening():
            try:
                target_id_formatted = f"{int(can_id_receive, 16):08X}"
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

        # 使用静默模式发送
        success = self.send_can_message(can_id_send, command_data, use_canfd=use_canfd, silent=True)

        if success:
            listen_thread.join(timeout=3)
            if candump_process[0]:
                candump_process[0].terminate()

            if response_data[0]:
                try:
                    data_bytes = bytes.fromhex(response_data[0])
                    if len(data_bytes) >= 9:
                        byte5 = data_bytes[4]
                        data_value_bytes = data_bytes[5:9]

                        if byte5 == 0x01:
                            value = struct.unpack('>i', data_value_bytes)[0]
                            return True, value, 'INT32'
                        elif byte5 == 0x02:
                            value = struct.unpack('>f', data_value_bytes)[0]
                            return True, value, 'FLOAT32'
                except Exception:
                    pass
        else:
            if candump_process[0]:
                candump_process[0].terminate()

        return False, None, None


def batch_query_all_devices():
    """批量查询所有设备的所有参数（简洁版）"""

    # 创建通信对象
    can = CANCommunicator('can0')

    # 定义参数配置：命令数据、参数名称
    params = [
        ('03010003', '是否开启限位'),
        ('03010008', '位置上限反馈'),
        ('03010009', '位置下限反馈'),
        ('0301000B', '速度最大值'),
        ('0301000C', '加速度最大值'),
        ('0301000D', '电流最大值'),
        ('0301000F', '减速度最大值'),
    ]

    # 设备ID列表
    device_ids = [1, 2, 3, 4, 5, 6]

    print("\n" + "=" * 80)
    print("CAN总线批量查询工具")
    print("=" * 80)
    print(f"查询 {len(device_ids)} 个设备 × {len(params)} 个参数 = {len(device_ids) * len(params)} 次查询")
    print("=" * 80)

    # 存储查询结果
    results = []

    # 对每个设备查询所有参数
    for device_id in device_ids:
        for command_data, param_name in params:
            success, value, data_type = can.batch_query_simple(device_id, command_data, use_canfd=True)

            if success and value is not None:
                results.append((f"设备{device_id}-{param_name}", device_id, value, data_type))
            else:
                results.append((f"设备{device_id}-{param_name}", device_id, None, 'ERROR'))

            # 查询间延迟
            time.sleep(0.05)

    # 打印汇总结果
    print("\n" + "=" * 80)
    print("查询结果汇总")
    print("=" * 80)
    print(f"{'参数名称':<20} {'设备ID':<10} {'数值（十进制）':<20} {'数据类型':<10}")
    print("-" * 80)

    for param_name, device_id, value, data_type in results:
        if value is not None:
            if data_type == 'FLOAT32':
                value_str = f"{value:.2f}"
            else:
                value_str = f"{value}"
        else:
            value_str = "N/A"

        print(f"{param_name:<20} {device_id:<10} {value_str:<20} {data_type:<10}")

    print("=" * 80)
    print(f"总计查询: {len(results)} 个参数")
    success_count = sum(1 for _, _, v, _ in results if v is not None)
    print(f"成功: {success_count} 个, 失败: {len(results) - success_count} 个")
    print("=" * 80 + "\n")

    return results


def detailed_query_all_devices():
    """批量查询所有设备的所有参数（详细版）"""

    # 创建通信对象
    can = CANCommunicator('can0')

    # 定义参数配置：命令数据、参数名称
    params = [
        ('03010003', '是否开启限位'),
        ('03010008', '位置上限反馈'),
        ('03010009', '位置下限反馈'),
        ('0301000B', '速度最大值'),
        ('0301000C', '加速度最大值'),
        ('0301000D', '电流最大值'),
        ('0301000F', '减速度最大值'),
    ]

    # 设备ID列表
    device_ids = [1, 2, 3, 4, 5, 6]

    print("\n开始批量查询设备参数...")
    print("=" * 70)
    print(f"将查询 {len(device_ids)} 个设备，每个设备查询 {len(params)} 个参数")
    print(f"总计: {len(device_ids) * len(params)} 次查询")
    print("=" * 70)

    # 对每个设备查询所有参数
    for device_id in device_ids:
        print(f"\n{'#' * 70}")
        print(f"【设备 {device_id}】")
        print(f"{'#' * 70}")

        for command_data, param_name in params:
            print(f"\n{'*' * 70}")
            print(f"  查询: {param_name}")
            print(f"{'*' * 70}")

            can.query_device(
                device_id=device_id,
                command_data=command_data,
                use_canfd=True,
                param_name=param_name
            )

            # 查询间添加短暂延迟，避免总线拥塞
            time.sleep(0.3)

        # 设备间添加稍长延迟
        print(f"\n{'─' * 70}")
        print(f"设备 {device_id} 查询完成")
        print(f"{'─' * 70}")
        time.sleep(0.5)

    print("\n" + "=" * 70)
    print("所有设备批量查询完成！")
    print("=" * 70)


def main():
    """主函数"""
    print("=" * 80)
    print("CAN总线通信工具")
    print("=" * 80)
    print("\n请选择运行模式：")
    print("1. 简洁版批量查询（推荐日常使用）")
    print("2. 详细版批量查询（调试用，显示完整信息）")
    print("3. 单个设备查询（自定义）")
    print("0. 退出")
    print("-" * 80)

    choice = input("请输入选项 (默认1): ").strip()

    if not choice:
        choice = '1'

    if choice == '1':
        print("\n运行简洁版批量查询...")
        batch_query_all_devices()

    elif choice == '2':
        print("\n运行详细版批量查询...")
        detailed_query_all_devices()

    elif choice == '3':
        can = CANCommunicator('can0')

        try:
            device_id = int(input("请输入设备ID (1-6): ").strip())
            command_data = input("请输入命令数据 (例如: 03010008): ").strip()
            param_name = input("请输入参数名称 (可选): ").strip()

            if not param_name:
                param_name = None

            can.query_device(
                device_id=device_id,
                command_data=command_data,
                use_canfd=True,
                param_name=param_name
            )
        except ValueError:
            print("输入错误，请输入有效的数字")
        except KeyboardInterrupt:
            print("\n用户取消操作")

    elif choice == '0':
        print("退出程序")
        sys.exit(0)

    else:
        print("无效的选项")


if __name__ == "__main__":
    try:
        main()
    except KeyboardInterrupt:
        print("\n\n程序被用户中断")
        sys.exit(0)
