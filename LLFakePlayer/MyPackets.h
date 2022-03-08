#pragma once
//#include <MC/Packet.hpp>
#include <MC/MinecraftEventing.hpp>
#include <MC/NetworkItemStackDescriptor.hpp>
#include <MC/Block.hpp>
#include <MC/Level.hpp>
#include <MC/BinaryStream.hpp>
#include <MC/ServerNetworkHandler.hpp>

class ReadOnlyBinaryStream;
class BinaryStream;
class ServerPlayer;
enum StreamReadResult;
enum class PacketReliability
{
    Relible,
    RelibleOrdered
};

class Packet
{
public:
    unsigned unk2 = 2;                                                     // 8
    PacketReliability reliableOrdered = PacketReliability::RelibleOrdered; // 12
    unsigned char clientSubId = 0;                                         // 16
    uint64_t unk24 = 0;                                                    // 24
    uint64_t unk40 = 0;                                                    // 32
    uint32_t incompressible = 0;                                           // 40

    inline Packet(unsigned compress)
        : incompressible(!compress)
    {
    }
    inline Packet()
    {
    }
    class Packet& operator=(class Packet const&) = delete;
    Packet(class Packet const&) = delete;

    inline ServerPlayer* getPlayerFromPacket(ServerNetworkHandler* handler, NetworkIdentifier* netId)
    {
        return handler->getServerPlayer(*netId, dAccess<char>(this, 16));
    }
    inline enum StreamReadResult read(class ReadOnlyBinaryStream& binaryStream)
    {
        return _read(binaryStream);
    }

    std::string toDebugString()
    {
        return fmt::format("{}({})", getName(), getId(), clientSubId);
    }

public:
    /*0*/ virtual ~Packet();
    /*1*/ virtual enum MinecraftPacketIds getId() const = 0;
    /*2*/ virtual std::string getName() const = 0;
    /*3*/ virtual void write(class BinaryStream&) const = 0;
    /*4*/ virtual struct ExtendedStreamReadResult readExtended(class ReadOnlyBinaryStream&);
    /*5*/ virtual bool disallowBatching() const;
    /*6*/ virtual enum StreamReadResult _read(class ReadOnlyBinaryStream&) = 0;
};

class ChangeDimensionPacket : public Packet
{
public:
    AutomaticID<Dimension, int> mDimensionId;
    Vec3 mPosition;
    bool mRespawn;

public:
    /*0*/ virtual ~ChangeDimensionPacket();
    /*1*/ virtual enum MinecraftPacketIds getId() const;
    /*2*/ virtual std::string getName() const;
    /*3*/ virtual void write(class BinaryStream&) const;
    /*6*/ virtual enum StreamReadResult _read(class ReadOnlyBinaryStream&);
    MCAPI ChangeDimensionPacket(class AutomaticID<class Dimension, int>, class Vec3, bool);
    MCAPI ChangeDimensionPacket();
};

class ChunkRadiusUpdatedPacket : public Packet
{
public:
    /*0*/ virtual ~ChunkRadiusUpdatedPacket();
    /*1*/ virtual enum MinecraftPacketIds getId() const;
    /*2*/ virtual std::string getName() const;
    /*3*/ virtual void write(class BinaryStream&) const;
    /*6*/ virtual enum StreamReadResult _read(class ReadOnlyBinaryStream&);

    MCAPI ChunkRadiusUpdatedPacket(int);
    MCAPI ChunkRadiusUpdatedPacket();
};

static_assert(sizeof(NetworkItemStackDescriptor) == 128);

class CraftingEventPacket : public Packet
{
public:
    unsigned char mScreenID;                              //48
    unsigned int mCraftingType;                           //52
    mce::UUID mRecipeUUID;                                //56
    std::vector<NetworkItemStackDescriptor> mInputItems;  //72
    std::vector<NetworkItemStackDescriptor> mOutputItems; //96

public:
    /*0*/ virtual ~CraftingEventPacket();
    /*1*/ virtual enum MinecraftPacketIds getId() const;
    /*2*/ virtual std::string getName() const;
    /*3*/ virtual void write(class BinaryStream&) const;
    /*6*/ virtual enum StreamReadResult _read(class ReadOnlyBinaryStream&);
    MCAPI CraftingEventPacket();
};

enum EventType : int
{
    ACHIEVEMENT_AWARDED,
    ENTITY_INTERACT,
    PORTAL_BUILT,
    PORTAL_USED,
    MOB_KILLED,
    CAULDRON_USED,
    PLAYER_DEATH,
    BOSS_KILLED,
    AGENT_COMMAND,
    AGENT_CREATED,
    PATTERN_REMOVED,
    SLASH_COMMAND_EXECUTED,
    FISH_BUCKETED,
    MOB_BORN,
    PET_DIED,
    CAULDRON_BLOCK_USED,
    COMPOSTER_BLOCK_USED,
    BELL_BLOCK_USED,
};

class EventPacket : public Packet
{
public:
    struct Data
    {
        EventType mType;
        unsigned char mUsePlayerId; // whether uniqueId is set
        int mInt_8;                 //fromDimensionID in PORTAL_USED Event
        int mInt_12;                //toDimensionID in PORTAL_USED Event
        char filler16[40 - 16];
        std::string unk40;
        std::string unk72;
        std::string unk104;
        std::string unk136;
        std::string unk168;
        std::string unk200;
        std::string unk232;
    }; //size: 264
    enum AgentResult;
    ActorUniqueID mUniqueId;
    Data mData;

public:
    /*0*/ virtual ~EventPacket();
    /*1*/ virtual enum MinecraftPacketIds getId() const;
    /*2*/ virtual std::string getName() const;
    /*3*/ virtual void write(class BinaryStream&) const;
    /*6*/ virtual enum StreamReadResult _read(class ReadOnlyBinaryStream&);

    MCAPI EventPacket(class Player const&, std::string const&);
    MCAPI EventPacket(class Player const&, std::string const&, int);
    MCAPI EventPacket(class Player const&, enum MovementEventType, float, float, float, float, float);
    MCAPI EventPacket(class Player const*, struct EventPacket::Data const&);
    MCAPI EventPacket(class Player const*, std::string const&, int, int, std::string const&);
    MCAPI EventPacket(class Player const*, class Raid const&, bool);
    MCAPI EventPacket(class Player const*, short, unsigned int, short);
    MCAPI EventPacket(class Player const*, int, int, int, int, int);
    MCAPI EventPacket(class Player const*, int, int, enum ActorDamageCause, bool);
    MCAPI EventPacket(class Player const*, int, class gsl::not_null<class Actor const*>);
    MCAPI EventPacket(class Player const*, class Actor const*, class gsl::not_null<class Mob const*>, enum ActorDamageCause, std::string, int, enum ActorType);
    MCAPI EventPacket(class Player const*, class Actor const*, class gsl::not_null<class Mob const*>, enum ActorDamageCause, enum ActorType);
    MCAPI EventPacket(class Player const*, class AutomaticID<class Dimension, int>, class AutomaticID<class Dimension, int>);
    MCAPI EventPacket(class Player const*, class AutomaticID<class Dimension, int>);
    MCAPI EventPacket(class Player const*, class gsl::not_null<class Actor const*>, enum MinecraftEventing::InteractionType);
    MCAPI EventPacket(class Player const*, class gsl::not_null<class Mob const*>);
    MCAPI EventPacket(class Player const*, enum MinecraftEventing::AchievementIds, bool);
    MCAPI EventPacket(class Player const*, enum EventPacket::AgentResult, std::string const&, std::string const&, std::string const&);
    MCAPI EventPacket(class Player const*, enum EventPacket::AgentResult, std::string const&, std::string const&, int);
    MCAPI EventPacket(class Player const*, bool, class Actor const*, class gsl::not_null<class Mob const*>, enum ActorDamageCause);
    MCAPI EventPacket();
    MCAPI class EventPacket& operator=(class EventPacket&&);
};

class ItemStackRequestPacket : public Packet
{
public:
    /*0*/ virtual ~ItemStackRequestPacket();
    /*1*/ virtual enum MinecraftPacketIds getId() const;
    /*2*/ virtual std::string getName() const;
    /*3*/ virtual void write(class BinaryStream&) const;
    /*6*/ virtual enum StreamReadResult _read(class ReadOnlyBinaryStream&);
    MCAPI ItemStackRequestPacket();
    MCAPI class ItemStackRequestBatch const& getRequestBatch() const;
};

class ModalFormRequestPacket : public Packet
{
public:
    int mFormId;
    std::string mData;

public:
    /*0*/ virtual ~ModalFormRequestPacket();
    /*1*/ virtual enum MinecraftPacketIds getId() const;
    /*2*/ virtual std::string getName() const;
    /*3*/ virtual void write(class BinaryStream&) const;
    /*6*/ virtual enum StreamReadResult _read(class ReadOnlyBinaryStream&);
    MCAPI ModalFormRequestPacket();
};

class ModalFormResponsePacket : public Packet
{
public:
    int mFormId;
    std::string mData;

public:
    /*0*/ virtual ~ModalFormResponsePacket();
    /*1*/ virtual enum MinecraftPacketIds getId() const;
    /*2*/ virtual std::string getName() const;
    /*3*/ virtual void write(class BinaryStream&) const;
    /*6*/ virtual enum StreamReadResult _read(class ReadOnlyBinaryStream&);
    MCAPI ModalFormResponsePacket();
};

enum TeleportationCause
{
    UNKNOWN,
    PROJECTILE,
    CHORUS_FRUIT,
    COMMAND,
    BEHAVIOR,
};

class MovePlayerPacket : public Packet
{
public:
    ActorRuntimeID mRuntimeId;
    Vec3 mPosition;
    float mPitch;
    float mYaw;
    float mHeadYaw;
    Player::PositionMode mMode;
    bool mOnGround;
    ActorRuntimeID mRidingRuntimeId;
    TeleportationCause mTeleportationCause;
    int mEntityType;
    long mTick;

public:
    /*0*/ virtual ~MovePlayerPacket();
    /*1*/ virtual enum MinecraftPacketIds getId() const;
    /*2*/ virtual std::string getName() const;
    /*3*/ virtual void write(class BinaryStream&) const;
    /*6*/ virtual enum StreamReadResult _read(class ReadOnlyBinaryStream&);
    MCAPI MovePlayerPacket(class Player const&, class Vec3 const&);
    MCAPI MovePlayerPacket(class Player const&, enum Player::PositionMode, int, int);
    MCAPI MovePlayerPacket();
};

// Refer to https://github.com/LiteLDev/BEProtocolGolang/blob/master/minecraft/protocol/player.go
enum PlayerActionType
{
    StartBreak,
    AbortBreak,
    StopBreak,
    GetUpdatedBlock,
    DropItem,
    StartSleeping,
    StopSleeping,
    Respawn,
    Jump,
    StartSprint,
    StopSprint,
    StartSneak,
    StopSneak,
    CreativePlayerDestroyBlock,
    DimensionChangeDone,
    StartGlide,
    StopGlide,
    BuildDenied,
    CrackBreak,
    ChangeSkin,
    SetEnchantmentSeed,
    StartSwimming,
    StopSwimming,
    StartSpinAttack,
    StopSpinAttack,
    StartBuildingBlock,
    PredictDestroyBlock,
    ContinueDestroyBlock,
};

class PlayerActionPacket : public Packet
{
public:
    BlockPos mPosition;           //48
    FaceID mBlockFace;            //60
    PlayerActionType mActionType; //64
    ActorRuntimeID mRuntimeID;    //72
public:
    /*0*/ virtual ~PlayerActionPacket();
    /*1*/ virtual enum MinecraftPacketIds getId() const;
    /*2*/ virtual std::string getName() const;
    /*3*/ virtual void write(class BinaryStream&) const;
    /*6*/ virtual enum StreamReadResult _read(class ReadOnlyBinaryStream&);
    MCAPI PlayerActionPacket(enum PlayerActionType, class BlockPos const&, unsigned char, class ActorRuntimeID);
    MCAPI PlayerActionPacket(enum PlayerActionType, class BlockPos const&, int, class ActorRuntimeID);
    MCAPI PlayerActionPacket(enum PlayerActionType, class ActorRuntimeID);
    MCAPI PlayerActionPacket();
};

enum PlayStatus : int
{
    PlayStatusLoginSuccess,
    PlayStatusLoginFailedClient,
    PlayStatusLoginFailedServer,
    PlayStatusPlayerSpawn,
    PlayStatusLoginFailedInvalidTenant,
    PlayStatusLoginFailedVanillaEdu,
    PlayStatusLoginFailedEduVanilla,
    PlayStatusLoginFailedServerFull,
};

class PlayStatusPacket : public Packet
{
public:
    PlayStatus status;

public:
    /*0*/ virtual ~PlayStatusPacket();
    /*1*/ virtual enum MinecraftPacketIds getId() const;
    /*2*/ virtual std::string getName() const;
    /*3*/ virtual void write(class BinaryStream&) const;
    /*6*/ virtual enum StreamReadResult _read(class ReadOnlyBinaryStream&);
    MCAPI PlayStatusPacket(enum PlayStatus);
    MCAPI PlayStatusPacket();
};

enum PlayerRespawnState : char
{
    SERVER_SEARCHING = 0,
    SERVER_READY,
    CLIENT_READY,
};

class RespawnPacket : public Packet
{
public:
    Vec3 mRespawnPosition;
    PlayerRespawnState mRespawnState;
    ActorRuntimeID mRuntimeId;

public:
    /*0*/ virtual ~RespawnPacket();
    /*1*/ virtual enum MinecraftPacketIds getId() const;
    /*2*/ virtual std::string getName() const;
    /*3*/ virtual void write(class BinaryStream&) const;
    /*6*/ virtual enum StreamReadResult _read(class ReadOnlyBinaryStream&);
    MCAPI RespawnPacket(class Vec3 const&, enum PlayerRespawnState const&);
    MCAPI RespawnPacket();
};

class ShowCreditsPacket : public Packet
{
public:
    enum CreditsState : int
    {
        START_CREDITS,
        END_CREDITS,
    };
    ActorRuntimeID mRuntimeId;
    CreditsState mState;

public:
    /*0*/ virtual ~ShowCreditsPacket();
    /*1*/ virtual enum MinecraftPacketIds getId() const;
    /*2*/ virtual std::string getName() const;
    /*3*/ virtual void write(class BinaryStream&) const;
    /*6*/ virtual enum StreamReadResult _read(class ReadOnlyBinaryStream&);
    MCAPI ShowCreditsPacket(class ActorRuntimeID, enum ShowCreditsPacket::CreditsState);
    MCAPI ShowCreditsPacket();
};

class StartGamePacket : public Packet
{
public:
    /*0*/ virtual ~StartGamePacket();
    /*1*/ virtual enum MinecraftPacketIds getId() const;
    /*2*/ virtual std::string getName() const;
    /*3*/ virtual void write(class BinaryStream&) const;
    /*6*/ virtual enum StreamReadResult _read(class ReadOnlyBinaryStream&);
    MCAPI StartGamePacket(class LevelSettings const&, struct ActorUniqueID, class ActorRuntimeID, enum GameType, bool, class Vec3 const&, class Vec2 const&, std::string const&, std::string const&, class ContentIdentity const&, class BlockPalette const&, std::string const&, class BlockDefinitionGroup const&, bool, struct PlayerMovementSettings const&, std::string const&, unsigned __int64, int, unsigned __int64);
    MCAPI StartGamePacket();
};

static_assert(offsetof(EventPacket, mData.mType) == 56);
static_assert(offsetof(ShowCreditsPacket, mState) == 56);
static_assert(offsetof(PlayerActionPacket, mActionType) == 64);

inline Vec3 TEST_VEC3 = {12345.0f, 54321.0f, 123456.0f};
template <typename PacketType>
inline void testPacket() = delete;

template <>
inline void testPacket<ChangeDimensionPacket>()
{
    ChangeDimensionPacket pkt(2, TEST_VEC3, false);
    assert(pkt.mDimensionId == 2);
    assert(pkt.mPosition == TEST_VEC3);
    assert(pkt.mRespawn == false);
    ChangeDimensionPacket pkt2(1, TEST_VEC3, true);
    assert(pkt.mDimensionId == 2);
    assert(pkt.mPosition == TEST_VEC3);
    assert(pkt.mRespawn == false);
}

inline void test()
{
    testPacket<ChangeDimensionPacket>();
}

#pragma region Packet Size Static Assert
// copy it to end of includes

// if type T is not complete
template <typename T, size_t size, typename = void>
struct size_or
{
    static constexpr size_t value = size;
};
// if type T is complete
template <typename T, size_t size>
struct size_or<T, size, decltype(void(sizeof(T)))>
{
    static constexpr size_t value = sizeof(T);
};

template <typename T, size_t size>
constexpr size_t size_or_v = size_or<T, size>::value;

// size of T is 48 or size if type T is complete
template <typename T, size_t size>
constexpr bool check_packet_size_v = size_or_v<T, sizeof(Packet)> == size || size_or_v<T, sizeof(Packet)> == sizeof(Packet);

static_assert(check_packet_size_v<class PlayStatusPacket, 0x38>, "size of PlayStatusPacket should be 56 or 48(default)");
static_assert(check_packet_size_v<class ServerToClientHandshakePacket, 0x50>, "size of ServerToClientHandshakePacket should be 80 or 48(default)");
static_assert(check_packet_size_v<class ClientToServerHandshakePacket, 0x30>, "size of ClientToServerHandshakePacket should be 48 or 48(default)");
static_assert(check_packet_size_v<class DisconnectPacket, 0x58>, "size of DisconnectPacket should be 88 or 48(default)");
static_assert(check_packet_size_v<class ResourcePacksInfoPacket, 0x68>, "size of ResourcePacksInfoPacket should be 104 or 48(default)");
static_assert(check_packet_size_v<class ResourcePackStackPacket, 0x128>, "size of ResourcePackStackPacket should be 296 or 48(default)");
static_assert(check_packet_size_v<class ResourcePackClientResponsePacket, 0x48>, "size of ResourcePackClientResponsePacket should be 72 or 48(default)");
static_assert(check_packet_size_v<class TextPacket, 0xD8>, "size of TextPacket should be 216 or 48(default)");
static_assert(check_packet_size_v<class SetTimePacket, 0x38>, "size of SetTimePacket should be 56 or 48(default)");
static_assert(check_packet_size_v<class StartGamePacket, 0x630>, "size of StartGamePacket should be 1584 or 48(default)");
static_assert(check_packet_size_v<class AddPlayerPacket, 0x2E8>, "size of AddPlayerPacket should be 744 or 48(default)");
static_assert(check_packet_size_v<class AddActorPacket, 0x180>, "size of AddActorPacket should be 384 or 48(default)");
static_assert(check_packet_size_v<class RemoveActorPacket, 0x38>, "size of RemoveActorPacket should be 56 or 48(default)");
static_assert(check_packet_size_v<class AddItemActorPacket, 0x100>, "size of AddItemActorPacket should be 256 or 48(default)");
static_assert(check_packet_size_v<class TakeItemActorPacket, 0x40>, "size of TakeItemActorPacket should be 64 or 48(default)");
static_assert(check_packet_size_v<class MoveActorAbsolutePacket, 0x50>, "size of MoveActorAbsolutePacket should be 80 or 48(default)");
static_assert(check_packet_size_v<class MovePlayerPacket, 0x70>, "size of MovePlayerPacket should be 112 or 48(default)");
static_assert(check_packet_size_v<class PassengerJumpPacket, 0x38>, "size of PassengerJumpPacket should be 56 or 48(default)");
static_assert(check_packet_size_v<class UpdateBlockPacket, 0x48>, "size of UpdateBlockPacket should be 72 or 48(default)");
static_assert(check_packet_size_v<class AddPaintingPacket, 0x70>, "size of AddPaintingPacket should be 112 or 48(default)");
static_assert(check_packet_size_v<class TickSyncPacket, 0x40>, "size of TickSyncPacket should be 64 or 48(default)");
static_assert(check_packet_size_v<class LevelSoundEventPacketV1, 0x50>, "size of LevelSoundEventPacketV1 should be 80 or 48(default)");
static_assert(check_packet_size_v<class LevelEventPacket, 0x48>, "size of LevelEventPacket should be 72 or 48(default)");
static_assert(check_packet_size_v<class BlockEventPacket, 0x48>, "size of BlockEventPacket should be 72 or 48(default)");
static_assert(check_packet_size_v<class ActorEventPacket, 0x40>, "size of ActorEventPacket should be 64 or 48(default)");
static_assert(check_packet_size_v<class MobEffectPacket, 0x50>, "size of MobEffectPacket should be 80 or 48(default)");
static_assert(check_packet_size_v<class UpdateAttributesPacket, 0x58>, "size of UpdateAttributesPacket should be 88 or 48(default)");
static_assert(check_packet_size_v<class InventoryTransactionPacket, 0x60>, "size of InventoryTransactionPacket should be 96 or 48(default)");
static_assert(check_packet_size_v<class MobEquipmentPacket, 0xC8>, "size of MobEquipmentPacket should be 200 or 48(default)");
static_assert(check_packet_size_v<class MobArmorEquipmentPacket, 0x238>, "size of MobArmorEquipmentPacket should be 568 or 48(default)");
static_assert(check_packet_size_v<class InteractPacket, 0x50>, "size of InteractPacket should be 80 or 48(default)");
static_assert(check_packet_size_v<class BlockPickRequestPacket, 0x40>, "size of BlockPickRequestPacket should be 64 or 48(default)");
static_assert(check_packet_size_v<class ActorPickRequestPacket, 0x40>, "size of ActorPickRequestPacket should be 64 or 48(default)");
static_assert(check_packet_size_v<class PlayerActionPacket, 0x50>, "size of PlayerActionPacket should be 80 or 48(default)");
static_assert(check_packet_size_v<class HurtArmorPacket, 0x40>, "size of HurtArmorPacket should be 64 or 48(default)");
static_assert(check_packet_size_v<class SetActorDataPacket, 0x58>, "size of SetActorDataPacket should be 88 or 48(default)");
static_assert(check_packet_size_v<class SetActorMotionPacket, 0x48>, "size of SetActorMotionPacket should be 72 or 48(default)");
static_assert(check_packet_size_v<class SetActorLinkPacket, 0x50>, "size of SetActorLinkPacket should be 80 or 48(default)");
static_assert(check_packet_size_v<class SetHealthPacket, 0x38>, "size of SetHealthPacket should be 56 or 48(default)");
static_assert(check_packet_size_v<class SetSpawnPositionPacket, 0x50>, "size of SetSpawnPositionPacket should be 80 or 48(default)");
static_assert(check_packet_size_v<class AnimatePacket, 0x40>, "size of AnimatePacket should be 64 or 48(default)");
static_assert(check_packet_size_v<class RespawnPacket, 0x48>, "size of RespawnPacket should be 72 or 48(default)");
static_assert(check_packet_size_v<class ContainerOpenPacket, 0x48>, "size of ContainerOpenPacket should be 72 or 48(default)");
static_assert(check_packet_size_v<class ContainerClosePacket, 0x38>, "size of ContainerClosePacket should be 56 or 48(default)");
static_assert(check_packet_size_v<class PlayerHotbarPacket, 0x38>, "size of PlayerHotbarPacket should be 56 or 48(default)");
static_assert(check_packet_size_v<class InventoryContentPacket, 0x50>, "size of InventoryContentPacket should be 80 or 48(default)");
static_assert(check_packet_size_v<class InventorySlotPacket, 0xB8>, "size of InventorySlotPacket should be 184 or 48(default)");
static_assert(check_packet_size_v<class ContainerSetDataPacket, 0x40>, "size of ContainerSetDataPacket should be 64 or 48(default)");
static_assert(check_packet_size_v<class CraftingDataPacket, 0x98>, "size of CraftingDataPacket should be 152 or 48(default)");
static_assert(check_packet_size_v<class CraftingEventPacket, 0x78>, "size of CraftingEventPacket should be 120 or 48(default)");
static_assert(check_packet_size_v<class GuiDataPickItemPacket, 0x78>, "size of GuiDataPickItemPacket should be 120 or 48(default)");
static_assert(check_packet_size_v<class AdventureSettingsPacket, 0x50>, "size of AdventureSettingsPacket should be 80 or 48(default)");
static_assert(check_packet_size_v<class BlockActorDataPacket, 0x58>, "size of BlockActorDataPacket should be 88 or 48(default)");
static_assert(check_packet_size_v<class PlayerInputPacket, 0x40>, "size of PlayerInputPacket should be 64 or 48(default)");
static_assert(check_packet_size_v<class LevelChunkPacket, 0x88>, "size of LevelChunkPacket should be 136 or 48(default)");
static_assert(check_packet_size_v<class SetCommandsEnabledPacket, 0x38>, "size of SetCommandsEnabledPacket should be 56 or 48(default)");
static_assert(check_packet_size_v<class SetDifficultyPacket, 0x38>, "size of SetDifficultyPacket should be 56 or 48(default)");
static_assert(check_packet_size_v<class ChangeDimensionPacket, 0x48>, "size of ChangeDimensionPacket should be 72 or 48(default)");
static_assert(check_packet_size_v<class SetPlayerGameTypePacket, 0x38>, "size of SetPlayerGameTypePacket should be 56 or 48(default)");
static_assert(check_packet_size_v<class PlayerListPacket, 0x50>, "size of PlayerListPacket should be 80 or 48(default)");
static_assert(check_packet_size_v<class SimpleEventPacket, 0x38>, "size of SimpleEventPacket should be 56 or 48(default)");
static_assert(check_packet_size_v<class EventPacket, 0x140>, "size of EventPacket should be 320 or 48(default)");
static_assert(check_packet_size_v<class SpawnExperienceOrbPacket, 0x40>, "size of SpawnExperienceOrbPacket should be 64 or 48(default)");
static_assert(check_packet_size_v<class ClientboundMapItemDataPacket, 0xB8>, "size of ClientboundMapItemDataPacket should be 184 or 48(default)");
static_assert(check_packet_size_v<class MapInfoRequestPacket, 0x38>, "size of MapInfoRequestPacket should be 56 or 48(default)");
static_assert(check_packet_size_v<class RequestChunkRadiusPacket, 0x38>, "size of RequestChunkRadiusPacket should be 56 or 48(default)");
static_assert(check_packet_size_v<class ChunkRadiusUpdatedPacket, 0x38>, "size of ChunkRadiusUpdatedPacket should be 56 or 48(default)");
static_assert(check_packet_size_v<class ItemFrameDropItemPacket, 0x40>, "size of ItemFrameDropItemPacket should be 64 or 48(default)");
static_assert(check_packet_size_v<class GameRulesChangedPacket, 0x48>, "size of GameRulesChangedPacket should be 72 or 48(default)");
static_assert(check_packet_size_v<class CameraPacket, 0x40>, "size of CameraPacket should be 64 or 48(default)");
static_assert(check_packet_size_v<class BossEventPacket, 0x80>, "size of BossEventPacket should be 128 or 48(default)");
static_assert(check_packet_size_v<class ShowCreditsPacket, 0x40>, "size of ShowCreditsPacket should be 64 or 48(default)");
static_assert(check_packet_size_v<class AvailableCommandsPacket, 0xC0>, "size of AvailableCommandsPacket should be 192 or 48(default)");
static_assert(check_packet_size_v<class CommandRequestPacket, 0x98>, "size of CommandRequestPacket should be 152 or 48(default)");
static_assert(check_packet_size_v<class CommandBlockUpdatePacket, 0xB0>, "size of CommandBlockUpdatePacket should be 176 or 48(default)");
static_assert(check_packet_size_v<class CommandOutputPacket, 0xA0>, "size of CommandOutputPacket should be 160 or 48(default)");
static_assert(check_packet_size_v<class UpdateTradePacket, 0x90>, "size of UpdateTradePacket should be 144 or 48(default)");
static_assert(check_packet_size_v<class UpdateEquipPacket, 0x58>, "size of UpdateEquipPacket should be 88 or 48(default)");
static_assert(check_packet_size_v<class ResourcePackDataInfoPacket, 0x88>, "size of ResourcePackDataInfoPacket should be 136 or 48(default)");
static_assert(check_packet_size_v<class ResourcePackChunkDataPacket, 0x78>, "size of ResourcePackChunkDataPacket should be 120 or 48(default)");
static_assert(check_packet_size_v<class ResourcePackChunkRequestPacket, 0x58>, "size of ResourcePackChunkRequestPacket should be 88 or 48(default)");
static_assert(check_packet_size_v<class TransferPacket, 0x58>, "size of TransferPacket should be 88 or 48(default)");
static_assert(check_packet_size_v<class PlaySoundPacket, 0x68>, "size of PlaySoundPacket should be 104 or 48(default)");
static_assert(check_packet_size_v<class StopSoundPacket, 0x58>, "size of StopSoundPacket should be 88 or 48(default)");
static_assert(check_packet_size_v<class SetTitlePacket, 0xA8>, "size of SetTitlePacket should be 168 or 48(default)");
static_assert(check_packet_size_v<class AddBehaviorTreePacket, 0x50>, "size of AddBehaviorTreePacket should be 80 or 48(default)");
static_assert(check_packet_size_v<class StructureBlockUpdatePacket, 0xF0>, "size of StructureBlockUpdatePacket should be 240 or 48(default)");
static_assert(check_packet_size_v<class ShowStoreOfferPacket, 0x78>, "size of ShowStoreOfferPacket should be 120 or 48(default)");
static_assert(check_packet_size_v<class PurchaseReceiptPacket, 0x48>, "size of PurchaseReceiptPacket should be 72 or 48(default)");
static_assert(check_packet_size_v<class PlayerSkinPacket, 0x2E8>, "size of PlayerSkinPacket should be 744 or 48(default)");
static_assert(check_packet_size_v<class SubClientLoginPacket, 0x38>, "size of SubClientLoginPacket should be 56 or 48(default)");
static_assert(check_packet_size_v<class AutomationClientConnectPacket, 0x50>, "size of AutomationClientConnectPacket should be 80 or 48(default)");
static_assert(check_packet_size_v<class SetLastHurtByPacket, 0x38>, "size of SetLastHurtByPacket should be 56 or 48(default)");
static_assert(check_packet_size_v<class BookEditPacket, 0xA0>, "size of BookEditPacket should be 160 or 48(default)");
static_assert(check_packet_size_v<class NpcRequestPacket, 0x88>, "size of NpcRequestPacket should be 136 or 48(default)");
static_assert(check_packet_size_v<class PhotoTransferPacket, 0xC0>, "size of PhotoTransferPacket should be 192 or 48(default)");
static_assert(check_packet_size_v<class ModalFormRequestPacket, 0x58>, "size of ModalFormRequestPacket should be 88 or 48(default)");
static_assert(check_packet_size_v<class ModalFormResponsePacket, 0x58>, "size of ModalFormResponsePacket should be 88 or 48(default)");
static_assert(check_packet_size_v<class ServerSettingsRequestPacket, 0x30>, "size of ServerSettingsRequestPacket should be 48 or 48(default)");
static_assert(check_packet_size_v<class ServerSettingsResponsePacket, 0x58>, "size of ServerSettingsResponsePacket should be 88 or 48(default)");
static_assert(check_packet_size_v<class ShowProfilePacket, 0x50>, "size of ShowProfilePacket should be 80 or 48(default)");
static_assert(check_packet_size_v<class SetDefaultGameTypePacket, 0x38>, "size of SetDefaultGameTypePacket should be 56 or 48(default)");
static_assert(check_packet_size_v<class RemoveObjectivePacket, 0x50>, "size of RemoveObjectivePacket should be 80 or 48(default)");
static_assert(check_packet_size_v<class SetDisplayObjectivePacket, 0xB8>, "size of SetDisplayObjectivePacket should be 184 or 48(default)");
static_assert(check_packet_size_v<class SetScorePacket, 0x50>, "size of SetScorePacket should be 80 or 48(default)");
static_assert(check_packet_size_v<class LabTablePacket, 0x48>, "size of LabTablePacket should be 72 or 48(default)");
static_assert(check_packet_size_v<class UpdateBlockSyncedPacket, 0x58>, "size of UpdateBlockSyncedPacket should be 88 or 48(default)");
static_assert(check_packet_size_v<class MoveActorDeltaPacket, 0x70>, "size of MoveActorDeltaPacket should be 112 or 48(default)");
static_assert(check_packet_size_v<class SetScoreboardIdentityPacket, 0x50>, "size of SetScoreboardIdentityPacket should be 80 or 48(default)");
static_assert(check_packet_size_v<class SetLocalPlayerAsInitializedPacket, 0x38>, "size of SetLocalPlayerAsInitializedPacket should be 56 or 48(default)");
static_assert(check_packet_size_v<class UpdateSoftEnumPacket, 0x70>, "size of UpdateSoftEnumPacket should be 112 or 48(default)");
static_assert(check_packet_size_v<class NetworkStackLatencyPacket, 0x40>, "size of NetworkStackLatencyPacket should be 64 or 48(default)");
static_assert(check_packet_size_v<class ScriptCustomEventPacket, 0x60>, "size of ScriptCustomEventPacket should be 96 or 48(default)");
static_assert(check_packet_size_v<class SpawnParticleEffectPacket, 0x70>, "size of SpawnParticleEffectPacket should be 112 or 48(default)");
static_assert(check_packet_size_v<class AvailableActorIdentifiersPacket, 0x48>, "size of AvailableActorIdentifiersPacket should be 72 or 48(default)");
static_assert(check_packet_size_v<class LevelSoundEventPacketV2, 0x70>, "size of LevelSoundEventPacketV2 should be 112 or 48(default)");
static_assert(check_packet_size_v<class NetworkChunkPublisherUpdatePacket, 0x40>, "size of NetworkChunkPublisherUpdatePacket should be 64 or 48(default)");
static_assert(check_packet_size_v<class BiomeDefinitionListPacket, 0x48>, "size of BiomeDefinitionListPacket should be 72 or 48(default)");
static_assert(check_packet_size_v<class LevelSoundEventPacket, 0x70>, "size of LevelSoundEventPacket should be 112 or 48(default)");
static_assert(check_packet_size_v<class LevelEventGenericPacket, 0x40>, "size of LevelEventGenericPacket should be 64 or 48(default)");
static_assert(check_packet_size_v<class LecternUpdatePacket, 0x48>, "size of LecternUpdatePacket should be 72 or 48(default)");
static_assert(check_packet_size_v<class AddEntityPacket, 0x38>, "size of AddEntityPacket should be 56 or 48(default)");
static_assert(check_packet_size_v<class RemoveEntityPacket, 0x38>, "size of RemoveEntityPacket should be 56 or 48(default)");
static_assert(check_packet_size_v<class ClientCacheStatusPacket, 0x38>, "size of ClientCacheStatusPacket should be 56 or 48(default)");
static_assert(check_packet_size_v<class OnScreenTextureAnimationPacket, 0x38>, "size of OnScreenTextureAnimationPacket should be 56 or 48(default)");
static_assert(check_packet_size_v<class MapCreateLockedCopyPacket, 0x40>, "size of MapCreateLockedCopyPacket should be 64 or 48(default)");
static_assert(check_packet_size_v<class StructureTemplateDataRequestPacket, 0xC8>, "size of StructureTemplateDataRequestPacket should be 200 or 48(default)");
static_assert(check_packet_size_v<class StructureTemplateDataResponsePacket, 0x60>, "size of StructureTemplateDataResponsePacket should be 96 or 48(default)");
static_assert(check_packet_size_v<class ClientCacheBlobStatusPacket, 0x60>, "size of ClientCacheBlobStatusPacket should be 96 or 48(default)");
static_assert(check_packet_size_v<class ClientCacheMissResponsePacket, 0x88>, "size of ClientCacheMissResponsePacket should be 136 or 48(default)");
static_assert(check_packet_size_v<class EducationSettingsPacket, 0x178>, "size of EducationSettingsPacket should be 376 or 48(default)");
static_assert(check_packet_size_v<class EmotePacket, 0x60>, "size of EmotePacket should be 96 or 48(default)");
static_assert(check_packet_size_v<class MultiplayerSettingsPacket, 0x38>, "size of MultiplayerSettingsPacket should be 56 or 48(default)");
static_assert(check_packet_size_v<class SettingsCommandPacket, 0x58>, "size of SettingsCommandPacket should be 88 or 48(default)");
static_assert(check_packet_size_v<class AnvilDamagePacket, 0x40>, "size of AnvilDamagePacket should be 64 or 48(default)");
static_assert(check_packet_size_v<class CompletedUsingItemPacket, 0x38>, "size of CompletedUsingItemPacket should be 56 or 48(default)");
static_assert(check_packet_size_v<class NetworkSettingsPacket, 0x38>, "size of NetworkSettingsPacket should be 56 or 48(default)");
static_assert(check_packet_size_v<class PlayerAuthInputPacket, 0xA8>, "size of PlayerAuthInputPacket should be 168 or 48(default)");
static_assert(check_packet_size_v<class CreativeContentPacket, 0x50>, "size of CreativeContentPacket should be 80 or 48(default)");
static_assert(check_packet_size_v<class PlayerEnchantOptionsPacket, 0x48>, "size of PlayerEnchantOptionsPacket should be 72 or 48(default)");
static_assert(check_packet_size_v<class ItemStackRequestPacket, 0x38>, "size of ItemStackRequestPacket should be 56 or 48(default)");
static_assert(check_packet_size_v<class ItemStackResponsePacket, 0x48>, "size of ItemStackResponsePacket should be 72 or 48(default)");
static_assert(check_packet_size_v<class PlayerArmorDamagePacket, 0x40>, "size of PlayerArmorDamagePacket should be 64 or 48(default)");
static_assert(check_packet_size_v<class CodeBuilderPacket, 0x58>, "size of CodeBuilderPacket should be 88 or 48(default)");
static_assert(check_packet_size_v<class UpdatePlayerGameTypePacket, 0x40>, "size of UpdatePlayerGameTypePacket should be 64 or 48(default)");
static_assert(check_packet_size_v<class EmoteListPacket, 0x50>, "size of EmoteListPacket should be 80 or 48(default)");
static_assert(check_packet_size_v<class PositionTrackingDBServerBroadcastPacket, 0x50>, "size of PositionTrackingDBServerBroadcastPacket should be 80 or 48(default)");
static_assert(check_packet_size_v<class PositionTrackingDBClientRequestPacket, 0x38>, "size of PositionTrackingDBClientRequestPacket should be 56 or 48(default)");
static_assert(check_packet_size_v<class DebugInfoPacket, 0x58>, "size of DebugInfoPacket should be 88 or 48(default)");
static_assert(check_packet_size_v<class PacketViolationWarningPacket, 0x60>, "size of PacketViolationWarningPacket should be 96 or 48(default)");
static_assert(check_packet_size_v<class MotionPredictionHintsPacket, 0x48>, "size of MotionPredictionHintsPacket should be 72 or 48(default)");
static_assert(check_packet_size_v<class AnimateEntityPacket, 0xD8>, "size of AnimateEntityPacket should be 216 or 48(default)");
static_assert(check_packet_size_v<class CameraShakePacket, 0x40>, "size of CameraShakePacket should be 64 or 48(default)");
static_assert(check_packet_size_v<class PlayerFogPacket, 0x48>, "size of PlayerFogPacket should be 72 or 48(default)");
static_assert(check_packet_size_v<class CorrectPlayerMovePredictionPacket, 0x58>, "size of CorrectPlayerMovePredictionPacket should be 88 or 48(default)");
static_assert(check_packet_size_v<class ItemComponentPacket, 0x48>, "size of ItemComponentPacket should be 72 or 48(default)");
static_assert(check_packet_size_v<class FilterTextPacket, 0x58>, "size of FilterTextPacket should be 88 or 48(default)");
static_assert(check_packet_size_v<class ClientboundDebugRendererPacket, 0x88>, "size of ClientboundDebugRendererPacket should be 136 or 48(default)");
static_assert(check_packet_size_v<class SyncActorPropertyPacket, 0x48>, "size of SyncActorPropertyPacket should be 72 or 48(default)");
static_assert(check_packet_size_v<class AddVolumeEntityPacket, 0x100>, "size of AddVolumeEntityPacket should be 256 or 48(default)");
static_assert(check_packet_size_v<class RemoveVolumeEntityPacket, 0x38>, "size of RemoveVolumeEntityPacket should be 56 or 48(default)");
static_assert(check_packet_size_v<class SimulationTypePacket, 0x38>, "size of SimulationTypePacket should be 56 or 48(default)");
static_assert(check_packet_size_v<class NpcDialoguePacket, 0xC0>, "size of NpcDialoguePacket should be 192 or 48(default)");
static_assert(check_packet_size_v<class EduUriResourcePacket, 0x70>, "size of EduUriResourcePacket should be 112 or 48(default)");
static_assert(check_packet_size_v<class CreatePhotoPacket, 0x78>, "size of CreatePhotoPacket should be 120 or 48(default)");
static_assert(check_packet_size_v<class UpdateSubChunkBlocksPacket, 0x70>, "size of UpdateSubChunkBlocksPacket should be 112 or 48(default)");
static_assert(check_packet_size_v<class SubChunkPacket, 0x60>, "size of SubChunkPacket should be 96 or 48(default)");
static_assert(check_packet_size_v<class SubChunkRequestPacket, 0x80>, "size of SubChunkRequestPacket should be 128 or 48(default)");
static_assert(check_packet_size_v<class PlayerStartItemCooldownPacket, 0x58>, "size of PlayerStartItemCooldownPacket should be 88 or 48(default)");
static_assert(check_packet_size_v<class ScriptMessagePacket, 0x70>, "size of ScriptMessagePacket should be 112 or 48(default)");
static_assert(check_packet_size_v<class CodeBuilderSourcePacket, 0x58>, "size of CodeBuilderSourcePacket should be 88 or 48(default)");

#pragma endregion