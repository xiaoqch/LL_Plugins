#include "pch.h"
#include "SymHelper.h"

LevelChunk* getChunkAt(BlockSource* bs, BlockPos bpos) {
    return SymCall("?getChunkAt@BlockSource@@QEBAPEAVLevelChunk@@AEBVBlockPos@@@Z", LevelChunk*, BlockSource*, BlockPos&)(bs, bpos);
}

void setChunkUnsaved(LevelChunk* lc) {
    SymCall("?setUnsaved@LevelChunk@@QEAAXXZ", void, LevelChunk*)(lc);
}

bool isDirty(LevelChunk* lc) {
    unsigned short result = SymCall("?isDirty@LevelChunk@@QEBA_NXZ", unsigned short, LevelChunk*)(lc);
    return result != 0;
}