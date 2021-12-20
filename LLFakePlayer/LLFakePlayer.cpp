#include "pch.h"
#include <MC/BlockLegacy.hpp>
#include <MC/BlockTypeRegistry.hpp>
#include <MC/Util.hpp>
#include <EventAPI.h>
#include "FakePlayerCommand.h"

using std::shared_ptr;

void genBlockType() {
    auto mBlockLookupMap = (map<string, shared_ptr<BlockLegacy>*>*)dlsym("?mBlockLookupMap@BlockTypeRegistry@@0V?$map@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$SharedPtr@VBlockLegacy@@@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$SharedPtr@VBlockLegacy@@@@@std@@@2@@std@@A");
    std::tuple<string, int, string> datas;
    std::cout << "enum BlockType : short{" << std::endl;
    for (auto& [name, blockptr] : *mBlockLookupMap) {
        auto blockLegacy = blockptr->get();
        if (!blockLegacy) {
            continue;
        }
        auto blockName = blockLegacy->getRawNameId();
        auto blockItemId = blockLegacy->getBlockItemId();
        auto block = &blockLegacy->getRenderBlock();
        string tmp = "m_" + blockName.substr(blockName.find(':') + 1);
        auto enumName = Util::toCamelCase(tmp, '_');
        //LOG_VAR(blockName)
        //LOG_VAR(blockItemId)
        //LOG_VAR(offset)
        std::cout << "    " << enumName << " = " << blockItemId << ", // " << blockName << std::endl;
    }
    std::cout << "};" << std::endl;
}
#include <MC/CompoundTag.hpp>
void testRW(std::string const& binary, bool isLittle) {
    logger.info("size: {}, isLittleEndian: {}", binary.size(), isLittle);
    auto tag = CompoundTag::fromBinaryNBT((void*)binary.c_str(), binary.size(), isLittle);
    auto newBinary = tag->toBinaryNBT(isLittle);
    if (binary == newBinary) {
        logger.info("bin->tag->bin 测试通过");
    }
    else {
        logger.error("bin->tag->bin 测试未通过");
    }
    auto snbt = tag->toSNBT();
    auto newTag = CompoundTag::fromSNBT(snbt);
    if (tag->equals(*newTag)) {
        logger.info("tag->snbt->tag 测试通过");
    }
    else {
        logger.error("tag->snbt->tag 测试未通过");
        WriteAllFile(fmt::format("./test/error{}.nbt", isLittle?"":"_big"), newTag->toBinaryNBT(isLittle), true);
        return;
    }
    auto newSnbt = newTag->toSNBT();
    if (newSnbt==snbt) {
        //logger.info("snbt->tag->snbt 测试通过");
    }
    else {
        logger.error("snbt->tag->snbt 测试未通过");
        WriteAllFile(fmt::format("./test/error{}.nbt", isLittle ? "" : "_big"), newTag->toBinaryNBT(isLittle), true);
        return;
    }

}
void testNbt() {
    auto filePath = "./test/test.nbt";
    auto binary = ReadAllFile(filePath, true);
    logger.info("Testing file:  {}", filePath);
    testRW(binary.value(), true);

    filePath = "./test/test_big.nbt";
    binary = ReadAllFile(filePath, true);
    logger.info("Testing file:  {}", filePath);
    testRW(binary.value(), false);

    filePath = "./test/test_longarray.nbt";
    binary = ReadAllFile(filePath, true);
    logger.info("Testing file:  {}", filePath);
    testRW(binary.value(), true);
}
void entry() {
    Event::ServerStartedEvent::subscribe([](Event::ServerStartedEvent ev)->bool {
        //genBlockType();
        testNbt();
        return true;
        });
    Event::RegCmdEvent::subscribe([](Event::RegCmdEvent ev)->bool {
        FakePlayerCommand::setup(*ev.mCommandRegistry);
        return true;
        });
}