#include "pch.h"
#include "DataHelepr.h"

Tag* loadPlayer(Player* player) {
	return nullptr;
};
Tag* loadPlayer(mce::UUID uuid) {
	return nullptr;
};
Tag* loadPlayer(const string& uuid) {
	mce::UUID tmp = mce::UUID::fromString(uuid);
	return loadPlayer(tmp);
};