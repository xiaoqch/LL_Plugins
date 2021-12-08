#pragma once
#include "../Global.h"
#include <string>
#include <Windows.h>

// GetLastError() -> string
LIAPI std::string GetLastErrorMessage();

// Get Current DLL's module handle
// (Must be header-only!)
HMODULE inline GetCurrentModule()
{
    HMODULE hModule = NULL;
    if (GetModuleHandleEx(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT,
        (LPCWSTR)GetCurrentModule, &hModule)) {
        return hModule;
    }
    return NULL;
}