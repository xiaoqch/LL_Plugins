#include "pch.h"
#include "mc/Item.h"
#include "rapidjson/document.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/writer.h"
#include <filesystem>
#include <mc/OffsetHelper.h>
#include "ItemHelper.h"
#include "RecipeHelper.h"
#include "ContainerHelper.h"
#include "RequestHelper.h"

using namespace std;

#define VERSION "1.1.0"
#define CONF_DIR "./plugins/AntiCutter/"
#define CONF_PATH "./plugins/AntiCutter/config.json"
//#define RECIPES_PATH "./plugins/AntiCutter/cutter_recipes.json"
#define LOG_PATH "./logs/cutter_modify_detected.log"

// config 
bool autoKick;
bool autoCmd;
string kickMssage;
vector<string> cmds;

std::ofstream logfile;

// ======== Some Operation ========
string getTimeStr()
{
    char timeStr[MAX_PATH];  //用于存储格式的时间
    struct tm t;     //tm结构指针
    time_t now;     //声明time_t类型变量
    time(&now);      //获取系统日期和时间
    localtime_s(&t, &now);   //获取当地日期和时间
    strftime(timeStr, _countof(timeStr), "%Y-%m-%d %H:%M:%S", &t);
    return timeStr;
}

void log(string msg) {
    logfile << msg << endl;
    logfile.flush();
    cout << msg << endl;
}

void detectedOperate(Player* player) {
    string playerName = offPlayer::getRealName(player);
    if (autoCmd) {
        if (cmds.size() > 0) {
            auto spacePos = playerName.find(" ");
            if (spacePos != playerName.npos) {
                playerName = "\"" + playerName + "\"";
            }
        }
        for (std::string cmd : cmds) {
            auto position = cmd.find("%player%");
            if (position != cmd.npos) {
                cmd.replace(position, 9, playerName);
            }
            liteloader::runcmd(cmd);
        }
    }
    if (autoKick) {
        WPlayer wp = WPlayer(*player);
        wp.kick(kickMssage);
    }
}

bool initConf() {
    rapidjson::Document config;
    std::ifstream fs(CONF_PATH, std::ios::in);
    if (!fs) {
        std::cout << "[AntiCutter] [" + getTimeStr() + "] Config file \"" << CONF_PATH << "\" not found, create it" << std::endl;
        std::filesystem::create_directory(CONF_DIR);
        std::ofstream of(CONF_PATH);
        if (of) {
            std::string defaultConf = "{\n    \"autoKick\":true,\n    \"kickMessage\":\"Bad kids are not welcome on this server.\",\n    \"autoCmd\":true,\n    \"cmds\":[\"ban %player%\"]\n}";
            of << defaultConf;
            config.Parse(defaultConf.c_str());
            of.close();
        }
        else {
            std::cerr << "[AntiCutter] [" + getTimeStr() + "] Can Not Create Config File." << std::endl;
            return false;
        }
    }
    else {
        std::string json;
        char buf[1024];
        while (fs.getline(buf, 1024)) {
            json.append(buf);
        }
        config.Parse(json.c_str());
        fs.close();
        if (config.HasMember("autoKick")) {
            autoKick = config["autoKick"].GetBool();
        }
        else {
            autoKick = true;
        }
        if (config.HasMember("kickMessage")) {
            kickMssage = config["kickMessage"].GetString();
        }
        else {
            kickMssage = "Bad kids are not welcome on this server.";
        }
        if (config.HasMember("autoCmd")) {
            autoCmd = config["autoCmd"].GetBool();
        }
        else {
            autoCmd = true;
        }
        if (config.HasMember("cmds")) {
            auto arraylist = config["cmds"].GetArray();
            for (rapidjson::Value::ConstValueIterator itr = arraylist.Begin(); itr != arraylist.End(); ++itr) {
                cmds.push_back(itr->GetString());
            }
        }
        else {
            cmds.push_back("ban %player%");
        }
    }
}

void entry() {
    logfile.open(LOG_PATH, std::ios::app);
    //initRecipes();
    initConf();
    cout << "[AntiCutter] Anti Cutter Item Modify Plugin Loaded. Version: " << VERSION << endl;
}

// VirtualCall
template<typename RTN = void, typename... Args>
RTN inline VirtualCall(void* _this, uintptr_t off, Args... args) {
    return (*(RTN(**)(void*, Args...))(*(uintptr_t*)_this + off))(_this, args...);
}

ItemStackNetResult vaildifyCrafting(ItemStack* inputItem, ItemInstance* outputItem) {
    auto recipe = getCutterRecipeFor(*outputItem);
    if (!recipe)
        return ItemStackNetResult::InvalidCraftResultItem;
    auto result = outputMatch(recipe, outputItem);
    if(!result)
        return ItemStackNetResult::InvalidCraftResultStackSize;
    result = ingredientMatch(recipe, inputItem);
    if (!result)
        return ItemStackNetResult::FailedToMatchExpectedAllowedAnywhereConsumedItem;
    return ItemStackNetResult::Success;
}

//ItemInstance* newItem(string const& name, int count) {
//    int64_t id;
//    unsigned int aux;
//    auto item = ItemRegistry::lookupByName(id, aux, name);
//    if (!item)
//        return nullptr;
//    ItemInstance itemIns{};
//    return SymCall("??0ItemInstance@@QEAA@AEBVItem@@HH@Z",
//        ItemInstance*, ItemInstance*, Item*, int, unsigned int)(&itemIns, item, count, aux);
//}

THook(ItemStackNetResult, "?handleCraftResults@ItemStackRequestActionCraftHandler@@QEAA?AW4ItemStackNetResult@@AEBVItemStackRequestActionCraftResults_DEPRECATEDASKTYLAING@@@Z",
    ItemStackRequestActionCraftHandler* irch, ItemStackRequestActionCraftResults* ircr) {
    ItemStackRequestActionHandler* irh = getHandlerFromCraftHandler(irch);

    auto containerType = getRequestContainerType(irh);
    if (containerType != ContainerType::STONECUTTER)
        return original(irch, ircr);

    auto ctn = getOrInitSparseContainer(irh, ContainerEnumName::stonecutterInputItems);
    ItemStack* inputItem = getItemFromSparseContainer(ctn, ContainerOffset::stonecutterInputItems);

    auto& outputItems = getResultItems(ircr);
    if (outputItems.size() != 1)
        return ItemStackNetResult::InvalidCraftResultItem;
    ItemInstance& outputItem = outputItems.at(0);
    //outputItem = *newItem("minecraft:stone_slab", 3); // test

    ItemStackNetResult result = vaildifyCrafting(inputItem, &outputItem);

    if (result == ItemStackNetResult::Success) {
        result = original(irch, ircr);
    }
    else {
        auto player = dAccess<Player*>(irch, 2 * 8);
        log("[AntiCutter] [" + getTimeStr() + "] Detected Invaild Craft By Player: " + player->getNameTag());
        log("[AntiCutter] [" + getTimeStr() + "] Detail: " + itemStackToString(*inputItem) + " -> " + itemInsToString(outputItem));
        detectedOperate(player);
    }
    return result;
}