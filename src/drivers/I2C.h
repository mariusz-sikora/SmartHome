#pragma once

#include <memory>

namespace SmartHome {
namespace I2C {

typedef int (*OpenDriverI2C) (const char *filename);
typedef int (*CloseDriverI2C) (const int handle);

typedef int (*SendDriverI2C) (const int handle,
                              const unsigned char addr,
                              const unsigned char cmd,
                              const char *buff,
                              const int len);

typedef int (*ReadDriverI2C) (const int handle,
                              const unsigned char addr,
                              const unsigned char cmd,
                              char *buff,
                              const int len);

class I2C
{
public:
    static std::unique_ptr<I2C> CreateDriverI2C(
            OpenDriverI2C  open,
            CloseDriverI2C close,
            SendDriverI2C  send,
            ReadDriverI2C  read);

private:
    I2C(OpenDriverI2C  open,
        CloseDriverI2C close,
        SendDriverI2C  send,
        ReadDriverI2C  read);

    OpenDriverI2C  open;
    CloseDriverI2C close;
    SendDriverI2C  send;
    ReadDriverI2C  read;

};

} // I2C namespace
} // SmartHome namespace
