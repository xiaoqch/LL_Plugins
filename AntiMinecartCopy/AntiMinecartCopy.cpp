#include "pch.h"
#include "loader/Loader.h"
#include "mc/Actor.h"
#include "mc/BlockSource.h"
#include "mc/LevelChunk.h"
#include "SymHelper.h"
#include <iostream>
#include <string>

//#include <windows.h>

using namespace std;

//LARGE_INTEGER t1, t2, tc;

//double deltaTime(LARGE_INTEGER t1, LARGE_INTEGER t2, LARGE_INTEGER tc) {
//	return (double)(t2.QuadPart - t1.QuadPart) / (double)tc.QuadPart;
//}

void entry()
{
	//QueryPerformanceFrequency(&tc);
	std::cout << "[AntiMinecartCopy] AntiMinecartCopy Loaded. Version: 1.1" << endl;
}

THook(short, "?pullInItems@HopperComponent@@QEAA_NAEAVActor@@@Z", void* a1, Actor* at)
{
	//QueryPerformanceCounter(&t1);
	short result = original(a1, at);
	//QueryPerformanceCounter(&t2);
	if (result != 0) {
		//printf("[AntiMinecartCopy] %-10s %.5fms\n", "original time:", deltaTime(t1, t2, tc) * 1000);
		//QueryPerformanceCounter(&t1);
		BlockSource* bs = getBlockSourceByDim(at->getDimensionId());
		Vec3 pos = at->getPos();
		LevelChunk* lc = getChunkByXZ(bs, floor(pos.x / 16), floor(pos.z / 16));
		if (!isDirty(lc)) {
			setChunkUnsaved(lc);
		}
		//QueryPerformanceCounter(&t2);
		//printf("[AntiMinecartCopy] %-10s %.5fms\n", "fix time:", deltaTime(t1, t2, tc) * 1000);
		//std::cout << "[AntiMinecartCopy] dimid: " << at->getDimensionId() <<", pos: " << pos.toString() << endl;
		//std::cout << "[AntiMinecartCopy] result: " << floor(pos.x / 16) << ", " << floor(pos.z / 16) << endl;
	}
	return result;
}