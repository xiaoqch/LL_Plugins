#pragma once
#include "Config.h"
#include <MC/SimulatedPlayer.hpp>
#include <MC/CompoundTag.hpp>
#include <MC/Int64Tag.hpp>
#include <MC/StringTag.hpp>
#include <MC/ByteTag.hpp>
#include <functional>
#include <KVDBAPI.h>

mce::UUID JAVA_nameUUIDFromBytes(std::string const& name);

class FakePlayerManager;
class FakePlayer;
class FakePlayerStorage;

class FakePlayer {
    std::string mRealName;
    mce::UUID mUUID;
    time_t mLastOnlineTime;
    bool mAutoLogin = false;
    FakePlayerManager* mManager;

    // 
    ActorUniqueID mUniqueID;
    bool mOnline = false;
    SimulatedPlayer* mPlayer = nullptr;
    unsigned char mClientSubID = -1;

    friend class FakePlayerManager;
    friend class FakePlayerStorage;
public:
    static bool mLoggingIn;
    static FakePlayer* mLoggingInPlayer;

    static NetworkIdentifier mNetworkID;
    static unsigned char mMaxClientSubID;
    
    FakePlayer(std::string const& realName, mce::UUID uuid, time_t lastOnlineTime = 0, bool autoLogin = false, FakePlayerManager* manager = nullptr);
    ~FakePlayer();
    static std::shared_ptr<FakePlayer> deserialize(CompoundTag const& tag, FakePlayerManager* manager);
    std::unique_ptr<CompoundTag> serialize();

    bool login();
    bool logout(bool save = true);
    mce::UUID getUUID();
    std::string getUUIDString();
    std::string getServerId();
    std::string getStorageId();
    inline unsigned char getClientSubId() {
        return mClientSubID;
    }

    inline std::string const& getRealName() {
        return mRealName;
    }
    std::unique_ptr<CompoundTag> getPlayerTag();
    std::unique_ptr<CompoundTag> getStoragePlayerTag();
    std::unique_ptr<CompoundTag> getOnlinePlayerTag();



};

//class FakePlayerStorage {
//    std::unique_ptr<KVDB> mDBStorage;
//    Logger mLogger;
//    std::mutex mLock;
//    FakePlayerManager* mManager;
//
//    std::unordered_map<std::string, std::shared_ptr<FakePlayer>> mFakePlayerMap;
//    std::unordered_map<std::string, std::shared_ptr<FakePlayer>> mFakePlayerMapByName;
//    std::vector<std::string> sortedNames;
//
//    static std::string getStorageId(mce::UUID uuid){
//        return "player_" + uuid.asString();
//    }
//    static std::string getServerId(mce::UUID uuid) {
//        return "player_server_" + uuid.asString();
//    }
//
//    FakePlayerStorage(std::string const& storagePath, FakePlayerManager* manager) :mManager(manager), mLogger("FakePlayerStorage") {
//        if (!mManager)
//            mManager = &FakePlayerManager::getManager();
//        mDBStorage = KVDB::create(storagePath);
//#ifdef PLUGIN_VERSION_IS_BETA
//        mDBStorage->iter([this](std::string_view key, std::string_view val)->bool {
//            DEBUGW("key: {}, value: ", key);
//            std::cout << CompoundTag::fromBinaryNBT((void*)val.data(), val.size())->toSNBT() << std::endl;
//            return true;
//            });
//#endif // PLUGIN_VERSION_IS_BETA
//        initPlayerMap();
//        initSortedNames();
//    }
//    bool initPlayerMap() {
//        mFakePlayerMapByName.clear();
//        mFakePlayerMap.clear();
//
//        mDBStorage->iter([this](std::string_view key, std::string_view val)->bool {
//            if (key._Starts_with("player_") && !key._Starts_with("player_server_")) {
//                auto tag = CompoundTag::fromBinaryNBT((void*)val.data(), val.size());
//                auto player = FakePlayer::deserialize(*tag.get());
//                ASSERT("player_" + player->getUUIDString() == key);
//                if (!player.get())
//                {
//                    logger.warn("Error in loading FakePlayer UUID({})", key);
//                }
//                else
//                {
//                    auto uuid = player->mUUID.asString();
//                    mFakePlayerMapByName.try_emplace(player->getRealName(), player);
//                    mFakePlayerMap.try_emplace(uuid, std::move(player));
//                }
//            }
//            return true;
//            });
//    };
//    void initSortedNames() {
//        sortedNames.clear();
//        std::vector<std::tuple<time_t, std::string_view>> tmp;
//        for (auto& [name, fakePlayer] : mFakePlayerMap) {
//            tmp.push_back({ fakePlayer->mLastOnlineTime, fakePlayer->mRealName });
//        }
//        std::sort(tmp.begin(), tmp.end(), [](std::tuple<time_t, std::string_view> const& left, std::tuple<time_t, std::string_view> const& right) {
//            return std::get<0>(left) > std::get<0>(left);
//            });
//        for (auto& [time, name] : tmp) {
//            sortedNames.emplace_back(name);
//        }
//    }
//    bool fixDatabase();
//    bool removePlayerData(FakePlayer& fakePlayer) {
//        mLock.lock();
//        auto storageId = fakePlayer.getStorageId();
//        auto serverId = fakePlayer.getServerId();
//        auto res = mDBStorage->del(storageId);
//        if (!res) {
//            logger.error("Error in removePlayerData - {}", storageId);
//            return false;
//        }
//        return mDBStorage->del(serverId);
//    };
//    bool savePlayer(FakePlayer& fakePlayer) {
//        auto res = savePlayerInfo(fakePlayer);
//        res &= savePlayerData(fakePlayer);
//        return res;
//    }
//    bool savePlayerData(FakePlayer& fakePlayer) {
//        mLock.lock();
//        auto serverId = fakePlayer.getServerId();
//        auto tag = fakePlayer.getOnlinePlayerTag();
//        if (!mDBStorage->set(serverId, tag->toBinaryNBT(true))) {
//            logger.warn("Error in savePlayerInfo - {}", serverId);
//            return false;
//        };
//        return true;
//    };
//    bool savePlayerInfo(FakePlayer& fakePlayer) {
//        mLock.lock();
//        auto storageId = fakePlayer.getStorageId();
//        auto info = fakePlayer.serialize()->toBinaryNBT(true);
//        if (!mDBStorage->set(storageId, info)) {
//            logger.warn("Error in savePlayerInfo - {}", storageId);
//            return false;
//        };
//        return true;
//    };
//    std::string getPlayerData(mce::UUID uuid) {
//        mLock.lock();
//        auto serverId = getServerId(uuid);
//        std::string data = "";
//        if (mDBStorage->get(serverId, data)) {
//            return data;
//        }
//        logger.warn("Error in getPlayerData - {}", serverId);
//        return "";
//    };
//    inline std::string getPlayerData(FakePlayer& fakePlayer) {
//        return getPlayerData(fakePlayer.getUUID());
//    }
//    std::unique_ptr<CompoundTag> getPlayerTag(mce::UUID uuid) {
//        auto data = getPlayerData(uuid);
//        if (!data.empty())
//            return CompoundTag::fromBinaryNBT((void*)data.c_str(), data.size(), true);
//        return {};
//    };
//    inline std::unique_ptr<CompoundTag> getPlayerTag(FakePlayer& fakePlayer) {
//        return getPlayerTag(fakePlayer.getUUID());
//    }
//    std::shared_ptr<FakePlayer> getPlayerInfo(mce::UUID uuid) {
//        mLock.lock();
//        auto storageId = "player_" + getStorageId(uuid);
//        std::string data = "";
//        auto res = mDBStorage->get(storageId, data);
//        if (!res) {
//            logger.warn("Error in getPlayerInfo - {}", storageId);
//            return {};
//        }
//        auto info = CompoundTag::fromBinaryNBT((void*)data.c_str(), data.size(), true);
//        return FakePlayer::deserialize(*info);
//    };
//};

class FakePlayerManager
{
public:
    std::unique_ptr<KVDB> mDatabase;

    std::unordered_map<std::string, std::shared_ptr<FakePlayer>> mFakePlayerMap;
    std::unordered_map<std::string, std::shared_ptr<FakePlayer>> mFakePlayerMapByName;
    std::vector<std::string> sortedNames;

    FakePlayerManager(std::string const& dbPath);
    ~FakePlayerManager();
    FakePlayerManager(const FakePlayerManager&) = delete;
    FakePlayerManager& operator=(const FakePlayerManager&) = delete;
    void loadData();
    void saveData();
    void saveData(mce::UUID uuid);
    void saveData(FakePlayer& fakePlayer);
    void saveData(SimulatedPlayer* simulatedPlayer);
    void initSortedNames();
    bool importData_DDF(std::string const& name);
    friend class FakePlayer;
    friend class SimulatedPlayer;
public:
    inline std::vector<std::string> const& getSortedNames() {
        return sortedNames;
    }
    static FakePlayerManager& getManager();
    inline void forEachFakePlayer(std::function<void(std::string_view name, FakePlayer const& fakePlayer)> callback) const {
        for (auto& [name, fakePlayer] : mFakePlayerMap) {
            //callback(name, *fakePlayer);
        }
    }
    inline std::vector<FakePlayer const*> getFakePlayerList() const {
        std::vector<FakePlayer const*> list(mFakePlayerMap.size());
        forEachFakePlayer([&list](std::string_view name, FakePlayer const& fakePlayer) {
            list.push_back(&fakePlayer);
            });
        std::sort(list.begin(), list.end(), [](FakePlayer const* left, FakePlayer const* right) {
            return left->mLastOnlineTime > right->mLastOnlineTime;
            });
        return list;
    }
    FakePlayer* create(std::string const& name);
    FakePlayer* create(std::string const& name, std::unique_ptr<CompoundTag> playerData);
    bool remove(std::string const& name);
    SimulatedPlayer* login(std::string const& name);
    bool logout(FakePlayer& simulatedPlayer);
    bool logout(std::string const& name);
    bool logout(SimulatedPlayer& simulatedPlayer);

    inline std::shared_ptr<FakePlayer> tryGetFakePlayer(Player* player) {
        auto uuid = mce::UUID::fromString(player->getUuid());
        return tryGetFakePlayer(uuid);
    };
    inline std::shared_ptr<FakePlayer> tryGetFakePlayer(std::string const& name) {
        auto fpIter = mFakePlayerMapByName.find(name);
        if (fpIter == mFakePlayerMapByName.end())
            return {};
        return fpIter->second;
    };
    inline std::shared_ptr<FakePlayer> tryGetFakePlayer(mce::UUID uuid) {
        auto fpIter = mFakePlayerMap.find(uuid.asString());
        if (fpIter == mFakePlayerMap.end())
            return {};
        return fpIter->second;
    };
    
};