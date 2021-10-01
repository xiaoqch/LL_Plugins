#include "pch.h"
#include "Util.h"

void setTimeOut(function<void()> func, tick_t denyTick) {
	auto task = DelayedTask(std::move(func), denyTick/20);
	auto taskId = Handler::schedule(std::move(task));
}