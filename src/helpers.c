#include "helpers.h"
#include "driver/i2c.h"
#include "driver/spi_master.h"
#include "esp_log.h"

#define TAG "helpers"

bool lvgl_spi_driver_init(int host, int miso_pin, int mosi_pin, int sclk_pin,
                          int max_transfer_sz, int dma_channel, int quadwp_pin,
                          int quadhd_pin) {
  assert((SPI_HOST <= host) && (VSPI_HOST >= host));
  const char *spi_names[] = {"SPI_HOST", "HSPI_HOST", "VSPI_HOST"};

  ESP_LOGI(TAG, "Configuring SPI host %s (%d)", spi_names[host], host);
  ESP_LOGI(TAG,
           "MISO pin: %d, MOSI pin: %d, SCLK pin: %d, IO2/WP pin: %d, IO3/HD "
           "pin: %d",
           miso_pin, mosi_pin, sclk_pin, quadwp_pin, quadhd_pin);

  ESP_LOGI(TAG, "Max transfer size: %d (bytes)", max_transfer_sz);

  spi_bus_config_t buscfg = {.miso_io_num = miso_pin,
                             .mosi_io_num = mosi_pin,
                             .sclk_io_num = sclk_pin,
                             .quadwp_io_num = quadwp_pin,
                             .quadhd_io_num = quadhd_pin,
                             .max_transfer_sz = max_transfer_sz};

  ESP_LOGI(TAG, "Initializing SPI bus...");
  esp_err_t ret = spi_bus_initialize(host, &buscfg, dma_channel);
  assert(ret == ESP_OK);

  return ESP_OK != ret;
}

bool lvgl_i2c_driver_init(int port, int sda_pin, int scl_pin, int speed_hz) {
  esp_err_t err;

  ESP_LOGI(TAG, "Initializing I2C master port %d...", port);
  ESP_LOGI(TAG, "SDA pin: %d, SCL pin: %d, Speed: %d (Hz)", sda_pin, scl_pin,
           speed_hz);

  i2c_config_t conf = {
      .mode = I2C_MODE_MASTER,
      .sda_io_num = sda_pin,
      .sda_pullup_en = GPIO_PULLUP_ENABLE,
      .scl_io_num = scl_pin,
      .scl_pullup_en = GPIO_PULLUP_ENABLE,
      .master.clk_speed = speed_hz,
  };

  ESP_LOGI(TAG, "Setting I2C master configuration...");
  err = i2c_param_config(port, &conf);
  assert(ESP_OK == err);

  ESP_LOGI(TAG, "Installing I2C master driver...");
  err = i2c_driver_install(
      port, I2C_MODE_MASTER, 0,
      0 /*I2C_MASTER_RX_BUF_DISABLE, I2C_MASTER_TX_BUF_DISABLE */,
      0 /* intr_alloc_flags */);
  assert(ESP_OK == err);

  return ESP_OK != err;
}
