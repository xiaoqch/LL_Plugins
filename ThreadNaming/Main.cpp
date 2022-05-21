#include "pch.h"
#include <EventAPI.h>
#include <PlayerInfoAPI.h>
#include <filesystem>
#include <MC/BinaryStream.hpp>
#include <MC/EduUriResourcePacket.hpp>
#include <MC/NetworkHandler.hpp>
#include <MC/ServerNetworkHandler.hpp>
#include <MC/ServerPlayer.hpp>
void entry()
{
    std::filesystem::create_directories(PLUGIN_DIR);
    //std::string data = "\xAA\x01\xAC\xF1\xFF\xFF\xFF\xFF\x07\x5F\xAC\xF1\xFF\xFF\xFF\xFF\x07\x5F";
    //ReadOnlyBinaryStream bs(std::move(data));
    ////auto buttonName = bs.getString();
    ////auto linkURI = bs.getString();
    //EduUriResourcePacket pkt;
    //auto res = pkt.read(bs);
    //logger.error("{} - {}", pkt.mButtonName, pkt.mLinkUri);
}

TClasslessInstanceHook(unsigned int, "?UpdateNetworkLoop@RakNet@@YAIPEAX@Z",
                       void* a1)
{
    SetThreadDescription(GetCurrentThread(), L"RakNet UpdateNetworkLoop");
    return original(this, a1);
}

TClasslessInstanceHook(unsigned int, "?ConnectionAttemptLoop@RakNet@@YAIPEAX@Z",
                       void* a1)
{
    SetThreadDescription(GetCurrentThread(), L"RakNet ConnectionAttemptLoop");
    return original(this, a1);
}

TClasslessInstanceHook(unsigned int, "?UpdateTCPInterfaceLoop@RakNet@@YAIPEAX@Z",
                       void* a1)
{
    SetThreadDescription(GetCurrentThread(), L"RakNet UpdateTCPInterfaceLoop");
    return original(this, a1);
}

TClasslessInstanceHook(unsigned int, "?RecvFromLoop@RNS2_Berkley@RakNet@@KAIPEAX@Z",
                       void* a1)
{
    SetThreadDescription(GetCurrentThread(), L"RakNet RNS2_Berkley RecvFromLoop");
    return original(this, a1);
}

THook(void, "?crashDumpLogThreadRoutine@CrashDumpLog@@CAXXZ",
      void)
{
    SetThreadDescription(GetCurrentThread(), L"CrashDumpLogThread");
    return original();
}

TClasslessInstanceHook(bool, "??$inner_enqueue@$0A@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$SPSCQueue@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@$0CAA@@@AEAA_NAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z",
      std::string const& a1)
{
    static bool inited = ([]() {
        SetThreadDescription(GetCurrentThread(), L"Console Input");
        return true;
    })();
    return original(this, a1);
}

//static_assert(sizeof(EduUriResourcePacket) == 0x70, "size of EduUriResourcePacket should be 112");

#if false
bool errorPacket = false;

TInstanceHook(enum StreamReadResult, "?_read@EduUriResourcePacket@@EEAA?AW4StreamReadResult@@AEAVReadOnlyBinaryStream@@@Z",
              EduUriResourcePacket, class ReadOnlyBinaryStream& bs)
{
    _set_se_translator(seh_exception::TranslateSEHtoCE);
    
    try
    {
        auto dataFilePath = fmt::format("{}EduUriResourcePacket-{:%Y%m%d-%H%M%S}.bin", PLUGIN_DIR, fmt::localtime(_time64(nullptr)));
        WriteAllFile(dataFilePath, bs.getData(), true);
        logger.warn("EduUriResourcePacket data had write to {}", dataFilePath);
        return original(this, bs);
    }
    catch (...)
    {
        errorPacket = true;
        logger.error("Exception in EduUriResourcePacket::_read");
    }
    return (StreamReadResult)0;
}

TInstanceHook(bool, "?_sortAndPacketizeEvents@NetworkHandler@@AEAA_NAEAVConnection@1@V?$time_point@Usteady_clock@chrono@std@@V?$duration@_JU?$ratio@$00$0DLJKMKAA@@std@@@23@@chrono@std@@@Z",
              NetworkHandler, class NetworkHandler::Connection& conn, void* a2)
{
    bool rtn = original(this, conn, a2);
    if (errorPacket) {
        errorPacket = false;
        auto player = Global<ServerNetworkHandler>->getServerPlayer((NetworkIdentifier&)conn, 0);
        if (player)
            logger.error("Player: {}, xuid: {}", player->getName(), player->getXuid());
    }
    return rtn;
}
#endif
