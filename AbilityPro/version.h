// Plugin Info
#define PLUGIN_NAME "AbilityPro"
#define PLUGIN_AUTHOR "xiaoqch"
#define PLUGIN_DISPLAY_NAME "AbilityPro"
#define PLUGIN_DESCRIPTION "Ability Pro"
#define PLUGIN_WEBSIDE GITHUB_LINK PLUGIN_NAME
#define PLUGIN_LICENCE "GPLv3"
#define PLUGIN_USAGE false

// Version
#define PLUGIN_VERSION_MAJOR 0
#define PLUGIN_VERSION_MINOR 0
#define PLUGIN_VERSION_REVISION 1
#define PLUGIN_VERSION_IS_BETA true

// Transfer macro to string
#define __TO_PLUGIN_VERSION_STRING(str) #str
#define TO_PLUGIN_VERSION_STRING(str) __TO_PLUGIN_VERSION_STRING(str)

#if PLUGIN_VERSION_IS_BETA
#define PLUGIN_VERSION_STRING TO_PLUGIN_VERSION_STRING(PLUGIN_VERSION_MAJOR.PLUGIN_VERSION_MINOR.PLUGIN_VERSION_REVISION beta)
#else
#define PLUGIN_VERSION_STRING TO_PLUGIN_VERSION_STRING(PLUGIN_VERSION_MAJOR.PLUGIN_VERSION_MINOR.PLUGIN_VERSION_REVISION)
#endif // PLUGIN_VERSION_IS_BETA
