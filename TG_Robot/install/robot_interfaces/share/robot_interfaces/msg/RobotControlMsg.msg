uint8[] motor_enable_flag  # 0-disable  1-enable
uint8[] motor_mode        # 04-velocity   05-position   02-effort 
float64[] position
float64[] velocity
float64[] effort
uint8[] kp 
uint8[] kd 
# Constants
uint8 MOTOR_DISABLE = 0
uint8 MOTOR_ENABLE = 1

uint8 CURRENT_MODE         = 2
uint8 EFFORT_POSITION_MODE = 3
uint8 SPEED_MODE           = 4
uint8 POSITION_ABS_MODE    = 5
uint8 POSITION_INC_MODE    = 6
