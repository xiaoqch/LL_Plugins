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
static_assert(sizeof(ChangeDimensionPacket) == 72);
static_assert(sizeof(CraftingEventPacket) == 120);
static_assert(sizeof(EventPacket) == 0x140);
static_assert(sizeof(ModalFormRequestPacket) == 88);
static_assert(sizeof(ModalFormResponsePacket) == 88);
static_assert(sizeof(MovePlayerPacket) == 112);
static_assert(sizeof(PlayerActionPacket) == 80);
static_assert(offsetof(PlayerActionPacket, mActionType) == 64);
static_assert(sizeof(PlayStatusPacket) == 56);
static_assert(sizeof(RespawnPacket) == 72);

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

