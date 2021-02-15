#pragma once

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

bool lvgl_spi_driver_init(int host, int miso_pin, int mosi_pin, int sclk_pin,
                          int max_transfer_sz, int dma_channel, int quadwp_pin,
                          int quadhd_pin);

bool lvgl_i2c_driver_init(int port, int sda_pin, int scl_pin, int speed_hz);

#ifdef __cplusplus
}
#endif
