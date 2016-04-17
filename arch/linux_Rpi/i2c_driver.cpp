#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/i2c-dev.h>

#define IsI2CHandleValid(handle) (0 <= (handle))

/* @brief Please see header file */
int OpenDriverI2C(const char *filename)
{
    int file_i2c;

    if( 0 == filename )
        return -1;

    file_i2c = open(filename, O_RDWR);

    return file_i2c;
}

/* @brief Please see header file */
int CloseDriverI2C(const int handle)
{
    return close( handle );
}

/* @brief Please see header file */
int SendDriverI2C(
        const int handle,
        const unsigned char addr,
        const unsigned char cmd,
        const char *buff,
        const int len)
{
    struct i2c_rdwr_ioctl_data msg_rdwr = { 0 };
    struct i2c_msg i2cmsg;
    int status = 0;
    char writeBuff[200] = { 0 };

    if(!IsI2CHandleValid(handle))
        return -1;

    if(sizeof(writeBuff) < len + 1)
        return -1;

    writeBuff[0] = cmd;
    for(int i = 0; i < len; i++)
        writeBuff[i + 1] = buff[i];

    msg_rdwr.msgs = &i2cmsg;
    msg_rdwr.nmsgs = 1;
    i2cmsg.addr = addr;
    i2cmsg.flags = 0;
    i2cmsg.len = 1 + len;
    i2cmsg.buf = writeBuff;

    status = ioctl(handle, I2C_RDWR, &msg_rdwr);

    return status;
}

/* @brief Please see header file */
int ReadDriverI2C(
        const int handle,
        const unsigned char addr,
        const unsigned char cmd,
        char *buff,
        const int len)
{
    struct i2c_rdwr_ioctl_data msg_rdwr = { 0 };
    struct i2c_msg i2cmsg = { 0 };
    int status = 0;

    if(!IsI2CHandleValid(handle))
        return -1;

    msg_rdwr.msgs = &i2cmsg;
    msg_rdwr.nmsgs = 1;
    i2cmsg.addr = addr;
    i2cmsg.flags = I2C_M_RD;
    i2cmsg.len = len;
    i2cmsg.buf = buff;

    status = ioctl(handle, I2C_RDWR, &msg_rdwr);

    return status;
}


