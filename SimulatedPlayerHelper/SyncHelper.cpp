#include "pch.h"
#include "SyncHelper.h"
#include "SymHelper.h"
#include <map>
#include <lbpch.h>

using namespace std;

unordered_map<long long, long long> syncMap;

bool startSync(Player* pl, SimulatedPlayer* sp) {
    if (!isSimulatedPlayer(sp))
        return false;
    auto uid = &pl->getUniqueID();
    if (uid && uid->id) {
        syncMap[uid->id] = sp->getUniqueID().id;
        return false;
    }
    return false;
};

bool stopSync(Player* pl) {
    if (pl) {
        syncMap.erase(pl->getUniqueID().id);
        return true;
    }
    return false;
};

SimulatedPlayer* getSP(Player* pl) {
    auto& auid = syncMap[pl->getUniqueID().id];
    return (SimulatedPlayer*)getPlayerByAUID(auid);
}

float getSpeed(Player* pl) {
    return SymCall("?getSpeed@Player@@UEBAMXZ", float, Player*)(pl);
}

THook(void, "?move@Player@@UEAAXAEBVVec3@@@Z",
    Player* _this, Vec3 const& v3) {
    if (auto sp = getSP(_this)) {
        auto speed = getSpeed(_this);
        sp->simulateWorldMove(v3, speed);
    }
    original(_this, v3);
}


//THook(void, "?jumpFromGround@Player@@UEAAXXZ",
//    Player* _this) {
//    if (auto sp = getSP(_this)) {
//        sp->simulateJump();
//    }
//    original(_this);
//}

THook(void, "?handle@ServerNetworkHandler@@UEAAXAEBVNetworkIdentifier@@AEBVPlayerActionPacket@@@Z",
    ServerNetworkHandler* _this, const NetworkIdentifier* source, const struct PlayerActionPacket* packet) {
    auto pl = _this->_getServerPlayer(*source, dAccess<uchar, 16>(packet));
    auto sp = getSP(pl);
    if (!sp)
        return original(_this, source, packet);
    auto type = dAccess<PlayerActionType>(packet, 16 * 4);
    auto& bpos = dAccess<BlockPos>(packet, 48);
    int face = dAccess<int>(packet, 60);
    void* rtid = dAccess<void*>(packet, 72);
    switch (type)
    {
    case PlayerActionType::JUMP:
        sp->simulateJump();
        break;
    case PlayerActionType::START_SPIN_ATTACK:
        sp->simulateAttack();
        break;
    case PlayerActionType::INTERACT_BLOCK:
        sp->simulateInteract(bpos, face);
        break;
    case PlayerActionType::START_BREAK:
        sp->simulateDestroyBlock(bpos, face);
        break;
    case PlayerActionType::STOP_BREAK:
    case PlayerActionType::ABORT_BREAK:
        sp->simulateStopDestroyingBlock();
        break;
    default:
        break;
    }
    original(_this, source, packet);
}