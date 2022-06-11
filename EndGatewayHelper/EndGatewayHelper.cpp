#include "pch.h"
#include "EndGatewayCommand.h"
#include "MyHeaders.h"
#include <EventAPI.h>
#include <MC/ServerPlayer.hpp>
#include <MC/ActorDefinitionDescriptor.hpp>
#include <MC/CommandUtils.hpp>
#include <PlayerInfoAPI.h>
#include <ScheduleAPI.h>

#include <MC/FallingBlock.hpp>
#include <MC/VanillaBlockTypes.hpp>
#include <MC/EndGatewayBlock.hpp>
#include <MC/BedrockBlockTypes.hpp>
#include <MC/BedrockBlocks.hpp>
//#include <MC/EndGatewayBlockActor.hpp>
#include <MC/EndGatewayFeature.hpp>
#include <MC/EndIslandFeature.hpp>
#include <MC/SynchedActorData.hpp>

inline bool findNextTopSolidBlockUnder(BlockSource const& region, class BlockPos& pos)
{
    ChunkPos cpos(pos);
    auto chunk = region.getChunk(cpos);
    if (!chunk)
        return false;
    int maxAllocatedY = chunk->getMaxAllocatedY();
    if (pos.y > maxAllocatedY)
        pos.y = maxAllocatedY;
    while (1)
    {
        auto& block = region.getBlock(pos);
        pos.y--;
        auto& legacyBlock = block.getLegacyBlock();
        if (&legacyBlock == BedrockBlockTypes::mAir.get())
            break;
        if (pos.y < region.getMinHeight())
            return false;
    }
    do
    {
        auto& material = region.getMaterial(pos);
        if (material.isSolidBlocking())
            return true;
        pos.y--;
    } while (pos.y >= region.getMinHeight());
    return false;
}

inline bool _hasRoomForPlayer(class BlockSource& region, class BlockPos const& bpos)
{
    if (region.getBlock(bpos + BlockPos{0, 1, 0}).isSolidBlockingBlock())
        return false;
    if (region.getBlock(bpos + BlockPos{0, 2, 0}).isSolidBlockingBlock())
        return false;
    return true;
}

inline float distSqrToCenter(BlockPos const& bpos, Vec3 const& pos)
{
    return bpos.center().distanceToSqr(pos);
}


class BlockPos findValidSpawnAround(class BlockSource& region, class BlockPos const& around, bool searchForEndStoneOnly, int searchRadius)
{
    // auto info = genTickingInfo(getChunkSource(region), around, 2);
    // logger.info(ColorFormat::convertToColsole(info.first));
    BlockPos ret = BlockPos::ZERO;
    float closestDist = 0;
    Vec3 center = around.center();
    // A rectangle， y = 127
    BlockPos start = {around.x - 16 * searchRadius, 127, around.z - 16 * searchRadius};
    BlockPos end = {around.x + 16 * searchRadius, 127, around.z + 16 * searchRadius};
    BlockPosIterator iter(start, end);
    for (BlockPos currentPos : iter)
    {
        bool validBlock = false;
#ifdef DEBUG
        auto pos1 = currentPos;
        auto pos2 = currentPos;
        if (region.findNextTopSolidBlockUnder(pos1) != ::findNextTopSolidBlockUnder(region, pos2))
            __debugbreak();
        if (pos1 != pos2)
            __debugbreak();
#endif // DEBUG
        if (!::findNextTopSolidBlockUnder(region, currentPos))
            continue;
        auto blockLegacy = &region.getBlock(currentPos).getLegacyBlock();
        if (blockLegacy == VanillaBlockTypes::mBedrock.get())
        {
            auto expectedGatewayPos = currentPos - BlockPos{0, 2, 0};
            if (&region.getBlock(expectedGatewayPos).getLegacyBlock() == VanillaBlockTypes::mEndGateway.get())
            {
                currentPos.y -= 2;
#ifdef DEBUG
                auto pos1 = currentPos;
                auto pos2 = currentPos;
                if (region.findNextTopSolidBlockUnder(pos1) != ::findNextTopSolidBlockUnder(region, pos2))
                    __debugbreak();
                if (pos1 != pos2)
                    __debugbreak();
#endif // DEBUG
                if (::findNextTopSolidBlockUnder(region, currentPos))
                    validBlock = ::_hasRoomForPlayer(region, currentPos);
            }
        }
        else
        {
            if (searchForEndStoneOnly)
                validBlock = blockLegacy == VanillaBlockTypes::mEndStone.get();
            else
                validBlock = ::_hasRoomForPlayer(region, currentPos);
        }

        if (validBlock)
        {
            auto dist = distSqrToCenter(currentPos, center);
            if (ret == BlockPos::ZERO || dist < closestDist)
            {
                ret = currentPos;
                closestDist = dist;
            }
        }
    }
    return ret;
}

BlockPos findExitPortal(class WorldGenerator& generator, class BlockPos const& entryPosition)
{
    BlockPos exitPosition = BlockPos::ZERO;
    Vec3 norm = Vec3{entryPosition.x, 0, entryPosition.z}.normalized();
    Vec3 predictedExitPosition = norm * 1024.0f;
    std::array<class Block const*, 32768ul> buffer;
    BlockVolume volume{buffer_span_mut<class Block const*>{buffer.data(), buffer.data() + buffer.size()}, 16, 128, 16, *BedrockBlocks::mAir, 0};
    int chunkLimit = 16;
    BlockPos iter = predictedExitPosition;
    while (EndGatewayBlockActor::getHighestSection(generator, volume, iter) > 0)
    {
        if (--chunkLimit < 0)
            break;
        predictedExitPosition = predictedExitPosition - (norm * 16.0f);
        iter = predictedExitPosition;
    }
    chunkLimit = 16;
    while (!EndGatewayBlockActor::getHighestSection(generator, volume, iter))
    {
        if (--chunkLimit < 0)
            break;
        predictedExitPosition = predictedExitPosition + (norm * 16.0f);
        iter = predictedExitPosition;
    }
    return predictedExitPosition;
}

BlockPos findTallestBlock(class BlockSource& region, class BlockPos const& around, int dist, bool allowBedrock)
{
    BlockPos tallest = BlockPos::ZERO;
    for (int xd = -dist; xd <= dist; ++xd)
    {
        for (int zd = -dist; zd <= dist; ++zd)
        {
            if (xd || zd || allowBedrock)
            {
                auto maxHeight = dAccess<short, 56>(&region) - 1;
                for (int y = maxHeight; y > tallest.y; --y)
                {
                    BlockPos pos(xd + around.x, y, zd + around.z);
                    auto& block = region.getBlock(pos);
                    if (block.isSolidBlockingBlock())
                    {
                        if (allowBedrock || &block.getLegacyBlock() != VanillaBlockTypes::mBedrock.get())
                        {
                            tallest = pos;
                            break;
                        }
                    }
                }
            }
        }
    }
    if (tallest == BlockPos::ZERO)
        return around;
    return tallest;
}

inline std::string getTaskDescription(class std::tuple<enum EndDragonFight::GatewayTask, struct EndDragonFight::GateWayGenerator, struct EndDragonFight::GateWayGenerator>& task)
{
    auto& taskType = std::get<0>(task);
    auto& entryGenerator = std::get<1>(task);
    auto& exitGenerator = std::get<2>(task);
    std::string entryString = ColorHelper::green(entryGenerator.mPosition.toString());
    if (entryGenerator.mPlaceNewBlocks)
        entryString = ColorHelper::red("(new)") + entryString;
    std::string exitString = ColorHelper::green(exitGenerator.mPosition.toString());
    if (exitGenerator.mPlaceNewBlocks)
        exitString = ColorHelper::red("(new)") + exitString;
    return fmt::format("Task<{}({})> - Pos1<{}> - Pos2<{}>",
                       ColorHelper::green(magic_enum::enum_name(taskType)), (int)taskType, entryString, exitString);
}

TInstanceHook(void, "?_spawnNewGatewayChunksTask@EndDragonFight@@AEAAXAEAV?$tuple@W4GatewayTask@EndDragonFight@@UGateWayGenerator@2@U32@@std@@@Z",
              EndDragonFight, class std::tuple<enum EndDragonFight::GatewayTask, struct EndDragonFight::GateWayGenerator, struct EndDragonFight::GateWayGenerator>& a0)
{
    // logger.info("EndDragonFight::_spawnNewGatewayChunksTask");
    auto message = getTaskDescription(a0);
    logger.warn(ColorFormat::convertToColsole(std::string(message)));
    Level::broadcastText(message, TextType::RAW);
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?_verifyExitPositionsTask@EndDragonFight@@AEAAXAEAV?$tuple@W4GatewayTask@EndDragonFight@@UGateWayGenerator@2@U32@@std@@@Z",
              EndDragonFight, class std::tuple<enum EndDragonFight::GatewayTask, struct EndDragonFight::GateWayGenerator, struct EndDragonFight::GateWayGenerator>& a0)
{
    // logger.info("EndDragonFight::_verifyExitPositionsTask");
    auto message = getTaskDescription(a0);
    logger.warn(ColorFormat::convertToColsole(std::string(message)));
    Level::broadcastText(message, TextType::RAW);
    original(this, std::forward<decltype(a0)>(a0));
}


TInstanceHook(void, "?setExitPosition@EndGatewayBlockActor@@QEAAXAEBVBlockPos@@@Z",
              EndGatewayBlockActor, class BlockPos const& a0)
{
    BlockPos aboveZero = BlockPos(0, 1, 0);
    BlockPos exitPos = getExitPosition();
    if (a0 != exitPos && (a0 == BlockPos::ZERO || a0 == aboveZero || exitPos == BlockPos::ZERO || exitPos == aboveZero))
    {
        auto message = fmt::format("EndGateway<{}> exit change: {} -> {}",
                                   ColorHelper::green(getPosition().toString()), ColorHelper::green(getExitPosition().toString()), ColorHelper::green(a0.toString()));
        logger.warn(ColorFormat::convertToColsole(std::string(message)));
        Level::broadcastText(message, TextType::RAW);
    }
    else if (Config::Verbose)
        logger.info("EndGatewayBlockActor({})::setExitPosition({})", getPosition().toString(), a0.toString());
    original(this, std::forward<decltype(a0)>(a0));
}
#include <MC/CompoundTag.hpp>
// virtual : 37
TInstanceHook(void, "?load@EndGatewayBlockActor@@UEAAXAEAVLevel@@AEBVCompoundTag@@AEAVDataLoadHelper@@@Z",
              EndGatewayBlockActor, class Level& a0, class CompoundTag const& a1, class DataLoadHelper& a2)
{
    original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1), std::forward<decltype(a2)>(a2));
    if (this->mNeedsExitGeneration)
    {
        logger.warn("EndGatewayBlockActor({})::load", getPosition().toString());
        auto message = debugLogNbt(a1);
        Level::broadcastText(ColorFormat::convertToMc(message), TextType::RAW);
    }
    else if (Config::Verbose)
        logger.info("EndGatewayBlockActor({})::load", getPosition().toString());
}


THook(int, "?_getHighestSection@EndGatewayBlockActor@@CAHAEAVWorldGenerator@@AEAVBlockVolume@@AEBVBlockPos@@@Z",
      class WorldGenerator& a0, class BlockVolume& a1, class BlockPos const& a2)
{
    auto rtn = original(std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1), std::forward<decltype(a2)>(a2));
    if (Config::Verbose)
        logger.info("EndGatewayBlockActor::_getHighestSection({}) -> {}", a2.toString(), rtn);
    return rtn;
}

THook(class BlockPos&, "?findExitPortal@EndGatewayBlockActor@@SA?AVBlockPos@@AEAVWorldGenerator@@AEBV2@@Z",
      class BlockPos& ret, class WorldGenerator& a0, class BlockPos const& a1)
{
    auto& rtn = original(ret, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
#ifdef DEBUG
    auto fakeRtn = ::findExitPortal(a0, a1);
    if (rtn != fakeRtn)
        __debugbreak();
#endif // DEBUG
    if (Config::Verbose)
        logger.info("EndGatewayBlockActor::findExitPortal({}) -> {}", a1.toString(), ret.toString());
    return rtn;
}
THook(class BlockPos&, "?findTallestBlock@EndGatewayBlockActor@@SA?AVBlockPos@@AEAVBlockSource@@AEBV2@H_N@Z",
      class BlockPos& ret, class BlockSource& a0, class BlockPos const& a1, int a2, bool a3)
{
    auto& rtn = original(ret, a0, a1, a2, a3);
#ifdef DEBUG
    auto fakeRtn = findTallestBlock(a0, a1, a2, a3);
    if (rtn != fakeRtn)
        __debugbreak();
#endif // DEBUG
    if (Config::Verbose)
        logger.info("EndGatewayBlockActor::findTallestBlock({}, {}, {}) -> {}", a1.toString(), a2, a3, rtn.toString());
    return rtn;
}

THook(class BlockPos&, "?findValidSpawnAround@EndGatewayBlockActor@@SA?AVBlockPos@@AEAVBlockSource@@AEBV2@_NH@Z",
      class BlockPos& ret, class BlockSource& a0, class BlockPos const& a1, bool a2, int a3)
{
    auto& rtn = original(ret, a0, a1, a2, a3);
#ifdef DEBUG
    BlockPos fakeRet = ::findValidSpawnAround(a0, a1, a2, a3);
    if (fakeRet != ret)
        __debugbreak();
#endif // DEBUG
    if (Config::Verbose)
        logger.info("EndGatewayBlockActor::findValidSpawnAround({}, {}, {}) -> {}", a1.toString(), a2, a3, ret.toString());
    return rtn;
}

TInstanceHook(void, "?_makeEndIslandFeature@EndDragonFight@@AEAAXAEAVBlockSource@@VBlockPos@@@Z",
              EndDragonFight, class BlockSource& a0, class BlockPos a1)
{
    if (Config::Verbose)
        logger.info("EndDragonFight::_makeEndIslandFeature({})", a1.toString());
    original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
}

TInstanceHook(void, "?_placeAndLinkNewGatewayPair@EndDragonFight@@AEAAXXZ",
              EndDragonFight)
{
    // if (Config::Verbose)
    logger.warn("EndDragonFight::_placeAndLinkNewGatewayPair - Entry: {} ,Exit: {}",
                this->mEntryGenerator.mPosition.toString(), this->mExitGenerator.mPosition.toString());
    original(this);
}

TInstanceHook(bool, "?_setEndGatewayBlockActorExitPosition@EndDragonFight@@AEAA_NAEAVBlockSource@@0AEBVBlockPos@@1_N@Z",
              EndDragonFight, class BlockSource& a0, class BlockSource& a1, class BlockPos const& a2, class BlockPos const& a3, bool a4)
{
    logger.info("EndDragonFight::_setEndGatewayBlockActorExitPosition({}, {}, {})", a2.toString(), a3.toString(), a4);
    auto rtn = original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1), std::forward<decltype(a2)>(a2), std::forward<decltype(a3)>(a3), std::forward<decltype(a4)>(a4));
    return rtn;
}

TInstanceHook(void, "?_spawnNewGatewayPair@EndDragonFight@@AEAAXXZ",
              EndDragonFight)
{
    logger.info("EndDragonFight::_spawnNewGatewayPair");
    original(this);
}

TInstanceHook(void, "?loadData@EndDragonFight@@QEAAXAEBVCompoundTag@@@Z",
              EndDragonFight, class CompoundTag const& a0)
{
    logger.info("EndDragonFight::loadData");
    original(this, std::forward<decltype(a0)>(a0));
    debugLogNbt(a0);
}

TInstanceHook(void, "?saveData@EndDragonFight@@QEAAXAEAVCompoundTag@@@Z",
              EndDragonFight, class CompoundTag& a0)
{
    // logger.info("EndDragonFight::saveData");
    original(this, std::forward<decltype(a0)>(a0));
    // debugLogNbt(a0);
}

TInstanceHook(void, "?spawnNewGatewayChunks@EndDragonFight@@QEAAXAEBVBlockPos@@_N1@Z",
              EndDragonFight, class BlockPos const& a0, bool a1, bool a2)
{
    logger.info("EndDragonFight::spawnNewGatewayChunks({}, {}, {})", a0.toString(), a1, a2);
    original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1), std::forward<decltype(a2)>(a2));
}

TInstanceHook(void, "?verifyExitPositions@EndDragonFight@@QEAAXAEAVEndGatewayBlockActor@@@Z",
              EndDragonFight, class EndGatewayBlockActor& a0)
{
    logger.info("EndDragonFight::verifyExitPositions({} -> {})", a0.getPosition().toString(), a0.getExitPosition().toString());
    original(this, std::forward<decltype(a0)>(a0));
}

//#define HOOK_CLASS_EndGatewayBlockActor

#ifdef HOOK_CLASS_EndGatewayBlockActor
// parent_types : 1
// private.static : 1

// public : 6
TInstanceHook(class EndGatewayBlockActor&, "??0EndGatewayBlockActor@@QEAA@AEBVBlockPos@@@Z",
              EndGatewayBlockActor, class BlockPos const& a0)
{
    logger.info("EndGatewayBlockActor::EndGatewayBlockActor({})", a0.toString());
    auto& rtn = original(this, std::forward<decltype(a0)>(a0));
    return rtn;
}

TInstanceHook(bool, "?canTeleport@EndGatewayBlockActor@@QEBA_NPEBVGetCollisionShapeInterface@@AEBVBlockSource@@@Z",
              EndGatewayBlockActor, class GetCollisionShapeInterface const* a0, class BlockSource const& a1)
{
    auto rtn = original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
    logger.debug("EndGatewayBlockActor({})::canTeleport() -> {}", getPosition().toString(), rtn);
    return rtn;
}

TInstanceHook(class BlockPos&, "?getExitPosition@EndGatewayBlockActor@@QEBA?AVBlockPos@@XZ",
              EndGatewayBlockActor, class BlockPos& ret)
{
    auto& rtn = original(this, ret);
    // logger.info("EndGatewayBlockActor({})::getExitPosition() -> {}", getPosition().toString(), rtn.toString());
    return rtn;
}

TInstanceHook(int, "?getParticleAmount@EndGatewayBlockActor@@QEBAHAEAVBlockSource@@AEBVBlockPos@@@Z",
              EndGatewayBlockActor, class BlockSource& a0, class BlockPos const& a1)
{
    auto rtn = original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
    logger.info("EndGatewayBlockActor({})::getParticleAmount({}) -> {}", getPosition().toString(), a1.toString(), rtn);
    return rtn;
}

TInstanceHook(void, "?teleportEntity@EndGatewayBlockActor@@QEAAXAEAVActor@@@Z",
              EndGatewayBlockActor, class Actor& a0)
{
    logger.info("EndGatewayBlockActor({})::teleportEntity({})", getPosition().toString(), CommandUtils::getActorName(a0));
    original(this, std::forward<decltype(a0)>(a0));
}


TInstanceHook(bool, "?save@EndGatewayBlockActor@@UEBA_NAEAVCompoundTag@@@Z",
              EndGatewayBlockActor, class CompoundTag& a0)
{
    auto rtn = original(this, std::forward<decltype(a0)>(a0));
    if (getExitPosition() == BlockPos::ZERO || getExitPosition() == BlockPos(0, 1, 0))
    {
        logger.info("EndGatewayBlockActor({})::save", getPosition().toString());
        debugLogNbt(a0);
    }
    return rtn;
}

TInstanceHook(void, "?tick@EndGatewayBlockActor@@UEAAXAEAVBlockSource@@@Z",
              EndGatewayBlockActor, class BlockSource& a0)
{
    logger.debug("EndGatewayBlockActor({})::tick", getPosition().toString());
    original(this, std::forward<decltype(a0)>(a0));
}

// there are 5 functions with the same rva

// ?onChanged@CampfireBlockActor@@UEAAXAEAVBlockSource@@@Z
// ?onChanged@CauldronBlockActor@@UEAAXAEAVBlockSource@@@Z
// ?onChanged@CommandBlockActor@@UEAAXAEAVBlockSource@@@Z
// ?onChanged@ItemFrameBlockActor@@UEAAXAEAVBlockSource@@@Z
// ?onChanged@SignBlockActor@@UEAAXAEAVBlockSource@@@Z

// TInstanceHook(void, "?onChanged@EndGatewayBlockActor@@UEAAXAEAVBlockSource@@@Z",
//     EndGatewayBlockActor, class BlockSource & a0){
//     logger.info("EndGatewayBlockActor({})::onChanged", getPosition().toString());
//     original(this, std::forward<decltype(a0)>(a0));
// }

TInstanceHook(void, "?triggerEvent@EndGatewayBlockActor@@UEAAXHH@Z",
              EndGatewayBlockActor, int a0, int a1)
{
    logger.info("EndGatewayBlockActor({})::triggerEvent({}, {})", getPosition().toString(), a0, a1);
    original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
}

// there are 14 functions with the same rva

// ?_getUpdatePacket@BannerBlockActor@@MEAA?AV?$unique_ptr@VBlockActorDataPacket@@U?$default_delete@VBlockActorDataPacket@@@std@@@std@@AEAVBlockSource@@@Z
// ?_getUpdatePacket@BedBlockActor@@MEAA?AV?$unique_ptr@VBlockActorDataPacket@@U?$default_delete@VBlockActorDataPacket@@@std@@@std@@AEAVBlockSource@@@Z
// ?_getUpdatePacket@CampfireBlockActor@@MEAA?AV?$unique_ptr@VBlockActorDataPacket@@U?$default_delete@VBlockActorDataPacket@@@std@@@std@@AEAVBlockSource@@@Z
// ?_getUpdatePacket@ConduitBlockActor@@MEAA?AV?$unique_ptr@VBlockActorDataPacket@@U?$default_delete@VBlockActorDataPacket@@@std@@@std@@AEAVBlockSource@@@Z
// ?_getUpdatePacket@EnchantingTableBlockActor@@MEAA?AV?$unique_ptr@VBlockActorDataPacket@@U?$default_delete@VBlockActorDataPacket@@@std@@@std@@AEAVBlockSource@@@Z
// ?_getUpdatePacket@FlowerPotBlockActor@@MEAA?AV?$unique_ptr@VBlockActorDataPacket@@U?$default_delete@VBlockActorDataPacket@@@std@@@std@@AEAVBlockSource@@@Z
// ?_getUpdatePacket@ItemFrameBlockActor@@MEAA?AV?$unique_ptr@VBlockActorDataPacket@@U?$default_delete@VBlockActorDataPacket@@@std@@@std@@AEAVBlockSource@@@Z
// ?_getUpdatePacket@JigsawBlockActor@@MEAA?AV?$unique_ptr@VBlockActorDataPacket@@U?$default_delete@VBlockActorDataPacket@@@std@@@std@@AEAVBlockSource@@@Z
// ?_getUpdatePacket@LecternBlockActor@@MEAA?AV?$unique_ptr@VBlockActorDataPacket@@U?$default_delete@VBlockActorDataPacket@@@std@@@std@@AEAVBlockSource@@@Z
// ?_getUpdatePacket@LodestoneBlockActor@@MEAA?AV?$unique_ptr@VBlockActorDataPacket@@U?$default_delete@VBlockActorDataPacket@@@std@@@std@@AEAVBlockSource@@@Z
// ?_getUpdatePacket@MovingBlockActor@@MEAA?AV?$unique_ptr@VBlockActorDataPacket@@U?$default_delete@VBlockActorDataPacket@@@std@@@std@@AEAVBlockSource@@@Z
// ?_getUpdatePacket@ShulkerBoxBlockActor@@MEAA?AV?$unique_ptr@VBlockActorDataPacket@@U?$default_delete@VBlockActorDataPacket@@@std@@@std@@AEAVBlockSource@@@Z
// ?_getUpdatePacket@SignBlockActor@@MEAA?AV?$unique_ptr@VBlockActorDataPacket@@U?$default_delete@VBlockActorDataPacket@@@std@@@std@@AEAVBlockSource@@@Z
// ?_getUpdatePacket@StructureBlockActor@@MEAA?AV?$unique_ptr@VBlockActorDataPacket@@U?$default_delete@VBlockActorDataPacket@@@std@@@std@@AEAVBlockSource@@@Z

// #include <MC/BlockActorDataPacket.hpp>
// TInstanceHook(std::unique_ptr<class BlockActorDataPacket>&, "?_getUpdatePacket@EndGatewayBlockActor@@MEAA?AV?$unique_ptr@VBlockActorDataPacket@@U?$default_delete@VBlockActorDataPacket@@@std@@@std@@AEAVBlockSource@@@Z",
//     EndGatewayBlockActor, std::unique_ptr<class BlockActorDataPacket>& ret, class BlockSource & a0){
//     logger.info("EndGatewayBlockActor({})::_getUpdatePacket", getPosition().toString());
//     auto& rtn = original(this, ret, std::forward<decltype(a0)>(a0));
//     return rtn;
// }

// vtbl_entry : 1

#include <MC/Random.hpp>
TInstanceHook(void, "?animateTick@EndGatewayBlock@@UEBAXAEAVBlockSource@@AEBVBlockPos@@AEAVRandom@@@Z",
              EndGatewayBlock, class BlockSource& bs, class BlockPos const& pos, class Random& random)
{
    logger.info("EndGatewayBlock::animateTick({})", pos.toString());
    original(this, std::forward<decltype(bs)>(bs), std::forward<decltype(pos)>(pos), std::forward<decltype(random)>(random));
}

TInstanceHook(bool, "?_placeBlock@Feature@@IEBA_NAEAVBlockSource@@AEBVBlockPos@@AEBVBlock@@@Z",
              Feature, class BlockSource& bs, class BlockPos const& pos, class Block const& block)
{
    // if (*(void**)this == dlsym("??_7EndIslandFeature@@6B@"))
    //     logger.info("Feature::_placeBlock({}, {})", pos.toString(), block.getName().getString());
    return original(this, std::forward<decltype(bs)>(bs), std::forward<decltype(pos)>(pos), std::forward<decltype(block)>(block));
}

TInstanceHook(void, "?place@EndGatewayFeature@@UEBA_NAEAVBlockSource@@AEBVBlockPos@@AEAVRandom@@@Z",
              EndGatewayFeature, class BlockSource& bs, class BlockPos const& pos, class Random& random)
{
    logger.info("EndGatewayFeature::place({})", pos.toString());
    original(this, std::forward<decltype(bs)>(bs), std::forward<decltype(pos)>(pos), std::forward<decltype(random)>(random));
}

TInstanceHook(void, "?place@EndIslandFeature@@UEBA_NAEAVBlockSource@@AEBVBlockPos@@AEAVRandom@@@Z",
              EndIslandFeature, class BlockSource& bs, class BlockPos const& pos, class Random& random)
{
    logger.info("EndIslandFeature::place({})", pos.toString());
    original(this, std::forward<decltype(bs)>(bs), std::forward<decltype(pos)>(pos), std::forward<decltype(random)>(random));
}

#endif // HOOK_CLASS_EndGatewayBlockActor

//#define HOOK_CLASS_EndDragonFight

#ifdef HOOK_CLASS_EndDragonFight
// private : 14

TInstanceHook(bool, "?_canSpawnNewGateway@EndDragonFight@@AEBA_NPEAVChunkViewSource@@AEBVBlockPos@@@Z",
              EndDragonFight, class ChunkViewSource* a0, class BlockPos const& a1)
{
    // 以 a1 为中心的3*3区块加载进内存则返回true（不需要tick）
    auto rtn = original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
    // if (true) {
    //     auto info = genTickingInfo(*a0, a1, 10);
    //     logger.info("EndDragonFight::_canSpawnNewGateway({}) -> {}", a1.toString(), rtn);
    //     logger.info("{}", ColorHelper::transformToConsole(info.first));
    // }
    return rtn;
}


TInstanceHook(void, "?_spawnExitPortal@EndDragonFight@@AEAAX_N@Z",
              EndDragonFight, bool a0)
{
    logger.info("EndDragonFight::_spawnExitPortal({})", a0);
    original(this, std::forward<decltype(a0)>(a0));
}
TInstanceHook(void, "?_createNewDragon@EndDragonFight@@AEAAXXZ",
              EndDragonFight)
{
    logger.info("EndDragonFight::_createNewDragon");
    original(this);
}

TInstanceHook(void, "?_initializeDragon@EndDragonFight@@AEAAXAEAVEnderDragon@@@Z",
              EndDragonFight, class EnderDragon& a0)
{
    // logger.info("EndDragonFight::_initializeDragon");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?_setRespawnStage@EndDragonFight@@AEAAXW4RespawnAnimation@@@Z",
              EndDragonFight, enum RespawnAnimation a0)
{
    // logger.info("EndDragonFight::_setRespawnStage");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?_tickRespawnAnimation@EndDragonFight@@AEAAXAEBV?$vector@UActorUniqueID@@V?$allocator@UActorUniqueID@@@std@@@std@@H@Z",
              EndDragonFight, class std::vector<struct ActorUniqueID, class std::allocator<struct ActorUniqueID>> const& a0, int a1)
{
    // logger.info("EndDragonFight::_tickRespawnAnimation");
    original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
}

TInstanceHook(void, "?_updateCrystalCount@EndDragonFight@@AEAAXXZ",
              EndDragonFight)
{
    logger.info("EndDragonFight::_updateCrystalCount");
    original(this);
}


struct BuildMatch
{
    bool mMatched;
    bool mForward;
    bool mUp;
    int mNumPatterns;
    int mPatternSize;
    int mSubPatternIndex;
    int mRowIndex;
    BlockPos mPattern;
    Vec3 mObjectPos;
};

TInstanceHook(struct BuildMatch&, "?_findExitPortal@EndDragonFight@@AEAA?AUBuildMatch@@XZ",
              EndDragonFight, struct BuildMatch& ret)
{
    logger.info("EndDragonFight::_findExitPortal");
    auto& rtn = original(this, ret);
    return rtn;
}

// public : 10
TInstanceHook(class EndDragonFight&, "??1EndDragonFight@@QEAA@XZ",
              EndDragonFight)
{
    logger.info("EndDragonFight::~EndDragonFight");
    auto& rtn = original(this);
    return rtn;
}

TInstanceHook(class EndDragonFight&, "??0EndDragonFight@@QEAA@AEAVBlockSource@@@Z",
              EndDragonFight, class BlockSource& a0)
{
    logger.info("EndDragonFight::EndDragonFight");
    auto& rtn = original(this, std::forward<decltype(a0)>(a0));
    return rtn;
}

TInstanceHook(void, "?onCrystalDestroyed@EndDragonFight@@QEAAXAEBVEnderCrystal@@AEBVActorDamageSource@@@Z",
              EndDragonFight, class EnderCrystal const& a0, class ActorDamageSource const& a1)
{
    logger.info("EndDragonFight::onCrystalDestroyed");
    original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
}

TInstanceHook(void, "?resetSpikeCrystals@EndDragonFight@@QEAAXXZ",
              EndDragonFight)
{
    logger.info("EndDragonFight::resetSpikeCrystals");
    original(this);
}

TInstanceHook(void, "?tick@EndDragonFight@@QEAAXXZ",
              EndDragonFight)
{
    // logger.info("EndDragonFight::tick");
    original(this);
}

TInstanceHook(void, "?tryRespawn@EndDragonFight@@QEAAXXZ",
              EndDragonFight)
{
    logger.info("EndDragonFight::tryRespawn");
    original(this);
}


#endif // HOOK_CLASS_EndDragonFight

#include <MC/GameMode.hpp>
#include <MC/ItemStack.hpp>
#include <shared_mutex>
#include <MC/BlockTypeRegistry.hpp>
#include <MC/HitResult.hpp>
#include <MC/HitDetection.hpp>
#include "EndGatewayCommand.h"

TInstanceHook(bool, "?destroyBlock@GameMode@@UEAA_NAEBVBlockPos@@E@Z",
              GameMode, class BlockPos const& bpos, unsigned char face)
{
    auto& player = *this->getPlayer();
    auto ba = (EndGatewayBlockActor*)player.getRegion().getBlockEntity(bpos);
    if (ba && ba->getType() == (BlockActorType)24)
    {
        auto& item = player.getSelectedItem();
        if (item.getTypeName() == "minecraft:stick")
        {
            player.sendTextPacket(ba->getNbt()->toPrettySNBT(true));
            return false;
        }
        else if (item.getTypeName() == "minecraft:arrow")
        {
            auto pos = ba->getExitPosition();
            player.teleport(Vec3(pos), 2);
            return false;
        }
    }
    return original(this, bpos, face);
}

TClasslessInstanceHook(Actor*,
                       "?spawnProjectile@Spawner@@QEAAPEAVActor@@AEAVBlockSource@@AEBUActorDefinitionIdentifier@@PEAV2@AEBVVec3@@3@Z",
                       class BlockSource& region, struct ActorDefinitionIdentifier const& identifier, class Actor* actor, class Vec3 const& position, class Vec3 const& velocity)
{
    auto projectile = original(this, region, identifier, actor, position, velocity);
    try
    {

        if (identifier.getCanonicalName() == "minecraft:ender_pearl")
        {
            const int maxDistance = 512;
            const bool includeLiquid = false;
            const bool solidOnly = false;
            const bool ignoreBorderBlocks = true;
            const bool fullOnly = false;
            Vec3 viewVec = velocity;
            if (actor && viewVec == Vec3::ZERO)
            {
                viewVec = actor->getViewVector(1.0f);
            }
            Vec3 viewPos = position + (viewVec * maxDistance);
            Player* player = actor != nullptr && actor->isPlayer() ? (Player*)this : nullptr;
            int maxDisManhattan = (int)((maxDistance + 1) * 2);
            HitResult blockResult = region.clip(position, viewPos, includeLiquid, solidOnly, maxDisManhattan, ignoreBorderBlocks, fullOnly, nullptr, BlockSource::ClipParameters::CHECK_ALL_BLOCKS);
            float blockDistance = FLT_MAX;
            if (blockResult.isHit())
            {
                blockDistance = position.distanceTo(blockResult.getPos());
                const_cast<Vec3&>(position) = blockResult.getPos();
                projectile->setPos(position);
            }
            else if (actor)
            {
                auto& aabb = actor->getAABB();
                Actor* actorResult = nullptr;
                float distance = 0.0f;
                Vec3 resultPos{};
                HitDetection::searchActors(viewVec, maxDistance, position, aabb, actor, (Player*)this, distance, actorResult, resultPos, false);
                if (actorResult && distance < blockDistance)
                {
                    const_cast<Vec3&>(position) = resultPos;
                    projectile->setPos(position);
                }
            }
        }
    }
    catch (...)
    {
        logger.error("Error in hook spawnProjectile");
    }
    return projectile;
}

TClasslessInstanceHook(class HashedString const&,
                       "?getCooldownType@EnderpearlItem@@UEBAAEBVHashedString@@XZ")
{
    return HashedString::getEmptyString();
}


inline void printBlocks()
{
    I18n::chooseLanguage("zh_CN");
    std::ostringstream blockCsv, materialCsv;
    blockCsv << "Name,Trans,Material,SolidBlckingBlock,SolidBlckingMaterial,SolidBlock,BlockProperties" << std::endl;
    materialCsv << "Material,Flammable,NeverBuildable,AlwaysDestroyable,Replaceable,Liquid,Translucency,BlocksMotion,BlocksPrecipitation,Solid,SuperHot" << std::endl;
    std::vector<std::pair<int, std::string>> blocks;
    BlockTypeRegistry::forEachBlock([&](class BlockLegacy const& bl) {
        static_assert(sizeof(Material) == 0x14);
        auto& material = bl.getMaterial();
        auto& Name = bl.getRawNameId();
        auto Trans = bl.buildDescriptionName(bl.getDefaultState());
        if (Trans._Starts_with("tile."))
        {
            auto key = "item" + Trans.substr(4);
            auto newTrans = I18n::get(key);
            if (!newTrans._Starts_with("item."))
                Trans = newTrans;
            else
                Trans = "NoTrans";
        }
        auto& Type = material.mType;
        bool SolidBlckingBlock = bl.isSolidBlockingBlock();
        bool SolidBlockingMaterial = material.isSolidBlocking();
        bool Solid = bl.isSolid();
        uint64_t BlockProperties = dAccess<uint64_t>(&bl, 168);
        // bool Propetory = bl.get;
        auto line = fmt::format("{},{},{},{},{},{},0x{:X}\n",
                                Name, Trans, (int)Type, SolidBlckingBlock, SolidBlockingMaterial, Solid, BlockProperties);
        blocks.push_back({(int)Type, line});
        // blockCsv << line;
        return true;
    });
    std::sort(blocks.begin(), blocks.end(), [](auto& a, auto& b) {
        return (int)a.first < (int)b.first;
    });
    for (auto& block : blocks)
    {
        blockCsv << block.second;
    }
    for (auto& material : Material::getAll())
    {
        auto& Type = material->mType;
        auto& Flammable = material->mFlammable;
        auto& NeverBuildable = material->mNeverBuildable;
        auto& AlwaysDestroyable = material->mAlwaysDestroyable;
        auto& Replaceable = material->mReplaceable;
        auto& Liquid = material->mLiquid;
        auto& Translucency = material->mTranslucency;
        auto& BlocksMotion = material->mBlocksMotion;
        auto& BlocksPrecipitation = material->mBlocksPrecipitation;
        auto& Solid = material->mSolid;
        auto& SuperHot = material->mSuperHot;
        assert(material->isType(Type));
        assert(Flammable == material->isFlammable());
        // assert(NeverBuildable == material->isNeverBuildable());
        assert(AlwaysDestroyable == material->isAlwaysDestroyable());
        assert(Replaceable == material->isReplaceable());
        assert(Liquid == material->isLiquid());
        assert(Translucency == material->getTranslucency());
        assert(BlocksMotion == material->getBlocksMotion());
        assert(BlocksPrecipitation == material->getBlocksPrecipitation());
        assert(Solid == material->isSolid());
        assert(SuperHot == material->isSuperHot());
        materialCsv << fmt::format("{},{},{},{},{},{},{},{},{},{},{}\n",
                                   (int)Type, Flammable, NeverBuildable, AlwaysDestroyable, Replaceable, Liquid, Translucency, BlocksMotion, BlocksPrecipitation, Solid, SuperHot);
    }
    WriteAllFile("blocks.csv", blockCsv.str(), false);
    WriteAllFile("materials.csv", materialCsv.str(), false);
}

void entry()
{
    // Schedule::nextTick(printBlocks);
    Event::RegCmdEvent::subscribe_ref([](Event::RegCmdEvent& ev) {
        EndGatewayCommand::setup(*ev.mCommandRegistry);
        return true;
    });
}


#ifdef DEBUG_

#include <MC/ActorDefinitionDescriptor.hpp>
#include <MC/CommandUtils.hpp>
#include <MC/Sheep.hpp>
TInstanceHook(bool, "?executeEvent@ActorDefinitionDescriptor@@QEAA_NAEAVActor@@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEBVVariantParameterList@@@Z",
              ActorDefinitionDescriptor, class Actor& actor, std::string const& identifier, class VariantParameterList const& params)
{
    auto rtn = original(this, actor, identifier, params);
    // logger.warn("executeEvent - {} - {} -> {}", CommandUtils::getActorName(actor), identifier, rtn);
    return rtn;
}
TInstanceHook(bool, "?handleEntityEvent@Sheep@@UEAAXW4ActorEvent@@H@Z",
              Sheep, enum ActorEvent ev, int i)
{
    auto rtn = original(this, ev, i);
    logger.warn("handleEntityEvent - {} - {} -> {}", CommandUtils::getActorName(*this), (int)ev, i);
    return rtn;
}

#include <MC/FallingBlock.hpp>
TInstanceHook(void, "?_waitRemoval@FallingBlock@@AEAAXXZ",
              FallingBlock)
{
    original(this);
    logger.warn("_waitRemoval - {} - {}", CommandUtils::getActorName(*this), getUniqueID().id);
}
#include <MC/FallingBlock.hpp>
TInstanceHook(void, "?normalTick@FallingBlock@@UEAAXXZ",
              FallingBlock)
{
    auto d1840 = dAccess<int, 1840>(this);
    auto d1836 = dAccess<int, 1836>(this);
    logger.warn("normalTick - {} - {} - d1836: {} - d1840: {}",
                CommandUtils::getActorName(*this), getUniqueID().id, d1836, d1840);
    original(this);
}

#endif // DEBUG

//#define VOID_WORLD

#ifdef VOID_WORLD
TClasslessInstanceHook(bool, "?_hasChunk@DBChunkStorage@@AEAA_NAEBVDBChunkStorageKey@@@Z",
                       class DBChunkStorageKey const& key)
{
    auto rtn = original(this, key);
    // if(!rtn)
    //     printf("OnChunkFirstLoaded: (%d, %d) in dim: %d\n", key->cx, key->cy, key->dimid);
    // else
    //     printf("OnChunkLoaded: (%d, %d) in dim: %d\n", key->cx, key->cy, key->dimid);
    return true;
}
#endif // VOID_WORLD
