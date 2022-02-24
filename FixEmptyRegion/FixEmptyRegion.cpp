#include "pch.h"
#include <MC/SimulatedPlayer.hpp>
#include <MC/CompoundTag.hpp>
#include <MC/Block.hpp>
#include <MC/BlockSource.hpp>
#include <Utils/DbgHelper.h>
#include <filesystem>
#include <MC/Level.hpp>

#ifdef DEBUG
template <typename T>
void logActorInfo(T* actor, std::string const& func);

#include <MC/CommandUtils.hpp>
#include <MC/ActorClassTree.hpp>
namespace
{
constexpr int maxDistance = 10;
constexpr float ha = 75.0f;
constexpr float va = 45.0f;
} // namespace
TInstanceHook(void, "?attack@Player@@UEAA_NAEAVActor@@AEBW4ActorDamageCause@@@Z",
              Player, Actor* actor, ActorDamageCause& cause)
{
#ifdef DEBUG
    logger.info("Player::startSpinAttack - {}", getNameTag());
#endif // DEBUG

    auto dimid = getDimensionId();
    auto playerRot = getRotation();
    auto playerPos = getPos();
    auto viewVector = getViewVector(1.0f);
    for (auto actor : Global<Level>->getRuntimeActorList())
    {
        if (actor == this)
            continue;
        if (!ActorClassTree::isMob(actor->getEntityTypeId()))
            continue;
        if (dimid != actor->getDimensionId())
            continue;
        if (distanceTo(*actor) > maxDistance)
            continue;
        auto posVector = actor->getPos() - playerPos;
        auto posRot = Vec3::rotationFromDirection(posVector);
#ifdef DEBUG
        LOG_VAR(playerPos.toString());
        LOG_VAR(playerRot.toString());
        LOG_VAR(posVector.toString());
        LOG_VAR(posRot.toString());
#endif // DEBUG

        if (std::fmodf(abs(posRot.x - playerRot.x), 360) < ha && std::fmodf(abs(posRot.y - playerRot.y), 360) < va)
        {
#ifdef DEBUG
            logger.warn("Player::attack - {} -> {}", getNameTag(), CommandUtils::getActorName(*actor));
#endif // DEBUG
            original(this, actor, cause);
        }
    }
}
#endif // DEBUG

void entry()
{
    filesystem::create_directories(PLUGIN_DIR);
#ifdef DEBUG
    //logActorInfo((Actor*)114514, "Test");
    logger.error("Actor::`vftable' Rva: {}", (uintptr_t)dlsym_real("??_7Actor@@6B@") - (uintptr_t)GetModuleHandle(NULL));
    PrintCurrentStackTraceback(&logger);
#endif // DEBUG
}

#include <MC/StructureTemplate.hpp>
namespace
{
bool kill = true;
}
template <typename T>
void logActorInfo(T* actor, std::string const& func)
{
    if (actor == nullptr)
    {
        return logger.error("Detected actor nullptr in {}", func);
    }
    logger.error("Detected region nullptr in {}", func);
    logger.error("Type: {}", typeid(T).name());
    try
    {
        logger.error("vftable RVA: {}", dAccess<uintptr_t, 0>(actor) - (uintptr_t)GetModuleHandle(NULL));
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
                     actor->getPos().toString(), (int)actor->getDimensionId());
        auto bpos = ((Actor*)actor)->getPos().toBlockPos();
        auto block = Level::getBlockEx(bpos, actor->getDimensionId());
        if (block)
            logger.error("Block: {} - {}", bpos.toString(), block->toDebugString());
        else
            logger.error("Block: {} - nullptr", bpos.toString());
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
                         player->getNameTag(), player->getPos().toString(), (int)player->getDimensionId());
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
    logger.error("StackTraceback:");
    PrintCurrentStackTraceback(&logger);
    logger.info << Logger::endl;
    if (kill)
    {
        try
        {
            actor->kill();
        }
        catch (...)
        {
            logger.error("Error in kill actor");
        }
    }
    return;
}

TClasslessInstanceHook(bool, "?_shouldBreakDoor@BreakDoorAnnotationComponent@@AEAA_NAEAVMob@@@Z",
                       Mob* mob)
{
    if (mob == nullptr || &mob->getRegion() == nullptr)
    {
        logActorInfo(mob, "BreakDoorAnnotationComponent::_shouldBreakDoor");
        return false;
    }
    return original(this, mob);
}

TInstanceHook(bool, "?isInWaterOrRain@Actor@@QEBA_NXZ",
              Actor)
{
    if (this == nullptr || &getRegion() == nullptr)
    {
        logActorInfo(this, "Actor::isInWaterOrRain");
        return false;
    }
    return original(this);
}

TInstanceHook(float, "?getBrightness@Actor@@UEBAMM@Z",
              Actor, float a2)
{
    if (this == nullptr || &getRegion() == nullptr)
    {
        logActorInfo(this, "Actor::getBrightness");
        return 0;
    }
    return original(this, a2);
}