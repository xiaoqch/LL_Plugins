#include "pch.h"
#include "TemplateCommand.h"
#include <EventAPI.h>
#include <MC/ServerPlayer.hpp>
#include <MC/ServerNetworkHandler.hpp>
#include <MC/Level.hpp>
#include <PlayerInfoAPI.h>
#include <ScheduleAPI.h>

int randomInt(int min, int max)
{
    return min + rand() % (max - min + 1);
}
int count = 0;
void randomReload(int delay)
{
    logger.warn("randomReload - {}", ++count);
    Level::runcmdEx("ll reload");
    Schedule::delay(
        []() {
            randomReload(randomInt(1, 100));
        },
        delay);
}
void entry()
{
    Event::PlayerJumpEvent::subscribe_ref([](Event::PlayerJumpEvent& ev) {
        logger.info("Player::Jump");
        auto& bs = ev.mPlayer->getRegion();
        auto pos = ev.mPlayer->getBlockPosCurrentlyStandingOn(nullptr);
        TestFuncTime(Level::breakBlockNaturally, &bs, pos);
        return true;
        });
}

//TClasslessInstanceHook(void, "?startAnnouncingServer@RakNetServerLocator@@UEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@0W4GameType@@HH_N@Z",
//                       std::string const& motd, std::string const& levelName, enum GameType gameType, int playerCount, int maxPlayerCount, bool unk)
//{
//    original(this, motd, levelName, gameType, 41, 410, unk);
//}

