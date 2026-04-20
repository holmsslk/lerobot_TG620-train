# lerobot_TG620-train

Workspace aggregator for TG arm620 integration:

- `lerobot` (as submodule): LeRobot fork with `tg_arm620_follower` and `tg_arm620_keyboard`.
- `TG_Robot/src/ros2_socketcan` (as submodule): forked `ros2_socketcan` with TG-specific fixes.

Current publishing layout:

- `submodules/lerobot-feat` branch stores the `lerobot` submodule commit.
- `submodules/ros2-socketcan-feat` branch stores the `ros2_socketcan` submodule commit.
- `.gitmodules` points both submodules to this same repository URL so commits can be resolved without extra forks.

## Clone

```bash
git clone --recurse-submodules git@github.com:holmsslk/lerobot_TG620-train.git
cd lerobot_TG620-train
```

If submodules are missing:

```bash
git submodule update --init --recursive
```

## Update submodules to recorded commits

```bash
git submodule sync --recursive
git submodule update --init --recursive
git submodule status
```

## Runtime quick start

```bash
cd TG_Robot
source /opt/ros/humble/setup.bash
source install/setup.bash
export GAZEBO_MODEL_DATABASE_URI=""
ros2 launch robot_bringup robot_gazebo_lerobot.launch.py
```
