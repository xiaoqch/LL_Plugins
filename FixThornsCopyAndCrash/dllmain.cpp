// dllmain.cpp : 定义 DLL 应用程序的入口点。
#include "pch.h"
#include "framework.h"

#define VERSION "1.0.1"

void entry() {
    std::cout << "Fix Thorns Copy And Crash Loaded. Version: " << VERSION << std::endl;
};

extern "C" {
    _declspec(dllexport) void onPostInit() {
        std::ios::sync_with_stdio(false);
        entry();
    }
}

bool markThorns = false;

THook(bool, "?_hurt@Mob@@MEAA_NAEBVActorDamageSource@@H_N1@Z",
    class Mob* mob, class ActorDamageSource* ads, int damage, bool unk1_1, bool unk2_0)
{
    if (mob) {
        int cause = dAccess<int>(ads, 8); //
        //std::cout << cause << std::endl;
        if (cause == 18) {
            if (markThorns) {
                //cout << "发现荆棘产生的荆棘，阻止该荆棘伤害" << endl;
                return false;
            }
            markThorns = true;
            auto rtn = original(mob, ads, damage, unk1_1, unk2_0);
            markThorns = false;
            return rtn;
        }
    }
    return original(mob, ads, damage, unk1_1, unk2_0);
}
//THook(bool, "?doPostHurt@ProtectionEnchant@@UEBAXAEAVItemInstance@@AEAVActor@@1H@Z",
//    class ProtectionEnchant* _this,
//    class ItemInstance* a2,
//    class Actor* a3,
//    class Actor* a4,
//    int a5)
//{
//    if (a3 == a4)
//        return false;
//    return original(_this, a2, a3, a4, 10);
//}
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