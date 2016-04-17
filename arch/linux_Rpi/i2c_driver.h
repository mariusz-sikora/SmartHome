#ifndef _I2C_DRIVER_H_
#define _I2C_DRIVER_H_

/*
    @brief: Open I2C driver

    @param[in] filename : name of driver to open.

    @retval handle to driver.
*/
int OpenDriverI2C(const char *filename);

/*
    @brief Close I2C driver

    @param[in] file_i2c : handle to driver.

    @retval None.
 */
int CloseDriverI2C(const int handle);

/*
    @brief Send message via I2C driver to device.

    @param[in] handle : handle to driver.
    @param[in] addr   : address of device.
    @param[in] cmd    : command.
    @param[in] buff   : message to send.
    @param[in] len    : len of message.
 */
int SendDriverI2C(
        const int handle,
        const unsigned char addr,
        const unsigned char cmd,
        const char *buff,
        const int len);

/*
    @brief Read message via I2C driver from device.

    @param[in] handle : handle to driver.
    @param[in] addr   : address of device.
    @param[in] cmd    : command.
    @param[io] buff   : received message.
    @param[in] len    : len of message to read.
 */
int ReadDriverI2C(
        const int handle,
        const unsigned char addr,
        const unsigned char cmd,
        char *buff,
        const int len);



#endif // _i2C_DRIVER_H_
