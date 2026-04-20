# lerobot_TG620-train

这是 TG arm620 集成工程的顶层工作区，包含以下三部分：

- fork 后的 `lerobot` 仓库（作为子模块）
- `TG_Robot/src/ros2_socketcan` 下的 fork 版 `ros2_socketcan`（作为子模块）
- `TG_Robot/` 下的 ROS2 机器人工作区

该仓库用于统一固定三者的兼容提交版本，保证团队可复现。

## 仓库结构

```text
.
|-- lerobot/                         # 子模块: git@github.com:holmsslk/lerobot.git
`-- TG_Robot/
    `-- src/
        `-- ros2_socketcan/          # 子模块: git@github.com:holmsslk/ros2_socketcan.git
```

## 环境要求

- 推荐 Ubuntu 22.04
- 已安装并可用 ROS2 Humble
- Git 已配置 SSH（可访问这 3 个 GitHub 仓库）
- ROS2 构建工具（`colcon`、`rosdep`）及 CAN 相关运行环境

## 克隆项目

```bash
git clone --recurse-submodules git@github.com:holmsslk/lerobot_TG620-train.git
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

## 仿真快速启动（arm620 + LeRobot bridge）

终端 1：

```bash
cd TG_Robot
source /opt/ros/humble/setup.bash
source install/setup.bash
export GAZEBO_MODEL_DATABASE_URI=""
ros2 launch robot_bringup robot_gazebo_lerobot.launch.py
```

可选：启动桥接节点（新终端）：

```bash
cd TG_Robot
source /opt/ros/humble/setup.bash
source install/setup.bash
ros2 launch tg_lerobot_bridge sim_bridges.launch.py
```

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
