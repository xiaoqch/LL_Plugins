#pragma once
#include "../third-party/nbt-from-lxl/NBT.h"

namespace mce {
	class UUID {
	public:
		std::uint64_t a = 0, b = 0;

		UUID() {
		}
		UUID(std::uint64_t a, std::uint64_t b)
			: a(a)
			, b(b) {
		}
		UUID(UUID const& rhs)
			: a(rhs.a)
			, b(rhs.b) {
		}

		constexpr inline bool operator==(UUID const& rhs) const noexcept {
			return a == rhs.a && b == rhs.b;
		}

		UUID& operator=(UUID const& rhs) {
			a = rhs.a;
			b = rhs.b;
			return *this;
		}

		inline operator char const* () const {
			return (char const*)this;
		}

		std::string asString() const {
			std::string suuid;
			SymCall("?asString@UUID@mce@@QEBA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ",
				std::string*, const  mce::UUID*, std::string*)(this, &suuid);
			return suuid;
		};
		static UUID fromString(std::string const& source) {
			mce::UUID uuid = mce::UUID();
			return *SymCall("?fromString@UUID@mce@@SA?AV12@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z",
				mce::UUID*, mce::UUID*, const std::string&)(&uuid, source);
		};
		static UUID EMPTY;

		inline bool empty() const noexcept {
			return a == 0 && b == 0;
		}
	};
};

// Call
template<typename RTN = void, typename... Args>
RTN inline VirtualCall(void* _this, uintptr_t off, Args... args) {
	return (*(RTN(**)(void*, Args...))(*(uintptr_t*)_this + off))(_this, args...);
}

Level* getLevel();
LevelStorage* getLevelStorage();
string getServerId(const string& storageId);
vector<string> loadAllPlayerIDs(bool b);
string getPlatformOnlineId(Player* player);
Player* getPlayerFromServerId(const string& serverId);
Player* getPlayerByName(const string& name);
string getPlayerXUID(mce::UUID uuid);
string getPlayerUuid(Player* player);
Tag* loadPlayerData(const string& uuid);