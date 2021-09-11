#include "pch.h"
#include "SymHelper.h"
using namespace std;


bool oncmd_rd(CommandOrigin const& ori, CommandOutput& outp, std::string uuid, optional<int> index) {
	// [0] = MsaId
	// [1] = // Unknown，似乎读取玩家数据用不到
	// [2] = PlatformOnlineId // Create New If Not Exist!
	// [3] = PlatformOfflineId // Create New If Not Exist!
	// [4] = SelfSignedId // Create New If Not Exist!
	// [5] = // Unknown，但是对读取玩家数据有影响，一串
	// [5] 是一串纯数字的字符串，形如：5695722221326097789，然而并不能直接通过该值读取玩家数据
	// PlatformOnlineId, PlatformOfflineId, 还有一个？
	string playerStorageIds[6];
	//void* a=&playerStorageIds[5];
	//a = nullptr;
	if (index.set) {
		auto i = index.val();
		if (i >= 0 && i < 6) {
			playerStorageIds[i] = uuid;
		}
		else {
			playerStorageIds[0] = uuid;
		}
	}
	else {
		playerStorageIds[0] = uuid;
	}
	LevelStorage* ls = SymCall("?getLevelStorage@Level@@UEBAAEBVLevelStorage@@XZ",
		LevelStorage*, Level*)(ori.getLevel());
	Tag* playerTag = nullptr; Tag::createTag(TagType::Compound);
	SymCall("?loadPlayerData@PlayerDataSystem@@YA?AV?$unique_ptr@VCompoundTag@@U?$default_delete@VCompoundTag@@@std@@@std@@AEAVLevelStorage@@AEBUPlayerStorageIds@@_N@Z",
		void*, Tag*&, LevelStorage*, std::string*, bool)(playerTag, ls, playerStorageIds, true);

	return true;
}


void entry() {

}


// Player Ids Logger
THook(void*, "?loadPlayerData@PlayerDataSystem@@YA?AV?$unique_ptr@VCompoundTag@@U?$default_delete@VCompoundTag@@@std@@@std@@AEAVLevelStorage@@AEBUPlayerStorageIds@@_N@Z",
	unique_ptr<Tag>& tagPtr, LevelStorage* ls, string psi[6], bool b) {
	cout << "PlayerDataSystem::loadPlayerData(" << tagPtr << ", " << ls << ", \"" << psi << "\", " << b << ");" << endl;
	void* ret = original(tagPtr, ls, psi, b);
	cout << "psi[0]: " << psi[0] << endl;
	cout << "psi[1]: " << psi[1] << endl;
	cout << "psi[2]: " << psi[2] << endl;
	cout << "psi[3]: " << psi[3] << endl;
	cout << "psi[4]: " << psi[4] << endl;
	cout << "psi[4]: " << psi[5] << endl;
	Tag* tag = tagPtr.get();
	if (tag) {
		auto& pTag = tag->asCompound();
		auto uid = pTag.find("UniqueID");
		if (uid != pTag.end()) {
			std::cout << "UniqueID: " << endl << uid->second.asLong() << std::endl;
		}
		else {
			std::cout << "SNBT: " << endl << TagToSNBT(tag) << std::endl;
		}
	}
	return ret;
}