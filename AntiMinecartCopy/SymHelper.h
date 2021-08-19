#include "pch.h"
#include "mc/BlockSource.h"
#include "mc/LevelChunk.h"

BlockSource* getBlockSourceByDim(int dimid);
LevelChunk* getChunkByXZ(BlockSource* bs, int x, int z);
void setChunkUnsaved(LevelChunk* lc);
bool isDirty(LevelChunk* lc);