#include "pch.h"
#include "TemplateCommand.h"
#include <EventAPI.h>
#include <MC/ServerPlayer.hpp>
#include <MC/ServerNetworkHandler.hpp>
#include <MC/BlockSource.hpp>
#include <PlayerInfoAPI.h>
#include <ScheduleAPI.h>

void entry()
{
    std::filesystem::create_directory(PLUGIN_DIR);
    logger.fileLevel = logger.debug.level;
    logger.consoleLevel = logger.info.level;
    if (false)
        Event::RegCmdEvent::subscribe_ref([](Event::RegCmdEvent& ev) {
            TemplateCommand::setup(*ev.mCommandRegistry);
            return true;
        });
}

#include <MC/StackResultStorageEntity.hpp>
#include <MC/EntityContext.hpp>
#include <MC/Level.hpp>
#include <MC/Block.hpp>
#include <MC/StructureTemplate.hpp>


void logActorInfo(Actor* actor, std::string const& func)
{
    bool ignoreKill = false;
    if (actor == nullptr)
    {
        return logger.error("Detected actor nullptr in {}", func);
    }
    try
    {
        logger.error("vftable RVA: {}", dAccess<uintptr_t, 0>(actor) - (uintptr_t)GetModuleHandle(NULL));
        auto syms = dlsym_reverse(static_cast<int>(dAccess<uintptr_t, 0>(actor)));
        for (auto& sym : syms)
        {
            logger.error("vftable: {}", sym);
        }
    }
    catch (const std::exception&)
    {
        logger.error("Error in get actor vftable RVA");
        logger.error("Actor pointer: {:X}", (uintptr_t)actor);
    }
    try
    {
        std::string debugInfo;
        actor->buildDebugInfo(debugInfo);
        logger.error("DebugInfo: \n{}", debugInfo);
        logger.error("Pos: {}, DimId: {}",
                     actor->getPosition().toString(), (int)actor->getDimensionId());
        auto bpos = ((Actor*)actor)->getPosition().toBlockPos();
        auto block = Level::getBlockEx(bpos, actor->getDimensionId());
        if (block)
            logger.error("Block: {} - {}", bpos.toString(), block->toDebugString());
        else
            logger.error("Block: {} - nullptr", bpos.toString());
        logger.error("isRemoved: {}", actor->isRemoved());
        logger.error("isAlive: {}", actor->isAlive());
        logger.error("isGlobal: {}", actor->isGlobal());
        logger.error("isTickingEntity: {}", actor->isTickingEntity());
    }
    catch (...)
    {
        logger.error("Error in actor->buildDebugInfo()");
    }
    // NBT
    try
    {
        auto nbtFilePath = fmt::format("{}Actor-{:%Y%m%d-%H%M%S}.snbt", PLUGIN_DIR, fmt::localtime(_time64(nullptr)));
        logger.error("NBT: in {}", nbtFilePath);
        WriteAllFile(nbtFilePath, actor->getNbt()->toSNBT(4), true);
    }
    catch (...)
    {
        ignoreKill = true;
        logger.error("Error in actor->getNbt()->toSNBT()");
    }
    // Structure
    try
    {
        auto nbtFilePath = fmt::format("{}Structure-{:%Y%m%d-%H%M%S}.snbt", PLUGIN_DIR, fmt::localtime(_time64(nullptr)));
        Vec3 const& range = {16, 16, 16};
        auto structure = StructureTemplate::fromWorld("EmptyRegionStructure", ((Actor*)actor)->getDimensionId(), ((Actor*)actor)->getBlockPos() - range, ((Actor*)actor)->getBlockPos() + range, false, false);
        logger.error("Structure: in {}", nbtFilePath);
        WriteAllFile(nbtFilePath, structure.save()->toSNBT(4), true);
    }
    catch (...)
    {
        logger.error("Error in Save Structure");
    }
    try
    {
        for (auto& player : Level::getAllPlayers())
        {
            logger.error("Player: {},\t Pos: {},\t DimId: {}",
                         player->getNameTag(), player->getPosition().toString(), (int)player->getDimensionId());
            auto& region = player->getRegion();
            logger.error("Block: {} - {},\t {} - {}", player->getBlockPos().toString(),
                         region.getBlock(player->getBlockPos()).toDebugString(),
                         player->getBlockPosCurrentlyStandingOn(nullptr).toString(),
                         region.getBlock(player->getBlockPosCurrentlyStandingOn(nullptr)).toDebugString());
        }
    }
    catch (...)
    {
        logger.error("Error in log players message");
    }
    return;
}

THook(void, "?_onActorDie@MobGameEventSystem@@CAXAEAUActorDieEvent@@@Z",
      struct ActorDieEvent& ev)
{
    try
    {
        original(ev);
    }
    catch (...)
    {
        logger.error("Error in MobGameEventSystem::onActorDie");
        auto& entity = reinterpret_cast<StackResultStorageEntity&>(ev)._getStackRef();
        auto actor = Actor::tryGetFromEntity(entity, true);
        logActorInfo(actor, "MobGameEventSystem::onActorDie");
    }
}
