#pragma once

#include <MC/BlockSource.hpp>
#include <MC/Dimension.hpp>
#include <MC/WorldGenerator.hpp>
#include <MC/StructureFeatureRegistry.hpp>
#include <MC/Level.hpp>
#include <MC/SimulatedPlayer.hpp>
//#include <MC/WorldGenContext.hpp>
//#include <MC/WorldBlockTarget.hpp>
#include <MC/WeakStorageFeature.hpp>
#include <MC/HashedString.hpp>
#include <MC/FeatureRegistry.hpp>
#include <MC/Random.hpp>
#include <MC/IFeature.hpp>
#include <MC/Feature.hpp>
#include <MC/MolangVariable.hpp>
//#include <MC/RenderParams.hpp>
//#include <MC/MolangVariableMap.hpp>
#include <MC/SurfaceLevelCache.hpp>
enum MolangVariableIndex : short
{
};
struct WorldGenContext
{
public:
    void* unk0 = nullptr;
    void* filler[7];
    void* unk64 = nullptr;
    SurfaceLevelCache* mSurfaceProvider = nullptr;

public:
    MCAPI ~WorldGenContext();
};

DECLSPEC_ALIGN(8)
class WorldBlockTarget
{
public:
    BlockSource* mRegion; // 8
    WorldGenContext context;
    bool mBlockSimpleEnabled; // 96

public:
    /*0*/ virtual ~WorldBlockTarget();
    /*1*/ virtual void __unk_vfn_1();
    /*2*/ virtual class LevelChunk* getChunk(class ChunkPos const&);
    /*3*/ virtual class Block const* tryGetLiquidBlock(class BlockPos const&) const;
    /*4*/ virtual class Block const& getBlock(class BlockPos const&) const;
    /*5*/ virtual class Block const& getBlockNoBoundsCheck(class BlockPos const&) const;
    /*6*/ virtual class Block const& getExtraBlock(class BlockPos const&) const;
    /*7*/ virtual class gsl::span<class BlockDataFetchResult<class Block> const, -1> fetchBlocksInBox(class BoundingBox const&, class std::function<bool(class Block const&)>);
    /*8*/ virtual bool hasBiomeTag(unsigned __int64, class BlockPos const&) const;
    /*9*/ virtual bool setBlock(class BlockPos const&, class Block const&, int);
    /*10*/ virtual bool setBlockSimple(class BlockPos const&, class Block const&);
    /*11*/ virtual void __unk_vfn_11();
    /*12*/ virtual bool placeStructure(class BlockPos const&, class StructureTemplate&, class StructureSettings&);
    /*13*/ virtual bool mayPlace(class BlockPos const&, class Block const&) const;
    /*14*/ virtual bool canSurvive(class BlockPos const&, class Block const&) const;
    /*15*/ virtual short getMaxHeight() const;
    /*16*/ virtual short getMinHeight() const;
    /*17*/ virtual bool shimPlaceForOldFeatures(class Feature const&, class BlockPos const&, class Random&) const;
    /*18*/ virtual short getHeightmap(int, int);
    /*19*/ virtual bool isLegacyLevel();
    /*20*/ virtual class Biome const* getBiome(class BlockPos const&) const;
    /*21*/ virtual bool isInBounds(class Pos const&) const;
    /*22*/ virtual short getLocalWaterLevel(class BlockPos const&) const;
    /*23*/ virtual class LevelData const& getLevelData() const;
    /*24*/ virtual struct WorldGenContext const& getContext();
    /*25*/ virtual void disableBlockSimple();
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_WORLDBLOCKTARGET
    MCVAPI bool apply() const;
    MCVAPI bool canGetChunk() const;
#endif
    MCAPI WorldBlockTarget(class BlockSource&, struct WorldGenContext const&);
};

DECLSPEC_ALIGN(8)
class RenderParams
{
    char filler[490];

public:
    class RenderParams& operator=(class RenderParams const&) = delete;

public:
    MCAPI RenderParams(class RenderParams const&);
    MCAPI RenderParams(class RenderParams&&);
    MCAPI RenderParams();
    MCAPI class Actor* getActorTarget(enum FilterSubject const&) const;
    MCAPI class RenderParams& init(class BaseActorRenderContext*, class Actor*, class AnimationComponent*, class MolangVariableMap*, class std::shared_ptr<class DataDrivenModel>, float, float, int, bool, class std::function<float(void)>);
    MCAPI class RenderParams& operator=(class RenderParams&&);
    MCAPI float& operator[](unsigned __int64);
    MCAPI ~RenderParams();
    MCAPI static class RenderParams& getRenderParams(class Actor&);
};

class MolangVariableMap
{
public:
    std::vector<MolangVariableIndex> mIndices = {};
    std::vector<std::unique_ptr<MolangVariable>> mVariables = {};
    bool unk48 = false;
    MolangVariableMap() = default;

public:
    MCAPI MolangVariableMap(class MolangVariableMap&&);
    MCAPI MolangVariableMap(class MolangVariableMap const&);
    MCAPI class MolangVariableMap& clear();
    MCAPI struct MolangScriptArg const* getConstScriptArgReference(enum MolangVariableIndex const&) const;
    MCAPI struct MolangScriptArg const& getMolangVariable(enum MolangVariableIndex const&, bool&) const;
    MCAPI struct MolangScriptArg const& getMolangVariable(unsigned __int64 const&, bool&) const;
    MCAPI struct MolangScriptArg const& getMolangVariable(unsigned __int64, char const*) const;
    MCAPI struct MolangScriptArg* getNonConstScriptArgReference(enum MolangVariableIndex const&);
    MCAPI struct MolangScriptArg* getOrAddNonConstScriptArgReference(enum MolangVariableIndex const&);
    MCAPI struct MolangScriptArg const& getPublicMolangVariable(enum MolangVariableIndex const&, bool&) const;
    MCAPI std::vector<std::unique_ptr<class MolangVariable>> const& getVariables() const;
    MCAPI class MolangVariableMap& operator=(class MolangVariableMap&&);
    MCAPI class MolangVariableMap& operator=(class MolangVariableMap const&);
    MCAPI void setMolangStructMember(class HashedString const&, class HashedString const&, struct MolangScriptArg const&);
    MCAPI void setMolangVariable(class HashedString const&, struct MolangScriptArg const&);
    MCAPI void setMolangVariable(enum MolangVariableIndex, struct MolangScriptArg const&);
    MCAPI void setMolangVariable(unsigned __int64, char const*, struct MolangScriptArg const&);
    MCAPI void setMolangVariableSettings(struct MolangVariableSettings const&);
    MCAPI ~MolangVariableMap();

    // private:
    MCAPI class MolangVariable const* _getMolangVariable(enum MolangVariableIndex) const;
    MCAPI class MolangVariable* _getOrAddMolangVariable(unsigned __int64 const&, char const*, bool);
    MCAPI class MolangVariable* _getOrAddMolangVariable(enum MolangVariableIndex);
};

template <>
class WeakRefT<struct FeatureRefTraits> : public WeakStorageFeature
{
    char filler[32];
};
#include <MC/FeatureHelper.hpp>

std::unordered_map<std::string, IFeature const*> FeatureMap;
TInstanceHook(void, "?_registerFeature@FeatureRegistry@@AEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$unique_ptr@VIFeature@@U?$default_delete@VIFeature@@@std@@@3@@Z",
              FeatureRegistry, std::string const& name, class std::unique_ptr<class IFeature>& uptr)
{
    FeatureMap[name] = uptr.get();
    logger.warn("Registered feature {}", name);
    original(this, name, uptr);
}

inline std::optional<BlockPos> tryPlaceFeature(BlockSource& region, const BlockPos& pos, std::string const& name)
{

    auto& registry = Global<Level>->getFeatureRegistry();
    auto& random = Global<Level>->getRandom();
    auto feature = FeatureMap[name];
    if (!feature)
        return std::nullopt;
    WorldGenContext ctx;
    auto gen = region.getDimension().getWorldGenerator();
    ctx.mSurfaceProvider = &dAccess<SurfaceLevelCache, 64>(gen);
    WorldBlockTarget target(region, ctx);
    MolangVariableMap variables;
    RenderParams param = FeatureHelper::makeFeatureRenderParams(region, pos, variables);
    auto result = feature->place(reinterpret_cast<IBlockWorldGenAPI&>(target), pos, random, param);
    if (result)
        logger.warn("{} -> {}", name, result->toString());
    return result;
}
class IBlockWorldGenAPI;
static_assert(sizeof(WorldBlockTarget) == 104);
// TInstanceHook(WorldBlockTarget&, "??0WorldBlockTarget@@QEAA@AEAVBlockSource@@AEBUWorldGenContext@@@Z",
//               WorldBlockTarget, BlockSource& bs, WorldGenContext& ctx)
//{
//     auto& rtn = original(this, bs, ctx);
//     return rtn;
// }

TInstanceHook(RenderParams&, "?makeFeatureRenderParams@FeatureHelper@@YA?AVRenderParams@@AEAVBlockSource@@AEBVBlockPos@@AEAVMolangVariableMap@@@Z",
              RenderParams, class BlockSource& region, class BlockPos const& pos, class MolangVariableMap& map)
{
    auto& rtn = original(this, region, pos, map);
    return rtn;
}

TInstanceHook(std::optional<BlockPos>&, "?place@Feature@@UEBA?AV?$optional@VBlockPos@@@std@@AEAVIBlockWorldGenAPI@@AEBVBlockPos@@AEAVRandom@@AEAVRenderParams@@@Z",
              Feature, std::optional<BlockPos>& result, WorldBlockTarget& api, BlockPos const& pos, Random& random, RenderParams& params)
{
    auto& rtn = original(this, result, api, pos, random, params);
    return rtn;
}


#include <DynamicCommandAPI.h>
#include <ScheduleAPI.h>
using ParamType = DynamicCommand::ParameterType;
using Result = DynamicCommand::Result;


std::pair<std::string, IFeature const*> getFeature(int index)
{
    if (index >= FeatureMap.size())
        index = index % FeatureMap.size();
    auto begin = FeatureMap.begin();
    for (int i = 0; i < index; ++i)
        ++begin;
    return *begin;
}

void onFeatureExecute(DynamicCommand const& cmd, CommandOrigin const& origin, CommandOutput& output, std::unordered_map<std::string, Result>& results)
{
    if (!origin.getEntity())
        output.error("please execute feature command by entity or player");
    auto entity = origin.getEntity();
    std::string name = results["feature"].isSet ? results["feature"].getRaw<std::string>() : "";
    if (name.empty())
    {
        auto index = entity->getRandom().nextInt(0, static_cast<int>(FeatureMap.size()) - 1);
        name = getFeature(index).first;
    }
    auto& region = origin.getEntity()->getRegion();
    auto block = origin.getEntity()->getBlockFromViewVector(false, false, 100.0f);
    auto pos = block.isNull() ? origin.getBlockPosition() : block.getPosition();
    auto res = tryPlaceFeature(region, pos, name);
    if (res)
        output.success(fmt::format("Successfully placed {} at {}", name.substr(name.find(':') + 1), res->toString()));
    else
        output.error(fmt::format("Feature {} cannot be placed in {}", name.substr(name.find(':') + 1), pos.toString()));
}

std::vector<std::string> getFeatureNames()
{
    std::vector<std::string> names;
    for (auto& [name, feature] : FeatureMap)
    {
        names.push_back(name);
    }
    return names;
}
DynamicCommandInstance const* regFeatureCommand()
{
    auto command = DynamicCommand::createCommand("feature", "feature");
    command->setEnum("FeatureType", getFeatureNames());
    command->optional("feature", ParamType::Enum, "FeatureType");
    command->addOverload("feature");
    command->setCallback(onFeatureExecute);
    return DynamicCommand::setup(std::move(command));
}

inline auto featureCommand = Schedule::nextTick(regFeatureCommand);

#include <EventAPI.h>
#include <MC/ServerPlayer.hpp>
#include <Utils/PlayerMap.h>
#include <MC/ItemStack.hpp>
#include <MC/VanillaItemNames.hpp>
template <typename T>
using PlayerMap = playerMap<T>;

inline auto ev = Event::PlayerUseItemOnEvent::subscribe_ref([](Event::PlayerUseItemOnEvent& ev) {
    static PlayerMap<std::pair<BlockPos, Tick>> map{};
    if (ev.mItemStack->getFullNameHash() != VanillaItemNames::Stick)
        return true;
    auto& log = map[static_cast<ServerPlayer*>(ev.mPlayer)];
    auto tick = Global<Level>->getCurrentServerTick();
    auto pos = ev.mBlockInstance.getPosition();
    if (log.first == pos && tick - log.second < 10)
        return false;
    auto& region = ev.mPlayer->getRegion();

    auto index = ev.mPlayer->getRandom().nextInt(0, static_cast<int>(FeatureMap.size()) - 1);
    std::string name = getFeature(index).first;
    auto res = tryPlaceFeature(region, pos, name);
    if (res)
    {
        log.first = pos;
        log.second = tick;
        ev.mPlayer->sendText(fmt::format("{} -> {}", name.substr(name.find(':') + 1), res->toString()));
    }
    return false;
});