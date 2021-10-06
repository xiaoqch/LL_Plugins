// dllmain.cpp : 定义 DLL 应用程序的入口点。
#include "pch.h"
#include "framework.h"

#define VERSION "1.0.0"

void entry() {
    std::cout << "Fix Missing Recipes Pugin Loaded. Version: " << VERSION << std::endl;
};

extern "C" {
    _declspec(dllexport) void onPostInit() {
        std::ios::sync_with_stdio(false);
        entry();
    }
}

//Recipes::loadRecipe(std::pair<string ,Json::Value> const &,SemVersion const &)
THook(bool, "?loadRecipe@Recipes@@QEAA_NAEBU?$pair@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@VValue@Json@@@std@@AEBVSemVersion@@@Z",
    void* _this, std::pair<std::string, void* [2]> data, void* semVersion) {
    auto rtn = original(_this, data, semVersion);
    if (data.first == "recipe_material_reduction") {
        return false;
    }
    return rtn;
}

BOOL APIENTRY DllMain(HMODULE hModule,
    DWORD  ul_reason_for_call,
    LPVOID lpReserved
)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}