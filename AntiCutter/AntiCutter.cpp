#include "pch.h"
#include "mc/Item.h"
#include "rapidjson/document.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/writer.h"
#include <filesystem>
#include <mc/OffsetHelper.h>

using namespace std;

#define CONF_DIR "./plugins/AntiCutter/"
#define CONF_PATH "./plugins/AntiCutter/config.json"
#define RECIPES_PATH "./plugins/AntiCutter/cutter_recipes.json"
#define LOG_PATH "./logs/cutter_modify_detected.log"

rapidjson::Document cutterRecipes, config;

// config var
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

// ======== Init ========
void initRecipes() {
    std::ifstream fs;
    fs.open(RECIPES_PATH, std::ios::in);
    if (!fs) {
        cerr << "[AntiCutter] File \"" RECIPES_PATH "\" Not Found! Please Install This Plugins Correctly." << endl;;
        throw("[AntiCutter] File \"" RECIPES_PATH "\" Not Found! Please Install This Plugins Correctly.");
    }
    std::string json;
    char buf[1024];
    while (fs.getline(buf, 1024)) {
        json.append(buf);
    }
    cutterRecipes.Parse(json.c_str());
    fs.close();
}

bool initConf() {
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
    initRecipes();
    initConf();
    cout << "[AntiCutter] AntiCutter Loaded. Version: v1.0" << endl;
}

// ======== Main ========
typedef int ItemStackNetResult; // It seems that 0 represents false
typedef int EnumContainerType;
class ItemStackRequestActionHandler;
class ItemStackRequestActionCraftHandler;
class ItemStackRequestActionCraftResults;
class SparseContainer;
class ContainerScreenContext;

// There are a special virtual container (named as UI) in bds,that include all slot type.
// You can use the offset as index get the item from UI Container.
enum class UiContainerOffset :int {
    OUTPUT = 50, // Output slot of all crafting.
    CURSOR = 0,
    ANVI_1 = 1, // Anvi input slot 1
    ANVI_2 = 2,
    CUTTER = 3, // Stone cutter input slot
    SMITHING_1 = 51, // Weapon or armor alot in smithing table
    SMITHING_2 = 52,
    BEACON = 27,
    ENCHANTING_1 = 14,
    ENCHANTING_2 = 15,
    // others
};


// Call
template<typename RTN = void, typename... Args>
RTN inline VirtualCall(void* _this, uintptr_t off, Args... args) {
    return (*(RTN(**)(void*, Args...))(*(uintptr_t*)_this + off))(_this, args...);
}

// ======== Helpful Function For Handler ========
ItemStackRequestActionHandler* getHandlerFromCraftHandler(ItemStackRequestActionCraftHandler* irch) {
    return dAccess<ItemStackRequestActionHandler*>(irch, 8);
}

SparseContainer* getOrInitSparseContainer(ItemStackRequestActionHandler* irh, EnumContainerType type = 52) {
    // Many types will get the same result except for some special types,
    // but 52 seems to mean that the container includes the output slots.
    return SymCall("?_getOrInitSparseContainer@ItemStackRequestActionHandler@@QEAAPEAVSparseContainer@@W4ContainerEnumName@@@Z",
        SparseContainer*, ItemStackRequestActionHandler*, int)(irh, type);
}

SparseContainer* getOrInitSparseContainer(ItemStackRequestActionCraftHandler* irch, EnumContainerType type = 52) {
    // type=52 means the container include all UI Container slot
    ItemStackRequestActionHandler* irh = getHandlerFromCraftHandler(irch);
    return getOrInitSparseContainer(irh, type);
}

// This usually works under many conditions, with the exception of crafting in stone cutter.
ItemStack* getResultItem(ItemStackRequestActionHandler* irh) {
    return dAccess<ItemStack*>(irh, 5 * 8);
}

ItemStack* getResultItem(ItemStackRequestActionCraftHandler* irch) {
    if (!irch)
        return nullptr;
    ItemStackRequestActionHandler* irh = getHandlerFromCraftHandler(irch);
    return dAccess<ItemStack*>(irh, 5 * 8);
}

ItemStack* getResultItem(ItemStackRequestActionCraftResults* ircr) {
    if (!ircr)
        return nullptr;
    return dAccess<ItemStack*>(ircr, 9 * 8);
}

// ======== For SparseContainer ========
ItemStack* getItemFromSparseContainer(SparseContainer* ctn, int offset) {
    if (!ctn)
        return nullptr;
    int size = VirtualCall<int>(ctn, 0x70);
    if (offset >= size) {
        cerr << "Error in \"getItemFromSparseContainer\": Container size is " << size << " but want to get item in slot: " << offset << endl;
        return nullptr;
    }
    ItemStack* item = VirtualCall<ItemStack*>(ctn, 40, offset);
    return item;
}

ContainerScreenContext* getScreenContext(ItemStackRequestActionHandler* handler) {
    if (!handler)
        return nullptr;
    return SymCall("?getScreenContext@ItemStackRequestActionHandler@@QEBAAEBVContainerScreenContext@@XZ",
        ContainerScreenContext*, ItemStackRequestActionHandler*)(handler);
}

byte getScreenContainerType(ContainerScreenContext* context) {
    if (!context)
        return (byte)0;
    // ContainerScreenContext::getScreenContainerType
    return dAccess<byte>(context, 8);
}

byte getRequestScreenType(ItemStackRequestActionHandler* handler) {
    if (!handler)
        return (byte)0;
    auto screen = getScreenContext(handler);
    auto screenType = getScreenContainerType(screen);
    return screenType;
}

// ======== For Item ========
string getItemType(ItemStack* item) {
    if (item->isNull())
        return "";
    string itemType;
    SymCall("?getSerializedName@Item@@QEBA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ",
        void, Item const*, string*)(item->getItem(), &itemType);
    return itemType;
}

int getItemCount(ItemStack* item) {
    return (int)dAccess<byte>(item, 34);
}

string getItemString(ItemStack* item, bool includeCount) {
    string count = "";
    if (includeCount) {
        count = ":" + to_string(getItemCount(item));
    }
    return item->getName() + "<" + getItemType(item) + ":" + to_string(item->getAuxValue()) + ">" + count;
}

// ======== For SparseContainer ========
bool vaildifyCrafting(ItemStack* inputItem, ItemStack* outputItem) {
    string inputType = getItemType(inputItem) + ":" + to_string(inputItem->getAuxValue());
    int inputCount = getItemCount(inputItem);
    auto recipe = cutterRecipes.FindMember(inputType.c_str());
    if (recipe == cutterRecipes.MemberEnd()) {
        cout << "[AntiCutter] [" + getTimeStr() + "] Detected Invaild Input Item" << endl;
        return false;
    }

    rapidjson::Value& outputs = recipe->value;
    string outputType = getItemType(outputItem) + ":" + to_string(outputItem->getAuxValue());
    auto output = outputs.FindMember(outputType.c_str());
    int outputCount = getItemCount(outputItem);
    if (output == outputs.MemberEnd() || output->value != outputCount) {
        cout << "[AntiCutter] [" + getTimeStr() + "] Detected Invaild Output Item" << endl;
        return false;
    }
    return true;
}

THook(ItemStackNetResult, "?handleCraftResults@ItemStackRequestActionCraftHandler@@QEAA?AW4ItemStackNetResult@@AEBVItemStackRequestActionCraftResults_DEPRECATEDASKTYLAING@@@Z",
    ItemStackRequestActionCraftHandler* irch, ItemStackRequestActionCraftResults* ircr) {
    ItemStackRequestActionHandler* irh = getHandlerFromCraftHandler(irch);
    auto screenType = (int)getRequestScreenType(irh);
    if (screenType != 29) { // 29 means stone cutter ui
        return original(irch, ircr);
    }
    auto ctn = getOrInitSparseContainer(irh);
    ItemStack* inputItem = getItemFromSparseContainer(ctn, (int)UiContainerOffset::CUTTER);
    ItemStack* outputItem = getResultItem(ircr);
    auto player = dAccess<Player*>(irch, 2 * 8);
    bool vaild = vaildifyCrafting(inputItem, outputItem);
    if (vaild) {
        return original(irch, ircr);
    }
    else {
        log("[AntiCutter] [" + getTimeStr() + "] Detected Invaild Craft By Player: " + player->getNameTag());
        log("[AntiCutter] [" + getTimeStr() + "] Detail: " + getItemString(inputItem, false) + " -> " + getItemString(outputItem, true));
        detectedOperate(player);
        return 1;
    }
}