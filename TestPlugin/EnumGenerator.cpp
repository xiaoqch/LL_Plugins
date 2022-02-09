#include "pch.h"
#include "EnumGenerator.h"
#ifdef ENABLE_TEST_ENUM
#include <MC/BlockLegacy.hpp>
#include <MC/BlockTypeRegistry.hpp>
#include <MC/Util.hpp>
#include <MC/MinecraftPackets.hpp>
#include <MC/Packet.hpp>
void genPktIDs() {
    for (int i = 0; i < 200; i++) {
        auto pkt = MinecraftPackets::createPacket((MinecraftPacketIds)i);
        if (pkt.get())
            fmt::print("{} = \\x{:X},\n", pkt->getName(), i);
    }
}

void genBlockType() {
    auto mBlockLookupMap = (map<string, std::shared_ptr<BlockLegacy>*>*)dlsym("?mBlockLookupMap@BlockTypeRegistry@@0V?$map@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$SharedPtr@VBlockLegacy@@@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$SharedPtr@VBlockLegacy@@@@@std@@@2@@std@@A");
    std::tuple<string, int, string> datas;
    std::cout << "enum BlockType : short{" << std::endl;
    for (auto& [name, blockptr] : *mBlockLookupMap) {
        auto blockLegacy = blockptr->get();
        if (!blockLegacy) {
            continue;
        }
        auto& blockName = blockLegacy->getRawNameId();
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
#endif // ENABLE_TEST_ENUM

void EnumGenerator::gen()
{
#ifdef ENABLE_TEST_ENUM
    genBlockType();
    testNbt();
    genPktIDs();
#endif // ENABLE_TEST_ENUM
}
