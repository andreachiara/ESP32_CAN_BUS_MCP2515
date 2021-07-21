
#pragma once
#include "driver/spi_master.h"
#include "driver/gpio.h"
#include "esp_err.h"
#include <memory> 

#ifdef __cplusplus
extern "C"
{
#endif

void init_spi_can1();

esp_err_t spi2_send_data(uint16_t cmd, char *data, size_t len);

esp_err_t spi2_send_byte(char byte);

#ifdef __cplusplus
}
#endif