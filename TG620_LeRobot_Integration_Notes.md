# TG620 接入 LeRobot 框架实现总结

本文记录 `arm620(TG620)` 接入 `LeRobot` 的完整实现路径，覆盖：
- 实现过程（从接口定义到联调验收）
- 需要修改的文件清单（按模块分类）
- 可复用经验（后续接入其他机械臂可直接套用）

## 1. 接入目标与接口约定

本次接入采用“双环境 + ZMQ 桥接”架构：
- ROS2/TG_Robot 负责机械臂控制与仿真
- LeRobot 负责 teleop/record/replay/train
- 两侧通过 ZMQ 交换关节状态、控制命令与图像流

统一接口约定如下：
- 关节命名顺序：`joint1` 到 `joint6`
- 关节单位：全部使用 `rad`（action 和 observation 一致）
- 夹爪语义：`gripper.pos` 范围 `0~100`，桥接层映射固定 `type=1, speed=40, effort=100`
- 控制频率：30Hz
- 限位（来自 URDF）：  
  `joint1/4/6 = [-2.967, 2.967]`  
  `joint2/3/5 = [-1.5708, 1.5708]`
- 速度/加速度上限：`150 deg/s`、`150 deg/s^2` 转换为 `2.61799 rad/s`、`2.61799 rad/s^2`

## 2. 实现过程（按阶段）

### 阶段 A：LeRobot 新增 TG620 机器人类型
1. 定义 `TGArm620Config`，固化通信端口、频率、限位、夹爪参数。
2. 实现 `TGArm620Follower`：
   - ZMQ PUSH 发送控制命令
   - ZMQ SUB 接收状态
   - 关节/夹爪裁剪
   - 可选接入 ZMQ 相机
3. 注册工厂映射，使 CLI 可识别 `--robot.type=tg_arm620_follower`。

### 阶段 B：新增 TG620 键盘遥操作器
1. 定义 `TGArm620KeyboardConfig`（按键映射、步长、限位）。
2. 实现 `TGArm620Keyboard`（按键状态机、home、gripper 开合）。
3. 注册工厂映射，使 CLI 可识别 `--teleop.type=tg_arm620_keyboard`。

### 阶段 C：打通 LeRobot CLI 入口
在 `teleoperate/record/replay/calibrate/find_joint_limits` 等脚本中引入 `tg_arm620` 与 `tg_arm620_keyboard`，确保 draccus 能解析对应 type。

### 阶段 D：ROS2 桥接实现（真机 + 仿真）
1. 新建 `tg_lerobot_bridge` ROS2 包。
2. 实现三类节点：
   - 真机控制桥：`tg_arm620_control_bridge`
   - 仿真控制桥：`tg_arm620_sim_control_bridge`
   - 相机桥：`tg_camera_zmq_bridge`
3. `sim_bridges.launch.py` 统一启动控制桥和双路相机桥。

### 阶段 E：Gazebo 侧集成
1. 新建仿真专用模型 `gazebo_arm620_lerobot.urdf.xacro`：
   - 引用 arm620 本体 xacro
   - 增加两路外置相机（front/side_front）
   - 挂载 `gazebo_ros2_control` 与 position 控制接口
2. 新增 `ros2_controllers_lerobot.yaml`，定义：
   - `joint_state_broadcaster`
   - `arm_position_controller`
3. 新增 `robot_gazebo_lerobot.launch.py`：
   - 启 Gazebo
   - 生成/发布 `robot_description`
   - 启动控制器
4. 在 `robot_bringup` 中增加聚合 launch，同时拉起 Gazebo 与桥接。

### 阶段 F：联调与采集闭环
1. 验证控制器 `active`，验证 joint_states 与图像 topic。
2. `lerobot-teleoperate` 键盘控制验证。
3. `lerobot-record` 采集数据集（双相机）。
4. `lerobot-replay` 回放验证。

## 3. 需要修改的文件清单

### 3.1 LeRobot 侧（`lerobot/`）

| 文件 | 作用 |
|---|---|
| `src/lerobot/robots/tg_arm620/config_tg_arm620.py` | TG620 机器人配置与限位/约束参数 |
| `src/lerobot/robots/tg_arm620/tg_arm620.py` | TG620 follower 具体实现（ZMQ 控制/状态） |
| `src/lerobot/robots/tg_arm620/__init__.py` | 导出 TG620 config 与 follower |
| `src/lerobot/robots/utils.py` | 注册 `tg_arm620_follower` 工厂分发 |
| `src/lerobot/teleoperators/tg_arm620_keyboard/config_tg_arm620_keyboard.py` | 键盘 teleop 配置 |
| `src/lerobot/teleoperators/tg_arm620_keyboard/tg_arm620_keyboard.py` | 键盘 teleop 行为实现 |
| `src/lerobot/teleoperators/tg_arm620_keyboard/__init__.py` | 导出 teleop 配置与实现 |
| `src/lerobot/teleoperators/utils.py` | 注册 `tg_arm620_keyboard` 工厂分发 |
| `src/lerobot/scripts/lerobot_teleoperate.py` | 注入 tg_arm620/tg_arm620_keyboard 到 CLI 类型解析 |
| `src/lerobot/scripts/lerobot_record.py` | 注入 tg_arm620/tg_arm620_keyboard + ZMQCameraConfig |
| `src/lerobot/scripts/lerobot_replay.py` | 注入 tg_arm620 到 CLI 类型解析 |
| `src/lerobot/scripts/lerobot_calibrate.py` | 注入 tg_arm620/tg_arm620_keyboard |
| `src/lerobot/scripts/lerobot_find_joint_limits.py` | 注入 tg_arm620/tg_arm620_keyboard |
| `src/lerobot/rl/eval_policy.py` | 注入 tg_arm620/tg_arm620_keyboard（评估侧解析） |
| `src/lerobot/async_inference/robot_client.py` | 注入 tg_arm620（异步推理客户端解析） |
| `tests/robots/test_tg_arm620_follower.py` | follower 单测（连接/裁剪/状态） |
| `tests/teleoperators/test_tg_arm620_keyboard.py` | teleop 单测（按键/限位/home） |

### 3.2 TG_Robot 侧（`TG_Robot/`）

| 文件 | 作用 |
|---|---|
| `src/tg_lerobot_bridge/setup.py` | 桥接包入口脚本注册 |
| `src/tg_lerobot_bridge/package.xml` | 桥接包依赖声明 |
| `src/tg_lerobot_bridge/tg_lerobot_bridge/control_bridge_node.py` | 真机控制桥（ZMQ -> motor_control_msg / gripper_control_msg） |
| `src/tg_lerobot_bridge/tg_lerobot_bridge/sim_control_bridge_node.py` | 仿真控制桥（ZMQ -> /arm_position_controller/commands） |
| `src/tg_lerobot_bridge/tg_lerobot_bridge/camera_bridge_node.py` | ROS 图像 -> ZMQ 图像流桥 |
| `src/tg_lerobot_bridge/launch/sim_bridges.launch.py` | 一键启动控制桥与双相机桥 |
| `src/robot_gazebo/config/gazebo_arm620_lerobot.urdf.xacro` | 仿真模型、相机、ros2_control 插件 |
| `src/robot_config/arm620_config/config/ros2_controllers_lerobot.yaml` | LeRobot 仿真控制器配置 |
| `src/robot_gazebo/launch/robot_gazebo_lerobot.launch.py` | Gazebo + robot_description + controller spawner（含注释净化） |
| `src/robot_bringup/launch/robot_gazebo_lerobot.launch.py` | bringup 聚合入口（Gazebo + sim bridge + camera bridge） |
| `src/robot_description/arm620/arm620.urdf.xacro` | 关节顺序/限位来源参考（本次作为接口基准） |

## 4. 可复用经验（下次接入其他机械臂直接照做）

### 4.1 强制先定“外部接口契约”
先冻结这些字段再写代码：
- 关节名与顺序
- 单位（建议统一 rad）
- 夹爪语义（1 维或多维）
- 控制频率与时延预算
- 限位来源（URDF 或厂家参数）

若不先冻结契约，后续会在 teleop/record/replay/bridge 四层反复返工。

### 4.2 “桥接层限幅”比“上层限幅”更稳
本项目在桥接层执行：
- 关节限位裁剪
- 速度限幅
- 加速度限幅

这样可以保证即使上层策略输出异常，底层也有兜底。

### 4.3 Gazebo 与 LeRobot 分层解耦
- Gazebo 只关注 ROS 控制器与图像发布
- LeRobot 只面向统一 ZMQ 协议

优点是后续替换真机或仿真时，上层数据采集/训练脚本无需重写。

### 4.4 避免重复启动桥接
`robot_bringup/robot_gazebo_lerobot.launch.py` 已包含桥接。  
如果又手动起 `sim_bridges.launch.py`，会出现端口冲突或“看起来在发命令但不动”的假象。

### 4.5 解决 `gazebo_ros2_control` 参数解析坑
`robot_description` 中含 XML 注释时，`gazebo_ros2_control` 可能参数解析失败。  
实践中通过 launch 里“发送前移除 XML 注释”可稳定规避。

### 4.6 数据集路径与 episode 索引要显式
- `--dataset.root` 为空时会回退到 HF 缓存目录，容易引发 401/找不到数据。
- `--dataset.episode` 必须在实际索引范围内（常见只有 `0`）。

### 4.7 ZMQ 连通性调试建议
单发命令有时受连接时序影响，建议：
- connect 后等待短时间
- 连续发 0.5~1s
- 同步观察 ROS `commands` 与 `joint_states` 变化

## 5. 最小复用模板（接入新机械臂）

1. 在 LeRobot 新增 `robots/<new_arm>/config + follower`  
2. 在 LeRobot 新增 `teleoperators/<new_arm>_keyboard`（可选）  
3. 注册 `robots/utils.py` 与 `teleoperators/utils.py`  
4. 在 `record/teleoperate/replay` 脚本注入新类型  
5. 在 ROS2 新增桥接包（控制桥 + 状态桥 + 相机桥）  
6. 在 Gazebo 模型里挂 `ros2_control` 与相机  
7. 提供一键 launch（建议 bringup 聚合）  
8. 先跑 dry-run，再跑 teleop，再跑 record/replay，最后训练

---

如果后续你要把 `arm620` 切换到真机采集，只需要复用同一套 LeRobot 侧接口，把桥接入口从 `sim_control_bridge_node.py` 切到 `control_bridge_node.py` 即可。
