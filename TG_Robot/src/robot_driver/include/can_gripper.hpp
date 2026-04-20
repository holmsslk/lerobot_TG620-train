#ifndef CAN_GRIPPER_H
#define CAN_GRIPPER_H

#include <cstdint>
#include <stdexcept>
#include <cstring>
#include <cassert>
#include <iostream>


#define CANFD_2_RS485_ID 0x3F
#define RS485_2_CANFD_ID 0x4F

#define SEND_GRIPPER_ID 0x5F
#define RECV_GRIPPER_ID 0x6F

enum class Gripper_Type : uint8_t 
{
    OmniPicker = 0,
    PGC_Gripper,
    Raw_Frame,
};
class Canfd_485_Raw_Frame
{
public:
    // 常量：最大长度
    static constexpr size_t MAX_CANFD_LEN = 64;

    static constexpr size_t MAX_EXTRA_FRAME_LEN = 6;

    // 构造函数，解析接受数据
    Canfd_485_Raw_Frame(const uint8_t* data = nullptr, size_t length = 0, bool Tx_Flag = false) 
    {
        assert(Tx_Flag == true || Tx_Flag == false);
        std::cout << "Canfd_485_Raw_Frame::Canfd_485_Raw_Frame() Tx_Flag: " << Tx_Flag << std::endl;
        #ifdef DEBUG
        if (data == nullptr || length == 0) 
        {
            std::runtime_error("Data pointer is null or length is zero.");
        }
        if (length > MAX_CANFD_LEN + MAX_EXTRA_FRAME_LEN) 
        {
            std::cout << "Data length exceeds maximum CANFD length." << std::endl;
        }
        std::cout << "Canfd_485_Raw_Frame::Canfd_485_Raw_Frame() data length: " << length << std::endl;
        std::cout << "Canfd_485_Raw_Frame::Canfd_485_Raw_Frame() data: ";
        for (size_t i = 0; i < length; ++i) 
        {
            std::cout << std::hex << static_cast<int>(data[i]) << " ";
        }
        std::cout << std::dec << std::endl;
        #endif

        if (Tx_Flag) 
        {
            packed(data, length);
        } 
        else 
        {
            parsed(data, length);
        }
    };

    // 获取串口数据指针
    const uint8_t* getDataPtr() const 
    {
        return data_buffer;
    }

    // 获取数据长度
    size_t getDataLength() const 
    {
        return data_len;
    }

private:
    uint8_t data_buffer[MAX_CANFD_LEN + MAX_EXTRA_FRAME_LEN] = {};  // 固定长度缓冲区
    size_t data_len = 0;

    void parsed(const uint8_t* data, size_t length) 
    {
        if (length < MAX_EXTRA_FRAME_LEN || length > MAX_CANFD_LEN) 
        {
            std::cout << "parsed frame length invalid. Inpout length: " + std::to_string(length) << std::endl;
            return;
        }

        if (data[0] != 0x55 || data[1] != 0xaa) 
        {
            std::cout << "Invalid CANFD header." << std::endl;
            return;
        }

        uint8_t n = data[2];
        size_t expected_len = n + MAX_EXTRA_FRAME_LEN;  // 头3字节+数据n字节+校验+0xeb+0xaa

        if (length < expected_len) 
        {
            std::cout << "Incomplete CANFD frame." << std::endl;
            return;
        }

        // 校验和计算（D0 到 Dn+2）
        uint8_t checksum = 0;
        for (uint8_t i = 0; i <= 2 + n; ++i) 
        {
            checksum += data[i];
        }

        if (checksum != data[3 + n]) 
        {
            std::cout << "Checksum mismatch." << std::endl;
            return;
        }

        if (data[4 + n] != 0xeb || data[5 + n] != 0xaa) 
        {
            std::cout << "Invalid frame tail." << std::endl;
            return;
        }

        // 复制数据段
        std::copy(data, data + MAX_EXTRA_FRAME_LEN, data_buffer);
        data_len = n + MAX_EXTRA_FRAME_LEN;
    }

    void packed(const uint8_t* data, size_t length) 
    {
        if ( length > MAX_CANFD_LEN) 
        {
            std::cout << "packed frame length invalid." << std::endl;
        }

        data_buffer[0] = 0x55;  // 固定头
        data_buffer[1] = 0xaa;  // 固定头
        if (length > MAX_CANFD_LEN) 
        {
            std::cout << "Data length exceeds maximum CANFD length." << std::endl;
        }   
        data_buffer[2] = static_cast<uint8_t>(length);      // 数据长度
        std::copy(data, data + length, data_buffer + 3);    // 复制数据


        // 校验和计算（D0 到 Dn+2）
        uint8_t checksum = 0;
        for (size_t i = 0; i <= 3 + length; ++i) 
        {
            checksum += data_buffer[i];
        }
        data_buffer[3 + length] = checksum;         // 校验和
        data_buffer[4 + length] = 0xeb;             // 固定尾
        data_buffer[5 + length] = 0xaa;             // 固定尾
        data_len = length + MAX_EXTRA_FRAME_LEN;     // 数据长度包括头和尾
    }
};


class OmniPicker_Frame
{
    enum 
    {
        NORMAL = 0x00,  // 正常
        OVERHEAT,       // 过热
        OVERSPEED,      // 超速
        INIT_FAIL,      // 初始化失败
        OVERLIMIT       // 超限
    };

    enum 
    {
        REACHED_DES = 0x00,  // 到达目标位置
        GIRPPER_MOVING,      // 夹爪移动中
        GRIPPER_JAM,         // 夹爪堵转
        OBJ_FALL             // 物体掉落
    };

public:
    OmniPicker_Frame(uint8_t Pos, uint8_t Speed, uint8_t Force, uint8_t Acc, uint8_t Dec)
    {
        uint8_t position = Pos * 255 / 100;
        uint8_t velocity = Speed * 255 / 100;
        uint8_t effort = Force * 255 / 100;
        data_buffer[0] = 0x01;
        data_buffer[1] = 0x01;
        data_buffer[2] = position;
        data_buffer[3] = velocity;
        data_buffer[4] = effort;
        data_buffer[5] = Acc;
        data_buffer[6] = Dec;
        data_buffer[7] = 0x00;  // 固定尾
    }

    OmniPicker_Frame(uint8_t *data, uint8_t data_len)
    {
        if (data_len != 6) 
        {
            std::cout << "OmniPicker frame length must be 8 bytes." << std::endl;
        }

        std::copy(data, data + data_len, data_buffer);

        switch(data[1])
        {
            case NORMAL:
                // 处理正常状态
                break;
            case OVERHEAT:
                // 处理过热状态
                std::cerr << "Warning: Gripper is overheat!" << std::endl;
                break;
            case OVERSPEED:
                // 处理超速状态
                std::cerr << "Warning: Gripper is overspeed!" << std::endl;
                break;
            case INIT_FAIL:
                // 处理初始化失败状态
                std::cerr << "Error: Gripper initialization failed!" << std::endl;
                break;
            case OVERLIMIT:
                // 处理超限状态
                std::cerr << "Error: Gripper is overlimit!" << std::endl;
                break;
            default:
                std::cout << "Unknown OmniPicker status." << std::endl;
        }
        switch (data[2])
        {
            case REACHED_DES:
                // 处理到达目标位置状态
                std::cout << "Gripper has reached the desired position." << std::endl;
                break;
            case GIRPPER_MOVING:
                // 处理夹爪移动中状态
                std::cout << "Gripper is moving." << std::endl;
                break;
            case GRIPPER_JAM:
                // 处理夹爪堵转状态
                std::cerr << "Warning: Gripper is jammed!" << std::endl;
                break;
            case OBJ_FALL:
                // 处理物体掉落状态
                std::cerr << "Warning: Object has fallen!" << std::endl;
                break;
            default:
                std::cout << "Unknown OmniPicker action status." << std::endl;
        }
    }
    uint8_t getPos() const 
    {
        return data_buffer[3];
    }
    uint8_t getSpeed() const 
    {
        return data_buffer[4];
    }
    uint8_t getForce() const 
    {
        return data_buffer[5];
    }

    const uint8_t* getDataPtr() const 
    {
        return data_buffer;
    }

private:
    uint8_t data_buffer[8] = {0};  // 固定长度缓冲区

};


class PGC_Gripper
{
private:
    uint8_t data_buffer[8] = {0};  // 固定长度缓冲区

    enum 
    {
        GIRPPER_MOVING = 0x00,  
        GIRPPER_STOP_GIRPPER_NOTHING,      
        GIRPPER_STOP_GIRPPER_SOMETHING,         
        GIRPPER_STOP_OBJ_FALL
    };

public:
    PGC_Gripper(uint8_t velocity, uint8_t effort, uint8_t position)
    {
        uint16_t Pos = position * 10;
        assert(0x01 <= velocity && velocity <= 0x64);
        assert(0x14 <= effort && effort <= 0x64);
        assert(0x00 <= Pos && Pos <= 0x03E8);

        data_buffer[0] = 0x02;
        data_buffer[1] = 0x01;
        data_buffer[2] = velocity >> 8; 
        data_buffer[3] = velocity & 0xFF; 
        data_buffer[4] = effort >> 8;
        data_buffer[5] = effort & 0xFF;
        data_buffer[6] = Pos >> 8;
        data_buffer[7] = Pos & 0xFF;
    }

    PGC_Gripper(uint8_t *data_length = nullptr)
    {
        data_buffer[0] = 0x02;
        data_buffer[1] = 0x02;
        if (data_length != nullptr) 
        {
            *data_length = 2;
        }
    }

    PGC_Gripper(uint8_t *data, uint8_t data_len)
    {
        if (data_len != 2) 
        {
            std::cout << "PGC Gripper frame length must be 2 bytes." << std::endl;
            return;
        }

        std::copy(data, data + data_len, data_buffer);

        switch (data[1])
        {
            case GIRPPER_MOVING:
                // 处理夹爪移动中状态
                std::cout << "Gripper is moving." << std::endl;
                break;
            case GIRPPER_STOP_GIRPPER_NOTHING:
                // 处理夹爪停止且无物体状态
                std::cout << "Gripper stopped, nothing in gripper." << std::endl;
                break;
            case GIRPPER_STOP_GIRPPER_SOMETHING:
                // 处理夹爪停止且有物体状态
                std::cout << "Gripper stopped, something in gripper." << std::endl;
                break;
            case GIRPPER_STOP_OBJ_FALL:
                // 处理物体掉落状态
                std::cerr << "Warning: Object has fallen!" << std::endl;
                break;
            default:
                std::cout << "Unknown PGC Gripper status." << std::endl;
        }
    }
    
    // 获取串口数据指针
    const uint8_t* getDataPtr() const 
    {
        return data_buffer;
    }
};


#endif // CANFD_FRAME_H

