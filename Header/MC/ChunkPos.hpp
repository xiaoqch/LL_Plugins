// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class ChunkPos {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_CHUNKPOS
public:
    class ChunkPos& operator=(class ChunkPos const&) = delete;
    ChunkPos(class ChunkPos const&) = delete;
    ChunkPos() = delete;
#endif

public:
    MCAPI ChunkPos(class BlockPos const&);
    MCAPI ChunkPos(class Vec3 const&);
    MCAPI bool isWithinBounds(class ChunkPos const&, class ChunkPos const&) const;
    MCAPI class Vec3 toBlockSpaceVec3(float) const;
    MCAPI static class ChunkPos const INVALID;
    MCAPI static class ChunkPos const MAX;
    MCAPI static class ChunkPos const MIN;
    MCAPI static class ChunkPos const ONE;

protected:

private:

};