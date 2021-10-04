#pragma once
#include <api/scheduler/scheduler.h>

void setTimeOut(function<void()> func, tick_t denyTick);