# lerobot_TG620-train

这是 TG arm620 集成工程的顶层工作区，包含以下三部分：

- fork 后的 `lerobot` 仓库（作为子模块）
- `TG_Robot/src/ros2_socketcan` 下的 fork 版 `ros2_socketcan`（作为子模块）
- `TG_Robot/` 下的 ROS2 机器人工作区

该仓库用于统一固定三者的兼容提交版本，保证团队可复现。

## 仓库结构

```text
.
|-- lerobot/                         # 子模块: https://github.com/holmsslk/lerobot.git
`-- TG_Robot/
    `-- src/
        `-- ros2_socketcan/          # 子模块: https://github.com/holmsslk/ros2_socketcan.git
```

## 环境要求

- 推荐 Ubuntu 22.04
- 已安装并可用 ROS2 Humble
- 可通过 HTTPS 直接拉取公开仓库（无需配置 SSH）
- ROS2 构建工具（`colcon`、`rosdep`）及 CAN 相关运行环境

## 克隆项目

```bash
git clone --recurse-submodules https://github.com/holmsslk/lerobot_TG620-train.git
cd lerobot_TG620-train
```

如果子模块未拉取完整：

```bash
git submodule sync --recursive
git submodule update --init --recursive
git submodule status --recursive
```

## 构建 TG_Robot 工作区

```bash
cd TG_Robot
source /opt/ros/humble/setup.bash
colcon build --symlink-install
source install/setup.bash
```

## 仿真数据采集全流程（Gazebo Classic + LeRobot 键盘遥操作）

说明：`robot_bringup/robot_gazebo_lerobot.launch.py` 已经同时启动 Gazebo + `tg_arm620_sim_control_bridge` + 双路 `tg_camera_zmq_bridge`，通常不需要再单独启动 `sim_bridges.launch.py`。

### 0. 一次性准备

构建 ROS2 工作区：

```bash
cd TG_Robot
source /opt/ros/humble/setup.bash
colcon build --symlink-install
source install/setup.bash
```

准备 LeRobot Python 环境（推荐 Python 3.12）：

```bash
cd ../lerobot
uv venv --python 3.12
uv sync --locked --extra core_scripts --extra pyzmq-dep --extra pynput-dep
```

### 1. 启动仿真与桥接（终端 1）

```bash
cd ~/Projects/lerobot/TG_Robot
source /opt/ros/humble/setup.bash
source install/setup.bash
export GAZEBO_MODEL_DATABASE_URI=""
ros2 launch robot_bringup robot_gazebo_lerobot.launch.py
```

### 2. 启动后健康检查（终端 2）

```bash
cd ~/Projects/lerobot/TG_Robot
source /opt/ros/humble/setup.bash
source install/setup.bash

ros2 control list_controllers --controller-manager /controller_manager
ros2 topic hz /joint_states
ros2 topic hz /front_camera/front_camera/image_raw
ros2 topic hz /side_front_camera/side_front_camera/image_raw
```

期望：
- `joint_state_broadcaster`、`arm_position_controller` 为 `active`
- `joint_states` 和两路图像 topic 有稳定频率

### 3. 键盘遥操作联调（终端 3，可选）

```bash
cd ~/Projects/lerobot/lerobot
uv run --no-sync lerobot-teleoperate \
  --robot.type=tg_arm620_follower \
  --robot.remote_ip=127.0.0.1 \
  --robot.cmd_port=6001 \
  --robot.state_port=6002 \
  --robot.cameras='{front: {type: zmq, server_address: 127.0.0.1, port: 5555, camera_name: front_camera, width: 640, height: 480, fps: 30}, side_front: {type: zmq, server_address: 127.0.0.1, port: 5556, camera_name: side_front_camera, width: 640, height: 480, fps: 30}}' \
  --teleop.type=tg_arm620_keyboard \
  --fps=30 \
  --teleop_time_s=60 \
  --display_data=true
```

默认按键：
- 关节正向：`1 2 3 4 5 6`
- 关节反向：`q w e r t y`
- 夹爪开合：`p / o`
- 回零：`h`

### 4. 正式采集（终端 3）

建议每次使用新的 `dataset.root`，避免目录已存在报错。

```bash
cd ~/Projects/lerobot/lerobot
RUN_ID=$(date +%Y%m%d_%H%M%S)
DATA_ROOT=./data/tg_arm620_sim_${RUN_ID}
REPO_ID=local/tg_arm620_sim_empty_scene_${RUN_ID}

uv run --no-sync lerobot-record \
  --robot.type=tg_arm620_follower \
  --robot.remote_ip=127.0.0.1 \
  --robot.cmd_port=6001 \
  --robot.state_port=6002 \
  --robot.cameras='{front: {type: zmq, server_address: 127.0.0.1, port: 5555, camera_name: front_camera, width: 640, height: 480, fps: 30}, side_front: {type: zmq, server_address: 127.0.0.1, port: 5556, camera_name: side_front_camera, width: 640, height: 480, fps: 30}}' \
  --teleop.type=tg_arm620_keyboard \
  --dataset.repo_id=${REPO_ID} \
  --dataset.root=${DATA_ROOT} \
  --dataset.single_task="Teleop arm620 in empty Gazebo scene" \
  --dataset.fps=30 \
  --dataset.num_episodes=5 \
  --dataset.episode_time_s=30 \
  --dataset.reset_time_s=10 \
  --dataset.video=true \
  --dataset.streaming_encoding=true \
  --dataset.encoder_threads=2 \
  --dataset.push_to_hub=false \
  --display_data=true
```

### 5. 回放验证（终端 3）

使用上一步相同的 `REPO_ID` 和 `DATA_ROOT`：

```bash
cd ~/Projects/lerobot/lerobot
uv run --no-sync lerobot-replay \
  --robot.type=tg_arm620_follower \
  --robot.remote_ip=127.0.0.1 \
  --robot.cmd_port=6001 \
  --robot.state_port=6002 \
  --dataset.repo_id=${REPO_ID} \
  --dataset.root=${DATA_ROOT} \
  --dataset.episode=0
```

### 6. 常见问题排查

- Gazebo 报 `Address already in use`：有旧的 Gazebo 进程未退出，先清理后重启。
  - 可用：`pkill -f gzserver; pkill -f gzclient; pkill -f 'gazebo --verbose'`
- `FileExistsError: [Errno 17] File exists: 'data'`：`--dataset.root` 不能指向已存在目录，请改为新目录（如时间戳目录）。
- 控制器 `active` 但不动：
  - 确认只启动了一套桥接（不要重复启动 `sim_bridges.launch.py`）。
  - 查看 `ros2 topic echo /arm_position_controller/commands`，按键时应看到目标角度变化。
- 键盘无响应：
  - 确认命令窗口拥有焦点。
  - Linux 需有图形会话（`DISPLAY` 有效），且已安装 `pynput` extra。

## 真机快速启动（arm620）

先完成 CAN 配置，再启动：

```bash
cd TG_Robot
source /opt/ros/humble/setup.bash
source install/setup.bash
ros2 launch robot_bringup arm620_real.launch.py
```

开机自启动脚本参考：
`TG_Robot/autoinstall_script/How_to_startup.md`

## 开发提交流程（子模块模式）

1. 在子模块仓库内分别修改并提交代码：
   - `lerobot/`
   - `TG_Robot/src/ros2_socketcan/`
2. 将子模块的新提交先推送到各自 GitHub 仓库。
3. 回到顶层仓库，更新子模块指针并提交：

```bash
cd /path/to/lerobot_TG620-train
git add lerobot TG_Robot/src/ros2_socketcan .gitmodules
git commit -m "chore: bump submodule commits"
git push origin main
```

## 同步到最新固定版本

当队友更新了顶层仓库后：

```bash
git pull --rebase
git submodule sync --recursive
git submodule update --init --recursive
```

## 注意事项

- 子模块仓库建议保留两个 remote：
  - `origin`：你自己的 fork
  - `upstream`：上游官方仓库
- 一定先推子模块提交，再推顶层仓库中的子模块指针更新。
