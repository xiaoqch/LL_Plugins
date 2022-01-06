#include "pch.h"
#include <MC/ChunkLoadActionList.hpp>
#include <MC/ChunkLoadedRequest.hpp>
#include <MC/ChunkSource.hpp>
#include <MC/Dimension.hpp>
#include <MC/MinecraftPackets.hpp>
#include <MC/NetworkHandler.hpp>
#include <MC/NetworkPacketEventCoordinator.hpp>
#include <MC/NetworkPeer.hpp>
#include <MC/ServerNetworkHandler.hpp>
#include <MC/SimulatedPlayer.hpp>
#include <ScheduleAPI.h>
#include <MC/BlockSource.hpp>
#include <MC/Dimension.hpp>
#include <MC/ChunkSource.hpp>

#include <MC/ChangeDimensionPacket.hpp>
#include <MC/ChunkRadiusUpdatedPacket.hpp>
#include <MC/CraftingEventPacket.hpp>
#include <MC/EventPacket.hpp>
#include <MC/ItemStackRequestPacket.hpp>
#include <MC/ModalFormRequestPacket.hpp>
#include <MC/ModalFormResponsePacket.hpp>
#include <MC/MovePlayerPacket.hpp>
#include <MC/Packet.hpp>
#include <MC/PlayerActionPacket.hpp>
#include <MC/PlayStatusPacket.hpp>
#include <MC/RespawnPacket.hpp>
#include <MC/ShowCreditsPacket.hpp>
#include <MC/StartGamePacket.hpp>
//static_assert(sizeof(ItemStackRequestPacket) == 56);
auto ignorePacketId = { 39, 40, 58, 111, 121, 123, 136, 174 };
static_assert(offsetof(EventPacket, data.type) == 56);
static_assert(offsetof(ShowCreditsPacket, state) == 56);
static_assert(sizeof(ChangeDimensionPacket) == 72);
static_assert(sizeof(CraftingEventPacket) == 120);
static_assert(sizeof(EventPacket) == 0x140);
static_assert(sizeof(ModalFormRequestPacket) == 88);
static_assert(sizeof(ModalFormResponsePacket) == 88);
static_assert(sizeof(MovePlayerPacket) == 112);
static_assert(sizeof(PlayerActionPacket) == 80);
static_assert(sizeof(PlayStatusPacket) == 56);
static_assert(sizeof(RespawnPacket) == 72);

// Player offset:
//?3945  bool mIsInitialSpawnDone
// 2240  bool mServerHasMovementAuthority
// 559*4 int  mDimensionState
// 3904  bool mRespawnReady
// 8952  bool mLoading
// 8954  bool mLocalPlayerInitialized
// 8488  NetworkChunkPublisher 

#include <MC/VanillaDimensions.hpp>

namespace FakeHandler {
    template <typename T>
    void fakeSendPacket(Player* sp, T& packet) {
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
    void handle(SimulatedPlayer* sp, RespawnPacket* packet) {
        DEBUGW("FakeHandle:({}): {}", sp->getNameTag(), packet->toDebugString());
        auto state = packet->respawnState;
        auto& uniqueId = sp->getUniqueID();
        
        Schedule::delay([state, uniqueId]() {
            auto sp = Level::getPlayer(uniqueId);
            if (state == SERVER_SEARCHING)
            {
                //sp->setBlockRespawnUntilClientMessage(false);
                RespawnPacket res({ 0,0,0 }, CLIENT_READY);
                res.runtimeId = sp->getRuntimeID();

                fakeSendPacket(sp, res);

                ASSERT(!dAccess<bool>(sp, 3748));
            }
            else {
                //static_assert(offsetof(PlayerActionPacket, position) == 48);
                //static_assert(offsetof(PlayerActionPacket, runtimeId) == 72);
                PlayerActionPacket res(PlayerActionType::RESPAWN, { 0,0,0 }, -1, sp->getRuntimeID());
                ASSERT(res.runtimeId.id == sp->getRuntimeID().id);

                fakeSendPacket(sp, res);

                ASSERT(!dAccess<bool>(sp, 3904));
                ASSERT(!dAccess<bool>(sp, 2105));
            }
            }, 10);
    }

    // Received: EventPacket(uniqueEntityId=-94489280503, usePlayerId=1, eventData=null)
    // Received: ChangeDimensionPacket(dimension=1, position=(9.5, 66.5, 2.5), respawn=false)
    //     Send: PlayerActionPacket(runtimeEntityId=14, action=DIMENSION_CHANGE_SUCCESS, blockPosition=(0, 0, 0), face=0)
    // Received: AddPlayerPacket(metadata={FLAGS=EntityFlags(flags=[CAN_SHOW_NAME, CAN_CLIMB, CAN_WALK, BREATHING, HAS_COLLISION, HAS_GRAVITY, HIDDEN_WHEN_INVISIBLE]), FLAGS_2=EntityFlags(flags=[CAN_SHOW_NAME, CAN_CLIMB, CAN_WALK, BREATHING, HAS_COLLISION, HAS_GRAVITY, HIDDEN_WHEN_INVISIBLE]), HEALTH=1, VARIANT=0, COLOR=0, NAMETAG=a, OWNER_EID=-1, TARGET_EID=0, AIR_SUPPLY=300, EFFECT_COLOR=0, EFFECT_AMBIENT=0, JUMP_DURATION=0, CHARGE_AMOUNT=0, PLAYER_FLAGS=0, PLAYER_INDEX=1, BED_POSITION=(0, 0, 0), LEASH_HOLDER_EID=0, SCALE=1.0, HAS_NPC_COMPONENT=0, MAX_AIR_SUPPLY=300, MARK_VARIANT=0, CONTAINER_TYPE=0, CONTAINER_BASE_SIZE=0, CONTAINER_STRENGTH_MODIFIER=0, BOUNDING_BOX_WIDTH=0.6, BOUNDING_BOX_HEIGHT=1.8, RIDER_SEAT_POSITION=(0.0, 0.0, 0.0), RIDER_ROTATION_LOCKED=0, RIDER_MAX_ROTATION=0.0, RIDER_MIN_ROTATION=0, RIDER_ROTATION_OFFSET=0.0, COMMAND_BLOCK_ENABLED=0, COMMAND_BLOCK_COMMAND=, COMMAND_BLOCK_LAST_OUTPUT=, COMMAND_BLOCK_TRACK_OUTPUT=1, CONTROLLING_RIDER_SEAT_INDEX=0, STRENGTH=0, MAX_STRENGTH=0, EVOKER_SPELL_COLOR=0, LIMITED_LIFE=-1, NAMETAG_ALWAYS_SHOW=1, COLOR_2=0, SCORE_TAG=, AGENT_ID=-1, EATING_COUNTER=0, INTERACTIVE_TAG=, TRADE_TIER=0, MAX_TRADE_TIER=0, TRADE_XP=0, SKIN_ID=0, COMMAND_BLOCK_TICK_DELAY=3, COMMAND_BLOCK_EXECUTE_ON_FIRST_TICK=1, AMBIENT_SOUND_INTERVAL=8.0, AMBIENT_SOUND_INTERVAL_RANGE=16.0, AMBIENT_SOUND_EVENT_NAME=ambient, FALL_DAMAGE_MULTIPLIER=1.0, CAN_RIDE_TARGET=0, LOW_TIER_CURED_TRADE_DISCOUNT=0, HIGH_TIER_CURED_TRADE_DISCOUNT=0, NEARBY_CURED_TRADE_DISCOUNT=0, NEARBY_CURED_DISCOUNT_TIME_STAMP=0, HITBOX={}, IS_BUOYANT=0, BASE_RUNTIME_ID={}, FREEZING_EFFECT_STRENGTH=0.0}, entityLinks=[], uuid=33b61477-8e24-42ed-97e7-6f7706ac85ce, username=a, uniqueEntityId=-1967095021561, runtimeEntityId=12, platformChatId=, position=(9.5, 66.5, 2.5), motion=(0.0, -0.0784, 0.0), rotation=(0.0, 0.0, -23.241364), hand=ItemData(id=0, damage=0, count=0, tag=null, canPlace=[], canBreak=[], blockingTicks=0, blockRuntimeId=0, usingNetId=false, netId=0), adventureSettings=AdventureSettingsPacket(settings=[AUTO_JUMP, MINE, DOORS_AND_SWITCHES, OPEN_CONTAINERS, ATTACK_PLAYERS, ATTACK_MOBS, BUILD], commandPermission=NORMAL, playerPermission=MEMBER, uniqueEntityId=-1), deviceId=, buildPlatform=-1)
    // Received: MovePlayerPacket(runtimeEntityId=14, position=(9.5, 68.12001, 2.5), rotation=(-89.0, -92.0, 0.0), mode=RESPAWN, onGround=true, ridingRuntimeEntityId=0, teleportationCause=null, entityType=0, tick=0)
    // Received: UpdateAttributesPacket(runtimeEntityId=14, attributes=[AttributeData(name=minecraft:player.exhaustion, minimum=0.0, maximum=4.0, value=0.3544, defaultValue=0.0)], tick=0)
    void handle(SimulatedPlayer* sp, ChangeDimensionPacket* packet) {
        DEBUGW("FakeHandle:({}): {}", sp->getNameTag(), packet->toDebugString());
        auto& uniqueId = sp->getUniqueID();
        auto pos = packet->position;

        PlayerActionPacket res(PlayerActionType::DIMENSION_CHANGE_SUCCESS, { 0,0,0 }, 0, sp->getRuntimeID());
        ASSERT(res.actionType == PlayerActionType::DIMENSION_CHANGE_SUCCESS);
        ASSERT(res.position == (BlockPos{ 0, 0, 0 }));
        ASSERT(res.runtimeId == sp->getRuntimeID());
        fakeSendPacket(sp, res);

    }

    void handle(SimulatedPlayer* sp, PlayStatusPacket* packet) {
        DEBUGW("FakeHandle:({}): {}", sp->getNameTag(), packet->toDebugString());
        auto status = packet->status;
        // ChunkRadius should be greater than or equal to 7 to ensure that there are enough chunks (5*5) to change dimension
        sp->setChunkRadius(9);
        // fix region
        if (!&sp->getDimension() || sp->getDimensionId() != sp->getDimension().getDimensionId()) {
            sp->suspendRegion();
            sp->_fireWillChangeDimension();
            sp->destroyRegion();
            auto dim = Global<Level>->createDimension(sp->getDimensionId()); // get or create dimension
            sp->prepareRegion(dim->getChunkSource());
            sp->_fireDimensionChanged();
        }
    }

    void handle(SimulatedPlayer* sp, ShowCreditsPacket* packet) {
        DEBUGW("FakeHandle({}): {}", sp->getNameTag(), packet->toDebugString());
        auto& uniqueId = sp->getUniqueID();

        Schedule::delay([sp]() {
            // TODO: uniqueId 失效
            //auto sp = (SimulatedPlayer*)Global<Level>->fetchEntity(uniqueId, true);
            ASSERT(sp->isSimulatedPlayer());
            ShowCreditsPacket res(sp->getRuntimeID(), ShowCreditsPacket::CreditsState::END_CREDITS);
            ASSERT(res.runtimeId == sp->getRuntimeID());
            ASSERT(res.state == ShowCreditsPacket::CreditsState::END_CREDITS);
            fakeSendPacket(sp, res);
            }, 10);
    }

    void handle(SimulatedPlayer* sp, ModalFormRequestPacket* packet) {
        //DEBUGW("FakeHandle:({}): {}", sp->getNameTag(),  packet->toDebugString());
        auto& uniqueId = sp->getUniqueID();
        auto formId = packet->formId;
        auto taskid = Schedule::delay([uniqueId, formId]() {
            auto sp = Level::getPlayer(uniqueId);
            auto res = MinecraftPackets::createPacket(MinecraftPacketIds::ModalFormResponse);
            ((ModalFormResponsePacket*)res.get())->formId = formId;
            ((ModalFormResponsePacket*)res.get())->data = "null";
            res->clientSubId = sp->getClientSubId();
            Global<ServerNetworkHandler>->handle(*sp->getNetworkIdentifier(), *(ModalFormResponsePacket*)res.get());
            }, 20).getTaskId();
    }

    void handle(SimulatedPlayer* sp, MovePlayerPacket* packet) {
        //DEBUGW("FakeHandle({}): {}", sp->getNameTag(), packet->toDebugString());
        //auto& uniqueId = sp->getUniqueID();
        //auto taskid = Schedule::delay([uniqueId]() {
        //    auto sp = Level::getPlayer(uniqueId);
        //    }, 20).getTaskId();
    }
}


#include <MC/UpdateAttributesPacket.hpp>
#include <MC/ReadOnlyBinaryStream.hpp>
#include <MC/BinaryStream.hpp>
TInstanceHook(void, "?_sendInternal@NetworkHandler@@AEAAXAEBVNetworkIdentifier@@AEBVPacket@@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z",
    NetworkHandler, NetworkIdentifier& nid, class Packet& pkt, std::string const& data) {
    auto pktId = (int)pkt.getId();

    // fix simulated player sub id
    if (((int64_t*)&nid)[1] == -1 && ((short*)&nid)[8] == -1) {
        try
        {
            auto subId = dAccess<unsigned char>(&nid, 160);
            if (subId != pkt.clientSubId) {
                DEBUG("fix packet {} sub id: {} -> {}", pkt.getName(), pkt.clientSubId, dAccess<unsigned char>(&nid, 160));
                pkt.clientSubId = subId;
            }
        }
        catch (const std::exception&)
        {
            logger.error("Failed to get player's client sub id from NetworkIdentifier");
        }
    }
    auto pl = pkt.getPlayerFromPacket(Global<ServerNetworkHandler>, &nid);
    if (!pl) {
        return original(this, nid, pkt, data);
    }
    ASSERT(pl->getClientSubId() == pkt.clientSubId);
    if (pl->isSimulatedPlayer()) {
        ActorUniqueID uniqueId = pl->getUniqueID();
        switch (pkt.getId())
        {
        case MinecraftPacketIds::ShowCredits:
            FakeHandler::handle((SimulatedPlayer*)pl, (ShowCreditsPacket*)&pkt);
            break;
        case MinecraftPacketIds::ChangeDimension:
            FakeHandler::handle((SimulatedPlayer*)pl, (ChangeDimensionPacket*)&pkt);
            break;
        case MinecraftPacketIds::Respawn:
            FakeHandler::handle((SimulatedPlayer*)pl, (RespawnPacket*)&pkt);
            break;
        //case MinecraftPacketIds::StartGame:
        //    // Not be sent to simulated player, so listen to PlayStatusPacket instead
        //    FakeHandler::handle((SimulatedPlayer*)pl, (StartGamePacket*)&pkt);
        //    break;
        case MinecraftPacketIds::PlayStatus:
            FakeHandler::handle((SimulatedPlayer*)pl, (PlayStatusPacket*)&pkt);
            break;
        case MinecraftPacketIds::MovePlayer:
            FakeHandler::handle((SimulatedPlayer*)pl, (MovePlayerPacket*)&pkt);
            break;
        case MinecraftPacketIds::ModalFormRequest:
            FakeHandler::handle((SimulatedPlayer*)pl, (ModalFormRequestPacket*)&pkt);
            break;
        case MinecraftPacketIds::UpdateAttributes:
        {
            auto packet = (UpdateAttributesPacket*)&pkt;
            BinaryStream bs;
            packet->write(bs);
            DEBUGW("{}",bs.getUnsignedVarInt64());
            int count = bs.getUnsignedVarInt();
            DEBUGW("count {}", count);
            if (count > 60)
                count = 60;
            for (int i = 0; i < count; ++i) {
                DEBUGW("[{}, {}, {}, {}, {}]", bs.getFloat(), bs.getFloat(), bs.getFloat(), bs.getFloat(), bs.getString());
            }
            DEBUGW("{}", bs.getUnsignedVarInt64());
            break;
        }
        default:
            break;
        }
        return;
    }
#if PLUGIN_VERSION_IS_BETA

    switch (pkt.getId())
    {
    case MinecraftPacketIds::SubChunk:
    case MinecraftPacketIds::LevelChunk:
    case MinecraftPacketIds::ClientCacheMissResponse:
    case MinecraftPacketIds::MoveActorDelta:
    case (MinecraftPacketIds)40:// MinecraftPacketIds::SetActorMotion:
    case MinecraftPacketIds::SetActorData:
    case MinecraftPacketIds::LevelSoundEvent:
    case MinecraftPacketIds::ActorEvent:
    case MinecraftPacketIds::MovePlayer:
    //case (MinecraftPacketIds)10:
    //case (MinecraftPacketIds)13:
    //case (MinecraftPacketIds)15:
    //case (MinecraftPacketIds)19:
    //case (MinecraftPacketIds)21:
    //case (MinecraftPacketIds)27:
    //case (MinecraftPacketIds)39:
    //case (MinecraftPacketIds)40:
    //case (MinecraftPacketIds)58:
    //case (MinecraftPacketIds)111:
    //case (MinecraftPacketIds)121:
    //case (MinecraftPacketIds)123:
    //case (MinecraftPacketIds)136:
    //case (MinecraftPacketIds)172:
    //case (MinecraftPacketIds)174:
        break;
    case MinecraftPacketIds::Event:
        DEBUG("[Send] -> {}: {}", pl->getNameTag(), ((EventPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::CraftingEvent:
        DEBUG("[Send] -> {}: {}", pl->getNameTag(), ((CraftingEventPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::ItemStackRequest:
        DEBUG("[Send] -> {}: {}", pl->getNameTag(), ((ItemStackRequestPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::PlayerAction:
        DEBUG("[Send] -> {}: {}", pl->getNameTag(), ((PlayerActionPacket*)&pkt)->toDebugString());
        break;
    //case MinecraftPacketIds::MovePlayer:
    //    DEBUG("[Send] -> {}: {}", pl->getNameTag(), ((MovePlayerPacket*)&pkt)->toDebugString());
    //    break;
    case MinecraftPacketIds::PlayStatus:
        DEBUG("[Send] -> {}: {}", pl->getNameTag(), ((PlayStatusPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::Respawn:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((RespawnPacket*)&pkt)->toDebugString());
        break;
    default:
        DEBUG("[Send] -> {}: {}({})", pl->getNameTag(), pkt.getName(), pkt.getId());
        break;
    }
    /*
    MinecraftPacketIds id = pkt.getId();
    switch (id)
    {
    case MinecraftPacketIds::Login:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((LoginPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::ServerToClientHandshake:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((ServerToClientHandshakePacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::ClientToServerHandshake:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((ClientToServerHandshakePacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::Disconnect:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((DisconnectPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::ResourcePacksInfo:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((ResourcePacksInfoPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::ResourcePackStack:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((ResourcePackStackPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::ResourcePackClientResponse:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((ResourcePackClientResponsePacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::Text:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((TextPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::SetTime:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((SetTimePacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::StartGame:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((StartGamePacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::AddPlayer:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((AddPlayerPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::AddActor:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((AddActorPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::RemoveActor:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((RemoveActorPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::AddItemActor:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((AddItemActorPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::TakeItemActor:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((TakeItemActorPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::MoveActorAbsolute:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((MoveActorAbsolutePacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::UpdateBlock:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((UpdateBlockPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::AddPainting:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((AddPaintingPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::TickSync:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((TickSyncPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::BlockEvent:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((BlockEventPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::ActorEvent:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((ActorEventPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::MobEffect:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((MobEffectPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::UpdateAttributes:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((UpdateAttributesPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::InventoryTransaction:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((InventoryTransactionPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::MobEquipment:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((MobEquipmentPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::MobArmorEquipment:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((MobArmorEquipmentPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::Interact:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((InteractPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::BlockPickRequest:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((BlockPickRequestPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::ActorPickRequest:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((ActorPickRequestPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::HurtArmor:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((HurtArmorPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::SetActorData:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((SetActorDataPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::SetActorLink:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((SetActorLinkPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::SetHealth:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((SetHealthPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::SetSpawnPosition:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((SetSpawnPositionPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::Animate:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((AnimatePacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::Respawn:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((RespawnPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::ContainerOpen:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((ContainerOpenPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::ContainerClose:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((ContainerClosePacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::PlayerHotbar:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((PlayerHotbarPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::InventoryContent:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((InventoryContentPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::InventorySlot:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((InventorySlotPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::ContainerSetData:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((ContainerSetDataPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::CraftingData:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((CraftingDataPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::GuiDataPickItem:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((GuiDataPickItemPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::AdventureSettings:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((AdventureSettingsPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::BlockActorData:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((BlockActorDataPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::PlayerInput:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((PlayerInputPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::LevelChunk:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((LevelChunkPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::SetCommandsEnabled:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((SetCommandsEnabledPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::SetDifficulty:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((SetDifficultyPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::ChangeDimension:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((ChangeDimensionPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::SetPlayerGameType:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((SetPlayerGameTypePacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::PlayerList:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((PlayerListPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::SpawnExperienceOrb:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((SpawnExperienceOrbPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::ClientboundMapItemData:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((ClientboundMapItemDataPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::MapInfoRequest:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((MapInfoRequestPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::ItemFrameDropItem:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((ItemFrameDropItemPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::GameRulesChanged:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((GameRulesChangedPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::Camera:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((CameraPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::BossEvent:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((BossEventPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::ShowCredits:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((ShowCreditsPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::AvailableCommands:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((AvailableCommandsPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::CommandRequest:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((CommandRequestPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::CommandBlockUpdate:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((CommandBlockUpdatePacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::CommandOutput:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((CommandOutputPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::UpdateTrade:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((UpdateTradePacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::UpdateEquip:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((UpdateEquipPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::ResourcePackDataInfo:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((ResourcePackDataInfoPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::ResourcePackChunkData:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((ResourcePackChunkDataPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::ResourcePackChunkRequest:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((ResourcePackChunkRequestPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::Transfer:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((TransferPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::PlaySoundW:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((PlaySoundWPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::StopSound:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((StopSoundPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::SetTitle:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((SetTitlePacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::AddBehaviorTree:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((AddBehaviorTreePacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::StructureBlockUpdate:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((StructureBlockUpdatePacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::ShowStoreOffer:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((ShowStoreOfferPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::PurchaseReceipt:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((PurchaseReceiptPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::PlayerSkin:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((PlayerSkinPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::SubClientLogin:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((SubClientLoginPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::AutomationClientConnect:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((AutomationClientConnectPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::SetLastHurtBy:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((SetLastHurtByPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::BookEdit:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((BookEditPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::NpcRequest:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((NpcRequestPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::PhotoTransfer:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((PhotoTransferPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::ModalFormRequest:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((ModalFormRequestPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::ModalFormResponse:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((ModalFormResponsePacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::ServerSettingsRequest:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((ServerSettingsRequestPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::ServerSettingsResponse:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((ServerSettingsResponsePacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::ShowProfile:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((ShowProfilePacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::SetDefaultGameType:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((SetDefaultGameTypePacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::RemoveObjective:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((RemoveObjectivePacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::SetDisplayObjective:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((SetDisplayObjectivePacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::SetScore:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((SetScorePacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::LabTable:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((LabTablePacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::UpdateBlockSynced:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((UpdateBlockSyncedPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::MoveActorDelta:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((MoveActorDeltaPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::SetScoreboardIdentity:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((SetScoreboardIdentityPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::SetLocalPlayerAsInitialized:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((SetLocalPlayerAsInitializedPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::UpdateSoftEnum:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((UpdateSoftEnumPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::NetworkStackLatency:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((NetworkStackLatencyPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::ScriptCustomEvent:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((ScriptCustomEventPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::SpawnParticleEffect:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((SpawnParticleEffectPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::AvailableActorIdentifiers:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((AvailableActorIdentifiersPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::NetworkChunkPublisherUpdate:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((NetworkChunkPublisherUpdatePacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::BiomeDefinitionList:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((BiomeDefinitionListPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::LevelSoundEvent:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((LevelSoundEventPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::LevelEventGeneric:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((LevelEventGenericPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::LecternUpdate:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((LecternUpdatePacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::AddEntity:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((AddEntityPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::ClientCacheStatus:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((ClientCacheStatusPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::OnScreenTextureAnimation:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((OnScreenTextureAnimationPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::MapCreateLockedCopy:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((MapCreateLockedCopyPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::StructureTemplateDataRequest:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((StructureTemplateDataRequestPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::StructureTemplateDataResponse:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((StructureTemplateDataResponsePacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::ClientCacheBlobStatus:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((ClientCacheBlobStatusPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::ClientCacheMissResponse:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((ClientCacheMissResponsePacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::EducationSettings:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((EducationSettingsPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::Emote:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((EmotePacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::MultiplayerSettings:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((MultiplayerSettingsPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::SettingsCommand:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((SettingsCommandPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::AnvilDamage:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((AnvilDamagePacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::CompletedUsingItem:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((CompletedUsingItemPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::NetworkSettings:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((NetworkSettingsPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::PlayerAuthInput:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((PlayerAuthInputPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::CreativeContent:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((CreativeContentPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::PlayerEnchantOptions:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((PlayerEnchantOptionsPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::ItemStackResponse:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((ItemStackResponsePacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::PlayerArmorDamage:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((PlayerArmorDamagePacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::CodeBuilder:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((CodeBuilderPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::UpdatePlayerGameType:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((UpdatePlayerGameTypePacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::EmoteList:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((EmoteListPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::PositionTrackingDBServerBroadcast:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((PositionTrackingDBServerBroadcastPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::PositionTrackingDBClientRequest:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((PositionTrackingDBClientRequestPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::DebugInfo:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((DebugInfoPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::PacketViolationWarning:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((PacketViolationWarningPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::MotionPredictionHints:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((MotionPredictionHintsPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::AnimateEntity:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((AnimateEntityPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::CameraShake:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((CameraShakePacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::PlayerFog:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((PlayerFogPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::CorrectPlayerMovePrediction:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((CorrectPlayerMovePredictionPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::ItemComponent:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((ItemComponentPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::FilterText:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((FilterTextPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::ClientboundDebugRenderer:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((ClientboundDebugRendererPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::SyncActorProperty:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((SyncActorPropertyPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::AddVolumeEntity:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((AddVolumeEntityPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::RemoveVolumeEntity:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((RemoveVolumeEntityPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::SimulationType:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((SimulationTypePacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::NPCDialogue:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((NPCDialoguePacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::EduUriResource:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((EduUriResourcePacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::CreatePhoto:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((CreatePhotoPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::UpdateSubChunkBlocks:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((UpdateSubChunkBlocksPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::PhotoInfoRequest:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((PhotoInfoRequestPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::SubChunk:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((SubChunkPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::SubChunkRequest:
        DEBUG("[Send] -> {}: {}",pl->getNameTag(), ((SubChunkRequestPacket*)&pkt)->toDebugString());
        break;
    default:
        break;
    }
    */
#endif // PLUGIN_VERSION_IS_BETA
    original(this, nid, pkt, data);
}

// ================= Fix SimulatedPlayer =================

#include <MC/Certificate.hpp>
TInstanceHook(SimulatedPlayer*, "??0SimulatedPlayer@@QEAA@AEAVLevel@@AEAVPacketSender@@AEAVNetworkHandler@@AEAVActiveTransfersManager@Server@ClientBlobCache@@W4GameType@@AEBVNetworkIdentifier@@EV?$function@$$A6AXAEAVServerPlayer@@@Z@std@@VUUID@mce@@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$unique_ptr@VCertificate@@U?$default_delete@VCertificate@@@std@@@std@@H_NAEBV?$OwnerPtrT@UEntityRefTraits@@@@@Z",
    SimulatedPlayer,
    class Level& level,
    class PacketSender& sender,
    class NetworkHandler& handler,
    class ActiveTransfersManager& blobCache,
    enum GameType gameType,
    class NetworkIdentifier const& nid,
    unsigned char subId,
    class std::function<void(class ServerPlayer&)> onPlayerLoadedCallback,
    class mce::UUID uuid,
    std::string const& clientId,
    class std::unique_ptr<Certificate> cert,
    int unk_int,
    bool unk_bool,
    class OwnerPtrT<struct EntityRefTraits> const& refPtr
) {
    //auto fakeUUID = /*uuid;//*/ mce::UUID::fromString("db755d34-dde4-4e4a-bcff-7fae3013d68a");
    DEBUGW("SimulatedPlayer(level, sender, handler, blobCache, gameType = {}, nid, subId = {}, func, uuid = {}, clientId = {}, cert, unk_int = {}, unk_bool = {}, refPtr)",
        (int)gameType, (int)subId, uuid.asString(), clientId, unk_int, unk_bool);

    // fix client sub id for identify packet
    static unsigned char globalSimulatedPlayerSubId = 0;
    auto rtn = original(this, level, sender, handler, blobCache, gameType, nid, globalSimulatedPlayerSubId, onPlayerLoadedCallback, uuid, clientId, std::move(cert), unk_int, unk_bool, refPtr);
    // fix runtime id
    if (!rtn->hasRuntimeID())
        rtn->setRuntimeID(Global<Level>->getNextRuntimeID());
    auto ueif = rtn->getUserEntityIdentifierComponent();
    ASSERT(dAccess<unsigned char>(ueif, 160) == globalSimulatedPlayerSubId);
    globalSimulatedPlayerSubId++;

    DEBUGW("Simulated Player: {}, client sub id: {}, runtime id: {}", rtn->getNameTag(), rtn->getClientSubId(), rtn->getRuntimeID().id);
    return rtn;
}

//fix _updateChunkPublisherView
// _updateChunkPublisherView will be called after Player::tick in ServerPlayer::tick
TInstanceHook(void, "?tickWorld@Player@@UEAAXAEBUTick@@@Z",
    Player, struct Tick const& tick) {
    original(this, tick);

    static auto Vftbl_SimulatedPlayer = dlsym_real("??_7SimulatedPlayer@@6B@");
    static auto Func_updateChunkPublisherView = SymCall("?_updateChunkPublisherView@ServerPlayer@@MEAAXAEBVVec3@@M@Z", void, ServerPlayer*, Vec3 const&, float);
    if (this && *(void**)this == Vftbl_SimulatedPlayer) {
        static auto Func_getPos = SymCall("?getPos@Actor@@UEBAAEBVVec3@@XZ", Vec3 const&, Actor*);
        Func_updateChunkPublisherView((ServerPlayer*)this, Func_getPos(this), 16.0f);
    }
}

THook(void, "?_dropCreatedItems@InventoryTransaction@@AEBAXAEAVPlayer@@@Z",
    InventoryTransaction* _this, Player* pl) {
    original(_this, pl);
}

// fix ChunkSource load mode
TInstanceHook(std::shared_ptr<class ChunkViewSource>, "?_createChunkSource@SimulatedPlayer@@MEAA?AV?$shared_ptr@VChunkViewSource@@@std@@AEAVChunkSource@@@Z",
    SimulatedPlayer, class ChunkSource& chunkSource) {
    auto csPtr = original(this, chunkSource);
    // ChunkSource::LoadMode : None(0) -> Deferred(1)
    dAccess<int>(csPtr.get(), 56) = 1;
    return csPtr;
}


#if PLUGIN_VERSION_IS_BETA

// ================= Test =================

std::string getPlayerStateString(Player* player) {
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
struct voids {
    void**** filler[1000];
};
#include <MC/MinecraftEventing.hpp>
static Player* lastPlayer;
TInstanceHook(NetworkPeer::DataStatus, "?receivePacket@Connection@NetworkHandler@@QEAA?AW4DataStatus@NetworkPeer@@AEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV2@AEBV?$shared_ptr@V?$time_point@Usteady_clock@chrono@std@@V?$duration@_JU?$ratio@$00$0DLJKMKAA@@std@@@23@@chrono@std@@@6@@Z",
    NetworkHandler::Connection, std::string& data, NetworkHandler& handler, class std::shared_ptr<class std::chrono::time_point<struct std::chrono::steady_clock, class std::chrono::duration<__int64, struct std::ratio<1, 1000000000> > > > const& time_point) {
    auto rtn = original(this, data, handler, time_point);
    if (rtn != NetworkPeer::DataStatus::OK)
        return rtn;
    auto& nid = dAccess<NetworkIdentifier>(this, 0);
    lastPlayer = Global<ServerNetworkHandler>->getServerPlayer(nid, dAccess<unsigned int>(&nid, 160));
    return rtn;
    
}
TInstanceHook(void, "?sendPacketReceivedFrom@NetworkPacketEventCoordinator@@QEAAXAEBVPacketHeader@@AEBVPacket@@@Z",
    NetworkPacketEventCoordinator, class PacketHeader const& header, class Packet const& pkt) {
    auto pl = lastPlayer;
    static int count = 0;
    if (!pl) {
        DEBUG("[Received] <- : {}({})", pkt.getName(), pkt.getId());
        return original(this, header, pkt);
    }
    auto pktId = pkt.getId();
    switch (pkt.getId())
    {
    case MinecraftPacketIds::Event:
        DEBUG("[Received] <- {}: {}", pl->getNameTag(), ((EventPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::CraftingEvent:
        DEBUG("[Received] <- {}: {}", pl->getNameTag(), ((CraftingEventPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::ItemStackRequest:
        DEBUG("[Received] <- {}: {}", pl->getNameTag(), ((ItemStackRequestPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::PlayerAction:
        DEBUG("[Received] <- {}: {}", pl->getNameTag(), ((PlayerActionPacket*)&pkt)->toDebugString());
        break;
    //case MinecraftPacketIds::MovePlayer:
    //    DEBUG("[Received] <- {}: {}", pl->getNameTag(), ((MovePlayerPacket*)&pkt)->toDebugString());
    //    break;
    case MinecraftPacketIds::PlayStatus:
        DEBUG("[Received] <- {}: {}", pl->getNameTag(), ((PlayStatusPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::Respawn:
        DEBUG("[Received] <- {}: {}", pl->getNameTag(), ((RespawnPacket*)&pkt)->toDebugString());
        break;
    case (MinecraftPacketIds)123:
    case (MinecraftPacketIds)135:
    case (MinecraftPacketIds)144:
    case (MinecraftPacketIds)175:
    case MinecraftPacketIds::MovePlayer:
        if(!((++count) % 100))
            DEBUG("[Received] <- {}: {}({})", pl->getNameTag(), pkt.getName(), pkt.getId());
        break;
    default:
        DEBUG("[Received] <- {}: {}({})", pl->getNameTag(), pkt.getName(), pkt.getId());
        break;
    }

    original(this, header, pkt);
}

TInstanceHook(ServerPlayer*, "??0ServerPlayer@@QEAA@AEAVLevel@@AEAVPacketSender@@AEAVNetworkHandler@@AEAVActiveTransfersManager@Server@ClientBlobCache@@W4GameType@@AEBVNetworkIdentifier@@EV?$function@$$A6AXAEAVServerPlayer@@@Z@std@@VUUID@mce@@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$unique_ptr@VCertificate@@U?$default_delete@VCertificate@@@std@@@std@@H_NAEBV?$OwnerPtrT@UEntityRefTraits@@@@@Z",
    ServerPlayer, class Level& level, class PacketSender& sender, class NetworkHandler& handler,
    class ActiveTransfersManager& blobCache, enum GameType gameType,
    class NetworkIdentifier const& nid, unsigned char subId,
    class std::function<void(class ServerPlayer&)> onPlayerLoadedCallback, class mce::UUID uuid, std::string const& clientId,
    class std::unique_ptr<Certificate> cert, int unk_int, bool unk_bool, class OwnerPtrT<struct EntityRefTraits> const& refPtr) {
    DEBUG("ServerPlayer(level, sender, handler, blobCache, gameType = {}, nid, subId = {}, func, uuid = {}, clientId = {}, cert, unk_int = {}, unk_bool = {}, refPtr)",
        (int)gameType, (int)subId, uuid.asString(), clientId, unk_int, unk_bool);
    auto rtn = original(this, level, sender, handler, blobCache, gameType, nid, subId, onPlayerLoadedCallback, uuid, clientId, std::move(cert), unk_int, unk_bool, refPtr);
    return rtn;
}

class ChangeDimensionRequest {
public:
    int mState;
    AutomaticID<Dimension, int> mFromDimensionId;
    AutomaticID<Dimension, int> mToDimensionId;
    Vec3 mPosition;
    bool mUsePortal;
    bool mRespawn;
    std::unique_ptr<CompoundTag> mAgentTag;
    std::string toDebugString() {
        return fmt::format("state: {}, dim: {}->{}, position: ({}), usePortal: {}, respawn: {}",
            mState, (int)mFromDimensionId, (int)mToDimensionId, mPosition.toString(), mUsePortal, mRespawn);
    }
};

static bool Listen_hasChunksAt = false;
static_assert(offsetof(ChangeDimensionRequest, mRespawn) == 25);
TInstanceHook(bool, "?_playerChangeDimension@Level@@AEAA_NPEAVPlayer@@AEAVChangeDimensionRequest@@@Z",
    Level, Player* player, class ChangeDimensionRequest& request) {
    auto rtn = original(this, player, request);
    if (!player)
        return rtn;
    auto bpos = player->getBlockPos();
    int distance = 32*2; // IDA Level::_playerChangeDimension line 339 before return
    auto max_cx = (bpos.x + distance) >> 4;
    auto min_cx = (bpos.x - distance) >> 4;
    auto max_cz = (bpos.z + distance) >> 4;
    auto min_cz = (bpos.z - distance) >> 4;
    auto chunksCount = 0;
    auto needChunksCount = (max_cx - min_cx + 1) * (max_cz - min_cz + 1);

    string loadInfo = "";
    auto& region = player->getRegion();
    auto& cs = region.getChunkSource();

    for (auto cx = min_cx; cx <= max_cx; ++cx) {
        loadInfo += "\n";
        for (auto cz = min_cz; cz <= max_cz; ++cz) {
            auto chunk = region.getChunk({ cx, cz });
            loadInfo += chunk ? "1" : "0";
            if (chunk)
                ++chunksCount;
            else {
                //auto dimension = (Dimension*)&region.getDimensionConst();
                //auto actionList = dimension->getChunkLoadActionList().get();
                //actionList->addChunkLoadedRequest();
                cs.getOrLoadChunk({ cx, cz }, (ChunkSource::LoadMode)1, true);
            }
        }
    }
    DEBUG("cx range:[{}:{}], cz range:[{}:{}], Info: {}", min_cx, max_cx, min_cz, max_cz, loadInfo);
    DEBUG("Loaded Chunk: needs: {}, loaded:{} ", needChunksCount, chunksCount);
    return rtn;
}

TInstanceHook(void, "?requestPlayerChangeDimension@Level@@UEAAXAEAVPlayer@@V?$unique_ptr@VChangeDimensionRequest@@U?$default_delete@VChangeDimensionRequest@@@std@@@std@@@Z",
    Level, Player& player, std::unique_ptr<ChangeDimensionRequest> requestPtr) {
    DEBUG("Level::requestPlayerChangeDimension({}, requestPtr)", player.getNameTag());
    DEBUG("Request: {}", requestPtr->toDebugString());
    DEBUG(getPlayerStateString(&player));
    return original(this, player, std::move(requestPtr));
}


 //fix load chunk
TInstanceHook(void, "?prepareRegion@ServerPlayer@@UEAAXAEAVChunkSource@@@Z",
    ServerPlayer, class ChunkSource& cs) {
    //if (isSimulatedPlayer() && (!&getDimension())) {
    //    auto dim = Global<Level>->createDimension(truthDimensionId);
    //    if (dim)
    //        return original(this, dim->getChunkSource());
    //}
    DEBUG("ServerPlayer({})::prepareRegion(ChunkSource(dimid: {}))", this->getNameTag(), (int)cs.getDimension().getDimensionId());

    original(this, cs);
}


TInstanceHook(void, "?destroyRegion@ServerPlayer@@UEAAXXZ",
    ServerPlayer) {
    DEBUG("ServerPlayer({})::destroyRegion()", this->getNameTag());
    return original(this);
}

TInstanceHook(void, "?resendAllChunks@ServerPlayer@@UEAAXXZ",
    ServerPlayer) {
    DEBUG("ServerPlayer({})::resendAllChunks()", this->getNameTag());
    return original(this);
}

TInstanceHook(void, "?_fireDimensionChanged@Player@@UEAAXXZ",
    ServerPlayer) {
    DEBUG("ServerPlayer({})::_fireDimensionChanged()", this->getNameTag());
    return original(this);
}

TInstanceHook(void, "?suspendRegion@ServerPlayer@@UEAAXXZ",
    ServerPlayer) {
    DEBUG("ServerPlayer({})::suspendRegion()", this->getNameTag());
    return original(this);
}

TInstanceHook(void, "?_fireWillChangeDimension@Player@@UEAAXXZ",
    ServerPlayer) {
    DEBUG("Player({})::_fireWillChangeDimension()", this->getNameTag());
    return original(this);
}

TInstanceHook(void, "?_updateChunkPublisherView@ServerPlayer@@MEAAXAEBVVec3@@M@Z",
    ServerPlayer, Vec3 const& pos, float unkf) {
    static __int64 logTick = 0;
    //if (++logTick % 20 == 0)
    //    DEBUG("Player({})::_updateChunkPublisherView(({}), {})", this->getNameTag(), pos.toString(), unkf);
    return original(this, pos, unkf);
}

TInstanceHook(__int64, "?_getSpawnChunkLimit@ServerPlayer@@MEBAHXZ",
    ServerPlayer) {
    static __int64 logTick = 0;
    auto rtn = original(this);
    if (++logTick % 20 == 0)
        DEBUG("ServerPlayer({})::_getSpawnChunkLimit() -> {}", this->getNameTag(), rtn);
    return rtn;
}

TInstanceHook(__int64, "?respawn@Player@@UEAAXXZ",
    ServerPlayer) {
    DEBUG("Player({})::respawn()", this->getNameTag());
    auto rtn = original(this);
    return rtn;
}

#endif // PLUGIN_VERSION_IS_BETA