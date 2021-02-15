if(ESP_PLATFORM)

  idf_component_register(
    SRCS "src/AXP192.cpp" "src/M5Core2.cpp" "src/ili9341.c" "src/disp_spi.c"
         "src/helpers.c" "src/ft6x36.c"
    INCLUDE_DIRS "include"
    REQUIRES lvgl)

endif()
