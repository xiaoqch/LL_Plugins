#include "pch.h"
#include <mc/OffsetHelper.h>
#include "EnumGen.h"
#include "SymHelper.h"

using namespace std;


#define LOG_VAR(var) std::cout << #var" :\t" << var << std::endl;

struct voids {
    void***** v[1000];
};

//链接：https://www.nowcoder.com/questionTerminal/5a776e2954f545e0bcc01e6b04ef5f1d
//来源：牛客网

/**
* 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
*
*
* @param newString string字符串
* @return string字符串
*/
string camelCase(string newString) {
    // write code here
    string res;
    int cnt = 0;
    if (newString == "") return "shopee";
    for (char ch : newString) {
        if (!isalpha(ch) && !isdigit(ch)) cnt++;
    }
    if (cnt == newString.size()) return "shopee";
    char ch = newString[0];
    int index = 0;
    if (!isalpha(ch) && !isdigit(ch)) {
        while (!isalpha(newString[index]) && !isdigit(newString[index])) index++;
        res += tolower(newString[index]);
        index++;
    }
    else if (isalpha(ch)) res += tolower(ch), index++;
    else res += ch, index++;
    for (int i = index; i < newString.size(); i++) {
        char ch = newString[i];
        if (!isalpha(ch) && !isdigit(ch)) {
            if (i == newString.size() - 1) continue;
            while (!isalpha(newString[i]) && !isdigit(newString[i])) i++;
            res += toupper(newString[i]);
        }
        else if (isalpha(ch)) res += tolower(ch);
        else res += ch;
    }
    return res;
};

short getBlockItemId(BlockLegacy* bll) {
    return SymCall("?getBlockItemId@BlockLegacy@@QEBAFXZ", short, BlockLegacy*)(bll);
}

BlockLegacy* getFromWeakPtr(void* weakptr) {
    return SymCall("?get@?$WeakPtr@VBlockLegacy@@@@QEBAPEAVBlockLegacy@@XZ", BlockLegacy*, void*)(weakptr);
}
Block* getBlockFromLegacy(BlockLegacy* bl) {
    return SymCall("?getRenderBlock@BlockLegacy@@UEBAAEBVBlock@@XZ", Block*, BlockLegacy*)(bl);
}

void genBlockType() {
    uintptr_t weakPtrBlockLegacyStart = (uintptr_t)dlsym("?mAir@BedrockBlockTypes@@3V?$WeakPtr@VBlockLegacy@@@@A");
    uintptr_t weakPtrBlockLegacyEnd = (uintptr_t)dlsym("?mSculkShrieker@VanillaBlockTypes@@3V?$WeakPtr@VBlockLegacy@@@@A");
    size_t size = sizeof(weakPtrBlockLegacyStart);
    std::cout << "enum BlockType : short{" << std::endl;
    for (uintptr_t ptr = weakPtrBlockLegacyStart; ptr <= weakPtrBlockLegacyEnd; ptr += size) {
        auto blockLegacy = getFromWeakPtr((void*)ptr);
        if (!blockLegacy) {
            //cout << (ptr - weakPtrBlockLegacyStart) / 8 << endl;
            continue;
        }
        auto blockName = offBlockLegacy::getFullName(blockLegacy);
        auto blockItemId = getBlockItemId(blockLegacy);
        auto block = getBlockFromLegacy(blockLegacy);
        auto offset = (ptr - weakPtrBlockLegacyStart) / 8;
        auto enumName = camelCase("m_" + blockName.substr(blockName.find(':') + 1));
        //LOG_VAR(blockName)
        //LOG_VAR(blockItemId)
        //LOG_VAR(offset)
        std::cout << "    " << enumName << " = " << blockItemId << ", // " << blockName << std::endl;
    }
    std::cout << "};" << std::endl;
}

void genItemStackRequestActionType() {
    string typeName;
    cout << "enum ItemStackRequestActionType : char {" << endl;
    for (int t = 0; t < MAXBYTE; t++) {
        typeName = SymCall("?getActionTypeName@ItemStackRequestAction@@SA?BV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@W4ItemStackRequestActionType@@@Z",
            string&, string&, byte)(typeName, (byte)t);
        if (typeName != "Unknown Action")
            cout << "    " << typeName << " = " << t << "," << endl;
    }
    cout << "};" << endl;
}

void genComplexInventoryTransactionType() {
    string typeName;
    cout << "enum ComplexInventoryTransactionType : unsigned int {" << endl;
    for (unsigned int t = 0; t < MAXBYTE; t++) {
        SymCall("?getTransactionTypeName@ComplexInventoryTransaction@@SA?BV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@W4Type@1@@Z",
            string&, string&, unsigned int)(typeName, t);
        if (typeName != "Unknown Type")
            cout << "    " << typeName << " = " << t << "," << endl;
    }
    cout << "};" << endl;
}

void genContainerType() {
    string typeName;
    cout << "enum ContainerType : char {" << endl;
    for (char t = MINCHAR; t < MAXCHAR; t++) {
        typeName = SymCall("?getContainerTypeName@Container@@SAAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@W4ContainerType@@@Z",
            string&, uint8_t)(t);
        char newType = SymCall("?getContainerTypeId@Container@@SA?AW4ContainerType@@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z",
            char, string&)(typeName);
        if (t == newType)
            cout << "    " << typeName << " = " << (int)t << "," << endl;
    }
    cout << "};" << endl;
}

void genActorType() {
    string typeName;
    cout << "enum ActorType : unsigned short {" << endl;
    for (int t = 0; t < MAXUINT16; t++) {
        string entityType;
        string nameSpace;
        SymCall("?EntityTypeToStringAndNamespace@@YAXW4ActorType@@AEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@1@Z",
            void, unsigned short, string&, string&)(t, entityType, nameSpace);
        if (entityType != "unknown")
            cout << "    " << entityType << " = " << t << ", // " << nameSpace << ":" << entityType << endl;
    }
    cout << "};" << endl;
}

void genItemStackNetResult() {
    string typeName;
    cout << "enum ItemStackNetResult : char {" << endl;
    for (int t = 0; t < MAXBYTE; t++) {
        typeName = SymCall("?getItemStackNetResultName@ItemStackNetResultMap@@SAAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@W4ItemStackNetResult@@@Z",
            string&, unsigned char)(t);
        if (t < 10 || typeName != "Error")
            cout << "    " << typeName << " = " << t << "," << endl;
    }
    cout << "};" << endl;
}

void genContainerCollectionNameMap() {
    cout << "enum ContainerCollectionNameMap : char {" << endl;
    auto containerNameMap = (unordered_map<char, string>*)dlsym("?ContainerCollectionNameMap@@3V?$unordered_map@W4ContainerEnumName@@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UContainerEnumNameHasher@@U?$equal_to@W4ContainerEnumName@@@3@V?$allocator@U?$pair@$$CBW4ContainerEnumName@@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@3@@std@@A");

    for (auto& ctn : *containerNameMap)
        cout << "    " << ctn.second << " = " << (int)ctn.first << "," << endl;
    cout << "};" << endl;
}

void genLegacyIDToNameMap() {
    cout << "enum LegacyIDToNameMap : char {" << endl;
    auto containerNameMap = (unordered_map<short, HashedString>*)dlsym(
        "?mLegacyIDToNameMap@ItemRegistry@@0V?$unordered_map@FVHashedString@@U?$hash@F@std@@U?$equal_to@F@3@V?$allocator@U?$pair@$$CBFVHashedString@@@std@@@3@@std@@A"
    );

    for (auto& ctn : *containerNameMap)
        cout << "    " << ctn.second.getString() << " = " << (int)ctn.first << "," << endl;
    cout << "};" << endl;
}

void genParticleType() {
    string typeName;
    cout << "enum ParticleType : unsigned int {" << endl;
    for (unsigned int t = 0; t < MAXUINT16; t++) {
        typeName = SymCall("?getParticleName@ParticleTypeMap@@SAAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@W4ParticleType@@@Z",
            string&, unsigned int)(t);
        char newType = SymCall("?getParticleTypeId@ParticleTypeMap@@SA?AW4ParticleType@@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z",
            char, string&)(typeName);
        if (t == newType)
            cout << "    " << typeName << " = " << (int)t << "," << endl;
    }
    cout << "};" << endl;
}

void genBlockActorType() {
    cout << "enum BlockActorType : char {" << endl;
    auto nameIdMap = (map<int, string>*)dlsym(
        "?mClassIdMap@BlockActor@@0V?$map@W4BlockActorType@@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@W4BlockActorType@@@3@V?$allocator@U?$pair@$$CBW4BlockActorType@@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@3@@std@@B"
    );
    auto idNameMap = (map<string, int>*)dlsym(
        "?mIdClassMap@BlockActor@@0V?$map@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@W4BlockActorType@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@W4BlockActorType@@@std@@@2@@std@@B"
    );

    for (auto& mapIter : *nameIdMap) {
        if (idNameMap->at(mapIter.second) != mapIter.first)
            cout << "Error: " << endl;
        cout << "    " << mapIter.second << " = " << (int)mapIter.first << "," << endl;
    }
    cout << "};" << endl;
}


//void genJigsawStructureMap() {
//    cout << "enum JigsawStructureMap : char {" << endl;
//    auto man= SymCall("?getJigsawStructureRegistry@Level@@UEBAAEBVJigsawStructureRegistry@@XZ",
//        void*, Level*)(getLevel());
//    auto ele = SymCall("?getJigsawStructureElementRegistry@JigsawStructureRegistry@@QEAAAEAVJigsawStructureElementRegistry@@XZ",
//        void*, void*)(man);
//    auto nameIdMap = dAccess< map<string, int>*>(ele, 24);
//
//    for (auto& mapIter : *nameIdMap)
//        cout << "    " << mapIter.first << " = " << (int)mapIter.second << "," << endl;
//    cout << "};" << endl;
//}


void genEnchantType() {
    cout << "enum EnchantType : char {" << endl;
    //auto mEnchantmentNames = (vector<string>*)dlsym(
    //    "?mEnchantmentNames@EnchantUtils@@0V?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@A"
    //);
    //for (auto& name : *mEnchantmentNames) {
    //    auto hname = HashedString(name.c_str());
    //    char id = SymCall("?getEnchantmentId@EnchantUtils@@SA?AW4Type@Enchant@@AEBVHashedString@@@Z",
    //        char, HashedString&)(hname);
    //    cout << "    " << name << " = " << (int)id << "," << endl;
    //}
    class Enchant {
        void**** filler[112 / 8 + 1];
    };
    auto mEnchantments = (vector<unique_ptr<Enchant>>*)dlsym(
        "?mEnchants@Enchant@@2V?$vector@V?$unique_ptr@VEnchant@@U?$default_delete@VEnchant@@@std@@@std@@V?$allocator@V?$unique_ptr@VEnchant@@U?$default_delete@VEnchant@@@std@@@std@@@2@@std@@A"
    );
    for (auto& enptr : *mEnchantments) {
        Enchant* en = enptr.get();
        auto a = (voids*)en;
        char id = dAccess<char>(en, 8);
        int freq = dAccess<int>(en, 12);
        char a8 = dAccess<char>(en, 16); //cost?
        int a6 = dAccess<int>(en, 20);
        int a7 = dAccess<int>(en, 24);
        short maxLevel = dAccess<short>(en, 28);
        if (maxLevel > 0)
            *(short*)(((uintptr_t)en) + 28) = 10;
        string nameKey = dAccess<string>(en, 32);
        string name = dAccess<string>(en, 72);
        //SymCall("?getDescriptionId@Enchant@@QEBA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ",
        //    string&, Enchant*, string&)(en, name);
        //auto hstr = HashedString(name.c_str());
        //char id =SymCall("?getEnchantmentId@EnchantUtils@@SA?AW4Type@Enchant@@AEBVHashedString@@@Z",
        //    char, HashedString&)(hstr);
        cout << "    " << name << " = " << (int)id << ", // max level: " << maxLevel << ", frequency: " << freq
            << ", name key : " << nameKey << endl;
    }
    cout << "};" << endl;
}


void genEffectType() {
    void* eff;
    HashedString hstr = HashedString("");
    SymCall("?getDisplayName@MobEffectInstance@@QEBA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ",
        HashedString&, void*, HashedString&)(eff, hstr);
    cout << hstr.getString() << endl;

    cout << "enum EffectType : short {" << endl;
    for (short t = MININT16; t < MAXINT16; t++) {
        auto effect = SymCall("?getById@MobEffect@@SAPEAV1@H@Z",
            class Effect*, short)(t);
        if (!effect)
            continue;
        auto& unk8 = dAccess<short>(effect, 8); //id
        auto& unk12 = dAccess<char>(effect, 12);
        auto& effectName = dAccess<string>(effect, 32); // effect type name?
        auto& unk68 = dAccess<float>(effect, 68);
        auto& name = dAccess<string>(effect, 80); // effect name
        auto& unk112 = dAccess<string>(effect, 112);
        auto& unk144 = dAccess<char>(effect, 144);
        auto& fullName = dAccess<HashedString>(effect, 152); //full name
        cout << "    " << name << " = " << (int)t << ", // effect: " << effectName << endl;
    }
    cout << "};" << endl;
}

void genDamageCause() {
    cout << "enum ActorDagageCause : unsigned int {" << endl;
    for (unsigned int t = 0; t < MAXUINT16; t++) {
        auto& typeName = SymCall("?lookupCauseName@ActorDamageSource@@SAAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@W4ActorDamageCause@@@Z",
            string&, unsigned int)(t);
        char newType = SymCall("?lookupCause@ActorDamageSource@@SA?AW4ActorDamageCause@@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z",
            char, string&)(typeName);
        if (t == newType)
            cout << "    " << typeName << " = " << (int)t << "," << endl;
    }
    cout << "};" << endl;
}

void genEnum()
{
    //genBlockType();
    //genItemStackRequestActionType();
    //genComplexInventoryTransactionType();
    //genContainerType();
    //genActorType();
    //genItemStackNetResult();
    //genContainerCollectionNameMap();
    //genLegacyIDToNameMap();
    //genParticleType();
    //genBlockActorType();
    //genJigsawStructureMap(); //x
    //genEnchantType();
    //genEffectType();
    //genDamageCause();
}
