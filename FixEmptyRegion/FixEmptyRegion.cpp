#include "pch.h"
#include <MC/SimulatedPlayer.hpp>
#include <MC/CompoundTag.hpp>

void entry()
{
#ifdef PLUGIN_DEV_MODE
    logger.error("Actor::`vftable' Rva: {}", (uintptr_t)dlsym_real("??_7Actor@@6B@") - (uintptr_t)GetModuleHandle(NULL));
#endif // PLUGIN_DEV_MODE
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
        logger.error("DebugInfo: \n", debugInfo);
    }
    catch (...)
    {
        logger.error("Error in actor->buildDebugInfo()");
    }
    try
    {
        logger.error("NBT: \n", actor->getNbt()->toSNBT());
    }
    catch (...)
    {
        logger.error("Error in actor->getNbt()->toSNBT()");
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