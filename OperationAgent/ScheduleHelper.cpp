#include "pch.h"
#include <map>

long long ticks;
std::map<long long, std::function<void()>> funcSchedule;
void setTimeOut(std::function<void()> func, long long denyTick) {
	auto scheduleTick = ticks + denyTick;
	while (funcSchedule.size() > 0 && funcSchedule.find(scheduleTick) != funcSchedule.end())
	{
		++scheduleTick;
	}
	funcSchedule[scheduleTick] = func;
}

// ===== Tcik Schedule =====
THook(void, "?tick@ServerLevel@@UEAAXXZ", void* _this) {
	if (funcSchedule.size() > 0) {
		// 效率可能不太高，但是在不大量设置长时间延迟的情况下应该没什么问题
		for (auto funcIter = funcSchedule.begin(); funcIter != funcSchedule.end(); ++funcIter) {
			if (funcIter->first < ticks) {
				funcIter->second();
				funcSchedule.erase(funcIter);
			}
		}
	}
	ticks++;
	original(_this);
}