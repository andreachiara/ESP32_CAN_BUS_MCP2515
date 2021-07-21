#include "spi_driver.h"

static spi_device_handle_t spi2_hndl;
constexpr uint64_t mcp2518_addr {0xFF};
void init_spi_can1()
{
    spi_host_device_t host_dev {SPI2_HOST};
    spi_device_interface_config_t if_cfg {
    };
    spi_bus_add_device(host_dev, &if_cfg, &spi2_hndl);
}

void spi_can1_deinit() {
    spi_bus_remove_device(spi2_hndl);
}

esp_err_t spi2_send_data(uint16_t cmd, char *data, size_t len) {
    spi_transaction_t trans {
        .flags = (SPI_TRANS_MODE_QIO | SPI_TRANS_USE_RXDATA | SPI_TRANS_USE_TXDATA),
        .cmd = cmd,
        .addr = mcp2518_addr,
        .length = len
    };
    if (data != nullptr) {
        std::copy(data, data+len, trans.tx_data);
    }
    return spi_device_transmit(spi2_hndl, &trans);
}

esp_err_t spi2_send_byte(char byte) {
    return spi2_send_data(byte, nullptr, 0);
}