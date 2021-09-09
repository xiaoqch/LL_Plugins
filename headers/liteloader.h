#pragma once
#include <string>
#ifdef LITELOADER_EXPORTS
#    define LIAPI __declspec(dllexport)
#else
#    define LIAPI __declspec(dllexport)
#endif
#define LITELOADER_VERSION "1.1.2.1"
#define LITELOADER_VERSION_NUMBER 13ui8
typedef unsigned char uchar;

namespace loaderapi {
LIAPI std::string getLoaderVersion();
LIAPI unsigned short getLoaderVersionNum();
LIAPI bool           isDebugMode();
};  // namespace loaderapi
#define LITELOADER_VERSION_GITHUB LITELOADER_VERSION"-Ci-0668036_1630837437"
