#pragma once
#include <functional>

void setTimeOut(std::function<void()> func, long long denyTick);