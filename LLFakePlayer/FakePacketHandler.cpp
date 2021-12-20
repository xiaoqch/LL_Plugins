#include "pch.h"
#include <MC/MinecraftPackets.hpp>
#include <MC/NetworkHandler.hpp>
#include <MC/NetworkPacketEventCoordinator.hpp>
#include <MC/NetworkPeer.hpp>
#include <MC/Packet.hpp>
#include <MC/ServerNetworkHandler.hpp>
#include <MC/SimulatedPlayer.hpp>
#include <ScheduleAPI.h>

#include <MC/ChangeDimensionPacket.hpp>
#include <MC/PlayerActionPacket.hpp>
#include <MC/RespawnPacket.hpp>
#include <MC/ModalFormRequestPacket.hpp>
#include <MC/ModalFormResponsePacket.hpp>
#include <MC/ShowCreditsPacket.hpp>
#include <MC/MovePlayerPacket.hpp>

auto ignorePacketId = { 39, 40, 58, 111, 121, 123, 136, 174 };
static_assert(sizeof(PlayerActionPacket) == 80);
static_assert(sizeof(RespawnPacket) == 72);
static_assert(sizeof(ChangeDimensionPacket) == 72);
static_assert(sizeof(ModalFormRequestPacket) == 88);
static_assert(sizeof(ModalFormResponsePacket) == 88);
static_assert(sizeof(MovePlayerPacket) == 112);

namespace FakeHandler {

    //Received: RespawnPacket(position=(-40.5, 68.62001, 173.5), state=SERVER_SEARCHING, runtimeEntityId=0)
    //Received: EventPacket(uniqueEntityId=-94489280503, usePlayerId=1, eventData=null)
    //Received: UpdateAttributesPacket(runtimeEntityId=1, attributes=[AttributeData(name=minecraft:health, minimum=0.0, maximum=20.0, value=0.0, defaultValue=20.0)], tick=0)
    //Received: RespawnPacket(position=(-40.5, 68.62001, 173.5), state=SERVER_SEARCHING, runtimeEntityId=0)
    //Send: RespawnPacket(position=(0.0, 0.0, 0.0), state=CLIENT_READY, runtimeEntityId=1)
    //Send: RespawnPacket(position=(0.0, 0.0, 0.0), state=CLIENT_READY, runtimeEntityId=1)
    //Received: RespawnPacket(position=(-44.0, 32767.0, 176.0), state=SERVER_SEARCHING, runtimeEntityId=0)
    //Send: PlayerActionPacket(runtimeEntityId=1, action=RESPAWN, blockPosition=(0, 0, 0), face=-1)
    //Received: RespawnPacket(position=(-41.5, 72.62001, 180.5), state=SERVER_READY, runtimeEntityId=0)
    //Received: SetHealthPacket(health=20)
    //Received: UpdateAttributesPacket(runtimeEntityId=1, attributes=[AttributeData(name=minecraft:health, minimum=0.0, maximum=20.0, value=20.0, defaultValue=20.0), AttributeData(name=minecraft:player.hunger, minimum=0.0, maximum=20.0, value=20.0, defaultValue=20.0), AttributeData(name=minecraft:player.exhaustion, minimum=0.0, maximum=4.0, value=0.0, defaultValue=0.0), AttributeData(name=minecraft:player.saturation, minimum=0.0, maximum=20.0, value=20.0, defaultValue=20.0), AttributeData(name=minecraft:player.level, minimum=0.0, maximum=24791.0, value=0.0, defaultValue=0.0), AttributeData(name=minecraft:player.experience, minimum=0.0, maximum=1.0, value=0.0, defaultValue=0.0)], tick=0)
    void handle(SimulatedPlayer* sp, RespawnPacket* packet) {
        logger.warn("FakeHandle: {}", packet->toDebugString());
        auto state = packet->respawnState;
        auto& uniqueId = sp->getUniqueID();

        auto taskid = Schedule::schedule(Schedule::delay([state, uniqueId]() {
            auto sp = Level::getPlayer(uniqueId);
            if (state == SERVER_SEARCHING)
            {
                sp->setBlockRespawnUntilClientMessage(false);
                //BlockPos bpos{ 0,0,0 };
                //RespawnPacket res({ 0,0,0 }, CLIENT_READY);
                //logger.error("Send: {}", res.toDebugString());
                //Global<ServerNetworkHandler>->handle(*sp->getNetworkIdentifier(), res);
            }
            else {
                BlockPos bpos{ 0,0,0 };
                PlayerActionPacket res(PlayerActionType::RESPAWN, bpos, -1, sp->getRuntimeID());
                Global<ServerNetworkHandler>->handle(*sp->getNetworkIdentifier(), res);
            }
            }, 10));
    }

// WebSocketÒÑÍ£Ö¹
// Received: SetTimePacket(time=2331616)
// Received: EventPacket(uniqueEntityId=-94489280503, usePlayerId=1, eventData=null)
// Received: ChangeDimensionPacket(dimension=1, position=(9.5, 66.5, 2.5), respawn=false)
//     Send: PlayerActionPacket(runtimeEntityId=14, action=DIMENSION_CHANGE_SUCCESS, blockPosition=(0, 0, 0), face=0)
// Received: AddPlayerPacket(metadata={FLAGS=EntityFlags(flags=[CAN_SHOW_NAME, CAN_CLIMB, CAN_WALK, BREATHING, HAS_COLLISION, HAS_GRAVITY, HIDDEN_WHEN_INVISIBLE]), FLAGS_2=EntityFlags(flags=[CAN_SHOW_NAME, CAN_CLIMB, CAN_WALK, BREATHING, HAS_COLLISION, HAS_GRAVITY, HIDDEN_WHEN_INVISIBLE]), HEALTH=1, VARIANT=0, COLOR=0, NAMETAG=ccc, OWNER_EID=-1, TARGET_EID=0, AIR_SUPPLY=300, EFFECT_COLOR=0, EFFECT_AMBIENT=0, JUMP_DURATION=0, CHARGE_AMOUNT=0, PLAYER_FLAGS=0, PLAYER_INDEX=1, BED_POSITION=(0, 0, 0), LEASH_HOLDER_EID=0, SCALE=1.0, HAS_NPC_COMPONENT=0, MAX_AIR_SUPPLY=300, MARK_VARIANT=0, CONTAINER_TYPE=0, CONTAINER_BASE_SIZE=0, CONTAINER_STRENGTH_MODIFIER=0, BOUNDING_BOX_WIDTH=0.6, BOUNDING_BOX_HEIGHT=1.8, RIDER_SEAT_POSITION=(0.0, 0.0, 0.0), RIDER_ROTATION_LOCKED=0, RIDER_MAX_ROTATION=0.0, RIDER_MIN_ROTATION=0, RIDER_ROTATION_OFFSET=0.0, COMMAND_BLOCK_ENABLED=0, COMMAND_BLOCK_COMMAND=, COMMAND_BLOCK_LAST_OUTPUT=, COMMAND_BLOCK_TRACK_OUTPUT=1, CONTROLLING_RIDER_SEAT_INDEX=0, STRENGTH=0, MAX_STRENGTH=0, EVOKER_SPELL_COLOR=0, LIMITED_LIFE=-1, NAMETAG_ALWAYS_SHOW=1, COLOR_2=0, SCORE_TAG=, AGENT_ID=-1, EATING_COUNTER=0, INTERACTIVE_TAG=, TRADE_TIER=0, MAX_TRADE_TIER=0, TRADE_XP=0, SKIN_ID=0, COMMAND_BLOCK_TICK_DELAY=3, COMMAND_BLOCK_EXECUTE_ON_FIRST_TICK=1, AMBIENT_SOUND_INTERVAL=8.0, AMBIENT_SOUND_INTERVAL_RANGE=16.0, AMBIENT_SOUND_EVENT_NAME=ambient, FALL_DAMAGE_MULTIPLIER=1.0, CAN_RIDE_TARGET=0, LOW_TIER_CURED_TRADE_DISCOUNT=0, HIGH_TIER_CURED_TRADE_DISCOUNT=0, NEARBY_CURED_TRADE_DISCOUNT=0, NEARBY_CURED_DISCOUNT_TIME_STAMP=0, HITBOX={}, IS_BUOYANT=0, BASE_RUNTIME_ID={}, FREEZING_EFFECT_STRENGTH=0.0}, entityLinks=[], uuid=33b61477-8e24-42ed-97e7-6f7706ac85ce, username=ccc, uniqueEntityId=-1967095021561, runtimeEntityId=12, platformChatId=, position=(9.5, 66.5, 2.5), motion=(0.0, -0.0784, 0.0), rotation=(0.0, 0.0, -23.241364), hand=ItemData(id=0, damage=0, count=0, tag=null, canPlace=[], canBreak=[], blockingTicks=0, blockRuntimeId=0, usingNetId=false, netId=0), adventureSettings=AdventureSettingsPacket(settings=[AUTO_JUMP, MINE, DOORS_AND_SWITCHES, OPEN_CONTAINERS, ATTACK_PLAYERS, ATTACK_MOBS, BUILD], commandPermission=NORMAL, playerPermission=MEMBER, uniqueEntityId=-1), deviceId=, buildPlatform=-1)
// Received: MovePlayerPacket(runtimeEntityId=14, position=(9.5, 68.12001, 2.5), rotation=(-89.0, -92.0, 0.0), mode=RESPAWN, onGround=true, ridingRuntimeEntityId=0, teleportationCause=null, entityType=0, tick=0)
// Received: UpdateAttributesPacket(runtimeEntityId=14, attributes=[AttributeData(name=minecraft:player.exhaustion, minimum=0.0, maximum=4.0, value=0.3544, defaultValue=0.0)], tick=0)
    void handle(SimulatedPlayer* sp, ChangeDimensionPacket* packet) {
        logger.warn("FakeHandle: {}", packet->toDebugString());
        auto& uniqueId = sp->getUniqueID();
        auto clientSubId = packet->clientSubId;
        auto pos = packet->position;
        PlayerActionPacket res(PlayerActionType::DIMENSION_CHANGE_SUCCESS, { 0,0,0 }, 0, sp->getRuntimeID());
        res.clientSubId = clientSubId;
        Global<ServerNetworkHandler>->handle(*sp->getNetworkIdentifier(), res);
        logger.info("isPlayerInitialized: {}", sp->isPlayerInitialized());
        auto taskid = Schedule::schedule(Schedule::delay([clientSubId, uniqueId, pos]() {
            auto sp = (SimulatedPlayer*)Level::getPlayer(uniqueId);
            MovePlayerPacket res2(*sp, pos);
            res2.clientSubId = clientSubId;
            Global<ServerNetworkHandler>->handle(*sp->getNetworkIdentifier(), res2);
            sp->simulateLocalMove(Vec3{1, 0, 1}, 1);
            if (!sp->isPlayerInitialized()) {
                logger.info("dAccess<bool>(sp, 3954)->{}", dAccess<bool>(sp, 3954));
                logger.info("dAccess<bool>(sp, 8952)->{}", dAccess<bool>(sp, 8952));
                logger.info("dAccess<int>(sp, 559*4)->{}", dAccess<int>(sp, 559 * 4));
                logger.info("dAccess<bool>(sp, 8954)->{}", dAccess<bool>(sp, 8954));
                dAccess<bool>(sp, 8952) = true;
            }
            }, 20));
    }

    void handle(SimulatedPlayer* sp, ModalFormRequestPacket* packet) {
        //logger.warn("FakeHandle: {}", packet->toDebugString());
        auto& uniqueId = sp->getUniqueID();
        auto formId = packet->formId;
        auto taskid = Schedule::schedule(Schedule::delay([uniqueId, formId]() {
            auto sp = Level::getPlayer(uniqueId);
            auto res = MinecraftPackets::createPacket(MinecraftPacketIds::ModalFormResponse);
            ((ModalFormResponsePacket*)res.get())->formId = formId;
            ((ModalFormResponsePacket*)res.get())->data = "null";
            Global<ServerNetworkHandler>->handle(*sp->getNetworkIdentifier(), *(ModalFormResponsePacket*)res.get());
            }, 20));
    }
    static_assert(offsetof(ShowCreditsPacket, state) == 56);
    void handle(SimulatedPlayer* sp, ShowCreditsPacket* packet) {
        logger.warn("FakeHandle: {}", packet->toDebugString());
        auto& uniqueId = sp->getUniqueID();
        ShowCreditsPacket res(sp->getRuntimeID(), ShowCreditsPacket::CreditsState::END_CREDITS);
        res.clientSubId = packet->clientSubId;
        Global<ServerNetworkHandler>->handle(*sp->getNetworkIdentifier(), res);
    }
    void handle(SimulatedPlayer* sp, MovePlayerPacket* packet) {
        logger.warn("FakeHandle: {}", packet->toDebugString());
        auto& uniqueId = sp->getUniqueID();
        auto taskid = Schedule::schedule(Schedule::delay([uniqueId]() {
            auto sp = Level::getPlayer(uniqueId);
            }, 20));
    }
}

TInstanceHook(void, "?_sendInternal@NetworkHandler@@AEAAXAEBVNetworkIdentifier@@AEBVPacket@@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z",
    NetworkHandler, NetworkIdentifier& nid, class Packet& pkt, std::string const& data) {
    auto pktId = (int)pkt.getId();

    switch (pktId)
    {
    case 10:
    case 13:
    case 15:
    case 19:
    case 21:
    case 27:
    case 39:
    case 40:
    case 58:
    case 111:
    case 121:
    case 123:
    case 136:
    case 172:
    case 174:
        return original(this, nid, pkt, data);
    default:
        break;
    }
    try
    {
        pkt.clientSubId = dAccess<unsigned char>(&nid, 160);
    }
    catch (const std::exception&)
    {
        logger.error("Failed to get player's client sub id");
    }
    auto pl = pkt.getPlayerFromPacket(Global<ServerNetworkHandler>, &nid);
    if (!pl) {
        return original(this, nid, pkt, data);
    }
    if (pl->isSimulatedPlayer()) {
        logger.warn("pl->getHealth(): {}", pl->getHealth());
        ActorUniqueID uniqueId = pl->getUniqueID();
        switch (pkt.getId())
        {
        case MinecraftPacketIds::MovePlayer:
            FakeHandler::handle((SimulatedPlayer*)pl, (MovePlayerPacket*)&pkt);
            break;
        case MinecraftPacketIds::ShowCredits:
            FakeHandler::handle((SimulatedPlayer*)pl, (ShowCreditsPacket*)&pkt);
            break;
        case MinecraftPacketIds::ModalFormRequest:
            //FakeHandler::handle((SimulatedPlayer*)pl, (ModalFormRequestPacket*)&pkt);
            break;
        case MinecraftPacketIds::ChangeDimension:
            FakeHandler::handle((SimulatedPlayer*)pl, (ChangeDimensionPacket*)&pkt);
            break;
        case MinecraftPacketIds::Respawn:
            FakeHandler::handle((SimulatedPlayer*)pl, (RespawnPacket*)&pkt);
            break;
        default:
            break;
        }
        logger.warn("[Send] {}({:3d}), name: {}", pkt.getName(), pkt.getId(), pl->getNameTag());
        return;// this->privateCall<NetworkHandler::Connection*>(nid);
    }
    else {
        switch (pkt.getId())
        {
        case MinecraftPacketIds::Respawn:
            logger.info("[Send]: {}", ((RespawnPacket*)&pkt)->toDebugString());
            break;
        default:
            logger.info("[Send] {}({:3d}), name: {}", pkt.getName(), pkt.getId(), pl->getNameTag());
            break;
        }
    }
    original(this, nid, pkt, data);
}

TInstanceHook(void, "?sendPacketReceivedFrom@NetworkPacketEventCoordinator@@QEAAXAEBVPacketHeader@@AEBVPacket@@@Z",
    NetworkPacketEventCoordinator, class PacketHeader const& handler, Packet& pkt) {
    auto pktId = (int)pkt.getId();

    switch (pktId)
    {
    case 123:
    case 135:
    case 144:
    case 175:
        return original(this, handler, pkt);
    default:
        break;
    }
    switch (pkt.getId())
    {
    case MinecraftPacketIds::PlayerAction:
    {
        int actionType = dAccess<int>(&pkt, 64);
        auto& bpos = dAccess<BlockPos>(&pkt, 48);
        auto& runtimeId = dAccess<__int64>(&pkt, 72);
        logger.info("[Received] id: {:3d}, name: {}, Action: {}, bpos: {}",
            pkt.getId(), pkt.getName(), actionType, bpos.toString());
    }
    break;
    case MinecraftPacketIds::Respawn:
        logger.info("[Received]: {}", ((RespawnPacket*)&pkt)->toDebugString());
        break;
    default:
        logger.info("[Received] {}({:3d}), name: ", pkt.getName(), pkt.getId());
        break;
    }

    original(this, handler, pkt);
}

TInstanceHook(SimulatedPlayer*, "??0SimulatedPlayer@@QEAA@AEAVLevel@@AEAVPacketSender@@AEAVNetworkHandler@@AEAVActiveTransfersManager@Server@ClientBlobCache@@W4GameType@@AEBVNetworkIdentifier@@EV?$function@$$A6AXAEAVServerPlayer@@@Z@std@@VUUID@mce@@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$unique_ptr@VCertificate@@U?$default_delete@VCertificate@@@std@@@std@@H_NAEBV?$OwnerPtrT@UEntityRefTraits@@@@@Z",
    SimulatedPlayer, class Level& level, class PacketSender& sender, class NetworkHandler& handler,
    class ActiveTransfersManager& blobCache, enum GameType gameType,
    class NetworkIdentifier const& nid, unsigned char subId,
    class std::function<void(class ServerPlayer&)> func, class mce::UUID uuid, std::string const& str,
    class Certificate** cert, int unk_int, bool unk_bool, class OwnerPtrT<struct EntityRefTraits> const& refPtr) {
    static unsigned char globalSubId = 0;
    logger.info("New SimulatedPlayer Detected, subId auto increase");
    auto rtn = original(this, level, sender, handler, blobCache, gameType, nid, globalSubId, func, uuid, str, cert, unk_int, unk_bool, refPtr);
    auto ueif = rtn->getUserEntityIdentifierComponent();
    if (dAccess<unsigned char>(ueif, 160) != globalSubId) {
        dAccess<unsigned char>(ueif, 160) = globalSubId;
    }
    globalSubId++;
    return rtn;
}