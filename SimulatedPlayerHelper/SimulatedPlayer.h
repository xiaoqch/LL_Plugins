#pragma once
#include "SymHelper.h"

class SimulatedPlayer;

class SimulatedPlayerHelper
{
public:
    SimulatedPlayer* sp;
    inline SimulatedPlayerHelper(SimulatedPlayer* sp) {
        this->sp = sp;
    };
    inline static SimulatedPlayer* createSP(string const& name, BlockPos const& bpos, int dimid) {
        auto snh = getServerNetworkHandler();
        auto sp = SymCall("?create@SimulatedPlayer@@SAPEAV1@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEBVBlockPos@@V?$AutomaticID@VDimension@@H@@AEAVServerNetworkHandler@@@Z",
            SimulatedPlayer*, string const&, BlockPos const&, int, ServerNetworkHandler*)(name, bpos, dimid, snh);
        return sp;
    };
    inline static SimulatedPlayer* createSP(string const& name, int x, int y, int z, int dimid) {
        return createSP(name, { x, y, z }, dimid);
    }
};

