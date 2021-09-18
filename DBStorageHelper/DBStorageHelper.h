#pragma once
#include "DBStorage.h"
struct string_span {
    size_t len;
    char* str;
    string toString();
};
class DBStorageHelper : DBStorage
{
    DBStorage* levelStorage;
public:
    DBStorageHelper(Level* level);
};


string bytesToHexStr(byte* byte_arr, int arr_len, string prefix = "\\x");
string keyToString(string& key, string prefix = "\\x");