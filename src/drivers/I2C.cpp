#include "I2C.h"

namespace SmartHome {
namespace I2C {

std::unique_ptr<I2C> I2C::CreateDriverI2C(
        OpenDriverI2C  open,
        CloseDriverI2C close,
        SendDriverI2C  send,
        ReadDriverI2C  read)
{
    std::unique_ptr<I2C> driver(new I2C(open, close, send, read));
    
    return std::move(driver);
}

I2C::I2C(OpenDriverI2C  _open,
         CloseDriverI2C _close,
         SendDriverI2C  _send,
         ReadDriverI2C  _read)
    :
        open(_open),
        close(_close),
        send(_send),
        read(_read)
{

}


} // I2C namespace
} // SmartHome namespace
