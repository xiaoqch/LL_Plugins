#include "pch.h"
#include "EnumGenerator.h"
#ifdef ENABLE_TEST_ENUM
#include <MC/BlockLegacy.hpp>
#include <MC/Util.hpp>
#include <MC/MinecraftPackets.hpp>
#include <MC/Packet.hpp>
void genPktIDs()
{
    for (int i = 0; i < 200; i++)
    {
        auto pkt = MinecraftPackets::createPacket((MinecraftPacketIds)i);
        if (pkt.get())
            fmt::print("{} = \\x{:X},\n", pkt->getName(), i);
    }
}

void genBlockType()
{
    auto mBlockLookupMap = (map<string, std::shared_ptr<BlockLegacy>*>*)dlsym("?mBlockLookupMap@BlockTypeRegistry@@0V?$map@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$SharedPtr@VBlockLegacy@@@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$SharedPtr@VBlockLegacy@@@@@std@@@2@@std@@A");
    std::tuple<string, int, string> datas;
    std::cout << "enum BlockType : short{" << std::endl;
    for (auto& [name, blockptr] : *mBlockLookupMap)
    {
        auto blockLegacy = blockptr->get();
        if (!blockLegacy)
        {
            continue;
        }
        auto& blockName = blockLegacy->getRawNameId();
        auto blockItemId = blockLegacy->getBlockItemId();
        auto block = &blockLegacy->getRenderBlock();
        string tmp = "m_" + blockName.substr(blockName.find(':') + 1);
        auto enumName = Util::toCamelCase(tmp, '_');
        // LOG_VAR(blockName)
        // LOG_VAR(blockItemId)
        // LOG_VAR(offset)
        std::cout << "    " << enumName << " = " << blockItemId << ", // " << blockName << std::endl;
    }
    std::cout << "};" << std::endl;
}
#include <MC/Container.hpp>
struct FContainer : public Container
{
    inline static auto getMap()
    {
        return containerTypeMap;
    }
};
void validContainerType()
{
    for (auto& [type, name] : FContainer::getMap().mMap1)
    {
        if (name != magic_enum::enum_name(type))
            __debugbreak();
    }
}
#include <MC/ActorDamageSource.hpp>
void genActorDamageCause()
{
    logger.error(ActorDamageSource::lookupCauseName((ActorDamageCause)0x1F));
    std::vector<std::pair<std::string, enum ActorDamageCause>> causeEnum = ActorDamageSource::generateDamageCauseCommandEnum();
    std::sort(causeEnum.begin(), causeEnum.end(), [](std::pair<std::string, enum ActorDamageCause> left, std::pair<std::string, enum ActorDamageCause> right) { return left.second < right.second; });
    for (auto& [name, cause] : causeEnum)
    {
        logger.warn("{} = 0x{:0>2X},", Util::toCamelCase("m_" + name, '_').substr(1), (int)cause);
    }
    __debugbreak();
}

#include <ScheduleAPI.h>
void EnumGenerator::gen()
{
    Schedule::nextTick([]() {
        //genBlockType();
        //genPktIDs();
        //validContainerType();
        genActorDamageCause();
    });
}

#endif // ENABLE_TEST_ENUM