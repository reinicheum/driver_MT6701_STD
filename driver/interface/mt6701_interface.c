#include "mt6701_interface.h"
#include "main.h"
#include "i2c.h"
#include "mt6701.h"

#ifndef MT6701_DEFAULT_ADDRESS
#define MT6701_DEFAULT_ADDRESS 0x06
#endif

//extern I2C_HandleTypeDef hi2c2;

uint8_t mt6701_interface_i2c_write(uint8_t reg, uint8_t data) {
    uint8_t buffer[2] = {reg, data};

    HAL_StatusTypeDef status = HAL_I2C_Master_Transmit(&hi2c2,
                                                       MT6701_DEFAULT_ADDRESS << 1,
                                                       buffer,
                                                       2,
                                                       100);

    if (status != HAL_OK) {
        return 1;
    }
    
    return 0;
}

uint8_t mt6701_interface_i2c_read(uint8_t reg, uint8_t *data) {
    HAL_StatusTypeDef status = HAL_I2C_Master_Transmit(&hi2c2,
                                                       MT6701_DEFAULT_ADDRESS << 1,
                                                       &reg,
                                                       1,
                                                       100);
    if (status != HAL_OK) {
        return 1;
    }

    status = HAL_I2C_Master_Receive(&hi2c2,
                                    MT6701_DEFAULT_ADDRESS << 1,
                                    data,
                                    1,
                                    100);

    if (status != HAL_OK) {
        return 1;
    }
    
    return 0;
}

uint8_t mt6701_interface_ssi_read(uint8_t *data, uint8_t len) {
    return 1;
}

void mt6701_interface_delay(uint32_t ms) {
    HAL_Delay(ms);
}
