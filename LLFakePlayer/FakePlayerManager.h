#pragma once
#include "Config.h"
#include <MC/SimulatedPlayer.hpp>

class FakePlayerManager
{
    std::vector<std::string> mList;
    std::string mDataPath;

public:
    FakePlayerManager(std::string const& dataPath) {
        this->mDataPath = dataPath;
    }
    inline std::vector<std::string> getFakePlayerList() {
        return mList;
    }
    SimulatedPlayer* create(std::string const& name);
    bool remove(std::string const& name);
    SimulatedPlayer* login(std::string const& name);
    bool logout(std::string const& name);
    bool logout(SimulatedPlayer const& simulatedPlayer);
    bool save();
};

