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
time_t lastLogWriteTime = 0;
template <typename T>
size_t writeTimes = 0;
template <typename T>
time_t lastLogReadTime = 0;
template <typename T>
size_t readTimes = 0;
uint64_t lastReadHash=0;
uint64_t lastWriteHash=0;
bool LogSwitch = false;
}

#pragma region ForEachPacket

#define ForEachPacket(Func)                                                   \
    Func(ShowProfilePacket);                       /* 0    , 0     ,0      */ \
    Func(SetDefaultGameTypePacket);                /* 0    , 0     ,0      */ \
    Func(RemoveObjectivePacket);                   /* 0    , 0     ,0      */ \
    Func(RemoveVolumeEntityPacket);                /* 0    , 0     ,0      */ \
    Func(SyncActorPropertyPacket);                 /* 0    , 0     ,0      */ \
    Func(FilterTextPacket);                        /* 0    , 0     ,0      */ \
    Func(CodeBuilderPacket);                       /* 0    , 0     ,0      */ \
    Func(NetworkSettingsPacket);                   /* 0    , 0     ,0      */ \
    Func(MultiplayerSettingsPacket);               /* 0    , 0     ,0      */ \
    Func(SettingsCommandPacket);                   /* 0    , 0     ,0      */ \
    Func(MapCreateLockedCopyPacket);               /* 0    , 0     ,0      */ \
    Func(AddEntityPacket);                         /* 0    , 0     ,0      */ \
    Func(RemoveEntityPacket);                      /* 0    , 0     ,0      */ \
    Func(LevelSoundEventPacketV2);                 /* 0    , 0     ,0      */ \
    Func(ModalFormRequestPacket);                  /* 0    , 0     ,0      */ \
    Func(ModalFormResponsePacket);                 /* 0    , 0     ,0      */ \
    Func(ServerSettingsRequestPacket);             /* 0    , 0     ,0      */ \
    Func(ClientToServerHandshakePacket);           /* 0    , 0     ,0      */ \
    Func(ServerToClientHandshakePacket);           /* 0    , 0     ,0      */ \
    Func(SetTimePacket);                           /* 0    , 0     ,0      */ \
    Func(RemoveActorPacket);                       /* 0    , 0     ,0      */ \
    Func(PassengerJumpPacket);                     /* 0    , 0     ,0      */ \
    Func(LevelSoundEventPacketV1);                 /* 0    , 0     ,0      */ \
    Func(SetCommandsEnabledPacket);                /* 0    , 0     ,0      */ \
    Func(SetPlayerGameTypePacket);                 /* 0    , 0     ,0      */ \
    Func(RequestChunkRadiusPacket);                /* 0    , 0     ,0      */ \
    Func(ChunkRadiusUpdatedPacket);                /* 0    , 0     ,0      */ \
    Func(SetLastHurtByPacket);                     /* 0    , 0     ,0      */ \
    Func(AutomationClientConnectPacket);           /* 0    , 0     ,0      */ \
    Func(StopSoundPacket);                         /* 0    , 0     ,0      */ \
    Func(PlayerArmorDamagePacket);                 /* 0    , 0     ,0      */ \
    Func(ActorPickRequestPacket);                  /* 0    , 0     ,0      */ \
    Func(AddPaintingPacket);                       /* 0    , 0     ,0      */ \
    Func(StructureTemplateDataResponsePacket);     /* 0    , 0     ,0      */ \
    Func(TransferPacket);                          /* 0    , 0     ,0      */ \
    Func(UpdateEquipPacket);                       /* 0    , 0     ,0      */ \
    Func(UpdateSoftEnumPacket);                    /* 0    , 0     ,0      */ \
    Func(UpdateTradePacket);                       /* 0    , 0     ,0      */ \
    Func(CameraPacket);                            /* 0    , 0     ,0      */ \
    Func(MobArmorEquipmentPacket);                 /* 0    , 0     ,0      */ \
    Func(MobEffectPacket);                         /* 0    , 0     ,0      */ \
    Func(MoveActorAbsolutePacket);                 /* 0    , 0     ,0      */ \
    Func(NetworkStackLatencyPacket);               /* 0    , 0     ,0      */ \
    Func(NpcRequestPacket);                        /* 0    , 0     ,0      */ \
    Func(OnScreenTextureAnimationPacket);          /* 0    , 0     ,0      */ \
    Func(PacketViolationWarningPacket);            /* 0    , 0     ,0      */ \
    Func(PhotoTransferPacket);                     /* 0    , 0     ,0      */ \
    Func(PlaySoundPacket);                         /* 0    , 0     ,0      */ \
    Func(AnvilDamagePacket);                       /* 0    , 0     ,0      */ \
    Func(BlockEventPacket);                        /* 0    , 0     ,0      */ \
    Func(BookEditPacket);                          /* 0    , 0     ,0      */ \
    Func(BossEventPacket);                         /* 0    , 0     ,0      */ \
    Func(ClientboundMapItemDataPacket);            /* 0    , 0     ,0      */ \
    Func(CommandBlockUpdatePacket);                /* 0    , 0     ,0      */ \
    Func(CompletedUsingItemPacket);                /* 0    , 0     ,0      */ \
    Func(ContainerSetDataPacket);                  /* 0    , 0     ,0      */ \
    Func(CraftingEventPacket);                     /* 0    , 0     ,0      */ \
    Func(DebugInfoPacket);                         /* 0    , 0     ,0      */ \
    Func(EducationSettingsPacket);                 /* 0    , 0     ,0      */ \
    Func(EmoteListPacket);                         /* 0    , 0     ,0      */ \
    Func(EmotePacket);                             /* 0    , 0     ,0      */ \
    Func(HurtArmorPacket);                         /* 0    , 0     ,0      */ \
    Func(ItemFrameDropItemPacket);                 /* 0    , 0     ,0      */ \
    Func(LabTablePacket);                          /* 0    , 0     ,0      */ \
    Func(LecternUpdatePacket);                     /* 0    , 0     ,0      */ \
    Func(LevelEventGenericPacket);                 /* 0    , 0     ,0      */ \
    Func(PlayerEnchantOptionsPacket);              /* 0    , 0     ,0      */ \
    Func(PlayerInputPacket);                       /* 0    , 0     ,0      */ \
    Func(PlayerSkinPacket);                        /* 0    , 0     ,0      */ \
    Func(PositionTrackingDBClientRequestPacket);   /* 0    , 0     ,0      */ \
    Func(PositionTrackingDBServerBroadcastPacket); /* 0    , 0     ,0      */ \
    Func(PurchaseReceiptPacket);                   /* 0    , 0     ,0      */ \
    Func(ResourcePackChunkDataPacket);             /* 0    , 0     ,0      */ \
    Func(ResourcePackChunkRequestPacket);          /* 0    , 0     ,0      */ \
    Func(ResourcePackDataInfoPacket);              /* 0    , 0     ,0      */ \
    Func(ScriptCustomEventPacket);                 /* 0    , 0     ,0      */ \
    Func(CreatePhotoPacket);                       /* 0    , 0     ,0      */ \
    Func(EduUriResourcePacket);                    /* 0    , 0     ,0      */ \
    Func(NpcDialoguePacket);                       /* 0    , 0     ,0      */ \
    Func(SimulationTypePacket);                    /* 0    , 0     ,0      */ \
    Func(AddVolumeEntityPacket);                   /* 0    , 0     ,0      */ \
    Func(AnimateEntityPacket);                     /* 0    , 0     ,0      */ \
    Func(CameraShakePacket);                       /* 0    , 0     ,0      */ \
    Func(CodeBuilderSourcePacket);                 /* 0    , 0     ,0      */ \
    Func(ClientboundDebugRendererPacket);          /* 0    , 0     ,0      */ \
    Func(CorrectPlayerMovePredictionPacket);       /* 0    , 0     ,0      */ \
    Func(PlayerStartItemCooldownPacket);           /* 0    , 0     ,0      */ \
    Func(ScriptMessagePacket);                     /* 0    , 0     ,0      */ \
    Func(SetDisplayObjectivePacket);               /* 0    , 0     ,0      */ \
    Func(SetScorePacket);                          /* 0    , 0     ,0      */ \
    Func(SetScoreboardIdentityPacket);             /* 0    , 0     ,0      */ \
    Func(SetTitlePacket);                          /* 0    , 0     ,0      */ \
    Func(ShowCreditsPacket);                       /* 0    , 0     ,0      */ \
    Func(ShowStoreOfferPacket);                    /* 0    , 0     ,0      */ \
    Func(SpawnExperienceOrbPacket);                /* 0    , 0     ,0      */ \
    Func(SpawnParticleEffectPacket);               /* 0    , 0     ,0      */ \
    Func(StructureBlockUpdatePacket);              /* 0    , 0     ,0      */ \
    Func(StructureTemplateDataRequestPacket);      /* 0    , 0     ,0      */ \
    Func(SubClientLoginPacket);                    /* 0    , 0     ,0      */ \
    Func(SimpleEventPacket);                       /* 1    , 1     ,0      */ \
    Func(AddBehaviorTreePacket);                   /* 1    , 1     ,0      */ \
    Func(AvailableActorIdentifiersPacket);         /* 1    , 1     ,0      */ \
    Func(AvailableCommandsPacket);                 /* 1    , 1     ,0      */ \
    Func(BiomeDefinitionListPacket);               /* 1    , 1     ,0      */ \
    Func(CraftingDataPacket);                      /* 1    , 1     ,0      */ \
    Func(CreativeContentPacket);                   /* 1    , 1     ,0      */ \
    Func(GameRulesChangedPacket);                  /* 1    , 1     ,0      */ \
    Func(ResourcePackStackPacket);                 /* 1    , 1     ,0      */ \
    Func(ResourcePacksInfoPacket);                 /* 1    , 1     ,0      */ \
    Func(ItemComponentPacket);                     /* 1    , 1     ,0      */ \
    Func(SetSpawnPositionPacket);                  /* 1    , 1     ,0      */ \
    Func(StartGamePacket);                         /* 1    , 1     ,0      */ \
    Func(PlayerFogPacket);                         /* 1    , 1     ,0      */ \
    Func(AddPlayerPacket);                         /* 1    , 1     ,0      */ \
    Func(LoginPacket);                             /* 1    , 0     ,1      */ \
    Func(BlockPickRequestPacket);                  /* 1    , 0     ,1      */ \
    Func(DisconnectPacket);                        /* 1    , 1     ,0      */ \
    Func(GuiDataPickItemPacket);                   /* 1    , 1     ,0      */ \
    Func(SetLocalPlayerAsInitializedPacket);       /* 1    , 0     ,1      */ \
    Func(TextPacket);                              /* 2    , 2     ,0      */ \
    Func(PlayerListPacket);                        /* 2    , 2     ,0      */ \
    Func(PlayStatusPacket);                        /* 2    , 2     ,0      */ \
    Func(ClientCacheStatusPacket);                 /* 2    , 1     ,1      */ \
    Func(SetDifficultyPacket);                     /* 2    , 2     ,0      */ \
    Func(ChangeDimensionPacket);                   /* 2    , 2     ,0      */ \
    Func(ResourcePackClientResponsePacket);        /* 2    , 0     ,2      */ \
    Func(SetActorLinkPacket);                      /* 2    , 2     ,0      */ \
    Func(UpdatePlayerGameTypePacket);              /* 2    , 2     ,0      */ \
    Func(RespawnPacket);                           /* 3    , 3     ,0      */ \
    Func(TakeItemActorPacket);                     /* 3    , 3     ,0      */ \
    Func(PlayerHotbarPacket);                      /* 3    , 3     ,0      */ \
    Func(CommandOutputPacket);                     /* 3    , 3     ,0      */ \
    Func(TickSyncPacket);                          /* 4    , 2     ,2      */ \
    Func(CommandRequestPacket);                    /* 4    , 0     ,4      */ \
    Func(ContainerOpenPacket);                     /* 4    , 4     ,0      */ \
    Func(ContainerClosePacket);                    /* 8    , 4     ,4      */ \
    Func(InventoryContentPacket);                  /* 9    , 9     ,0      */ \
    Func(ServerSettingsResponsePacket);            /* 10   , 3     ,7      */ \
    Func(InventorySlotPacket);                     /* 12   , 12    ,0      */ \
    Func(UpdateBlockSyncedPacket);                 /* 17   , 17    ,0      */ \
    Func(PlayerActionPacket);                      /* 25   , 0     ,25     */ \
    Func(ItemStackRequestPacket);                  /* 27   , 0     ,27     */ \
    Func(ItemStackResponsePacket);                 /* 27   , 27    ,0      */ \
    Func(AdventureSettingsPacket);                 /* 42   , 2     ,40     */ \
    Func(BlockActorDataPacket);                    /* 42   , 42    ,0      */ \
    Func(EventPacket);                             /* 45   , 45    ,0      */ \
    Func(SetHealthPacket);                         /* 51   , 50    ,1      */ \
    Func(MobEquipmentPacket);                      /* 68   , 5     ,63     */ \
    Func(MotionPredictionHintsPacket);             /* 101  , 101   ,0      */ \
    Func(AddItemActorPacket);                      /* 149  , 149   ,0      */ \
    Func(UpdateAttributesPacket);                  /* 155  , 155   ,0      */ \
    Func(InteractPacket);                          /* 202  , 0     ,202    */ \
    Func(ActorEventPacket);                        /* 248  , 248   ,0      */ \
    Func(LevelEventPacket);                        /* 253  , 253   ,0      */ \
    Func(NetworkChunkPublisherUpdatePacket);       /* 315  , 315   ,0      */ \
    Func(AnimatePacket);                           /* 398  , 2     ,396    */ \
    Func(InventoryTransactionPacket);              /* 439  , 4     ,435    */ \
    Func(AddActorPacket);                          /* 459  , 459   ,0      */ \
    Func(MapInfoRequestPacket);                    /* 607  , 607   ,0      */ \
    Func(UpdateSubChunkBlocksPacket);              /* 758  , 758   ,0      */ \
    Func(SetActorMotionPacket);                    /* 894  , 894   ,0      */ \
    Func(LevelSoundEventPacket);                   /* 1187 , 627   ,560    */ \
    Func(SubChunkPacket);                          /* 2114 , 2114  ,0      */ \
    Func(SubChunkRequestPacket);                   /* 2114 , 0     ,2114   */ \
    Func(ClientCacheMissResponsePacket);           /* 2277 , 2277  ,0      */ \
    Func(ClientCacheBlobStatusPacket);             /* 2277 , 0     ,2277   */ \
    Func(LevelChunkPacket);                        /* 7153 , 7153  ,0      */ \
    Func(SetActorDataPacket);                      /* 9375 , 9375  ,0      */ \
    Func(UpdateBlockPacket);                       /* 12095, 12095 ,0      */ \
    Func(MoveActorDeltaPacket);                    /* 28931, 28931 ,0      */ \
    Func(MovePlayerPacket);                        /* 57189, 56755 ,434    */ \
    Func(PlayerAuthInputPacket);                   /* 69201, 0     ,69201  */ \

#define DISABLE_FOR_EACH\


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

void regCmd();

template <typename T, uint64_t hash>
void onPacketWrite(std::string const& type)
{
    regCmd();
    if (!LogSwitch) return;
    writeTimes<T> ++;
    auto newTime = time(0);
    if (hash != lastWriteHash)
    {
        lastWriteHash = hash;
        if ((writeTimes<T>) > 1000)
            return;
        logger.warn(">> {}", type);
    }
    //if (newTime - lastLogWriteTime<T> - minInterval > 0)
    //{
    //    logger.warn("{}::write", type);
    //    lastLogWriteTime<T> = newTime;
    //}
}
template <typename T, uint64_t hash>
void onPacketRead(std::string const& type)
{
    regCmd();
    if (!LogSwitch) return;
    readTimes<T> ++;
    auto newTime = time(0);
    if (hash != lastReadHash)
    {
        lastReadHash = hash;
        if ((readTimes<T>) > 1000)
            return;
        logger.warn("<< {}", type);
    }
}

#define HookPacketWrite(packetType)                                  \
    THook(void, "?write@" #packetType "@@UEBAXAEAVBinaryStream@@@Z", \
          class packetType& packet, class BinaryStream& bs)          \
    {                                                                \
        if (isHooking)                                               \
            return original(packet, bs);                             \
        isHooking = true;                                            \
        onPacketWrite<packetType, do_hash(#packetType)>(#packetType);                      \
        original(packet, bs);                                        \
        isHooking = false;                                           \
    }

#define HookPacketRead(packetType)                                  \
    THook(void, "?_read@" #packetType "@@EEAA?AW4StreamReadResult@@AEAVReadOnlyBinaryStream@@@Z", \
          class packetType& packet, class BinaryStream& bs)          \
    {                                                                \
        if (isHooking)                                               \
            return original(packet, bs);                             \
        isHooking = true;                                            \
        onPacketRead<packetType, do_hash(#packetType)>(#packetType);                      \
        original(packet, bs);                                        \
        isHooking = false;                                           \
    }


ForEachPacket(HookPacketWrite);
ForEachPacket(HookPacketRead);
#define LogPacketTimes(packet) logger.warn("{:4},{:4},{}", writeTimes<packet> ,readTimes<packet>, #packet)

void logPacketTimes()
{
    ForEachPacket(LogPacketTimes);
}

#include <MC/DataItem.hpp>
std::unordered_map<ActorDataIDs, std::set<DataItemType>> idTypeMap;

inline void logDataIdType(DataItem const& item)
{
    auto id = (ActorDataIDs)item.mId;
    auto iter = idTypeMap.find(id);
    //if (magic_enum::enum_name(id).empty())
    //    ASSERT(false);
    if (iter == idTypeMap.end())
        idTypeMap.emplace(id, std::set<DataItemType>{item.mType});
    else
        iter->second.emplace(item.mType);
}

THook(void, "?write@?$serialize@VDataItem@@@@SAXAEBVDataItem@@AEAVBinaryStream@@@Z",
      class DataItem const& dataItem, class BinaryStream& bs)
{
    logDataIdType(dataItem);
    original(dataItem, bs);
}
THook(std::unique_ptr<class DataItem>&, "?read@?$serialize@V?$unique_ptr@VDataItem@@U?$default_delete@VDataItem@@@std@@@std@@@@SA?AV?$unique_ptr@VDataItem@@U?$default_delete@VDataItem@@@std@@@std@@AEAVReadOnlyBinaryStream@@@Z",
      std::unique_ptr<class DataItem>& res, class ReadOnlyBinaryStream& bs)
{
    auto& rtn = original(res, bs);
    logDataIdType(*rtn);
    return rtn;
}
#include <ScheduleAPI.h>
bool Switch = false;

//THook(__int64, "??2@YAPEAX_K@Z", void* a)
//{
//    return original(a);
//}
template <typename T>
inline void* VFTABLE_ADDR;
template <typename T>
void* getVftableAddr()
{
    static bool inited = ([]() {
#define INIT_ADDR(type)\
        VFTABLE_ADDR<class type> = dlsym_real("??_7" #type "@@6B@");
        ForEachPacket(INIT_ADDR);
        return true;
        })();
    return VFTABLE_ADDR<T>;
}

std::string getClassName(Packet* packet)
{
#define RETURN_IF_FIND(type)                           \
    if (getVftableAddr<class type>() == *(void**)packet) \
        return #type;
    ForEachPacket(RETURN_IF_FIND);
    return "";
}

#include <MC/MinecraftPackets.hpp>
class PacketCommand : public Command
{
    virtual void execute(class CommandOrigin const& origin, class CommandOutput& output) const override
    {
        LogSwitch = !LogSwitch;
        logPacketTimes();
        output.success(fmt::format("§eSize of idTypeMap: {}", idTypeMap.size()));
        for (auto& [id, type] : idTypeMap) {
            auto key = fmt::format("{},{}", magic_enum::enum_name(id), (int)id);
            std::string types = "";
            for (auto t : type)
            { 
                types += fmt::format("{},{},", magic_enum::enum_name(t), (int)t); 
            }
            output.success(fmt::format("{},{}", key, types));
        }
        int packetId = 0;
        while (packetId<200)
        {
            auto packet = MinecraftPackets::createPacket(packetId);
            if (packet)
            {
                auto size = _msize((void**)packet.get() - 2);
                //logger.warn("Packet: {},{},{},{},{}", magic_enum::enum_name((MinecraftPacketIds)packetId), packet->getName(), getClassName(packet.get()), packetId, size);

                auto className = getClassName(packet.get());
                //className.erase(className.find_last_of("Packet") - 5, 6);
                //logger.warn("{} = 0x{:02X},", className, packetId);

                //logger.info("static_assert(sizeof({}) == 0x{:X}, \"size of {} should be {}\");", className, size-16, className, size-16);

                logger.info("#include <MC/{}.hpp>", className);
            }
            packetId++;
        }
        if (auto player = Command::getPlayerFromOrigin(origin))
        {
            static std::vector<std::string> actorTypes= Global<CommandRegistry>->getEnumValues("EntityType");;
            static size_t index = 0;
            static ScheduleTask task = Schedule::repeat(
                [=]() {
                    if (index == actorTypes.size())
                    {
                        player->sendText("task.cancel()");
                        const_cast<ScheduleTask&>(task).cancel();
                        return;
                    }
                    player->sendText("§e Summon " + actorTypes.at(index++));
                    player->runcmd(fmt::format("summon {}", actorTypes.at(index++)));
                },
                20);
        }
    };

public:
    static void setup(CommandRegistry& registry)
    {
        registry.registerCommand("packet", "Show Packet", CommandPermissionLevel::Any, {(CommandFlagValue)0}, {(CommandFlagValue)0x80});
        registry.registerOverload<PacketCommand>("packet");
    }
};
#include <DynamicCommandAPI.h>
#include <MC/SimulatedPlayer.hpp>

using Result = DynamicCommand::Result;
using ParamType = DynamicCommand::ParameterType;
using ParamPtr = DynamicCommand::ParameterPtr;
using ParamData = DynamicCommand::ParameterData;
using ParamIndex = DynamicCommandInstance::ParameterIndex;
constexpr auto AutoExpandOption = CommandParameterOption::EnumAutocompleteExpansion;

void regCmd()
{
    if (!Global<CommandRegistry> || !Global<Level>)
        return;
    static bool reg = false;
    if (reg)
        return;
    Schedule::nextTick([]() {
        PacketCommand::setup(*Global<CommandRegistry>);
        auto cmd = DynamicCommand::createCommand("fpc", "fake player controller");
        cmd->setEnum("ActionMove", {"move"});

        cmd->mandatory("player", ParamType::Player);
        cmd->mandatory("action", ParamType::Enum, "ActionMove", AutoExpandOption);
        cmd->mandatory("dir", ParamType::Vec3);

        cmd->addOverload("ActionMove", "dir");

        cmd->setCallback([](DynamicCommand const& cmd, CommandOrigin const& origin, CommandOutput& output, std::unordered_map<std::string, Result>& results) {
            auto players = results["player"].get<std::vector<Player*>>();
            switch (do_hash(results["direction"].getRaw<std::string>().c_str()))
            {
                case do_hash("move"):
                    for (auto& player : players)
                    {
                        if (player->isSimulatedPlayer())
                        {
                            ((SimulatedPlayer*)player)->simulateWorldMove(results["dir"].get<Vec3>(), 1.0f);
                            output.success(fmt::format("Move {}", player->getName()));
                        }
                    }
                    break;
                default:
                    break;
            }
        });
        DynamicCommand::setup(std::move(cmd)); 
        });
    reg = !reg;
    return ;
}
//#define SIZE_STATIC_ASSERT
//#define INCLUDE_ALL_PACKET

#include <MC/HungerAttributeDelegate.hpp>
TInstanceHook(void, "?notify@HungerAttributeDelegate@@UEAAX_J@Z",
              HungerAttributeDelegate, __int64 a)
{
    std::cout << a << std::endl;
    original(this, a);
}

#endif // DEBUG
