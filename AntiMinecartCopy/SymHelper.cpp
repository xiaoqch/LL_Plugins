#include "pch.h"
#include "SymHelper.h"

Minecraft* mc = nullptr;
//BlockSource* bss[] = { nullptr, nullptr, nullptr };

//?getLevel@Actor@@QEBAAEBVLevel@@XZ
//?isFree@Actor@@UEAA_NAEBVVec3@@@Z
//?isInWorld@Actor@@QEBA_NXZ
//?isRemoved@Actor@@QEBA_NXZ
//?isResting@Actor@@QEBA_NXZ
//?isSilent@Actor@@UEAA_NXZ
//?outOfWorld@Actor@@MEAAXXZ
//?tryMoveChunks@Actor@@QEAA_NXZ
//?setChanged@BlockActor@@QEAAXXZ

THook(void, "?initAsDedicatedServer@Minecraft@@QEAAXXZ", void* self)
{
	original(self);
	mc = (Minecraft*)self;
}

BlockSource* getBlockSourceByDim(int dimid)
{
	//if (bss[dimid] != nullptr) { return bss[dimid]; }
	auto dim = (int*)SymCall("?getDimension@Level@@UEBAPEAVDimension@@V?$AutomaticID@VDimension@@H@@@Z",
		uintptr_t, void*, int)(mc->getLevel(), dimid);
	return dAccess<BlockSource*>(dim, 96);
	//bss[dimid] = dAccess<BlockSource*>(dim, 96);
	//return bss[dimid];
}

LevelChunk* getChunkByXZ(BlockSource* bs, int x, int z) {
	return SymCall("?getChunk@BlockSource@@QEBAPEAVLevelChunk@@HH@Z", LevelChunk*, BlockSource*, int, int)(bs, x, z);
}

void setChunkUnsaved(LevelChunk* lc) {
	SymCall("?setUnsaved@LevelChunk@@QEAAXXZ", void, LevelChunk*)(lc);
}

bool isDirty(LevelChunk* lc) {
	unsigned short result = SymCall("?isDirty@LevelChunk@@QEBA_NXZ", unsigned short, LevelChunk*)(lc);
	//std::cout << "[AntiMinecartCopy] isDirty: " << result << std::endl;
	return result != 0;
}