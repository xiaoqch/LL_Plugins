// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class GameTestLevelListener {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_GAMETESTLEVELLISTENER
public:
    class GameTestLevelListener& operator=(class GameTestLevelListener const&) = delete;
    GameTestLevelListener(class GameTestLevelListener const&) = delete;
    GameTestLevelListener() = delete;
#endif

public:
    /*0*/ virtual ~GameTestLevelListener();
    /*1*/ virtual void __unk_vfn_0();
    /*2*/ virtual void __unk_vfn_1();
    /*3*/ virtual void __unk_vfn_2();
    /*4*/ virtual void __unk_vfn_3();
    /*5*/ virtual void __unk_vfn_4();
    /*6*/ virtual void __unk_vfn_5();
    /*7*/ virtual int /*enum enum EventResult*/ onLevelTick();
    MCAPI GameTestLevelListener(class gametest::GameTestTicker&);

protected:

private:

};