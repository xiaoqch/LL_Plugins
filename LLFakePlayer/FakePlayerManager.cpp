#include "pch.h"
#include "FakePlayerManager.h"
#include <KVDBAPI.h>
#include <MC/StringTag.hpp>
#include <MC/ListTag.hpp>
#include <MC/LevelStorage.hpp>
#include <MC/NetworkIdentifier.hpp>
#include <MC/ServerNetworkHandler.hpp>
#include <MC/RakNet.hpp>
#include <MC/DBStorage.hpp>
#include <Utils/CryptHelper.h>

// 
mce::UUID JAVA_nameUUIDFromBytes(std::string const& name) {
    auto md5 = CalcMD5(name);
    ASSERT(md5.size() == 32);
    //md5[6] &= 0x0f;  /* clear version        */
    //md5[6] |= 0x30;  /* set to version 3     */
    //md5[8] &= 0x3f;  /* clear variant        */
    //md5[8] |= 0x80;  /* set to IETF variant  */

    md5[12] = '3';     /* set to version 3     */
    auto c = (unsigned char)md5[16];
    ASSERT(c >= '0');
    auto b = c - '0';
    if (b > 9)
        b = 10 + c - 'A';
    if (b > 15)
        b = 10 + c - 'a';
    b &= 0x3;            /* clear variant        */
    b |= 0x8;            /* set to IETF variant  */

    md5[16] = "0123456789abcdef"[b];

    md5.insert(20, 1, '-');
    md5.insert(16, 1, '-');
    md5.insert(12, 1, '-');
    md5.insert(8, 1, '-');
    return mce::UUID::fromString(md5);
}

FakePlayer* FakePlayer::mRecordPlayer = nullptr;
std::unique_ptr<CompoundTag> FakePlayer::mRecordData = {};
bool FakePlayer::mLogining = false;
NetworkIdentifier FakePlayer::mNetworkID(RakNet::UNASSIGNED_RAKNET_GUID);
unsigned char FakePlayer::mMaxClientSubID = -1;


FakePlayer::FakePlayer(std::string const& realName, mce::UUID uuid, time_t lastOnlineTime, bool autoLogin, FakePlayerManager* manager)
    : mRealName(realName), mUUID(uuid), mLastOnlineTime(lastOnlineTime), mAutoLogin(autoLogin), mManager(manager) {
    if (!mManager)
        mManager = &FakePlayerManager::getManager();
    mMaxClientSubID++;
    mClientSubID = mMaxClientSubID;
    DEBUGL("FakePlayer::FakePlayer({}, {}, {}, {}", realName, uuid.asString(), lastOnlineTime, autoLogin);
}

FakePlayer::~FakePlayer() {
    DEBUGL("FakePlayer::~FakePlayer() - {}", mRealName);
}

std::shared_ptr<FakePlayer> FakePlayer::deserialize(CompoundTag const& tag, FakePlayerManager* manager)
{
    auto nameTag = const_cast<StringTag*>(tag.getStringTag("realName"));
    if (!nameTag)
        return {};
    auto& name = nameTag->value();
    auto uuidTag = const_cast<StringTag*>(tag.getStringTag("uuid"));
    if (!nameTag)
        return {};
    auto uuid = mce::UUID::fromString(uuidTag->value());

    auto timeTag = const_cast<Int64Tag*>(tag.getInt64Tag("lastOnlineTime"));
    time_t lastOnlineTime = 0;
    if (timeTag)
        lastOnlineTime = timeTag->value();

    auto autoLoginTag = const_cast<ByteTag*>(tag.getByteTag("autoLogin"));
    auto autoLogin = false;
    if (timeTag)
        autoLogin = autoLoginTag->value();
    return std::make_shared<FakePlayer>(name, uuid, lastOnlineTime, autoLogin, manager);
}

std::unique_ptr<CompoundTag> FakePlayer::serialize()
{
    auto tag = CompoundTag::create();
    tag->putString("realName", mRealName);
    tag->putString("uuid", mUUID.asString());
    tag->putInt64("lastOnlineTime", mLastOnlineTime);
    tag->putBoolean("autoLogin", mAutoLogin);
    return std::move(tag);
}

#include <MC/StackResultStorageEntity.hpp>
#include <MC/OwnerStorageEntity.hpp>
template <>
class OwnerPtrT<struct EntityRefTraits> {
    char filler[24];
public:
    inline ~OwnerPtrT(){
        void (OwnerPtrT::*rv)() const;
        *((void**)&rv) = dlsym("??1?$OwnerPtrT@UEntityRefTraits@@@@QEAA@XZ");
        (this->*rv)();
    }
    inline OwnerPtrT(OwnerPtrT&& right) {
        void (OwnerPtrT:: * rv)(OwnerPtrT && right);
        *((void**)&rv) = dlsym("??0OwnerStorageEntity@@IEAA@$$QEAV0@@Z");
        (this->*rv)(std::move(right));
    }
    inline OwnerPtrT& operator=(OwnerPtrT&& right) {
        void (OwnerPtrT:: * rv)(OwnerPtrT && right);
        *((void**)&rv) = dlsym("??4OwnerStorageEntity@@IEAAAEAV0@$$QEAV0@@Z");
        (this->*rv)(std::move(right));
    }
    inline SimulatedPlayer* tryGetSimulatedPlayer(bool b = false) {
        auto player = Player::tryGetFromEntity(*this, b);
        if (player && player->isSimulatedPlayer()) {
            return (SimulatedPlayer*)player;
        }
    }
};

inline void addUser(Level* level, class OwnerPtrT<struct EntityRefTraits> a0) {
    void (Level:: * rv)(class OwnerPtrT<struct EntityRefTraits>);
    *((void**)&rv) = dlsym("?addUser@Level@@UEAAXV?$OwnerPtrT@UEntityRefTraits@@@@@Z");
    return (level->*rv)(std::forward<class OwnerPtrT<struct EntityRefTraits>>(a0));
}
bool FakePlayer::login()
{
    if (mLogining)
        return false;
    mLogining = true;
    mRecordData = getStoragePlayerTag();
    mRecordPlayer = this;
    //BlockPos bpos = BlockPos::MIN;
    //AutomaticID<Dimension, int> dimId;
    //bool spawnIsSet = false;
    //if (mRecordData) {
    //    std::cout << mRecordData->toSNBT() << std::endl;
    //    dimId = mRecordData->getInt("SpawnDimension");
    //    if (dimId >= 0 && dimId <= 2) {
    //        auto spawnList = mRecordData->getList("Pos");
    //        if (spawnList && spawnList->size() == 3)
    //            bpos = { spawnList->getInt(0),spawnList->getInt(1) ,spawnList->getInt(2) };
    //        else
    //            logger.error("Error to get Pos from player data");
    //        if(bpos!=BlockPos::MIN)
    //            spawnIsSet = true;
    //    }
    //}
    //if (!spawnIsSet) {
    //    bpos = BlockPos::MIN;
    //    dimId = 0;
    //}

    //if (!Global<Level>->getDimension(dimId))
    //    Global<Level>->createDimension(dimId);

    OwnerPtrT<EntityRefTraits> ownerPtr = Global<ServerNetworkHandler>->createSimulatedPlayer(mRealName);
    mPlayer = ownerPtr.tryGetSimulatedPlayer();
    if (mPlayer) {
        //dAccess<int>(player, 57) = dimId;
        mPlayer->postLoad(/* isNewPlayer */ false);
        Level& level = mPlayer->getLevel();
        addUser(&level, std::move(ownerPtr));
        //auto pos = bpos.bottomCenter();
        //pos.y = pos.y + 1.62001;
        //player->setPos(pos);
        //player->setRespawnReady(pos);
        mPlayer->setLocalPlayerAsInitialized();
    }
    //mPlayer = SimulatedPlayer::create(mRealName, bpos, dimId, *Global<ServerNetworkHandler>);
    mOnline = true;
    mUniqueID = mPlayer->getUniqueID();
    mClientSubID = mPlayer->getClientSubId();
    time(&mLastOnlineTime);
    mLogining = false;
    FakePlayerManager::getManager().saveData(*this);
    DEBUGW("FakePlayer: {}", mPlayer->getNameTag());
    DEBUGW("Dimension: {}, Position: ({})", (int)mPlayer->getDimensionId(), ((Vec3&)mPlayer->getStateVectorComponent()).toString());
    auto tag = mPlayer->getNbt();
    for (auto& [k, v] : *tag) {
        auto tag = const_cast<CompoundTagVariant&>(v).asTag();
        std::string value;
        switch (tag->getTagType())
        {
        case Tag::Byte:
            value = std::to_string((int)tag->asByteTag()->value());
            break;
        case Tag::End:
        case Tag::Short:
        case Tag::Int:
        case Tag::Int64:
        case Tag::Float:
        case Tag::Double:
        case Tag::ByteArray:
        case Tag::String:
        case Tag::Compound:
        case Tag::IntArray:
            value = tag->toString();
            break;
        case Tag::List: {
            value = "[";
            auto listTag = tag->asListTag();
            for (auto& tagi : *listTag) {
                value += tagi->toString() + ", ";
            }
            value += "]";
            break;
        }
        default:
            break;
        }
        DEBUGL("{}: {}", k, value);
    }
};

bool FakePlayer::logout(bool save)
{
    if (!mOnline || !mPlayer)
        return false;
    if (save) {
        time(&mLastOnlineTime);
        FakePlayerManager::getManager().saveData(*this);
    }
    mPlayer->simulateDisconnect();
    mOnline = false;
    mPlayer = nullptr;
    mClientSubID = -1;
    return true;
}

mce::UUID FakePlayer::getUUID()
{
    return mUUID;
}

std::string FakePlayer::getUUIDString()
{
    return mUUID.asString();
}

std::string FakePlayer::getServerId()
{
    return "player_server_" + mUUID.asString();
}

std::string FakePlayer::getStorageId()
{
    return "player_" + mUUID.asString();
}

std::unique_ptr<CompoundTag> FakePlayer::getPlayerTag()
{
    if (!mOnline || !mPlayer) {
        getStoragePlayerTag();
    }
    return CompoundTag::fromPlayer(mPlayer);
}

std::unique_ptr<CompoundTag> FakePlayer::getStoragePlayerTag()
{
    std::string data;
    auto serverId = getServerId();
    if (mManager->mDatabase->get(serverId, data)) {
        return CompoundTag::fromBinaryNBT((void*)data.c_str(), data.size());
    }
    else {
        return {};
    }
}

std::unique_ptr<CompoundTag> FakePlayer::getOnlinePlayerTag()
{
    return CompoundTag::fromPlayer(mPlayer);
}

FakePlayerManager::FakePlayerManager(std::string const& dbPath) {
    DEBUGL("FakePlayerManager::FakePlayerManager({})", dbPath);
    dAccess<short>(&FakePlayer::mNetworkID, 152) = 4;

    mDatabase = KVDB::create(dbPath);

#ifdef PLUGIN_VERSION_IS_BETA
    mDatabase->iter([this](std::string_view key, std::string_view val)->bool {
        DEBUGW(key);
        std::cout << CompoundTag::fromBinaryNBT((void*)val.data(), val.size())->toSNBT() << std::endl;
        return true;
        });
#endif // PLUGIN_VERSION_IS_BETA

    loadData();
    initSortedNames();
}
FakePlayerManager::~FakePlayerManager() {
    DEBUGL("FakePlayerManager::FakePlayerManager()");
}
void FakePlayerManager::saveData() {
    for (auto& [uuid, player] : mFakePlayerMap) {
        mDatabase->set(player->getStorageId(), player->serialize()->toBinaryNBT());
    }
}

void FakePlayerManager::saveData(mce::UUID uuid) {
    auto uuidStr = uuid.asString();
    auto playerIter = mFakePlayerMap.find(uuidStr);
    if(playerIter != mFakePlayerMap.end())
        mDatabase->set(playerIter->second->getStorageId(), playerIter->second->serialize()->toBinaryNBT());
}
void FakePlayerManager::saveData(FakePlayer& fakePlayer)
{
    mDatabase->set(fakePlayer.getStorageId(), fakePlayer.serialize()->toBinaryNBT());
    if (fakePlayer.mOnline && fakePlayer.mPlayer) {
        auto tag = fakePlayer.getOnlinePlayerTag();
        if (tag.get())
            mDatabase->set(fakePlayer.getServerId(), tag->toBinaryNBT());
    }
}
void FakePlayerManager::saveData(SimulatedPlayer* simulatedPlayer) {
    auto uuidStr = simulatedPlayer->getUuid();
    auto playerIter = mFakePlayerMap.find(uuidStr);
    if (playerIter != mFakePlayerMap.end())
        mDatabase->set(uuidStr, playerIter->second->serialize()->toBinaryNBT());
}


void FakePlayerManager::initSortedNames()
{
    sortedNames.clear();
    std::vector<std::tuple<time_t, std::string_view>> tmp;
    for (auto& [name, fakePlayer] : mFakePlayerMap) {
        tmp.push_back({ fakePlayer->mLastOnlineTime, fakePlayer->mRealName });
    }
    std::sort(tmp.begin(), tmp.end(), [](std::tuple<time_t, std::string_view> const& left, std::tuple<time_t, std::string_view> const& right) {
        return std::get<0>(left) > std::get<0>(left);
        });
    for (auto& [time, name] : tmp) {
        sortedNames.push_back(std::string(name));
    }
}

bool FakePlayerManager::importData_DDF(std::string const& name)
{
    auto uuid = JAVA_nameUUIDFromBytes(name);
    auto uuidStr = uuid.asString();
    auto dbStorage = (DBStorage*)&Global<Level>->getLevelStorage();
    auto tag = dbStorage->getCompoundTag("player_" + uuid.asString(), (DBHelpers::Category)7);
    if (!tag) {
        logger.error("Error in getting PlayerStorageIds");
        return false;
    }
    auto& serverId = tag->getString("ServerId");
    if (serverId.empty()) {
        logger.error("Error in getting player's ServerId");
        return false;
    }
    auto playerData = dbStorage->getCompoundTag(serverId, (DBHelpers::Category)7);
    auto fp = create(name, std::move(playerData));
    if (fp)
        return true;
    logger.error("Error in reading player's data");
    return false;
}

void FakePlayerManager::loadData() {
    mDatabase->iter([this](std::string_view key, std::string_view val)->bool {
        if (key._Starts_with("player_") && !key._Starts_with("player_server_")) {
            auto tag = CompoundTag::fromBinaryNBT((void*)val.data(), val.size());
            auto player = FakePlayer::deserialize(*tag.get(), this);
            ASSERT("player_" + player->getUUIDString() == key);
            if (!player.get())
            {
                logger.warn("Error in loading FakePlayer UUID({})", key);
            }
            else
            {
                auto uuid = player->mUUID.asString();
                mFakePlayerMapByName.try_emplace(player->getRealName(), player);
                mFakePlayerMap.try_emplace(uuid, std::move(player));
            }
        }
        return true;
        });
}
FakePlayerManager& FakePlayerManager::getManager()
{
    static FakePlayerManager manager(PLUGIN_DATA_PATH);
    return manager;
}


FakePlayer* FakePlayerManager::create(std::string const& name)
{
    if (std::find(sortedNames.begin(), sortedNames.end(), name) != sortedNames.end())
        return nullptr;
    auto uuid = mce::UUID::seedFromString(name);
    auto uuidStr = uuid.asString();
    auto player = std::make_shared<FakePlayer>(name, uuid, time(0), false);
    mFakePlayerMapByName.try_emplace(name, player);
    mFakePlayerMap.try_emplace(uuidStr, player);
    sortedNames.push_back(name);
    player->login();
    auto ptr = player.get();
    return ptr;
}

FakePlayer* FakePlayerManager::create(std::string const& name, std::unique_ptr<CompoundTag> playerData)
{
    if (std::find(sortedNames.begin(), sortedNames.end(), name) != sortedNames.end())
        return nullptr;
    auto uuid = mce::UUID::seedFromString(name);
    auto player = std::make_shared<FakePlayer>(name, uuid, time(0), false);
    mFakePlayerMapByName.try_emplace(name, player);
    mFakePlayerMap.try_emplace(uuid.asString(), player);
    sortedNames.push_back(name);
    saveData(*player);
    mDatabase->set(player->getServerId(), playerData->toBinaryNBT());
    auto ptr = player.get();
    return ptr;
}

bool FakePlayerManager::remove(std::string const& name)
{
    auto fakePlayer = tryGetFakePlayer(name);
    if (fakePlayer) {
        auto uuidStr = fakePlayer->getUUIDString();
        auto serverId = fakePlayer->getServerId();
        mFakePlayerMap.erase(uuidStr);
        mFakePlayerMapByName.erase(name);
        sortedNames.erase(std::find(sortedNames.begin(), sortedNames.end(), name));
        mDatabase->del(uuidStr);
        mDatabase->del(serverId);
        return true;
    }
    return false;
}

SimulatedPlayer* FakePlayerManager::login(std::string const& name)
{
    auto fakePlayer = tryGetFakePlayer(name);
    if (fakePlayer && fakePlayer->login())
        return fakePlayer->mPlayer;
    return nullptr;
}

bool FakePlayerManager::logout(FakePlayer& fakePlayer)
{
    return fakePlayer.logout(true);
}

bool FakePlayerManager::logout(std::string const& name)
{
    auto fakePlayer = tryGetFakePlayer(name);
    if (fakePlayer)
        return fakePlayer->logout(true);
    return false;
}

bool FakePlayerManager::logout(SimulatedPlayer& simulatedPlayer)
{
    auto fakePlayer = tryGetFakePlayer(&simulatedPlayer);
    if (fakePlayer)
        return fakePlayer->logout(true);
    return false;
}

//TInstanceHook(BlockPos&, "?getDefaultSpawn@Level@@UEBAAEBVBlockPos@@XZ",
//    Level, BlockPos& rtn) {
//
//}

#include <MC/Certificate.hpp>
TInstanceHook(SimulatedPlayer*, "??0SimulatedPlayer@@QEAA@AEAVLevel@@AEAVPacketSender@@AEAVNetworkHandler@@AEAVActiveTransfersManager@Server@ClientBlobCache@@W4GameType@@AEBVNetworkIdentifier@@EV?$function@$$A6AXAEAVServerPlayer@@@Z@std@@VUUID@mce@@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$unique_ptr@VCertificate@@U?$default_delete@VCertificate@@@std@@@std@@H_NAEBV?$OwnerPtrT@UEntityRefTraits@@@@@Z",
    SimulatedPlayer,
    class Level& level,
    class PacketSender& sender,
    class NetworkHandler& handler,
    class ActiveTransfersManager& blobCache,
    enum GameType gameType,
    class NetworkIdentifier const& nid,
    unsigned char subId,
    class std::function<void(class ServerPlayer&)> onPlayerLoadedCallback,
    class mce::UUID uuid,
    std::string const& clientId,
    class std::unique_ptr<Certificate> cert,
    int unk_int,
    bool unk_bool,
    class OwnerPtrT<struct EntityRefTraits> const& refPtr
) {
    // fix Player subClinetId, for identify packet
    if (FakePlayer::mLogining) {
        auto fp = FakePlayer::mRecordPlayer;
        uuid = fp->getUUID();
        subId = fp->getClientSubId();
    }
    else {
        logger.warn("Unknown SimulatedPlayer creation detected, it is recommended to create an SimulatedPlayer through FakePlayerManager");
    }

    DEBUGW("SimulatedPlayer(level, sender, handler, blobCache, gameType = {}, nid, subId = {}, func, uuid = {}, clientId = {}, cert, unk_int = {}, unk_bool = {}, refPtr)",
        (int)gameType, (int)subId, uuid.asString(), clientId, unk_int, unk_bool);
    // fix client sub id for identify packet

    auto rtn = original(this, level, sender, handler, blobCache, gameType, nid, subId, onPlayerLoadedCallback, uuid, clientId, std::move(cert), unk_int, unk_bool, refPtr);
    // fix runtime id
    auto ueif = rtn->getUserEntityIdentifierComponent();
    ASSERT(dAccess<unsigned char>(ueif, 160) == subId);

    DEBUGW("Simulated Player: {}, client sub id: {}, runtime id: {}", rtn->getNameTag(), rtn->getClientSubId(), rtn->getRuntimeID().id);
    return rtn;
}

// 
THook(std::unique_ptr<CompoundTag>&, "?loadServerPlayerData@LevelStorage@@QEAA?AV?$unique_ptr@VCompoundTag@@U?$default_delete@VCompoundTag@@@std@@@std@@AEBVPlayer@@_N@Z",
    class LevelStorage* _this, std::unique_ptr<CompoundTag>& res, Player& player, bool unkBool) {
    DEBUGW("LevelStorage::loadServerPlayerData({}, {})", player.getNameTag(), unkBool);
    auto& rtn = original(_this, res, player, unkBool);
    if (player.isSimulatedPlayer()) {
        ASSERT(!rtn);
        if (FakePlayer::mLogining && FakePlayer::mRecordData) {
            DEBUGW("Replace SimulatedPlayer data");
            auto& fp = FakePlayer::mRecordPlayer;
            ASSERT(player.getUuid() == fp->getUUID().asString());
            rtn.swap(FakePlayer::mRecordData);
        }
        //auto fakePlayer = FakePlayerManager::getManager().tryGetFakePlayer(&player);
        //if (!fakePlayer)
        //    return rtn;
        //auto playerTag = fakePlayer->getPlayerTag();
        //if (playerTag)
        //    rtn.swap(playerTag);
    }
    return rtn;
}
