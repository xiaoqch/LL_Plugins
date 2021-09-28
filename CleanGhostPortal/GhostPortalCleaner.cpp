#include "pch.h"
#include <nbt-from-lxl/NBT.h>
#include <api/scheduler/scheduler.h>
#include <mc/OffsetHelper.h>
#include <mc/LevelChunk.h>

using namespace std;

#define VERSION "v1.0.0"

class PortalForcer;

Minecraft* mc;

THook(void, "?initAsDedicatedServer@Minecraft@@QEAAXXZ", void* self)
{
    original(self);
    mc = (Minecraft*)self;
}

Dimension* getDimensionByDid(int dimid) {
    return SymCall("?getDimension@Level@@UEBAPEAVDimension@@V?$AutomaticID@VDimension@@H@@@Z",
        Dimension*, void*, int)(mc->getLevel(), dimid);
}

BlockSource* getBlockSourceByDim(int dimid)
{
    auto dim = (int*)getDimensionByDid(dimid);
    if (dim)
        return dAccess<BlockSource*>(dim, 96);
        
    return nullptr;
}

// 单传送门记录
struct PortalRecord {
    int DimId;
    char Span;
    int TpX;
    int TpY;
    int TpZ;
    char Xa;
    char Za;
    Tag* toTag() {
        Tag* tag = Tag::createTag(TagType::Compound);
        tag->putInt("DimId", this->DimId);
        tag->putByte("Span", this->Span);
        tag->putInt("TpX", this->TpX);
        tag->putInt("TpY", this->TpY);
        tag->putInt("TpZ", this->TpZ);
        tag->putByte("Xa", this->Xa);
        tag->putByte("Za", this->Za);
        return tag;
    }
    PortalRecord(Tag* tag) {
        auto& cmp = tag->asCompound();
        this->DimId = cmp["DimId"].asInt();
        this->Span = cmp["Span"].asByte();
        this->TpX = cmp["TpX"].asInt();
        this->TpY = cmp["TpY"].asInt();
        this->TpZ = cmp["TpZ"].asInt();
        this->Xa = cmp["Xa"].asByte();
        this->Za = cmp["Za"].asByte();
    }
    BlockPos getPos() {
        return { this->TpX, this->TpY, this->TpZ };
    }
    BlockPos getTpPos() {
        return { this->TpX + (int)this->Xa, this->TpY, this->TpZ + (int)this->Za };
    }
    string toString() {
        return TagToSNBT(this->toTag());
    }
};

// 所有传送门记录
struct Portals {
    vector<PortalRecord> records;
    Tag* toTag() {
        Tag* prTags = Tag::createTag(TagType::List);
        for (auto& r : records) {
            prTags->add(r.toTag());
        }
        Tag* tag = Tag::createTag(TagType::Compound);
        Tag* data = Tag::createTag(TagType::Compound);
        data->put("PortalRecords", prTags);
        tag->putCompound("data", data);
        return tag;
    }
    Portals(Tag* tag) {
        try {
            auto& prTags = tag->asCompound()["PortalRecords"].asList();
            for (auto& prTag : prTags) {
                PortalRecord pr(prTag);
                this->records.push_back(pr);
            }
        }
        catch (...) {};
    }
};

void entry() {
    _set_se_translator(seh_exception::TranslateSEHtoCE);

    cout << "Ghost Portal Cleaner has loaded. Version: " << VERSION << endl;
}

struct ChunkBlockPos {
    char x;
    char z;
    __int16 y;
};
template<typename RTN = void, typename... Args>
RTN inline VirtualCall(void* _this, uintptr_t off, Args... args) {
    return (*(RTN(**)(void*, Args...))(*(uintptr_t*)_this + off))(_this, args...);
}
// 返回方块或空指针
Block* getBlockEx(BlockSource* bs, BlockPos bpos) {
    //if (bpos.y < *((__int16*)bs + 21))
    //    return nullptr;
    //if (bpos.y >= *((__int16*)bs + 20))
    //    return nullptr;

    LevelChunk* chunk = SymCall("?getChunkAt@BlockSource@@QEBAPEAVLevelChunk@@AEBVBlockPos@@@Z",
        LevelChunk*, BlockSource*, BlockPos*)(bs, &bpos);
    if (!chunk)
        return nullptr;

    short cby = bpos.y - dAccess<short>(bs, 42);
    char cbx = bpos.x & 0xF;
    char cbz = bpos.z & 0xF;
    ChunkBlockPos cbpos{ cbx, cbz, cby };

    // unknown code from IDA LevelChunk::getBlock
    //auto subChunkIndex = cbpos.y >> 4; // cbpos.y/16 数据中的第几层？
    //auto subChunkCount=dAccess<int64_t>(chunk, 352);
    //auto subChunk = dAccess<void*>(chunk, 80 * static_cast<uintptr_t>(subChunkIndex) + 248);
    //if (subChunkIndex >= subChunkCount || !subChunk)
    //    return nullptr;
    //void* func = dAccess<void*>(subChunk, 6*8); //blockPalette?
    //auto blockIndex = (cbpos.y & 0xF) + 16 * (cbpos.z + 16 * cbpos.x);
    //VirtualCall<void*>(func, 16, blockIndex);
    //return (Block*)(*(__int64(__fastcall**)(uintptr_t, uintptr_t))(**((uintptr_t**)v3 + 6) + 16i64))(
    //    *((uintptr_t*)v3 + 6),
    //    (unsigned __int16)((cbpos.y & 0xF)
    //        + 16 * (cbpos.z + 16 * cbpos.x)));

    return SymCall("?getBlock@LevelChunk@@QEBAAEBVBlock@@AEBVChunkBlockPos@@@Z",
        Block*, LevelChunk*, ChunkBlockPos*)(chunk, &cbpos);
}

// 快速判断
bool isPortalBlock(BlockSource* bs, BlockPos bpos) {
    Block* bl = SymCall("?getBlock@BlockSource@@QEBAAEBVBlock@@AEBVBlockPos@@@Z",
        Block*, BlockSource*, BlockPos&)(bs, bpos);
    //cout << offBlock::getFullName(bl) << ":" << bpos.toString() << endl;
    return offBlock::getFullName(bl) == "minecraft:portal";
}

bool shouldRemove(BlockSource* bs, BlockPos bpos) {
    Block* bl = getBlockEx(bs, bpos);
    if (!bl)
        return false;
    //cout << offBlock::getFullName(bl) << ":" << bpos.toString() << endl;
    return offBlock::getFullName(bl) != "minecraft:portal";
}

// 刚过传送门时不适用
bool isInsidePortal(Actor* actor) {
    return SymCall("?isInsidePortal@Actor@@QEBA_NXZ",
        bool, Actor*)(actor);
}

void removePortal(PortalForcer* pf, BlockPos bpos, BlockSource* bs) {
    SymCall("?removePortalRecord@PortalForcer@@QEAAXAEAVBlockSource@@AEBVBlockPos@@@Z",
        void, PortalForcer*, BlockSource*, BlockPos*)(pf, bs, &bpos);
}

int cleanPortals(PortalForcer* pf) {
    int count = 0;
    Tag* pTag = Tag::createTag(TagType::Compound);
    SymCall("?serialize@PortalForcer@@UEBAXAEAVCompoundTag@@@Z",
        void, PortalForcer*, Tag*)(pf, pTag);
    //cout << TagToSNBT(pTag) << endl;
    Portals portals(pTag);
    for (auto& pr : portals.records) {
        auto dimid = pr.DimId;
        auto bs = getBlockSourceByDim(dimid);
        if (!bs)
            continue;
        if (((bool)pr.Xa && (bool)pr.Za)
            || shouldRemove(bs, pr.getPos())
            || shouldRemove(bs, pr.getTpPos())) {
            cout << "Remove Portal In Dim " << dimid << " (" << pr.getPos().toString() << ")" << endl;
            removePortal(pf, pr.getPos(), bs);
            ++count;
        }
    }
    return count;
}

THook(void, "?travelPortal@PortalForcer@@QEBAXAEAVActor@@AEBVBlockPos@@V?$AutomaticID@VDimension@@H@@@Z",
    PortalForcer* pf, Actor* actor, BlockPos* bpos, int dimid) {
    original(pf, actor, bpos, dimid);

    if (!actor || isPortalBlock(offPlayer::getBlockSource(actor), *bpos))
        return;

    auto task = DelayedTask([pf]()->void {
        _set_se_translator(seh_exception::TranslateSEHtoCE);
        try {
            int count = cleanPortals(pf);
            if (count)
                cout << "Found and clean " << count << " Ghost Portal" << (count > 1 ? "s." : ".") << endl;
            else
                cerr << "Ghost Portal not found." << endl;
        }
        catch (const seh_exception&) {}
        catch (const exception&) {}
        }, 1);
    auto taskId = Handler::schedule(std::move(task));
    cout << "Found Ghost Portal! Try to clean all Ghost Portals" << endl;
}
