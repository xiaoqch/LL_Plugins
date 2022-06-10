#include "pch.h"
#include "ActorDebugCommand.h"
#include <EventAPI.h>
#include <MC/ActorClassTree.hpp>
#include <MC/ActorDefinitionIdentifier.hpp>
#include <MC/AddActorBasePacket.hpp>
#include <MC/Attribute.hpp>
#include <MC/AttributeInstanceDelegate.hpp>
#include <MC/BinaryStream.hpp>
#include <MC/CommandUtils.hpp>
#include <MC/Dimension.hpp>
#include <MC/ExperienceOrb.hpp>
#include <MC/HashedString.hpp>
#include <MC/HealthAttributeDelegate.hpp>
#include <MC/ItemActor.hpp>
#include <MC/ItemStack.hpp>
#include <MC/Level.hpp>
#include <MC/LoopbackPacketSender.hpp>
#include <MC/NetworkItemStackDescriptor.hpp>
#include <MC/Packet.hpp>
#include <MC/ServerPlayer.hpp>
#include <MC/ProjectileComponent.hpp>
#include <MC/ReadOnlyBinaryStream.hpp>
#include <MC/ThrownTrident.hpp>
#include <MC/Util.hpp>
#include <MC/Villager.hpp>
#include <MC/VillagerV2.hpp>
#include <ScheduleAPI.h>
#include <MC/DataItem.hpp>
#include <MC/NetworkHandler.hpp>
#include <MC/NetworkIdentifier.hpp>
//#include <MC/AdventureSettingsPacket.hpp>
//#include <MC/Abilities.hpp>
//#include <MC/Ability.hpp>
//#include <MC/AddActorPacket.hpp>
//#include <MC/AddItemActorPacket.hpp>
//#include <MC/AddPaintingPacket.hpp>
//#include <MC/AddPlayerPacket.hpp>
//#include <MC/AttributeInstance.hpp>
//#include <MC/AttributeInstanceHandle.hpp>
//#include <MC/SynchedActorData.hpp>


enum class ActorCategory2 : int
{
    mBoat = 0x20000,
    mNone = 0x0,
    mWaterAnimal = 0x30,
    mWater = 0x20,
    mUndead = 0x4000,
    mPlayer = 0x1,
    mAnimal = 0x10,
    mMob = 0x2,
    mMonster = 0x4,
    mPathable = 0x40,
    mHumanoid = 0x8,
    mTamable = 0x80,
    mRidable = 0x100,
    mItem = 0x400,
    mAmbient = 0x800,
    mVillager = 0x1000,
    mArthropod = 0x2000,
    mZombie = 0x8000,
    mMinecart = 0x10000,
    mBoatrideable = 0x20100,
    mMinecartRidable = 0x10100,
    mHumanoidMonster = 0xC,
    mTamableAnimal = 0x90,
    mUndeadMob = 0x4004,
    mZombieMonster = 0x8004,
};

enum class ActorType2 : int
{
    Item = 0x40,                     // minecraft:item,                   翻译: 物品
    Tnt = 0x41,                      // minecraft:tnt,                    翻译: TNT 方块
    FallingBlock = 0x42,             // minecraft:falling_block,          翻译: 下落的方块
    MovingBlock = 0x43,              // minecraft:moving_block,           翻译: 移动中的方块
    XpOrb = 0x45,                    // minecraft:xp_orb,                 翻译: 经验球
    EyeOfEnderSignal = 0x46,         // minecraft:eye_of_ender_signal,    翻译: 末影之眼
    EnderCrystal = 0x47,             // minecraft:ender_crystal,          翻译: 末影水晶
    FireworksRocket = 0x48,          // minecraft:fireworks_rocket,       翻译: 焰火火箭
    FishingHook = 0x4D,              // minecraft:fishing_hook,           翻译: 鱼钩
    Chalkboard = 0x4E,               // minecraft:chalkboard,             翻译: entity.chalkboard.name
    Painting = 0x53,                 // minecraft:painting,               翻译: 画
    LeashKnot = 0x58,                // minecraft:leash_knot,             翻译: 拴绳结
    Boat = 0x5A,                     // minecraft:boat,                   翻译: 船
    LightningBolt = 0x5D,            // minecraft:lightning_bolt,         翻译: 闪电
    AreaEffectCloud = 0x5F,          // minecraft:area_effect_cloud,      翻译: 区域效果云雾
    Balloon = 0x6B,                  // minecraft:balloon,                翻译: entity.balloon.name
    Shield = 0x75,                   // minecraft:shield,                 翻译: entity.shield.name
    Npc = 0x0133,                    // minecraft:npc,                    翻译: entity.npc.name
    Agent = 0x0138,                  // minecraft:agent,                  翻译: entity.agent.name
    ArmorStand = 0x013D,             // minecraft:armor_stand,            翻译: 盔甲架
    TripodCamera = 0x013E,           // minecraft:tripod_camera,          翻译: 三脚架摄像机
    Player = 0x013F,                 // minecraft:player,                 翻译: entity.player.name
    Bee = 0x017A,                    // minecraft:bee,                    翻译: 蜜蜂
    Piglin = 0x017B,                 // minecraft:piglin,                 翻译: 猪灵
    PiglinBrute = 0x017F,            // minecraft:piglin_brute,           翻译: 残暴猪灵
    IronGolem = 0x0314,              // minecraft:iron_golem,             翻译: 铁傀儡
    SnowGolem = 0x0315,              // minecraft:snow_golem,             翻译: 雪傀儡
    WanderingTrader = 0x0376,        // minecraft:wandering_trader,       翻译: 流浪商人
    Creeper = 0x0B21,                // minecraft:creeper,                翻译: 爬行者
    Slime = 0x0B25,                  // minecraft:slime,                  翻译: 史莱姆
    Enderman = 0x0B26,               // minecraft:enderman,               翻译: 末影人
    Ghast = 0x0B29,                  // minecraft:ghast,                  翻译: 恶魂
    MagmaCube = 0x0B2A,              // minecraft:magma_cube,             翻译: 岩浆怪
    Blaze = 0x0B2B,                  // minecraft:blaze,                  翻译: 烈焰人
    Witch = 0x0B2D,                  // minecraft:witch,                  翻译: 女巫
    Guardian = 0x0B31,               // minecraft:guardian,               翻译: 守卫者
    ElderGuardian = 0x0B32,          // minecraft:elder_guardian,         翻译: 远古守卫者
    EnderDragon = 0x0B35,            // minecraft:ender_dragon,           翻译: 末影龙
    Shulker = 0x0B36,                // minecraft:shulker,                翻译: 潜影贝
    Vindicator = 0x0B39,             // minecraft:vindicator,             翻译: 卫道士
    Ravager = 0x0B3B,                // minecraft:ravager,                翻译: 劫掠兽
    EvocationIllager = 0x0B68,       // minecraft:evocation_illager,      翻译: 唤魔者
    Vex = 0x0B69,                    // minecraft:vex,                    翻译: 恼鬼
    Pillager = 0x0B72,               // minecraft:pillager,               翻译: 掠夺者
    ElderGuardianGhost = 0x0B78,     // minecraft:elder_guardian_ghost,   翻译: entity.elder_guardian_ghost.name
    Chicken = 0x130A,                // minecraft:chicken,                翻译: 鸡
    Cow = 0x130B,                    // minecraft:cow,                    翻译: 牛
    Pig = 0x130C,                    // minecraft:pig,                    翻译: 猪
    Sheep = 0x130D,                  // minecraft:sheep,                  翻译: 羊
    Mooshroom = 0x1310,              // minecraft:mooshroom,              翻译: 哞菇
    Rabbit = 0x1312,                 // minecraft:rabbit,                 翻译: 兔子
    PolarBear = 0x131C,              // minecraft:polar_bear,             翻译: 北极熊
    Llama = 0x131D,                  // minecraft:llama,                  翻译: 羊驼
    Turtle = 0x134A,                 // minecraft:turtle,                 翻译: 海龟
    Panda = 0x1371,                  // minecraft:panda,                  翻译: 熊猫
    Fox = 0x1379,                    // minecraft:fox,                    翻译: 狐狸
    Hoglin = 0x137C,                 // minecraft:hoglin,                 翻译: 疣猪兽
    Strider = 0x137D,                // minecraft:strider,                翻译: 炽足兽
    Goat = 0x1380,                   // minecraft:goat,                   翻译: 山羊
    Axolotl = 0x1382,                // minecraft:axolotl,                翻译: 美西螈
    Squid = 0x2311,                  // minecraft:squid,                  翻译: 鱿鱼
    Dolphin = 0x231F,                // minecraft:dolphin,                翻译: 海豚
    Pufferfish = 0x236C,             // minecraft:pufferfish,             翻译: 河豚
    Salmon = 0x236D,                 // minecraft:salmon,                 翻译: 鲑鱼
    Tropicalfish = 0x236F,           // minecraft:tropicalfish,           翻译: 热带鱼
    Cod = 0x2370,                    // minecraft:cod,                    翻译: 鳕鱼
    GlowSquid = 0x2381,              // minecraft:glow_squid,             翻译: 发光鱿鱼
    Wolf = 0x530E,                   // minecraft:wolf,                   翻译: 狼
    Ocelot = 0x5316,                 // minecraft:ocelot,                 翻译: 豹猫
    Parrot = 0x531E,                 // minecraft:parrot,                 翻译: 鹦鹉
    Cat = 0x534B,                    // minecraft:cat,                    翻译: 猫
    Bat = 0x8113,                    // minecraft:bat,                    翻译: 蝙蝠
    ZombiePigman = 0x010B24,         // minecraft:zombie_pigman,          翻译: 僵尸猪灵
    Wither = 0x010B34,               // minecraft:wither,                 翻译: 凋灵
    Phantom = 0x010B3A,              // minecraft:phantom,                翻译: 幻翼
    Zoglin = 0x010B7E,               // minecraft:zoglin,                 翻译: 僵尸疣猪兽
    Zombie = 0x030B20,               // minecraft:zombie,                 翻译: 僵尸
    ZombieVillager = 0x030B2C,       // minecraft:zombie_villager,        翻译: 僵尸村民
    Husk = 0x030B2F,                 // minecraft:husk,                   翻译: 尸壳
    Drowned = 0x030B6E,              // minecraft:drowned,                翻译: 溺尸
    ZombieVillagerV2 = 0x030B74,     // minecraft:zombie_villager_v2,     翻译: 怪人村民
    Spider = 0x040B23,               // minecraft:spider,                 翻译: 蜘蛛
    Silverfish = 0x040B27,           // minecraft:silverfish,             翻译: 蠹虫
    CaveSpider = 0x040B28,           // minecraft:cave_spider,            翻译: 洞穴蜘蛛
    Endermite = 0x040B37,            // minecraft:endermite,              翻译: 末影螨
    Minecart = 0x080054,             // minecraft:minecart,               翻译: 矿车
    HopperMinecart = 0x080060,       // minecraft:hopper_minecart,        翻译: 漏斗矿车
    TntMinecart = 0x080061,          // minecraft:tnt_minecart,           翻译: TNT 矿车
    ChestMinecart = 0x080062,        // minecraft:chest_minecart,         翻译: 运输矿车
    CommandBlockMinecart = 0x080064, // minecraft:command_block_minecart, 翻译: 命令方块矿车
    Skeleton = 0x110B22,             // minecraft:skeleton,               翻译: 骷髅
    Stray = 0x110B2E,                // minecraft:stray,                  翻译: 流浪者
    WitherSkeleton = 0x110B30,       // minecraft:wither_skeleton,        翻译: 凋灵骷髅
    Horse = 0x205317,                // minecraft:horse,                  翻译: 马
    Donkey = 0x205318,               // minecraft:donkey,                 翻译: 驴
    Mule = 0x205319,                 // minecraft:mule,                   翻译: 骡子
    SkeletonHorse = 0x215B1A,        // minecraft:skeleton_horse,         翻译: 骷髅马
    ZombieHorse = 0x215B1B,          // minecraft:zombie_horse,           翻译: 僵尸马
    XpBottle = 0x400044,             // minecraft:xp_bottle,              翻译: 附魔之瓶
    ShulkerBullet = 0x40004C,        // minecraft:shulker_bullet,         翻译: 潜影贝子弹
    DragonFireball = 0x40004F,       // minecraft:dragon_fireball,        翻译: 末影龙火球
    Snowball = 0x400051,             // minecraft:snowball,               翻译: 雪球
    Egg = 0x400052,                  // minecraft:egg,                    翻译: 鸡蛋
    Fireball = 0x400055,             // minecraft:fireball,               翻译: 火球
    SplashPotion = 0x400056,         // minecraft:splash_potion,          翻译: 药水
    EnderPearl = 0x400057,           // minecraft:ender_pearl,            翻译: 末影珍珠
    WitherSkull = 0x400059,          // minecraft:wither_skull,           翻译: 凋灵头颅
    WitherSkullDangerous = 0x40005B, // minecraft:wither_skull_dangerous, 翻译: 凋灵头颅
    SmallFireball = 0x40005E,        // minecraft:small_fireball,         翻译: 小火球
    LingeringPotion = 0x400065,      // minecraft:lingering_potion,       翻译: 滞留药水
    LlamaSpit = 0x400066,            // minecraft:llama_spit,             翻译: 羊驼口水
    EvocationFang = 0x400067,        // minecraft:evocation_fang,         翻译: 唤魔者尖牙
    IceBomb = 0x40006A,              // minecraft:ice_bomb,               翻译: entity.ice_bomb.name
    ThrownTrident = 0xC00049,        // minecraft:thrown_trident,         翻译: 三叉戟
    Arrow = 0xC00050,                // minecraft:arrow,                  翻译: 箭
    Villager = 0x0100030F,           // minecraft:villager,               翻译: 村民
    VillagerV2 = 0x01000373,         // minecraft:villager_v2,            翻译: 村民
};

std::string getActorFakeName(Actor* actor);

struct ActorMapping
{
    std::string mNameSpace;
    std::string mName;
    std::string mAlias;
    HashedString mMappingName;

public:
    MCAPI ActorMapping(std::string const&, std::string const&, std::string const&);
    MCAPI ActorMapping(std::string const&, std::string const&);
    MCAPI std::string getMappingName(enum ActorTypeNamespaceRules) const;
    MCAPI ~ActorMapping();
};

void testDataItem()
{
    // Test destructor of DataItem2
    std::string* str;
    {
        auto item = DataItem::create(1, fmt::format("{},{}", "0LoopbackPacketSender@@QEAA@EAEAVNetworkHandler@@@Z", "[02:16:08 Info][Item] ActorEventCoordinator::sendActorCarriedItemChanged actor: , previouslyCarriedItem: 0 x (0)@0, carriedItem: 1 x 弓(300)@0, hand: 0"));
        auto item2 = item->clone();
        ASSERT(item->isDataEqual(*item2));
        //ASSERT((*(uintptr_t**)item.get())[2] == (*(uintptr_t**)item2.get())[2]);
        str = &item->getData<std::string>();
        ASSERT(*str == "0LoopbackPacketSender@@QEAA@EAEAVNetworkHandler@@@Z,[02:16:08 Info][Item] ActorEventCoordinator::sendActorCarriedItemChanged actor: , previouslyCarriedItem: 0 x (0)@0, carriedItem: 1 x 弓(300)@0, hand: 0");
    }
    //logger.error(*str);
    ASSERT(*str != "0LoopbackPacketSender@@QEAA@EAEAVNetworkHandler@@@Z,[02:16:08 Info][Item] ActorEventCoordinator::sendActorCarriedItemChanged actor: , previouslyCarriedItem: 0 x (0)@0, carriedItem: 1 x 弓(300)@0, hand: 0");
    Schedule::delay([str]() {
        //logger.error(*str);
        ASSERT(*str != "0LoopbackPacketSender@@QEAA@EAEAVNetworkHandler@@@Z,[02:16:08 Info][Item] ActorEventCoordinator::sendActorCarriedItemChanged actor: , previouslyCarriedItem: 0 x (0)@0, carriedItem: 1 x 弓(300)@0, hand: 0");
    },
                    200);
}
#include <MC/I18n.hpp>
void printActorCategory()
{
    auto& entityTypeMap = *(std::unordered_map<enum class ActorType2, struct ActorMapping>*)dlsym("?ENTITY_TYPE_MAP@@3V?$unordered_map@W4ActorType@@UActorMapping@@U?$hash@W4ActorType@@@std@@U?$equal_to@W4ActorType@@@4@V?$allocator@U?$pair@$$CBW4ActorType@@UActorMapping@@@std@@@4@@std@@A");
    std::map<enum class ActorType2, struct ActorMapping> sortedMap;
    std::transform(entityTypeMap.begin(), entityTypeMap.end(), std::inserter(sortedMap, sortedMap.begin()),
                   [](std::pair<enum class ActorType2, struct ActorMapping> a) { return std::pair<enum class ActorType2, struct ActorMapping>(a.first, a.second); });
    logger.info("enum class ActorType2 : int {");
    for (auto& [type, mapping] : sortedMap)
    {
        auto currentLang = I18n::getCurrentLanguage().get();
        auto nameKey = fmt::format("%entity.{}.name", mapping.mName);
        auto trName = I18n::get(nameKey, currentLang);
        logger.info("                           \r    {:21s} = 0x{:08X}, // fullname: {}, 翻译: {}",
                    Util::toCamelCase("m_" + mapping.getMappingName((ActorTypeNamespaceRules)0), '_').substr(1),
                    (int)type,
                    mapping.getMappingName((ActorTypeNamespaceRules)1),
                    trName
                    //,mapping.mAlias
        );
    }
    logger.info("};");

    SymCall("?entityCategoryFromString@@YA?AW4ActorCategory@@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z", void, std::string const&)("none");
    //((void (*)(std::string const&))(       0x1421C8AD4 -        0x141F4EA20 + (uintptr_t)ptr))("none");
    auto tmpPtr = dlsym("?mFeatureToggles@FeatureToggles@@0V?$unique_ptr@VFeatureToggles@@U?$default_delete@VFeatureToggles@@@std@@@std@@A");
    auto& categoryMap = *(std::unordered_map<std::string, enum class ActorCategory2>*)((uintptr_t)16 + (uintptr_t)tmpPtr);
    logger.info("enum class ActorCategory2 : int {");
    for (auto& [name, category] : categoryMap)
    {
        logger.info("    {} = 0x{:06X},", Util::toCamelCase("m_" + name, '_').substr(1), (int)category);
    }
    logger.info("};");
}

template <>
LoopbackPacketSender* Global<LoopbackPacketSender>;
TInstanceHook(LoopbackPacketSender*, "??0LoopbackPacketSender@@QEAA@EAEAVNetworkHandler@@@Z",
              LoopbackPacketSender, unsigned char unk, class NetworkHandler& handler)
{
#ifdef PRINT_ENUM
    testDataItem();
    Schedule::delay(
        []() {
            printActorCategory();
        },
        50);
#endif // DEBUG

    Global<LoopbackPacketSender> = this;
    return original(this, unk, handler);
}

class SynchedActorData
{
public:
    //using DataList = std::vector<std::unique_ptr<DataItem>>;
    std::vector<std::unique_ptr<DataItem>> mItemsArray; //0
private:
    unsigned short mMinDirtyId; //24
    unsigned short mMaxDirtyId; //26
public:
    template <typename T>
    MCAPI void define(unsigned short, T const&);
    template <typename T>
    MCAPI void set(unsigned short, T const&);
    inline std::vector<std::unique_ptr<DataItem>>& getItemArray()
    {
        return mItemsArray;
    }

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


#pragma region SetActorDataPacket

// ============= SetActorDataPacket =============
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

static_assert(offsetof(SetActorDataPacket, mDataItems) == 64);

#pragma endregion

#pragma region AddActorPacket

// ============= AddActorPacket =============
class AttributeInstanceHandle
{
    unsigned int mAttributeID;
    BaseAttributeMap* mAttributeMap;

public:
    MCAPI class AttributeInstance const& getInstance() const;
    MCAPI class AttributeInstance* getMutableInstance() const;
};
class BaseAttributeMap;
class AttributeInstance
{
public:
    BaseAttributeMap* mAttributeMap;                      //8
    Attribute* mAttribute;                                //16
    std::vector<AttributeModifier> mModifierList;         //24
    std::vector<TemporalAttributeBuff> mTemporalBuffs;    //48
    std::vector<AttributeInstanceHandle> mListeners;      //72
    std::shared_ptr<AttributeInstanceDelegate> mDelegate; //96
    float mDefaultMin;
    float mDefaultMax;
    float mDefaultValue;
    float mMinValue; //124
    float mMaxValue;
    float mCurrentValue;

public:
    /*0*/ virtual ~AttributeInstance();
    /*1*/ virtual void tick();
    MCAPI AttributeInstance(class AttributeInstance const&);
    MCAPI AttributeInstance();
    MCAPI void addBuff(class AttributeBuff const&);
    MCAPI void addModifier(class AttributeModifier const&);
    MCAPI void addModifier(class std::shared_ptr<class AttributeModifier>);
    MCAPI class Attribute const* getAttribute() const;
    MCAPI std::vector<class TemporalAttributeBuff> const& getBuffs() const;
    MCAPI float getCurrentValue() const;
    MCAPI float getDefaultValue(int) const;
    MCAPI class AttributeInstanceHandle getHandle() const;
    MCAPI std::vector<class AttributeInstanceHandle> const& getListeners() const;
    MCAPI float getMaxValue() const;
    MCAPI float getMinValue() const;
    MCAPI class AttributeModifier getModifier(class mce::UUID const&) const;
    MCAPI std::vector<class AttributeModifier> getModifiers(int) const;
    MCAPI std::vector<class AttributeModifier> getModifiers() const;
    MCAPI bool hasModifier(class mce::UUID const&) const;
    MCAPI bool hasModifier(class std::shared_ptr<class AttributeModifier>) const;
    MCAPI bool hasModifiers() const;
    MCAPI bool hasTemporalBuffs() const;
    MCAPI bool isValid() const;
    MCAPI void notify(__int64);
    MCAPI void recalculateModifiers();
    MCAPI void registerListener(class AttributeInstance const&);
    MCAPI void removeBuff(class std::shared_ptr<class AttributeBuff>);
    MCAPI void removeBuffs();
    MCAPI void removeModifier(class AttributeModifier const&);
    MCAPI void removeModifier(class std::shared_ptr<class AttributeModifier>);
    MCAPI bool removeModifier(class mce::UUID const&);
    MCAPI void resetToDefaultValue();
    MCAPI void resetToMaxValue();
    MCAPI void resetToMinValue();
    MCAPI void serializationSetRange(float, float, float);
    MCAPI void serializationSetValue(float, int, float);
    MCAPI void setCurrentValue(float);
    MCAPI void setDefaultValue(float, int);
    MCAPI void setDefaultValueOnly(float);
    MCAPI void setDelegate(class std::shared_ptr<class AttributeInstanceDelegate>);
    MCAPI void setMaxValue(float);
    MCAPI void setRange(float, float, float);
};
static_assert(offsetof(AttributeInstance, mMinValue) == 124);
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
        bs.writeType(mPosition);
        bs.writeType(mVelocity);
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
        auto actor = Global<Level>->getRuntimeEntity(mRuntimeId, true);
        auto fakeName = getActorFakeName(actor);
        dataItems.emplace_back(DataItem::create(ActorDataIDs::NAMETAG, fakeName));
        dataItems.emplace_back(DataItem::create<signed char>(ActorDataIDs::ALWAYS_SHOW_NAMETAG, true));
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
static_assert(offsetof(AddActorPacket, mType) == 160);
static_assert(offsetof(AddActorPacket, mAttributeHandles) == 336);

#pragma endregion

#pragma region AddItemActorPacket

// ============= AddItemActorPacket =============
class AddItemActorPacket : public Packet
{
public:
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
        bs.writeType(mPos);
        bs.writeType(mVelocity);
        auto dataItems = mActorData->packAll();
        auto actor = Global<Level>->getRuntimeEntity(mRuntimeId, true);
        auto fakeName = getActorFakeName(actor);
        dataItems.emplace_back(DataItem::create(ActorDataIDs::NAMETAG, fakeName));
        dataItems.emplace_back(DataItem::create<signed char>(ActorDataIDs::ALWAYS_SHOW_NAMETAG, true));
        bs.writeType(dataItems);

        bs.writeBool(mIsFromFishing);
    }
};
static_assert(offsetof(AddItemActorPacket, mActorData) == 72);
static_assert(sizeof(ItemStackNetIdVariant) == 24);
static_assert(sizeof(AddItemActorPacket) == 280);

#pragma endregion

#pragma region AddPaintingPacket

// ============= AddPaintingPacket =============
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
        bs.writeType(mPos);
        bs.writeVarInt(mDirection);
        bs.writeString(mMotive);
    }
};

#pragma endregion

#pragma region AddPlayerPacket

// ============= AddPlayerPacket =============
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
    std::array<Ability, 18> mCustomAbilityCache;
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
//static_assert(sizeof(Abilities) == 336);
struct AdventureSettings
{
    char filler[26];

public:
    MCAPI AdventureSettings();
};
class AdventureSettingsPacket : public Packet
{
    char filler[80 - sizeof(Packet)];

public:
    /*0*/ virtual ~AdventureSettingsPacket();
    /*1*/ virtual enum MinecraftPacketIds getId() const;
    /*2*/ virtual std::string getName() const;
    /*3*/ virtual void write(class BinaryStream&) const;
    /*4*/ virtual bool disallowBatching() const;
    /*5*/ virtual enum StreamReadResult _read(class ReadOnlyBinaryStream&);
    MCAPI AdventureSettingsPacket(struct AdventureSettings const&, class Abilities const&, struct ActorUniqueID, bool);
};
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
    std::vector<std::unique_ptr<DataItem>> mDataItems; //208, only for deserialize
    Abilities mAbilities;                              //232
    std::string mDeviceId;                             //688
    enum BuildPlatform mBuildPlatform;                 //720
    char pad_604[4];                                   //604
    NetworkItemStackDescriptor mCarriedItem;           //728
    SynchedActorData* mActorData;                      //880
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
        bs.writeString(getActorFakeName(Global<Level>->getRuntimeEntity(mRuntimeId, true)));
        bs.writeVarInt64(mUniqueId.id);
        bs.writeUnsignedVarInt64(mRuntimeId.id);
        bs.writeString(mPlatformOnlineId);
        bs.writeType(mPosition);
        bs.writeType(mVelocity);
        bs.writeFloat(mPitch);
        bs.writeFloat(mYaw);
        bs.writeFloat(mHeadYaw);
        bs.writeType(mCarriedItem);
        auto dataItems = mActorData->packAll();
        auto actor = Global<Level>->getRuntimeEntity(mRuntimeId, true);
        auto fakeName = getActorFakeName(actor);
        dataItems.emplace_back(DataItem::create(ActorDataIDs::NAMETAG, fakeName));
        dataItems.emplace_back(DataItem::create<signed char>(ActorDataIDs::ALWAYS_SHOW_NAMETAG, true));
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
constexpr auto a = offsetof(AddPlayerPacket, mCarriedItem);
static_assert(sizeof(AddPlayerPacket) == 888);
static_assert(offsetof(AddPlayerPacket, mDataItems) == 208);
static_assert(offsetof(AddPlayerPacket, mAbilities) == 232);
static_assert(offsetof(AddPlayerPacket, mDeviceId) == 688);
static_assert(offsetof(AddPlayerPacket, mBuildPlatform) == 720);
static_assert(offsetof(AddPlayerPacket, mCarriedItem) == 728);
static_assert(offsetof(AddPlayerPacket, mActorData) == 880);

#pragma endregion

void setActorFakeName(Actor* actor, std::string const& fakeName)
{
    SetActorDataPacket packet;
    packet.mRuntimeId = actor->getRuntimeID();
    packet.mDataItems.emplace_back(DataItem::create(ActorDataIDs::NAMETAG, fakeName));
    packet.mDataItems.emplace_back(DataItem::create<signed char>(ActorDataIDs::ALWAYS_SHOW_NAMETAG, true));
    Global<LoopbackPacketSender>->sendBroadcast(packet);
}

#define FmtArg(name) fmt::arg(#name, name)
#define GetArg(name) std::move(name)
#define BuildArg(name)\
ActorArg::ArgType::name __##name;\
auto&& name = ActorArg::getArg<currentActorType, ActorArg::ArgName::name, ActorArg::ArgType::name>(actor, __##name)

#pragma region ActorFakeNameBuilder

#include <MC/SharedAttributes.hpp>
namespace ActorArg
{
template <typename T>
static const fmt::detail::named_arg<char, T> EMPTY_ARG = {"", T()};
enum class FormatType
{
    Actor,
    Player,
    Unmovable,
    Item,
    XpOrb,
    Monster,
    Boss,
    Friendly,
    Vehicle,
    Mount,
    Projectile,
    Arrow,
    Trident,
    Villager,
    Crafted,
    Attackable,
    WanderingTrader,
    Other,
};
enum class ArgName
{
    Name,
    UID,
    Type,
    AgeInfo,
    DamageInfo,
    ItemInfo,
    HealthInfo,
    Exp,
    Health,
    MaxHealth,
    Hunger,
    MaxHunger,
    OwnerInfo,
    IsCreative,
    IsPlayer,
    Attack,
    Speed,
    JumpStrength,
};
namespace ArgType
{
typedef std::string Name;
typedef __int64 UID;
typedef std::string Type;
typedef std::string AgeInfo;
typedef std::string DamageInfo;
typedef std::string ItemInfo;
typedef std::string HealthInfo;
typedef int Exp;
typedef int Health;
typedef int MaxHealth;
typedef float Hunger;
typedef float MaxHunger;
typedef std::string OwnerInfo;
typedef bool IsCreative;
typedef bool IsPlayer;
typedef float Attack;
typedef float Speed;
typedef float JumpStrength;
} // namespace ArgType

template <FormatType actorType, ArgName argName>
static bool argEnable = false;
template <ArgName argName, typename ArgType>
inline ArgType getArgValue(Actor* actor, FormatType actorType = FormatType::Actor) = delete;
template <>
inline ArgType::Name getArgValue<ArgName::Name>(Actor* actor, FormatType actorType)
{
    if (actorType == FormatType::Trident)
    {
        auto item = &dAccess<ItemStack>(actor, 1872);
        if (item&&!item->isNull())
        {
            std::string customName = item->getCustomName();
            if (!customName.empty())
                return customName;
        }
    }
    return CommandUtils::getActorName(*actor);
}
template <>
inline ArgType::UID getArgValue<ArgName::UID>(Actor* actor, FormatType actorType)
{
    return actor->getUniqueID().id;
}
template <>
inline ArgType::Type getArgValue<ArgName::Type>(Actor* actor, FormatType actorType)
{
    return actor->getTypeName();
}

template <>
inline ArgType::AgeInfo getArgValue<ArgName::AgeInfo>(Actor* actor, FormatType actorType)
{
    constexpr auto formatAgeInfo = "§b{RemainingAge}§r/§b{MaxAge}§rs";
    float Age;
    float MaxAge;
    if (actorType == FormatType::Item)
    {
        MaxAge = ((ItemActor*)actor)->getDespawnTime() / 20.0f;
        Age = ((ItemActor*)actor)->getLatestSpawnTime() / 20.0f;
    }
    else if (actorType == FormatType::XpOrb)
    {
        MaxAge = 300.0f;
        Age = dAccess<unsigned short>(actor, 1868) / 20.0f;
    }
    else if (actorType == FormatType::Arrow)
    {
    }
    else
        return ArgType::AgeInfo();
    float RemainingAge = MaxAge - Age;
    return fmt::format(formatAgeInfo, FmtArg(Age), FmtArg(MaxAge), FmtArg(RemainingAge));
}

template <>
inline ArgType::DamageInfo getArgValue<ArgName::DamageInfo>(Actor* actor, FormatType actorType)
{
    constexpr auto formatDamageInfo = "§b{RemainingDamage}§r/§b{MaxDamage}§rs";
    float Damage;
    float MaxDamage;
    if (actorType == FormatType::Item)
    {
        auto item = ((ItemActor*)actor)->getItemStack();
        MaxDamage = item->getMaxDamage();
        Damage = item->getDamageValue();
    }
    else if (actorType == FormatType::Trident)
    {
        auto& item = dAccess<ItemStack>(actor, 1848); // ThrownTrident::playerTouch
        MaxDamage = item.getMaxDamage();
        Damage = item.getDamageValue();
    }
    else
        return "";
    float RemainingDamage = MaxDamage - Damage;
    return fmt::format(formatDamageInfo, FmtArg(Damage), FmtArg(MaxDamage), FmtArg(RemainingDamage));
}

template <>
inline ArgType::ItemInfo getArgValue<ArgName::ItemInfo>(Actor* actor, FormatType actorType)
{
    if (actorType != FormatType::Item)
    {
        logger.error("e");
        return ArgType::ItemInfo();
    }
    auto item = ((ItemActor*)actor)->getItemStack();
    auto maxStackSize = item->getMaxStackSize();
    if (maxStackSize > 1)
    {
        static auto formatItemCount = " ⨯ {Count}";
        auto Count = item->getCount();
        return fmt::format(formatItemCount, FmtArg(Count));
    }
    else if (item->isDamageableItem())
    {
        return getArgValue<ArgName::DamageInfo, ArgType::DamageInfo>(actor, actorType);
    }
    return "";
}

template <>
inline ArgType::Health getArgValue<ArgName::Health>(Actor* actor, FormatType actorType)
{
    return actor->getHealth();
}
template <>
inline ArgType::MaxHealth getArgValue<ArgName::MaxHealth>(Actor* actor, FormatType actorType)
{
    return actor->getMaxHealth();
}
template <>
inline ArgType::HealthInfo getArgValue<ArgName::HealthInfo>(Actor* actor, FormatType actorType)
{
    static auto formatHelpthInfo = "§c❤§a{Health}§r/§a{MaxHealth}§r";
    auto MaxHealth = actor->getMaxHealth();
    auto Health = actor->getHealth();
    return fmt::format(formatHelpthInfo, FmtArg(Health), FmtArg(MaxHealth));
}
template <>
inline ArgType::Hunger getArgValue<ArgName::Hunger>(Actor* actor, FormatType actorType)
{
    if (actorType == FormatType::Player)
        return ((Player*)actor)->getAttribute(Player::HUNGER).getCurrentValue();
    return ArgType::Hunger();
}
template <>
inline ArgType::MaxHunger getArgValue<ArgName::MaxHunger>(Actor* actor, FormatType actorType)
{
    if (actorType == FormatType::Player)
        return ((Player*)actor)->getAttribute(Player::HUNGER).getMaxValue();
    return ArgType::MaxHunger();
}
template <>
inline ArgType::OwnerInfo getArgValue<ArgName::OwnerInfo>(Actor* actor, FormatType actorType)
{
    auto ownerId = actor->getOwnerId();
    if (auto ownerActor = Level::getEntity(ownerId))
    {
        return fmt::format("\n§b拥有者§r：{}", CommandUtils::getActorName(*ownerActor));
    }
    else if (ownerId != -1 && ownerId != 0)
    {
        return fmt::format("\n§7拥有者：0x{:016x}§r", *(unsigned __int64*)&ownerId);
    }
    return ArgType::OwnerInfo();
}
template <>
inline ArgType::IsCreative getArgValue<ArgName::IsCreative>(Actor* actor, FormatType actorType)
{
    if (actorType == FormatType::Arrow || actorType == FormatType::Trident)
        return dAccess<bool>(actor, 1861) ? "§a§l✓§r" : "§4§l✗§r";
    return ArgType::IsCreative();
}
template <>
inline ArgType::IsPlayer getArgValue<ArgName::IsPlayer>(Actor* actor, FormatType actorType)
{

    if (actorType == FormatType::Arrow || actorType == FormatType::Trident)
        return dAccess<bool>(actor, 1860) ? "§a§l✓§r" : "§4§l✗§r";
    return ArgType::IsPlayer();
}
template <>
inline ArgType::Attack getArgValue<ArgName::Attack>(Actor* actor, FormatType actorType)
{
    auto value = actor->getAttribute(SharedAttributes::ATTACK_DAMAGE).getCurrentValue();
    value += actor->getCarriedItem().getAttackDamage();
    if (actor->hasEffect(*MobEffect::DAMAGE_BOOST))
    {
        auto effect = actor->getEffect(*MobEffect::DAMAGE_BOOST);
        auto amplifier = effect->getAmplifier() + 1;
        auto v12 = 0;
        if (amplifier >= 8)
        {
            auto v13 = ((unsigned int)(amplifier - 8) >> 3) + 1;
            auto v14 = v13;
            v12 = 8 * v13;
            do
            {
                value = (float)(int)(float)((float)((float)(int)(float)((float)((float)(int)(float)((float)((float)(int)(float)((float)((float)(int)(float)((float)((float)(int)(float)((float)((float)(int)(float)((float)((float)(int)(float)((float)((float)value * 1.3) + 1.0) * 1.3) + 1.0) * 1.3) + 1.0) * 1.3) + 1.0) * 1.3) + 1.0) * 1.3) + 1.0) * 1.3) + 1.0) * 1.3) + 1.0);
                --v14;
            } while (v14);
        }
        if (v12 < amplifier)
        {
            auto v15 = (unsigned int)(amplifier - v12);
            do
            {
                value = (float)(int)(float)((float)((float)value * 1.3) + 1.0);
                --v15;
            } while (v15);
        }
    }
    if (actor->hasEffect(*MobEffect::WEAKNESS))
    {
        auto effect = actor->getEffect(*MobEffect::WEAKNESS);
        auto amplifier = effect->getAmplifier() + 1;
        auto v18 = 0;
        if (amplifier > 0)
        {
            while (1)
            {
                value = (float)(int)(float)((float)((float)value * 0.80000001) - 0.5);
                if (value < 0)
                {
                    value = 0;
                    break;
                }
                if (++v18 >= amplifier)
                    break;
            }
        }
    }
    return value;
}
template <>
inline ArgType::Exp getArgValue<ArgName::Exp>(Actor* actor, FormatType actorType)
{
    if (actorType == FormatType::XpOrb)
        return dAccess<SynchedActorData>(actor, 376).getInt((unsigned short)ActorDataIDs::EXPERIENCE_VALUE);
    return ArgType::Exp();
}
template <>
inline ArgType::Speed getArgValue<ArgName::Speed>(Actor* actor, FormatType actorType)
{
    return actor->getAttribute(SharedAttributes::MOVEMENT_SPEED).getDefaultValue(2);
}
template <>
inline ArgType::JumpStrength getArgValue<ArgName::JumpStrength>(Actor* actor, FormatType actorType)
{
    return actor->getAttribute(SharedAttributes::JUMP_STRENGTH).getDefaultValue(2);
}


template <FormatType actorType, ArgName argName, typename ArgType>
inline fmt::detail::named_arg<char, ArgType> getArg(Actor* actor, ArgType& argValue)
{
    //if (!argEnable<FormatType, argName>)
    //    return EMPTY_ARG<ArgType>;
    constexpr auto enumName = magic_enum::enum_name(argName).data();
    argValue = getArgValue<argName, ArgType>(actor, actorType);
    return {enumName, argValue};
};

} // namespace ActorArg

#define BuildCommomArg()    \
    BuildArg(Name);         \
    BuildArg(Type);         \
    BuildArg(UID);          \
    BuildArg(Speed);        \
    BuildArg(JumpStrength); \
    BuildArg(HealthInfo);

#define GetCommomArg() \
    GetArg(Name), GetArg(Type), GetArg(UID), GetArg(Speed), GetArg(JumpStrength), GetArg(HealthInfo)

template <ActorArg::FormatType actorType>
std::string getFakeName(Actor* actor) = delete;

template <>
std::string getFakeName<ActorArg::FormatType::Item>(Actor* actor)
{
    constexpr auto currentActorType = ActorArg::FormatType::Item;
    static auto formatItemActor = "{Name}{ItemInfo}\n§7{Type}\n{AgeInfo}";

    BuildCommomArg();
    BuildArg(ItemInfo);
    BuildArg(AgeInfo);

    return fmt::format(formatItemActor, GetCommomArg(), GetArg(ItemInfo), GetArg(AgeInfo));
}
template <>
std::string getFakeName<ActorArg::FormatType::Projectile>(Actor* actor)
{
    constexpr auto currentActorType = ActorArg::FormatType::Projectile;
    static auto formatItemActor = "{Name}\n§7{Type}{OwnerInfo}";

    BuildCommomArg();
    BuildArg(OwnerInfo);

    return fmt::format(formatItemActor, GetCommomArg(), GetArg(OwnerInfo));
}
template <>
std::string getFakeName<ActorArg::FormatType::Arrow>(Actor* actor)
{
    constexpr auto currentActorType = ActorArg::FormatType::Arrow;
    static auto formatItemActor = "{Name}\n§7{Type}{OwnerInfo}\n§e创造§r：{IsCreative}，§e玩家§r：{IsPlayer}";

    BuildCommomArg();
    BuildArg(OwnerInfo);
    BuildArg(IsCreative);
    BuildArg(IsPlayer);

    return fmt::format(formatItemActor, GetCommomArg(), GetArg(OwnerInfo), GetArg(IsCreative), GetArg(IsPlayer));
}
template <>
std::string getFakeName<ActorArg::FormatType::Trident>(Actor* actor)
{
    constexpr auto currentActorType = ActorArg::FormatType::Trident;
    static auto formatItemActor = "{Name} {DamageInfo}\n§7{Type}{OwnerInfo}\n§e创造§r：{IsCreative}，§e玩家§r：{IsPlayer}";

    BuildCommomArg();
    BuildArg(DamageInfo);
    BuildArg(OwnerInfo);
    BuildArg(IsCreative);
    BuildArg(IsPlayer);

    return fmt::format(formatItemActor, GetCommomArg(), GetArg(DamageInfo), GetArg(OwnerInfo), GetArg(IsCreative), GetArg(IsPlayer));
}
template <>
std::string getFakeName<ActorArg::FormatType::XpOrb>(Actor* actor)
{
    constexpr auto currentActorType = ActorArg::FormatType::XpOrb;
    static auto formatItemActor = "{Name} - {Exp}\n§7{Type}\n{AgeInfo}";

    BuildCommomArg();
    BuildArg(AgeInfo);
    BuildArg(Exp);

    return fmt::format(formatItemActor, GetCommomArg(), GetArg(AgeInfo), GetArg(Exp));
}
template <>
std::string getFakeName<ActorArg::FormatType::Player>(Actor* actor)
{
    constexpr auto currentActorType = ActorArg::FormatType::Player;
    static auto formatItemActor = "{Name}\n§7{Type}\n{HealthInfo} §b{Hunger}§r/§b{MaxHunger}§r";

    BuildCommomArg();
    BuildArg(Health);
    BuildArg(MaxHealth);
    BuildArg(Hunger);
    BuildArg(MaxHunger);
    return fmt::format(formatItemActor, GetCommomArg(), GetArg(Health), GetArg(MaxHealth), GetArg(Hunger), GetArg(MaxHunger));
}
template <>
std::string getFakeName<ActorArg::FormatType::Unmovable>(Actor* actor)
{
    constexpr auto currentActorType = ActorArg::FormatType::Unmovable;
    static auto formatItemActor = "{Name}\n§7{Type}\n{HealthInfo}";

    BuildCommomArg();

    return fmt::format(formatItemActor, GetCommomArg());
}
template <>
std::string getFakeName<ActorArg::FormatType::Monster>(Actor* actor)
{
    constexpr auto currentActorType = ActorArg::FormatType::Monster;
    static auto formatItemActor = "{Name}\n§7{Type}\n{HealthInfo} §l§4⚔§r: {Attack}";

    BuildCommomArg();
    BuildArg(Attack);

    return fmt::format(formatItemActor, GetCommomArg(), GetArg(Attack));
}
template <>
std::string getFakeName<ActorArg::FormatType::Attackable>(Actor* actor)
{
    constexpr auto currentActorType = ActorArg::FormatType::Attackable;
    static auto formatItemActor = "{Name}\n§7{Type}\n{HealthInfo} §l§4⚔§r: {Attack}{OwnerInfo}";

    BuildCommomArg();
    BuildArg(Attack);
    BuildArg(OwnerInfo);

    return fmt::format(formatItemActor, GetCommomArg(), GetArg(Attack), GetArg(OwnerInfo));
}
template <>
std::string getFakeName<ActorArg::FormatType::Boss>(Actor* actor)
{
    constexpr auto currentActorType = ActorArg::FormatType::Boss;
    static auto formatItemActor = "{Name}\n§7{Type}\n{HealthInfo} §l§4⚔§r: {Attack}";

    BuildCommomArg();
    BuildArg(Attack);
    BuildArg(OwnerInfo);

    return fmt::format(formatItemActor, GetCommomArg(), GetArg(Attack), GetArg(OwnerInfo));
}
template <>
std::string getFakeName<ActorArg::FormatType::Friendly>(Actor* actor)
{
    constexpr auto currentActorType = ActorArg::FormatType::Friendly;
    static auto formatItemActor = "{Name}\n§7{Type}\n{HealthInfo}{OwnerInfo}";

    BuildCommomArg();
    BuildArg(OwnerInfo);

    return fmt::format(formatItemActor, GetCommomArg(), GetArg(OwnerInfo));
}
template <>
std::string getFakeName<ActorArg::FormatType::Villager>(Actor* actor)
{
    constexpr auto currentActorType = ActorArg::FormatType::Villager;
    static auto formatItemActor = "{Name}\n§7{Type}\n{HealthInfo}";

    BuildCommomArg();

    return fmt::format(formatItemActor, GetCommomArg());
}
template <>
std::string getFakeName<ActorArg::FormatType::Crafted>(Actor* actor)
{
    constexpr auto currentActorType = ActorArg::FormatType::Crafted;
    static auto formatItemActor = "{Name}\n§7{Type}\n{HealthInfo} §l§4⚔§r: {Attack}{OwnerInfo}";

    BuildCommomArg();
    BuildArg(Attack);
    BuildArg(OwnerInfo);

    return fmt::format(formatItemActor, GetCommomArg(), GetArg(Attack), GetArg(OwnerInfo));
}
template <>
std::string getFakeName<ActorArg::FormatType::Vehicle>(Actor* actor)
{
    constexpr auto currentActorType = ActorArg::FormatType::Vehicle;
    static auto formatItemActor = "{Name}\n§7{Type}";

    BuildCommomArg();

    return fmt::format(formatItemActor, GetCommomArg());
}
template <>
std::string getFakeName<ActorArg::FormatType::Mount>(Actor* actor)
{
    constexpr auto currentActorType = ActorArg::FormatType::Mount;
    static auto formatItemActor = "{Name}\n§7{Type}\n{HealthInfo}\nSpeed: {Speed:.2f}, Jump: {JumpStrength:.2f}{OwnerInfo}";

    BuildCommomArg();
    BuildArg(OwnerInfo);

    return fmt::format(formatItemActor, GetCommomArg(), GetArg(OwnerInfo));
}
template <>
std::string getFakeName<ActorArg::FormatType::Other>(Actor* actor)
{
    constexpr auto currentActorType = ActorArg::FormatType::Other;
    static auto formatItemActor = "{Name}\n§7{Type}{OwnerInfo}";

    BuildCommomArg();
    BuildArg(OwnerInfo);

    return fmt::format(formatItemActor, GetCommomArg(), GetArg(OwnerInfo));
}
template <>
std::string getFakeName<ActorArg::FormatType::WanderingTrader>(Actor* actor)
{
    constexpr auto currentActorType = ActorArg::FormatType::WanderingTrader;
    static auto formatItemActor = "{Name}\n§7{Type}\n{HealthInfo}";

    BuildCommomArg();

    return fmt::format(formatItemActor, GetCommomArg());
}

std::string getActorFakeName(Actor* actor)
{
    _set_se_translator(seh_exception::TranslateSEHtoCE);
    try
    {
        switch ((ActorType2)actor->getEntityTypeId())
        {
            case ActorType2::Item: // 物品
                // Item
                return getFakeName<ActorArg::FormatType::Item>(actor);
            case ActorType2::XpOrb: // 经验球
                // XpOrb
                return getFakeName<ActorArg::FormatType::XpOrb>(actor);
                break;
            case ActorType2::Npc:   // entity
            case ActorType2::Agent: // entity
                // Intelgent
            case ActorType2::ArmorStand:   // 盔甲架
            case ActorType2::TripodCamera: // 三脚架摄像机
            case ActorType2::EnderCrystal: // 末影水晶
                // Unmovable
                return getFakeName<ActorArg::FormatType::Unmovable>(actor);
                break;
            case ActorType2::Player: // 玩家
                // Player
                return getFakeName<ActorArg::FormatType::Player>(actor);
                break;
            case ActorType2::Creeper:          // 爬行者
            case ActorType2::Slime:            // 史莱姆
            case ActorType2::Enderman:         // 末影人
            case ActorType2::Ghast:            // 恶魂
            case ActorType2::MagmaCube:        // 岩浆怪
            case ActorType2::Blaze:            // 烈焰人
            case ActorType2::Witch:            // 女巫
            case ActorType2::Shulker:          // 潜影贝
            case ActorType2::Vindicator:       // 卫道士
            case ActorType2::Ravager:          // 劫掠兽
            case ActorType2::EvocationIllager: // 唤魔者
            case ActorType2::Vex:              // 恼鬼
            case ActorType2::Pillager:         // 掠夺者
            case ActorType2::ZombiePigman:     // 僵尸猪灵
            case ActorType2::Wither:           // 凋灵
            case ActorType2::Phantom:          // 幻翼
            case ActorType2::Zoglin:           // 僵尸疣猪兽
            case ActorType2::Zombie:           // 僵尸
            case ActorType2::ZombieVillager:   // 僵尸村民
            case ActorType2::Husk:             // 尸壳
            case ActorType2::Drowned:          // 溺尸
            case ActorType2::ZombieVillagerV2: // 怪人村民
            case ActorType2::Spider:           // 蜘蛛
            case ActorType2::Silverfish:       // 蠹虫
            case ActorType2::CaveSpider:       // 洞穴蜘蛛
            case ActorType2::Endermite:        // 末影螨
            case ActorType2::Piglin:           // 猪灵
            case ActorType2::PiglinBrute:      // 残暴猪灵
            case ActorType2::Guardian:         // 守卫者
            case ActorType2::Skeleton:         // 骷髅
            case ActorType2::Stray:            // 流浪者
            case ActorType2::WitherSkeleton:   // 凋灵骷髅
                // Monster
                return getFakeName<ActorArg::FormatType::Monster>(actor);
                break;
            case ActorType2::ElderGuardian: // 远古守卫者
            case ActorType2::EnderDragon:   // 末影龙
                // Boss
                return getFakeName<ActorArg::FormatType::Boss>(actor);
                break;
            case ActorType2::Chicken:      // 鸡
            case ActorType2::Cow:          // 牛
            case ActorType2::Sheep:        // 羊
            case ActorType2::Mooshroom:    // 哞菇
            case ActorType2::Rabbit:       // 兔子
            case ActorType2::Turtle:       // 海龟
            case ActorType2::Fox:          // 狐狸
            case ActorType2::Hoglin:       // 疣猪兽
            case ActorType2::Strider:      // 炽足兽
            case ActorType2::Squid:        // 鱿鱼
            case ActorType2::Salmon:       // 鲑鱼
            case ActorType2::Tropicalfish: // 热带鱼
            case ActorType2::Cod:          // 鳕鱼
            case ActorType2::GlowSquid:    // 发光鱿鱼
            case ActorType2::Parrot:       // 鹦鹉
            case ActorType2::Bat:          // 蝙蝠
            case ActorType2::Donkey:       // 驴
            case ActorType2::ZombieHorse:  // 僵尸马
                // Friendly
                return getFakeName<ActorArg::FormatType::Friendly>(actor);
                break;
            case ActorType2::Goat:       // 山羊
            case ActorType2::Bee:        // 蜜蜂
            case ActorType2::Wolf:       // 狼
            case ActorType2::Pufferfish: // 河豚
            case ActorType2::PolarBear:  // 北极熊
            case ActorType2::Llama:      // 羊驼
            case ActorType2::Panda:      // 熊猫
            case ActorType2::Ocelot:     // 豹猫
            case ActorType2::Cat:        // 猫
            case ActorType2::Dolphin:    // 海豚
            case ActorType2::Axolotl:    // 美西螈
                // Attackable
                return getFakeName<ActorArg::FormatType::Attackable>(actor);
                break;
            case ActorType2::Minecart:             // 矿车
            case ActorType2::HopperMinecart:       // 漏斗矿车
            case ActorType2::TntMinecart:          // TNT 矿车
            case ActorType2::ChestMinecart:        // 运输矿车
            case ActorType2::CommandBlockMinecart: // 命令方块矿车
            case ActorType2::Boat:                 // 船
                // Vehicle
                return getFakeName<ActorArg::FormatType::Vehicle>(actor);
                break;
            case ActorType2::Pig:                  // 猪
            case ActorType2::Horse:                // 马
            case ActorType2::Mule:                 // 骡子
            case ActorType2::SkeletonHorse:        // 骷髅马
                // Mount
                return getFakeName<ActorArg::FormatType::Mount>(actor);
                break;
            case ActorType2::EyeOfEnderSignal:     // 末影之眼
            case ActorType2::XpBottle:             // 附魔之瓶
            case ActorType2::ShulkerBullet:        // 潜影贝子弹
            case ActorType2::DragonFireball:       // 末影龙火球
            case ActorType2::Snowball:             // 雪球
            case ActorType2::Egg:                  // 鸡蛋
            case ActorType2::Fireball:             // 火球
            case ActorType2::SplashPotion:         // 药水
            case ActorType2::EnderPearl:           // 末影珍珠
            case ActorType2::WitherSkull:          // 凋灵头颅
            case ActorType2::WitherSkullDangerous: // 凋灵头颅
            case ActorType2::SmallFireball:        // 小火球
            case ActorType2::LingeringPotion:      // 滞留药水
            case ActorType2::LlamaSpit:            // 羊驼口水
            case ActorType2::EvocationFang:        // 唤魔者尖牙
            case ActorType2::IceBomb:              // entity
                // Projectile
                return getFakeName<ActorArg::FormatType::Projectile>(actor);
                break;
            case ActorType2::ThrownTrident: // 三叉戟
                return getFakeName<ActorArg::FormatType::Trident>(actor);
            case ActorType2::Arrow: // 箭
                return getFakeName<ActorArg::FormatType::Arrow>(actor);
                break;
            case ActorType2::Villager:   // 村民
            case ActorType2::VillagerV2: // 村民
                return getFakeName<ActorArg::FormatType::Villager>(actor);
                // Villager
                break;
            case ActorType2::Tnt:                // TNT 方块
            case ActorType2::FallingBlock:       // 下落的方块
            case ActorType2::MovingBlock:        // 移动中的方块
            case ActorType2::FireworksRocket:    // 焰火火箭
            case ActorType2::FishingHook:        // 鱼钩
            case ActorType2::Chalkboard:         // entity
            case ActorType2::Painting:           // 画
            case ActorType2::LeashKnot:          // 拴绳结
            case ActorType2::LightningBolt:      // 闪电
            case ActorType2::AreaEffectCloud:    // 区域效果云雾
            case ActorType2::Balloon:            // entity
            case ActorType2::Shield:             // entity
            case ActorType2::ElderGuardianGhost: // entity
                // Other
                return getFakeName<ActorArg::FormatType::Other>(actor);
            case ActorType2::WanderingTrader: // 流浪商人
                return getFakeName<ActorArg::FormatType::WanderingTrader>(actor);
                break;
            case ActorType2::IronGolem: // 铁傀儡
            case ActorType2::SnowGolem: // 雪傀儡
                // Crafted
                return getFakeName<ActorArg::FormatType::Crafted>(actor);
                break;
            default:
                return "";
                break;
        }
    }
    catch (...)
    {
        logger.error("Error in getActorFakeName");
    }
    return "";
}

#pragma endregion

void refreshActorFakeName(Actor* actor, Player* player = nullptr)
{
    SetActorDataPacket packet;
    packet.mRuntimeId = actor->getRuntimeID();
    if (packet.mRuntimeId.id == 0)
        return;
    packet.mDataItems.emplace_back(DataItem::create(ActorDataIDs::NAMETAG, actor->getNameTag()));
    packet.mDataItems.emplace_back(DataItem::create<signed char>(ActorDataIDs::ALWAYS_SHOW_NAMETAG, actor->isPlayer()||Config::globalActive));
    if (!player)
    {
        auto& dim = actor->getDimension();
        dim.sendPacketForEntity(*actor, packet, nullptr);
    }
    else
    {
        player->sendNetworkPacket(packet);
    }
    //Global<LoopbackPacketSender>->sendBroadcast(packet);
}

inline DataItem2<std::string>* findNameItemAndSetAlwayShow(std::vector<std::unique_ptr<DataItem>>& dataItems)
{
    DataItem2<std::string>* result = nullptr;
    for (auto& item : dataItems)
    {
        if (!item)
            continue;
        if (item->mId == (unsigned short)ActorDataIDs::NAMETAG)
        {
            result = (DataItem2<std::string>*)item.get();
            dataItems.emplace_back(DataItem::create<signed char>(ActorDataIDs::ALWAYS_SHOW_NAMETAG, true));
            break;
        }
        else if (item->mId == (unsigned short)ActorDataIDs::ALWAYS_SHOW_NAMETAG)
        {
            item->setData<signed char>(true);
        }
    }
    return result;
}


// ============= Set Fake Name - Global =============
TInstanceHook(void, "?write@AddActorPacket@@UEBAXAEAVBinaryStream@@@Z",
              AddActorPacket, class BinaryStream& bs)
{
    if (Config::globalActive)
    {
        constexpr auto OFFSET_ACTOR_DATA = offsetof(std::remove_reference<decltype(*this)>::type, mActorData);
        constexpr auto OFFSET_RUNTIMEID = offsetof(std::remove_reference<decltype(*this)>::type, mRuntimeId);
        auto& runtimeId = dAccess<ActorRuntimeID>(this, OFFSET_RUNTIMEID);
        auto& actorData = dAccess<SynchedActorData*>(this, OFFSET_ACTOR_DATA); //mActorData;

        auto actorDataBackup = actorData;
        SynchedActorData fakeActorData = actorData->_clone();
        if (auto nameItem = findNameItemAndSetAlwayShow(fakeActorData.mItemsArray))
        {
            auto actor = Global<Level>->getRuntimeEntity(runtimeId, true);
            *nameItem = getActorFakeName(actor);
        }
        else
        {
            logger.error("AddActorPacket::write");
        }
        actorData = &fakeActorData;
        original(this, bs);
        actorData = actorDataBackup;
        return;
    }
    original(this, bs);
}

TInstanceHook(void, "?write@AddItemActorPacket@@UEBAXAEAVBinaryStream@@@Z",
              AddItemActorPacket, class BinaryStream& bs)
{
    if (Config::globalActive)
    {
        constexpr auto OFFSET_ACTOR_DATA = offsetof(std::remove_reference<decltype(*this)>::type, mActorData);
        constexpr auto OFFSET_RUNTIMEID = offsetof(std::remove_reference<decltype(*this)>::type, mRuntimeId);
        auto& runtimeId = dAccess<ActorRuntimeID>(this, OFFSET_RUNTIMEID);
        auto& actorData = dAccess<SynchedActorData*>(this, OFFSET_ACTOR_DATA); //mActorData;

        auto actorDataBackup = actorData;
        SynchedActorData fakeActorData = actorData->_clone();
        if (auto nameItem = findNameItemAndSetAlwayShow(fakeActorData.mItemsArray))
        {
            auto actor = Global<Level>->getRuntimeEntity(runtimeId, true);
            *nameItem = getActorFakeName(actor);
        }
        else
        {
            logger.error("AddActorPacket::write");
        }
        actorData = &fakeActorData;
        original(this, bs);
        actorData = actorDataBackup;
        return;
    }
    original(this, bs);
}

TInstanceHook(void, "?write@AddPlayerPacket@@UEBAXAEAVBinaryStream@@@Z",
              AddPlayerPacket, class BinaryStream& bs)
{
    if (Config::globalActive)
    {
        constexpr auto OFFSET_ACTOR_DATA = 880;//offsetof(std::remove_reference<decltype(*this)>::type, mActorData);
        constexpr auto OFFSET_RUNTIMEID = offsetof(std::remove_reference<decltype(*this)>::type, mRuntimeId);
        auto& runtimeId = dAccess<ActorRuntimeID>(this, OFFSET_RUNTIMEID);
        auto& actorData = dAccess<SynchedActorData*>(this, OFFSET_ACTOR_DATA); //mActorData;

        auto actorDataBackup = actorData;
        SynchedActorData fakeActorData = actorData->_clone();
        if (auto nameItem = findNameItemAndSetAlwayShow(fakeActorData.mItemsArray))
        {
            auto actor = Global<Level>->getRuntimeEntity(runtimeId, true);
            nameItem->setData(getActorFakeName(actor));
        }
        else
        {
            logger.error("AddActorPacket::write");
        }
        actorData = &fakeActorData;
        original(this, bs);
        actorData = actorDataBackup;
        return;
    }
    original(this, bs);
}

TInstanceHook(void, "?write@SetActorDataPacket@@UEBAXAEAVBinaryStream@@@Z",
              SetActorDataPacket, class BinaryStream& bs)
{
    if (Config::globalActive)
    {
        if (auto item = findNameItemAndSetAlwayShow(mDataItems))
        {
            auto actor = Global<Level>->getRuntimeEntity(mRuntimeId, true);
            item->setData(getActorFakeName(actor));
        }
    }
    original(this, bs);
}

// ============= Set Fake Name - Personal =============
std::vector<ActorUniqueID> uniqueIds = {};

ServerPlayer* tryGetDebugPlayer(NetworkIdentifier const& networkID, unsigned char clientSubID)
{
    auto player = Global<ServerNetworkHandler>->getServerPlayer(networkID, clientSubID);
    if (!player)
        return nullptr;
    ActorUniqueID uniqueId = player->getUniqueID();
    if (std::find(uniqueIds.begin(), uniqueIds.end(), uniqueId.id) != uniqueIds.end())
        return player;
    return nullptr;
}

TInstanceHook(void, "?send@NetworkHandler@@QEAAXAEBVNetworkIdentifier@@AEBVPacket@@E@Z",
              NetworkHandler, NetworkIdentifier const& networkID, Packet& packet, unsigned char clientSubID)
{
    if (!Config::globalActive && !uniqueIds.empty())
    {
        auto pktid = packet.getId();
        if (pktid == MinecraftPacketIds::SetActorData)
        {
            if (!tryGetDebugPlayer(networkID, clientSubID))
                return original(this, networkID, packet, clientSubID);
            constexpr auto OFFSET_DATAITEMS = offsetof(SetActorDataPacket, mDataItems);
            constexpr auto OFFSET_RUNTIMEID = offsetof(SetActorDataPacket, mRuntimeId);
            auto& runtimeId = dAccess<ActorRuntimeID>(&packet, OFFSET_RUNTIMEID);
            auto& dataItems = dAccess<decltype(SetActorDataPacket::mDataItems)>(&packet, OFFSET_DATAITEMS);

            if (auto item = findNameItemAndSetAlwayShow(dataItems))
            {
                auto actor = Global<Level>->getRuntimeEntity(runtimeId, true);
                item->setData(getActorFakeName(actor));
            }
            return original(this, networkID, packet, clientSubID);
        }
        else if (pktid == MinecraftPacketIds::AddActor || pktid == MinecraftPacketIds::AddItemActor || pktid == MinecraftPacketIds::AddPlayer)
        {
            if (!tryGetDebugPlayer(networkID, clientSubID))
                return original(this, networkID, packet, clientSubID);
            size_t offsetActorData;
            size_t offsetRuntimeId;
            if (pktid == MinecraftPacketIds::AddActor)
            {
                offsetActorData = offsetof(AddActorPacket, mActorData);
                offsetRuntimeId = offsetof(AddActorPacket, mRuntimeId);
            }
            else if (pktid == MinecraftPacketIds::AddItemActor)
            {
                offsetActorData = offsetof(AddItemActorPacket, mActorData);
                offsetRuntimeId = offsetof(AddItemActorPacket, mRuntimeId);
            }
            else if (pktid == MinecraftPacketIds::AddPlayer)
            {
                offsetActorData = offsetof(AddPlayerPacket, mActorData);
                offsetRuntimeId = offsetof(AddPlayerPacket, mRuntimeId);
            }

            auto& actorData = dAccess<SynchedActorData*>(&packet, offsetActorData);
            auto& runtimeId = dAccess<ActorRuntimeID>(&packet, offsetRuntimeId);
            auto actorDataBackup = actorData;
            SynchedActorData fakeActorData = actorData->_clone();
            if (auto nameItem = findNameItemAndSetAlwayShow(fakeActorData.mItemsArray))
            {
                auto actor = Global<Level>->getRuntimeEntity(runtimeId, true);
                nameItem->setData(getActorFakeName(actor));
            }
            actorData = &fakeActorData;
            original(this, networkID, packet, clientSubID);
            actorData = actorDataBackup;
            return;
        }
    }
    original(this, networkID, packet, clientSubID);
}
struct NetworkIdentifierWithSubId
{
    NetworkIdentifier mNetworkIdentifier;
    unsigned char mClientSubId;
    char filler161[7];
};
static_assert(sizeof(NetworkIdentifierWithSubId) == 168);
TInstanceHook(void, "?sendToClients@LoopbackPacketSender@@UEAAXAEBV?$vector@UNetworkIdentifierWithSubId@@V?$allocator@UNetworkIdentifierWithSubId@@@std@@@std@@AEBVPacket@@@Z",
              LoopbackPacketSender, std::vector<struct NetworkIdentifierWithSubId> const& nidWithSubIds, class Packet& packet)
{
    original(this, nidWithSubIds, packet);
    if (!Config::globalActive && !uniqueIds.empty() && packet.getId() == MinecraftPacketIds::SetActorData)
    {
        SetActorDataPacket fakeNamePacket;
        fakeNamePacket.mRuntimeId = ((SetActorDataPacket&)packet).mRuntimeId;
        fakeNamePacket.mDataItems.emplace_back(DataItem::create<std::string>(ActorDataIDs::NAMETAG, ""));
        for (auto& nidWithSubId : nidWithSubIds)
        {
            auto player = tryGetDebugPlayer((NetworkIdentifier&)nidWithSubId, dAccess<unsigned char>(&nidWithSubId, 160));
            if (player)
                player->sendNetworkPacket(fakeNamePacket);
        }
    }
}

#ifdef DEBUG

TInstanceHook(void, "?_sendInternal@NetworkHandler@@AEAAXAEBVNetworkIdentifier@@AEBVPacket@@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z",
              NetworkHandler, NetworkIdentifier& nid, class Packet& pkt, std::string const& data)
{
    auto pktid = pkt.getId();
    if (pktid == MinecraftPacketIds::AddActor || pktid == MinecraftPacketIds::AddItemActor || pktid == MinecraftPacketIds::AddPlayer || pktid == MinecraftPacketIds::SetActorData)
    {
        if (!true)
            __debugbreak();
    }
    return original(this, nid, pkt, data);
}

#endif // DEBUG

// ============= Update Fake Name =============
TInstanceHook(float, "?change@HealthAttributeDelegate@@UEAAMMMAEBVAttributeBuff@@@Z",
              HealthAttributeDelegate, float before, float after, struct AttributeBuffInfo* info)
{
    auto rtn = original(this, before, after, info);
    if (Config::globalActive)
    {
        if (before - after > 0.1)
            refreshActorFakeName(dAccess<Mob*>(this, 32));
    }
    else if (!uniqueIds.empty())
    {
        for (auto& uid : uniqueIds) {
            refreshActorFakeName(dAccess<Mob*>(this, 32), Global<Level>->getPlayer(uid));
        }
    }
    return rtn;
}

//#include <MC/ChorusFlowerBlock.hpp>
//TClasslessInstanceHook(void, "?_placeGrownFlower@ChorusFlowerBlock@@AEBAXAEAVBlockSource@@AEBVBlockPos@@H@Z",
//               class BlockSource& bs, class BlockPos const& bpos, int age)
//{
//    return original(this, bs, bpos, 0);
//}
//TInstanceHook(void, "?_placeDeadFlower@ChorusFlowerBlock@@AEBAXAEAVBlockSource@@AEBVBlockPos@@@Z",
//              ChorusFlowerBlock, class BlockSource& bs, class BlockPos const& bpos)
//{
//    SymCallStatic("?_placeGrownFlower@ChorusFlowerBlock@@AEBAXAEAVBlockSource@@AEBVBlockPos@@H@Z",
//                  void, ChorusFlowerBlock*, class BlockSource&, class BlockPos const&, int)(this, bs, bpos, 0);
//}

//TInstanceHook(void, "?setSpeed@Mob@@UEAAXM@Z",
//              Mob, float speed)
//{
//    DEBUGW("Mob::setSpeed({})", speed);
//    original(this, speed);
//    if (Config::globalActive)
//    {
//        if (getSpeed() - speed > 0.01)
//            refreshActorFakeName(this);
//    }
//}
//TInstanceHook(void, "?setSpeedModifier@Mob@@QEAAXM@Z",
//              Mob, float modifier)
//{
//    DEBUGW("Mob::setSpeedModifier({})", modifier);
//    original(this, modifier);
//    if (Config::globalActive)
//    {
//        refreshActorFakeName(this);
//    }
//}

void entry()
{
    Event::RegCmdEvent::subscribe([](Event::RegCmdEvent ev) {
        ActorDebugCommand::setup(*ev.mCommandRegistry);
        return true;
    });
}