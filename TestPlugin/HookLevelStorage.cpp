#include "pch.h"
#include <MC/LevelStorage.hpp>


#ifdef HOOK_CLASS_LevelStorage
// child_types : 1
// public : 7
TInstanceHook(std::string&, "?getServerId@LevelStorage@@QEAA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEBUPlayerStorageIds@@@Z",
              LevelStorage, std::string& ret, struct PlayerStorageIds const& a0)
{
    logger.info("LevelStorage::getServerId");
    auto& rtn = original(this, ret, std::forward<decltype(a0)>(a0));
    return rtn;
}

TInstanceHook(std::string&, "?getServerId@LevelStorage@@QEAA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEBVPlayer@@_N@Z",
              LevelStorage, std::string& ret, class Player const& a0, bool a1)
{
    logger.info("LevelStorage::getServerId");
    auto& rtn = original(this, ret, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
    return rtn;
}

TInstanceHook(std::vector<std::string>&, "?loadAllPlayerIDs@LevelStorage@@QEBA?AV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@_N@Z",
              LevelStorage, std::vector<std::string>& ret, bool a0)
{
    logger.info("LevelStorage::loadAllPlayerIDs");
    auto& rtn = original(this, ret, std::forward<decltype(a0)>(a0));
    return rtn;
}

#include <MC/CompoundTag.hpp>
TInstanceHook(std::unique_ptr<class CompoundTag>&, "?loadPlayerDataFromTag@LevelStorage@@QEAA?AV?$unique_ptr@VCompoundTag@@U?$default_delete@VCompoundTag@@@std@@@std@@V?$basic_string_span@$$CBD$0?0@gsl@@@Z",
              LevelStorage, std::unique_ptr<class CompoundTag>& ret, class gsl::basic_string_span<char const, -1> a0)
{
    logger.info("LevelStorage::loadPlayerDataFromTag");
    auto& rtn = original(this, ret, std::forward<decltype(a0)>(a0));
    return rtn;
}

#include <MC/CompoundTag.hpp>
TInstanceHook(std::unique_ptr<class CompoundTag>&, "?loadServerPlayerData@LevelStorage@@QEAA?AV?$unique_ptr@VCompoundTag@@U?$default_delete@VCompoundTag@@@std@@@std@@AEBVPlayer@@_N@Z",
              LevelStorage, std::unique_ptr<class CompoundTag>& ret, class Player const& a0, bool a1)
{
    logger.info("LevelStorage::loadServerPlayerData");
    auto& rtn = original(this, ret, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
    return rtn;
}

TInstanceHook(void, "?save@LevelStorage@@QEAAXAEAVActor@@@Z",
              LevelStorage, class Actor& a0)
{
    logger.info("LevelStorage::save");
    original(this, std::forward<decltype(a0)>(a0));
}

#include <MC/Bedrock.hpp>
TInstanceHook(std::shared_ptr<class Bedrock::Threading::IAsyncResult<void>>&, "?saveData@LevelStorage@@QEAA?AV?$shared_ptr@V?$IAsyncResult@X@Threading@Bedrock@@@std@@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@3@AEBVCompoundTag@@W4Category@DBHelpers@@@Z",
              LevelStorage, std::shared_ptr<class Bedrock::Threading::IAsyncResult<void>>& ret, std::string const& a0, class CompoundTag const& a1, enum DBHelpers::Category a2)
{
    logger.info("LevelStorage::saveData");
    auto& rtn = original(this, ret, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1), std::forward<decltype(a2)>(a2));
    return rtn;
}

// public.static : 2
THook(std::string const&, "?LOCAL_PLAYER_TAG@LevelStorage@@2V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@B",
      std::string const& ret)
{
    logger.info("LevelStorage::LOCAL_PLAYER_TAG");
    auto& rtn = original(ret);
    return rtn;
}

THook(std::string const&, "?LEGACY_CONSOLE_PLAYER_PREFIX@LevelStorage@@2V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@B",
      std::string const& ret)
{
    logger.info("LevelStorage::LEGACY_CONSOLE_PLAYER_PREFIX");
    auto& rtn = original(ret);
    return rtn;
}

// virtual : 32
TInstanceHook(bool, "?clonePlayerData@LevelStorage@@UEAA_NV?$basic_string_span@$$CBD$0?0@gsl@@0@Z",
              LevelStorage, class gsl::basic_string_span<char const, -1> a0, class gsl::basic_string_span<char const, -1> a1)
{
    logger.info("LevelStorage::clonePlayerData");
    auto rtn = original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
    return rtn;
}

// there are 1382 functions with the same rva

// ??$parse@PEBUActorDefinitionIdentifier@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@PEBVBlock@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@PEBVMobEffect@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@V?$AutomaticID@VDimension@@H@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@VCommandItem@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@VExecuteChainedSubcommand@NewExecuteCommand@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@W4Action@AllowListCommand@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@W4Action@CodeBuilderCommand@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@W4Action@DialogueCommand@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@W4Action@MusicCommand@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@W4Action@PermissionCommand@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@W4Action@ScoreboardCommand@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@W4Action@TagCommand@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@W4ActionType@ResourceUriCommand@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@W4ActorDamageCause@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@W4AddAreaType@TickingAreaCommand@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@W4AnimationMode@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@W4AreaType@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@W4AvailableCommandPermissionPresets@PermissionCommand@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@W4BlockSlot@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z

// TInstanceHook(bool, "?loadData@LevelStorage@@UEBA_NV?$basic_string_span@$$CBD$0?0@gsl@@AEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@W4Category@DBHelpers@@@Z",
//     LevelStorage, class gsl::basic_string_span<char const, -1> a0, std::string& a1, enum DBHelpers::Category a2){
//     logger.info("LevelStorage::loadData");
//     auto rtn = original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1), std::forward<decltype(a2)>(a2));
//     return rtn;
// }

// there are 1606 functions with the same rva

// ??$basic_vtable@C@meta_any@entt@@CAXW4operation@01@AEBV?$basic_any@$0BA@$07@1@PEAX@Z
// ??$basic_vtable@D@meta_any@entt@@CAXW4operation@01@AEBV?$basic_any@$0BA@$07@1@PEAX@Z
// ??$basic_vtable@E@meta_any@entt@@CAXW4operation@01@AEBV?$basic_any@$0BA@$07@1@PEAX@Z
// ??$basic_vtable@F@meta_any@entt@@CAXW4operation@01@AEBV?$basic_any@$0BA@$07@1@PEAX@Z
// ??$basic_vtable@G@meta_any@entt@@CAXW4operation@01@AEBV?$basic_any@$0BA@$07@1@PEAX@Z
// ??$basic_vtable@H@meta_any@entt@@CAXW4operation@01@AEBV?$basic_any@$0BA@$07@1@PEAX@Z
// ??$basic_vtable@I@meta_any@entt@@CAXW4operation@01@AEBV?$basic_any@$0BA@$07@1@PEAX@Z
// ??$basic_vtable@M@meta_any@entt@@CAXW4operation@01@AEBV?$basic_any@$0BA@$07@1@PEAX@Z
// ??$basic_vtable@N@meta_any@entt@@CAXW4operation@01@AEBV?$basic_any@$0BA@$07@1@PEAX@Z
// ??$basic_vtable@U?$VariantCRef@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UBlockMaterialInstance@@@cereal@@@meta_any@entt@@CAXW4operation@01@AEBV?$basic_any@$0BA@$07@1@PEAX@Z
// ??$basic_vtable@U?$_Wrap_alloc@V?$allocator@I@std@@@std@@@meta_any@entt@@CAXW4operation@01@AEBV?$basic_any@$0BA@$07@1@PEAX@Z
// ??$basic_vtable@U?$char_traits@D@std@@@meta_any@entt@@CAXW4operation@01@AEBV?$basic_any@$0BA@$07@1@PEAX@Z
// ??$basic_vtable@U?$equal_to@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@meta_any@entt@@CAXW4operation@01@AEBV?$basic_any@$0BA@$07@1@PEAX@Z
// ??$basic_vtable@U?$hash@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@meta_any@entt@@CAXW4operation@01@AEBV?$basic_any@$0BA@$07@1@PEAX@Z
// ??$basic_vtable@U?$hash@VHashedString@@@std@@@meta_any@entt@@CAXW4operation@01@AEBV?$basic_any@$0BA@$07@1@PEAX@Z
// ??$basic_vtable@U?$less@PEBVItem@@@std@@@meta_any@entt@@CAXW4operation@01@AEBV?$basic_any@$0BA@$07@1@PEAX@Z
// ??$basic_vtable@U?$less@UStateNameProxy@@@std@@@meta_any@entt@@CAXW4operation@01@AEBV?$basic_any@$0BA@$07@1@PEAX@Z
// ??$basic_vtable@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@meta_any@entt@@CAXW4operation@01@AEBV?$basic_any@$0BA@$07@1@PEAX@Z
// ??$basic_vtable@U?$meta_class_template_tag@UTypedObjectHandle@Scripting@@@entt@@@meta_any@entt@@CAXW4operation@01@AEBV?$basic_any@$0BA@$07@1@PEAX@Z
// ??$basic_vtable@U?$meta_class_template_tag@UVariantCRef@cereal@@@entt@@@meta_any@entt@@CAXW4operation@01@AEBV?$basic_any@$0BA@$07@1@PEAX@Z

// TInstanceHook(void, "?freeCaches@LevelStorage@@UEAAXXZ",
//     LevelStorage){
//     logger.info("LevelStorage::freeCaches");
//     original(this);
// }

// there are 1606 functions with the same rva

// ??$basic_vtable@C@meta_any@entt@@CAXW4operation@01@AEBV?$basic_any@$0BA@$07@1@PEAX@Z
// ??$basic_vtable@D@meta_any@entt@@CAXW4operation@01@AEBV?$basic_any@$0BA@$07@1@PEAX@Z
// ??$basic_vtable@E@meta_any@entt@@CAXW4operation@01@AEBV?$basic_any@$0BA@$07@1@PEAX@Z
// ??$basic_vtable@F@meta_any@entt@@CAXW4operation@01@AEBV?$basic_any@$0BA@$07@1@PEAX@Z
// ??$basic_vtable@G@meta_any@entt@@CAXW4operation@01@AEBV?$basic_any@$0BA@$07@1@PEAX@Z
// ??$basic_vtable@H@meta_any@entt@@CAXW4operation@01@AEBV?$basic_any@$0BA@$07@1@PEAX@Z
// ??$basic_vtable@I@meta_any@entt@@CAXW4operation@01@AEBV?$basic_any@$0BA@$07@1@PEAX@Z
// ??$basic_vtable@M@meta_any@entt@@CAXW4operation@01@AEBV?$basic_any@$0BA@$07@1@PEAX@Z
// ??$basic_vtable@N@meta_any@entt@@CAXW4operation@01@AEBV?$basic_any@$0BA@$07@1@PEAX@Z
// ??$basic_vtable@U?$VariantCRef@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UBlockMaterialInstance@@@cereal@@@meta_any@entt@@CAXW4operation@01@AEBV?$basic_any@$0BA@$07@1@PEAX@Z
// ??$basic_vtable@U?$_Wrap_alloc@V?$allocator@I@std@@@std@@@meta_any@entt@@CAXW4operation@01@AEBV?$basic_any@$0BA@$07@1@PEAX@Z
// ??$basic_vtable@U?$char_traits@D@std@@@meta_any@entt@@CAXW4operation@01@AEBV?$basic_any@$0BA@$07@1@PEAX@Z
// ??$basic_vtable@U?$equal_to@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@meta_any@entt@@CAXW4operation@01@AEBV?$basic_any@$0BA@$07@1@PEAX@Z
// ??$basic_vtable@U?$hash@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@meta_any@entt@@CAXW4operation@01@AEBV?$basic_any@$0BA@$07@1@PEAX@Z
// ??$basic_vtable@U?$hash@VHashedString@@@std@@@meta_any@entt@@CAXW4operation@01@AEBV?$basic_any@$0BA@$07@1@PEAX@Z
// ??$basic_vtable@U?$less@PEBVItem@@@std@@@meta_any@entt@@CAXW4operation@01@AEBV?$basic_any@$0BA@$07@1@PEAX@Z
// ??$basic_vtable@U?$less@UStateNameProxy@@@std@@@meta_any@entt@@CAXW4operation@01@AEBV?$basic_any@$0BA@$07@1@PEAX@Z
// ??$basic_vtable@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@meta_any@entt@@CAXW4operation@01@AEBV?$basic_any@$0BA@$07@1@PEAX@Z
// ??$basic_vtable@U?$meta_class_template_tag@UTypedObjectHandle@Scripting@@@entt@@@meta_any@entt@@CAXW4operation@01@AEBV?$basic_any@$0BA@$07@1@PEAX@Z
// ??$basic_vtable@U?$meta_class_template_tag@UVariantCRef@cereal@@@entt@@@meta_any@entt@@CAXW4operation@01@AEBV?$basic_any@$0BA@$07@1@PEAX@Z

// TInstanceHook(void, "?corruptLevel@LevelStorage@@UEAAXXZ",
//     LevelStorage){
//     logger.info("LevelStorage::corruptLevel");
//     original(this);
// }

// virtual.unordered : 1
TInstanceHook(class LevelStorage&, "??1LevelStorage@@UEAA@XZ",
              LevelStorage)
{
    logger.info("LevelStorage::~LevelStorage");
    auto& rtn = original(this);
    return rtn;
}

// vtbl_entry : 1

#endif // HOOK_CLASS_LevelStorage
