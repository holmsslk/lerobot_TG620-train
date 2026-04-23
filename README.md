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
- MuJoCo（本仓默认路径：`/home/holms/Projects/mujoco/mujoco-3.3.0`）

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

## 一次性构建

### 构建 TG_Robot 工作区

```bash
cd TG_Robot
source /opt/ros/humble/setup.bash
colcon build --symlink-install
source install/setup.bash
```

### 准备 LeRobot Python 环境（推荐 Python 3.12）

```bash
cd ../lerobot
uv venv --python 3.12
uv sync --locked --extra core_scripts --extra pyzmq-dep --extra pynput-dep
```

## 当前实现概览

当前已实现两条可切换仿真链路：

- 推荐：`MuJoCo + tg_arm620_mujoco_sim`
- 备选：`Gazebo Classic + tg_arm620_sim_control_bridge`

LeRobot 侧接口保持一致：

- 机器人类型：`--robot.type=tg_arm620_follower`
- 遥操作类型：`--teleop.type=tg_arm620_keyboard`
- 关节接口：`joint1~joint6`（单位 `rad`）
- 夹爪接口：`gripper.pos`（`0~100`）
- 双相机：`front_camera@5555`、`side_front_camera@5556`

默认端口：

- 命令：`6001`
- 状态：`6002`
- 前视相机：`5555`
- 侧前相机：`5556`

## MuJoCo 仿真数据采集全流程（推荐）

说明：本流程用于 imitation 数据采集/回放，保持 LeRobot CLI 不变，仅替换仿真后端。

### 1. 启动 MuJoCo 仿真桥接（终端 1）

```bash
cd ~/Projects/lerobot/TG_Robot
source /opt/ros/humble/setup.bash
source install/setup.bash

export MUJOCO_GL=egl
ros2 launch robot_bringup robot_mujoco_lerobot.launch.py \
  mujoco_home:=/home/holms/Projects/mujoco/mujoco-3.3.0 \
  viewer:=false
```

备注：

- `viewer:=false` 为无界面模式，最稳定，避免 MuJoCo 快捷键冲突。
- 如需窗口，改为 `viewer:=true mujoco_gl:=glfw`。

### 2. 端口健康检查（终端 2）

```bash
ss -ltnp | grep -E '5555|5556|6001|6002'
```

### 3. 键盘遥操作联调（终端 3）

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

默认按键：

- 关节正向：`1 2 3 4 5 6`
- 关节反向：`q w e r t y`
- 夹爪开/合：`p / o`
- 回零：`h`

说明：

- 当前建议显式使用 `--teleop.input_backend=stdin`，在 VM/Wayland 下更稳定。
- `stdin` 模式需要终端焦点，按键是“脉冲步进”（按一次走一步）。

### 4. 正式采集（终端 3）

建议每次使用新的 `dataset.root`，避免目录已存在报错。

```bash
cd ~/Projects/lerobot/lerobot
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
  --dataset.streaming_encoding=true \
  --dataset.encoder_threads=2 \
  --dataset.push_to_hub=false \
  --display_data=true
```

### 5. 回放验证（终端 3）

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

## Gazebo Classic 链路（备选）

说明：当你需要对照 ROS2 控制器链路时，可使用 Gazebo 方案。

### 1. 启动 Gazebo 与桥接（终端 1）

```bash
cd ~/Projects/lerobot/TG_Robot
source /opt/ros/humble/setup.bash
source install/setup.bash
export GAZEBO_MODEL_DATABASE_URI=""
ros2 launch robot_bringup robot_gazebo_lerobot.launch.py
```

### 2. 控制器与图像检查（终端 2）

```bash
cd ~/Projects/lerobot/TG_Robot
source /opt/ros/humble/setup.bash
source install/setup.bash

ros2 control list_controllers --controller-manager /controller_manager
ros2 topic hz /joint_states
ros2 topic hz /front_camera/front_camera/image_raw
ros2 topic hz /side_front_camera/side_front_camera/image_raw
```

### 3. LeRobot 侧命令

遥操作、采集、回放命令与 MuJoCo 流程相同。

## 常见问题排查

- `Address already in use`：有旧仿真进程未退出。
  - Gazebo: `pkill -f gzserver; pkill -f gzclient; pkill -f 'gazebo --verbose'`
  - MuJoCo: `pkill -f tg_arm620_mujoco_sim`
- `FileExistsError: ... 'data'`：`--dataset.root` 需使用新目录。
- 键盘无响应（尤其 VM/Wayland）：
  - 使用 `--teleop.input_backend=stdin`
  - 确保运行 `lerobot-teleoperate` 的终端窗口有焦点
- 开了 MuJoCo viewer 后按键异常：
  - viewer 与 teleop 可能抢按键，建议 `viewer:=false`
- 机械臂在某些接触姿态不操作仍轻微抖动：
  - 当前参数下可能由接触刚度 + 高增益控制共同导致（已知现象，后续可做参数整定）

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
