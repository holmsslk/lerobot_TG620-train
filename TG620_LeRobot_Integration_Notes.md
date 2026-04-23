# TG620 接入 LeRobot 框架设计与实现说明（当前版）

本文记录 `arm620 (TG620)` 接入 `LeRobot` 的当前实现状态，覆盖：

- 设计思路与系统架构
- 关键实现模块与文件改动范围
- 日常使用方法（teleoperate / record / replay）
- 当前版本已知行为与排查建议
- 复用到其他机械臂的通用模板

## 1. 目标与接口契约

本项目优先稳定复用 LeRobot 工作流，不改上层 CLI 语义，仅替换底层仿真/硬件执行链路。

统一接口契约：

- 关节顺序：`joint1` 到 `joint6`
- 关节单位：`rad`（action/observation 都是弧度）
- 夹爪接口：`gripper.pos`，范围 `0~100`
- 夹爪语义映射：`type=1, speed=40, effort=100`（桥接层固定）
- 控制频率目标：`30Hz`
- 速度/加速度上限：`150 deg/s`、`150 deg/s^2`，换算为 `2.61799 rad/s`、`2.61799 rad/s^2`
- 视觉输入：双路相机（front / side_front）

关节限位（来自 URDF）：

- `joint1/4/6 = [-2.967, 2.967]`
- `joint2/3/5 = [-1.5708, 1.5708]`

## 2. 总体架构

采用“双环境 + ZMQ 桥接”设计：

- `LeRobot`：负责 `teleoperate / record / replay / train/eval`
- `TG_Robot (ROS2)`：负责仿真/真机执行与相机发布
- `ZMQ`：负责三类数据通道
  - 命令通道（关节 + 夹爪）
  - 状态通道（关节 + 夹爪）
  - 图像通道（JPEG base64）

后端可切换：

- Gazebo Classic 链路（备选）
- MuJoCo 链路（当前推荐）

关键点是：**LeRobot 侧接口不变**，后端可替换。

## 3. 当前实现分层

### 3.1 LeRobot 侧

1. 新增机器人类型 `tg_arm620_follower`，统一对外 `rad` 接口。
2. 新增遥操作器 `tg_arm620_keyboard`。
3. 将新类型注入 `lerobot-teleoperate / record / replay / calibrate / find_joint_limits` 等入口。
4. 新增并扩展测试，覆盖 follower 与 teleop 行为。

### 3.2 TG_Robot 侧

1. 新增 `tg_lerobot_bridge` 包。
2. 提供真机桥、Gazebo 仿真桥、MuJoCo 仿真桥、相机桥。
3. 提供 `robot_bringup` 聚合 launch：
   - Gazebo 聚合入口
   - MuJoCo 聚合入口
4. 维护 MuJoCo 模型 `arm620_omnipicker_mujoco.xml`，实现 6 轴 + 夹爪联动 + 双相机。

## 4. 关键设计选择

### 4.1 对外统一弧度接口

不在 LeRobot 侧混用 deg/rad，避免训练数据与控制链路单位错配。

### 4.2 约束放在桥接层

关节裁剪、速度限幅、加速度限幅在桥接层执行，保证上层策略异常时仍可控。

### 4.3 仿真后端可替换

LeRobot 不感知 Gazebo/MuJoCo 差异，只感知统一 ZMQ 协议。

### 4.4 键盘输入后备模式

针对 VM/Wayland 下 `pynput` 全局监听不稳定的问题，`tg_arm620_keyboard` 增加：

- `input_backend=auto|pynput|stdin`
- `auto` 在 Wayland 环境默认走 `stdin`
- `stdin` 模式通过终端读键，避免窗口焦点竞争导致“无响应”

## 5. 文件修改清单（按模块）

## 5.1 LeRobot 侧（`lerobot/`）

| 文件 | 作用 |
|---|---|
| `src/lerobot/robots/tg_arm620/config_tg_arm620.py` | TG620 配置与约束参数 |
| `src/lerobot/robots/tg_arm620/tg_arm620.py` | TG620 follower（ZMQ 命令/状态/相机） |
| `src/lerobot/robots/tg_arm620/__init__.py` | 导出 TG620 机器人类型 |
| `src/lerobot/robots/utils.py` | 注册 `tg_arm620_follower` |
| `src/lerobot/teleoperators/tg_arm620_keyboard/config_tg_arm620_keyboard.py` | 遥操作配置（含 `input_backend`） |
| `src/lerobot/teleoperators/tg_arm620_keyboard/tg_arm620_keyboard.py` | 遥操作实现（`pynput` + `stdin` 后备） |
| `src/lerobot/teleoperators/tg_arm620_keyboard/__init__.py` | 导出 teleop 类型 |
| `src/lerobot/teleoperators/utils.py` | 注册 `tg_arm620_keyboard` |
| `src/lerobot/scripts/lerobot_teleoperate.py` | 注入 tg_arm620 + tg_arm620_keyboard 解析 |
| `src/lerobot/scripts/lerobot_record.py` | 注入 tg_arm620 + ZMQCameraConfig |
| `src/lerobot/scripts/lerobot_replay.py` | 注入 tg_arm620 解析 |
| `src/lerobot/scripts/lerobot_calibrate.py` | 注入 tg_arm620/tg_arm620_keyboard |
| `src/lerobot/scripts/lerobot_find_joint_limits.py` | 注入 tg_arm620/tg_arm620_keyboard |
| `src/lerobot/rl/eval_policy.py` | 评估侧类型注入 |
| `src/lerobot/async_inference/robot_client.py` | 异步推理侧类型注入 |
| `tests/robots/test_tg_arm620_follower.py` | follower 单测 |
| `tests/teleoperators/test_tg_arm620_keyboard.py` | teleop 单测（含 `stdin` 后备） |

### 5.2 TG_Robot 侧（`TG_Robot/`）

| 文件 | 作用 |
|---|---|
| `src/tg_lerobot_bridge/setup.py` | 桥接脚本注册 |
| `src/tg_lerobot_bridge/package.xml` | 桥接依赖 |
| `src/tg_lerobot_bridge/tg_lerobot_bridge/control_bridge_node.py` | 真机控制桥 |
| `src/tg_lerobot_bridge/tg_lerobot_bridge/sim_control_bridge_node.py` | Gazebo 控制桥 |
| `src/tg_lerobot_bridge/tg_lerobot_bridge/camera_bridge_node.py` | ROS 图像到 ZMQ |
| `src/tg_lerobot_bridge/tg_lerobot_bridge/mujoco_sim_node.py` | MuJoCo 仿真桥（控制 + 状态 + 相机） |
| `src/tg_lerobot_bridge/launch/sim_bridges.launch.py` | Gazebo 链路桥接聚合 |
| `src/tg_lerobot_bridge/launch/mujoco_sim.launch.py` | MuJoCo 桥接入口 |
| `src/tg_lerobot_bridge/models/arm620_omnipicker_mujoco.xml` | MuJoCo 机器人与场景模型 |
| `src/robot_gazebo/config/gazebo_arm620_lerobot.urdf.xacro` | Gazebo 模型与相机 |
| `src/robot_config/arm620_config/config/ros2_controllers_lerobot.yaml` | Gazebo 控制器配置 |
| `src/robot_gazebo/launch/robot_gazebo_lerobot.launch.py` | Gazebo 启动（含 robot_description 处理） |
| `src/robot_bringup/launch/robot_gazebo_lerobot.launch.py` | Gazebo 一键入口 |
| `src/robot_bringup/launch/robot_mujoco_lerobot.launch.py` | MuJoCo 一键入口 |

## 6. 使用方法（当前推荐 MuJoCo）

### 6.1 终端 1：启动 MuJoCo

```bash
cd ~/Projects/lerobot/TG_Robot
source /opt/ros/humble/setup.bash
source install/setup.bash

export MUJOCO_GL=egl
ros2 launch robot_bringup robot_mujoco_lerobot.launch.py \
  mujoco_home:=/home/holms/Projects/mujoco/mujoco-3.3.0 \
  viewer:=false
```

### 6.2 终端 2：键盘遥操作

```bash
cd ~/Projects/lerobot/lerobot
uv run --no-sync lerobot-teleoperate \
  --robot.type=tg_arm620_follower \
  --robot.remote_ip=127.0.0.1 \
  --robot.cmd_port=6001 \
  --robot.state_port=6002 \
  --robot.cameras='{front: {type: zmq, server_address: 127.0.0.1, port: 5555, camera_name: front_camera, width: 640, height: 480, fps: 30}, side: {type: zmq, server_address: 127.0.0.1, port: 5556, camera_name: side_front_camera, width: 640, height: 480, fps: 30}}' \
  --teleop.type=tg_arm620_keyboard \
  --teleop.input_backend=stdin \
  --fps=30 \
  --teleop_time_s=300 \
  --display_data=true
```

### 6.3 终端 2：采集

```bash
RUN_ID=$(date +%Y%m%d_%H%M%S)
DATA_ROOT=./data/tg_arm620_mujoco_${RUN_ID}
REPO_ID=local/tg_arm620_mujoco_${RUN_ID}

uv run --no-sync lerobot-record \
  --robot.type=tg_arm620_follower \
  --robot.remote_ip=127.0.0.1 \
  --robot.cmd_port=6001 \
  --robot.state_port=6002 \
  --robot.cameras='{front: {type: zmq, server_address: 127.0.0.1, port: 5555, camera_name: front_camera, width: 640, height: 480, fps: 30}, side: {type: zmq, server_address: 127.0.0.1, port: 5556, camera_name: side_front_camera, width: 640, height: 480, fps: 30}}' \
  --teleop.type=tg_arm620_keyboard \
  --teleop.input_backend=stdin \
  --dataset.repo_id=${REPO_ID} \
  --dataset.root=${DATA_ROOT} \
  --dataset.single_task="Teleop arm620 in MuJoCo scene" \
  --dataset.fps=30 \
  --dataset.num_episodes=5 \
  --dataset.episode_time_s=30 \
  --dataset.reset_time_s=10 \
  --dataset.video=true \
  --dataset.push_to_hub=false \
  --display_data=true
```

### 6.4 回放

```bash
uv run --no-sync lerobot-replay \
  --robot.type=tg_arm620_follower \
  --robot.remote_ip=127.0.0.1 \
  --robot.cmd_port=6001 \
  --robot.state_port=6002 \
  --dataset.repo_id=${REPO_ID} \
  --dataset.root=${DATA_ROOT} \
  --dataset.episode=0
```

## 7. 当前版已知行为与排查

1. VM/Wayland 下 `pynput` 可能“已连接但无输入事件”。
   - 解决：`--teleop.input_backend=stdin`。
2. 开启 MuJoCo viewer 时，viewer 快捷键可能与 teleop 按键竞争。
   - 解决：采集阶段建议 `viewer:=false`。
3. 某些接触姿态下，不操作也可能出现轻微晃动。
   - 成因通常是接触刚度、执行器增益、阻尼组合导致的接触抖动。
   - 当前文档先记录现象与分析，不在本轮调整参数。

## 8. 可复用经验（接入新机械臂）

1. 先冻结接口契约：关节名/顺序、单位、夹爪语义、频率、限位来源。
2. 先做桥接层限幅，再做上层策略调参。
3. 让 LeRobot 只依赖统一 ZMQ 协议，仿真后端可替换。
4. 给遥操作准备输入后备路径（GUI 全局监听 + 终端本地读取）。
5. 先跑最小闭环：`teleoperate -> record -> replay`，再进入训练。

---

如果后续切换真机采集，只需复用同一套 LeRobot 接口，把桥接入口从仿真桥切到真机桥。
