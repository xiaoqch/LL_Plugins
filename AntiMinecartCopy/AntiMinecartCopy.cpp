#include "pch.h"
#include "loader/Loader.h"
#include "SymHelper.h"
#include <iostream>
#include <mc/OffsetHelper.h>

using namespace std;

#define VERSION "1.2.0"

void entry()
{
    std::cout << "Anti Minecart Copy Plugin Loaded. Version: " << VERSION << endl;
}

THook(short, "?pullInItems@HopperComponent@@QEAA_NAEAVActor@@@Z", void* _this, Actor* actor)
{
    short result = original(_this, actor);
    if (result != 0) {
        BlockSource* bs = offPlayer::getBlockSource(actor);
        Vec3 pos = actor->getPos();
        LevelChunk* lc = getChunkAt(bs, pos.toBlockPos());
        //if(!isDirty(lc))
        if(!lc)
            return result;
        setChunkUnsaved(lc);
    }
    return result;
}