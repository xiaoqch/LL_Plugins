#include "pch.h"
#include "TestRegRecipe.h"
#include <EventAPI.h>
#include <ScheduleAPI.h>
#include "TestDBStorage.h"
#include "TestCommandReg.h"
#include "EnumGenerator.h"
#include "TestNbt.h"
#include "TestDlsym.h"
#include <MC/ChunkViewSource.hpp>
#include <MC/Level.hpp>
#include <MC/BlockSource.hpp>
#include <MC/WorldGenerator.hpp>
#include <MC/LevelChunk.hpp>
#include <MC/Dimension.hpp>
#include <MC/VanillaBlockTypes.hpp>
#include <MC/EndGatewayBlock.hpp>
#include <MC/EndGatewayFeature.hpp>
#include <MC/EndIslandFeature.hpp>
#include <MC/BlockActor.hpp>
#include <MC/Block.hpp>
#include <MC/ServerPlayer.hpp>
#include <MC/ItemStack.hpp>
#include <MC/VanillaBlocks.hpp>
#include <MC/CompoundTag.hpp>
#include <MC/GameMode.hpp>
#include <MC/Random.hpp>
#include "TestAI.h"

//#include <MC/ItemDescriptor.hpp>
void genBlockActorType()
{
    auto& m = *(std::map<enum BlockActorType, class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>>, struct std::less<enum BlockActorType>, class std::allocator<struct std::pair<enum BlockActorType const, class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>>>>>*)dlsym("?mClassIdMap@BlockActor@@0V?$map@W4BlockActorType@@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@W4BlockActorType@@@3@V?$allocator@U?$pair@$$CBW4BlockActorType@@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@3@@std@@B");
    for (auto& [k, v] : m)
        logger.warn("{} = 0x{:02X}", v, (int)k);
    auto& m2 = *(std::map<class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>>, enum BlockActorType, struct std::less<class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>>>, class std::allocator<struct std::pair<class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>> const, enum BlockActorType>>>*)dlsym("?mIdClassMap@BlockActor@@0V?$map@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@W4BlockActorType@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@W4BlockActorType@@@std@@@2@@std@@B");
    for (auto& [k, v] : m2)
        logger.warn("{} = 0x{:02X}", k, (int)v);
}
void entry()
{
    //Schedule::nextTick(genBlockActorType);
    logger.consoleLevel = logger.info.level;
    logger.fileLevel = logger.warn.level;
    // ItemDescriptor i1;
    // ItemDescriptor i2;
    // i1 = i2;
    Schedule::delay([]() { testMCAPI(); }, 200);
    Event::ServerStartedEvent::subscribe([](Event::ServerStartedEvent const& ev) -> bool {
        testRegRecipe();
        testStaticDlsym();
        TestNbt::test();
        TestCommandReg::test();
        TestDBStorage::test();
        EnumGenerator::gen();
        // verifyHashUnique();
        return true;
    });
    Event::RegCmdEvent::subscribe([](Event::RegCmdEvent const& ev) -> bool {
#ifdef ENABLE_TEST_DBSTORAGE
        RemovePlayerCommand::setup(*ev.mCommandRegistry);
        DBTestCommand::setup(*ev.mCommandRegistry);
#endif // ENABLE_TEST_DBSTORAGE
#ifdef ENABLE_TEST_AI
        AiTest::setupCommand(*ev.mCommandRegistry);
#endif // ENABLE_TEST_AI
        return true;
    });
}

// namespace
//{
// bool isEdu = false;
// }
// TClasslessInstanceHook(bool, "?isEducationEditionLevel@LevelData@@QEBA_NXZ")
//{
//     return isEdu;
// }
// TClasslessInstanceHook(void, "?setupStandardServer@ServerCommands@@YAXAEAVMinecraft@@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@1PEAVPermissionsFile@@@Z",
//                        class Minecraft& mc, std::string const&a2, std::string const& a3, class PermissionsFile* a4)
//{
//     isEdu = true;
//     original(this, mc, a2, a3, a4);
//     isEdu = false;
// }

// TClasslessInstanceHook(void, "?updateServerAnnouncement@ServerNetworkHandler@@QEAAXXZ")
//{
//#ifdef DEBUG
//
//    auto v8 = *dAccess<voids<>*>(this, 13 * 8);
//    auto motd = dAccess<char*>(this, 632);
//    using Fn = void (*)(void*, char *, std::string const&, unsigned int, int, int, char);
//    auto v9 = dAccess<Fn>(&v8, 24);
//    auto v10 = dAccess<int>(this, 188 * 4);
//    std::string levelName = "TestName";
//    v9(&v8, motd, levelName, 1, 12, v10, 1);
//#endif // DEBUG
//    //original(this);
// }

