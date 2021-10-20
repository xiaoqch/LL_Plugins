﻿#pragma once
#include <api/serviceLocate.h>
#include <loader/Loader.h>
#include <mc/Core.h>
#include <functional>
#include <iostream>

struct MCRESULT {
    unsigned char filler[4];
    operator bool() { return filler[0]; }
    bool isSuccess() { return operator bool(); }
};
class CommandOrigin;
struct CommandContext {
    std::string CMD;
    CommandOrigin *Ori;
    int Version = 10;
    std::string &getCmd() { return CMD; }
    class CommandOrigin &getOrigin() {
        return *Ori;
    }
    template <typename TP>
    CommandContext(TP &&x, CommandOrigin *o) : CMD(std::forward<TP>(x)), Ori(o) {}
};
static_assert(offsetof(CommandContext, Ori) == 32);

class MinecraftCommands;
class MinecraftCommands {
  public:
    static MCRESULT _runcmd(void* origin, const std::string& cmd, int unk1, bool unk2) {
        MCRESULT rv;
        SymCall(
            "?executeCommand@MinecraftCommands@@QEBA?AUMCRESULT@@V?$shared_ptr@VCommandContext@@@"
            "std@@_N@Z",
            void, MinecraftCommands *, MCRESULT *, std::shared_ptr<CommandContext>,
            bool)(LocateS<MinecraftCommands>::_srv, &rv,
                  std::make_shared<CommandContext>(cmd, (CommandOrigin *)origin), false);
        // SymCall("?requestCommandExecution@MinecraftCommands@@QEBA?AUMCRESULT@@V?$unique_ptr@VCommandOrigin@@U?$default_delete@VCommandOrigin@@@std@@@std@@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@4@H_N@Z",
        // void, MinecraftCommands*, MCRESULT*, void**, std::string const&, int,
        // bool)(LocateS<MinecraftCommands>::_srv, &rv, &origin, cmd, unk1, unk2);
        return rv;
    }
};
class RakNetServerLocator {
  public:
    MCINLINE void accounce(class std::basic_string<char,
                                                   struct std::char_traits<char>,
                                                   class std::allocator<char>> const &a,
                           class std::basic_string<char,
                                                   struct std::char_traits<char>,
                                                   class std::allocator<char>> const &b,
                           int c_type,
                           int d,
                           int e,
                           bool f) {
        SymCall(
            "?announceServer@RakNetServerLocator@@UEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?"
            "$allocator@D@2@@std@@0W4GameType@@HH_N@Z",
            void, void *,
            class std::basic_string<char, struct std::char_traits<char>,
                                    class std::allocator<char>> const &,
            class std::basic_string<char, struct std::char_traits<char>,
                                    class std::allocator<char>> const &,
            int, int, int, bool)(this, a, b, c_type, d, e, f);
    }
};

namespace mce {
class UUID;
};
class NetworkIdentifier {
    char filler[144];
};
namespace Util {
class HashString;
};

namespace Json {
class Value;
}

namespace RakNet {
struct SystemAddress {
    char           filler[17*8]; // uncertain?
    std::string toString() {
        char buf[128];
        SymCall("?ToString@SystemAddress@RakNet@@QEBAX_NPEADD@Z", void, void*, bool, char*, char)(
            this, true, buf, ':');
        return buf;
    }
};
struct RakNetGUID {
    uint64_t unk;
    short    unk8;
};
struct RakPeer {
    RakPeer(RakPeer const&) = delete;
    RakPeer(RakPeer&&)      = delete;
    SystemAddress getAdr(NetworkIdentifier const& ni) {
        SystemAddress rv;
        RakNetGUID    guid = dAccess<RakNetGUID>(&ni, 8);
        SymCall("?GetSystemAddressFromGuid@RakPeer@RakNet@@UEBA?AUSystemAddress@2@URakNetGUID@2@@Z",
                void, void*, SystemAddress*, RakNetGUID const*)(this, &rv, &guid);
        return rv;
    }
};
}


class ServerPlayer;
class ServerNetworkHandler {
  public:
    // class ServerPlayer * __ptr64 __cdecl ServerNetworkHandler::_getServerPlayer(class
    // NetworkIdentifier const & __ptr64,unsigned char)
    ServerPlayer *_getServerPlayer(NetworkIdentifier const &a0, unsigned char a1) {
        return SymCall(
            "?_getServerPlayer@ServerNetworkHandler@@AEAAPEAVServerPlayer@@AEBVNetworkIdentifier@@"
            "E@Z",
            ServerPlayer *, decltype(this), decltype(a0), decltype(a1))(this, a0, a1);
    }
    MCINLINE void disconnectClient(class NetworkIdentifier const &a,
                                   class std::basic_string<char,
                                                           struct std::char_traits<char>,
                                                           class std::allocator<char>> const &b,
                                   bool c) {
        return SymCall(
            "?disconnectClient@ServerNetworkHandler@@QEAAXAEBVNetworkIdentifier@@AEBV?$basic_"
            "string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@_N@Z",
            void, void *, class NetworkIdentifier const &,
            class std::basic_string<char, struct std::char_traits<char>,
                                    class std::allocator<char>> const &,
            bool)(this, a, b, c);
    }
    MCINLINE void onDisconnect(class NetworkIdentifier const &a0) {
        SymCall(
            "?onDisconnect@ServerNetworkHandler@@UEAAXAEBVNetworkIdentifier@@AEBV?$basic_string@DU?"
            "$char_traits@D@std@@V?$allocator@D@2@@std@@_N1@Z",
            void, ServerNetworkHandler const *, class NetworkIdentifier const &)(this, a0);
    }
};
class Minecraft {
  public:
    MCINLINE class Level *getLevel() {
        class Level *(Minecraft::*rv)();
        *((void **)&rv) = dlsym("?getLevel@Minecraft@@QEBAPEAVLevel@@XZ");
        return (this->*rv)();
    }
    MCINLINE class ServerNetworkHandler *getServerNetworkHandler() {
        class ServerNetworkHandler *(Minecraft::*rv)();
        *((void **)&rv) =
            dlsym("?getServerNetworkHandler@Minecraft@@QEAAPEAVServerNetworkHandler@@XZ");
        return (this->*rv)();
    }
    MCINLINE class NetworkHandler* getNetworkHandler() {
        class NetworkHandler* (Minecraft::*fnp)() const;
        *((void**)&fnp) = dlsym("?getNetworkHandler@Minecraft@@QEAAAEAVNetworkHandler@@XZ");
        return (this->*fnp)();
    }
};

class NetworkPeer {
public:
    enum class Reliability : int {};
    enum class DataStatus : int { OK,
                                  BUSY };
    struct NetworkStatus {
        int    level;
        int    ping, avgping;
        double packetloss, avgpacketloss;
        char   pkt[64];
    };

    virtual void          sendPacket(std::string, NetworkPeer::Reliability, int) = 0;
    virtual DataStatus    receivePacket(std::string&)                            = 0;
    virtual NetworkStatus getNetworkStatus()                                     = 0;
};