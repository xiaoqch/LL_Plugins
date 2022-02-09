#include "pch.h"
#include "TestFakeName.h"
#ifdef ENABLE_TEST_FAKENAME
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
#include <MC/LoopbackPacketSender.hpp>
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

#include <MC/Util.hpp>
#include <ScheduleAPI.h>
#include <MC/Player.hpp>
#include <MC/ExperienceOrb.hpp>
#include <MC/ThrownTrident.hpp>
#include <MC/VanillaBlocks.hpp>
#include <MC/CommandUtils.hpp>
#include <MC/Level.hpp>
#include <MC/AttributeInstance.hpp>
#include <MC/ItemActor.hpp>
#include <MC/ItemStack.hpp>
#include <MC/Villager.hpp>
#include <MC/VillagerV2.hpp>
#include <MC/ActorClassTree.hpp>
#include <MC/HashedString.hpp>
//#include <MC/ActorMapping.hpp>
enum ActorCategory;
//enum ActorCategory : int
//{
//    mBoat            = 0x020000,
//    mNone            = 0x000000,
//    mWaterAnimal     = 0x000030,
//    mWater           = 0x000020,
//    mUndead          = 0x004000,
//    mPlayer          = 0x000001,
//    mAnimal          = 0x000010,
//    mMob             = 0x000002,
//    mMonster         = 0x000004,
//    mPathable        = 0x000040,
//    mHumanoid        = 0x000008,
//    mTamable         = 0x000080,
//    mRidable         = 0x000100,
//    mItem            = 0x000400,
//    mAmbient         = 0x000800,
//    mVillager        = 0x001000,
//    mArthropod       = 0x002000,
//    mZombie          = 0x008000,
//    mMinecart        = 0x010000,
//    mBoatrideable    = 0x020100,
//    mMinecartRidable = 0x010100,
//    mHumanoidMonster = 0x00000C,
//    mTamableAnimal   = 0x000090,
//    mUndeadMob       = 0x004004,
//    mZombieMonster   = 0x008004,
//};
enum ActorType : int
{
    mTurtle = 0x00134A,
    mChicken = 0x00130A,
    mBee = 0x00017A,
    mAxolotl = 0x001382,
    mPig = 0x00130C,
    mHoglin = 0x00137C,
    mZoglin = 0x010B7E,
    mCat = 0x00534B,
    mCow = 0x00130B,
    mSheep = 0x00130D,
    mWolf = 0x00530E,
    mVillager = 0x100030F,
    mVillagerV2 = 0x1000373,
    mShulker = 0x000B36,
    mWanderingTrader = 0x000376,
    mMooshroom = 0x001310,
    mSquid = 0x002311,
    mGlowSquid = 0x002381,
    mStrider = 0x00137D,
    mRabbit = 0x001312,
    mBat = 0x008113,
    mIronGolem = 0x000314,
    mSnowGolem = 0x000315,
    mOcelot = 0x005316,
    mHorse = 0x205317,
    mLlama = 0x00131D,
    mPolarBear = 0x00131C,
    mParrot = 0x00531E,
    mDolphin = 0x00231F,
    mGuardian = 0x000B31,
    mPanda = 0x001371,
    mFox = 0x001379,
    mHusk = 0x030B2F,
    mTropicalfish = 0x00236F,
    mWitherSkeleton = 0x110B30,
    mCod = 0x002370,
    mZombieVillager = 0x030B2C,
    mPufferfish = 0x00236C,
    mWitch = 0x000B2D,
    mSalmon = 0x00236D,
    mDonkey = 0x205318,
    mMule = 0x205319,
    mSkeletonHorse = 0x215B1A,
    mZombieHorse = 0x215B1B,
    mZombie = 0x030B20,
    mStray = 0x110B2E,
    mDrowned = 0x030B6E,
    mCreeper = 0x000B21,
    mSkeleton = 0x110B22,
    mSpider = 0x040B23,
    mZombiePigman = 0x010B24,
    mSlime = 0x000B25,
    mEnderman = 0x000B26,
    mSilverfish = 0x040B27,
    mCaveSpider = 0x040B28,
    mGhast = 0x000B29,
    mMagmaCube = 0x000B2A,
    mBlaze = 0x000B2B,
    mWither = 0x010B34,
    mZombieVillagerV2 = 0x030B74,
    mElderGuardian = 0x000B32,
    mElderGuardianGhost = 0x000B78,
    mEnderDragon = 0x000B35,
    mEndermite = 0x040B37,
    mVindicator = 0x000B39,
    mEvocationIllager = 0x000B68,
    mVex = 0x000B69,
    mPhantom = 0x010B3A,
    mPillager = 0x000B72,
    mRavager = 0x000B3B,
    mPiglinBrute = 0x00017F,
    mPiglin = 0x00017B,
    mGoat = 0x001380,
    mPlayer = 0x00013F,
    mMinecart = 0x080054,
    mHopperMinecart = 0x080060,
    mTntMinecart = 0x080061,
    mChestMinecart = 0x080062,
    mCommandBlockMinecart = 0x080064,
    mItem = 0x000040,
    mTnt = 0x000041,
    mFallingBlock = 0x000042,
    mMovingBlock = 0x000043,
    mXpBottle = 0x400044,
    mXpOrb = 0x000045,
    mEyeOfEnderSignal = 0x000046,
    mEnderCrystal = 0x000047,
    mShulkerBullet = 0x40004C,
    mFishingHook = 0x00004D,
    mDragonFireball = 0x40004F,
    mArrow = 0xC00050,
    mSnowball = 0x400051,
    mEgg = 0x400052,
    mPainting = 0x000053,
    mShield = 0x000075,
    mThrownTrident = 0xC00049,
    mFireball = 0x400055,
    mSplashPotion = 0x400056,
    mEnderPearl = 0x400057,
    mLeashKnot = 0x000058,
    mWitherSkull = 0x400059,
    mWitherSkullDangerous = 0x40005B,
    mBoat = 0x00005A,
    mLightningBolt = 0x00005D,
    mSmallFireball = 0x40005E,
    mLlamaSpit = 0x400066,
    mAreaEffectCloud = 0x00005F,
    mLingeringPotion = 0x400065,
    mEvocationFang = 0x400067,
    mArmorStand = 0x00013D,
    mFireworksRocket = 0x000048,
    mAgent = 0x000138,
    mIceBomb = 0x40006A,
    mBalloon = 0x00006B,
    mChalkboard = 0x00004E,
    mNpc = 0x000133,
    mTripodCamera = 0x00013E,
};
#define TryGetComponent(T, actor) \
    ((class T * (*)(Actor*)) dlsym_real("??$tryGetComponent@V" #T "@@@Actor@@QEAAPEAV" #T "@@XZ"))(actor)
#include <MC/ProjectileComponent.hpp>
template <class T>
T& tryGetComponent(Actor* actor)
{
    static auto name = typeid(T).name() + 6;
    static std::string sym = std::string("??$tryGetComponent@V") + name + "@@@Actor@@QEAAPEAV" + name + "@@XZ";
    static auto func = (T & (*)(Actor*)) dlsym_real(sym.c_str());
    return func(actor);
}
struct ActorMapping
{
    std::string mNameSpace;
    std::string mName;
    std::string mName2;
    HashedString mMappingName;

public:
    MCAPI ActorMapping(std::string const&, std::string const&, std::string const&);
    MCAPI ActorMapping(std::string const&, std::string const&);
    MCAPI std::string getMappingName(enum ActorTypeNamespaceRules) const;
    MCAPI ~ActorMapping();
};

void printActorCategory()
{
    auto& entityTypeMap = *(std::unordered_map<enum ActorType, struct ActorMapping>*)dlsym_real("?ENTITY_TYPE_MAP@@3V?$unordered_map@W4ActorType@@UActorMapping@@U?$hash@W4ActorType@@@std@@U?$equal_to@W4ActorType@@@4@V?$allocator@U?$pair@$$CBW4ActorType@@UActorMapping@@@std@@@4@@std@@A");
    logger.info("enum ActorType : int {");
    for (auto& [type, mapping] : entityTypeMap)
    {
        logger.info("    {} = {:>8X},", Util::toCamelCase("m_" + mapping.getMappingName((ActorTypeNamespaceRules)0), '_'), (int)type);
    }
    logger.info("};");

    SymCall("?entityCategoryFromString@@YA?AW4ActorCategory@@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z", void, std::string const&)("none");
    //((void (*)(std::string const&))(0x00000001421C8AD4 - 0x0000000141F4EA20 + (uintptr_t)ptr))("none");
    auto& categoryMap = *(std::unordered_map<std::string, enum ActorCategory>*)((uintptr_t)16 + (uintptr_t)dlsym("?mFeatureToggles@FeatureToggles@@0V?$unique_ptr@VFeatureToggles@@U?$default_delete@VFeatureToggles@@@std@@@std@@A"));
    logger.info("enum ActorCategory : int {");
    for (auto& [name, category] : categoryMap)
    {
        logger.info("    {} = 0x{:06X},", Util::toCamelCase("m_" + name, '_'), (int)category);
    }
    logger.info("};");
}
template <>
LoopbackPacketSender* Global<LoopbackPacketSender>;
TInstanceHook(LoopbackPacketSender*, "??0LoopbackPacketSender@@QEAA@EAEAVNetworkHandler@@@Z",
              LoopbackPacketSender, unsigned char unk, class NetworkHandler& handler)
{
    Schedule::delay([]() {
        printActorCategory();
    },
                    50);
    Global<LoopbackPacketSender> = this;
    return original(this, unk, handler);
}
enum class DataItemKey : unsigned short
{

};
enum class DataItemType2 : unsigned char
{
    //Flags,
    Byte,
    Short,
    Int,
    Float,
    String,
    CompoundTag,
    BlockPos,
    Int64,
    Vec3
};

class DataItem
{
public:
    DataItemType mDataType;
    DataItemKey mDataKey;

    /*0*/ virtual ~DataItem();
    /*1*/ virtual bool isDataEqual(class DataItem const&) const;
    /*2*/ virtual std::unique_ptr<DataItem> clone() const = 0; // ~DataItem()

    template <typename T>
    T const& getData() const
    {
        return dAccess<T>(this, 16);
    };
    template <typename T>
    T& getData()
    {
        return dAccess<T>(this, 16);
    };
    DataItem()
    {
    }
    DataItem(DataItemType type, DataItemKey key)
        : mDataKey(key)
        , mDataType(type)
    {
    }
};
//#include <MC/AddActorPacket.hpp>
#include <MC/AddActorBasePacket.hpp>
//??1?$DataItem2@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@@UEAA@XZ
//??_E?$DataItem2@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@@UEAAPEAXI@Z
template <typename T>
struct FakeDataItem2
{
    void* vftbl;
    DataItemType mDataType;
    DataItemKey mDataKey;
    T mValue;
};
template <typename T>
class DataItem2 : public DataItem
{
public:
    T mValue;

public:
    /*2*/ virtual std::unique_ptr<DataItem> clone() const; // ~DataItem()
    template <typename T>
    T& getData() const
    {
        return mValue;
    };
    DataItem2(DataItemKey key, T value)
    {
        mDataKey = key;
        mValue = value;
        if constexpr (std::is_same<T, signed char>::value)
        {
            *(void**)this = dlsym_real("??_7?$DataItem2@C@@6B@");
            mDataType = DataItemType::BYTE;
        }
        else if constexpr (std::is_same<T, short>::value)
        {
            *(void**)this = dlsym_real("??_7?$DataItem2@F@@6B@");
            mDataType = DataItemType::SHORT;
        }
        else if constexpr (std::is_same<T, int>::value)
        {
            *(void**)this = dlsym_real("??_7?$DataItem2@M@@6B@");
            mDataType = DataItemType::INT;
        }
        else if constexpr (std::is_same<T, float>::value)
        {
            *(void**)this = dlsym_real("??_7?$DataItem2@M@@6B@");
            mDataType = DataItemType::FLOAT;
        }
        else if constexpr (std::is_same<T, std::string>::value)
        {
            *(void**)this = dlsym_real("??_7?$DataItem2@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@@6B@");
            mDataType = DataItemType::STRING;
        }
        else if constexpr (std::is_same<T, CompoundTag>::value)
        {
            *(void**)this = dlsym_real("??_7?$DataItem2@VCompoundTag@@@@6B@");
            mDataType = DataItemType::NBT;
        }
        else if constexpr (std::is_same<T, BlockPos>::value)
        {
            *(void**)this = dlsym_real("??_7?$DataItem2@VBlockPos@@@@6B@");
            mDataType = DataItemType::POS;
        }
        else if constexpr (std::is_same<T, __int64>::value)
        {
            *(void**)this = dlsym_real("??_7?$DataItem2@_J@@6B@");
            mDataType = DataItemType::LONG;
        }
        else if constexpr (std::is_same<T, Vec3>::value)
        {
            *(void**)this = dlsym_real("??_7?$DataItem2@VVec3@@@@6B@");
            mDataType = DataItemType::VEC3;
        }
        else
        {
            static_assert(false);
        }
    }
    static std::unique_ptr<DataItem> create(DataItemKey key, T value)
    {
    }
};

class SynchedActorData
{
    std::vector<std::unique_ptr<DataItem>> mItemsArray;
    unsigned short minIdxDirty;
    unsigned short maxIdxDirty;

public:
    MCAPI SynchedActorData();
    MCAPI class SynchedActorData _clone() const;
    MCAPI bool assignValues(std::vector<std::unique_ptr<class DataItem>> const&, class Actor*);
    MCAPI void forEachDataItem(class std::function<void(std::unique_ptr<class DataItem> const&)> const&) const;
    MCAPI class CompoundTag const& getCompoundTag(unsigned short) const;
    MCAPI float getFloat(unsigned short) const;
    MCAPI int getInt(unsigned short) const;
    MCAPI __int64 getInt64(unsigned short) const;
    MCAPI signed char getInt8(unsigned short) const;
    MCAPI class BlockPos getPos(unsigned short) const;
    MCAPI short getShort(unsigned short) const;
    MCAPI std::string const& getString(unsigned short) const;
    MCAPI unsigned __int64 getValidDataItemCount() const;
    MCAPI class Vec3 getVec3(unsigned short) const;
    MCAPI bool hasData(unsigned short) const;
    MCAPI void markDirty(unsigned short);
    MCAPI class SynchedActorData& operator=(class SynchedActorData&&);
    MCAPI std::vector<std::unique_ptr<class DataItem>> packAll() const;
    MCAPI std::vector<std::unique_ptr<class DataItem>> packDirty();
    MCAPI ~SynchedActorData();

protected:
private:
    MCAPI class DataItem* _find(unsigned short) const;
    MCAPI class DataItem& _get(unsigned short);
    MCAPI void _resizeToContain(unsigned short);
};
inline class Actor* getRuntimeEntity(class ActorRuntimeID a0, bool a1)
{
    class Actor* (Level::*rv)(class ActorRuntimeID, bool);
    *((void**)&rv) = dlsym("?getRuntimeEntity@Level@@UEBAPEAVActor@@VActorRuntimeID@@_N@Z");
    return (Global<Level>->*rv)(std::forward<class ActorRuntimeID>(a0), std::forward<bool>(a1));
}
std::string getActorFakeName(Actor* actor)
{
    //logger.warn(actor->getNbt()->toSNBT());
#define FmtArg(argv) fmt::arg(#argv, argv)
    std::string fakeName;
    std::string name = actor->getNameTag();
    if (name.empty())
        name = "§7" + CommandUtils::getActorName(*actor) + "§r";
    logger.warn(name);
    auto health = actor->getHealth();
    auto maxHealth = actor->getMaxHealth();

    auto& syncActorData = dAccess<SynchedActorData>(actor, 376);
    std::string type = actor->getTypeName();
    auto uniqueId = actor->getUniqueID().id;
    if (ActorClassTree::isInstanceOf(*actor, ActorType::mPlayer))
    {
        static auto formatPlayer = "{name}\n§7{type}\n§c❤§a{health}§r/§a{maxHealth}§r §b{hunger}§r/§b{maxHunger}§r";
        auto player = (Player*)actor;
        try
        {
            auto hunger = player->getAttribute(Player::HUNGER).getCurrentValue();
            auto maxHunger = player->getAttribute(Player::HUNGER).getMaxValue();
            fakeName = fmt::format(formatPlayer, FmtArg(name), FmtArg(type), FmtArg(uniqueId), FmtArg(health), FmtArg(maxHealth), FmtArg(hunger), FmtArg(maxHunger));
        }
        catch (...)
        {
            fakeName = name;
        }
    }
    else if (ActorClassTree::isInstanceOf(*actor, ActorType::mItem))
    {
        static auto formatItemActor = "{name}{itemInfo}\n§7{type}\n§b{time}§r/§b{maxTime}§rs";

        auto itemActor = (ItemActor*)actor;
        auto item = itemActor->getItemStack();
        std::string itemInfo;
        auto maxStackSize = item->getMaxStackSize();
        if (maxStackSize > 1)
        {
            itemInfo = " ⨯ " + std::to_string(item->getCount());
        }
        else if (item->isDamageableItem())
        {
            auto maxDamage = item->getMaxDamage();
            auto damage = maxDamage - item->getDamageValue();
            itemInfo = fmt::format(" {} / {}", damage, maxDamage);
        }
        auto count = itemActor->getItemStack()->getCount();
        auto maxTime = itemActor->getDespawnTime() / 20.0f;
        auto time = maxTime - itemActor->getLatestSpawnTime() / 20.0f;
        fakeName = fmt::format(formatItemActor, FmtArg(name), FmtArg(type), FmtArg(uniqueId), FmtArg(itemInfo), FmtArg(time), FmtArg(maxTime));
    }
    else if (ActorClassTree::isInstanceOf(*actor, ActorType::mVillager))
    {
        static auto formatVillage = "{name}\n§7{type}\n§c❤§a{health}§r/§a{maxHealth}§r\n";
        auto villager = (VillagerV2*)actor;

        fakeName = fmt::format(formatVillage, FmtArg(name), FmtArg(type), FmtArg(uniqueId), FmtArg(health), FmtArg(maxHealth));
    }
    else if (SymCallStatic("??$hasComponent@VProjectileComponent@@@Actor@@QEBA_NXZ", bool, Actor*)(actor))
    {
        auto& proj = tryGetComponent<ProjectileComponent>(actor);
        proj.getOffset();
        static auto formatProjectile = "{name}{tridentInfo}\n§7{type}{owner}\n§e创造§r：{isCreative}，§e玩家§r：{isPlayer}";
        auto projectile = (PredictableProjectile*)actor;
        auto ownerId = projectile->getOwnerId();
        std::string owner;

        if (auto ownerActor = Level::getEntity(ownerId))
        {
            owner += fmt::format("\n§b拥有者§r：{}", CommandUtils::getActorName(*ownerActor));
        }
        else if (ownerId != -1)
        {
            owner = fmt::format("\n§7拥有者：0x{:016x}§r", *(unsigned __int64*)&ownerId);
        }
        std::string tridentInfo;
        if (ActorClassTree::isInstanceOf(*actor, ActorType::mThrownTrident))
        {
            auto& item = dAccess<ItemStack>(projectile, 1872);
            auto maxDamage = item.getMaxDamage();
            auto damage = maxDamage - item.getDamageValue();
            auto customName = item.getCustomName();
            if (!customName.empty())
                name = customName;
            tridentInfo = fmt::format("{damage} / {maxDamage}", FmtArg(damage), FmtArg(maxDamage));
        }
        auto isPlayer = dAccess<bool>(actor, 1860) ? "§a§l✓§r" : "§4§l✗§r";
        auto isCreative = dAccess<bool>(actor, 1861) ? "§a§l✓§r" : "§4§l✗§r";
        fakeName = fmt::format(formatProjectile, FmtArg(name), FmtArg(type), FmtArg(uniqueId), FmtArg(tridentInfo), FmtArg(owner), FmtArg(isPlayer), FmtArg(isCreative));
    }
    else if (actor->hasCategory((enum ActorCategory)0x000002 /* Mob */))
    {
        static auto formatMob = "{name}{mobInfo}\n§7{type}\n§c❤§a{health}§r/§a{maxHealth}§r";
        std::string mobInfo;
        auto ownerId = actor->getOwnerId().id;
        if (ownerId != -1 && ownerId != 0)
        {
            if (auto ownerActor = Level::getEntity(ownerId))
            {
                mobInfo += fmt::format("\n§b拥有者§r：{}", CommandUtils::getActorName(*ownerActor));
            }
            else
            {
                mobInfo = fmt::format("\n§7拥有者：0x{:016x}§r", *(unsigned __int64*)&ownerId);
            }
        }
        fakeName = fmt::format(formatMob, FmtArg(name), FmtArg(type), FmtArg(uniqueId), FmtArg(mobInfo), FmtArg(health), FmtArg(maxHealth));
    }
    else if (ActorClassTree::isInstanceOf(*actor, ActorType::mXpOrb))
    {
        static auto formatExp = "{name} {exp}\n§7{type}\n§b{time}§r/§b{maxTime}§rs";
        auto orb = (ExperienceOrb*)actor;
        auto exp = syncActorData.getInt(0xFu);
        auto maxTime = 300;
        auto time = maxTime - dAccess<unsigned short>(actor, 1868) / 20;
        fakeName = fmt::format(formatExp, FmtArg(name), FmtArg(type), FmtArg(uniqueId), FmtArg(exp), FmtArg(time), FmtArg(maxTime));
    }
    else
    {
        fakeName = name;
    }
    return fakeName;
}

class SetActorDataPacket : public Packet
{
public:
    ActorRuntimeID mRuntimeId;
    Tick mTick = {0};
    std::vector<std::unique_ptr<DataItem>> mDataItems; //64

public:
    /*0*/ virtual ~SetActorDataPacket();
    /*1*/ virtual enum MinecraftPacketIds getId() const;
    /*2*/ virtual std::string getName() const;
    /*3*/ virtual void write(class BinaryStream&) const;
    /*4*/ virtual bool disallowBatching() const;
    /*5*/ virtual enum StreamReadResult _read(class ReadOnlyBinaryStream&);
    MCAPI SetActorDataPacket(class ActorRuntimeID, class SynchedActorData&, bool);
    MCAPI SetActorDataPacket();
};
static_assert(sizeof(SetActorDataPacket) == 88);
static_assert(offsetof(SetActorDataPacket, mDataItems) == 64);
#include <MC/ActorDefinitionIdentifier.hpp>
//#include <MC/SynchedActorData.hpp>
//#include <MC/AttributeInstanceHandle.hpp>
#include <MC/AttributeInstance.hpp>
//class AttributeInstance {
//public:
//    BaseAttributeMap* mAttributeMap;//8
//    Attribute* mAttribute;//16
//    std::vector<AttributeModifier> mModifierList;//24
//    std::vector<TemporalAttributeBuff> mTemporalBuffs;//48
//    std::vector<AttributeInstanceHandle> mListeners;//72
//    std::shared_ptr<AttributeInstanceDelegate> mDelegate;//96
//    float mDefaultMin;
//    float mDefaultMax;
//    float mDefaultValue;
//    float mMinValue;//124
//    float mMaxValue;
//    float mCurrentValue;
//public:
//    /*0*/ virtual ~AttributeInstance();
//    /*1*/ virtual void tick();
//    MCAPI AttributeInstance(class AttributeInstance const&);
//    MCAPI AttributeInstance();
//    MCAPI void addBuff(class AttributeBuff const&);
//    MCAPI void addModifier(class AttributeModifier const&);
//    MCAPI void addModifier(class std::shared_ptr<class AttributeModifier>);
//    MCAPI class Attribute const* getAttribute() const;
//    MCAPI std::vector<class TemporalAttributeBuff> const& getBuffs() const;
//    MCAPI float getCurrentValue() const;
//    MCAPI float getDefaultValue(int) const;
//    MCAPI class AttributeInstanceHandle getHandle() const;
//    MCAPI std::vector<class AttributeInstanceHandle> const& getListeners() const;
//    MCAPI float getMaxValue() const;
//    MCAPI float getMinValue() const;
//    MCAPI class AttributeModifier getModifier(class mce::UUID const&) const;
//    MCAPI std::vector<class AttributeModifier> getModifiers(int) const;
//    MCAPI std::vector<class AttributeModifier> getModifiers() const;
//    MCAPI bool hasModifier(class mce::UUID const&) const;
//    MCAPI bool hasModifier(class std::shared_ptr<class AttributeModifier>) const;
//    MCAPI bool hasModifiers() const;
//    MCAPI bool hasTemporalBuffs() const;
//    MCAPI bool isValid() const;
//    MCAPI void notify(__int64);
//    MCAPI void recalculateModifiers();
//    MCAPI void registerListener(class AttributeInstance const&);
//    MCAPI void removeBuff(class std::shared_ptr<class AttributeBuff>);
//    MCAPI void removeBuffs();
//    MCAPI void removeModifier(class AttributeModifier const&);
//    MCAPI void removeModifier(class std::shared_ptr<class AttributeModifier>);
//    MCAPI bool removeModifier(class mce::UUID const&);
//    MCAPI void resetToDefaultValue();
//    MCAPI void resetToMaxValue();
//    MCAPI void resetToMinValue();
//    MCAPI void serializationSetRange(float, float, float);
//    MCAPI void serializationSetValue(float, int, float);
//    MCAPI void setCurrentValue(float);
//    MCAPI void setDefaultValue(float, int);
//    MCAPI void setDefaultValueOnly(float);
//    MCAPI void setDelegate(class std::shared_ptr<class AttributeInstanceDelegate>);
//    MCAPI void setMaxValue(float);
//    MCAPI void setRange(float, float, float);
//};
static_assert(offsetof(AttributeInstance, mMinValue) == 124);
#include <MC/Attribute.hpp>
class AttributeInstanceHandle
{
    unsigned int mAttributeID;
    BaseAttributeMap* mAttributeMap;

public:
    MCAPI class AttributeInstance const& getInstance() const;
    MCAPI class AttributeInstance* getMutableInstance() const;
};
class SyncedAttribute
{
    std::string mName;
    float mMinValue;
    float mCurrentValue;
    float mMaxValue;
    float mDefaultValue;
};
struct ActorLink
{
    unsigned char mType;
    ActorUniqueID mRiddenUniqueID;
    ActorUniqueID mRidderUniqueID;
    bool mImmediate;
    bool mRiderInitiated;
};
static_assert(sizeof(SyncedAttribute) == 48); //sizeof(NpcCommandAction::SavedCommand)
class AddActorPacket : public Packet
{
public:
    std::vector<struct ActorLink> mActorLinks; //48
    Vec3 mPosition;                            //72
    Vec3 mVelocity;                            //84
    float mPitch;                              //96
    float mYaw;                                //100
    float mHeadYaw;                            //104

    ActorUniqueID mUniqueId;                                //112
    ActorRuntimeID mRuntimeId;                              //120
    SynchedActorData* mActorData;                           //128, only for write
    std::vector<std::unique_ptr<DataItem>> mDataItems;      //136, only for read
    ActorDefinitionIdentifier mType;                        //160
    std::vector<AttributeInstanceHandle> mAttributeHandles; //336
    std::vector<SyncedAttribute> mAttributes;               //360

public:
    /*0*/ virtual ~AddActorPacket();
    /*1*/ virtual enum MinecraftPacketIds getId() const;
    /*2*/ virtual std::string getName() const;
    /*3*/ virtual void write(class BinaryStream&) const;
    /*4*/ virtual bool disallowBatching() const;
    /*5*/ virtual enum StreamReadResult _read(class ReadOnlyBinaryStream&);
    MCAPI AddActorPacket(class Actor&);
    MCAPI AddActorPacket();
    void fakeWrite(class BinaryStream& bs) const
    {
        bs.writeVarInt64(mUniqueId.id);
        bs.writeUnsignedVarInt64(mRuntimeId.id);
        bs.writeString(mType.getCanonicalName());
        bs.writeVec3(mPosition);
        bs.writeVec3(mVelocity);
        bs.writeFloat(mPitch);
        bs.writeFloat(mYaw);
        bs.writeFloat(mHeadYaw);
        //writeAtrribute
        bs.writeUnsignedVarInt((int)mAttributeHandles.size());
        for (auto& handle : mAttributeHandles)
        {
            auto& ins = handle.getInstance();
            bs.writeString(ins.getAttribute()->getName().getString());
            bs.writeFloat(ins.getMinValue());
            bs.writeFloat(ins.getCurrentValue());
            bs.writeFloat(ins.getMaxValue());
        }
        //writeDataItems
        auto dataItems = mActorData->packAll();
        auto actor = getRuntimeEntity(mRuntimeId, true);
        auto fakeName = getActorFakeName(actor);
        dataItems.emplace_back(DataItem2<std::string>((DataItemKey)4, fakeName).clone());
        dataItems.emplace_back(DataItem2<signed char>((DataItemKey)0x51u, true).clone());
        bs.writeType(dataItems);

        //writeLinks
        bs.writeUnsignedVarInt((int)mActorLinks.size());
        for (auto& link : mActorLinks)
        {
            bs.writeVarInt64(link.mRiddenUniqueID.id);
            bs.writeVarInt64(link.mRidderUniqueID.id);
            bs.writeUnsignedChar(link.mType);
            bs.writeBool(link.mImmediate);
            bs.writeBool(link.mRiderInitiated);
        }
    }
};
static_assert(sizeof(AddActorPacket) == 384);
static_assert(offsetof(AddActorPacket, mActorLinks) == 48);
static_assert(offsetof(AddActorPacket, mHeadYaw) == 104);
static_assert(offsetof(AddActorPacket, mRuntimeId) == 120);
static_assert(offsetof(AddActorPacket, mActorData) == 128);
static_assert(offsetof(AddActorPacket, mType) == 160);
static_assert(offsetof(AddActorPacket, mAttributeHandles) == 336);
//#include <MC/AddItemActorPacket.hpp>
//#include <MC/Abilities.hpp>
class AddItemActorPacket : public Packet
{
    std::vector<std::unique_ptr<DataItem>> mDataItems; //unk
    SynchedActorData* mActorData;                      //72
    ActorUniqueID mUniqueId;                           //80
    ActorRuntimeID mRuntimeId;                         //88
    NetworkItemStackDescriptor mDescriptor;            //96
    Vec3 mPos;                                         //224
    Vec3 mVelocity;                                    //236
    bool mIsFromFishing;                               //

public:
    /*0*/ virtual ~AddItemActorPacket();
    /*1*/ virtual enum MinecraftPacketIds getId() const;
    /*2*/ virtual std::string getName() const;
    /*3*/ virtual void write(class BinaryStream&) const;
    /*4*/ virtual bool disallowBatching() const;
    /*5*/ virtual enum StreamReadResult _read(class ReadOnlyBinaryStream&);
    MCAPI AddItemActorPacket(class ItemActor&);
    MCAPI AddItemActorPacket();
    void fakeWrite(class BinaryStream& bs) const
    {
        bs.writeVarInt64(mUniqueId.id);
        bs.writeUnsignedVarInt64(mRuntimeId.id);
        bs.writeType(mDescriptor);
        bs.writeVec3(mPos);
        bs.writeVec3(mVelocity);
        auto dataItems = mActorData->packAll();
        auto actor = getRuntimeEntity(mRuntimeId, true);
        auto fakeName = getActorFakeName(actor);
        dataItems.emplace_back(DataItem2<std::string>((DataItemKey)4, fakeName).clone());
        dataItems.emplace_back(DataItem2<signed char>((DataItemKey)0x51u, true).clone());
        bs.writeType(dataItems);

        bs.writeBool(mIsFromFishing);
    }
};
static_assert(sizeof(AddItemActorPacket) == 256);
//#include <MC/AddPaintingPacket.hpp>
class AddPaintingPacket : public Packet
{
    ActorUniqueID mUniqueId;   //48
    ActorRuntimeID mRuntimeId; //56
    Vec3 mPos;                 //64
    int mDirection;            //72
    std::string mMotive;       //80

public:
    /*0*/ virtual ~AddPaintingPacket();
    /*1*/ virtual enum MinecraftPacketIds getId() const;
    /*2*/ virtual std::string getName() const;
    /*3*/ virtual void write(class BinaryStream&) const;
    /*4*/ virtual bool disallowBatching() const;
    /*5*/ virtual enum StreamReadResult _read(class ReadOnlyBinaryStream&);
    MCAPI AddPaintingPacket(class Painting const&);
    MCAPI AddPaintingPacket();
    void fakeWrite(class BinaryStream& bs) const
    {
        bs.writeVarInt64(mUniqueId.id);
        bs.writeUnsignedVarInt64(mRuntimeId.id);
        bs.writeVec3(mPos);
        bs.writeVarInt(mDirection);
        bs.writeString(mMotive);
    }
};
//#include <MC/Ability.hpp>
class Ability
{
    enum Options : unsigned char;
    enum Type;

    Type mType;
    int mValue;
    Options mOptions;
};
class Abilities
{
    std::unique_ptr<class PermissionsHandler> mPermissions;
    std::array<Ability, 18> mAbilities;
    std::array<Ability, 8> mCustomAbilityCache;
    int unk320;
    int unk324;
    int unk328;

public:
    MCAPI Abilities(class Abilities const&);
    MCAPI Abilities();
    MCAPI void addSaveData(class CompoundTag&) const;
    MCAPI void forEachAbility(class std::function<void(class Ability&, char const*)> const&, enum Ability::Options);
    MCAPI class Ability& getAbility(enum AbilitiesIndex);
    MCAPI class Ability const& getAbility(enum AbilitiesIndex) const;
    MCAPI bool getBool(enum AbilitiesIndex) const;
    MCAPI enum CommandPermissionLevel getCommandPermissions() const;
    MCAPI class Ability const& getCustomAbilityFromCache(enum AbilitiesIndex) const;
    MCAPI class Ability& getCustomAbilityFromCache(enum AbilitiesIndex);
    MCAPI enum PlayerPermissionLevel getPlayerPermissions() const;
    MCAPI bool isFlying() const;
    MCAPI bool loadSaveData(class CompoundTag const&);
    MCAPI class Abilities& operator=(class Abilities const&);
    MCAPI void setAbility(enum AbilitiesIndex, bool);
    MCAPI void setAbilityDiff(enum AbilitiesIndex, bool, bool&);
    MCAPI void setCommandPermissions(enum CommandPermissionLevel);
    MCAPI void setPlayerPermissions(enum PlayerPermissionLevel);
    MCAPI ~Abilities();
    MCAPI static char const* getAbilityName(enum AbilitiesIndex);
    MCAPI static enum AbilitiesIndex nameToAbilityIndex(std::string const&);

protected:
private:
    MCAPI void _registerAbilities();
    MCAPI static class std::array<char const*, 18> ABILITY_NAMES;
    MCAPI static std::string const TAG;
};
constexpr auto size = sizeof(Abilities);
static_assert(sizeof(Abilities) == 336);
//#include <MC/AddPlayerPacket.hpp>
struct AdventureSettings
{
    char filler26;

public:
    MCAPI AdventureSettings();
};
#include <MC/AdventureSettingsPacket.hpp>
class AddPlayerPacket : public Packet
{
public:
    std::vector<struct ActorLink> mActorLinks;         //48
    std::string mName;                                 //72
    mce::UUID mUuid;                                   //104
    ActorUniqueID mUniqueId;                           //120
    ActorRuntimeID mRuntimeId;                         //128
    std::string mPlatformOnlineId;                     //136
    Vec3 mPosition;                                    //168
    Vec3 mVelocity;                                    //180
    float mPitch;                                      //192
    float mYaw;                                        //196
    float mHeadYaw;                                    //200
    std::vector<std::unique_ptr<DataItem>> mDataItems; //208, only for read
    Abilities mAbilities;                              //232
    std::string mDeviceId;                             //568
    enum BuildPlatform mBuildPlatform;                 //600
    NetworkItemStackDescriptor mCarriedItem;           //608
    SynchedActorData* mActorData;                      //736
public:
    /*0*/ virtual ~AddPlayerPacket();
    /*1*/ virtual enum MinecraftPacketIds getId() const;
    /*2*/ virtual std::string getName() const;
    /*3*/ virtual void write(class BinaryStream&) const;
    /*4*/ virtual bool disallowBatching() const;
    /*5*/ virtual enum StreamReadResult _read(class ReadOnlyBinaryStream&);
    MCAPI AddPlayerPacket(class Player&);
    MCAPI AddPlayerPacket();
    void fakeWrite(class BinaryStream& bs) const
    {
        bs.writeUnsignedInt64(*(unsigned __int64*)&mUuid);
        bs.writeUnsignedInt64(*((unsigned __int64*)&mUuid + 1));
        bs.writeString(getActorFakeName(getRuntimeEntity(mRuntimeId, true)));
        bs.writeVarInt64(mUniqueId.id);
        bs.writeUnsignedVarInt64(mRuntimeId.id);
        bs.writeString(mPlatformOnlineId);
        bs.writeVec3(mPosition);
        bs.writeVec3(mVelocity);
        bs.writeFloat(mPitch);
        bs.writeFloat(mYaw);
        bs.writeFloat(mHeadYaw);
        bs.writeType(mCarriedItem);
        auto dataItems = mActorData->packAll();
        auto actor = getRuntimeEntity(mRuntimeId, true);
        auto fakeName = getActorFakeName(actor);
        dataItems.emplace_back(DataItem2<std::string>((DataItemKey)4, fakeName).clone());
        dataItems.emplace_back(DataItem2<signed char>((DataItemKey)0x51u, true).clone());
        bs.writeType(dataItems);
        AdventureSettingsPacket settings(AdventureSettings{}, mAbilities, {-1}, false);
        settings.write(bs);
        //writeLinks
        bs.writeUnsignedVarInt((int)mActorLinks.size());
        for (auto& link : mActorLinks)
        {
            bs.writeVarInt64(link.mRiddenUniqueID.id);
            bs.writeVarInt64(link.mRidderUniqueID.id);
            bs.writeUnsignedChar(link.mType);
            bs.writeBool(link.mImmediate);
            bs.writeBool(link.mRiderInitiated);
        }
        bs.writeString(mDeviceId);
        bs.writeUnsignedInt(mBuildPlatform);
    }
};
//constexpr auto a = sizeof(AddPlayerPacket);
static_assert(sizeof(AddPlayerPacket) == 744);
static_assert(offsetof(AddPlayerPacket, mDataItems) == 208);
static_assert(offsetof(AddPlayerPacket, mAbilities) == 232);
static_assert(offsetof(AddPlayerPacket, mDeviceId) == 568);
static_assert(offsetof(AddPlayerPacket, mCarriedItem) == 608);
static_assert(offsetof(AddPlayerPacket, mActorData) == 736);
TInstanceHook(void, "?write@AddActorPacket@@UEBAXAEAVBinaryStream@@@Z",
              AddActorPacket, class BinaryStream& bs)
{
    fakeWrite(bs);
}
TInstanceHook(void, "?write@AddItemActorPacket@@UEBAXAEAVBinaryStream@@@Z",
              AddItemActorPacket, class BinaryStream& bs)
{
    fakeWrite(bs);
}
TInstanceHook(void, "?write@AddPlayerPacket@@UEBAXAEAVBinaryStream@@@Z",
              AddPlayerPacket, class BinaryStream& bs)
{
    fakeWrite(bs);
}

void setActorFakeName(Actor* actor, std::string const& name)
{
    SetActorDataPacket packet;
    packet.mRuntimeId = actor->getRuntimeID();
    packet.mDataItems.emplace_back(DataItem2<std::string>((DataItemKey)4, name).clone());
    packet.mDataItems.emplace_back(DataItem2<signed char>((DataItemKey)0x51u, true).clone());
    Global<LoopbackPacketSender>->sendBroadcast(packet);
}
void refreshActorFakeName(Actor* actor)
{
    SetActorDataPacket packet;
    packet.mRuntimeId = actor->getRuntimeID();
    packet.mDataItems.emplace_back(DataItem2<std::string>((DataItemKey)4, actor->getNameTag()).clone());
    auto pos = actor->getPos();
    auto& dim = actor->getDimension();
    dim.sendPacketForEntity(*actor, packet, nullptr);
    //Global<LoopbackPacketSender>->sendBroadcast(packet);
}
#include <MC/HealthAttributeDelegate.hpp>
TInstanceHook(bool, "?change@HealthAttributeDelegate@@UEAA_NMMUAttributeBuffInfo@@@Z",
              HealthAttributeDelegate, float before, float after, struct AttributeBuffInfo* info)
{
    auto rtn = original(this, before, after, info);
    logger.info("Health change: {} -> {}", before, after);
    if (before - after > 0.1)
        refreshActorFakeName(dAccess<Mob*>(this, 32));
    return rtn;
}

//TInstanceHook(SetActorDataPacket*, "??0SetActorDataPacket@@QEAA@VActorRuntimeID@@AEAVSynchedActorData@@_N@Z",
//    SetActorDataPacket, class ActorRuntimeID runtimeId,class SynchedActorData & sad,bool isAllData) {
//    auto pkt = original(this, runtimeId, sad, isAllData);
//    auto actor = getRuntimeEntity(mRuntimeId, true);
//    mDataItems.emplace_back(DataItem2<std::string>((DataItemKey)4, CommandUtils::getActorName(*actor)).clone());
//    mDataItems.emplace_back(DataItem2<signed char>((DataItemKey)0x51u, true).clone());
//    return pkt;
//}
TInstanceHook(void, "?write@SetActorDataPacket@@UEBAXAEAVBinaryStream@@@Z",
              SetActorDataPacket, class BinaryStream& bs)
{
    for (auto& item : mDataItems)
    {
        if (item->mDataKey == (DataItemKey)4)
        {
            auto actor = getRuntimeEntity(mRuntimeId, true);
            ((DataItem2<std::string>*)item.get())->mValue = getActorFakeName(actor);
        }
        else if (item->mDataKey == (DataItemKey)0x51u)
        {
            ((DataItem2<bool>*)item.get())->mValue = true;
        }
    }
    original(this, bs);
}
//THook(void, "?write@?$serialize@VDataItem@@@@SAXAEBVDataItem@@AEAVBinaryStream@@@Z",
//      class DataItem const& dataItem, class BinaryStream& bs)
//{
//    switch (dataItem.mDataType)
//    {
//        case DataItemType::BYTE:
//            logger.info("Key: {}, Type: Byte, Value: {}", dataItem.mDataKey, (int)dataItem.getData<unsigned char>());
//            break;
//        case DataItemType::SHORT:
//            logger.info("Key: {}, Type: Short, Value: {}", dataItem.mDataKey, dataItem.getData<unsigned short>());
//            break;
//        case DataItemType::INT:
//            logger.info("Key: {}, Type: Int, Value: {}", dataItem.mDataKey, dataItem.getData<int>());
//            break;
//        case DataItemType::FLOAT:
//            logger.info("Key: {}, Type: Float, Value: {}", dataItem.mDataKey, dataItem.getData<float>());
//            break;
//        case DataItemType::STRING:
//            logger.info("Key: {}, Type: String, Value: {}", dataItem.mDataKey, dataItem.getData<std::string>());
//            break;
//        case DataItemType::NBT:
//            logger.info("Key: {}, Type: CompoundTag, Value: {}", dataItem.mDataKey, dataItem.getData<CompoundTag>().toString());
//            break;
//        case DataItemType::POS:
//            logger.info("Key: {}, Type: BlockPos, Value: {}", dataItem.mDataKey, dataItem.getData<BlockPos>().toString());
//            break;
//        case DataItemType::LONG:
//            logger.info("Key: {}, Type: Int64, Value: {}", dataItem.mDataKey, dataItem.getData<__int64>());
//            break;
//        case DataItemType::VEC3:
//            logger.info("Key: {}, Type: Vec3, Value: {}", dataItem.mDataKey, dataItem.getData<Vec3>().toString());
//            break;
//        default:
//            logger.info("Key: {}, Type: Unknown", dataItem.mDataKey);
//            break;
//    }
//    return original(dataItem, bs);
//}
//TClasslessInstanceHook(void, "?write@AddPlayerPacket@@UEBAXAEAVBinaryStream@@@Z",
//                       class BinaryStream& bs)
//{
//    static int a= 0;
//    a++;
//    //auto b = (voids*)this;
//    logger.error("{}, {}, {}", dAccess<std::string>(this, 72), dAccess<std::string>(this, 136), dAccess<std::string>(this, 568));
//    dAccess<std::string>(this, 568) = fmt::format("aaa{}", a);
//    return original(this, bs);
//}

#endif // ENABLE_TEST_FAKENAME
