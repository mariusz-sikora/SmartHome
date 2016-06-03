#include "gtest/gtest.h"
#include "I2C.h"

int Open(const char *filename)
{
    return 4;
}

int Close(const int handle)
{
    return 0;
}

int Send(const int handle,
        const unsigned char addr,
        const unsigned char cmd,
        const char *buff,
        const int len)
{
    return 0;
}

int Read(const int handle,
        const unsigned char addr,
        const unsigned char cmd,
        char *buff,
        const int len)
{
    return 0;
}

TEST(I2C_driver, all)
{
    std::unique_ptr<SmartHome::I2C::I2C> I2C_driver = SmartHome::I2C::I2C::CreateDriverI2C(
            "Test\\Path",
            Open,
            Close,
            Send,
            Read);

    ASSERT_TRUE(nullptr != I2C_driver);
}
