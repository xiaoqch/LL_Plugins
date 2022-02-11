#include "pch.h"
#include <MC/SimulatedPlayer.hpp>
#include <MC/CompoundTag.hpp>
#include <Utils/DbgHelper.h>

void entry()
{
#ifdef DEBUG
    logger.error("Actor::`vftable' Rva: {}", (uintptr_t)dlsym_real("??_7Actor@@6B@") - (uintptr_t)GetModuleHandle(NULL));
    PrintCurrentStackTraceback(&logger);
#endif // DEBUG
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
    PrintCurrentStackTraceback(&logger);
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