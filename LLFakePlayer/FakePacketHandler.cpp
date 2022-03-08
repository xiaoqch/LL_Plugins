#include "pch.h"
#include "FakePlayerManager.h"
#include <MC/Certificate.hpp>
#include <MC/ReadOnlyBinaryStream.hpp>
#include <MC/BinaryStream.hpp>
#include <MC/ChunkLoadActionList.hpp>
#include <MC/ChunkLoadedRequest.hpp>
#include <MC/ChunkSource.hpp>
#include <MC/Dimension.hpp>
#include <MC/MinecraftPackets.hpp>
#include <MC/NetworkHandler.hpp>
#include <MC/LoopbackPacketSender.hpp>
#include <MC/NetworkPacketEventCoordinator.hpp>
#include <MC/NetworkPeer.hpp>
#include <MC/ServerNetworkHandler.hpp>
#include <MC/SimulatedPlayer.hpp>
#include <ScheduleAPI.h>
#include <MC/BlockSource.hpp>
#include <MC/Dimension.hpp>
#include <MC/ChunkSource.hpp>
#include "MyPackets.h"

namespace
{
inline class Player* getPlayer(class mce::UUID const& a0)
{
    class Player* (Level::*rv)(class mce::UUID const&);
    *((void**)&rv) = dlsym("?getPlayer@Level@@UEBAPEAVPlayer@@AEBVUUID@mce@@@Z");
    return (Global<Level>->*rv)(std::forward<class mce::UUID const&>(a0));
}
}

#include <MC/VanillaDimensions.hpp>
#include <MC/NetworkIdentifier.hpp>
class UserEntityIdentifierComponent
{
public:
    NetworkIdentifier mNetworkId;
    unsigned char mClientSubId;
    mce::UUID mUUID;
    std::unique_ptr<Certificate> mCertificate;
};

struct NetworkIdentifierWithSubId
{
    NetworkIdentifier mNetworkId;
    unsigned char mSubId; // 160
    char filler161[7];

    inline ServerPlayer* getServerPlayer() const
    {
        return Global<ServerNetworkHandler>->getServerPlayer(mNetworkId, mSubId);
    }
};

namespace FakeClient
{
template <typename T>
void send(Player* sp, T& packet)
{
    packet.clientSubId = sp->getClientSubId();
    DEBUGW("FakeSend:({}): {}", sp->getNameTag(), packet.toDebugString());
    Global<ServerNetworkHandler>->handle(*sp->getNetworkIdentifier(), packet);
}

//Received: RespawnPacket(position=(-40.5, 68.62001, 173.5), state=SERVER_SEARCHING, runtimeEntityId=0)
//Received: EventPacket(uniqueEntityId=-94489280503, usePlayerId=1, eventData=null)
//Received: UpdateAttributesPacket(runtimeEntityId=1, attributes=[AttributeData(name=minecraft:health, minimum=0.0, maximum=20.0, value=0.0, defaultValue=20.0)], tick=0)
//Received: RespawnPacket(position=(-40.5, 68.62001, 173.5), state=SERVER_SEARCHING, runtimeEntityId=0)
//Received: RespawnPacket(position=(-44.0, 32767.0, 176.0), state=SERVER_SEARCHING, runtimeEntityId=0)
//Send: RespawnPacket(position=(0.0, 0.0, 0.0), state=CLIENT_READY, runtimeEntityId=1)
//Send: RespawnPacket(position=(0.0, 0.0, 0.0), state=CLIENT_READY, runtimeEntityId=1)
//Received: RespawnPacket(position=(-41.5, 72.62001, 180.5), state=SERVER_READY, runtimeEntityId=0)
//Send: PlayerActionPacket(runtimeEntityId=1, action=RESPAWN, blockPosition=(0, 0, 0), face=-1)
//Received: SetHealthPacket(health=20)
//Received: UpdateAttributesPacket(runtimeEntityId=1, attributes=[AttributeData(name=minecraft:health, minimum=0.0, maximum=20.0, value=20.0, defaultValue=20.0), AttributeData(name=minecraft:player.hunger, minimum=0.0, maximum=20.0, value=20.0, defaultValue=20.0), AttributeData(name=minecraft:player.exhaustion, minimum=0.0, maximum=4.0, value=0.0, defaultValue=0.0), AttributeData(name=minecraft:player.saturation, minimum=0.0, maximum=20.0, value=20.0, defaultValue=20.0), AttributeData(name=minecraft:player.level, minimum=0.0, maximum=24791.0, value=0.0, defaultValue=0.0), AttributeData(name=minecraft:player.experience, minimum=0.0, maximum=1.0, value=0.0, defaultValue=0.0)], tick=0)

// ================== Fix Respawn ==================
void handle(SimulatedPlayer* sp, RespawnPacket* packet)
{
    DEBUGW("FakeHandle:({}): {}", sp->getNameTag(), packet->toDebugString());
    auto state = packet->mRespawnState;
    auto& uniqueId = sp->getUniqueID();

    Schedule::delay(
        [state, uniqueId]() {
            auto sp = Level::getPlayer(uniqueId);
            if (state == SERVER_SEARCHING)
            {
                //sp->setBlockRespawnUntilClientMessage(false);
                RespawnPacket res({0, 0, 0}, CLIENT_READY);
                res.mRuntimeId = sp->getRuntimeID();

                send(sp, res);

                ASSERT(!dAccess<bool>(sp, 3748));
            }
            else
            {
                //static_assert(offsetof(PlayerActionPacket, position) == 48);
                //static_assert(offsetof(PlayerActionPacket, runtimeId) == 72);
                PlayerActionPacket res(PlayerActionType::Respawn, {0, 0, 0}, -1, sp->getRuntimeID());
                ASSERT(res.mRuntimeID.id == sp->getRuntimeID().id);
                ASSERT(res.mPosition == BlockPos::ZERO);
                ASSERT((int)res.mBlockFace == -1);
                ASSERT(res.mActionType == PlayerActionType::Respawn);

                send(sp, res);

                ASSERT(dAccess<bool>(sp, 3929));
                ASSERT(!dAccess<bool>(sp, 553 * 4));
            }
        },
        10);
}

// Received: EventPacket(uniqueEntityId=-94489280503, usePlayerId=1, eventData=null)
// Received: ChangeDimensionPacket(dimension=1, position=(9.5, 66.5, 2.5), respawn=false)
//     Send: PlayerActionPacket(runtimeEntityId=14, action=DIMENSION_CHANGE_SUCCESS, blockPosition=(0, 0, 0), face=0)
// Received: AddPlayerPacket(metadata={FLAGS=EntityFlags(flags=[CAN_SHOW_NAME, CAN_CLIMB, CAN_WALK, BREATHING, HAS_COLLISION, HAS_GRAVITY, HIDDEN_WHEN_INVISIBLE]), FLAGS_2=EntityFlags(flags=[CAN_SHOW_NAME, CAN_CLIMB, CAN_WALK, BREATHING, HAS_COLLISION, HAS_GRAVITY, HIDDEN_WHEN_INVISIBLE]), HEALTH=1, VARIANT=0, COLOR=0, NAMETAG=a, OWNER_EID=-1, TARGET_EID=0, AIR_SUPPLY=300, EFFECT_COLOR=0, EFFECT_AMBIENT=0, JUMP_DURATION=0, CHARGE_AMOUNT=0, PLAYER_FLAGS=0, PLAYER_INDEX=1, BED_POSITION=(0, 0, 0), LEASH_HOLDER_EID=0, SCALE=1.0, HAS_NPC_COMPONENT=0, MAX_AIR_SUPPLY=300, MARK_VARIANT=0, CONTAINER_TYPE=0, CONTAINER_BASE_SIZE=0, CONTAINER_STRENGTH_MODIFIER=0, BOUNDING_BOX_WIDTH=0.6, BOUNDING_BOX_HEIGHT=1.8, RIDER_SEAT_POSITION=(0.0, 0.0, 0.0), RIDER_ROTATION_LOCKED=0, RIDER_MAX_ROTATION=0.0, RIDER_MIN_ROTATION=0, RIDER_ROTATION_OFFSET=0.0, COMMAND_BLOCK_ENABLED=0, COMMAND_BLOCK_COMMAND=, COMMAND_BLOCK_LAST_OUTPUT=, COMMAND_BLOCK_TRACK_OUTPUT=1, CONTROLLING_RIDER_SEAT_INDEX=0, STRENGTH=0, MAX_STRENGTH=0, EVOKER_SPELL_COLOR=0, LIMITED_LIFE=-1, NAMETAG_ALWAYS_SHOW=1, COLOR_2=0, SCORE_TAG=, AGENT_ID=-1, EATING_COUNTER=0, INTERACTIVE_TAG=, TRADE_TIER=0, MAX_TRADE_TIER=0, TRADE_XP=0, SKIN_ID=0, COMMAND_BLOCK_TICK_DELAY=3, COMMAND_BLOCK_EXECUTE_ON_FIRST_TICK=1, AMBIENT_SOUND_INTERVAL=8.0, AMBIENT_SOUND_INTERVAL_RANGE=16.0, AMBIENT_SOUND_EVENT_NAME=ambient, FALL_DAMAGE_MULTIPLIER=1.0, CAN_RIDE_TARGET=0, LOW_TIER_CURED_TRADE_DISCOUNT=0, HIGH_TIER_CURED_TRADE_DISCOUNT=0, NEARBY_CURED_TRADE_DISCOUNT=0, NEARBY_CURED_DISCOUNT_TIME_STAMP=0, HITBOX={}, IS_BUOYANT=0, BASE_RUNTIME_ID={}, FREEZING_EFFECT_STRENGTH=0.0}, entityLinks=[], uuid=33b61477-8e24-42ed-97e7-6f7706ac85ce, username=a, uniqueEntityId=-1967095021561, runtimeEntityId=12, platformChatId=, position=(9.5, 66.5, 2.5), motion=(0.0, -0.0784, 0.0), rotation=(0.0, 0.0, -23.241364), hand=ItemData(id=0, damage=0, count=0, tag=null, canPlace=[], canBreak=[], blockingTicks=0, blockRuntimeId=0, usingNetId=false, netId=0), adventureSettings=AdventureSettingsPacket(settings=[AUTO_JUMP, MINE, DOORS_AND_SWITCHES, OPEN_CONTAINERS, ATTACK_PLAYERS, ATTACK_MOBS, BUILD], commandPermission=NORMAL, playerPermission=MEMBER, uniqueEntityId=-1), deviceId=, buildPlatform=-1)
// Received: MovePlayerPacket(runtimeEntityId=14, position=(9.5, 68.12001, 2.5), rotation=(-89.0, -92.0, 0.0), mode=RESPAWN, onGround=true, ridingRuntimeEntityId=0, teleportationCause=null, entityType=0, tick=0)
// Received: UpdateAttributesPacket(runtimeEntityId=14, attributes=[AttributeData(name=minecraft:player.exhaustion, minimum=0.0, maximum=4.0, value=0.3544, defaultValue=0.0)], tick=0)

// ================== Fix Change Dimension ==================
void handle(SimulatedPlayer* sp, ChangeDimensionPacket* packet)
{
    DEBUGW("FakeHandle:({}): {}", sp->getNameTag(), packet->toDebugString());
    auto& uniqueId = sp->getUniqueID();
    auto pos = packet->mPosition;

    PlayerActionPacket res(PlayerActionType::DimensionChangeDone, {0, 0, 0}, 0, sp->getRuntimeID());
    ASSERT(res.mActionType == PlayerActionType::DimensionChangeDone);
    ASSERT(res.mPosition == (BlockPos{0, 0, 0}));
    ASSERT(res.mRuntimeID == sp->getRuntimeID());
    send(sp, res);
}

void handle(SimulatedPlayer* sp, PlayStatusPacket* packet)
{
    DEBUGW("FakeHandle:({}): {}", sp->getNameTag(), packet->toDebugString());
    auto status = packet->status;
    // ================== Fix Change Dimension ==================
    // ChunkRadius should be greater than or equal to 7 to ensure that there are enough chunks (5*5) to change dimension
    sp->setChunkRadius(9);

    // ================== Fix Region ==================
    //if (!&sp->getDimension() || sp->getDimensionId() != sp->getDimension().getDimensionId()) {
    //    sp->suspendRegion();
    //    sp->_fireWillChangeDimension();
    //    sp->destroyRegion();
    //    auto dim = Global<Level>->createDimension(sp->getDimensionId()); // get or create dimension
    //    sp->prepareRegion(dim->getChunkSource());
    //    sp->_fireDimensionChanged();
    //}
}

void handle(SimulatedPlayer* sp, ShowCreditsPacket* packet)
{
    DEBUGW("FakeHandle({}): {}", sp->getNameTag(), packet->toDebugString());
    auto& uniqueId = sp->getUniqueID();

    Schedule::delay([sp]() {
        // TODO: uniqueId 失效
        //auto sp = (SimulatedPlayer*)Global<Level>->fetchEntity(uniqueId, true);
        ASSERT(sp->isSimulatedPlayer());
        ShowCreditsPacket res(sp->getRuntimeID(), ShowCreditsPacket::CreditsState::END_CREDITS);
        assert(res.mRuntimeId == sp->getRuntimeID());
        ASSERT(res.mState == ShowCreditsPacket::CreditsState::END_CREDITS);
        send(sp, res);
    },
                    10);
}

void handle(SimulatedPlayer* sp, ModalFormRequestPacket* packet)
{
    //DEBUGW("FakeHandle:({}): {}", sp->getNameTag(),  packet->toDebugString());
    auto& uniqueId = sp->getUniqueID();
    auto formId = packet->mFormId;
    Schedule::delay(
        [uniqueId, formId]() {
        auto sp = Level::getPlayer(uniqueId);
        auto res = MinecraftPackets::createPacket(MinecraftPacketIds::ModalFormResponse);
        ((ModalFormResponsePacket*)res.get())->mFormId = formId;
        ((ModalFormResponsePacket*)res.get())->mData = "null";
        res->clientSubId = sp->getClientSubId();
        Global<ServerNetworkHandler>->handle(*sp->getNetworkIdentifier(), *(ModalFormResponsePacket*)res.get());
    },
                    20);
}

void handle(SimulatedPlayer* sp, MovePlayerPacket* packet)
{
    //DEBUGW("FakeHandle({}): {}", sp->getNameTag(), packet->toDebugString());
    //auto& uniqueId = sp->getUniqueID();
    //auto taskid = Schedule::delay([uniqueId]() {
    //    auto sp = Level::getPlayer(uniqueId);
    //    }, 20).getTaskId();
}

void handlePacket(SimulatedPlayer* sp, Packet* packet)
{
    switch (packet->getId())
    {
        case MinecraftPacketIds::ShowCredits:
            FakeClient::handle((SimulatedPlayer*)sp, (ShowCreditsPacket*)packet);
            break;
        case MinecraftPacketIds::ChangeDimension:
            FakeClient::handle((SimulatedPlayer*)sp, (ChangeDimensionPacket*)packet);
            break;
        case MinecraftPacketIds::Respawn:
            FakeClient::handle((SimulatedPlayer*)sp, (RespawnPacket*)packet);
            break;
        //case MinecraftPacketIds::StartGame:
        //    // Not be sent to simulated player, so listen to PlayStatusPacket instead
        //    FakeClient::handle((SimulatedPlayer*)sp, (StartGamePacket*)&packet);
        //    break;
        case MinecraftPacketIds::PlayStatus:
            FakeClient::handle((SimulatedPlayer*)sp, (PlayStatusPacket*)packet);
            break;
        case MinecraftPacketIds::MovePlayer:
            FakeClient::handle((SimulatedPlayer*)sp, (MovePlayerPacket*)packet);
            break;
        case MinecraftPacketIds::ModalFormRequest:
            FakeClient::handle((SimulatedPlayer*)sp, (ModalFormRequestPacket*)packet);
            break;
#ifndef DEBUG
        case MinecraftPacketIds::MoveActorDelta:
        case MinecraftPacketIds::LevelChunk:
        case MinecraftPacketIds::LevelSoundEvent:
        case MinecraftPacketIds::SetActorData:
        case MinecraftPacketIds::LevelEventGeneric:
        //case MinecraftPacketIds::SetActorMotion:
        case (MinecraftPacketIds)40:
        //case MinecraftPacketIds::MovePlayer:
        case MinecraftPacketIds::ClientCacheMissResponse:
        case MinecraftPacketIds::SubChunk:
        case MinecraftPacketIds::UpdateAttributes:
        case MinecraftPacketIds::NetworkChunkPublisherUpdate:
        case MinecraftPacketIds::MapInfoRequest:
        case MinecraftPacketIds::AddActor:
        case MinecraftPacketIds::ActorEvent:
        case MinecraftPacketIds::AddItemActor:
        case MinecraftPacketIds::UpdateBlock:
        case MinecraftPacketIds::SetHealth:
        case MinecraftPacketIds::InventoryContent:
        case MinecraftPacketIds::Event:
        case MinecraftPacketIds::InventoryTransaction:
            break;
        //case MinecraftPacketIds::UpdateAttributes:
            {
                BinaryStream bs;
                packet->write(bs);
                logger.warn("getUnreadLength: {}", bs.getUnreadLength());
                logger.warn("getReadPointer: {}", bs.getReadPointer());
                bs.setReadPointer(0);
                logger.warn("Actor Runtime Id: {} - {}", bs.getUnsignedVarInt64(), sp->getRuntimeID().id);
                int count = bs.getUnsignedVarInt();
                logger.warn("count {}", count);
                if (count > 100)
                    count = 100;
                for (int i = 0; i < count; ++i)
                {
                    logger.warn("[{}, {}, {}, {}, {}]",
                        bs.getString(), bs.getFloat(), bs.getFloat(), bs.getFloat(), bs.getFloat());
                }
                logger.warn("tick: {}", bs.getUnsignedVarInt64());
                logger.warn("getUnreadLength: {}", bs.getUnreadLength());
                logger.warn("getReadPointer: {}", bs.getReadPointer());
                break;
            }
        case MinecraftPacketIds::PlayerList:
        {
            int a = 1;
        }
        default:
            DEBUGW("[Send] ->  {}: {}({}) {}", sp->getNameTag(), packet->getName(), packet->getId(), packet->clientSubId);
#else
        default:
#endif // DEBUG
            break;
    }
}
} // namespace FakeClient

// clientSubId is necessary to identify SimulatedPlayer because they have the same networkID
TInstanceHook(void, "?send@NetworkHandler@@QEAAXAEBVNetworkIdentifier@@AEBVPacket@@E@Z",
              NetworkHandler, NetworkIdentifier const& networkID, Packet const& packet, unsigned char clientSubID)
{
    if (networkID == FakePlayer::mNetworkID)
    {
        try
        {
            auto sp = Global<ServerNetworkHandler>->getServerPlayer(networkID, clientSubID);
            if (sp && sp->isSimulatedPlayer())
                return FakeClient::handlePacket((SimulatedPlayer*)sp, const_cast<Packet*>(&packet));
        }
        catch (const std::exception&)
        {
            logger.error("Error in NetworkHandler::send");
        }
    }
    return original(this, networkID, packet, clientSubID);
}
bool processed = false;
TInstanceHook(void, "?sendToClients@LoopbackPacketSender@@UEAAXAEBV?$vector@UNetworkIdentifierWithSubId@@V?$allocator@UNetworkIdentifierWithSubId@@@std@@@std@@AEBVPacket@@@Z",
              LoopbackPacketSender, std::vector<NetworkIdentifierWithSubId> const& clients, class Packet& packet)
{
    // fix simulated player sub id
//#ifdef DEBUG
//    logger.info("[sendToClients] -> {} clients: {}({})", clients.size(), packet.getName(), packet.getId());
//#endif // DEBUG
    
    for (auto const& client : clients) {
        if (client.mNetworkId.isUnassigned()&& client.mNetworkId == FakePlayer::mNetworkID)
        {
            try
            {
                auto sp = client.getServerPlayer();
                if (sp && sp->isSimulatedPlayer())
                {
                    FakeClient::handlePacket((SimulatedPlayer*)sp, &packet);
                }
            }
            catch (const std::exception&)
            {
                logger.error("Failed to get player's client sub id from NetworkIdentifier");
            }
        }
    }
    processed = true;
    original(this, clients, packet);
    processed = false;
}


TInstanceHook(void, "?_sendInternal@NetworkHandler@@AEAAXAEBVNetworkIdentifier@@AEBVPacket@@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z",
              NetworkHandler, NetworkIdentifier& nid, class Packet& pkt, std::string const& data)
{
    // fix simulated player sub id
    if (!processed && nid == FakePlayer::mNetworkID)
    {
        //ASSERT(false);
        try
        {
            auto subId = dAccess<unsigned char>(&nid, 160);
            auto sp = Global<ServerNetworkHandler>->getServerPlayer(nid, subId);
            if (!sp || !sp->isSimulatedPlayer())
            {
                DEBUGW("try fix sub id failed - {}", pkt.getName());
                sp = Global<ServerNetworkHandler>->getServerPlayer(nid, pkt.clientSubId);
            }
            if (sp && sp->isSimulatedPlayer())
            {
                return FakeClient::handlePacket((SimulatedPlayer*)sp, &pkt);
            }
        }
        catch (const std::exception&)
        {
            logger.error("Failed to get player's client sub id from NetworkIdentifier");
        }
    }

    original(this, nid, pkt, data);
}

// ================= Fix SimulatedPlayer =================

//fix _updateChunkPublisherView
// _updateChunkPublisherView will be called after Player::tick in ServerPlayer::tick
TInstanceHook(void, "?tickWorld@Player@@UEAAXAEBUTick@@@Z",
              Player, struct Tick const& tick)
{
    original(this, tick);

    if (this && *(void**)this == dlsym_static("??_7SimulatedPlayer@@6B@"))
    {
        // Force to call the implementation of ServerPlayer
        SymCallStatic("?_updateChunkPublisherView@ServerPlayer@@MEAAXAEBVVec3@@M@Z",
                      void, ServerPlayer*, Vec3 const&, float)((ServerPlayer*)this, getPos(), 16.0f);
    }
}

// fix ChunkSource load mode
TInstanceHook(std::shared_ptr<class ChunkViewSource>&, "?_createChunkSource@SimulatedPlayer@@MEAA?AV?$shared_ptr@VChunkViewSource@@@std@@AEAVChunkSource@@@Z",
              SimulatedPlayer, std::shared_ptr<class ChunkViewSource>& res, class ChunkSource& chunkSource)
{
    //auto& csPtr = original(this, res, chunkSource);
    //// ChunkSource::LoadMode : None(0) -> Deferred(1)
    //dAccess<int>(csPtr.get(), 56) = 1;
    //return csPtr;
    return SymCallStatic("?_createChunkSource@Player@@MEAA?AV?$shared_ptr@VChunkViewSource@@@std@@AEAVChunkSource@@@Z",
                         std::shared_ptr<class ChunkViewSource>&, SimulatedPlayer const&, std::shared_ptr<class ChunkViewSource>&, class ChunkSource&)(*this, res, chunkSource);
}

// fix item change


#ifdef DEBUG

// ================= Test =================

// Player offset:
//?3945  bool mIsInitialSpawnDone
// 2240  bool mServerHasMovementAuthority
// 553*4 int  mDimensionState - ServerPlayer::isPlayerInitialized
// 3929  bool mRespawnReady - ServerPlayer::isPlayerInitialized
// 8936  bool mLoading - ServerPlayer::isPlayerInitialized
// 8938  bool mLocalPlayerInitialized - ServerPlayer::setLocalPlayerAsInitialized
// 8488  NetworkChunkPublisher

std::string getPlayerStateString(Player* player)
{
    std::string str = "\r";
    str += fmt::format("\nposition: {}({})", VanillaDimensions::toString(player->getDimensionId()), player->getPos().toString());
    str += fmt::format("\nmIsInitialSpawnDone: {}", dAccess<bool>(player, 3945));
    str += fmt::format("\nmServerHasMovementAuthority: {}", dAccess<bool>(player, 2240));
    str += fmt::format("\nmDimensionState: {}", dAccess<int>(player, 559 * 4));
    str += fmt::format("\nmRespawnReady: {}", dAccess<bool>(player, 3904));
    str += fmt::format("\nmLoading: {}", dAccess<bool>(player, 8952));
    str += fmt::format("\nmLocalPlayerInitialized: {}", dAccess<bool>(player, 8954));
    return str;
}
struct voids
{
    void**** filler[1000];
};
TInstanceHook(ServerPlayer*, "??0ServerPlayer@@QEAA@AEAVLevel@@AEAVPacketSender@@AEAVNetworkHandler@@AEAVActiveTransfersManager@Server@ClientBlobCache@@W4GameType@@AEBVNetworkIdentifier@@EV?$function@$$A6AXAEAVServerPlayer@@@Z@std@@VUUID@mce@@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$unique_ptr@VCertificate@@U?$default_delete@VCertificate@@@std@@@std@@H_NAEAVEntityContext@@@Z",
              ServerPlayer, class Level& level, class PacketSender& sender, class NetworkHandler& handler,
              class ActiveTransfersManager& blobCache, enum GameType gameType,
              class NetworkIdentifier const& nid, unsigned char subId,
              class std::function<void(class ServerPlayer&)> onPlayerLoadedCallback, class mce::UUID uuid, std::string const& clientId,
              class std::unique_ptr<Certificate> cert, int unk_int, bool unk_bool, class EntityContext& entity)
{
    DEBUGL("ServerPlayer(level, sender, handler, blobCache, gameType = {}, nid, subId = {}, func, uuid = {}, clientId = {}, cert, unk_int = {}, unk_bool = {}, entity)",
           (int)gameType, (int)subId, uuid.asString(), clientId, unk_int, unk_bool);
    auto rtn = original(this, level, sender, handler, blobCache, gameType, nid, subId, onPlayerLoadedCallback, uuid, clientId, std::move(cert), unk_int, unk_bool, entity);
    return rtn;
}

class ChangeDimensionRequest
{
public:
    int mState;
    AutomaticID<Dimension, int> mFromDimensionId;
    AutomaticID<Dimension, int> mToDimensionId;
    Vec3 mPosition;
    bool mUsePortal;
    bool mRespawn;
    std::unique_ptr<CompoundTag> mAgentTag;
    std::string toDebugString()
    {
        return fmt::format("state: {}, dim: {}->{}, position: ({}), usePortal: {}, respawn: {}",
                           mState, (int)mFromDimensionId, (int)mToDimensionId, mPosition.toString(), mUsePortal, mRespawn);
    }
};

inline class ChunkSource& getChunkSource(BlockSource& bs)
{
    class ChunkSource& (BlockSource::*rv)();
    *((void**)&rv) = dlsym("?getChunkSource@BlockSource@@UEAAAEAVChunkSource@@XZ");
    return (bs.*rv)();
}
static bool Listen_hasChunksAt = false;
static_assert(offsetof(ChangeDimensionRequest, mRespawn) == 25);
TInstanceHook(bool, "?_playerChangeDimension@Level@@AEAA_NPEAVPlayer@@AEAVChangeDimensionRequest@@@Z",
              Level, Player* player, class ChangeDimensionRequest& request)
{
    auto rtn = original(this, player, request);
    if (!player)
        return rtn;
    auto bpos = player->getBlockPos();
    int distance = 32 * 2; // IDA Level::_playerChangeDimension line 339 before return
    auto max_cx = (bpos.x + distance) >> 4;
    auto min_cx = (bpos.x - distance) >> 4;
    auto max_cz = (bpos.z + distance) >> 4;
    auto min_cz = (bpos.z - distance) >> 4;
    auto chunksCount = 0;
    auto needChunksCount = (max_cx - min_cx + 1) * (max_cz - min_cz + 1);

    string loadInfo = "";
    auto& region = player->getRegion();
    auto& cs = getChunkSource(region);
    //auto& cs = region.getChunkSource();

    for (auto cx = min_cx; cx <= max_cx; ++cx)
    {
        loadInfo += "\n";
        for (auto cz = min_cz; cz <= max_cz; ++cz)
        {
            auto chunk = region.getChunk({cx, cz});
            loadInfo += chunk ? "1" : "0";
            if (chunk)
                ++chunksCount;
            else
            {
                //auto dimension = (Dimension*)&region.getDimensionConst();
                //auto actionList = dimension->getChunkLoadActionList().get();
                //actionList->addChunkLoadedRequest();
                cs.getOrLoadChunk({cx, cz}, (ChunkSource::LoadMode)1, true);
            }
        }
    }
    DEBUGL("cx range:[{}:{}], cz range:[{}:{}], Info: {}", min_cx, max_cx, min_cz, max_cz, loadInfo);
    DEBUGL("Loaded Chunk: needs: {}, loaded:{} ", needChunksCount, chunksCount);
    return rtn;
}

TInstanceHook(void, "?requestPlayerChangeDimension@Level@@UEAAXAEAVPlayer@@V?$unique_ptr@VChangeDimensionRequest@@U?$default_delete@VChangeDimensionRequest@@@std@@@std@@@Z",
              Level, Player& player, std::unique_ptr<ChangeDimensionRequest> requestPtr)
{
    DEBUGL("Level::requestPlayerChangeDimension({}, requestPtr)", player.getNameTag());
    DEBUGL("Request: {}", requestPtr->toDebugString());
    DEBUGL(getPlayerStateString(&player));
    return original(this, player, std::move(requestPtr));
}


//fix load chunk
TInstanceHook(void, "?prepareRegion@ServerPlayer@@UEAAXAEAVChunkSource@@@Z",
              ServerPlayer, class ChunkSource& cs)
{
    //if (isSimulatedPlayer() && (!&getDimension())) {
    //    auto dim = Global<Level>->createDimension(truthDimensionId);
    //    if (dim)
    //        return original(this, dim->getChunkSource());
    //}
    DEBUGL("ServerPlayer({})::prepareRegion(ChunkSource(dimid: {}))", this->getNameTag(), (int)cs.getDimension().getDimensionId());

    original(this, cs);
}


TInstanceHook(void, "?destroyRegion@ServerPlayer@@UEAAXXZ",
              ServerPlayer)
{
    DEBUGL("ServerPlayer({})::destroyRegion()", this->getNameTag());
    return original(this);
}

TInstanceHook(void, "?resendAllChunks@ServerPlayer@@UEAAXXZ",
              ServerPlayer)
{
    DEBUGL("ServerPlayer({})::resendAllChunks()", this->getNameTag());
    return original(this);
}

TInstanceHook(void, "?_fireDimensionChanged@Player@@UEAAXXZ",
              ServerPlayer)
{
    DEBUGL("ServerPlayer({})::_fireDimensionChanged()", this->getNameTag());
    return original(this);
}

TInstanceHook(void, "?suspendRegion@ServerPlayer@@UEAAXXZ",
              ServerPlayer)
{
    DEBUGL("ServerPlayer({})::suspendRegion()", this->getNameTag());
    return original(this);
}

TInstanceHook(void, "?_fireWillChangeDimension@Player@@UEAAXXZ",
              ServerPlayer)
{
    DEBUGL("Player({})::_fireWillChangeDimension()", this->getNameTag());
    return original(this);
}

TInstanceHook(void, "?_updateChunkPublisherView@ServerPlayer@@MEAAXAEBVVec3@@M@Z",
              ServerPlayer, Vec3 const& pos, float unkf)
{
    static __int64 logTick = 0;
    //if (++logTick % 20 == 0)
    //    DEBUGL("Player({})::_updateChunkPublisherView(({}), {})", this->getNameTag(), pos.toString(), unkf);
    return original(this, pos, unkf);
}

TInstanceHook(__int64, "?_getSpawnChunkLimit@ServerPlayer@@MEBAHXZ",
              ServerPlayer)
{
    static __int64 logTick = 0;
    auto rtn = original(this);
    if (++logTick % 20 == 0)
        DEBUGL("ServerPlayer({})::_getSpawnChunkLimit() -> {}", this->getNameTag(), rtn);
    return rtn;
}

TInstanceHook(__int64, "?respawn@Player@@UEAAXXZ",
              ServerPlayer)
{
    DEBUGL("Player({})::respawn()", this->getNameTag());
    auto rtn = original(this);
    return rtn;
}

#endif // DEBUG
