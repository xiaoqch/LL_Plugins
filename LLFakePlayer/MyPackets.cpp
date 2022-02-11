#include "pch.h"
#include "MyPackets.h"
#ifdef DEBUG
Logger bsLogger("BinaryStream");
namespace
{
bool isWriting = false;
bool isHooking = false;
time_t minInterval = 1;
template <typename T>
time_t lastLogTime = 0;
template <typename T>
size_t writeTimes = 0;
}

#pragma region ForEachPacket

#define ForEachPacket(func)                        \
    /*func(MoveActorDeltaPacket);              */      /* 10452 */\
    /*func(LevelChunkPacket);                  */      /* 1976  */\
    /*func(LevelSoundEventPacket);             */      /* 1597  */\
    /*func(SetActorDataPacket);                */      /* 1221  */\
    /*func(LevelEventPacket);                  */      /* 1130  */\
    /*func(SetActorMotionPacket);              */      /* 926   */\
    /*func(MovePlayerPacket);                  */      /* 869   */\
    /*func(ClientCacheMissResponsePacket);     */      /* 779   */\
    /*func(SubChunkPacket);                    */      /* 594   */\
    /*func(UpdateAttributesPacket);            */      /* 500   */\
    /*func(NetworkChunkPublisherUpdatePacket); */      /* 269   */\
    /*func(MapInfoRequestPacket);              */      /* 242   */\
    /*func(AddActorPacket);                    */      /* 183   */\
    /*func(ActorEventPacket);                  */      /* 134   */\
    /*func(AddItemActorPacket);                */      /* 113   */\
    /*func(UpdateBlockPacket);                 */      /* 41    */\
    /*func(SetHealthPacket);                   */      /* 39    */\
    /*func(InventoryContentPacket);            */      /* 32    */\
    /*func(EventPacket);                       */      /* 24    */\
    /*func(InventoryTransactionPacket);        */      /* 19    */\
    /*func(MobEquipmentPacket);                */      /* 16    */\
    /*func(RespawnPacket);                     */      /* 10    */\
    /*func(MotionPredictionHintsPacket);       */      /* 10    */\
    func(TakeItemActorPacket);                     /* 9     */\
    func(InventorySlotPacket);                     /* 8     */\
    func(PlayerHotbarPacket);                      /* 8     */\
    func(AnimatePacket);                           /* 7     */\
    func(TextPacket);                              /* 5     */\
    func(CommandOutputPacket);                     /* 5     */\
    func(PlayerListPacket);                        /* 5     */\
    func(AdventureSettingsPacket);                 /* 4     */\
    func(PlayStatusPacket);                        /* 4     */\
    func(SimpleEventPacket);                       /* 2     */\
    func(AddBehaviorTreePacket);                   /* 2     */\
    func(TickSyncPacket);                          /* 2     */\
    func(AvailableActorIdentifiersPacket);         /* 2     */\
    func(AvailableCommandsPacket);                 /* 2     */\
    func(BiomeDefinitionListPacket);               /* 2     */\
    func(ClientCacheStatusPacket);                 /* 2     */\
    func(ContainerClosePacket);                    /* 2     */\
    func(CraftingDataPacket);                      /* 2     */\
    func(CreativeContentPacket);                   /* 2     */\
    func(SetDifficultyPacket);                     /* 2     */\
    func(GameRulesChangedPacket);                  /* 2     */\
    func(ResourcePackStackPacket);                 /* 2     */\
    func(ResourcePacksInfoPacket);                 /* 2     */\
    func(ItemComponentPacket);                     /* 2     */\
    func(SetSpawnPositionPacket);                  /* 2     */\
    func(StartGamePacket);                         /* 2     */\
    func(PlayerFogPacket);                         /* 2     */\
    func(AddPlayerPacket);                         /* 1     */\
    func(StopSoundPacket);                         /* 0     */\
    func(PlayerArmorDamagePacket);                 /* 0     */\
    func(ActorPickRequestPacket);                  /* 0     */\
    func(AddPaintingPacket);                       /* 0     */\
    func(StructureTemplateDataResponsePacket);     /* 0     */\
    func(TransferPacket);                          /* 0     */\
    func(UpdateBlockSyncedPacket);                 /* 0     */\
    func(UpdateEquipPacket);                       /* 0     */\
    func(UpdateSoftEnumPacket);                    /* 0     */\
    func(UpdateTradePacket);                       /* 0     */\
    func(LoginPacket);                             /* 0     */\
    func(CameraPacket);                            /* 0     */\
    func(MobArmorEquipmentPacket);                 /* 0     */\
    func(MobEffectPacket);                         /* 0     */\
    func(ServerSettingsResponsePacket);            /* 0     */\
    func(MoveActorAbsolutePacket);                 /* 0     */\
    func(NetworkStackLatencyPacket);               /* 0     */\
    func(NpcRequestPacket);                        /* 0     */\
    func(OnScreenTextureAnimationPacket);          /* 0     */\
    func(PacketViolationWarningPacket);            /* 0     */\
    func(PhotoTransferPacket);                     /* 0     */\
    func(PlaySoundPacket);                         /* 0     */\
    func(PlayerActionPacket);                      /* 0     */\
    func(PlayerAuthInputPacket);                   /* 0     */\
    func(AnvilDamagePacket);                       /* 0     */\
    func(BlockActorDataPacket);                    /* 0     */\
    func(BlockEventPacket);                        /* 0     */\
    func(BlockPickRequestPacket);                  /* 0     */\
    func(BookEditPacket);                          /* 0     */\
    func(BossEventPacket);                         /* 0     */\
    func(ChangeDimensionPacket);                   /* 0     */\
    func(ClientCacheBlobStatusPacket);             /* 0     */\
    func(ClientboundMapItemDataPacket);            /* 0     */\
    func(CommandBlockUpdatePacket);                /* 0     */\
    func(CommandRequestPacket);                    /* 0     */\
    func(CompletedUsingItemPacket);                /* 0     */\
    func(ContainerOpenPacket);                     /* 0     */\
    func(ContainerSetDataPacket);                  /* 0     */\
    func(CraftingEventPacket);                     /* 0     */\
    func(DebugInfoPacket);                         /* 0     */\
    func(DisconnectPacket);                        /* 0     */\
    func(EducationSettingsPacket);                 /* 0     */\
    func(EmoteListPacket);                         /* 0     */\
    func(EmotePacket);                             /* 0     */\
    func(GuiDataPickItemPacket);                   /* 0     */\
    func(HurtArmorPacket);                         /* 0     */\
    func(InteractPacket);                          /* 0     */\
    func(ItemFrameDropItemPacket);                 /* 0     */\
    func(ItemStackRequestPacket);                  /* 0     */\
    func(ItemStackResponsePacket);                 /* 0     */\
    func(LabTablePacket);                          /* 0     */\
    func(LecternUpdatePacket);                     /* 0     */\
    func(LevelEventGenericPacket);                 /* 0     */\
    func(PlayerEnchantOptionsPacket);              /* 0     */\
    func(PlayerInputPacket);                       /* 0     */\
    func(PlayerSkinPacket);                        /* 0     */\
    func(PositionTrackingDBClientRequestPacket);   /* 0     */\
    func(PositionTrackingDBServerBroadcastPacket); /* 0     */\
    func(PurchaseReceiptPacket);                   /* 0     */\
    func(ResourcePackChunkDataPacket);             /* 0     */\
    func(ResourcePackChunkRequestPacket);          /* 0     */\
    func(ResourcePackClientResponsePacket);        /* 0     */\
    func(ResourcePackDataInfoPacket);              /* 0     */\
    func(ScriptCustomEventPacket);                 /* 0     */\
    func(SetActorLinkPacket);                      /* 0     */\
    func(CreatePhotoPacket);                       /* 0     */\
    func(EduUriResourcePacket);                    /* 0     */\
    func(NpcDialoguePacket);                       /* 0     */\
    func(SimulationTypePacket);                    /* 0     */\
    func(UpdateSubChunkBlocksPacket);              /* 0     */\
    func(SubChunkRequestPacket);                   /* 0     */\
    func(AddVolumeEntityPacket);                   /* 0     */\
    func(AnimateEntityPacket);                     /* 0     */\
    func(CameraShakePacket);                       /* 0     */\
    func(CodeBuilderSourcePacket);                 /* 0     */\
    func(ClientboundDebugRendererPacket);          /* 0     */\
    func(CorrectPlayerMovePredictionPacket);       /* 0     */\
    func(PlayerStartItemCooldownPacket);           /* 0     */\
    func(ScriptMessagePacket);                     /* 0     */\
    func(SetDisplayObjectivePacket);               /* 0     */\
    func(SetLocalPlayerAsInitializedPacket);       /* 0     */\
    func(SetScorePacket);                          /* 0     */\
    func(SetScoreboardIdentityPacket);             /* 0     */\
    func(SetTitlePacket);                          /* 0     */\
    func(ShowCreditsPacket);                       /* 0     */\
    func(ShowStoreOfferPacket);                    /* 0     */\
    func(SpawnExperienceOrbPacket);                /* 0     */\
    func(SpawnParticleEffectPacket);               /* 0     */\
    func(StructureBlockUpdatePacket);              /* 0     */\
    func(StructureTemplateDataRequestPacket);      /* 0     */\
    func(SubClientLoginPacket);                    /* 0     */\
    func(UpdatePlayerGameTypePacket);              /* 0     */

#pragma endregion

//TInstanceHook(void, "?writeVarInt@BinaryStream@@QEAAXH@Z",
//              BinaryStream, int value)
//{
//    if (!isHooking || !isWriting)
//        return original(this, value);
//    isWriting = true;
//    bsLogger.info("{}, {}");
//    original(this, value);
//    isWriting = false;
//}

bool regCmd();

template <typename T>
void onPacketWrite(std::string const& type)
{
    static auto a = regCmd();
    writeTimes<T> ++;
    auto newTime = time(0);
    if (newTime - lastLogTime<T> - minInterval > 0)
    {
        logger.warn("{}::write", type);
        lastLogTime<T> = newTime;
    }
}

#define HookPacketWrite(packetType)                                  \
    THook(void, "?write@" #packetType "@@UEBAXAEAVBinaryStream@@@Z", \
          class packetType& packet, class BinaryStream& bs)          \
    {                                                                \
        if (isHooking)                                               \
            return original(packet, bs);                             \
        isHooking = true;                                            \
        onPacketWrite<packetType>(#packetType);                      \
        original(packet, bs);                                        \
        isHooking = false;                                           \
    }


ForEachPacket(HookPacketWrite);
#define LogPacketTimes(packet) logger.warn("{}\t: {}", writeTimes<packet>, #packet)

void logPacketTimes()
{
    ForEachPacket(LogPacketTimes);
}


class PacketCommand : public Command
{
    virtual void execute(class CommandOrigin const& origin, class CommandOutput& output) const override
    {
        logPacketTimes();
    };

public:
    static void setup(CommandRegistry& registry)
    {
        registry.registerCommand("packet", "Show Packet", CommandPermissionLevel::Any, {(CommandFlagValue)0}, {(CommandFlagValue)0x80});
        registry.registerOverload<PacketCommand>("packet");
    }
};

bool regCmd()
{
    PacketCommand::setup(*Global<CommandRegistry>);
    return true;
}
#endif // DEBUG
