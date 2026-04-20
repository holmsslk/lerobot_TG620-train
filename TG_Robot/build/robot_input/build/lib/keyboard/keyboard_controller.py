#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from std_msgs.msg import UInt8, Float64MultiArray, String, Bool
from robot_interfaces.msg import MoveCAction, StateAction, KeyPressedAction
from rclpy.qos import QoSProfile
import sys, select, termios, tty
import os
import sqlite3
from pathlib import Path
from pynput import keyboard as pynput_keyboard
from keyboard.robot_messages import *
from keyboard.key_mappings import *

class ModeHandler:
    def __init__(self, node):
        self.node = node
        self.exit_flag = False
        self.listener = None

    def _start_esc_listener(self):
        def on_press(key):
            try:
                if key == pynput_keyboard.Key.esc:
                    self.exit_flag = True
                    if self.listener is not None:
                        self.listener.stop()
                    return False
            except AttributeError:
                pass
        if self.listener is not None:
            self.listener.stop()

        self.listener = pynput_keyboard.Listener(on_press=on_press)
        self.listener.start()

    def _stop_esc_listener(self):
        if self.listener is not None:
            self.listener.stop()
            self.listener = None

    def _clear_stdin_buffer(self):
        import sys
        import termios
        termios.tcflush(sys.stdin, termios.TCIFLUSH)

    def handle_mode(self, mode):
        self._clear_stdin_buffer()
        self.exit_flag = False
        self._stop_esc_listener()

        handlers = {
            BACKTOSTART: self._handle_back_to_start,
            DISABLE: self._handle_disable,
            JOINTCONTROL: self._handle_joint_control,
            CARTESIAN: self._handle_cartesian,
            MOVEJ: self._handle_movej,
            MOVEL: self._handle_movel,
            MOVEC: self._handle_movec,
            TEACH: self._handle_teach,
            TEACHREPEAT: self._handle_teachrepeat,
            STATEOPERATION: self._handle_save_delete_state,
            LOADSTATE: self._handle_loadstate,
            BACKTOINITIAL: self._handle_back_to_initial
        }
        handler = handlers.get(mode)
        if handler:
            handler()
        self._stop_esc_listener()
        self.exit_flag = False
        return

    def _handle_back_to_start(self):
        print(BACKTOSTART_MSG)
        msg = UInt8()
        msg.data = BACKTOSTART
        self.node.current_mode = msg.data
        self.node.mode_pub_.publish(msg)

        self._start_esc_listener()
        while not self.exit_flag:
            pass

    def _handle_disable(self):
        print(DISABLE_MSG)
        msg = UInt8()
        msg.data = DISABLE
        self.node.current_mode = msg.data
        self.node.mode_pub_.publish(msg)

        self._start_esc_listener()
        while not self.exit_flag:
            pass
    
    def _handle_joint_control(self):
        print(JOINTCONTROL_MSG)
        msg = UInt8()
        msg.data = JOINTCONTROL
        self.node.current_mode = msg.data
        self.node.mode_pub_.publish(msg)

        self._start_esc_listener()

        fd = sys.stdin.fileno()
        old_settings = termios.tcgetattr(fd)
        try:
            tty.setraw(sys.stdin.fileno())
            def on_press(key):
                try:
                    if hasattr(key, 'char') and key.char in JOINT_CONTROL_KEYS:
                        action = JOINT_CONTROL_KEYS[key.char]
                        msg = KeyPressedAction()
                        msg.key_code = action
                        msg.is_pressed = True
                        self.node.jointctrl_pub_.publish(msg)
                except AttributeError:
                    pass

            def on_release(key):
                try:
                    if hasattr(key, 'char') and key.char in JOINT_CONTROL_KEYS:
                        action = JOINT_CONTROL_KEYS[key.char]
                        msg = KeyPressedAction()
                        msg.key_code = action
                        msg.is_pressed = False
                        self.node.jointctrl_pub_.publish(msg)
                except AttributeError:
                    pass

                if key == pynput_keyboard.Key.esc:
                    return False
        
            with pynput_keyboard.Listener(on_press=on_press, on_release=on_release) as listener:
                listener.join()
        finally:
            termios.tcsetattr(fd, termios.TCSADRAIN, old_settings)
    
    def _handle_cartesian(self):
        print(CARTESIAN_MSG)
        msg = UInt8()
        msg.data = CARTESIAN
        self.node.current_mode = msg.data
        self.node.mode_pub_.publish(msg)

        self._start_esc_listener()

        fd = sys.stdin.fileno()
        old_settings = termios.tcgetattr(fd)

        try:
            tty.setraw(sys.stdin.fileno())
            def on_press(key):
                try:
                    if hasattr(key, 'char') and key.char in CARTESIAN_CONTROL_KEYS:
                        action = CARTESIAN_CONTROL_KEYS[key.char]
                        msg = KeyPressedAction()
                        msg.key_code = action
                        msg.is_pressed = True
                        self.node.cartesian_pub_.publish(msg)
                except AttributeError:
                    pass

            def on_release(key):
                try:
                    if hasattr(key, 'char') and key.char in CARTESIAN_CONTROL_KEYS:
                        action = CARTESIAN_CONTROL_KEYS[key.char]
                        msg = KeyPressedAction()
                        msg.key_code = action
                        msg.is_pressed = False
                        self.node.cartesian_pub_.publish(msg)
                except AttributeError:
                    pass
                
                if key == pynput_keyboard.Key.esc:
                    return False
                
            with pynput_keyboard.Listener(on_press=on_press, on_release=on_release) as listener:
                listener.join()
        finally:
            termios.tcsetattr(fd, termios.TCSADRAIN, old_settings)
                        

    def _handle_movej(self):
        print(MOVEJ_MSG)
        msg = UInt8()
        msg.data = MOVEJ
        self.node.current_mode = msg.data
        self.node.mode_pub_.publish(msg)

        all_joint_positions = []
        empty_input_count = 0
        
        self._start_esc_listener()

        while not self.exit_flag:
            try:
                rlist, _, _ = select.select([sys.stdin], [], [], 0.1)
                if self.exit_flag:
                    # print("ESC detected. Exiting...")
                    return
                if rlist:
                    input_str = sys.stdin.readline().strip()
                    if self.exit_flag:
                        # print("ESC detected. Exiting...")
                        return
            
                    if input_str == "":
                        empty_input_count += 1

                        if empty_input_count >= 1 and all_joint_positions:
                            # 发布所有收集的数据
                            msg = Float64MultiArray()
                            msg.data = [x for joint in all_joint_positions for x in joint]
                            self.node.movej_pub_.publish(msg)
                            print("Joint positions published.")

                            # 重置状态以继续输入新的数据
                            all_joint_positions.clear()
                            empty_input_count = 0
                            print("You can keep entering joint angles. Press Enter twice again to publish.")
                        elif empty_input_count >= 1:
                            print("No valid joint data to publish.")
                            empty_input_count = 0  # 重置
                    else:
                        try:
                            joint_positions = [float(x) for x in input_str.strip().split()]
                            if len(joint_positions) != 6:
                                print("Invalid input. Please enter exactly 6 joint positions.")
                            else:
                                all_joint_positions.append(joint_positions)
                                empty_input_count = 0
                        except ValueError:
                            print("Invalid input. Please enter only numeric joint angles.")
            except KeyboardInterrupt:
                break    


    def _handle_movel(self):
        print(MOVEL_MSG)
        msg = UInt8()
        msg.data = MOVEL
        self.node.current_mode = msg.data
        self.node.mode_pub_.publish(msg)

        all_positions = []
        empty_input_count = 0

        self._start_esc_listener()

        while not self.exit_flag:
            try:
                rlist, _, _ = select.select([sys.stdin], [], [], 0.1)
                if self.exit_flag:
                    # print("ESC detected. Exiting...")
                    return
                if rlist:
                    input_str = sys.stdin.readline().strip()
                    if self.exit_flag:
                        # print("ESC detected. Exiting...")
                        return
                    
                    if input_str == "":
                        empty_input_count += 1
                        if empty_input_count >= 1 and all_positions:
                            # 发布所有收集的数据
                            msg = Float64MultiArray()
                            msg.data = [x for pose in all_positions for x in pose]
                            self.node.movel_pub_.publish(msg)
                            print("Poses published.")

                            # 重置状态以继续输入新的数据
                            all_positions.clear()
                            empty_input_count = 0
                        elif empty_input_count >= 1:
                            print("No valid pose data to publish.")
                            empty_input_count = 0
                    else:
                        try:
                            pose = [float(x) for x in input_str.strip().split()]
                            if len(pose) != 6:
                                print("Invalid input. Please enter 6 values separated by spaces.")
                            else:
                                all_positions.append(pose)
                                empty_input_count = 0
                        except ValueError:
                            print("Invalid input. Please enter only numeric poses.")
            except KeyboardInterrupt:
                break
                            

    def _handle_movec(self):
        print(MOVEC_MSG)
        msg = UInt8()
        msg.data = MOVEC
        self.node.current_mode = msg.data
        self.node.mode_pub_.publish(msg)
        self._start_esc_listener()

        while not self.exit_flag:
            print("\nMust pass through middle point? (1=True/0=False):")
            must_pass = self._get_boolean_input()
            if must_pass is None:  # ESC pressed
                return
            # 获取中间点和终点
            intermediate = self._get_six_values("Enter intermediate point (6 values - x y z roll pitch yaw):")
            if not intermediate: return
            
            final = self._get_six_values("Enter final point (6 values - x y z roll pitch yaw):")
            if not final: return

            # 发布路径
            msg = MoveCAction()
            msg.pose_array = Float64MultiArray()
            msg.must_pass_through_middle = Bool()
            msg.pose_array.data = intermediate + final
            msg.must_pass_through_middle.data = must_pass
            self.node.movec_pub_.publish(msg)
            print("Path published. Press Enter for new path or esc to exit")

            # 等待用户确认
            if self._wait_for_continue(): return


    def _get_boolean_input(self):
        """获取用户输入的布尔值选择(1=True/0=False)"""
        while not self.exit_flag:
            rlist, _, _ = select.select([sys.stdin], [], [], 0.1)
            if not rlist: continue
            
            input_str = sys.stdin.readline().strip()
            if not input_str: continue
            
            if input_str == "1":
                return True
            elif input_str == "0":
                return False
            else:
                print("Invalid input. Please enter 1 (True) or 0 (False)")
    
        return None
    
    def _get_six_values(self, prompt=""):
        """获取6个数值输入"""
        if prompt: print("\n" + prompt)
        
        while not self.exit_flag:
            rlist, _, _ = select.select([sys.stdin], [], [], 0.1)
            if not rlist: continue
            
            input_str = sys.stdin.readline().strip()
            if not input_str: continue
            
            try:
                values = [float(x) for x in input_str.split()]
                if len(values) == 6: 
                    return values
                print("Need exactly 6 values (x y z roll pitch yaw)")
            except ValueError:
                print("Invalid input. Numbers only")

        return None

    def _wait_for_continue(self):
        """等待用户按Enter继续或ESC退出"""
        while not self.exit_flag:
            rlist, _, _ = select.select([sys.stdin], [], [], 0.1)
            if not rlist: continue
            
            input_str = sys.stdin.readline().strip()
            if input_str == "": 
                return False  # 继续
            if input_str.lower() == 'esc':
                return True  # 退出

         
    def _handle_teach(self):
        print(TEACH_MSG)
        msg = UInt8()
        msg.data = TEACH
        self.node.current_mode = msg.data
        self.node.mode_pub_.publish(msg)

        self._start_esc_listener()
        self._clear_stdin_buffer()

        while not self.exit_flag:
            try:
                rlist, _, _ = select.select([sys.stdin], [], [], 0.1)
                if self.exit_flag: 
                    return
                if rlist:
                    input_str = sys.stdin.readline().strip()
                    if self.exit_flag:
                        return
                    if input_str == "":
                        pass
                    else:
                        msg = String()
                        msg.data = input_str
                        self.node.teach_pub_.publish(msg)
                        print(f"Published trajectory label: {input_str}")
                        print("Now dragging arm to recorded trajectory...")

                        recording = True
                        while recording and not self.exit_flag:
                            rlist, _, _ = select.select([sys.stdin], [], [], 0.1)
                            if rlist:
                                check_str = sys.stdin.readline().strip()
                                if check_str == "":
                                    msg.data = "stop"
                                    self.node.teach_pub_.publish(msg)
                                    recording = False
                                    print("Recording finished. Ready for next label or ESC to exit.")
                                elif check_str.lower() == "esc":
                                    self.exit_flag = True
                                    return
            except KeyboardInterrupt:
                break
            except Exception as e:
                self.get_logger().error(f"Teach mode error: {e}")
                            

    def _handle_teachrepeat(self):
        print(TEACHREPEAT_MSG)
        msg = UInt8()
        msg.data = TEACHREPEAT
        self.node.current_mode = msg.data
        self.node.mode_pub_.publish(msg)
        
        self._start_esc_listener()
        self._clear_stdin_buffer()
        
        while not self.exit_flag:
            try:
                rlist, _, _ = select.select([sys.stdin], [], [], 0.1)
                if self.exit_flag: 
                    return
                
                if rlist:
                    input_str = sys.stdin.readline().strip()
                    if self.exit_flag:
                        return
                    
                    if input_str == "":
                        pass  # 忽略空输入
                    else:
                        # 发布轨迹名称
                        msg = String()
                        msg.data = input_str
                        self.node.teachrepeat_pub_.publish(msg)
                        print(f"Repeating trajectory: {input_str}")
                        print("Playing trajectory... (Press Enter when finished or ESC to exit)")
                        
                        # 等待播放完成
                        playing = True
                        while playing and not self.exit_flag:
                            rlist, _, _ = select.select([sys.stdin], [], [], 0.1)
                            if rlist:
                                check_str = sys.stdin.readline().strip()
                                if check_str == "":  # Enter结束播放
                                    msg.data = "stop"
                                    self.node.teachrepeat_pub_.publish(msg)
                                    playing = False
                                    print("Playback finished. Ready for next trajectory.")
                                elif check_str.lower() == "esc":
                                    self.exit_flag = True
                                    return
            
            except KeyboardInterrupt:
                break
            except Exception as e:
                self.get_logger().error(f"Teachrepeat mode error: {e}")

    def get_saved_state_names(self):
        colcon_prefix_path = os.environ.get("COLCON_PREFIX_PATH")
        if not colcon_prefix_path:
            print("❌ 环境变量 COLCON_PREFIX_PATH 未设置！")
            return []
        
        ws_path = Path(colcon_prefix_path).parent
        db_path = ws_path / "config" / "robotic_arm_saved_states.db3"
        if not db_path.exists():
            print("❌ 没有找到数据库文件！")
            return []
        
        try:
            conn = sqlite3.connect(str(db_path))
            cursor = conn.cursor()
            cursor.execute("SELECT name FROM saved_states;")
            rows = cursor.fetchall()
            state_names = [row[0] for row in rows]
            conn.close()
            return state_names
        except Exception as e:
            print(f"❌ 读取数据库文件时出错: {e}")
            return []

    def _handle_save_delete_state(self):
        print(STATEOPERATION_MSG)
        msg = UInt8()
        msg.data = STATEOPERATION
        self.node.current_mode = msg.data
        self.node.mode_pub_.publish(msg)

        self._start_esc_listener()
        self._clear_stdin_buffer()

        try:
            # 打印已有状态名
            existing_names = self.get_saved_state_names()
            if existing_names:
                print("📂 已保存的状态名称：")
                for name in existing_names:
                    print(f"  - {name}")
            else:
                print("⚠️ 当前没有已保存的状态")

            while not self.exit_flag:
                state_name = input("Enter state name: ").strip()
                if not state_name:
                    continue

                print(f"\nSelected state name: {state_name}")
                print("Press 's' to Save, 'd' to Delete, or ESC to Cancel...")

                action_msg = StateAction()
                action_msg.state_name = state_name

                fd = sys.stdin.fileno()
                old_settings = termios.tcgetattr(fd)
                new_settings = termios.tcgetattr(fd)
                new_settings[3] = new_settings[3] & ~(termios.ECHO | termios.ICANON)

                try:
                    termios.tcsetattr(fd, termios.TCSADRAIN, new_settings)
                    key = sys.stdin.read(1)

                    if key == 's':
                        if state_name in existing_names:
                            confirm = input(f"⚠️ 状态 '{state_name}' 已存在，是否覆盖？(y/n): ").strip().lower()
                            if confirm != 'y':
                                print("❌ 取消保存操作。")
                                return
        
                        action_msg.operation_mode = StateAction.SAVE
                        self.node.save_delete_state_pub_.publish(action_msg)
                        print(f"✅ State saved: {state_name}")
                    elif key == 'd':
                        if state_name not in existing_names:
                            print(f"❌ 无法删除，状态 '{state_name}' 不存在。")
                            return
                        action_msg.operation_mode = StateAction.DELETE
                        self.node.save_delete_state_pub_.publish(action_msg)
                        print(f"❌ State deleted: {state_name}")
                    else:
                        print("Invalid key pressed. Cancelling.")
                        return

                finally:
                    termios.tcsetattr(fd, termios.TCSADRAIN, old_settings)

                # msg = UInt8()
                # msg.data = JOINTCONTROL
                # self.node.current_mode = msg.data
                # self.node.mode_pub_.publish(msg)
                # print("Auto switched to JOINTCONTROL mode.")
                # self.node.mode_handler.handle_mode(JOINTCONTROL)
                return

        except Exception as e:
            self.node.get_logger().error(f"Save/Delete state mode error: {e}")


    def _handle_loadstate(self):
        print(LOADSTATE_MSG)
        msg = UInt8()
        msg.data = LOADSTATE
        self.node.current_mode = msg.data
        self.node.mode_pub_.publish(msg)

        self._start_esc_listener()
        self._clear_stdin_buffer()

        list_printed = False    # Flag to check if list has been printed
        try:
            while not self.exit_flag:
                # 打印已有状态名
                if not list_printed:
                    existing_names = self.get_saved_state_names()
                    if existing_names:
                        print("📂 可加载的状态名称：")
                        for name in existing_names:
                            print(f"  - {name}")
                    else:
                        print("⚠️ 当前没有可加载的状态")
                    list_printed = True

                rlist, _, _ = select.select([sys.stdin], [], [], 0.1)
                if self.exit_flag:
                    return
                if rlist:
                    input_str = sys.stdin.readline().strip()
                    if self.exit_flag:
                        return
                    if input_str == "":
                        pass
                    elif input_str not in existing_names:
                        print(f"❌ State '{input_str}' does not exist. Please enter a valid state name.")
                        continue
                    else:
                        msg = String()
                        msg.data = input_str
                        self.node.loadstate_pub_.publish(msg)
                        print(f"\nState loading: {input_str}")
                        print("Press Enter when the state is loaded or ESC to cancel.")

                        while not self.exit_flag:
                            rlist, _, _ = select.select([sys.stdin], [], [], 0.1)
                            if rlist:
                                check_str = sys.stdin.readline().strip()
                                if check_str == "":
                                    # self.node.current_mode = JOINTCONTROL
                                    # mode_msg = UInt8()
                                    # mode_msg.data = JOINTCONTROL
                                    # self.node.mode_pub_.publish(mode_msg)
                                    # print("Auto switched to JOINTCONTROL mode.")
                                    # self.node.mode_handler.handle_mode(JOINTCONTROL)
                                    return
                                elif check_str == "ESC":
                                    print("Cancel loading state.")
                                    return
        except KeyboardInterrupt:
            pass
        except Exception as e:
            self.node.get_logger().error(f"Error in load state mode: {e}")
        # finally:
            # if not self.exit_flag and self.node.current_mode != JOINTCONTROL:
            #     self.node.current_mode = JOINTCONTROL
            #     mode_msg = UInt8()
            #     mode_msg.data = JOINTCONTROL
            #     self.node.mode_pub_.publish(mode_msg)
            #     print("Auto switched to JOINTCONTROL mode.")
            #     self.node.mode_handler.handle_mode(JOINTCONTROL)


    def _handle_back_to_initial(self):
        print(BACKTOINITIAL_MSG)
        msg = UInt8()
        msg.data = BACKTOINITIAL
        self.node.current_mode = msg.data
        self.node.mode_pub_.publish(msg)

        self._start_esc_listener()
        while not self.exit_flag:
            pass

class KeyboardController(Node):
    def __init__(self):
        super().__init__('keyboard_controller')
        self.mode_handler = ModeHandler(self)

        msg = UInt8()
        msg.data = DISABLE
        self.current_mode = msg.data
        # 初始化发布器
        self._init_publishers()
        self.mode_pub_.publish(msg)
        # 终端设置
        self.settings = termios.tcgetattr(sys.stdin)

    def _init_publishers(self):
        qos = QoSProfile(depth=10)
        self.mode_pub_ = self.create_publisher(UInt8, 'robotic_arm_control_mode', qos)
        self.jointctrl_pub_ = self.create_publisher(KeyPressedAction, 'jointctrl_action', qos)
        self.cartesian_pub_ = self.create_publisher(KeyPressedAction, 'cartesian_action', qos)
        self.movej_pub_ = self.create_publisher(Float64MultiArray, 'movej_action', qos)
        self.movel_pub_ = self.create_publisher(Float64MultiArray, 'movel_action', qos)
        self.movec_pub_ = self.create_publisher(MoveCAction, 'movec_action', qos)
        self.teach_pub_ = self.create_publisher(String, 'teach_action', qos)
        self.teachrepeat_pub_ = self.create_publisher(String, 'teachrepeat_action', qos)
        self.save_delete_state_pub_ = self.create_publisher(StateAction, 'sd_state_action', qos)
        self.loadstate_pub_ = self.create_publisher(String, 'loadstate_action', qos)

    def get_key(self):
        tty.setraw(sys.stdin.fileno())
        rlist, _, _ = select.select([sys.stdin], [], [], 0.1)
        if rlist:
            key = sys.stdin.read(1)
        else:
            key = ''
        termios.tcsetattr(sys.stdin, termios.TCSADRAIN, self.settings)
        return key
    
    def run(self):
        print(MAIN_MENU)
        try:
            while True:
                key = self.get_key()
                if key == '\x03':
                    break
                if key == '\x7f':  # ASCII ESC
                    print("ESC pressed. Exiting current mode.")
                    self.mode_handler.exit_flag = True
                    self.current_mode = DISABLE
                    self.mode_handler._clear_stdin_buffer()
                    print(MAIN_MENU)
                    continue
                if key in MODE_KEYS:
                    new_mode = MODE_KEYS[key]
                    if self.current_mode in MODE_PREREQUISITES.get(new_mode, []):
                        # if self.current_mode not in [BACKTOSTART, DISABLE, BACKTOINITIAL]:  # 这些模式需要手动退出
                        #     self.mode_handler.exit_flag = True
                        self.current_mode = new_mode
                        self.mode_handler.exit_flag = False  # 重置退出标志
                        self.mode_handler.handle_mode(new_mode)
                        print(MAIN_MENU)
                    continue
                else:
                    pass
                # 关节速度空间控制
                # if self.current_mode == JOINTCONTROL and key in JOINT_CONTROL_KEYS:
                #         action = JOINT_CONTROL_KEYS[key]
                #         msg = UInt8()
                #         msg.data = action
                #         self.jointctrl_pub_.publish(msg)
                # 笛卡尔空间控制
                # elif self.current_mode == CARTESIAN and key in CARTESIAN_CONTROL_KEYS:
                #     action = CARTESIAN_CONTROL_KEYS[key]
                #     msg = UInt8()
                #     msg.data = action
                #     self.cartesian_pub_.publish(msg)
                # elif self.current_mode in [MOVEJ, MOVEL, MOVEC, TEACH, TEACHREPEAT]:
                #     pass
        except KeyboardInterrupt:
            print("\nCtrl-C detected. Exiting gracefully...")
            self.mode_handler.exit_flag = True  # 强制中断当前模式
            rclpy.shutdown()
            sys.exit(0)
        finally:
            termios.tcsetattr(sys.stdin, termios.TCSADRAIN, self.settings)

def main(args=None):
    if args is None:
        args = sys.argv
    rclpy.init(args=args)
    node = KeyboardController()
    node.run()
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()






