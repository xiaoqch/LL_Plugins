#pragma once
#include <Global.h>

#include <MC/Level.hpp>
#include <MC/Dimension.hpp>
#include <MC/LevelChunk.hpp>
#include <MC/BlockSource.hpp>
#include <MC/ChunkViewSource.hpp>
#include <MC/Block.hpp>

enum MaterialType;

class Material
{

public:
    MaterialType mType;        // 0
    bool mFlammable;           // 4
    bool mNeverBuildable;      // 5
    bool mAlwaysDestroyable;   // 6
    bool mReplaceable;         // 7
    bool mLiquid;              // 8
    float mTranslucency;       // 12
    bool mBlocksMotion;        // 16
    bool mBlocksPrecipitation; // 17
    bool mSolid;               // 18
    bool mSuperHot;            // 18

    inline static std::vector<std::unique_ptr<Material>> const& getAll()
    {
        return mMaterials;
    }

public:
    MCAPI bool getBlocksMotion() const;
    MCAPI bool getBlocksPrecipitation() const;
    MCAPI float getTranslucency() const;
    MCAPI bool isAlwaysDestroyable() const;
    MCAPI bool isFlammable() const;
    MCAPI bool isLiquid() const;
    MCAPI bool isReplaceable() const;
    MCAPI bool isSolid() const;
    MCAPI bool isSolidBlocking() const;
    MCAPI bool isSuperHot() const;
    MCAPI bool isTopSolid(bool, bool) const;
    MCAPI bool isType(enum MaterialType) const;
    MCAPI bool operator!=(class Material const&) const;
    MCAPI bool operator==(class Material const&) const;
    MCAPI static void addMaterial(std::unique_ptr<class Material>);
    MCAPI static class Material const& getMaterial(enum MaterialType);
    MCAPI static void initMaterials();
    MCAPI static void teardownMaterials();

protected:
private:
    MCAPI static void _setupSurfaceMaterials();
    MCAPI static bool mInitialized;
    MCAPI static std::vector<std::unique_ptr<class Material>> mMaterials;
};

class Container;
class CompoundTag;
class BlockSource;

template<>
class buffer_span_mut<class Block const*>
{
public:
    class Block const** begin;
    class Block const** end;
    buffer_span_mut(class Block const** begin, class Block const** end)
        : begin(begin)
        , end(end){};
};

class BlockActor
{
public:
    int mTickCount; // 8
    Block* mBlock;  // 16
    int mDestroyTimer;
    Vec3 mDestroyDirection;
    int mDestroyProgress;
    BlockPos mPosition;
    AABB mBB;
    enum BlockActorType mType;
    enum BlockActorRendererId mRendererId;
    std::string mCustomName;
    std::string mFilteredCustomName;
    int mRepairCost;
    bool mClientSideOnly;
    bool mIsMovable;
    bool mSaveCustomName;
    bool mCanRenderCustomName;
    int signShadowRadius;
    void* ActorTerrainInterlockData[3];
    bool mChanged;
    inline void test()
    {
        static_assert(sizeof(BlockActor) == 200);
    }

    LIAPI bool refreshData();
    LIAPI bool refreshData(BlockSource* bs);
    LIAPI std::unique_ptr<CompoundTag> getNbt();
    LIAPI bool setNbt(CompoundTag* nbt);
    LIAPI bool setNbt(CompoundTag* nbt, BlockSource* bs);
    static unsigned int getBlockEntityType(Block* block);

public:
    /*0*/ virtual ~BlockActor();
    /*1*/ virtual void load(class Level&, class CompoundTag const&, class DataLoadHelper&);
    /*2*/ virtual bool save(class CompoundTag&) const;
    /*3*/ virtual bool saveItemInstanceData(class CompoundTag&);
    /*4*/ virtual void saveBlockData(class CompoundTag&, class BlockSource&) const;
    /*5*/ virtual void loadBlockData(class CompoundTag const&, class BlockSource&, class DataLoadHelper&);
    /*6*/ virtual void onCustomTagLoadDone(class BlockSource&);
    /*7*/ virtual void tick(class BlockSource&);
    /*8*/ virtual void onChanged(class BlockSource&);
    /*9*/ virtual bool isMovable(class BlockSource&);
    /*10*/ virtual bool isCustomNameSaved();
    /*11*/ virtual void onPlace(class BlockSource&);
    /*12*/ virtual void __unk_vfn_12();
    /*13*/ virtual void onRemoved(class BlockSource&);
    /*14*/ virtual void triggerEvent(int, int);
    /*15*/ virtual void clearCache();
    /*16*/ virtual void __unk_vfn_16();
    /*17*/ virtual float getShadowRadius(class BlockSource&) const;
    /*18*/ virtual bool hasAlphaLayer() const;
    /*19*/ virtual class BlockActor* getCrackEntity(class BlockSource&, class BlockPos const&);
    /*20*/ virtual void getDebugText(std::vector<std::string>&, class BlockPos const&);
    /*21*/ virtual std::string const& getCustomName() const;
    /*22*/ virtual std::string const& getFilteredCustomName(class UIProfanityContext const&);
    /*23*/ virtual std::string getName() const;
    /*24*/ virtual void setCustomName(std::string const&);
    /*25*/ virtual std::string getImmersiveReaderText(class BlockSource&);
    /*26*/ virtual int getRepairCost() const;
    /*27*/ virtual class PistonBlockActor* getOwningPiston(class BlockSource&);
    /*28*/ virtual void __unk_vfn_28();
    /*29*/ virtual void __unk_vfn_29();
    /*30*/ virtual float getDeletionDelayTimeSeconds() const;
    /*31*/ virtual void __unk_vfn_31();
    /*32*/ virtual void __unk_vfn_32();
    /*33*/ virtual void __unk_vfn_33();
    /*34*/ virtual std::unique_ptr<class BlockActorDataPacket> _getUpdatePacket(class BlockSource&);
    /*35*/ virtual void _onUpdatePacket(class CompoundTag const&, class BlockSource&);
    /*36*/ virtual bool _playerCanUpdate(class Player const&) const;
    MCAPI BlockActor(enum BlockActorType, class BlockPos const&, std::string const&);
    MCAPI void assignBlockIfNotAssigned(class BlockSource&);
    MCAPI class AABB const& getAABB() const;
    MCAPI class Block const* getBlock() const;
    MCAPI class BlockPos const& getPosition() const;
    MCAPI std::unique_ptr<class BlockActorDataPacket> getServerUpdatePacket(class BlockSource&);
    MCAPI enum BlockActorType const& getType() const;
    MCAPI bool const ignoreLighting() const;
    MCAPI bool isType(enum BlockActorType) const;
    MCAPI void moveTo(class BlockPos const&);
    MCAPI bool onUpdatePacket(class CompoundTag const&, class BlockSource&, class Player const*);
    MCAPI void setBB(class AABB);
    MCAPI void setChanged();
    MCAPI void setCustomNameSaved(bool);
    MCAPI void setIgnoreLighting(bool);
    MCAPI void setMovable(bool);
    MCAPI static bool isType(class BlockActor&, enum BlockActorType);
    MCAPI static class std::shared_ptr<class BlockActor> loadStatic(class Level&, class CompoundTag const&, class DataLoadHelper&);

protected:
    MCAPI void _resetAABB();

private:
    MCAPI static class std::map<std::string, enum BlockActorType, struct std::less<std::string>, class std::allocator<struct std::pair<std::string const, enum BlockActorType>>> _createIdClassMap();
    MCAPI static class std::map<enum BlockActorType, std::string, struct std::less<enum BlockActorType>, class std::allocator<struct std::pair<enum BlockActorType const, std::string>>> const mClassIdMap;
    MCAPI static class std::map<std::string, enum BlockActorType, struct std::less<std::string>, class std::allocator<struct std::pair<std::string const, enum BlockActorType>>> const mIdClassMap;
};

class BlockVolume
{
public:
    struct BlockVolumeIter
    {
        BlockVolumeIter() = delete;
        BlockVolumeIter(BlockVolumeIter const&) = delete;
        BlockVolumeIter(BlockVolumeIter const&&) = delete;
    };
    buffer_span_mut<class Block const*> buffer;
    int mWidth;
    int mHeight;
    int mDepth;
    int height;

public:
    MCAPI BlockVolume(class buffer_span_mut<class Block const*>, int, int, int, class Block const&, int);
    MCAPI struct BlockVolumeIter begin() const;
    MCAPI std::unique_ptr<std::vector<short>> computeHeightMap() const;
    MCAPI struct BlockVolumeIter end() const;
    MCAPI short findHighestNonAirBlock() const;
    MCAPI short getAboveTopSolidBlock(class BlockPos const&, bool, bool, bool) const;
    MCAPI class Pos getDimensions() const;
    MCAPI unsigned int getIndexBounds() const;
    MCAPI unsigned int index(class BlockPos const&) const;
    MCAPI unsigned int index(class Pos const&) const;
    MCAPI unsigned int indexNoBoundsCheck(class BlockPos const&) const;
    MCAPI unsigned int indexNoBoundsCheck(class Pos const&) const;
    MCAPI bool isInBounds(class Pos const&) const;
    MCAPI bool isInBounds(class BlockPos const&) const;
};

class BlockPosIterator
{
    BlockPos mMinCorner;
    BlockPos mMaxCorner;
    BlockPos mCurrentPos;
    bool mDone;

public:
    MCAPI BlockPosIterator(class BlockPos const&, class BlockPos const&);
    MCAPI class BlockPosIterator begin() const;
    MCAPI class BlockPosIterator end() const;
    MCAPI bool operator!=(class BlockPosIterator const&) const;
    MCAPI class BlockPos const& operator*();
    MCAPI class BlockPosIterator& operator++();
};

struct PatternEntry
{
    const Block* mBlock;
    std::function<bool(BlockSource&, BlockPos const&, Block const&)> mBlockEntryTester;
};

class BlockPatternBuilder
{
    BlockSource* mRegion;
    std::vector<std::string> mPattern;
    std::map<char, PatternEntry> mLookup;
    bool mReadyForMatch;
    int mNumPatterns;
    int mPatternLength;
};

class EndDragonFight
{

public:
    enum GatewayTask : unsigned char
    {
        GENERATE_PAIR,
        VERIFY_PAIR,
        NO_TASK,
    };
    struct GateWayGenerator
    {
        bool mPlaceNewBlocks;
        std::unique_ptr<ChunkViewSource> mSource;
        BlockPos mPosition;
    };
    BlockSource* mRegion;                                                                  // 0
    std::vector<int> mGateways;                                                            // 8
    std::unique_ptr<BlockPatternBuilder> mExitPortalPattern;                               // 32
    int mCrystalsAlive;                                                                    // 40
    int mTicksSinceCrystalsScanned;                                                        // 44
    int mTicksSincePortalScanned;                                                          // 48
    int mTicksSinceLastPlayerScan;                                                         // 52
    bool mDragonKilled;                                                                    // 56
    bool mPreviouslyKilled;                                                                // 57
    bool mDragonSpawned;                                                                   // 58
    ActorUniqueID mDragonUUID;                                                             // 64
    BlockPos mExitPortalLocation;                                                          // 72
    BlockPos mDragonSpawnPos;                                                              // 84
    enum RespawnAnimation mRespawnStage;                                                   // 96
    int mRespawnTime;                                                                      // 100
    std::vector<ActorUniqueID> mRespawnCrystals;                                           // 104
    unsigned char mDragonFightVersion;                                                     // 128
    GateWayGenerator mEntryGenerator;                                                      // 136
    GateWayGenerator mExitGenerator;                                                       // 168
    GatewayTask mBuildingOrVerifyingEndGatewayPair;                                        // 200
    std::deque<std::tuple<GatewayTask, GateWayGenerator, GateWayGenerator>> mGatewayTasks; // 208

public:
    MCAPI EndDragonFight(class BlockSource&);
    MCAPI void loadData(class CompoundTag const&);
    MCAPI void onCrystalDestroyed(class EnderCrystal const&, class ActorDamageSource const&);
    MCAPI void resetSpikeCrystals();
    MCAPI void saveData(class CompoundTag&);
    MCAPI void spawnNewGatewayChunks(class BlockPos const&, bool, bool);
    MCAPI void tick();
    MCAPI void tryRespawn();
    MCAPI void verifyExitPositions(class EndGatewayBlockActor&);
    MCAPI ~EndDragonFight();

private:
    MCAPI bool _canSpawnNewGateway(class ChunkViewSource*, class BlockPos const&) const;
    MCAPI void _createNewDragon();
    MCAPI struct BuildMatch _findExitPortal();
    MCAPI void _initializeDragon(class EnderDragon&);
    MCAPI void _makeEndIslandFeature(class BlockSource&, class BlockPos);
    MCAPI void _placeAndLinkNewGatewayPair();
    MCAPI bool _setEndGatewayBlockActorExitPosition(class BlockSource&, class BlockSource&, class BlockPos const&, class BlockPos const&, bool);
    MCAPI void _setRespawnStage(enum RespawnAnimation);
    MCAPI void _spawnExitPortal(bool);
    MCAPI void _spawnNewGatewayChunksTask(class std::tuple<enum EndDragonFight::GatewayTask, struct EndDragonFight::GateWayGenerator, struct EndDragonFight::GateWayGenerator>&);
    MCAPI void _spawnNewGatewayPair();
    MCAPI void _tickRespawnAnimation(std::vector<struct ActorUniqueID> const&, int);
    MCAPI void _updateCrystalCount();
    MCAPI void _verifyExitPositionsTask(class std::tuple<enum EndDragonFight::GatewayTask, struct EndDragonFight::GateWayGenerator, struct EndDragonFight::GateWayGenerator>&);
    MCAPI static int const ARENA_SIZE_CHUNKS;
    MCAPI static class BlockPos const DEFAULT_PORTAL_LOCATION;
    MCAPI static int const GATEWAY_CHUNK_RADIUS;
    MCAPI static int const GATEWAY_COUNT;
    MCAPI static int const GATEWAY_DISTANCE;
    MCAPI static int const GATEWAY_HEIGHT;
    MCAPI static int const TIME_BETWEEN_CRYSTAL_SCANS;
    MCAPI static int const TIME_BETWEEN_PLAYER_SCANS;
    MCAPI static int const TIME_BETWEEN_PORTAL_SCANS;
};

static_assert(sizeof(EndDragonFight::mGatewayTasks) == 40);


class EndGatewayBlockActor : public BlockActor
{
public:
    int mAge;
    int mTeleportCooldown;
    BlockPos mExitPortal;
    bool mNeedsExitGeneration;
    bool mTeleportTriggered;
    bool mNeedsExitPositionVerification;
    bool mExitPositionVerified;
    inline void test()
    {
        static_assert(sizeof(EndGatewayBlockActor) == 224);
    }

    /*0*/ virtual ~EndGatewayBlockActor();
    /*1*/ virtual void load(class Level&, class CompoundTag const&, class DataLoadHelper&);
    /*2*/ virtual bool save(class CompoundTag&) const;
    /*4*/ virtual void saveBlockData(class CompoundTag&, class BlockSource&) const;
    /*5*/ virtual void loadBlockData(class CompoundTag const&, class BlockSource&, class DataLoadHelper&);
    /*6*/ virtual void onCustomTagLoadDone(class BlockSource&);
    /*7*/ virtual void tick(class BlockSource&);
    /*8*/ virtual void onChanged(class BlockSource&);
    /*11*/ virtual void onPlace(class BlockSource&);
    /*12*/ virtual void __unk_vfn_12();
    /*13*/ virtual void onRemoved(class BlockSource&);
    /*14*/ virtual void triggerEvent(int, int);
    /*16*/ virtual void __unk_vfn_16();
    /*17*/ virtual float getShadowRadius(class BlockSource&) const;
    /*18*/ virtual bool hasAlphaLayer() const;
    /*19*/ virtual class BlockActor* getCrackEntity(class BlockSource&, class BlockPos const&);
    /*27*/ virtual class PistonBlockActor* getOwningPiston(class BlockSource&);
    /*28*/ virtual void __unk_vfn_28();
    /*29*/ virtual void __unk_vfn_29();
    /*30*/ virtual void __unk_vfn_30();
    /*31*/ virtual void __unk_vfn_31();
    /*32*/ virtual void __unk_vfn_32();
    /*33*/ virtual void __unk_vfn_33();
    /*34*/ virtual std::unique_ptr<class BlockActorDataPacket> _getUpdatePacket(class BlockSource&);
    /*35*/ virtual void _onUpdatePacket(class CompoundTag const&, class BlockSource&);
    /*36*/ virtual bool _playerCanUpdate(class Player const&) const;
    MCAPI EndGatewayBlockActor(class BlockPos const&);
    MCAPI bool canTeleport(class GetCollisionShapeInterface const*, class BlockSource const&) const;
    MCAPI class BlockPos getExitPosition() const;
    MCAPI int getParticleAmount(class BlockSource&, class BlockPos const&) const;
    MCAPI void setExitPosition(class BlockPos const&);
    MCAPI void teleportEntity(class Actor&);
    MCAPI static int const COOLDOWN_TIME;
    MCAPI static int const EVENT_COOLDOWN;
    MCAPI static int const SPAWN_TIME;
    MCAPI static class BlockPos findExitPortal(class WorldGenerator&, class BlockPos const&);
    MCAPI static class BlockPos findTallestBlock(class BlockSource&, class BlockPos const&, int, bool);
    MCAPI static class BlockPos findValidSpawnAround(class BlockSource&, class BlockPos const&, bool, int);
    inline static int getHighestSection(class WorldGenerator& a0, class BlockVolume& a1, class BlockPos const& a2)
    {
        return _getHighestSection(a0, a1, a2);
    };

private:
    MCAPI static int _getHighestSection(class WorldGenerator&, class BlockVolume&, class BlockPos const&);
};



#include <MC/ColorFormat.hpp>
namespace ColorHelper
{

template <typename T>
inline std::string aqua(T const& arg)
{
    return fmt::format("{}{}§r", ColorFormat::AQUA, arg);
}
template <typename T>
inline std::string black(T const& arg)
{
    return fmt::format("{}{}§r", ColorFormat::BLACK, arg);
}
template <typename T>
inline std::string blue(T const& arg)
{
    return fmt::format("{}{}§r", ColorFormat::BLUE, arg);
}
template <typename T>
inline std::string bold(T const& arg)
{
    return fmt::format("{}{}§r", ColorFormat::BOLD, arg);
}
template <typename T>
inline std::string dark_aqua(T const& arg)
{
    return fmt::format("{}{}§r", ColorFormat::DARK_AQUA, arg);
}
template <typename T>
inline std::string dark_blue(T const& arg)
{
    return fmt::format("{}{}§r", ColorFormat::DARK_BLUE, arg);
}
template <typename T>
inline std::string dark_gray(T const& arg)
{
    return fmt::format("{}{}§r", ColorFormat::DARK_GRAY, arg);
}
template <typename T>
inline std::string dark_green(T const& arg)
{
    return fmt::format("{}{}§r", ColorFormat::DARK_GREEN, arg);
}
template <typename T>
inline std::string dark_purple(T const& arg)
{
    return fmt::format("{}{}§r", ColorFormat::DARK_PURPLE, arg);
}
template <typename T>
inline std::string dark_red(T const& arg)
{
    return fmt::format("{}{}§r", ColorFormat::DARK_RED, arg);
}
template <typename T>
inline std::string gold(T const& arg)
{
    return fmt::format("{}{}§r", ColorFormat::GOLD, arg);
}
template <typename T>
inline std::string gray(T const& arg)
{
    return fmt::format("{}{}§r", ColorFormat::GRAY, arg);
}
template <typename T>
inline std::string green(T const& arg)
{
    return fmt::format("{}{}§r", ColorFormat::GREEN, arg);
}
template <typename T>
inline std::string italic(T const& arg)
{
    return fmt::format("{}{}§r", ColorFormat::ITALIC, arg);
}
template <typename T>
inline std::string light_purple(T const& arg)
{
    return fmt::format("{}{}§r", ColorFormat::LIGHT_PURPLE, arg);
}
template <typename T>
inline std::string minecoin_gold(T const& arg)
{
    return fmt::format("{}{}§r", ColorFormat::MINECOIN_GOLD, arg);
}
template <typename T>
inline std::string obfuscated(T const& arg)
{
    return fmt::format("{}{}§r", ColorFormat::OBFUSCATED, arg);
}
template <typename T>
inline std::string red(T const& arg)
{
    return fmt::format("{}{}§r", ColorFormat::RED, arg);
}
template <typename T>
inline std::string white(T const& arg)
{
    return fmt::format("{}{}§r", ColorFormat::WHITE, arg);
}
template <typename T>
inline std::string yellow(T const& arg)
{
    return fmt::format("{}{}§r", ColorFormat::YELLOW, arg);
}

template <typename T>
inline std::string aqua_bold(T const& arg)
{
    return fmt::format("{}{}{}§r", ColorFormat::AQUA, ColorFormat::BOLD, arg);
}
template <typename T>
inline std::string black_bold(T const& arg)
{
    return fmt::format("{}{}{}§r", ColorFormat::BLACK, ColorFormat::BOLD, arg);
}
template <typename T>
inline std::string blue_bold(T const& arg)
{
    return fmt::format("{}{}{}§r", ColorFormat::BLUE, ColorFormat::BOLD, arg);
}
template <typename T>
inline std::string dark_aqua_bold(T const& arg)
{
    return fmt::format("{}{}{}§r", ColorFormat::DARK_AQUA, ColorFormat::BOLD, arg);
}
template <typename T>
inline std::string dark_blue_bold(T const& arg)
{
    return fmt::format("{}{}{}§r", ColorFormat::DARK_BLUE, ColorFormat::BOLD, arg);
}
template <typename T>
inline std::string dark_gray_bold(T const& arg)
{
    return fmt::format("{}{}{}§r", ColorFormat::DARK_GRAY, ColorFormat::BOLD, arg);
}
template <typename T>
inline std::string dark_green_bold(T const& arg)
{
    return fmt::format("{}{}{}§r", ColorFormat::DARK_GREEN, ColorFormat::BOLD, arg);
}
template <typename T>
inline std::string dark_purple_bold(T const& arg)
{
    return fmt::format("{}{}{}§r", ColorFormat::DARK_PURPLE, ColorFormat::BOLD, arg);
}
template <typename T>
inline std::string dark_red_bold(T const& arg)
{
    return fmt::format("{}{}{}§r", ColorFormat::DARK_RED, ColorFormat::BOLD, arg);
}
template <typename T>
inline std::string gold_bold(T const& arg)
{
    return fmt::format("{}{}{}§r", ColorFormat::GOLD, ColorFormat::BOLD, arg);
}
template <typename T>
inline std::string gray_bold(T const& arg)
{
    return fmt::format("{}{}{}§r", ColorFormat::GRAY, ColorFormat::BOLD, arg);
}
template <typename T>
inline std::string green_bold(T const& arg)
{
    return fmt::format("{}{}{}§r", ColorFormat::GREEN, ColorFormat::BOLD, arg);
}
template <typename T>
inline std::string italic_bold(T const& arg)
{
    return fmt::format("{}{}{}§r", ColorFormat::ITALIC, ColorFormat::BOLD, arg);
}
template <typename T>
inline std::string light_purple_bold(T const& arg)
{
    return fmt::format("{}{}{}§r", ColorFormat::LIGHT_PURPLE, ColorFormat::BOLD, arg);
}
template <typename T>
inline std::string minecoin_gold_bold(T const& arg)
{
    return fmt::format("{}{}{}§r", ColorFormat::MINECOIN_GOLD, ColorFormat::BOLD, arg);
}
template <typename T>
inline std::string obfuscated_bold(T const& arg)
{
    return fmt::format("{}{}{}§r", ColorFormat::OBFUSCATED, ColorFormat::BOLD, arg);
}
template <typename T>
inline std::string red_bold(T const& arg)
{
    return fmt::format("{}{}{}§r", ColorFormat::RED, ColorFormat::BOLD, arg);
}
template <typename T>
inline std::string reset_bold(T const& arg)
{
    return fmt::format("{}{}{}§r", ColorFormat::RESET, ColorFormat::BOLD, arg);
}
template <typename T>
inline std::string white_bold(T const& arg)
{
    return fmt::format("{}{}{}§r", ColorFormat::WHITE, ColorFormat::BOLD, arg);
}
template <typename T>
inline std::string yellow_bold(T const& arg)
{
    return fmt::format("{}{}{}§r", ColorFormat::YELLOW, ColorFormat::BOLD, arg);
}

template <typename T>
inline std::string aqua_italic(T const& arg)
{
    return fmt::format("{}{}{}§r", ColorFormat::AQUA, ColorFormat::ITALIC, arg);
}
template <typename T>
inline std::string black_italic(T const& arg)
{
    return fmt::format("{}{}{}§r", ColorFormat::BLACK, ColorFormat::ITALIC, arg);
}
template <typename T>
inline std::string blue_italic(T const& arg)
{
    return fmt::format("{}{}{}§r", ColorFormat::BLUE, ColorFormat::ITALIC, arg);
}
template <typename T>
inline std::string dark_aqua_italic(T const& arg)
{
    return fmt::format("{}{}{}§r", ColorFormat::DARK_AQUA, ColorFormat::ITALIC, arg);
}
template <typename T>
inline std::string dark_blue_italic(T const& arg)
{
    return fmt::format("{}{}{}§r", ColorFormat::DARK_BLUE, ColorFormat::ITALIC, arg);
}
template <typename T>
inline std::string dark_gray_italic(T const& arg)
{
    return fmt::format("{}{}{}§r", ColorFormat::DARK_GRAY, ColorFormat::ITALIC, arg);
}
template <typename T>
inline std::string dark_green_italic(T const& arg)
{
    return fmt::format("{}{}{}§r", ColorFormat::DARK_GREEN, ColorFormat::ITALIC, arg);
}
template <typename T>
inline std::string dark_purple_italic(T const& arg)
{
    return fmt::format("{}{}{}§r", ColorFormat::DARK_PURPLE, ColorFormat::ITALIC, arg);
}
template <typename T>
inline std::string dark_red_italic(T const& arg)
{
    return fmt::format("{}{}{}§r", ColorFormat::DARK_RED, ColorFormat::ITALIC, arg);
}
template <typename T>
inline std::string gold_italic(T const& arg)
{
    return fmt::format("{}{}{}§r", ColorFormat::GOLD, ColorFormat::ITALIC, arg);
}
template <typename T>
inline std::string gray_italic(T const& arg)
{
    return fmt::format("{}{}{}§r", ColorFormat::GRAY, ColorFormat::ITALIC, arg);
}
template <typename T>
inline std::string green_italic(T const& arg)
{
    return fmt::format("{}{}{}§r", ColorFormat::GREEN, ColorFormat::ITALIC, arg);
}
template <typename T>
inline std::string light_purple_italic(T const& arg)
{
    return fmt::format("{}{}{}§r", ColorFormat::LIGHT_PURPLE, ColorFormat::ITALIC, arg);
}
template <typename T>
inline std::string minecoin_gold_italic(T const& arg)
{
    return fmt::format("{}{}{}§r", ColorFormat::MINECOIN_GOLD, ColorFormat::ITALIC, arg);
}
template <typename T>
inline std::string obfuscated_italic(T const& arg)
{
    return fmt::format("{}{}{}§r", ColorFormat::OBFUSCATED, ColorFormat::ITALIC, arg);
}
template <typename T>
inline std::string red_italic(T const& arg)
{
    return fmt::format("{}{}{}§r", ColorFormat::RED, ColorFormat::ITALIC, arg);
}
template <typename T>
inline std::string reset_italic(T const& arg)
{
    return fmt::format("{}{}{}§r", ColorFormat::RESET, ColorFormat::ITALIC, arg);
}
template <typename T>
inline std::string white_italic(T const& arg)
{
    return fmt::format("{}{}{}§r", ColorFormat::WHITE, ColorFormat::ITALIC, arg);
}
template <typename T>
inline std::string yellow_italic(T const& arg)
{
    return fmt::format("{}{}{}§r", ColorFormat::YELLOW, ColorFormat::ITALIC, arg);
}

inline std::string& transformToConsole(std::string& str)
{
    return ColorFormat::convertToColsole(str, false);
}

}; // namespace ColorHelper

// Utils
#ifdef DEBUG

#include <MC/PrettySnbtFormat.hpp>
class PrettySnbtFormatConsole : public PrettySnbtFormat
{
public:
    inline void setMaxLevel(unsigned int maxLevel)
    {
        mMaxLevel = maxLevel;
    }
};
inline std::string debugLogNbt(CompoundTag const& tag, unsigned int maxLevel = 0)
{
    PrettySnbtFormat format = PrettySnbtFormat::getDefaultFormat(false);
    // format.setValueColor<Tag::Type::Short>(ColorFormat::colorCodeToColorMap.at("§7"));
    ((PrettySnbtFormatConsole&)format).setMaxLevel(maxLevel);
    auto snbt = tag.toPrettySNBT(format);
    logger.warn("Snbt: \n{}", snbt);
    return snbt;
}


inline std::pair<std::string, int> genTickingInfo(ChunkSource& region, BlockPos const& bpos, int range)
{
    int chunk_x = bpos.x >> 4;
    int chunk_z = bpos.z >> 4;
    auto max_cx = chunk_x + range;
    auto min_cx = chunk_x - range;
    auto max_cz = chunk_z + range;
    auto min_cz = chunk_z - range;
    auto totalChunksCount = (max_cx - min_cx + 1) * (max_cz - min_cz + 1);
    auto chunksCount = 0;
    static std::string centerLabel = ColorHelper::red_bold("Ｘ");
    static std::string tickingLabel = ColorHelper::green("＃");
    static std::string inRegionLabel = "Ｏ";
    static std::string outofRegionLabel = "＋";
    static std::string unloadedLabel = ColorHelper::dark_gray("－");
    std::ostringstream loadInfo;
    std::set<__int64> playerChunkHashs;
    for (auto player : Level::getAllPlayers())
    {
        if (&player->getDimension() == &region.getDimension())
        {
            playerChunkHashs.insert(ChunkPos(player->getPos()).hash());
        }
    }
    auto& mainBlockSource = region.getDimension().getBlockSourceFromMainChunkSource();
    for (auto cx = min_cx; cx <= max_cx; ++cx)
    {
        loadInfo << " \n";
        for (auto cz = min_cz; cz <= max_cz; ++cz)
        {
            auto chunkHash = ChunkPos(cx, cz).hash();
            std::string label;
            auto chunk = region.getAvailableChunk({cx, cz});
            if (cx == chunk_x && cz == chunk_z)
            {
                label = centerLabel;
            }
            else
            {
                if (chunk)
                {
                    if (chunk->getLastTick().t == Global<Level>->getCurrentServerTick().t)
                    {
                        label = tickingLabel;
                    }
                    else
                    {
                        label = inRegionLabel;
                    }
                }
                else
                {
                    auto chunk = mainBlockSource.getChunk({cx, cz});
                    if (chunk)
                        label = outofRegionLabel;
                    else
                        label = unloadedLabel;
                }
            }
            if (chunk)
                ++chunksCount;
            if (playerChunkHashs.find(chunkHash) != playerChunkHashs.end())
            {
                ColorFormat::removeColorCode(label);
                label = ColorHelper::red_bold(label);
            }
            loadInfo << label;
        }
    }
    return {loadInfo.str(), chunksCount};
}
#else
#define debugLogNbt(...) ""
inline std::pair<std::string, int> genTickingInfo(ChunkSource& region, BlockPos const& bpos, int range)
{
    return {"", 0};
}
#endif // DEBUG

