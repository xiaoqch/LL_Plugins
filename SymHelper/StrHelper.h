#pragma once
#include <mc/CommandReg.h>
namespace StrHelper {
    inline string toCamelCase(string const& src, char c = '_') {
        string dst;
        dst = SymCall("?toCamelCase@Util@@YA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEBV23@D@Z",
            string&, string&, string const&, char)(dst, src, c);
        return dst;
    }
    inline string toLower(string const& src) {
        string dst;
        dst = SymCall("?toLower@Util@@YA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEBV23@@Z",
            string&, string&, string const&)(dst, src);
        return dst;
    }
    inline string toUpper(string const& src) {
        string dst;
        dst = SymCall("?toUpper@Util@@YA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEBV23@@Z",
            string&, string&, string const&)(dst, src);
        return dst;
    }
    inline string toHex(string const& src) {
        string dst;
        dst = SymCall("?toHex@Util@@YA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEBV23@@Z",
            string&, string&, string const&)(dst, src);
        return dst;
    }
    inline string fromHex(string const& src) {
        string dst;
        dst = SymCall("?fromHex@Util@@YA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEBV23@@Z",
            string&, string&, string const&)(dst, src);
        return dst;
    }
    inline bool isValidUTF8(string const& src) {
        return SymCall("?isValidUTF8@Util@@YA_NAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z",
            bool, string const&)(src);
    }
    inline string seriJson(void* json) {
        string str;
        return SymCall("?serialize@JsonHelpers@@YA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEBVValue@Json@@@Z",
            string&, string&, void*)(str, json);
    }

    inline void* parseJson(void* json, string& str) {
        SymCall("?parseJson@JsonHelpers@@YA_NAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAVValue@Json@@@Z",
            bool, string&, void*)(str, json);
        return json;
    }
}

