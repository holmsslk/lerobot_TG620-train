import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/holms/Projects/lerobot/TG_Robot/install/traj_smoother_py'
