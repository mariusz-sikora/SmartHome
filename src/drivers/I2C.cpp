#include "I2C.h"

namespace SmartHome {
namespace I2C {

std::unique_ptr<I2C> I2C::CreateDriverI2C(
        const char *filename,
        const OpenDriverI2C  open,
        const CloseDriverI2C close,
        const SendDriverI2C  send,
        const ReadDriverI2C  read)
{
    std::unique_ptr<I2C> driver(new I2C(open, close, send, read));
    
    driver->handle = driver->open(filename);

    return std::move(driver);
}

I2C::I2C(const OpenDriverI2C  _open,
         const CloseDriverI2C _close,
         const SendDriverI2C  _send,
         const ReadDriverI2C  _read)
    :
        open(_open),
        close(_close),
        send(_send),
        read(_read)
{
}

I2C::~I2C()
{
    this->close(this->handle);
}

} // I2C namespace
} // SmartHome namespace
