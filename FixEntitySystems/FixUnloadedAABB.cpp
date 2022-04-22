#include "pch.h"
#include <MC/BlockSource.hpp>
#include <MC/ServerPlayer.hpp>
#include <I18nAPI.h>

bool catchError = false;

inline void logAABB(class AABB const& aabb)
{
    try
    {
        logger.error("BlockSource::addUnloadedChunksAABBs crash! - AABB: {}, {}",
            aabb.pointA.toString(), aabb.pointB.toString());
    }
    catch (...)
    {
        logger.error("Error in log AABB");
    }
}
inline bool Interval(int a1)
{
    if (a1 < 0x5ffffff && a1 > -0x5ffffff) return true;
    return false;
}
template <typename T>
inline bool validPosition(T const& pos)
{
    return Interval(static_cast<int>(pos.x)) && Interval(static_cast<int>(pos.y)) && Interval(static_cast<int>(pos.z));
}

TInstanceHook(void, "?addUnloadedChunksAABBs@BlockSource@@IEAAXAEBVAABB@@@Z", 
    BlockSource, class AABB const& aabb)
{
    try
    {
        if (!validPosition(aabb.pointA) || !validPosition(aabb.pointB))
        {
            logger.error("Error in BlockSource::addUnloadedChunksAABBs: Invaild AABB");
            logAABB(aabb);
            catchError = true;
            return;
        }
        //logger.info("BlockSource::addUnloadedChunksAABBs");
        return original(this, aabb);
    }
    catch (const seh_exception& e)
    {
        logAABB(aabb);
        logger.error(e.what());
    }
    catch (const std::exception& e)
    {
        logAABB(aabb);
        logger.error(TextEncoding::toUTF8(e.what()));
    }
    catch (...)
    {
        logAABB(aabb);
    }
    catchError = true;
}

TInstanceHook(void, "?move@Player@@UEAAXAEBVVec3@@@Z", Player, class Vec3 const& vec)
{
    static bool inited = ([]() {
        _set_se_translator(seh_exception::TranslateSEHtoCE);
        return true;
        })();
    original(this, vec);
    if (catchError) {
        catchError = false;
        try
        {
            logger.error("BlockSource::addUnloadedChunksAABBs crash because {} try move to {}",
                         getName(), vec.toString());
            logger.error("pos: {}, posPrev: {}", getPosition().toString(), getPosPrev().toString());
            auto nbtFilePath = fmt::format("{}move-Player-{:%Y%m%d-%H%M%S}.snbt", PLUGIN_DIR, fmt::localtime(_time64(nullptr)));
            logger.error("NBT: in {}", nbtFilePath);
            auto tag = getNbt();
            WriteAllFile(nbtFilePath, tag->toBinaryNBT(), true);
        }
        catch (...)
        {
            logger.error("Error in log Crash Info");
        }
    }
}
//#include <MC/ServerNetworkHandler.hpp>
//#include <MC/InteractPacket.hpp>
//TInstanceHook(void, "?handle@ServerNetworkHandler@@UEAAXAEBVNetworkIdentifier@@AEBVInteractPacket@@@Z",
//              ServerNetworkHandler, class NetworkIdentifier const& nid, class InteractPacket const& packet)
//{
//    static ActorRuntimeID oldRuntimeId = {0ull};
//    logger.warn("Action: {}", (int)packet.mAction);
//    if (packet.mAction == (InteractPacket::Action)6) {
//        __debugbreak();
//    }
//    original(this, nid, packet);
//}
#include <MC/Level.hpp>

#ifdef DEBUG

TInstanceHook(void, "?interact@Player@@QEAA_NAEAVActor@@AEBVVec3@@@Z",
              Player, Actor& actor, Vec3 const& pos)
{
    logger.warn("interact - {:x}", (unsigned long long&)actor.getUniqueID().id);
    if (actor.getTypeName() == "minecraft:villager_v2")
    {
        Level** level = &dAccess<Level*>(&actor, 872);
        int a = 1;
    }
    original(this, actor, pos);
}
TInstanceHook(Actor&, "??0Actor@@QEAA@PEAVActorDefinitionGroup@@AEBUActorDefinitionIdentifier@@AEAVEntityContext@@@Z",
              Actor, class ActorDefinitionGroup* adg, struct ActorDefinitionIdentifier const& adi, class EntityContext& ec)
{
    static bool first = true;
    if (first) {
        first = false;
        auto level = dAccess<Level*>(this, 872);
        first = false;
    }
    return original(this, adg, adi, ec);
}

#endif // DEBUG

// ServerPlayer::openTrading crash

bool TradeError = false;
#include <MC/EconomyTradeableComponent.hpp>
TInstanceHook(class UpdateTradePacket&, "?createDataPacket@EconomyTradeableComponent@@QEAA?AVUpdateTradePacket@@W4ContainerID@@@Z",
              EconomyTradeableComponent, class UpdateTradePacket& res, enum ContainerID ctnID)
{
    auto& actor = dAccess<Actor*, 0>(this);
    if (actor && (void*)-1 == & actor->getLevel())
    {
        // return res;
        // actor->_setLevelPtr(nullptr);
        actor->_setLevelPtr(Global<Level>);
        TradeError = true;
    }
    return original(this, res, ctnID);
}

TInstanceHook(void, "?openTrading@ServerPlayer@@UEAAXAEBUActorUniqueID@@_N@Z",
              ServerPlayer, struct ActorUniqueID const& uid, bool a2)
{
    original(this, uid, a2);
    if (TradeError) {
        TradeError = false;
        try
        {
            logger.warn("Player {} trigger a openTrading error, uid: {}, a2: {}", getName(), uid.id, a2);
            auto actor = Level::getEntity(uid);
            if (actor)
            {
                logger.warn("Actor: {}, dim: {}, pos: {}", actor->getTypeName(), (int)actor->getDimensionId(), actor->getPosition().toString());
                auto nbtFilePath = fmt::format("{}openTrading-Actor-{:%Y%m%d-%H%M%S}.snbt", PLUGIN_DIR, fmt::localtime(_time64(nullptr)));
                logger.warn("NBT: in {}", nbtFilePath);
                auto tag = getNbt();
                WriteAllFile(nbtFilePath, tag->toBinaryNBT(), true);
            }
        }
        catch (...)
        {
            logger.error("Error in get openTrading detail");
        }
    }
}   



