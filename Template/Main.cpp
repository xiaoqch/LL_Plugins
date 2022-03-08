#include "pch.h"
#include "TemplateCommand.h"
#include <EventAPI.h>
#include <MC/ServerPlayer.hpp>
#include <MC/ServerNetworkHandler.hpp>
#include <PlayerInfoAPI.h>
void entry()
{
    Event::RegCmdEvent::subscribe(
        [](Event::RegCmdEvent ev) {
            //logger.warn("All PlayerInfo: ");
            //PlayerInfo::forEachInfo([](std::string_view name, std::string_view xuid, std::string_view uuid) {
            //    logger.warn("name: {}, xuid: {}, uuid: {}", name, xuid, uuid);
            //    return true;
            //});
            TemplateCommand::setup(*ev.mCommandRegistry);
            return true;
        });
    Event::PlayerJoinEvent::subscribe_ref(
        [](Event::PlayerJoinEvent& ev) -> bool {
            if (ev.mPlayer->getClientSubId() != 0)
            {
                auto mainPlayer = Global<ServerNetworkHandler>->getServerPlayer(*ev.mPlayer->getNetworkIdentifier());
                if (mainPlayer)
                {
                    logger.warn("Detected sub client player \"{}\" connected. main Player is \"{}\"",
                                ev.mPlayer->getName(), mainPlayer->getName());
                }
                else
                {
                    logger.warn("Detected sub client player \"{}\" connected. main Player is \"Unknown\"",
                                ev.mPlayer->getName());
                }
            }
            return true;
        });
}
