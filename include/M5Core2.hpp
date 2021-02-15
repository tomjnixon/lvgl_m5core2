#pragma once

#include "AXP192.hpp"
#include <mutex>

extern std::mutex gui_mutex;

extern AXP192 pmu;

void m5core2_init();
