#pragma once
#include <RegCommandAPI.h>
#include <PlayerInfoAPI.h>
#ifdef ENABLE_TEST_DBSTORAGE


namespace TestDBStorage
{
    bool deletePlayerData(mce::UUID uuid);
};
using namespace RegisterCommandHelper;
class RemovePlayerCommand :public Command {
    std::string mName;
    virtual void execute(class CommandOrigin const& origin, class CommandOutput& output) const override;

public:
    static std::vector<std::string> playerList;
    static void setup(CommandRegistry& registry);
    inline static void addPlayer(std::string const& name) {
        if (std::find(playerList.begin(), playerList.end(), name)==playerList.end()) {
            playerList.push_back(name);
            //Global<CommandRegistry>->("PlayerList", playerList);
        }
    };
    inline static void removePlayer(std::string const& name) {
        auto iter = std::find(playerList.begin(), playerList.end(), name);
        if (iter != playerList.end()) {
            playerList.erase(iter);
            //Global<CommandRegistry>->setSoftEnumValues("PlayerList", playerList);
        }
    };
    inline static void updatePlayerList()
    {
        playerList.clear();
        PlayerInfo::forEachInfo([](std::string_view name, std::string_view xuid, std::string_view uuid)->bool {
            RemovePlayerCommand::playerList.push_back(std::string(name));
            return true;
            });
        //Global<CommandRegistry>->setSoftEnumValues("PlayerList", playerList);j
    }
};

class DBTestCommand : public Command {
    enum class Operation {
        Read,
        ReadPrefix,
        ReadChunk,
        Remove,
        RemovePrefix,
        RemoveChunk,
    } mOperation;
    std::string mKey;
    virtual void execute(class CommandOrigin const& origin, class CommandOutput& output) const override;

public:
    static void setup(CommandRegistry& registry);
};

namespace TestDBStorage
{
void test();
}
#else
namespace TestDBStorage
{
inline void test(){};
}
#endif // ENABLE_TEST_DBSTORAGE