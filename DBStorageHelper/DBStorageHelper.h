#pragma once
#include "DBStorage.h"
struct string_span {
    size_t len;
    const char* str;
    string toString();
    static string_span fromString(const string& str) {
        return { str.length(), str.c_str() };
    };
};
class DBStorageHelper
{
    DBStorage* db;
public:
    DBStorageHelper(DBStorage* dbStorage);
    bool hasKey(const string& key);
    IAsyncResult<void> createAsyncResult();
    string getBinaryData(const string& key);
    Tag* getCompoundTag(const string& key);
    vector<Tag*> getCompoundTags(const string& key);
    bool forEachKeyWithPrefix(const string& prefix, function<void(const string& key, string& bin)> const& func);
    vector<string> getKeysWithPrefix(const string& prefix);
    bool saveBinary(const string& key, string& binary);
    bool saveTags(const string& key, vector<Tag*> tags);

    bool saveTag(const string& key, Tag* tag);
    vector<PortalRecord> getPortals();
    bool setPortals(vector<PortalRecord> portals);
};


string bytesToHexStr(byte* byte_arr, int arr_len, const string& prefix = "\\x");
string keyToString(const string& key, const string& prefix = "\\x");