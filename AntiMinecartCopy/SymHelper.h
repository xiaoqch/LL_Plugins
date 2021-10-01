#include "pch.h"
#include "mc/BlockSource.h"
#include "mc/LevelChunk.h"

BlockSource* getBlockSourceByDim(int dimid);
LevelChunk* getChunkAt(BlockSource* bs, BlockPos bpos);
void setChunkUnsaved(LevelChunk* lc);
bool isDirty(LevelChunk* lc);