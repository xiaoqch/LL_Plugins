#pragma once

#include <MC/WorldGenContext.hpp>
#include <MC/WorldBlockTarget.hpp>
#include <MC/WeakStorageFeature.hpp>
#include <MC/HashedString.hpp>
#include <MC/FeatureRegistry.hpp>
#include <MC/Random.hpp>
#include <MC/Feature.hpp>
#include <MC/RenderParams.hpp>
#include <MC/MolangVariableMap.hpp>
#include <MC/FeatureHelper.hpp>
#include <MC/ITreeFeature.hpp>
#include <MC/VanillaTreeFeature.hpp>
#include <MC/BlockSource.hpp>
#include <MC/Dimension.hpp>
#include <MC/WorldGenerator.hpp>
#include <MC/StructureFeatureRegistry.hpp>
#include <MC/Level.hpp>
#include <MC/SimulatedPlayer.hpp>

template <>
class WeakRefT<struct FeatureRefTraits> : public WeakStorageFeature
{
    char filler[32];
};

std::unordered_map<std::string, Feature const*> FeatureMap;
TInstanceHook(void, "?_registerFeature@FeatureRegistry@@AEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$unique_ptr@VIFeature@@U?$default_delete@VIFeature@@@std@@@3@@Z",
              FeatureRegistry, std::string const& name, class std::unique_ptr<class Feature>& uptr)
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


std::pair<std::string, Feature const*> getFeature(int index)
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