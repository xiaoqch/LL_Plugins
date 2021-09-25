#include "pch.h"
#include "NBT.h"
#include <vector>
#include <map>
#include <sstream>
#include "nbt-cpp/include/nbt.hpp"

using namespace std;

// 不要忘记实现这个
Level* getLevel();

template<typename RTN = void, typename... Args>
RTN inline VirtualCall(void* _this, uintptr_t off, Args... args) {
    return (*(RTN(**)(void*, Args...))(*(uintptr_t*)_this + off))(_this, args...);
}

void Raw_RefreshActorData(Actor* ac)
{
    SymCall("?_sendDirtyActorData@Actor@@QEAAXXZ", uintptr_t, Actor*)(ac);
}
void Raw_RefreshActorData(Player* pl)
{
    Raw_RefreshActorData((Actor*)pl);
}

//////////////////// NBT Class ////////////////////

char& Tag::asByte()
{
    return *(char*)((uintptr_t)this + 8);
}

short& Tag::asShort()
{
    return *(short*)((uintptr_t)this + 8);
}

int& Tag::asInt()
{
    return *(int*)((uintptr_t)this + 8);
}

__int64& Tag::asLong()
{
    return *(__int64*)((uintptr_t)this + 8);
}

float& Tag::asFloat()
{
    return *(float*)((uintptr_t)this + 8);
}

double& Tag::asDouble()
{
    return *(double*)((uintptr_t)this + 8);
}

std::string& Tag::asString()
{
    return *(string*)((uintptr_t)this + 8);
}

vector<Tag*>& Tag::asList()
{
    return *(vector<Tag*>*)((uintptr_t)this + 8);
}

map<string, Tag>& Tag::asCompound()
{
    return *(map<string, Tag>*)((uintptr_t)this + 8);
}

TagMemoryChunk& Tag::asByteArray()
{
    return *(TagMemoryChunk*)((uintptr_t)this + 8);
}

Tag* Tag::createTag(TagType t)
{
    Tag* tag = 0;
    SymCall("?newTag@Tag@@SA?AV?$unique_ptr@VTag@@U?$default_delete@VTag@@@std@@@std@@W4Type@1@@Z",
        void, Tag**, TagType)(&tag, t);
    return tag;
}

char Tag::getTagType() {
    __try
    {
        return ((*(__int64(__fastcall**)(const struct Tag*))(*(uintptr_t*)this + 40i64))(this));
    }
    __except (EXCEPTION_EXECUTE_HANDLER)
    {
        return -1;
    }
}

void Tag::put(const std::string& k, Tag* v) {
    return SymCall("?put@CompoundTag@@QEAAAEAVTag@@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@$$QEAV2@@Z"
        , void, void*, string, Tag*)(this, k, v);
}

void Tag::putEnd(const std::string& k)
{
    put(k, Tag::createTag(TagType::End));
}

void Tag::putShort(const std::string& k, short v) {
    return SymCall("?putShort@CompoundTag@@QEAAAEAFV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@F@Z"
        , void, void*, string, short)(this, k, v);
}

void Tag::putString(const std::string& k, string v) {
    return SymCall("?putString@CompoundTag@@QEAAAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V23@0@Z"
        , void, void*, string, string)(this, k, v);
}

void Tag::putInt(const std::string& k, int v) {
    return SymCall("?putInt@CompoundTag@@QEAAAEAHV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@H@Z"
        , void, void*, string, int)(this, k, v);
}

void Tag::putLong(const std::string& k, __int64 v) {
    return SymCall("?putInt64@CompoundTag@@QEAAAEA_JV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@_J@Z",
        void, void*, string, __int64)(this, k, v);
}

void Tag::putFloat(const std::string& k, float v) {
    return SymCall("?putFloat@CompoundTag@@QEAAAEAMV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@M@Z"
        , void, void*, string, float)(this, k, v);
}

void Tag::putDouble(const std::string& k, double v) {
    Tag* tag = Tag::createTag(TagType::Double);
    tag->asDouble() = v;
    put(k, tag);
}

void Tag::putCompound(const std::string& k, Tag* v) {
    return SymCall("?putCompound@CompoundTag@@QEAAAEAV1@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V1@@Z",
        void, void*, string, Tag*)(this, k, v);
}

void Tag::putByte(const std::string& k, char v) {
    return SymCall("?putByte@CompoundTag@@QEAAAEAEV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@E@Z"
        , void, void*, string, char)(this, k, v);
}

void Tag::putByteArray(const string& key, const TagMemoryChunk& value) {
    return SymCall("?putByteArray@CompoundTag@@QEAAAEAUTagMemoryChunk@@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U2@@Z",
        void, void*, string, const TagMemoryChunk&)(this, key, value);
}

void Tag::putByteArray(const std::string& key, void* data, size_t size) {
    uint8_t* written = new uint8_t[size];
    memcpy(written, data, size);
    TagMemoryChunk tmc(size, written);

    putByteArray(key, tmc);
}

void Tag::destroy()
{
    try
    {
        SymCall("??1CompoundTag@@UEAA@XZ", void, Tag*)(this);
    }
    catch (...)
    {
        ;
    }
}

void Tag::add(Tag* t) {
    SymCall("?add@ListTag@@QEAAXV?$unique_ptr@VTag@@U?$default_delete@VTag@@@std@@@std@@@Z",
        void, void*, Tag**)(this, &t);
}

void Tag::addEnd()
{
    Tag* t = Tag::createTag(TagType::End);
    add(t);
}

void Tag::addByte(char v)
{
    Tag* t = Tag::createTag(TagType::Byte);
    t->asByte() = v;
    add(t);
}

void Tag::addShort(short v)
{
    Tag* t = Tag::createTag(TagType::Short);
    t->asShort() = v;
    add(t);
}

void Tag::addInt(int v)
{
    Tag* t = Tag::createTag(TagType::Int);
    t->asInt() = v;
    add(t);
}

void Tag::addLong(__int64 v)
{
    Tag* t = Tag::createTag(TagType::Long);
    t->asLong() = v;
    add(t);
}

void Tag::addFloat(float v)
{
    Tag* t = Tag::createTag(TagType::Float);
    t->asFloat() = v;
    add(t);
}

void Tag::addDouble(double v)
{
    Tag* t = Tag::createTag(TagType::Double);
    t->asDouble() = v;
    add(t);
}

void Tag::addString(const string& v)
{
    Tag* t = Tag::createTag(TagType::String);
    t->asString() = v;
    add(t);
}

void Tag::addByteArray(void* data, size_t size)
{
    Tag* t = Tag::createTag(TagType::ByteArray);

    uint8_t* written = new uint8_t[size];
    memcpy(written, data, size);
    t->asByteArray() = TagMemoryChunk(size, written);

    add(t);
}


Tag* Tag::fromItem(ItemStack* item) {
    Tag* tmp = 0;
    SymCall("?save@ItemStackBase@@QEBA?AV?$unique_ptr@VCompoundTag@@U?$default_delete@VCompoundTag@@@std@@@std@@XZ",
        void*, void*, Tag**)(item, &tmp);

    return tmp;
}

void Tag::setItem(ItemStack* item) {
    SymCall("?fromTag@ItemStack@@SA?AV1@AEBVCompoundTag@@@Z",
        void*, void*, Tag*)(item, this);
}

Tag* Tag::fromBlock(Block* blk) {
    return (Tag*)((uintptr_t)blk + 96);
}

void Tag::setBlock(Block* blk) {
    *(Tag*)((uintptr_t)blk + 96) = *this;
}

Tag* Tag::fromActor(Actor* actor) {
    Tag* tmp = Tag::createTag(TagType::Compound);
    SymCall("?save@Actor@@UEAA_NAEAVCompoundTag@@@Z",
        void, Actor*, Tag*)(actor, tmp);
    SymCall("?saveWithoutId@Actor@@UEAAXAEAVCompoundTag@@@Z",
        void, Actor*, Tag*)(actor, tmp);
    VirtualCall(actor, 0x810, tmp);    //IDA Virtual Table from Actor::addAdditionalSaveData

    return tmp;
}

bool Tag::setActor(Actor* actor)
{
    void* vtbl = dlsym("??_7DefaultDataLoadHelper@@6B@");
    bool res = SymCall("?load@Actor@@UEAA_NAEBVCompoundTag@@AEAVDataLoadHelper@@@Z",
        bool, Actor*, Tag*, void*)(actor, this, &vtbl);
    VirtualCall(actor, 0x808, this, &vtbl);    //IDA Virtual Table from Actor::readAdditionalSaveData

    Raw_RefreshActorData(actor);
    return res;
}

bool Tag::setPlayer(Player* player)
{
    void* vtbl = dlsym("??_7DefaultDataLoadHelper@@6B@");
    bool res = SymCall("?load@ServerPlayer@@UEAA_NAEBVCompoundTag@@AEAVDataLoadHelper@@@Z",
        bool, ServerPlayer*, Tag*, void*)((ServerPlayer*)player, this, &vtbl);

    SymCall("?readAdditionalSaveData@Player@@MEAAXAEBVCompoundTag@@AEAVDataLoadHelper@@@Z",
        void, Player*, Tag*, void*)(player, this, &vtbl);
    //VirtualCall(player, 0x808, this, &vtbl);    //IDA Virtual Table from Actor::readAdditionalSaveData
    Raw_RefreshActorData(player);
    return res;
}

bool Tag::setBlockEntity(BlockActor* ble)
{
    void* vtbl = dlsym("??_7DefaultDataLoadHelper@@6B@");
    VirtualCall(ble, 0x8, getLevel(), this, &vtbl);    //IDA Virtual Table from BlockActor::load
    return true;
}

Tag* Tag::fromBlockEntity(BlockActor* ble)
{
    Tag* tmp = Tag::createTag(TagType::Compound);
    VirtualCall(ble, 0x10, tmp);    //IDA Virtual Table from BlockActor::save
    return tmp;
}


//////////////////// SNBT ////////////////////

using namespace nbt;

void TagToSNBT_Compound_Helper(tags::compound_tag& res, Tag* nbt);
void TagToSNBT_List_Helper(tags::compound_list_tag& res, Tag* nbt);

void TagToSNBT_List_Helper(tags::byte_list_tag& res, Tag* nbt)
{
    auto& list = nbt->asList();
    for (auto& tag : list)
        res.value.emplace_back(tag->asByte());
}

void TagToSNBT_List_Helper(tags::short_list_tag& res, Tag* nbt)
{
    auto& list = nbt->asList();
    for (auto& tag : list)
        res.value.emplace_back(tag->asShort());
}

void TagToSNBT_List_Helper(tags::int_list_tag& res, Tag* nbt)
{
    auto& list = nbt->asList();
    for (auto& tag : list)
        res.value.emplace_back(tag->asInt());
}

void TagToSNBT_List_Helper(tags::long_list_tag& res, Tag* nbt)
{
    auto& list = nbt->asList();
    for (auto& tag : list)
        res.value.emplace_back(tag->asLong());
}

void TagToSNBT_List_Helper(tags::float_list_tag& res, Tag* nbt)
{
    auto& list = nbt->asList();
    for (auto& tag : list)
        res.value.emplace_back(tag->asFloat());
}

void TagToSNBT_List_Helper(tags::double_list_tag& res, Tag* nbt)
{
    auto& list = nbt->asList();
    for (auto& tag : list)
        res.value.emplace_back(tag->asDouble());
}

void TagToSNBT_List_Helper(tags::string_list_tag& res, Tag* nbt)
{
    auto& list = nbt->asList();
    for (auto& tag : list)
        res.value.emplace_back(tag->asString());
}

void TagToSNBT_List_Helper(tags::bytearray_list_tag& res, Tag* nbt)
{
    auto& list = nbt->asList();
    for (auto& tag : list)
    {
        auto& bytes = tag->asByteArray();

        char* raw = (char*)bytes.data.get();
        vector<int8_t> data;
        data.reserve(bytes.size);
        for (int i = 0; i < bytes.size; ++i)
            data.emplace_back(raw[i]);

        res.value.emplace_back(data);
    }
}

tags::tag_list_tag TagToSNBT_List_Helper(Tag* nbt)
{
    auto& list = nbt->asList();
    if (list.empty())
    {
        return tags::tag_list_tag();
    }
    switch (list[0]->getTagType())
    {
    case TagType::Byte:
    {
        tags::byte_list_tag data;
        TagToSNBT_List_Helper(data, nbt);
        return data.as_tags();
    }
    case TagType::Short:
    {
        tags::short_list_tag data;
        TagToSNBT_List_Helper(data, nbt);
        return data.as_tags();
    }
    case TagType::Int:
    {
        tags::int_list_tag data;
        TagToSNBT_List_Helper(data, nbt);
        // this is error, so return.
        // res = std::move(data.as_tags());
        return data.as_tags();
    }
    case TagType::Long:
    {
        tags::long_list_tag data;
        TagToSNBT_List_Helper(data, nbt);
        return data.as_tags();
    }
    case TagType::Float:
    {
        tags::float_list_tag data;
        TagToSNBT_List_Helper(data, nbt);
        return data.as_tags();
    }
    case TagType::Double:
    {
        tags::double_list_tag data;
        TagToSNBT_List_Helper(data, nbt);
        return data.as_tags();
    }
    case TagType::String:
    {
        tags::string_list_tag data;
        TagToSNBT_List_Helper(data, nbt);
        return data.as_tags();
    }
    case TagType::ByteArray:
    {
        tags::bytearray_list_tag data;
        TagToSNBT_List_Helper(data, nbt);
        return data.as_tags();
    }
    case TagType::List:
    {
        tags::list_list_tag res;
        for (auto& tag : list) {
            tags::tag_list_tag data = TagToSNBT_List_Helper(tag);
            res.value.emplace_back(std::make_unique<tags::tag_list_tag>(data));
        }
        return res.as_tags();
    }
    case TagType::Compound:
    {
        tags::compound_list_tag data;
        TagToSNBT_List_Helper(data, nbt);
        return data.as_tags();
    }
    default:
    {
        return tags::end_list_tag().as_tags();
    }
    }
}

void TagToSNBT_List_Helper(tags::compound_list_tag& res, Tag* nbt)
{
    auto& list = nbt->asList();
    for (auto& tag : list)
    {
        auto obj = tags::compound_tag(false);
        TagToSNBT_Compound_Helper(obj, tag);
        res.value.emplace_back(obj.value);
    }
}

void TagToSNBT_Compound_Helper(tags::compound_tag& res, Tag* nbt)
{
    auto& list = nbt->asCompound();
    for (auto& [key, tag] : list)
    {
        switch (tag.getTagType())
        {
        case TagType::End:
            res.value[key].reset();
            break;
        case TagType::Byte:
            res.value[key] = make_unique<tags::byte_tag>(tag.asByte());
            break;
        case TagType::Short:
            res.value[key] = make_unique<tags::short_tag>(tag.asShort());
            break;
        case TagType::Int:
            res.value[key] = make_unique<tags::int_tag>(tag.asInt());
            break;
        case TagType::Long:
            res.value[key] = make_unique<tags::long_tag>(tag.asLong());
            break;
        case TagType::Float:
            res.value[key] = make_unique<tags::float_tag>(tag.asFloat());
            break;
        case TagType::Double:
            res.value[key] = make_unique<tags::double_tag>(tag.asDouble());
            break;
        case TagType::String:
            res.value[key] = make_unique<tags::string_tag>(tag.asString());
            break;
        case TagType::ByteArray:
        {
            auto& bytes = tag.asByteArray();
            char* raw = (char*)bytes.data.get();
            vector<int8_t> data;
            data.reserve(bytes.size);
            for (int i = 0; i < bytes.size; ++i)
                data.emplace_back(raw[i]);

            res.value[key] = make_unique<tags::bytearray_tag>(data);
            break;
        }
        case TagType::List: {
            auto& list = tag.asList();
            if (list.empty())
            {
                res.value[key] = make_unique<tags::tag_list_tag>();
                break;
            }
            tags::tag_list_tag obj = TagToSNBT_List_Helper(&tag);
            res.value[key] = make_unique<tags::tag_list_tag>(obj);
            break;
        }
        case TagType::Compound: {
            auto obj = tags::compound_tag(false);
            TagToSNBT_Compound_Helper(obj, &tag);
            res.value[key] = make_unique<tags::compound_tag>(obj);
            break;
        }
        default:
            res.value[key].reset();
            break;
        }
    }
}

string TagToSNBT(Tag* nbt)
{
    if (nbt->getTagType() != TagType::Compound)
        return "";
    tags::compound_tag root(true);
    TagToSNBT_Compound_Helper(root, nbt);

    ostringstream sout;
    sout << contexts::mojangson << root;
    return sout.str();
}

// Reference from StringByteOutput and BigEndianStringByteInput
class BigEndianStringByteOutput {
    void writeBigEndianBytes(byte* bytes, size_t count) {
        auto v5 = bytes + count - 1;
        if (v5 >= bytes)
        {
            auto v7 = bytes + 1;
            do
            {
                auto v8 = *(v7 - 1);
                *(v7 - 1) = *v5;
                *v5-- = v8;
            } while (v7++ <= v5);
        }
        writeBytes(bytes, count);
    }
public:
    virtual ~BigEndianStringByteOutput() {};
    virtual void* writeString(void* string_span) {
        return SymCall("?writeString@BytesDataOutput@@UEAAXV?$basic_string_span@$$CBD$0?0@gsl@@@Z",
            void*, void*, void*)((void*)this, string_span);
    }
    virtual void* writeLongString(void* string_span) {
        return SymCall("?writeLongString@BytesDataOutput@@UEAAXV?$basic_string_span@$$CBD$0?0@gsl@@@Z",
            void*, void*, void*)((void*)this, string_span);
    }
    virtual void writeFloat(float data) {
        writeBigEndianBytes((byte*)&data, 4);
    }
    virtual void writeDouble(double data) {
        writeBigEndianBytes((byte*)&data, 8);
    }
    virtual void writeByte(byte data) {
        writeBytes(&data, 1);
    }
    virtual void writeShort(short data) {
        writeBigEndianBytes((byte*)&data, 2);
    }
    virtual void writeInt(int data) {
        writeBigEndianBytes((byte*)&data, 4);
    }
    virtual void writeLongLong(long long data) {
        writeBigEndianBytes((byte*)&data, 8);
    }
    virtual void* writeBytes(byte* bytes, size_t count) {
        return SymCall("?writeBytes@StringByteOutput@@UEAAXPEBX_K@Z",
            void*, void*, byte*, size_t)((void*)this, bytes, count);
    }
};

string TagToBinaryNBT(Tag* tag, bool isLittleEndian) {
    void* vtbl;
    if (isLittleEndian) {
        vtbl = dlsym("??_7StringByteOutput@@6B@");
    }
    else {
        auto tmp = BigEndianStringByteOutput();
        vtbl = *(void***)&tmp;
    }
    //void* vtbl2 = dlsym("??_7BigEndianStringByteOutput@@6B@"); // deleted
    string result = "";
    void* iDataOutput[2] = { vtbl , &result };
    SymCall("?write@NbtIo@@SAXPEBVCompoundTag@@AEAVIDataOutput@@@Z",
        void*, Tag*, void*)(tag, (void*)iDataOutput);
    return result;
}

string TagsToBinaryNBT(const vector<Tag*>& tags, bool isLittleEndian) {
    string bin;
    for (auto tag : tags) {
        bin += TagToBinaryNBT(tag, isLittleEndian);
    }
    return bin;
}

//string TagToBinaryNBT(Tag* nbt)
//{
//    if (nbt->getTagType() != TagType::Compound)
//        return "";
//    tags::compound_tag content(false);
//    TagToSNBT_Compound_Helper(content, nbt);
//    tags::compound_tag root(true);
//    root.value[""] = make_unique<tags::compound_tag>(content);
//
//    ostringstream sout;
//    sout << contexts::bedrock_disk << root;
//    return sout.str();
//}


//////////////////// From SNBT ////////////////////

void SNBTToTag_Compound_Helper(Tag*& nbt, tags::compound_tag& data);
void SNBTToTag_List_Helper(Tag*& nbt, tags::compound_list_tag& data);

void SNBTToTag_List_Helper(Tag*& nbt, tags::end_list_tag& data)
{
    nbt->addEnd();
}

void SNBTToTag_List_Helper(Tag*& nbt, tags::byte_list_tag& data)
{
    for (auto& dat : data.value)
        nbt->addByte((char)dat);
}

void SNBTToTag_List_Helper(Tag*& nbt, tags::short_list_tag& data)
{
    for (auto& dat : data.value)
        nbt->addShort((short)dat);
}

void SNBTToTag_List_Helper(Tag*& nbt, tags::int_list_tag& data)
{
    for (auto& dat : data.value)
        nbt->addInt((int)dat);
}

void SNBTToTag_List_Helper(Tag*& nbt, tags::long_list_tag& data)
{
    for (auto& dat : data.value)
        nbt->addLong((long long)dat);
}

void SNBTToTag_List_Helper(Tag*& nbt, tags::float_list_tag& data)
{
    for (auto& dat : data.value)
        nbt->addFloat((float)dat);
}

void SNBTToTag_List_Helper(Tag*& nbt, tags::double_list_tag& data)
{
    for (auto& dat : data.value)
        nbt->addDouble((double)dat);
}

void SNBTToTag_List_Helper(Tag*& nbt, tags::string_list_tag& data)
{
    for (auto& dat : data.value)
        nbt->addString((string)dat);
}

void SNBTToTag_List_Helper(Tag*& nbt, tags::bytearray_list_tag& data)
{
    for (auto& dat : data.value)
        nbt->addByteArray(dat.data(), dat.size());
}

void SNBTToTag_List_Helper(Tag*& nbt, tags::list_list_tag& data)
{
    for (auto& dat : data.value)
    {
        Tag* tagList = Tag::createTag(TagType::List);
        switch (dat->element_id())
        {
        case tag_id::tag_end:
            SNBTToTag_List_Helper(tagList, *(tags::end_list_tag*)dat.get());
            break;
        case tag_id::tag_byte:
            SNBTToTag_List_Helper(tagList, *(tags::byte_list_tag*)dat.get());
            break;
        case tag_id::tag_short:
            SNBTToTag_List_Helper(tagList, *(tags::short_list_tag*)dat.get());
            break;
        case tag_id::tag_int:
            SNBTToTag_List_Helper(tagList, *(tags::int_list_tag*)dat.get());
            break;
        case tag_id::tag_long:
            SNBTToTag_List_Helper(tagList, *(tags::long_list_tag*)dat.get());
            break;
        case tag_id::tag_float:
            SNBTToTag_List_Helper(tagList, *(tags::float_list_tag*)dat.get());
            break;
        case tag_id::tag_double:
            SNBTToTag_List_Helper(tagList, *(tags::double_list_tag*)dat.get());
            break;
        case tag_id::tag_string:
            SNBTToTag_List_Helper(tagList, *(tags::string_list_tag*)dat.get());
            break;
        case tag_id::tag_bytearray:
            SNBTToTag_List_Helper(tagList, *(tags::bytearray_list_tag*)dat.get());
            break;
        case tag_id::tag_list:
            SNBTToTag_List_Helper(tagList, *(tags::list_list_tag*)dat.get());
            break;
        case tag_id::tag_compound:
            SNBTToTag_List_Helper(tagList, *(tags::compound_list_tag*)dat.get());
            break;
        default:
            break;
        }
        nbt->add(tagList);
    }
}

void SNBTToTag_List_Helper(Tag*& nbt, tags::compound_list_tag& data)
{
    for (auto& dat : data.value)
    {
        Tag* tagComp = Tag::createTag(TagType::Compound);
        SNBTToTag_Compound_Helper(tagComp, dat);
        nbt->add(tagComp);
    }
}

void SNBTToTag_Compound_Helper(Tag*& nbt, tags::compound_tag& data)
{
    for (auto& [key, value] : data.value)
    {
        switch (value->id())
        {
        case tag_id::tag_end:
            nbt->putEnd(key);
            break;
        case tag_id::tag_byte:
            nbt->putByte(key, ((tags::byte_tag*)value.get())->value);
            break;
        case tag_id::tag_short:
            nbt->putShort(key, ((tags::short_tag*)value.get())->value);
            break;
        case tag_id::tag_int:
            nbt->putInt(key, ((tags::int_tag*)value.get())->value);
            break;
        case tag_id::tag_long:
            nbt->putLong(key, ((tags::long_tag*)value.get())->value);
            break;
        case tag_id::tag_float:
            nbt->putFloat(key, ((tags::float_tag*)value.get())->value);
            break;
        case tag_id::tag_double:
            nbt->putDouble(key, ((tags::double_tag*)value.get())->value);
            break;
        case tag_id::tag_string:
            nbt->putString(key, ((tags::string_tag*)value.get())->value);
            break;
        case tag_id::tag_bytearray:
        {
            auto& data = ((tags::bytearray_tag*)value.get())->value;
            nbt->putByteArray(key, data.data(), data.size());
            break;
        }
        case tag_id::tag_list:
        {
            Tag* res = Tag::createTag(TagType::List);

            tags::list_tag* data = (tags::list_tag*)value.get();
            switch (data->element_id())
            {
            case tag_id::tag_byte:
                SNBTToTag_List_Helper(res, *(tags::byte_list_tag*)data);
                break;
            case tag_id::tag_short:
                SNBTToTag_List_Helper(res, *(tags::short_list_tag*)data);
                break;
            case tag_id::tag_int:
                SNBTToTag_List_Helper(res, *(tags::int_list_tag*)data);
                break;
            case tag_id::tag_long:
                SNBTToTag_List_Helper(res, *(tags::long_list_tag*)data);
                break;
            case tag_id::tag_float:
                SNBTToTag_List_Helper(res, *(tags::float_list_tag*)data);
                break;
            case tag_id::tag_double:
                SNBTToTag_List_Helper(res, *(tags::double_list_tag*)data);
                break;
            case tag_id::tag_string:
                SNBTToTag_List_Helper(res, *(tags::string_list_tag*)data);
                break;
            case tag_id::tag_bytearray:
                SNBTToTag_List_Helper(res, *(tags::bytearray_list_tag*)data);
                break;
            case tag_id::tag_list:
                SNBTToTag_List_Helper(res, *(tags::list_list_tag*)data);
                break;
            case tag_id::tag_compound:
                SNBTToTag_List_Helper(res, *(tags::compound_list_tag*)data);
                break;
            default:
                break;
            }
            nbt->put(key, res);
            break;
        }
        case tag_id::tag_compound:
        {
            Tag* res = Tag::createTag(TagType::Compound);
            tags::compound_tag* data = (tags::compound_tag*)value.get();
            SNBTToTag_Compound_Helper(res, *data);
            nbt->put(key, res);
            break;
        }
        }
    }
}

Tag* SNBTToTag(const string& snbt)
{
    istringstream sin(snbt);
    tags::compound_tag root(true);
    sin >> contexts::mojangson >> root;

    Tag* res = Tag::createTag(TagType::Compound);
    SNBTToTag_Compound_Helper(res, root);
    return res;
}

Tag* BinaryNBTToTag(const string& bin, size_t& offset, bool isLittleEndian) {
    void* vtbl;
    if (isLittleEndian)
        vtbl = dlsym("??_7StringByteInput@@6B@");
    else
        vtbl = dlsym("??_7BigEndianStringByteInput@@6B@");

    uintptr_t iDataInput[4] = { (uintptr_t)vtbl , offset, bin.length(), (uintptr_t)bin.c_str() };
    Tag* tag = Tag::createTag(TagType::Compound);
    auto rtn = SymCall("?read@NbtIo@@SA?AV?$unique_ptr@VCompoundTag@@U?$default_delete@VCompoundTag@@@std@@@std@@AEAVIDataInput@@@Z",
        unique_ptr<Tag>*, Tag**, void*)(&tag, (void*)iDataInput);

    offset = iDataInput[1];
    return rtn->get();
}

Tag* BinaryNBTToTag(const string& bin, bool isLittleEndian) {
    size_t offset = 0;
    return BinaryNBTToTag(bin, offset, isLittleEndian);
}

vector<Tag*> BinaryNBTToTags(const string& bin, bool isLittleEndian) {
    vector<Tag*> tags;
    size_t offset = 0;
    while (offset < bin.length()) {
        auto tag = BinaryNBTToTag(bin, offset, isLittleEndian);
        if (offset < 4||tag->getTagType()!=TagType::Compound||tag->asCompound().size()<1)
            return tags;
        tags.emplace_back(tag);
    }
    return tags;
}

//Tag* BinaryNBTToTag(void* data, size_t len)
//{
//    istringstream bsin(string((char*)data, len));
//    tags::compound_tag root(true);
//    bsin >> contexts::bedrock_disk >> root;
//    tags::compound_tag content(false);
//    content = *(tags::compound_tag*)root.value.begin()->second.get();
//
//    Tag* res = Tag::createTag(TagType::Compound);
//    SNBTToTag_Compound_Helper(res, content);
//    return res;
//}

//////////////////// To Json ////////////////////
/*
void TagToJson_Compound_Helper(JSON_VALUE& res, Tag* nbt);

void TagToJson_List_Helper(JSON_VALUE& res, Tag* nbt)
{
    auto& list = nbt->asList();
    for (auto& tag : list)
    {
        switch (tag->getTagType())
        {
        case TagType::End:
            res.push_back(nullptr);
            break;
        case TagType::Byte:
            res.push_back(tag->asByte());
            break;
        case TagType::Short:
            res.push_back(tag->asShort());
            break;
        case TagType::Int:
            res.push_back(tag->asInt());
            break;
        case TagType::Long:
            res.push_back(tag->asLong());
            break;
        case TagType::Float:
            res.push_back(tag->asFloat());
            break;
        case TagType::Double:
            res.push_back(tag->asDouble());
            break;
        case TagType::String:
            res.push_back(tag->asString());
            break;
        case TagType::ByteArray:
        {
            auto& bytes = nbt->asByteArray();
            char* resStr = Raw_Base64Encode((char*)bytes.data.get(), bytes.size);
            res.push_back(string(resStr));
            free(resStr);
            break;
        }
        case TagType::List: {
            JSON_VALUE arrJson = JSON_VALUE::array();
            TagToJson_List_Helper(arrJson, tag);
            res.push_back(arrJson);
            break;
        }
        case TagType::Compound: {
            JSON_VALUE arrObj = JSON_VALUE::object();
            TagToJson_Compound_Helper(arrObj, tag);
            res.push_back(arrObj);
            break;
        }
        default:
            res.push_back(nullptr);
            break;
        }
    }
}

void TagToJson_Compound_Helper(JSON_VALUE& res, Tag* nbt)
{
    auto& list = nbt->asCompound();
    for (auto& [key, tag] : list)
    {
        switch (tag.getTagType())
        {
        case TagType::End:
            res.push_back({ key,nullptr });
            break;
        case TagType::Byte:
            res.push_back({ key,tag.asByte() });
            break;
        case TagType::Short:
            res.push_back({ key,tag.asShort() });
            break;
        case TagType::Int:
            res.push_back({ key,tag.asInt() });
            break;
        case TagType::Long:
            res.push_back({ key,tag.asLong() });
            break;
        case TagType::Float:
            res.push_back({ key,tag.asFloat() });
            break;
        case TagType::Double:
            res.push_back({ key,tag.asDouble() });
            break;
        case TagType::String:
            res.push_back({ key,tag.asString() });
            break;
        case TagType::ByteArray:
        {
            auto& bytes = nbt->asByteArray();
            char* resStr = Raw_Base64Encode((char*)bytes.data.get(), bytes.size);
            res.push_back({ key,string(resStr) });
            free(resStr);
            break;
        }
        case TagType::List: {
            JSON_VALUE arrJson = JSON_VALUE::array();
            TagToJson_List_Helper(arrJson, &tag);
            res.push_back({ key,arrJson });
            break;
        }
        case TagType::Compound: {
            JSON_VALUE arrObj = JSON_VALUE::object();
            TagToJson_Compound_Helper(arrObj, &tag);
            res.push_back({ key,arrObj });
            break;
        }
        default:
            res.push_back({ key,nullptr });
            break;
        }
    }
}

string TagToJson(Tag* nbt, int formatIndent)
{
    string result;
    switch (nbt->getTagType())
    {
    case TagType::End:
        result = "";
        break;
    case TagType::Byte:
        result = to_string(nbt->asByte());
        break;
    case TagType::Short:
        result = to_string(nbt->asShort());
        break;
    case TagType::Int:
        result = to_string(nbt->asInt());
        break;
    case TagType::Long:
        result = to_string(nbt->asLong());
        break;
    case TagType::Float:
        result = to_string(nbt->asFloat());
        break;
    case TagType::Double:
        result = to_string(nbt->asDouble());
        break;
    case TagType::String:
        result = nbt->asString();
        break;
    case TagType::ByteArray:
    {
        auto& bytes = nbt->asByteArray();
        char* res = Raw_Base64Encode((char*)bytes.data.get(), bytes.size);
        result = string(res);
        free(res);
        break;
    }
    case TagType::List: {
        JSON_VALUE jsonRes = JSON_VALUE::array();
        TagToJson_List_Helper(jsonRes, nbt);
        result = jsonRes.dump(formatIndent);
        break;
    }
    case TagType::Compound: {
        JSON_VALUE jsonRes = JSON_VALUE::object();
        TagToJson_Compound_Helper(jsonRes, nbt);
        result = jsonRes.dump(formatIndent);
        break;
    }
    default:
        result = "";
        break;
    }
    return result;
}
*/
