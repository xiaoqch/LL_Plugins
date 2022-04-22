#include "pch.h"
#include <MC/SimulatedPlayer.hpp>

#ifdef HOOK_CLASS_SimulatedPlayer
// parent_types : 4
// private : 6
TInstanceHook(void, "?_addMoveComponent@SimulatedPlayer@@AEAAXXZ",
              SimulatedPlayer)
{
    logger.info("SimulatedPlayer({})::_addMoveComponent", getName());
    original(this);
}

//// if type T is not complete
//template <typename T, typename = void>
//struct auto_type
//{
//    using type = std::conditional_t<std::is_reference_v<T>,T,std::add_lvalue_reference_t<T>>;
//};
//// if type T is complete
//template <typename T>
//struct auto_type<T, decltype(void(sizeof(T)))>
//{
//    using type = T;
//};
//template <typename T>
//using auto_type_t = auto_type<T>::type;


TInstanceHook(struct ScriptNavigationResult&, "?_createNavigationResult@SimulatedPlayer@@AEBA?AUScriptNavigationResult@@PEAVNavigationComponent@@@Z",
              SimulatedPlayer, struct ScriptNavigationResult& ret, class NavigationComponent* a0)
{
    logger.info("SimulatedPlayer({})::_createNavigationResult", getName());
    auto& rtn = original(this, ret, std::forward<decltype(a0)>(a0));
    return rtn;
}

TInstanceHook(float, "?_getInputSpeed@SimulatedPlayer@@AEAAMXZ",
              SimulatedPlayer)
{
    logger.info("SimulatedPlayer({})::_getInputSpeed", getName());
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(void, "?_startCooldown@SimulatedPlayer@@AEAAXXZ",
              SimulatedPlayer)
{
    logger.info("SimulatedPlayer({})::_startCooldown", getName());
    original(this);
}

TInstanceHook(bool, "?_trySwing@SimulatedPlayer@@AEAA_NXZ",
              SimulatedPlayer)
{
    logger.info("SimulatedPlayer({})::_trySwing", getName());
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(void, "?_updateMovement@SimulatedPlayer@@AEAAXXZ",
              SimulatedPlayer)
{
    logger.info("SimulatedPlayer({})::_updateMovement", getName());
    original(this);
}

// public : 31
#include <MC/Certificate.hpp>
TInstanceHook(class SimulatedPlayer&, "??0SimulatedPlayer@@QEAA@AEAVLevel@@AEAVPacketSender@@AEAVNetworkHandler@@AEAVActiveTransfersManager@Server@ClientBlobCache@@W4GameType@@AEBVNetworkIdentifier@@EV?$function@$$A6AXAEAVServerPlayer@@@Z@std@@VUUID@mce@@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$unique_ptr@VCertificate@@U?$default_delete@VCertificate@@@std@@@std@@H_NAEAVEntityContext@@@Z",
              SimulatedPlayer, class Level& a0, class PacketSender& a1, class NetworkHandler& a2, class ClientBlobCache::Server::ActiveTransfersManager& a3, enum GameType a4, class NetworkIdentifier const& a5, unsigned char a6, class std::function<void(class ServerPlayer&)> a7, class mce::UUID a8, std::string const& a9, std::unique_ptr<class Certificate> a10, int a11, bool a12, class EntityContext& a13)
{
    logger.info("SimulatedPlayer::SimulatedPlayer");
    auto& rtn = original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1), std::forward<decltype(a2)>(a2), std::forward<decltype(a3)>(a3), std::forward<decltype(a4)>(a4), std::forward<decltype(a5)>(a5), std::forward<decltype(a6)>(a6), std::forward<decltype(a7)>(a7), std::forward<decltype(a8)>(a8), std::forward<decltype(a9)>(a9), std::forward<decltype(a10)>(a10), std::forward<decltype(a11)>(a11), std::forward<decltype(a12)>(a12), std::forward<decltype(a13)>(a13));
    return rtn;
}

TInstanceHook(class Bedrock::NonOwnerPointer<class gametest::BaseGameTestHelper>&, "?getGameTestHelper@SimulatedPlayer@@QEBA?AV?$NonOwnerPointer@VBaseGameTestHelper@gametest@@@Bedrock@@XZ",
              SimulatedPlayer, class Bedrock::NonOwnerPointer<class gametest::BaseGameTestHelper>& ret)
{
    logger.info("SimulatedPlayer({})::getGameTestHelper", getName());
    auto& rtn = original(this, ret);
    return rtn;
}

// TInstanceHook(void, "?setGameTestHelper@SimulatedPlayer@@QEAAXV?$NonOwnerPointer@VBaseGameTestHelper@gametest@@@Bedrock@@@Z",
//     SimulatedPlayer, class Bedrock::NonOwnerPointer<class gametest::BaseGameTestHelper> a0){
//     logger.info("SimulatedPlayer({})::setGameTestHelper", getName());
//     original(this, std::forward<decltype(a0)>(a0));
// }

TInstanceHook(bool, "?simulateAttack@SimulatedPlayer@@QEAA_NAEAVActor@@@Z",
              SimulatedPlayer, class Actor& a0)
{
    logger.info("SimulatedPlayer({})::simulateAttack", getName());
    auto rtn = original(this, std::forward<decltype(a0)>(a0));
    return rtn;
}

TInstanceHook(bool, "?simulateAttack@SimulatedPlayer@@QEAA_NXZ",
              SimulatedPlayer)
{
    logger.info("SimulatedPlayer({})::simulateAttack", getName());
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(bool, "?simulateDestroyBlock@SimulatedPlayer@@QEAA_NAEBVBlockPos@@E@Z",
              SimulatedPlayer, class BlockPos const& a0, unsigned char a1)
{
    logger.info("SimulatedPlayer({})::simulateDestroyBlock", getName());
    auto rtn = original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
    return rtn;
}

TInstanceHook(void, "?simulateDisconnect@SimulatedPlayer@@QEAAXXZ",
              SimulatedPlayer)
{
    logger.info("SimulatedPlayer({})::simulateDisconnect", getName());
    original(this);
}

TInstanceHook(bool, "?simulateGiveItem@SimulatedPlayer@@QEAA_NAEAVItemStack@@_N@Z",
              SimulatedPlayer, class ItemStack& a0, bool a1)
{
    logger.info("SimulatedPlayer({})::simulateGiveItem", getName());
    auto rtn = original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
    return rtn;
}

TInstanceHook(bool, "?simulateInteract@SimulatedPlayer@@QEAA_NAEAVActor@@@Z",
              SimulatedPlayer, class Actor& a0)
{
    logger.info("SimulatedPlayer({})::simulateInteract", getName());
    auto rtn = original(this, std::forward<decltype(a0)>(a0));
    return rtn;
}

TInstanceHook(bool, "?simulateInteract@SimulatedPlayer@@QEAA_NAEBVBlockPos@@E@Z",
              SimulatedPlayer, class BlockPos const& a0, unsigned char a1)
{
    logger.info("SimulatedPlayer({})::simulateInteract", getName());
    auto rtn = original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
    return rtn;
}

TInstanceHook(bool, "?simulateInteract@SimulatedPlayer@@QEAA_NXZ",
              SimulatedPlayer)
{
    logger.info("SimulatedPlayer({})::simulateInteract", getName());
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(bool, "?simulateJump@SimulatedPlayer@@QEAA_NXZ",
              SimulatedPlayer)
{
    logger.info("SimulatedPlayer({})::simulateJump", getName());
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(void, "?simulateLocalMove@SimulatedPlayer@@QEAAXAEBVVec3@@M@Z",
              SimulatedPlayer, class Vec3 const& a0, float a1)
{
    logger.info("SimulatedPlayer({})::simulateLocalMove", getName());
    original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
}

TInstanceHook(void, "?simulateLookAt@SimulatedPlayer@@QEAAXAEAVActor@@@Z",
              SimulatedPlayer, class Actor& a0)
{
    logger.info("SimulatedPlayer({})::simulateLookAt", getName());
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?simulateLookAt@SimulatedPlayer@@QEAAXAEBVBlockPos@@@Z",
              SimulatedPlayer, class BlockPos const& a0)
{
    logger.info("SimulatedPlayer({})::simulateLookAt", getName());
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?simulateLookAt@SimulatedPlayer@@QEAAXAEBVVec3@@@Z",
              SimulatedPlayer, class Vec3 const& a0)
{
    logger.info("SimulatedPlayer({})::simulateLookAt", getName());
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?simulateMoveToLocation@SimulatedPlayer@@QEAAXAEBVVec3@@M@Z",
              SimulatedPlayer, class Vec3 const& a0, float a1)
{
    logger.info("SimulatedPlayer({})::simulateMoveToLocation", getName());
    original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
}

TInstanceHook(struct ScriptNavigationResult&, "?simulateNavigateToEntity@SimulatedPlayer@@QEAA?AUScriptNavigationResult@@AEAVActor@@M@Z",
              SimulatedPlayer, struct ScriptNavigationResult& ret, class Actor& a0, float a1)
{
    logger.info("SimulatedPlayer({})::simulateNavigateToEntity", getName());
    auto& rtn = original(this, ret, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
    return rtn;
}

TInstanceHook(struct ScriptNavigationResult&, "?simulateNavigateToLocation@SimulatedPlayer@@QEAA?AUScriptNavigationResult@@AEBVVec3@@M@Z",
              SimulatedPlayer, struct ScriptNavigationResult& ret, class Vec3 const& a0, float a1)
{
    logger.info("SimulatedPlayer({})::simulateNavigateToLocation", getName());
    auto& rtn = original(this, ret, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
    return rtn;
}

TInstanceHook(void, "?simulateNavigateToLocations@SimulatedPlayer@@QEAAX$$QEAV?$vector@VVec3@@V?$allocator@VVec3@@@std@@@std@@M@Z",
              SimulatedPlayer, std::vector<class Vec3>&& a0, float a1)
{
    logger.info("SimulatedPlayer({})::simulateNavigateToLocations", getName());
    original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
}

TInstanceHook(void, "?simulateSetBodyRotation@SimulatedPlayer@@QEAAXM@Z",
              SimulatedPlayer, float a0)
{
    logger.info("SimulatedPlayer({})::simulateSetBodyRotation", getName());
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(bool, "?simulateSetItem@SimulatedPlayer@@QEAA_NAEAVItemStack@@_NH@Z",
              SimulatedPlayer, class ItemStack& a0, bool a1, int a2)
{
    logger.info("SimulatedPlayer({})::simulateSetItem", getName());
    auto rtn = original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1), std::forward<decltype(a2)>(a2));
    return rtn;
}

TInstanceHook(void, "?simulateStopDestroyingBlock@SimulatedPlayer@@QEAAXXZ",
              SimulatedPlayer)
{
    logger.info("SimulatedPlayer({})::simulateStopDestroyingBlock", getName());
    original(this);
}

TInstanceHook(void, "?simulateStopInteracting@SimulatedPlayer@@QEAAXXZ",
              SimulatedPlayer)
{
    logger.info("SimulatedPlayer({})::simulateStopInteracting", getName());
    original(this);
}

TInstanceHook(void, "?simulateStopMoving@SimulatedPlayer@@QEAAXXZ",
              SimulatedPlayer)
{
    logger.info("SimulatedPlayer({})::simulateStopMoving", getName());
    original(this);
}

TInstanceHook(void, "?simulateStopUsingItem@SimulatedPlayer@@QEAAXXZ",
              SimulatedPlayer)
{
    logger.info("SimulatedPlayer({})::simulateStopUsingItem", getName());
    original(this);
}

TInstanceHook(bool, "?simulateUseItem@SimulatedPlayer@@QEAA_NAEAVItemStack@@@Z",
              SimulatedPlayer, class ItemStack& a0)
{
    logger.info("SimulatedPlayer({})::simulateUseItem", getName());
    auto rtn = original(this, std::forward<decltype(a0)>(a0));
    return rtn;
}

TInstanceHook(bool, "?simulateUseItemInSlot@SimulatedPlayer@@QEAA_NH@Z",
              SimulatedPlayer, int a0)
{
    logger.info("SimulatedPlayer({})::simulateUseItemInSlot", getName());
    auto rtn = original(this, std::forward<decltype(a0)>(a0));
    return rtn;
}

TInstanceHook(bool, "?simulateUseItemInSlotOnBlock@SimulatedPlayer@@QEAA_NHAEBVBlockPos@@EAEBVVec3@@@Z",
              SimulatedPlayer, int a0, class BlockPos const& a1, unsigned char a2, class Vec3 const& a3)
{
    logger.info("SimulatedPlayer({})::simulateUseItemInSlotOnBlock", getName());
    auto rtn = original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1), std::forward<decltype(a2)>(a2), std::forward<decltype(a3)>(a3));
    return rtn;
}

TInstanceHook(bool, "?simulateUseItemOnBlock@SimulatedPlayer@@QEAA_NAEAVItemStack@@AEBVBlockPos@@EAEBVVec3@@@Z",
              SimulatedPlayer, class ItemStack& a0, class BlockPos const& a1, unsigned char a2, class Vec3 const& a3)
{
    logger.info("SimulatedPlayer({})::simulateUseItemOnBlock", getName());
    auto rtn = original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1), std::forward<decltype(a2)>(a2), std::forward<decltype(a3)>(a3));
    return rtn;
}

TInstanceHook(void, "?simulateWorldMove@SimulatedPlayer@@QEAAXAEBVVec3@@M@Z",
              SimulatedPlayer, class Vec3 const& a0, float a1)
{
    logger.info("SimulatedPlayer({})::simulateWorldMove", getName());
    original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
}

// public.static : 2
// #include <MC/Bedrock.hpp>
// THook(class SimulatedPlayer*, "?create@SimulatedPlayer@@SAPEAV1@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEBVBlockPos@@V?$AutomaticID@VDimension@@H@@V?$not_null@V?$NonOwnerPointer@VServerNetworkHandler@@@Bedrock@@@gsl@@@Z",
//     std::string const& a0, class BlockPos const& a1, class AutomaticID<class Dimension, int> a2, gsl::not_null<class Bedrock::NonOwnerPointer<class ServerNetworkHandler> > a3){
//     logger.info("SimulatedPlayer::create");
//     auto rtn = original(std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1), std::forward<decltype(a2)>(a2), std::forward<decltype(a3)>(a3));
//     return rtn;
// }

THook(class SimulatedPlayer*, "?tryGetFromEntity@SimulatedPlayer@@SAPEAV1@AEAVEntityContext@@_N@Z",
      class EntityContext& a0, bool a1)
{
    logger.info("SimulatedPlayer::tryGetFromEntity");
    auto rtn = original(std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
    return rtn;
}

// virtual : 444
TInstanceHook(void, "?initializeComponents@SimulatedPlayer@@UEAAXW4InitializationMethod@Actor@@AEBVVariantParameterList@@@Z",
              SimulatedPlayer, enum Actor::InitializationMethod a0, class VariantParameterList const& a1)
{
    logger.info("SimulatedPlayer({})::initializeComponents", getName());
    original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
}

TInstanceHook(void, "?aiStep@SimulatedPlayer@@UEAAXXZ",
              SimulatedPlayer)
{
    logger.info("SimulatedPlayer({})::aiStep", getName());
    original(this);
}

// there are 4 functions with the same rva

// ?getAlternateContentKey@IContentKeyProvider@@UEBA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEBVContentIdentity@@@Z
// ?getLocalIp@LocalConnector@@UEAA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ
// ?getName@BlockActor@@UEBA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ
// ?getName@PrecompiledCommandOrigin@@UEBA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ

// TInstanceHook(std::string&, "?getXuid@SimulatedPlayer@@UEBA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ",
//     SimulatedPlayer, std::string& ret){
//     logger.info("SimulatedPlayer({})::getXuid", getName());
//     auto& rtn = original(this, ret);
//     return rtn;
// }

TInstanceHook(struct PlayerMovementSettings const&, "?getMovementSettings@SimulatedPlayer@@UEBAAEBUPlayerMovementSettings@@XZ",
              SimulatedPlayer)
{
    logger.info("SimulatedPlayer({})::getMovementSettings", getName());
    auto& rtn = original(this);
    return rtn;
}

#include <MC/ChunkViewSource.hpp>
TInstanceHook(std::shared_ptr<class ChunkViewSource>&, "?_createChunkSource@SimulatedPlayer@@MEAA?AV?$shared_ptr@VChunkViewSource@@@std@@AEAVChunkSource@@@Z",
              SimulatedPlayer, std::shared_ptr<class ChunkViewSource>& ret, class ChunkSource& a0)
{
    logger.info("SimulatedPlayer({})::_createChunkSource", getName());
    auto& rtn = original(this, ret, std::forward<decltype(a0)>(a0));
    return rtn;
}

// there are 23 functions with the same rva

// ?getArmorMaterialTextureTypeInSlot@Actor@@UEBA?AW4ArmorTextureType@@W4ArmorSlot@@@Z
// ?getArmorMaterialTypeInSlot@Actor@@UEBA?AW4ArmorMaterialType@@W4ArmorSlot@@@Z
// ?getBlockShape@ComponentItem@@UEBA?AW4BlockShape@@XZ
// ?getBlockShape@Item@@UEBA?AW4BlockShape@@XZ
// ?getBuildPlatform@AppPlatform@@UEBA?AW4BuildPlatform@@XZ
// ?getColor@AzaleaLeafBlock@@UEBAHAEAVBlockSource@@AEBVBlockPos@@AEBVBlock@@@Z
// ?getColor@BlockLegacy@@UEBAHAEAVBlockSource@@AEBVBlockPos@@AEBVBlock@@@Z
// ?getColor@BlockLegacy@@UEBAHAEBVBlock@@@Z
// ?getColor@Coral@@UEBAHAEAVBlockSource@@AEBVBlockPos@@AEBVBlock@@@Z
// ?getColor@Coral@@UEBAHAEBVBlock@@@Z
// ?getColor@CoralFan@@UEBAHAEAVBlockSource@@AEBVBlockPos@@AEBVBlock@@@Z
// ?getColor@CoralFan@@UEBAHAEBVBlock@@@Z
// ?getColor@SeaPickle@@UEBAHAEAVBlockSource@@AEBVBlockPos@@AEBVBlock@@@Z
// ?getColor@SeaPickle@@UEBAHAEBVBlock@@@Z
// ?getColorAtPos@BlockLegacy@@UEBAHAEAVBlockSource@@AEBVBlockPos@@@Z
// ?getEnchantSlot@EnchantedBookItem@@UEBAHXZ
// ?getFilteredStringIndex@ItemStackRequestAction@@UEBAHXZ
// ?getMaxSimultaneousServiceRequests@AppPlatform@@UEBAIXZ
// ?getResourceCount@Coral@@UEBAHAEAVRandomize@@AEBVBlock@@H@Z
// ?getResourceCount@FrogEggBlock@@UEBAHAEAVRandomize@@AEBVBlock@@H@Z

// TInstanceHook(int, "?_getSpawnChunkLimit@SimulatedPlayer@@MEBAHXZ",
//     SimulatedPlayer){
//     logger.info("SimulatedPlayer({})::_getSpawnChunkLimit", getName());
//     auto rtn = original(this);
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

// TInstanceHook(void, "?_updateChunkPublisherView@SimulatedPlayer@@MEAAXAEBVVec3@@M@Z",
//     SimulatedPlayer, class Vec3 const& a0, float a1){
//     logger.info("SimulatedPlayer({})::_updateChunkPublisherView", getName());
//     original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
// }

// virtual.unordered : 2
// there are 1048 functions with the same rva

// ?_Do_call@?$_Func_impl_no_alloc@V<lambda_22965a617e6ab392d6b1f1a7a48586ba>@@_NAEBVDefinitionInstanceGroup@@@std@@EEAA_NAEBVDefinitionInstanceGroup@@@Z
// ?_Do_call@?$_Func_impl_no_alloc@V<lambda_bac109946998141606a5d33732ab2465>@@_NAEBVDefinitionInstanceGroup@@@std@@EEAA_NAEBVDefinitionInstanceGroup@@@Z
// ?_allowAscendingScaffolding@Mob@@MEBA_NXZ
// ?_calculatePlacePos@DeprecatedSlabBlockItem@@UEBA_NAEAVItemStackBase@@AEAVActor@@AEAEAEAVBlockPos@@@Z
// ?_calculatePlacePos@Item@@EEBA_NAEAVItemStackBase@@AEAVActor@@AEAEAEAVBlockPos@@@Z
// ?_calculatePlacePos@SlabBlockItem@@UEBA_NAEAVItemStackBase@@AEAVActor@@AEAEAEAVBlockPos@@@Z
// ?_checkAgainstEventAllowlist@AggregationEventListener@Events@Social@@MEBA_NAEBVEvent@23@@Z
// ?_handleUnknownMember@FilterGroup@@MEAA_NAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEBVValue@Json@@@Z
// ?_isListenerReadyForEvents@AggregationEventListener@Events@Social@@MEBA_NXZ
// ?_isValidEnchantmentTypeForCategory@Enchant@@EEBA_NW4Type@1@@Z
// ?_makeFlySound@Parrot@@MEBA_NXZ
// ?_needsPostProcessing@PoolElementStructurePiece@@MEAA_NAEAVBlockSource@@@Z
// ?_playerCanUpdate@BlockActor@@MEBA_NAEBVPlayer@@@Z
// ?_read@?$ItemStackRequestActionDataless@$08@@MEAA_NAEAVReadOnlyBinaryStream@@@Z
// ?_read@ItemStackRequestActionCraftNonImplemented_DEPRECATEDASKTYLAING@@MEAA_NAEAVReadOnlyBinaryStream@@@Z
// ?_registerSystemObjects@ScriptEngine@@MEAA_NAEBVScriptObjectHandle@ScriptApi@@@Z
// ?_validate@?$JsonSchemaTypedNode@PEAVBiome@@V?$JsonParseState@V?$JsonParseState@V?$JsonParseState@V?$JsonParseState@VEmptyClass@JsonUtil@@U?$pair@V?$reference_wrapper@VBiome@@@std@@V?$reference_wrapper@VIWorldRegistriesProvider@@@2@@std@@@JsonUtil@@U?$pair@V?$reference_wrapper@VBiome@@@std@@V?$reference_wrapper@VIWorldRegistriesProvider@@@2@@std@@@JsonUtil@@V?$vector@U?$pair@PEAVBiome@@I@std@@V?$allocator@U?$pair@PEAVBiome@@I@std@@@2@@std@@@JsonUtil@@U?$pair@PEAVBiome@@I@std@@@JsonUtil@@PEAV1@@JsonUtil@@UEBA_NAEAV?$JsonParseState@V?$JsonParseState@V?$JsonParseState@V?$JsonParseState@V?$JsonParseState@VEmptyClass@JsonUtil@@U?$pair@V?$reference_wrapper@VBiome@@@std@@V?$reference_wrapper@VIWorldRegistriesProvider@@@2@@std@@@JsonUtil@@U?$pair@V?$reference_wrapper@VBiome@@@std@@V?$reference_wrapper@VIWorldRegistriesProvider@@@2@@std@@@JsonUtil@@V?$vector@U?$pair@PEAVBiome@@I@std@@V?$allocator@U?$pair@PEAVBiome@@I@std@@@2@@std@@@JsonUtil@@U?$pair@PEAVBiome@@I@std@@@JsonUtil@@PEAVBiome@@@2@_N@Z
// ?_validate@?$JsonSchemaTypedNode@PEAVBiome@@V?$JsonParseState@V?$JsonParseState@V?$JsonParseState@VEmptyClass@JsonUtil@@U?$pair@V?$reference_wrapper@VBiome@@@std@@V?$reference_wrapper@VIWorldRegistriesProvider@@@2@@std@@@JsonUtil@@U?$pair@V?$reference_wrapper@VBiome@@@std@@V?$reference_wrapper@VIWorldRegistriesProvider@@@2@@std@@@JsonUtil@@V?$vector@U?$pair@PEAVBiome@@I@std@@V?$allocator@U?$pair@PEAVBiome@@I@std@@@2@@std@@@JsonUtil@@PEAV1@@JsonUtil@@UEBA_NAEAV?$JsonParseState@V?$JsonParseState@V?$JsonParseState@V?$JsonParseState@VEmptyClass@JsonUtil@@U?$pair@V?$reference_wrapper@VBiome@@@std@@V?$reference_wrapper@VIWorldRegistriesProvider@@@2@@std@@@JsonUtil@@U?$pair@V?$reference_wrapper@VBiome@@@std@@V?$reference_wrapper@VIWorldRegistriesProvider@@@2@@std@@@JsonUtil@@V?$vector@U?$pair@PEAVBiome@@I@std@@V?$allocator@U?$pair@PEAVBiome@@I@std@@@2@@std@@@JsonUtil@@PEAVBiome@@@2@_N@Z
// ?_validate@?$JsonSchemaTypedNode@PEAVBiome@@V?$JsonParseState@V?$JsonParseState@VEmptyClass@JsonUtil@@U?$pair@V?$reference_wrapper@VBiome@@@std@@V?$reference_wrapper@VIWorldRegistriesProvider@@@2@@std@@@JsonUtil@@U?$pair@V?$reference_wrapper@VBiome@@@std@@V?$reference_wrapper@VIWorldRegistriesProvider@@@2@@std@@@JsonUtil@@PEAV1@@JsonUtil@@UEBA_NAEAV?$JsonParseState@V?$JsonParseState@V?$JsonParseState@VEmptyClass@JsonUtil@@U?$pair@V?$reference_wrapper@VBiome@@@std@@V?$reference_wrapper@VIWorldRegistriesProvider@@@2@@std@@@JsonUtil@@U?$pair@V?$reference_wrapper@VBiome@@@std@@V?$reference_wrapper@VIWorldRegistriesProvider@@@2@@std@@@JsonUtil@@PEAVBiome@@@2@_N@Z
// ?_validate@?$JsonSchemaTypedNode@PEAVStructureTemplate@@V?$JsonParseState@V?$JsonParseState@VEmptyClass@JsonUtil@@UFeatureRootParseContext@FeatureLoading@@@JsonUtil@@U?$ConcreteFeatureHolder@VStructureTemplateFeature@@@FeatureLoading@@@JsonUtil@@PEAV1@@JsonUtil@@UEBA_NAEAV?$JsonParseState@V?$JsonParseState@V?$JsonParseState@VEmptyClass@JsonUtil@@UFeatureRootParseContext@FeatureLoading@@@JsonUtil@@U?$ConcreteFeatureHolder@VStructureTemplateFeature@@@FeatureLoading@@@JsonUtil@@PEAVStructureTemplate@@@2@_N@Z

// TInstanceHook(bool, "?useNewAi@SimulatedPlayer@@UEBA_NXZ",
//     SimulatedPlayer){
//     logger.info("SimulatedPlayer({})::useNewAi", getName());
//     auto rtn = original(this);
//     return rtn;
// }

// there are 1048 functions with the same rva

// ?_Do_call@?$_Func_impl_no_alloc@V<lambda_22965a617e6ab392d6b1f1a7a48586ba>@@_NAEBVDefinitionInstanceGroup@@@std@@EEAA_NAEBVDefinitionInstanceGroup@@@Z
// ?_Do_call@?$_Func_impl_no_alloc@V<lambda_bac109946998141606a5d33732ab2465>@@_NAEBVDefinitionInstanceGroup@@@std@@EEAA_NAEBVDefinitionInstanceGroup@@@Z
// ?_allowAscendingScaffolding@Mob@@MEBA_NXZ
// ?_calculatePlacePos@DeprecatedSlabBlockItem@@UEBA_NAEAVItemStackBase@@AEAVActor@@AEAEAEAVBlockPos@@@Z
// ?_calculatePlacePos@Item@@EEBA_NAEAVItemStackBase@@AEAVActor@@AEAEAEAVBlockPos@@@Z
// ?_calculatePlacePos@SlabBlockItem@@UEBA_NAEAVItemStackBase@@AEAVActor@@AEAEAEAVBlockPos@@@Z
// ?_checkAgainstEventAllowlist@AggregationEventListener@Events@Social@@MEBA_NAEBVEvent@23@@Z
// ?_handleUnknownMember@FilterGroup@@MEAA_NAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEBVValue@Json@@@Z
// ?_isListenerReadyForEvents@AggregationEventListener@Events@Social@@MEBA_NXZ
// ?_isValidEnchantmentTypeForCategory@Enchant@@EEBA_NW4Type@1@@Z
// ?_makeFlySound@Parrot@@MEBA_NXZ
// ?_needsPostProcessing@PoolElementStructurePiece@@MEAA_NAEAVBlockSource@@@Z
// ?_playerCanUpdate@BlockActor@@MEBA_NAEBVPlayer@@@Z
// ?_read@?$ItemStackRequestActionDataless@$08@@MEAA_NAEAVReadOnlyBinaryStream@@@Z
// ?_read@ItemStackRequestActionCraftNonImplemented_DEPRECATEDASKTYLAING@@MEAA_NAEAVReadOnlyBinaryStream@@@Z
// ?_registerSystemObjects@ScriptEngine@@MEAA_NAEBVScriptObjectHandle@ScriptApi@@@Z
// ?_validate@?$JsonSchemaTypedNode@PEAVBiome@@V?$JsonParseState@V?$JsonParseState@V?$JsonParseState@V?$JsonParseState@VEmptyClass@JsonUtil@@U?$pair@V?$reference_wrapper@VBiome@@@std@@V?$reference_wrapper@VIWorldRegistriesProvider@@@2@@std@@@JsonUtil@@U?$pair@V?$reference_wrapper@VBiome@@@std@@V?$reference_wrapper@VIWorldRegistriesProvider@@@2@@std@@@JsonUtil@@V?$vector@U?$pair@PEAVBiome@@I@std@@V?$allocator@U?$pair@PEAVBiome@@I@std@@@2@@std@@@JsonUtil@@U?$pair@PEAVBiome@@I@std@@@JsonUtil@@PEAV1@@JsonUtil@@UEBA_NAEAV?$JsonParseState@V?$JsonParseState@V?$JsonParseState@V?$JsonParseState@V?$JsonParseState@VEmptyClass@JsonUtil@@U?$pair@V?$reference_wrapper@VBiome@@@std@@V?$reference_wrapper@VIWorldRegistriesProvider@@@2@@std@@@JsonUtil@@U?$pair@V?$reference_wrapper@VBiome@@@std@@V?$reference_wrapper@VIWorldRegistriesProvider@@@2@@std@@@JsonUtil@@V?$vector@U?$pair@PEAVBiome@@I@std@@V?$allocator@U?$pair@PEAVBiome@@I@std@@@2@@std@@@JsonUtil@@U?$pair@PEAVBiome@@I@std@@@JsonUtil@@PEAVBiome@@@2@_N@Z
// ?_validate@?$JsonSchemaTypedNode@PEAVBiome@@V?$JsonParseState@V?$JsonParseState@V?$JsonParseState@VEmptyClass@JsonUtil@@U?$pair@V?$reference_wrapper@VBiome@@@std@@V?$reference_wrapper@VIWorldRegistriesProvider@@@2@@std@@@JsonUtil@@U?$pair@V?$reference_wrapper@VBiome@@@std@@V?$reference_wrapper@VIWorldRegistriesProvider@@@2@@std@@@JsonUtil@@V?$vector@U?$pair@PEAVBiome@@I@std@@V?$allocator@U?$pair@PEAVBiome@@I@std@@@2@@std@@@JsonUtil@@PEAV1@@JsonUtil@@UEBA_NAEAV?$JsonParseState@V?$JsonParseState@V?$JsonParseState@V?$JsonParseState@VEmptyClass@JsonUtil@@U?$pair@V?$reference_wrapper@VBiome@@@std@@V?$reference_wrapper@VIWorldRegistriesProvider@@@2@@std@@@JsonUtil@@U?$pair@V?$reference_wrapper@VBiome@@@std@@V?$reference_wrapper@VIWorldRegistriesProvider@@@2@@std@@@JsonUtil@@V?$vector@U?$pair@PEAVBiome@@I@std@@V?$allocator@U?$pair@PEAVBiome@@I@std@@@2@@std@@@JsonUtil@@PEAVBiome@@@2@_N@Z
// ?_validate@?$JsonSchemaTypedNode@PEAVBiome@@V?$JsonParseState@V?$JsonParseState@VEmptyClass@JsonUtil@@U?$pair@V?$reference_wrapper@VBiome@@@std@@V?$reference_wrapper@VIWorldRegistriesProvider@@@2@@std@@@JsonUtil@@U?$pair@V?$reference_wrapper@VBiome@@@std@@V?$reference_wrapper@VIWorldRegistriesProvider@@@2@@std@@@JsonUtil@@PEAV1@@JsonUtil@@UEBA_NAEAV?$JsonParseState@V?$JsonParseState@V?$JsonParseState@VEmptyClass@JsonUtil@@U?$pair@V?$reference_wrapper@VBiome@@@std@@V?$reference_wrapper@VIWorldRegistriesProvider@@@2@@std@@@JsonUtil@@U?$pair@V?$reference_wrapper@VBiome@@@std@@V?$reference_wrapper@VIWorldRegistriesProvider@@@2@@std@@@JsonUtil@@PEAVBiome@@@2@_N@Z
// ?_validate@?$JsonSchemaTypedNode@PEAVStructureTemplate@@V?$JsonParseState@V?$JsonParseState@VEmptyClass@JsonUtil@@UFeatureRootParseContext@FeatureLoading@@@JsonUtil@@U?$ConcreteFeatureHolder@VStructureTemplateFeature@@@FeatureLoading@@@JsonUtil@@PEAV1@@JsonUtil@@UEBA_NAEAV?$JsonParseState@V?$JsonParseState@V?$JsonParseState@VEmptyClass@JsonUtil@@UFeatureRootParseContext@FeatureLoading@@@JsonUtil@@U?$ConcreteFeatureHolder@VStructureTemplateFeature@@@FeatureLoading@@@JsonUtil@@PEAVStructureTemplate@@@2@_N@Z

// TInstanceHook(bool, "?isSimulated@SimulatedPlayer@@UEBA_NXZ",
//     SimulatedPlayer){
//     logger.info("SimulatedPlayer({})::isSimulated", getName());
//     auto rtn = original(this);
//     return rtn;
// }

// vtbl_entry : 1

#endif // HOOK_CLASS_SimulatedPlayer
