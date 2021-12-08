// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "Json.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class FlatWorldGeneratorOptions {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_FLATWORLDGENERATOROPTIONS
public:
    class FlatWorldGeneratorOptions& operator=(class FlatWorldGeneratorOptions const&) = delete;
    FlatWorldGeneratorOptions(class FlatWorldGeneratorOptions const&) = delete;
    FlatWorldGeneratorOptions() = delete;
#endif

public:
    MCAPI ~FlatWorldGeneratorOptions();
    MCAPI static class Json::Value getLayers(enum WorldVersion);

protected:
    MCAPI bool _load(class Json::Value const&, class BlockPalette const&, class LevelData const&);

private:

};