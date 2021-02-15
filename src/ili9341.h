#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

#include "lvgl.h"
// #include "../lvgl_helpers.h"
#include "config.h"

#define ILI9341_DC CONFIG_LV_DISP_PIN_DC
#define ILI9341_RST CONFIG_LV_DISP_PIN_RST
#define ILI9341_BCKL CONFIG_LV_DISP_PIN_BCKL

void ili9341_init(void);
void ili9341_flush(lv_disp_drv_t *drv, const lv_area_t *area,
                   lv_color_t *color_map);
void ili9341_enable_backlight(bool backlight);
void ili9341_sleep_in(void);
void ili9341_sleep_out(void);

#ifdef __cplusplus
} /* extern "C" */
#endif
