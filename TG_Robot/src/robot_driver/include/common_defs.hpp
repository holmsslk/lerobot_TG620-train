#ifndef __COMMON_DEFS_HPP__
#define __COMMON_DEFS_HPP__

#include <cstdint>
#include <map>
namespace motor_driver {

union FloatUintConverter {
    float f; 
    uint32_t u; 
};

enum class MotorFeedbackMethod : uint8_t {
    ONCE  = 0x00,
    CYCLE = 0x01
};

enum class MotorFeedbackType : uint8_t {
    DATA1 = 0x01,   // Include: enable_flag, motor_mode, position
    DATA2 = 0x02,   // Include: limit_flag, temeprature, velocity
    DATA3 = 0x03,   // Include: voltage, current
    DATA4 = 0x04,   // Include: error_code
};

enum class ExecuteStatus : uint8_t {
    SUCCESS = 0x01,
    FAILED = 0xFF,
};

enum class CommandType_Tx : uint32_t {
    MOTOR_CTRL = 0x000,
    FDB_REQ = 0x200,
    FUNC_CTRL = 0x400,
    PARAM_RW = 0x600,
    DUBUG_PARAM = 0x1600,
    BUTTON_SEND = 0x7F,
};

enum class CommandType_Rx : uint32_t {
    MOTOR_CTRL = 0x100,
    FDB_REQ = 0x300,
    FUNC_CTRL = 0x500,
    PARAM_RW = 0x700,
    DUBUG_PARAM = 0x1700,
};

enum class OperationMethod : uint8_t {
    READ = 0x01,
    WRITE = 0x02,
};

enum class MotorControlMode : uint8_t {
    CURRENT_MODE         = 0x02,
    EFFORT_POSITION_MODE = 0x03,
    SPEED_MODE           = 0x04,
    POSITION_ABS_MODE    = 0x05,
    POSITION_INC_MODE    = 0x06
};

enum class MotorEnableMode : uint8_t {
    MOTOR_DISABLE = 0x00,
    MOTOR_ENABLE  = 0x01
};

enum class ParamType : uint8_t {
    INT32 = 0x01,
    FLOAT = 0x02
};

enum class FuncOpCode : uint8_t {
    PARAM_RESET = 0x01,
    PARAM_SAVE_TO_FLASH = 0x02,
    CLEAR_ERROR_CODE = 0x03,
    MOTOR_ZERO_POS_SET = 0x04,
    MOTOR_FIND_ZERO_POS = 0x11,
    MOTOR_IAP_UPDATE = 0x12,
    MOTOR_HALL_CALIBRATION = 0x13,
    MOTOR_CURRENT_CALIBRATION = 0x14,
    MOTOR_ENCODER_CALIBRATION = 0x15,
    MOTOR_SOFTWARE_RESET = 0x16
};


enum class ParamAddr : uint16_t {
    SYS_CAN_ID_BASE = 0x0000,
    SERVO_CONTROL_MODE = 0x0001,
    SERVO_ENABLE_FLAG = 0x0002,
    LIMIT_POS_FLAG = 0x0003,
    SYS_CAN_TYPE = 0x0004,
    SYS_INT_RESERVER_3 = 0x0005,
    SYS_INT_RESERVER_2 = 0x0006,
    SYS_INT_RESERVER_1 = 0x0007,
    LIMIT_POS_MAX = 0x0008,
    LIMIT_POS_MIN = 0x0009,
    LIMIT_POS_ZERO = 0x000A,
    LIMIT_VELOCITY_MAX = 0x000B,
    LIMIT_VELOCITY_ACC_T1 = 0x000C,
    LIMIT_CURRENT_MAX = 0x000D,
    LIMIT_VOLTAGE_MAX = 0x000E,
    LIMIT_VELOCITY_ACC_T3 = 0x000F,

};
enum class DebugParamAddr : uint16_t
{
    SYS_HARD_VERSION = 0,
    SYS_SOFT_VERSION = 1,
    SYS_PN_3 = 2,
    SYS_PN_2 = 3,
    SYS_PN_1 = 4,
    SYS_PN_0 = 5,
    SYS_SN_3 = 6,
    SYS_SN_2 = 7,
    SYS_SN_1 = 8,
    SYS_SN_0 = 9,
    SERVO_MIX_KP = 80,
    SERVO_MIX_KI = 81,
    SERVO_MIX_KD = 82,
    SERVO_POS_KP = 83,
    SERVO_POS_KI = 84,
    SERVO_POS_KD = 85,
    SERVO_VELOCITY_KP = 86,
    SERVO_VELOCITY_KI = 87,
    SERVO_VELOCITY_KD = 88,
    SERVO_VELOCITY_KA = 89,
    SERVO_CURRENT_KP = 90,
    SERVO_CURRENT_KI = 91,
    SERVO_CURRENT_KD = 92,
};
class Motor_Parameter 
{
public:
    // 定义类型标识符
    enum Type 
    {
        INT32 = 0x01,
        FLOAT = 0x02
    };
    enum ParameterEnum 
    {
        servo_mix_kp = 80,
        servo_mix_ki,
        servo_mix_kd,
        servo_pos_kp,
        servo_pos_ki,
        servo_pos_kd,
        servo_velocity_kp,
        servo_velocity_ki,
        servo_velocity_kd,
        servo_velocity_ka,
        servo_current_kp,
        servo_current_ki,
        servo_current_kd,
    };
    // 参数信息结构体
    struct ParamInfo 
    {
        uint16_t address;   // 参数地址
        uint8_t type;       // 参数类型（字符串描述）
    };
    inline static const std::map<ParameterEnum, ParamInfo> param_info_map = 
    {
        { servo_mix_kp,           {80,  FLOAT} },
        { servo_mix_ki,           {81,  FLOAT} },
        { servo_mix_kd,           {82,  FLOAT} },
        { servo_pos_kp,           {83,  FLOAT} },
        { servo_pos_ki,           {84,  FLOAT} },
        { servo_pos_kd,           {85,  FLOAT} },
        { servo_velocity_kp,      {86,  FLOAT} },
        { servo_velocity_ki,      {87,  FLOAT} },
        { servo_velocity_kd,      {88,  FLOAT} },
        { servo_velocity_ka,      {89,  FLOAT} },
        { servo_current_kp,       {90,  FLOAT} },
        { servo_current_ki,       {91,  FLOAT} },
        { servo_current_kd,       {92,  FLOAT} }
    };
    
    // 构造函数
    Motor_Parameter(ParameterEnum id) : id(id)
    {
        address = param_info_map.at(id).address;
        type = param_info_map.at(id).type;
    }
public:
    uint16_t id;              // 参数的ID
    uint16_t address;       // 参数的地址
    uint8_t type;           // 参数的类型标识符
};

constexpr float PI = 3.141592654f;
constexpr int MOTOR_NUM = 6;

enum class BUTTONSTATUS : uint8_t {
    ENTRY_TEACH  = 1,
    EXIT_TEACH   = 2,
    TEACH_REPEAT = 3,
};
// 定义一个协议映射结构体
typedef struct {
    char code[5]; // 存储 ASCII 字符串 (4字节 + '\0')
    uint8_t description; // 协议含义
} ProtocolEntry;

extern const ProtocolEntry protocol_table[];

#define PROTOCOL_COUNT (sizeof(protocol_table)/sizeof(protocol_table[0]))

}   



// namespace motor_driver


#endif