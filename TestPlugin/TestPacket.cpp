#include "pch.h"
#include "TestPacket.h"
#include <MC/Certificate.hpp>
#include <MC/UpdateAttributesPacket.hpp>
#include <MC/ReadOnlyBinaryStream.hpp>
#include <MC/BinaryStream.hpp>
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

TInstanceHook(void, "?_sendInternal@NetworkHandler@@AEAAXAEBVNetworkIdentifier@@AEBVPacket@@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z",
              NetworkHandler, NetworkIdentifier& nid, class Packet& pkt, std::string const& data)
{
    auto pktId = (int)pkt.getId();
    static size_t packetCount = 0;
    static time_t timeStart = time(0);
    if (++packetCount % 10000 == 0)
    {
        logger.warn("sendPacket - time: {} \t, count: {}", time(0) - timeStart, packetCount);
    }
    auto pl = pkt.getPlayerFromPacket(Global<ServerNetworkHandler>, &nid);
    if (!pl)
    {
        return original(this, nid, pkt, data);
    }
    switch (pkt.getId())
    {
        case MinecraftPacketIds::SubChunk:
        case MinecraftPacketIds::LevelChunk:
        case MinecraftPacketIds::ClientCacheMissResponse:
        case MinecraftPacketIds::MoveActorDelta:
        case (MinecraftPacketIds)40: // MinecraftPacketIds::SetActorMotion:
        case MinecraftPacketIds::SetActorData:
        case MinecraftPacketIds::LevelSoundEvent:
        case MinecraftPacketIds::ActorEvent:
        case MinecraftPacketIds::MovePlayer:
            //case MinecraftPacketIds::Event:
        case MinecraftPacketIds::LevelEventGeneric:
        case MinecraftPacketIds::UpdateBlock:
        case MinecraftPacketIds::UpdateSubChunkBlocks:
        case MinecraftPacketIds::UpdateAttributes:
            break;
        case MinecraftPacketIds::Event:
            logger.info("[Send] -> {}: {}", pl->getNameTag(), ((EventPacket*)&pkt)->toDebugString());
            break;
        case MinecraftPacketIds::CraftingEvent:
            logger.info("[Send] -> {}: {}", pl->getNameTag(), ((CraftingEventPacket*)&pkt)->toDebugString());
            break;
            //case MinecraftPacketIds::ItemStackRequest:
            //    logger.info("[Send] -> {}: {}", pl->getNameTag(), ((ItemStackRequestPacket*)&pkt)->toDebugString());
            //    break;
            //case MinecraftPacketIds::PlayerAction:
            //    logger.info("[Send] -> {}: {}", pl->getNameTag(), ((PlayerActionPacket*)&pkt)->toDebugString());
            //    break;
            //case MinecraftPacketIds::MovePlayer:
            //    logger.info("[Send] -> {}: {}", pl->getNameTag(), ((MovePlayerPacket*)&pkt)->toDebugString());
            //    break;
        case MinecraftPacketIds::PlayStatus:
            logger.info("[Send] -> {}: {}", pl->getNameTag(), ((PlayStatusPacket*)&pkt)->toDebugString());
            break;
        case MinecraftPacketIds::Respawn:
            logger.info("[Send] -> {}: {}", pl->getNameTag(), ((RespawnPacket*)&pkt)->toDebugString());
            break;
        default:
            logger.info("[Send] -> {}: {}({})", pl->getNameTag(), pkt.getName(), pkt.getId());
            break;
    }
    /*
    MinecraftPacketIds id = pkt.getId();
    switch (id)
    {
    case MinecraftPacketIds::Login:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((LoginPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::ServerToClientHandshake:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((ServerToClientHandshakePacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::ClientToServerHandshake:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((ClientToServerHandshakePacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::Disconnect:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((DisconnectPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::ResourcePacksInfo:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((ResourcePacksInfoPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::ResourcePackStack:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((ResourcePackStackPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::ResourcePackClientResponse:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((ResourcePackClientResponsePacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::Text:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((TextPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::SetTime:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((SetTimePacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::StartGame:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((StartGamePacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::AddPlayer:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((AddPlayerPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::AddActor:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((AddActorPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::RemoveActor:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((RemoveActorPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::AddItemActor:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((AddItemActorPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::TakeItemActor:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((TakeItemActorPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::MoveActorAbsolute:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((MoveActorAbsolutePacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::UpdateBlock:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((UpdateBlockPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::AddPainting:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((AddPaintingPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::TickSync:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((TickSyncPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::BlockEvent:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((BlockEventPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::ActorEvent:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((ActorEventPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::MobEffect:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((MobEffectPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::UpdateAttributes:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((UpdateAttributesPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::InventoryTransaction:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((InventoryTransactionPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::MobEquipment:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((MobEquipmentPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::MobArmorEquipment:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((MobArmorEquipmentPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::Interact:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((InteractPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::BlockPickRequest:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((BlockPickRequestPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::ActorPickRequest:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((ActorPickRequestPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::HurtArmor:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((HurtArmorPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::SetActorData:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((SetActorDataPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::SetActorLink:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((SetActorLinkPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::SetHealth:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((SetHealthPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::SetSpawnPosition:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((SetSpawnPositionPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::Animate:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((AnimatePacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::Respawn:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((RespawnPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::ContainerOpen:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((ContainerOpenPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::ContainerClose:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((ContainerClosePacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::PlayerHotbar:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((PlayerHotbarPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::InventoryContent:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((InventoryContentPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::InventorySlot:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((InventorySlotPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::ContainerSetData:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((ContainerSetDataPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::CraftingData:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((CraftingDataPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::GuiDataPickItem:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((GuiDataPickItemPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::AdventureSettings:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((AdventureSettingsPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::BlockActorData:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((BlockActorDataPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::PlayerInput:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((PlayerInputPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::LevelChunk:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((LevelChunkPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::SetCommandsEnabled:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((SetCommandsEnabledPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::SetDifficulty:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((SetDifficultyPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::ChangeDimension:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((ChangeDimensionPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::SetPlayerGameType:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((SetPlayerGameTypePacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::PlayerList:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((PlayerListPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::SpawnExperienceOrb:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((SpawnExperienceOrbPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::ClientboundMapItemData:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((ClientboundMapItemDataPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::MapInfoRequest:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((MapInfoRequestPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::ItemFrameDropItem:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((ItemFrameDropItemPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::GameRulesChanged:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((GameRulesChangedPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::Camera:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((CameraPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::BossEvent:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((BossEventPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::ShowCredits:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((ShowCreditsPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::AvailableCommands:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((AvailableCommandsPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::CommandRequest:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((CommandRequestPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::CommandBlockUpdate:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((CommandBlockUpdatePacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::CommandOutput:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((CommandOutputPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::UpdateTrade:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((UpdateTradePacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::UpdateEquip:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((UpdateEquipPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::ResourcePackDataInfo:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((ResourcePackDataInfoPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::ResourcePackChunkData:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((ResourcePackChunkDataPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::ResourcePackChunkRequest:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((ResourcePackChunkRequestPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::Transfer:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((TransferPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::PlaySoundW:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((PlaySoundWPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::StopSound:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((StopSoundPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::SetTitle:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((SetTitlePacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::AddBehaviorTree:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((AddBehaviorTreePacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::StructureBlockUpdate:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((StructureBlockUpdatePacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::ShowStoreOffer:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((ShowStoreOfferPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::PurchaseReceipt:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((PurchaseReceiptPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::PlayerSkin:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((PlayerSkinPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::SubClientLogin:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((SubClientLoginPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::AutomationClientConnect:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((AutomationClientConnectPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::SetLastHurtBy:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((SetLastHurtByPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::BookEdit:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((BookEditPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::NpcRequest:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((NpcRequestPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::PhotoTransfer:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((PhotoTransferPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::ModalFormRequest:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((ModalFormRequestPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::ModalFormResponse:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((ModalFormResponsePacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::ServerSettingsRequest:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((ServerSettingsRequestPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::ServerSettingsResponse:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((ServerSettingsResponsePacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::ShowProfile:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((ShowProfilePacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::SetDefaultGameType:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((SetDefaultGameTypePacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::RemoveObjective:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((RemoveObjectivePacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::SetDisplayObjective:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((SetDisplayObjectivePacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::SetScore:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((SetScorePacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::LabTable:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((LabTablePacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::UpdateBlockSynced:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((UpdateBlockSyncedPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::MoveActorDelta:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((MoveActorDeltaPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::SetScoreboardIdentity:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((SetScoreboardIdentityPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::SetLocalPlayerAsInitialized:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((SetLocalPlayerAsInitializedPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::UpdateSoftEnum:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((UpdateSoftEnumPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::NetworkStackLatency:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((NetworkStackLatencyPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::ScriptCustomEvent:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((ScriptCustomEventPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::SpawnParticleEffect:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((SpawnParticleEffectPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::AvailableActorIdentifiers:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((AvailableActorIdentifiersPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::NetworkChunkPublisherUpdate:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((NetworkChunkPublisherUpdatePacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::BiomeDefinitionList:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((BiomeDefinitionListPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::LevelSoundEvent:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((LevelSoundEventPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::LevelEventGeneric:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((LevelEventGenericPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::LecternUpdate:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((LecternUpdatePacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::AddEntity:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((AddEntityPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::ClientCacheStatus:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((ClientCacheStatusPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::OnScreenTextureAnimation:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((OnScreenTextureAnimationPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::MapCreateLockedCopy:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((MapCreateLockedCopyPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::StructureTemplateDataRequest:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((StructureTemplateDataRequestPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::StructureTemplateDataResponse:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((StructureTemplateDataResponsePacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::ClientCacheBlobStatus:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((ClientCacheBlobStatusPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::ClientCacheMissResponse:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((ClientCacheMissResponsePacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::EducationSettings:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((EducationSettingsPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::Emote:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((EmotePacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::MultiplayerSettings:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((MultiplayerSettingsPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::SettingsCommand:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((SettingsCommandPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::AnvilDamage:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((AnvilDamagePacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::CompletedUsingItem:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((CompletedUsingItemPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::NetworkSettings:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((NetworkSettingsPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::PlayerAuthInput:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((PlayerAuthInputPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::CreativeContent:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((CreativeContentPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::PlayerEnchantOptions:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((PlayerEnchantOptionsPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::ItemStackResponse:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((ItemStackResponsePacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::PlayerArmorDamage:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((PlayerArmorDamagePacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::CodeBuilder:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((CodeBuilderPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::UpdatePlayerGameType:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((UpdatePlayerGameTypePacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::EmoteList:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((EmoteListPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::PositionTrackingDBServerBroadcast:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((PositionTrackingDBServerBroadcastPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::PositionTrackingDBClientRequest:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((PositionTrackingDBClientRequestPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::DebugInfo:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((DebugInfoPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::PacketViolationWarning:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((PacketViolationWarningPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::MotionPredictionHints:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((MotionPredictionHintsPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::AnimateEntity:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((AnimateEntityPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::CameraShake:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((CameraShakePacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::PlayerFog:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((PlayerFogPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::CorrectPlayerMovePrediction:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((CorrectPlayerMovePredictionPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::ItemComponent:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((ItemComponentPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::FilterText:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((FilterTextPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::ClientboundDebugRenderer:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((ClientboundDebugRendererPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::SyncActorProperty:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((SyncActorPropertyPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::AddVolumeEntity:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((AddVolumeEntityPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::RemoveVolumeEntity:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((RemoveVolumeEntityPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::SimulationType:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((SimulationTypePacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::NPCDialogue:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((NPCDialoguePacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::EduUriResource:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((EduUriResourcePacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::CreatePhoto:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((CreatePhotoPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::UpdateSubChunkBlocks:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((UpdateSubChunkBlocksPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::PhotoInfoRequest:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((PhotoInfoRequestPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::SubChunk:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((SubChunkPacket*)&pkt)->toDebugString());
        break;
    case MinecraftPacketIds::SubChunkRequest:
        logger.info("[Send] -> {}: {}",pl->getNameTag(), ((SubChunkRequestPacket*)&pkt)->toDebugString());
        break;
    default:
        break;
    }
    */

    original(this, nid, pkt, data);
}

