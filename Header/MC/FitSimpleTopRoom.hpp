// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class FitSimpleTopRoom {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_FITSIMPLETOPROOM
public:
    class FitSimpleTopRoom& operator=(class FitSimpleTopRoom const&) = delete;
    FitSimpleTopRoom(class FitSimpleTopRoom const&) = delete;
    FitSimpleTopRoom() = delete;
#endif

public:
    /*0*/ virtual ~FitSimpleTopRoom();
    /*1*/ virtual bool fits(class RoomDefinition const&) const;
    /*2*/ virtual std::unique_ptr<class OceanMonumentPiece> create(int&, class std::shared_ptr<class RoomDefinition>, class Random&);

protected:

private:

};