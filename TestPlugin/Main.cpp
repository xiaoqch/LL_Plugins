#include "pch.h"
#include "TestRegRecipe.h"
#include <EventAPI.h>
#include "TestDBStorage.h"
#include "TestCommandReg.h"
#include "EnumGenerator.h"
#include "TestNbt.h"

LARGE_INTEGER freq_;
auto INITPERFORMANCE = QueryPerformanceFrequency(&freq_);

LARGE_INTEGER begin_time;
LARGE_INTEGER end_time;
inline double ns_time()
{
    return (end_time.QuadPart - begin_time.QuadPart) * 1000000.0 / freq_.QuadPart;
}

#define TestTimeLog(func, ...)            \
    QueryPerformanceCounter(&begin_time); \
    func(__VA_ARGS__);                    \
    QueryPerformanceCounter(&end_time);   \
    logger.warn("  {}\t time: {}", #func, ns_time());

#ifdef ENABLE_TEST_DLSYM

inline void static_query()
{
    dlsym_static("?EVENT_BEGIN@ActorDefinitionIdentifier@@2V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@B");
    dlsym_static("?$TSS0@?1??value@?$type_index@V?$sigh_storage_mixin@V?$basic_storage@W4ObjectHandleValue@Scripting@@VScriptFoodComponent@@V?$allocator@VScriptFoodComponent@@@std@@X@entt@@@entt@@X@entt@@SAIXZ@4HA");
    dlsym_static("?$TSS0@?1???$type_id@VCommandRegistry@@W4Mode@ExecuteCommand@@@@YA?AV?$typeid_t@VCommandRegistry@@@@XZ@4HA");
    dlsym_static("?value@?1??0?$type_index@V?$sigh_storage_mixin@V?$basic_storage@W4ObjectHandleValue@Scripting@@VScriptMovementBasicComponent@@V?$allocator@VScriptMovementBasicComponent@@@std@@X@entt@@@entt@@X@entt@@SAIXZ@4IB");
    dlsym_static("?mCrimsonFence@VanillaBlocks@@3PEBVBlock@@EB");
    dlsym_static("?$TSS0@?1???$type_id@VGoal@@VRandomSwimmingGoal@@@@YA?AV?$typeid_t@VGoal@@@@XZ@4HA");
    dlsym_static("?value@?1??0?$type_index@V?$shared_ptr@VFoodItemComponent@@@std@@X@entt@@SAIXZ@4IB");
    dlsym_static("?VERT_OFFHAND_MAP_POS@MapConstants@@3VVec3@@B");
    dlsym_static("?$TSS0@?4??meta_template_info@?$meta_node@V?$ScriptEventSignal@U?$TypedObjectHandle@UScriptChatEvent@@@Scripting@@@@@internal@entt@@CAPEAUmeta_template_node@34@XZ@4HA");
    dlsym_static("?$TSS0@?1??value@?$type_index@UOnExtractStateFrom@@X@entt@@SAIXZ@4HA");
    dlsym_static("?CMD_INPUT_UNICODE_TRANSLATE_MAP@CommandUtils@@3V?$vector@U?$pair@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@D@std@@V?$allocator@U?$pair@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@D@std@@@2@@std@@B");
    dlsym_static("?$TSS0@?1???$base@VItemComponent@@@?$meta_factory@VWeaponItemComponent@@@entt@@QEAA?A_PXZ@4HA");
    dlsym_static("?$TSS0@?1???$toNBT@W4CauldronLiquidType@@@StateSerializationUtils@@YA?AV?$unique_ptr@VTag@@U?$default_delete@VTag@@@std@@@std@@AEBW4CauldronLiquidType@@@Z@4HA");
    dlsym_static("?instance@?1???$type_id@VWeakLifetimeScope@Scripting@@@entt@@YAAEBVtype_info@1@XZ@4V21@A");
    dlsym_static("?mLitRedStoneLamp@VanillaBlockTypes@@3V?$WeakPtr@VBlockLegacy@@@@A");
    dlsym_static("?$TSS0@?1???$type_id@VIDefinitionInstance@@VHarvestFarmBlockDefinition@@@@YA?AV?$typeid_t@VIDefinitionInstance@@@@XZ@4HA");
    dlsym_static("?$TSS0@?1???$type_id@$$CBUSeatDescription@@@entt@@YAAEBVtype_info@1@XZ@4HA");
    dlsym_static("?handlerThunk@?1???$make_packet@VMobArmorEquipmentPacket@@@@YA?AV?$shared_ptr@VPacket@@@std@@XZ@4V?$PacketHandlerDispatcherInstance@VMobArmorEquipmentPacket@@$0A@@@A");
    dlsym_static("?instance@?1???$type_id@AEAVBasicLoader@@@entt@@YAAEBVtype_info@1@XZ@4V21@A");
    dlsym_static("?id@?1???$type_id@VGoal@@VBreedGoal@@@@YA?AV?$typeid_t@VGoal@@@@XZ@4V1@A");
    dlsym_static("?$TSS0@?1??resolve@?$meta_node@VScriptPromiseAny@Scripting@@@internal@entt@@SAPEAUmeta_type_node@34@XZ@4HA");
    dlsym_static("?instance@?1???$type_id@AEAV?$vector@UShooterAmmunitionEntry@ShooterItemComponent@@V?$allocator@UShooterAmmunitionEntry@ShooterItemComponent@@@std@@@std@@@entt@@YAAEBVtype_info@1@XZ@4V21@A");
    dlsym_static("?$TSS0@?1??resolve@?$meta_node@U?$meta_class_template_tag@Upair@std@@@entt@@@internal@entt@@SAPEAUmeta_type_node@34@XZ@4HA");
    dlsym_static("?mSeaGrass@VanillaBlocks@@3PEBVBlock@@EB");
    dlsym_static("?count@?$typeid_t@VCommandRegistry@@@@2GA");
    dlsym_static("?mElement26@VanillaBlocks@@3PEBVBlock@@EB");
    dlsym_static("?HARM@SharedBuffs@@2V?$shared_ptr@VAttributeBuff@@@std@@A");
    dlsym_static("?$TSS0@?1??value@?$type_index@V?$StrongTypedObjectHandle@VScriptGameTestConnectivity@@@Scripting@@X@entt@@SAIXZ@4HA");
    dlsym_static("?node@?1??resolve@?$meta_node@V?$_Vb_reference@U?$_Wrap_alloc@V?$allocator@I@std@@@std@@@std@@@internal@entt@@SAPEAUmeta_type_node@34@XZ@4U534@A");
    dlsym_static("?vtable@?1???$instance@U?$storage_adapter_mixin@V?$basic_storage@VEntityId@@VWardenSpawnTrackerComponent@@V?$allocator@VWardenSpawnTrackerComponent@@@std@@X@entt@@@entt@@@?$poly_vtable@U?$Storage@VEntityId@@@entt@@$0BA@$07@entt@@SAP6AAEBVtype_info@2@AEBV?$basic_any@$0BA@$07@2@@ZXZ@4V?$tuple@P6AAEBVtype_info@entt@@AEBV?$basic_any@$0BA@$07@2@@Z@std@@B");
    dlsym_static("?value@?1??0?$type_index@V?$FlagComponent@UActorInsideBlockTriggerFlag@@@@X@entt@@SAIXZ@4IB");
    dlsym_static("?mCyanCandleCake@VanillaBlockTypes@@3V?$WeakPtr@VBlockLegacy@@@@A");
    dlsym_static("?$TSS0@?1???$type_id@U?$meta_class_template_tag@Vunordered_map@std@@@entt@@@entt@@YAAEBVtype_info@1@XZ@4HA");
    dlsym_static("?$TSS0@?1???$type_id@AEAU?$storage_adapter_mixin@V?$basic_storage@VEntityId@@V?$FlagComponent@USaveSurroundingChunksFlag@@@@V?$allocator@V?$FlagComponent@USaveSurroundingChunksFlag@@@@@std@@X@entt@@@entt@@@entt@@YAAEBVtype_info@1@XZ@4HA");
    dlsym_static("?$TSS0@?1???$instance@U?$storage_adapter_mixin@V?$basic_storage@VEntityId@@VOutOfControlComponent@@V?$allocator@VOutOfControlComponent@@@std@@X@entt@@@entt@@@?$poly_vtable@U?$Storage@VEntityId@@@entt@@$0BA@$07@entt@@SAP6AAEBVtype_info@2@AEBV?$basic_any@$0BA@$07@2@@ZXZ@4HA");
    dlsym_static("?mTopSnow@VanillaBlocks@@3PEBVBlock@@EB");
    dlsym_static("?instance@?1???$type_id@AEAU?$storage_adapter_mixin@V?$basic_storage@VEntityId@@VInsideBlockNotifierComponent@@V?$allocator@VInsideBlockNotifierComponent@@@std@@X@entt@@@entt@@@entt@@YAAEBVtype_info@1@XZ@4V21@A");
    dlsym_static("?Low@OSThreadPriority@Threading@Bedrock@@2V123@B");
    dlsym_static("?mCoralFanHang3@VanillaBlocks@@3PEBVBlock@@EB");
    dlsym_static("?mLoomBlock@VanillaBlockTypes@@3V?$WeakPtr@VBlockLegacy@@@@A");
    dlsym_static("?$TSS0@?1???$type_id@AEAV?$array@M$02@std@@@entt@@YAAEBVtype_info@1@XZ@4HA");
    dlsym_static("?$TSS0@?1???$type_id@AEAU?$storage_adapter_mixin@V?$basic_storage@VEntityId@@UCraftingTableComponent@@V?$allocator@UCraftingTableComponent@@@std@@X@entt@@@entt@@@entt@@YAAEBVtype_info@1@XZ@4HA");
    dlsym_static("?$TSS0@?1??resolve@?$meta_node@VScriptRideableComponent@@@internal@entt@@SAPEAUmeta_type_node@34@XZ@4HA");
    dlsym_static("?node@?1???$conv@$MP6A?AV?$shared_ptr@UBlockComponentDescription@@@std@@AEBV?$shared_ptr@UBlockDisplayNameDescription@@@2@@Z1??$castToBaseType@UBlockDisplayNameDescription@@UBlockComponentDescription@@@CerealHelpers@@YA?AV12@0@Z@?$meta_factory@V?$shared_ptr@UBlockDisplayNameDescription@@@std@@@entt@@QEAA?AV12@XZ@4Umeta_conv_node@internal@2@A");
    dlsym_static("?PLAYER_ALIVE_HEIGHT@Player@@2MB");
    dlsym_static("?$TSS0@?1???$type_id@AEAU?$storage_adapter_mixin@V?$basic_storage@VEntityId@@VDanceComponent@@V?$allocator@VDanceComponent@@@std@@X@entt@@@entt@@@entt@@YAAEBVtype_info@1@XZ@4HA");
    dlsym_static("?$TSS0@?1???$instance@U?$storage_adapter_mixin@V?$basic_storage@VEntityId@@V?$ActorFlagComponent@UEnvironmentSensorFlag@@@@V?$allocator@V?$ActorFlagComponent@UEnvironmentSensorFlag@@@@@std@@X@entt@@@entt@@@?$poly_vtable@U?$Storage@VEntityId@@@entt@@$0BA@$07@entt@@SAP6AAEBVtype_info@2@AEBV?$basic_any@$0BA@$07@2@@ZXZ@4HA");
    dlsym_static("?$TSS0@?1??value@?$type_index@U?$storage_adapter_mixin@V?$basic_storage@VEntityId@@VUserEntityIdentifierComponent@@V?$allocator@VUserEntityIdentifierComponent@@@std@@X@entt@@@entt@@X@entt@@SAIXZ@4HA");
    dlsym_static("?$TSS0@?1??value@?$type_index@V?$unordered_map@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$shared_ptr@UBlockComponentDescription@@@2@U?$hash@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@U?$equal_to@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$shared_ptr@UBlockComponentDescription@@@2@@std@@@2@@std@@X@entt@@SAIXZ@4HA");
    dlsym_static("?$TSS0@?6???$data@$MPEQIconItemComponent@@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@0BI@$MPEQ1@V23@0BI@Uas_ref_t@entt@@@?$meta_factory@VIconItemComponent@@@entt@@QEAA?A_PI@Z@4HA");
    dlsym_static("?NUM_GROUPS_ON_NORMAL@Raid@@0EB");
    dlsym_static("?node@?4??meta_template_info@?$meta_node@V?$vector@_NV?$allocator@_N@std@@@std@@@internal@entt@@CAPEAUmeta_template_node@34@XZ@4U534@A");
    dlsym_static("?$TSS0@?1???$type_id@AEAVScriptMovementComponent@@@entt@@YAAEBVtype_info@1@XZ@4HA");
    dlsym_static("?value@?1??0?$type_index@V?$sigh_storage_mixin@V?$basic_storage@W4ObjectHandleValue@Scripting@@VScriptSimulatedPlayer@@V?$allocator@VScriptSimulatedPlayer@@@std@@X@entt@@@entt@@X@entt@@SAIXZ@4IB");
    dlsym_static("?node@?1???$base@VScriptActorComponent@@@?$meta_factory@VScriptMountTamingComponent@@@entt@@QEAA?A_PXZ@4Umeta_base_node@internal@2@A");
    dlsym_static("?$TSS0@?1???$type_id@AEAW4ArmorTextureType@@@entt@@YAAEBVtype_info@1@XZ@4HA");
    dlsym_static("?instance@?1???$type_id@AEAUScriptBlockExplodedEvent@@@entt@@YAAEBVtype_info@1@XZ@4V21@A");
    dlsym_static("?instance@?1???$type_id@AEAVScriptMovementSwayComponent@@@entt@@YAAEBVtype_info@1@XZ@4V21@A");
    dlsym_static("?node@?1???$base@VItemComponent@@@?$meta_factory@VEntityPlacerItemComponent@@@entt@@QEAA?A_PXZ@4Umeta_base_node@internal@2@A");
    dlsym_static("?$TSS0@?1???$instance@V?$sigh_storage_mixin@V?$basic_storage@W4ObjectHandleValue@Scripting@@VScriptStringBlockProperty@@V?$allocator@VScriptStringBlockProperty@@@std@@X@entt@@@entt@@@?$poly_vtable@U?$Storage@W4ObjectHandleValue@Scripting@@@entt@@$0BA@$07@entt@@SAP6AAEBVtype_info@2@AEBV?$basic_any@$0BA@$07@2@@ZXZ@4HA");
    dlsym_static("?$TSS0@?1??value@?$type_index@V?$sigh_storage_mixin@V?$basic_storage@W4ObjectHandleValue@Scripting@@VScriptMovementGenericComponent@@V?$allocator@VScriptMovementGenericComponent@@@std@@X@entt@@@entt@@X@entt@@SAIXZ@4HA");
    dlsym_static("?mPiglin@BannerPattern@@2PEAV1@EA");
    dlsym_static("?mLitRedStoneTorch@VanillaBlockTypes@@3V?$WeakPtr@VBlockLegacy@@@@A");
    dlsym_static("?$TSS0@?4??meta_template_info@?$meta_node@U?$hash@VHashedString@@@std@@@internal@entt@@CAPEAUmeta_template_node@34@XZ@4HA");
    dlsym_static("?value@?1??0?$type_index@V?$shared_ptr@VThrowableItemComponent@@@std@@X@entt@@SAIXZ@4IB");
    dlsym_static("?property@?1???$assign@$0A@@?$meta_factory@VRenderOffsetsItemComponent@@V1@@entt@@AEAAXVmeta_any@2@0@Z@4PAV32@A");
    dlsym_static("?node@?1???$func@$MQ8SaturationModifier@FoodItemComponent@@EBA_NAEAVBasicSaver@@AEBUSerializerTraits@@@Z1?Serialize@12@QEBA_N01@ZUas_is_t@entt@@@?$meta_factory@VSaturationModifier@FoodItemComponent@@@entt@@QEAA?A_PI@Z@4Umeta_func_node@internal@2@A");
    dlsym_static("?node@?1???$func@$MQ8ExpressionNode@@EAA_NAEAVBasicLoader@@AEBUSerializerTraits@@AEBVBedrockLoadContext@@@Z1?deserialize@1@QEAA_N012@ZUas_is_t@entt@@@?$meta_factory@VExpressionNode@@@entt@@QEAA?A_PI@Z@4Umeta_func_node@internal@2@A");
    dlsym_static("?MAX_HEALTH_CAP_UUID@WitherBoss@@2VUUID@mce@@B");
    dlsym_static("?ABSORPTION@SharedAmplifiers@@2V?$shared_ptr@VAmplifier@@@std@@A");
    dlsym_static("?vtable@?1???$instance@V?$sigh_storage_mixin@V?$basic_storage@W4ObjectHandleValue@Scripting@@VScriptItemDurabilityComponent@@V?$allocator@VScriptItemDurabilityComponent@@@std@@X@entt@@@entt@@@?$poly_vtable@U?$Storage@W4ObjectHandleValue@Scripting@@@entt@@$0BA@$07@entt@@SAP6AAEBVtype_info@2@AEBV?$basic_any@$0BA@$07@2@@ZXZ@4V?$tuple@P6AAEBVtype_info@entt@@AEBV?$basic_any@$0BA@$07@2@@Z@std@@B");
    dlsym_static("?instance@?1???$type_id@AEAVScriptPlayerInventoryComponentContainer@@@entt@@YAAEBVtype_info@1@XZ@4V21@A");
    dlsym_static("?value@?1??0?$type_index@U?$storage_adapter_mixin@V?$basic_storage@VEntityId@@UBlockQueuedTickingComponent@@V?$allocator@UBlockQueuedTickingComponent@@@std@@X@entt@@@entt@@X@entt@@SAIXZ@4IB");
    dlsym_static("?mLog2@VanillaBlocks@@3PEBVBlock@@EB");
    dlsym_static("?Sign@VanillaItemTags@@2QBDB");
    dlsym_static("?node@?4??meta_template_info@?$meta_node@V?$map@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$shared_ptr@VItemComponent@@@2@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$shared_ptr@VItemComponent@@@2@@std@@@2@@std@@@internal@entt@@CAPEAUmeta_template_node@34@XZ@4U534@A");
    dlsym_static("?node@?4??meta_template_info@?$meta_node@V?$shared_ptr@VRecordItemComponent@@@std@@@internal@entt@@CAPEAUmeta_template_node@34@XZ@4U534@A");
    dlsym_static("?mSoulCampfire@VanillaBlocks@@3PEBVBlock@@EB");
    dlsym_static("?instance@?1???$type_id@AEAU?$storage_adapter_mixin@V?$basic_storage@VEntityId@@VOverworldHeightAttributes@@V?$allocator@VOverworldHeightAttributes@@@std@@X@entt@@@entt@@@entt@@YAAEBVtype_info@1@XZ@4V21@A");
    dlsym_static("?node@?1??resolve@?$meta_node@U?$TypedObjectHandle@UScriptActorAddEffectEvent@@@Scripting@@@internal@entt@@SAPEAUmeta_type_node@34@XZ@4U534@A");
    dlsym_static("?mGlazedTerracottaPink@VanillaBlocks@@3PEBVBlock@@EB");
    dlsym_static("?id@?1???$type_id@VIDefinitionInstance@@VDryingOutTimerDefinition@DryingOutTimerComponent@@@@YA?AV?$typeid_t@VIDefinitionInstance@@@@XZ@4V1@A");
    dlsym_static("?MOVEMENT_SPEED@SharedModifiers@@2V?$shared_ptr@VAttributeModifier@@@std@@A");
    dlsym_static("?instance@?1???$type_id@$$CB_N@entt@@YAAEBVtype_info@1@XZ@4V21@A");
    dlsym_static("?$TSS1@?1???$assign@$0A@@?$meta_factory@VDiggerItemComponent@@V1@@entt@@AEAAXVmeta_any@2@0@Z@4HA");
    dlsym_static("?$TSS0@?1???$type_id@V?$allocator@VDefinitionTrigger@@@std@@@entt@@YAAEBVtype_info@1@XZ@4HA");
    dlsym_static("?value@?1??0?$type_index@VScriptBlockPistonComponent@@X@entt@@SAIXZ@4IB");
    dlsym_static("?mPolishedBlackstoneStairs@VanillaBlockTypes@@3V?$WeakPtr@VBlockLegacy@@@@A");
    dlsym_static("?mSlimeBlock@VanillaBlocks@@3PEBVBlock@@EB");
    dlsym_static("?value@?1??0?$type_index@VBodyControlComponent@@X@entt@@SAIXZ@4IB");
    dlsym_static("?instance@?1???$type_id@AEAV?$sigh_storage_mixin@V?$basic_storage@W4entity@entt@@UtempLevelComponent@WORKAROUNDS@ScriptApi@@V?$allocator@UtempLevelComponent@WORKAROUNDS@ScriptApi@@@std@@X@entt@@@entt@@@entt@@YAAEBVtype_info@1@XZ@4V21@A");
    dlsym_static("?GLB_EXTENSION@glTFExporter@@2V?$basic_string_span@$$CBD$0?0@gsl@@B");
    dlsym_static("?$TSS0@?1??value@?$type_index@U?$storage_adapter_mixin@V?$basic_storage@VEntityId@@VLootComponent@@V?$allocator@VLootComponent@@@std@@X@entt@@@entt@@X@entt@@SAIXZ@4HA");
    dlsym_static("?$TSS1@?1???$assign@$0A@@?$meta_factory@VThrowableItemComponent@@U?$integral_constant@PEQThrowableItemComponent@@_N$0CE@@std@@U23@@entt@@AEAAXVmeta_any@2@0@Z@4HA");
    dlsym_static("?$TSS0@?1??value@?$type_index@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@VHashedString@@@std@@@std@@@std@@X@entt@@SAIXZ@4HA");
    dlsym_static("?mElement104@VanillaBlocks@@3PEBVBlock@@EB");
    dlsym_static("?mStoneBrickStairs@VanillaBlockTypes@@3V?$WeakPtr@VBlockLegacy@@@@A");
    dlsym_static("?mLightBlueCandleCake@VanillaBlockTypes@@3V?$WeakPtr@VBlockLegacy@@@@A");
    dlsym_static("?BrewingStandSlotABit@VanillaStates@@3V?$ItemStateVariant@_N@@B");
    dlsym_static("?node@?1???$assign@$0A@@?$meta_factory@UBlockFlammableDescription@@U?$integral_constant@PEQBlockFlammableDescription@@H$07@std@@U23@@entt@@AEAAXVmeta_any@2@0@Z@4Umeta_prop_node@internal@2@A");
    dlsym_static("?instance@?1???$type_id@AEBUActorDefinitionIdentifier@@@entt@@YAAEBVtype_info@1@XZ@4V21@A");
    dlsym_static("?$TSS0@?1???$type_id@V?$_Vb_const_iterator@U?$_Wrap_alloc@V?$allocator@I@std@@@std@@@std@@@entt@@YAAEBVtype_info@1@XZ@4HA");
    dlsym_static("?node@?1???$assign@$0A@@?$meta_factory@VIconItemComponent@@U?$integral_constant@PEQIconItemComponent@@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@$0DI@@std@@U23@@entt@@AEAAXVmeta_any@2@0@Z@4Umeta_prop_node@internal@2@A");
    dlsym_static("?$TSS0@?1???$type_id@$$CBV?$TypedScriptClosure@$$A6AXU?$TypedObjectHandle@UScriptBeforePistonActionEvent@@@Scripting@@@Z$$V@Scripting@@@entt@@YAAEBVtype_info@1@XZ@4HA");
    dlsym_static("?node@?4??meta_template_info@?$meta_node@V?$Result@VVec3@@@Scripting@@@internal@entt@@CAPEAUmeta_template_node@34@XZ@4U534@A");
    dlsym_static("?DEFAULT_DISTANCE_WEATHER_SETTING@FogDefinition@@2UFogDistanceSetting@@B");
    dlsym_static("?value@?1??0?$type_index@V?$TagsComponent@U?$IDType@ULevelTagSetIDType@@@@@@X@entt@@SAIXZ@4IB");
    dlsym_static("?$TSS0@?1???$type_id@AEAV?$ScriptEventSignal@U?$TypedObjectHandle@UScriptBeforePistonActionEvent@@@Scripting@@@@@entt@@YAAEBVtype_info@1@XZ@4HA");
    dlsym_static("?$TSS1@?1???$assign@$0A@@?$meta_factory@UBlockGeometryDescription@@U1@@entt@@AEAAXVmeta_any@2@0@Z@4HA");
    dlsym_static("?value@?1??0?$type_index@V?$sigh_storage_mixin@V?$basic_storage@W4ObjectHandleValue@Scripting@@VScriptFoodComponent@@V?$allocator@VScriptFoodComponent@@@std@@X@entt@@@entt@@X@entt@@SAIXZ@4IB");
    dlsym_static("?MIN_DELTA_TO_JUMP@MoveControl@@2MB");
    dlsym_static("?value@?1??0?$type_index@V?$sigh_storage_mixin@V?$basic_storage@W4ObjectHandleValue@Scripting@@U?$PointerStorageComponent@UScriptBeforeChatEvent@@@internal@2@V?$allocator@U?$PointerStorageComponent@UScriptBeforeChatEvent@@@internal@Scripting@@@std@@X@entt@@@entt@@X@entt@@SAIXZ@4IB");
    dlsym_static("?vtable@?1???$instance@U?$storage_adapter_mixin@V?$basic_storage@VEntityId@@UBlockRandomTickingComponent@@V?$allocator@UBlockRandomTickingComponent@@@std@@X@entt@@@entt@@@?$poly_vtable@U?$Storage@VEntityId@@@entt@@$0BA@$07@entt@@SAP6AAEBVtype_info@2@AEBV?$basic_any@$0BA@$07@2@@ZXZ@4V?$tuple@P6AAEBVtype_info@entt@@AEBV?$basic_any@$0BA@$07@2@@Z@std@@B");
    dlsym_static("?instance@?1???$type_id@AEAVItemComponent@@@entt@@YAAEBVtype_info@1@XZ@4V21@A");
    dlsym_static("?value@?1??0?$type_index@V?$sigh_storage_mixin@V?$basic_storage@W4ObjectHandleValue@Scripting@@UKey@ScriptActor@@V?$allocator@UKey@ScriptActor@@@std@@X@entt@@@entt@@X@entt@@SAIXZ@4IB");
    dlsym_static("?instance@?1???$type_id@$$CBVScriptNavigationWalkComponent@@@entt@@YAAEBVtype_info@1@XZ@4V21@A");
    dlsym_static("?mRedStoneDust@VanillaBlocks@@3PEBVBlock@@EB");
    dlsym_static("?escape@?1???$ParseStringToStream@$0A@U?$UTF8@D@rapidjson@@U12@U?$GenericStringStream@U?$UTF8@D@rapidjson@@@2@V?$StackStream@D@?$GenericReader@U?$UTF8@D@rapidjson@@U12@VCrtAllocator@2@@2@@?$GenericReader@U?$UTF8@D@rapidjson@@U12@VCrtAllocator@2@@rapidjson@@AEAAXAEAU?$GenericStringStream@U?$UTF8@D@rapidjson@@@2@AEAV?$StackStream@D@12@_N@Z@4QBDB");
    dlsym_static("?value@?1??0?$type_index@U?$storage_adapter_mixin@V?$basic_storage@VEntityId@@VEquippableComponent@@V?$allocator@VEquippableComponent@@@std@@X@entt@@@entt@@X@entt@@SAIXZ@4IB");
    dlsym_static("?$TSS0@?1??resolve@?$meta_node@VKnockbackResistanceItemComponent@@@internal@entt@@SAPEAUmeta_type_node@34@XZ@4HA");
    dlsym_static("?MAP_PLAYER_PITCH_SCALE@MapConstants@@3MB");
    dlsym_static("?$TSS0@?1???$make_packet@VClientCacheBlobStatusPacket@@@@YA?AV?$shared_ptr@VPacket@@@std@@XZ@4HA");
    dlsym_static("?mRedNetherBrickStairs@VanillaBlocks@@3PEBVBlock@@EB");
    dlsym_static("?id@?1???$type_id@VIDefinitionInstance@@VDefinition@RamAttackGoal@@@@YA?AV?$typeid_t@VIDefinitionInstance@@@@XZ@4V1@A");
    dlsym_static("?$TSS0@?1???$type_id@$$CBV?$vector@VBlockDescriptor@@V?$allocator@VBlockDescriptor@@@std@@@std@@@entt@@YAAEBVtype_info@1@XZ@4HA");
    dlsym_static("?$TSS0@?1???$type_id@AEAV?$vector@UGameTestResult@@V?$allocator@UGameTestResult@@@std@@@std@@@entt@@YAAEBVtype_info@1@XZ@4HA");
    dlsym_static("?$TSS0@?1??resolve@?$meta_node@UScriptExplosionOptions@@@internal@entt@@SAPEAUmeta_type_node@34@XZ@4HA");
    dlsym_static("?$TSS0@?1???$type_id@$$CBVArmorItemComponent@@@entt@@YAAEBVtype_info@1@XZ@4HA");
    dlsym_static("?instance@?1???$type_id@U?$TypedObjectHandle@UScriptWeatherChangedEvent@@@Scripting@@@entt@@YAAEBVtype_info@1@XZ@4V21@A");
    dlsym_static("?id@?1???$type_id@VIDefinitionInstance@@UIsStunnedDefinition@@@@YA?AV?$typeid_t@VIDefinitionInstance@@@@XZ@4V1@A");
    dlsym_static("?mAllReferenceObjects@?$ServiceLocator@VSessionInfoManager@Bedrock@@@@0U?$atomic@_K@std@@A");
    dlsym_static("?$TSS0@?1???$instance@V?$sigh_storage_mixin@V?$basic_storage@W4ObjectHandleValue@Scripting@@U?$PointerStorageComponent@UScriptActorEvent@@@internal@2@V?$allocator@U?$PointerStorageComponent@UScriptActorEvent@@@internal@Scripting@@@std@@X@entt@@@entt@@@?$poly_vtable@U?$Storage@W4ObjectHandleValue@Scripting@@@entt@@$0BA@$07@entt@@SAP6AAEBVtype_info@2@AEBV?$basic_any@$0BA@$07@2@@ZXZ@4HA");
    dlsym_static("?value@?1??0?$type_index@_NX@entt@@SAIXZ@4IB");
    dlsym_static("?$TSS0@?4??meta_template_info@?$meta_node@V?$StrongTypedObjectHandle@VScriptItemStack@@@Scripting@@@internal@entt@@CAPEAUmeta_template_node@34@XZ@4HA");
    dlsym_static("?$TSS0@?1??resolve@?$meta_node@V?$vector@VStrongObjectHandle@Scripting@@V?$allocator@VStrongObjectHandle@Scripting@@@std@@@std@@@internal@entt@@SAPEAUmeta_type_node@34@XZ@4HA");
    dlsym_static("?mGoldOre@VanillaBlockTypes@@3V?$WeakPtr@VBlockLegacy@@@@A");
    dlsym_static("?value@?1??0?$type_index@USurfaceMaterialAttributes@@X@entt@@SAIXZ@4IB");
    dlsym_static("?MAP_LEFTHAND_ROT@MapConstants@@3VVec3@@B");
    dlsym_static("?$TSS0@?1???$instance@V?$sigh_storage_mixin@V?$basic_storage@W4ObjectHandleValue@Scripting@@VScriptWorld@@V?$allocator@VScriptWorld@@@std@@X@entt@@@entt@@@?$poly_vtable@U?$Storage@W4ObjectHandleValue@Scripting@@@entt@@$0BA@$07@entt@@SAP6AAEBVtype_info@2@AEBV?$basic_any@$0BA@$07@2@@ZXZ@4HA");
    dlsym_static("?$TSS0@?1??value@?$type_index@U?$storage_adapter_mixin@V?$basic_storage@VEntityId@@VDebugInfoComponent@@V?$allocator@VDebugInfoComponent@@@std@@X@entt@@@entt@@X@entt@@SAIXZ@4HA");
    dlsym_static("?$TSS0@?1???$type_id@AEAU?$storage_adapter_mixin@V?$basic_storage@VEntityId@@VBarterComponent@@V?$allocator@VBarterComponent@@@std@@X@entt@@@entt@@@entt@@YAAEBVtype_info@1@XZ@4HA");
    dlsym_static("?$TSS0@?1???$base@VItemComponent@@@?$meta_factory@VWearableItemComponent@@@entt@@QEAA?A_PXZ@4HA");
    dlsym_static("?DEFAULT_MUTATION_RATE@GeneticsDefinition@@0MB");
    dlsym_static("?$TSS0@?1???$type_id@U?$TypedObjectHandle@VScriptItemDurabilityComponent@@@Scripting@@@entt@@YAAEBVtype_info@1@XZ@4HA");
    dlsym_static("?value@?1??0?$type_index@VCustomMapFoliageColorAttributes@@X@entt@@SAIXZ@4IB");
    dlsym_static("?$TSS0@?1??value@?$type_index@V?$allocator@_N@std@@X@entt@@SAIXZ@4HA");
    dlsym_static("?value@?1??0?$type_index@V?$map@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@VExpressionNode@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@VExpressionNode@@@std@@@2@@std@@X@entt@@SAIXZ@4IB");
    dlsym_static("?instance@?1???$type_id@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@@entt@@YAAEBVtype_info@1@XZ@4V21@A");
    dlsym_static("?vtable@?1???$instance@U?$storage_adapter_mixin@V?$basic_storage@VEntityId@@VAgeableComponent@@V?$allocator@VAgeableComponent@@@std@@X@entt@@@entt@@@?$poly_vtable@U?$Storage@VEntityId@@@entt@@$0BA@$07@entt@@SAP6AAEBVtype_info@2@AEBV?$basic_any@$0BA@$07@2@@ZXZ@4V?$tuple@P6AAEBVtype_info@entt@@AEBV?$basic_any@$0BA@$07@2@@Z@std@@B");
    dlsym_static("?mMayTakeIsSetup@EnderMan@@0_NA");
    dlsym_static("?mMesaRock@VanillaBiomes@@2PEAVBiome@@EA");
    dlsym_static("?mGlazedTerracottaCyan@VanillaBlocks@@3PEBVBlock@@EB");
    dlsym_static("?$TSS0@?1???$func@$MQ8SaturationModifier@FoodItemComponent@@EBA_NAEAVBasicSaver@@AEBUSerializerTraits@@@Z1?Serialize@12@QEBA_N01@ZUas_is_t@entt@@@?$meta_factory@VSaturationModifier@FoodItemComponent@@@entt@@QEAA?A_PI@Z@4HA");
    dlsym_static("?$TSS0@?1???$type_id@AEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@entt@@YAAEBVtype_info@1@XZ@4HA");
    dlsym_static("?$TSS0@?1???$instance@U?$storage_adapter_mixin@V?$basic_storage@VEntityId@@UOnPlayerDestroyedTrigger@@V?$allocator@UOnPlayerDestroyedTrigger@@@std@@X@entt@@@entt@@@?$poly_vtable@U?$Storage@VEntityId@@@entt@@$0BA@$07@entt@@SAP6AAEBVtype_info@2@AEBV?$basic_any@$0BA@$07@2@@ZXZ@4HA");
    dlsym_static("?instance@?1???$type_id@U?$TypedObjectHandle@UScriptExplosionOptions@@@Scripting@@@entt@@YAAEBVtype_info@1@XZ@4V21@A");
    dlsym_static("?$TSS1@?1???$assign@$0A@@?$meta_factory@UVolumeBoundsDefinition@@U?$integral_constant@PEQVolumeBoundsDefinition@@VBlockPos@@$0M@@std@@U23@@entt@@AEAAXVmeta_any@2@0@Z@4HA");
    dlsym_static("?$TSS0@?1???$type_id@$$CBUOnActorLeaveVolumeDefinition@@@entt@@YAAEBVtype_info@1@XZ@4HA");
    dlsym_static("?$TSS0@?1???$assign@$0A@@?$meta_factory@VShooterItemComponent@@U?$integral_constant@PEQShooterItemComponent@@M$0DA@@std@@U23@@entt@@AEAAXVmeta_any@2@0@Z@4HA");
    dlsym_static("?$TSS0@?1???$toNBT@W4LeverDirection@@@StateSerializationUtils@@YA?AV?$unique_ptr@VTag@@U?$default_delete@VTag@@@std@@@std@@AEBW4LeverDirection@@@Z@4HA");
    dlsym_static("?$TSS0@?1??value@?$type_index@UScriptBeforeChatEvent@@X@entt@@SAIXZ@4HA");
    dlsym_static("?$TSS0@?1???$assign@$0A@@?$meta_factory@UVolumeDefinition@@U1@@entt@@AEAAXVmeta_any@2@0@Z@4HA");
    dlsym_static("?$TSS0@?1???$type_id@AEAU?$storage_adapter_mixin@V?$basic_storage@VEntityId@@UBlockRotationComponent@@V?$allocator@UBlockRotationComponent@@@std@@X@entt@@@entt@@@entt@@YAAEBVtype_info@1@XZ@4HA");
    dlsym_static("?$TSS0@?1???$type_id@VGoal@@VHoverGoal@@@@YA?AV?$typeid_t@VGoal@@@@XZ@4HA");
    dlsym_static("?node@?4??meta_template_info@?$meta_node@V?$TypedScriptClosure@$$A6A_NU?$TypedObjectHandle@VScriptActor@@@Scripting@@@Z$$V@Scripting@@@internal@entt@@CAPEAUmeta_template_node@34@XZ@4U534@A");
    dlsym_static("?HangingActor@VanillaItemTags@@2QBDB");
    dlsym_static("?node@?1???$conv@$MP6A?AV?$shared_ptr@UBlockComponentDescription@@@std@@AEBV?$shared_ptr@UBlockDestroyTimeDescription@@@2@@Z1??$castToBaseType@UBlockDestroyTimeDescription@@UBlockComponentDescription@@@CerealHelpers@@YA?AV12@0@Z@?$meta_factory@V?$shared_ptr@UBlockDestroyTimeDescription@@@std@@@entt@@QEAA?AV12@XZ@4Umeta_conv_node@internal@2@A");
    dlsym_static("?node@?1???$conv@$MP6AHW4GameTestFluidType@@@Z1??$constructUnderlyingType@H@?$EnumBindingBuilder@W4GameTestFluidType@@@Scripting@@SAH0@Z@?$meta_factory@W4GameTestFluidType@@@entt@@QEAA?AV12@XZ@4Umeta_conv_node@internal@2@A");
    dlsym_static("?$TSS0@?1???$type_id@VGoal@@VRandomHoverGoal@@@@YA?AV?$typeid_t@VGoal@@@@XZ@4HA");
    dlsym_static("?FUNCTION_NAME_SOFTENUM_NAME@CommandRegistry@@2PEBDEB");
    dlsym_static("?mBeehive@VanillaBlockTypes@@3V?$WeakPtr@VBlockLegacy@@@@A");
    dlsym_static("?$TSS0@?1??resolve@?$meta_node@U?$TypedObjectHandle@VScriptItemDurabilityComponent@@@Scripting@@@internal@entt@@SAPEAUmeta_type_node@34@XZ@4HA");
    dlsym_static("?$TSS0@?1???$base@VScriptActorComponent@@@?$meta_factory@VScriptMovementJumpComponent@@@entt@@QEAA?A_PXZ@4HA");
    dlsym_static("?value@?1??0?$type_index@U?$storage_adapter_mixin@V?$basic_storage@VEntityId@@VOutOfControlComponent@@V?$allocator@VOutOfControlComponent@@@std@@X@entt@@@entt@@X@entt@@SAIXZ@4IB");
    dlsym_static("?$TSS0@?1???$type_id@VScriptMovementJumpComponent@@@entt@@YAAEBVtype_info@1@XZ@4HA");
    dlsym_static("?$TSS0@?6???$data@$MPEQVolumeBoundsDefinition@@VBlockPos@@0M@$MPEQ1@V2@0M@Uas_ref_t@entt@@@?$meta_factory@UVolumeBoundsDefinition@@@entt@@QEAA?A_PI@Z@4HA");
    dlsym_static("?instance@?1???$type_id@AEAVScriptNavigationClimbComponent@@@entt@@YAAEBVtype_info@1@XZ@4V21@A");
    dlsym_static("?value@?1??0?$type_index@U?$TypedObjectHandle@VScriptGameTestConnectivity@@@Scripting@@X@entt@@SAIXZ@4IB");
    dlsym_static("?mWoodenDoorBirch@VanillaBlockTypes@@3V?$WeakPtr@VBlockLegacy@@@@A");
    dlsym_static("?node@?1??resolve@?$meta_node@V?$Result@V?$StrongTypedObjectHandle@VScriptBlock@@@Scripting@@@Scripting@@@internal@entt@@SAPEAUmeta_type_node@34@XZ@4U534@A");
    dlsym_static("?node@?1??resolve@?$meta_node@V?$TypedScriptClosure@$$A6AXXZ$$V@Scripting@@@internal@entt@@SAPEAUmeta_type_node@34@XZ@4U534@A");
    dlsym_static("?$TSS0@?1???$type_id@AEAU?$storage_adapter_mixin@V?$basic_storage@VEntityId@@V?$WeightedBiomeAttributes@UMutateBiomeTransformation@@@@V?$allocator@V?$WeightedBiomeAttributes@UMutateBiomeTransformation@@@@@std@@X@entt@@@entt@@@entt@@YAAEBVtype_info@1@XZ@4HA");
    dlsym_static("?$TSS0@?1???$type_id@$$CBV?$TypedScriptClosure@$$A6AXU?$TypedObjectHandle@VScriptGameTestHelper@@@Scripting@@@Z$$V@Scripting@@@entt@@YAAEBVtype_info@1@XZ@4HA");
    dlsym_static("?$TSS0@?1???$base@VScriptComponent@@@?$meta_factory@VScriptAgeableComponent@@@entt@@QEAA?A_PXZ@4HA");
    dlsym_static("?mCopperOre@VanillaBlockTypes@@3V?$WeakPtr@VBlockLegacy@@@@A");
    dlsym_static("?$TSS0@?1??value@?$type_index@VFreezingComponent@@X@entt@@SAIXZ@4HA");
    dlsym_static("?$TSS0@?1??value@?$type_index@V?$TypedScriptClosure@$$A6AXU?$TypedObjectHandle@UScriptChatEvent@@@Scripting@@@Z$$V@Scripting@@X@entt@@SAIXZ@4HA");
    dlsym_static("?value@?1??0?$type_index@UBlockDestroyTimeComponent@@X@entt@@SAIXZ@4IB");
}
inline void dlsym_query()
{
    dlsym_real("?EVENT_BEGIN@ActorDefinitionIdentifier@@2V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@B");
    dlsym_real("?$TSS0@?1??value@?$type_index@V?$sigh_storage_mixin@V?$basic_storage@W4ObjectHandleValue@Scripting@@VScriptFoodComponent@@V?$allocator@VScriptFoodComponent@@@std@@X@entt@@@entt@@X@entt@@SAIXZ@4HA");
    dlsym_real("?$TSS0@?1???$type_id@VCommandRegistry@@W4Mode@ExecuteCommand@@@@YA?AV?$typeid_t@VCommandRegistry@@@@XZ@4HA");
    dlsym_real("?value@?1??0?$type_index@V?$sigh_storage_mixin@V?$basic_storage@W4ObjectHandleValue@Scripting@@VScriptMovementBasicComponent@@V?$allocator@VScriptMovementBasicComponent@@@std@@X@entt@@@entt@@X@entt@@SAIXZ@4IB");
    dlsym_real("?mCrimsonFence@VanillaBlocks@@3PEBVBlock@@EB");
    dlsym_real("?$TSS0@?1???$type_id@VGoal@@VRandomSwimmingGoal@@@@YA?AV?$typeid_t@VGoal@@@@XZ@4HA");
    dlsym_real("?value@?1??0?$type_index@V?$shared_ptr@VFoodItemComponent@@@std@@X@entt@@SAIXZ@4IB");
    dlsym_real("?VERT_OFFHAND_MAP_POS@MapConstants@@3VVec3@@B");
    dlsym_real("?$TSS0@?4??meta_template_info@?$meta_node@V?$ScriptEventSignal@U?$TypedObjectHandle@UScriptChatEvent@@@Scripting@@@@@internal@entt@@CAPEAUmeta_template_node@34@XZ@4HA");
    dlsym_real("?$TSS0@?1??value@?$type_index@UOnExtractStateFrom@@X@entt@@SAIXZ@4HA");
    dlsym_real("?CMD_INPUT_UNICODE_TRANSLATE_MAP@CommandUtils@@3V?$vector@U?$pair@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@D@std@@V?$allocator@U?$pair@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@D@std@@@2@@std@@B");
    dlsym_real("?$TSS0@?1???$base@VItemComponent@@@?$meta_factory@VWeaponItemComponent@@@entt@@QEAA?A_PXZ@4HA");
    dlsym_real("?$TSS0@?1???$toNBT@W4CauldronLiquidType@@@StateSerializationUtils@@YA?AV?$unique_ptr@VTag@@U?$default_delete@VTag@@@std@@@std@@AEBW4CauldronLiquidType@@@Z@4HA");
    dlsym_real("?instance@?1???$type_id@VWeakLifetimeScope@Scripting@@@entt@@YAAEBVtype_info@1@XZ@4V21@A");
    dlsym_real("?mLitRedStoneLamp@VanillaBlockTypes@@3V?$WeakPtr@VBlockLegacy@@@@A");
    dlsym_real("?$TSS0@?1???$type_id@VIDefinitionInstance@@VHarvestFarmBlockDefinition@@@@YA?AV?$typeid_t@VIDefinitionInstance@@@@XZ@4HA");
    dlsym_real("?$TSS0@?1???$type_id@$$CBUSeatDescription@@@entt@@YAAEBVtype_info@1@XZ@4HA");
    dlsym_real("?handlerThunk@?1???$make_packet@VMobArmorEquipmentPacket@@@@YA?AV?$shared_ptr@VPacket@@@std@@XZ@4V?$PacketHandlerDispatcherInstance@VMobArmorEquipmentPacket@@$0A@@@A");
    dlsym_real("?instance@?1???$type_id@AEAVBasicLoader@@@entt@@YAAEBVtype_info@1@XZ@4V21@A");
    dlsym_real("?id@?1???$type_id@VGoal@@VBreedGoal@@@@YA?AV?$typeid_t@VGoal@@@@XZ@4V1@A");
    dlsym_real("?$TSS0@?1??resolve@?$meta_node@VScriptPromiseAny@Scripting@@@internal@entt@@SAPEAUmeta_type_node@34@XZ@4HA");
    dlsym_real("?instance@?1???$type_id@AEAV?$vector@UShooterAmmunitionEntry@ShooterItemComponent@@V?$allocator@UShooterAmmunitionEntry@ShooterItemComponent@@@std@@@std@@@entt@@YAAEBVtype_info@1@XZ@4V21@A");
    dlsym_real("?$TSS0@?1??resolve@?$meta_node@U?$meta_class_template_tag@Upair@std@@@entt@@@internal@entt@@SAPEAUmeta_type_node@34@XZ@4HA");
    dlsym_real("?mSeaGrass@VanillaBlocks@@3PEBVBlock@@EB");
    dlsym_real("?count@?$typeid_t@VCommandRegistry@@@@2GA");
    dlsym_real("?mElement26@VanillaBlocks@@3PEBVBlock@@EB");
    dlsym_real("?HARM@SharedBuffs@@2V?$shared_ptr@VAttributeBuff@@@std@@A");
    dlsym_real("?$TSS0@?1??value@?$type_index@V?$StrongTypedObjectHandle@VScriptGameTestConnectivity@@@Scripting@@X@entt@@SAIXZ@4HA");
    dlsym_real("?node@?1??resolve@?$meta_node@V?$_Vb_reference@U?$_Wrap_alloc@V?$allocator@I@std@@@std@@@std@@@internal@entt@@SAPEAUmeta_type_node@34@XZ@4U534@A");
    dlsym_real("?vtable@?1???$instance@U?$storage_adapter_mixin@V?$basic_storage@VEntityId@@VWardenSpawnTrackerComponent@@V?$allocator@VWardenSpawnTrackerComponent@@@std@@X@entt@@@entt@@@?$poly_vtable@U?$Storage@VEntityId@@@entt@@$0BA@$07@entt@@SAP6AAEBVtype_info@2@AEBV?$basic_any@$0BA@$07@2@@ZXZ@4V?$tuple@P6AAEBVtype_info@entt@@AEBV?$basic_any@$0BA@$07@2@@Z@std@@B");
    dlsym_real("?value@?1??0?$type_index@V?$FlagComponent@UActorInsideBlockTriggerFlag@@@@X@entt@@SAIXZ@4IB");
    dlsym_real("?mCyanCandleCake@VanillaBlockTypes@@3V?$WeakPtr@VBlockLegacy@@@@A");
    dlsym_real("?$TSS0@?1???$type_id@U?$meta_class_template_tag@Vunordered_map@std@@@entt@@@entt@@YAAEBVtype_info@1@XZ@4HA");
    dlsym_real("?$TSS0@?1???$type_id@AEAU?$storage_adapter_mixin@V?$basic_storage@VEntityId@@V?$FlagComponent@USaveSurroundingChunksFlag@@@@V?$allocator@V?$FlagComponent@USaveSurroundingChunksFlag@@@@@std@@X@entt@@@entt@@@entt@@YAAEBVtype_info@1@XZ@4HA");
    dlsym_real("?$TSS0@?1???$instance@U?$storage_adapter_mixin@V?$basic_storage@VEntityId@@VOutOfControlComponent@@V?$allocator@VOutOfControlComponent@@@std@@X@entt@@@entt@@@?$poly_vtable@U?$Storage@VEntityId@@@entt@@$0BA@$07@entt@@SAP6AAEBVtype_info@2@AEBV?$basic_any@$0BA@$07@2@@ZXZ@4HA");
    dlsym_real("?mTopSnow@VanillaBlocks@@3PEBVBlock@@EB");
    dlsym_real("?instance@?1???$type_id@AEAU?$storage_adapter_mixin@V?$basic_storage@VEntityId@@VInsideBlockNotifierComponent@@V?$allocator@VInsideBlockNotifierComponent@@@std@@X@entt@@@entt@@@entt@@YAAEBVtype_info@1@XZ@4V21@A");
    dlsym_real("?Low@OSThreadPriority@Threading@Bedrock@@2V123@B");
    dlsym_real("?mCoralFanHang3@VanillaBlocks@@3PEBVBlock@@EB");
    dlsym_real("?mLoomBlock@VanillaBlockTypes@@3V?$WeakPtr@VBlockLegacy@@@@A");
    dlsym_real("?$TSS0@?1???$type_id@AEAV?$array@M$02@std@@@entt@@YAAEBVtype_info@1@XZ@4HA");
    dlsym_real("?$TSS0@?1???$type_id@AEAU?$storage_adapter_mixin@V?$basic_storage@VEntityId@@UCraftingTableComponent@@V?$allocator@UCraftingTableComponent@@@std@@X@entt@@@entt@@@entt@@YAAEBVtype_info@1@XZ@4HA");
    dlsym_real("?$TSS0@?1??resolve@?$meta_node@VScriptRideableComponent@@@internal@entt@@SAPEAUmeta_type_node@34@XZ@4HA");
    dlsym_real("?node@?1???$conv@$MP6A?AV?$shared_ptr@UBlockComponentDescription@@@std@@AEBV?$shared_ptr@UBlockDisplayNameDescription@@@2@@Z1??$castToBaseType@UBlockDisplayNameDescription@@UBlockComponentDescription@@@CerealHelpers@@YA?AV12@0@Z@?$meta_factory@V?$shared_ptr@UBlockDisplayNameDescription@@@std@@@entt@@QEAA?AV12@XZ@4Umeta_conv_node@internal@2@A");
    dlsym_real("?PLAYER_ALIVE_HEIGHT@Player@@2MB");
    dlsym_real("?$TSS0@?1???$type_id@AEAU?$storage_adapter_mixin@V?$basic_storage@VEntityId@@VDanceComponent@@V?$allocator@VDanceComponent@@@std@@X@entt@@@entt@@@entt@@YAAEBVtype_info@1@XZ@4HA");
    dlsym_real("?$TSS0@?1???$instance@U?$storage_adapter_mixin@V?$basic_storage@VEntityId@@V?$ActorFlagComponent@UEnvironmentSensorFlag@@@@V?$allocator@V?$ActorFlagComponent@UEnvironmentSensorFlag@@@@@std@@X@entt@@@entt@@@?$poly_vtable@U?$Storage@VEntityId@@@entt@@$0BA@$07@entt@@SAP6AAEBVtype_info@2@AEBV?$basic_any@$0BA@$07@2@@ZXZ@4HA");
    dlsym_real("?$TSS0@?1??value@?$type_index@U?$storage_adapter_mixin@V?$basic_storage@VEntityId@@VUserEntityIdentifierComponent@@V?$allocator@VUserEntityIdentifierComponent@@@std@@X@entt@@@entt@@X@entt@@SAIXZ@4HA");
    dlsym_real("?$TSS0@?1??value@?$type_index@V?$unordered_map@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$shared_ptr@UBlockComponentDescription@@@2@U?$hash@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@U?$equal_to@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$shared_ptr@UBlockComponentDescription@@@2@@std@@@2@@std@@X@entt@@SAIXZ@4HA");
    dlsym_real("?$TSS0@?6???$data@$MPEQIconItemComponent@@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@0BI@$MPEQ1@V23@0BI@Uas_ref_t@entt@@@?$meta_factory@VIconItemComponent@@@entt@@QEAA?A_PI@Z@4HA");
    dlsym_real("?NUM_GROUPS_ON_NORMAL@Raid@@0EB");
    dlsym_real("?node@?4??meta_template_info@?$meta_node@V?$vector@_NV?$allocator@_N@std@@@std@@@internal@entt@@CAPEAUmeta_template_node@34@XZ@4U534@A");
    dlsym_real("?$TSS0@?1???$type_id@AEAVScriptMovementComponent@@@entt@@YAAEBVtype_info@1@XZ@4HA");
    dlsym_real("?value@?1??0?$type_index@V?$sigh_storage_mixin@V?$basic_storage@W4ObjectHandleValue@Scripting@@VScriptSimulatedPlayer@@V?$allocator@VScriptSimulatedPlayer@@@std@@X@entt@@@entt@@X@entt@@SAIXZ@4IB");
    dlsym_real("?node@?1???$base@VScriptActorComponent@@@?$meta_factory@VScriptMountTamingComponent@@@entt@@QEAA?A_PXZ@4Umeta_base_node@internal@2@A");
    dlsym_real("?$TSS0@?1???$type_id@AEAW4ArmorTextureType@@@entt@@YAAEBVtype_info@1@XZ@4HA");
    dlsym_real("?instance@?1???$type_id@AEAUScriptBlockExplodedEvent@@@entt@@YAAEBVtype_info@1@XZ@4V21@A");
    dlsym_real("?instance@?1???$type_id@AEAVScriptMovementSwayComponent@@@entt@@YAAEBVtype_info@1@XZ@4V21@A");
    dlsym_real("?node@?1???$base@VItemComponent@@@?$meta_factory@VEntityPlacerItemComponent@@@entt@@QEAA?A_PXZ@4Umeta_base_node@internal@2@A");
    dlsym_real("?$TSS0@?1???$instance@V?$sigh_storage_mixin@V?$basic_storage@W4ObjectHandleValue@Scripting@@VScriptStringBlockProperty@@V?$allocator@VScriptStringBlockProperty@@@std@@X@entt@@@entt@@@?$poly_vtable@U?$Storage@W4ObjectHandleValue@Scripting@@@entt@@$0BA@$07@entt@@SAP6AAEBVtype_info@2@AEBV?$basic_any@$0BA@$07@2@@ZXZ@4HA");
    dlsym_real("?$TSS0@?1??value@?$type_index@V?$sigh_storage_mixin@V?$basic_storage@W4ObjectHandleValue@Scripting@@VScriptMovementGenericComponent@@V?$allocator@VScriptMovementGenericComponent@@@std@@X@entt@@@entt@@X@entt@@SAIXZ@4HA");
    dlsym_real("?mPiglin@BannerPattern@@2PEAV1@EA");
    dlsym_real("?mLitRedStoneTorch@VanillaBlockTypes@@3V?$WeakPtr@VBlockLegacy@@@@A");
    dlsym_real("?$TSS0@?4??meta_template_info@?$meta_node@U?$hash@VHashedString@@@std@@@internal@entt@@CAPEAUmeta_template_node@34@XZ@4HA");
    dlsym_real("?value@?1??0?$type_index@V?$shared_ptr@VThrowableItemComponent@@@std@@X@entt@@SAIXZ@4IB");
    dlsym_real("?property@?1???$assign@$0A@@?$meta_factory@VRenderOffsetsItemComponent@@V1@@entt@@AEAAXVmeta_any@2@0@Z@4PAV32@A");
    dlsym_real("?node@?1???$func@$MQ8SaturationModifier@FoodItemComponent@@EBA_NAEAVBasicSaver@@AEBUSerializerTraits@@@Z1?Serialize@12@QEBA_N01@ZUas_is_t@entt@@@?$meta_factory@VSaturationModifier@FoodItemComponent@@@entt@@QEAA?A_PI@Z@4Umeta_func_node@internal@2@A");
    dlsym_real("?node@?1???$func@$MQ8ExpressionNode@@EAA_NAEAVBasicLoader@@AEBUSerializerTraits@@AEBVBedrockLoadContext@@@Z1?deserialize@1@QEAA_N012@ZUas_is_t@entt@@@?$meta_factory@VExpressionNode@@@entt@@QEAA?A_PI@Z@4Umeta_func_node@internal@2@A");
    dlsym_real("?MAX_HEALTH_CAP_UUID@WitherBoss@@2VUUID@mce@@B");
    dlsym_real("?ABSORPTION@SharedAmplifiers@@2V?$shared_ptr@VAmplifier@@@std@@A");
    dlsym_real("?vtable@?1???$instance@V?$sigh_storage_mixin@V?$basic_storage@W4ObjectHandleValue@Scripting@@VScriptItemDurabilityComponent@@V?$allocator@VScriptItemDurabilityComponent@@@std@@X@entt@@@entt@@@?$poly_vtable@U?$Storage@W4ObjectHandleValue@Scripting@@@entt@@$0BA@$07@entt@@SAP6AAEBVtype_info@2@AEBV?$basic_any@$0BA@$07@2@@ZXZ@4V?$tuple@P6AAEBVtype_info@entt@@AEBV?$basic_any@$0BA@$07@2@@Z@std@@B");
    dlsym_real("?instance@?1???$type_id@AEAVScriptPlayerInventoryComponentContainer@@@entt@@YAAEBVtype_info@1@XZ@4V21@A");
    dlsym_real("?value@?1??0?$type_index@U?$storage_adapter_mixin@V?$basic_storage@VEntityId@@UBlockQueuedTickingComponent@@V?$allocator@UBlockQueuedTickingComponent@@@std@@X@entt@@@entt@@X@entt@@SAIXZ@4IB");
    dlsym_real("?mLog2@VanillaBlocks@@3PEBVBlock@@EB");
    dlsym_real("?Sign@VanillaItemTags@@2QBDB");
    dlsym_real("?node@?4??meta_template_info@?$meta_node@V?$map@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$shared_ptr@VItemComponent@@@2@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$shared_ptr@VItemComponent@@@2@@std@@@2@@std@@@internal@entt@@CAPEAUmeta_template_node@34@XZ@4U534@A");
    dlsym_real("?node@?4??meta_template_info@?$meta_node@V?$shared_ptr@VRecordItemComponent@@@std@@@internal@entt@@CAPEAUmeta_template_node@34@XZ@4U534@A");
    dlsym_real("?mSoulCampfire@VanillaBlocks@@3PEBVBlock@@EB");
    dlsym_real("?instance@?1???$type_id@AEAU?$storage_adapter_mixin@V?$basic_storage@VEntityId@@VOverworldHeightAttributes@@V?$allocator@VOverworldHeightAttributes@@@std@@X@entt@@@entt@@@entt@@YAAEBVtype_info@1@XZ@4V21@A");
    dlsym_real("?node@?1??resolve@?$meta_node@U?$TypedObjectHandle@UScriptActorAddEffectEvent@@@Scripting@@@internal@entt@@SAPEAUmeta_type_node@34@XZ@4U534@A");
    dlsym_real("?mGlazedTerracottaPink@VanillaBlocks@@3PEBVBlock@@EB");
    dlsym_real("?id@?1???$type_id@VIDefinitionInstance@@VDryingOutTimerDefinition@DryingOutTimerComponent@@@@YA?AV?$typeid_t@VIDefinitionInstance@@@@XZ@4V1@A");
    dlsym_real("?MOVEMENT_SPEED@SharedModifiers@@2V?$shared_ptr@VAttributeModifier@@@std@@A");
    dlsym_real("?instance@?1???$type_id@$$CB_N@entt@@YAAEBVtype_info@1@XZ@4V21@A");
    dlsym_real("?$TSS1@?1???$assign@$0A@@?$meta_factory@VDiggerItemComponent@@V1@@entt@@AEAAXVmeta_any@2@0@Z@4HA");
    dlsym_real("?$TSS0@?1???$type_id@V?$allocator@VDefinitionTrigger@@@std@@@entt@@YAAEBVtype_info@1@XZ@4HA");
    dlsym_real("?value@?1??0?$type_index@VScriptBlockPistonComponent@@X@entt@@SAIXZ@4IB");
    dlsym_real("?mPolishedBlackstoneStairs@VanillaBlockTypes@@3V?$WeakPtr@VBlockLegacy@@@@A");
    dlsym_real("?mSlimeBlock@VanillaBlocks@@3PEBVBlock@@EB");
    dlsym_real("?value@?1??0?$type_index@VBodyControlComponent@@X@entt@@SAIXZ@4IB");
    dlsym_real("?instance@?1???$type_id@AEAV?$sigh_storage_mixin@V?$basic_storage@W4entity@entt@@UtempLevelComponent@WORKAROUNDS@ScriptApi@@V?$allocator@UtempLevelComponent@WORKAROUNDS@ScriptApi@@@std@@X@entt@@@entt@@@entt@@YAAEBVtype_info@1@XZ@4V21@A");
    dlsym_real("?GLB_EXTENSION@glTFExporter@@2V?$basic_string_span@$$CBD$0?0@gsl@@B");
    dlsym_real("?$TSS0@?1??value@?$type_index@U?$storage_adapter_mixin@V?$basic_storage@VEntityId@@VLootComponent@@V?$allocator@VLootComponent@@@std@@X@entt@@@entt@@X@entt@@SAIXZ@4HA");
    dlsym_real("?$TSS1@?1???$assign@$0A@@?$meta_factory@VThrowableItemComponent@@U?$integral_constant@PEQThrowableItemComponent@@_N$0CE@@std@@U23@@entt@@AEAAXVmeta_any@2@0@Z@4HA");
    dlsym_real("?$TSS0@?1??value@?$type_index@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@VHashedString@@@std@@@std@@@std@@X@entt@@SAIXZ@4HA");
    dlsym_real("?mElement104@VanillaBlocks@@3PEBVBlock@@EB");
    dlsym_real("?mStoneBrickStairs@VanillaBlockTypes@@3V?$WeakPtr@VBlockLegacy@@@@A");
    dlsym_real("?mLightBlueCandleCake@VanillaBlockTypes@@3V?$WeakPtr@VBlockLegacy@@@@A");
    dlsym_real("?BrewingStandSlotABit@VanillaStates@@3V?$ItemStateVariant@_N@@B");
    dlsym_real("?node@?1???$assign@$0A@@?$meta_factory@UBlockFlammableDescription@@U?$integral_constant@PEQBlockFlammableDescription@@H$07@std@@U23@@entt@@AEAAXVmeta_any@2@0@Z@4Umeta_prop_node@internal@2@A");
    dlsym_real("?instance@?1???$type_id@AEBUActorDefinitionIdentifier@@@entt@@YAAEBVtype_info@1@XZ@4V21@A");
    dlsym_real("?$TSS0@?1???$type_id@V?$_Vb_const_iterator@U?$_Wrap_alloc@V?$allocator@I@std@@@std@@@std@@@entt@@YAAEBVtype_info@1@XZ@4HA");
    dlsym_real("?node@?1???$assign@$0A@@?$meta_factory@VIconItemComponent@@U?$integral_constant@PEQIconItemComponent@@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@$0DI@@std@@U23@@entt@@AEAAXVmeta_any@2@0@Z@4Umeta_prop_node@internal@2@A");
    dlsym_real("?$TSS0@?1???$type_id@$$CBV?$TypedScriptClosure@$$A6AXU?$TypedObjectHandle@UScriptBeforePistonActionEvent@@@Scripting@@@Z$$V@Scripting@@@entt@@YAAEBVtype_info@1@XZ@4HA");
    dlsym_real("?node@?4??meta_template_info@?$meta_node@V?$Result@VVec3@@@Scripting@@@internal@entt@@CAPEAUmeta_template_node@34@XZ@4U534@A");
    dlsym_real("?DEFAULT_DISTANCE_WEATHER_SETTING@FogDefinition@@2UFogDistanceSetting@@B");
    dlsym_real("?value@?1??0?$type_index@V?$TagsComponent@U?$IDType@ULevelTagSetIDType@@@@@@X@entt@@SAIXZ@4IB");
    dlsym_real("?$TSS0@?1???$type_id@AEAV?$ScriptEventSignal@U?$TypedObjectHandle@UScriptBeforePistonActionEvent@@@Scripting@@@@@entt@@YAAEBVtype_info@1@XZ@4HA");
    dlsym_real("?$TSS1@?1???$assign@$0A@@?$meta_factory@UBlockGeometryDescription@@U1@@entt@@AEAAXVmeta_any@2@0@Z@4HA");
    dlsym_real("?value@?1??0?$type_index@V?$sigh_storage_mixin@V?$basic_storage@W4ObjectHandleValue@Scripting@@VScriptFoodComponent@@V?$allocator@VScriptFoodComponent@@@std@@X@entt@@@entt@@X@entt@@SAIXZ@4IB");
    dlsym_real("?MIN_DELTA_TO_JUMP@MoveControl@@2MB");
    dlsym_real("?value@?1??0?$type_index@V?$sigh_storage_mixin@V?$basic_storage@W4ObjectHandleValue@Scripting@@U?$PointerStorageComponent@UScriptBeforeChatEvent@@@internal@2@V?$allocator@U?$PointerStorageComponent@UScriptBeforeChatEvent@@@internal@Scripting@@@std@@X@entt@@@entt@@X@entt@@SAIXZ@4IB");
    dlsym_real("?vtable@?1???$instance@U?$storage_adapter_mixin@V?$basic_storage@VEntityId@@UBlockRandomTickingComponent@@V?$allocator@UBlockRandomTickingComponent@@@std@@X@entt@@@entt@@@?$poly_vtable@U?$Storage@VEntityId@@@entt@@$0BA@$07@entt@@SAP6AAEBVtype_info@2@AEBV?$basic_any@$0BA@$07@2@@ZXZ@4V?$tuple@P6AAEBVtype_info@entt@@AEBV?$basic_any@$0BA@$07@2@@Z@std@@B");
    dlsym_real("?instance@?1???$type_id@AEAVItemComponent@@@entt@@YAAEBVtype_info@1@XZ@4V21@A");
    dlsym_real("?value@?1??0?$type_index@V?$sigh_storage_mixin@V?$basic_storage@W4ObjectHandleValue@Scripting@@UKey@ScriptActor@@V?$allocator@UKey@ScriptActor@@@std@@X@entt@@@entt@@X@entt@@SAIXZ@4IB");
    dlsym_real("?instance@?1???$type_id@$$CBVScriptNavigationWalkComponent@@@entt@@YAAEBVtype_info@1@XZ@4V21@A");
    dlsym_real("?mRedStoneDust@VanillaBlocks@@3PEBVBlock@@EB");
    dlsym_real("?escape@?1???$ParseStringToStream@$0A@U?$UTF8@D@rapidjson@@U12@U?$GenericStringStream@U?$UTF8@D@rapidjson@@@2@V?$StackStream@D@?$GenericReader@U?$UTF8@D@rapidjson@@U12@VCrtAllocator@2@@2@@?$GenericReader@U?$UTF8@D@rapidjson@@U12@VCrtAllocator@2@@rapidjson@@AEAAXAEAU?$GenericStringStream@U?$UTF8@D@rapidjson@@@2@AEAV?$StackStream@D@12@_N@Z@4QBDB");
    dlsym_real("?value@?1??0?$type_index@U?$storage_adapter_mixin@V?$basic_storage@VEntityId@@VEquippableComponent@@V?$allocator@VEquippableComponent@@@std@@X@entt@@@entt@@X@entt@@SAIXZ@4IB");
    dlsym_real("?$TSS0@?1??resolve@?$meta_node@VKnockbackResistanceItemComponent@@@internal@entt@@SAPEAUmeta_type_node@34@XZ@4HA");
    dlsym_real("?MAP_PLAYER_PITCH_SCALE@MapConstants@@3MB");
    dlsym_real("?$TSS0@?1???$make_packet@VClientCacheBlobStatusPacket@@@@YA?AV?$shared_ptr@VPacket@@@std@@XZ@4HA");
    dlsym_real("?mRedNetherBrickStairs@VanillaBlocks@@3PEBVBlock@@EB");
    dlsym_real("?id@?1???$type_id@VIDefinitionInstance@@VDefinition@RamAttackGoal@@@@YA?AV?$typeid_t@VIDefinitionInstance@@@@XZ@4V1@A");
    dlsym_real("?$TSS0@?1???$type_id@$$CBV?$vector@VBlockDescriptor@@V?$allocator@VBlockDescriptor@@@std@@@std@@@entt@@YAAEBVtype_info@1@XZ@4HA");
    dlsym_real("?$TSS0@?1???$type_id@AEAV?$vector@UGameTestResult@@V?$allocator@UGameTestResult@@@std@@@std@@@entt@@YAAEBVtype_info@1@XZ@4HA");
    dlsym_real("?$TSS0@?1??resolve@?$meta_node@UScriptExplosionOptions@@@internal@entt@@SAPEAUmeta_type_node@34@XZ@4HA");
    dlsym_real("?$TSS0@?1???$type_id@$$CBVArmorItemComponent@@@entt@@YAAEBVtype_info@1@XZ@4HA");
    dlsym_real("?instance@?1???$type_id@U?$TypedObjectHandle@UScriptWeatherChangedEvent@@@Scripting@@@entt@@YAAEBVtype_info@1@XZ@4V21@A");
    dlsym_real("?id@?1???$type_id@VIDefinitionInstance@@UIsStunnedDefinition@@@@YA?AV?$typeid_t@VIDefinitionInstance@@@@XZ@4V1@A");
    dlsym_real("?mAllReferenceObjects@?$ServiceLocator@VSessionInfoManager@Bedrock@@@@0U?$atomic@_K@std@@A");
    dlsym_real("?$TSS0@?1???$instance@V?$sigh_storage_mixin@V?$basic_storage@W4ObjectHandleValue@Scripting@@U?$PointerStorageComponent@UScriptActorEvent@@@internal@2@V?$allocator@U?$PointerStorageComponent@UScriptActorEvent@@@internal@Scripting@@@std@@X@entt@@@entt@@@?$poly_vtable@U?$Storage@W4ObjectHandleValue@Scripting@@@entt@@$0BA@$07@entt@@SAP6AAEBVtype_info@2@AEBV?$basic_any@$0BA@$07@2@@ZXZ@4HA");
    dlsym_real("?value@?1??0?$type_index@_NX@entt@@SAIXZ@4IB");
    dlsym_real("?$TSS0@?4??meta_template_info@?$meta_node@V?$StrongTypedObjectHandle@VScriptItemStack@@@Scripting@@@internal@entt@@CAPEAUmeta_template_node@34@XZ@4HA");
    dlsym_real("?$TSS0@?1??resolve@?$meta_node@V?$vector@VStrongObjectHandle@Scripting@@V?$allocator@VStrongObjectHandle@Scripting@@@std@@@std@@@internal@entt@@SAPEAUmeta_type_node@34@XZ@4HA");
    dlsym_real("?mGoldOre@VanillaBlockTypes@@3V?$WeakPtr@VBlockLegacy@@@@A");
    dlsym_real("?value@?1??0?$type_index@USurfaceMaterialAttributes@@X@entt@@SAIXZ@4IB");
    dlsym_real("?MAP_LEFTHAND_ROT@MapConstants@@3VVec3@@B");
    dlsym_real("?$TSS0@?1???$instance@V?$sigh_storage_mixin@V?$basic_storage@W4ObjectHandleValue@Scripting@@VScriptWorld@@V?$allocator@VScriptWorld@@@std@@X@entt@@@entt@@@?$poly_vtable@U?$Storage@W4ObjectHandleValue@Scripting@@@entt@@$0BA@$07@entt@@SAP6AAEBVtype_info@2@AEBV?$basic_any@$0BA@$07@2@@ZXZ@4HA");
    dlsym_real("?$TSS0@?1??value@?$type_index@U?$storage_adapter_mixin@V?$basic_storage@VEntityId@@VDebugInfoComponent@@V?$allocator@VDebugInfoComponent@@@std@@X@entt@@@entt@@X@entt@@SAIXZ@4HA");
    dlsym_real("?$TSS0@?1???$type_id@AEAU?$storage_adapter_mixin@V?$basic_storage@VEntityId@@VBarterComponent@@V?$allocator@VBarterComponent@@@std@@X@entt@@@entt@@@entt@@YAAEBVtype_info@1@XZ@4HA");
    dlsym_real("?$TSS0@?1???$base@VItemComponent@@@?$meta_factory@VWearableItemComponent@@@entt@@QEAA?A_PXZ@4HA");
    dlsym_real("?DEFAULT_MUTATION_RATE@GeneticsDefinition@@0MB");
    dlsym_real("?$TSS0@?1???$type_id@U?$TypedObjectHandle@VScriptItemDurabilityComponent@@@Scripting@@@entt@@YAAEBVtype_info@1@XZ@4HA");
    dlsym_real("?value@?1??0?$type_index@VCustomMapFoliageColorAttributes@@X@entt@@SAIXZ@4IB");
    dlsym_real("?$TSS0@?1??value@?$type_index@V?$allocator@_N@std@@X@entt@@SAIXZ@4HA");
    dlsym_real("?value@?1??0?$type_index@V?$map@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@VExpressionNode@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@VExpressionNode@@@std@@@2@@std@@X@entt@@SAIXZ@4IB");
    dlsym_real("?instance@?1???$type_id@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@@entt@@YAAEBVtype_info@1@XZ@4V21@A");
    dlsym_real("?vtable@?1???$instance@U?$storage_adapter_mixin@V?$basic_storage@VEntityId@@VAgeableComponent@@V?$allocator@VAgeableComponent@@@std@@X@entt@@@entt@@@?$poly_vtable@U?$Storage@VEntityId@@@entt@@$0BA@$07@entt@@SAP6AAEBVtype_info@2@AEBV?$basic_any@$0BA@$07@2@@ZXZ@4V?$tuple@P6AAEBVtype_info@entt@@AEBV?$basic_any@$0BA@$07@2@@Z@std@@B");
    dlsym_real("?mMayTakeIsSetup@EnderMan@@0_NA");
    dlsym_real("?mMesaRock@VanillaBiomes@@2PEAVBiome@@EA");
    dlsym_real("?mGlazedTerracottaCyan@VanillaBlocks@@3PEBVBlock@@EB");
    dlsym_real("?$TSS0@?1???$func@$MQ8SaturationModifier@FoodItemComponent@@EBA_NAEAVBasicSaver@@AEBUSerializerTraits@@@Z1?Serialize@12@QEBA_N01@ZUas_is_t@entt@@@?$meta_factory@VSaturationModifier@FoodItemComponent@@@entt@@QEAA?A_PI@Z@4HA");
    dlsym_real("?$TSS0@?1???$type_id@AEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@entt@@YAAEBVtype_info@1@XZ@4HA");
    dlsym_real("?$TSS0@?1???$instance@U?$storage_adapter_mixin@V?$basic_storage@VEntityId@@UOnPlayerDestroyedTrigger@@V?$allocator@UOnPlayerDestroyedTrigger@@@std@@X@entt@@@entt@@@?$poly_vtable@U?$Storage@VEntityId@@@entt@@$0BA@$07@entt@@SAP6AAEBVtype_info@2@AEBV?$basic_any@$0BA@$07@2@@ZXZ@4HA");
    dlsym_real("?instance@?1???$type_id@U?$TypedObjectHandle@UScriptExplosionOptions@@@Scripting@@@entt@@YAAEBVtype_info@1@XZ@4V21@A");
    dlsym_real("?$TSS1@?1???$assign@$0A@@?$meta_factory@UVolumeBoundsDefinition@@U?$integral_constant@PEQVolumeBoundsDefinition@@VBlockPos@@$0M@@std@@U23@@entt@@AEAAXVmeta_any@2@0@Z@4HA");
    dlsym_real("?$TSS0@?1???$type_id@$$CBUOnActorLeaveVolumeDefinition@@@entt@@YAAEBVtype_info@1@XZ@4HA");
    dlsym_real("?$TSS0@?1???$assign@$0A@@?$meta_factory@VShooterItemComponent@@U?$integral_constant@PEQShooterItemComponent@@M$0DA@@std@@U23@@entt@@AEAAXVmeta_any@2@0@Z@4HA");
    dlsym_real("?$TSS0@?1???$toNBT@W4LeverDirection@@@StateSerializationUtils@@YA?AV?$unique_ptr@VTag@@U?$default_delete@VTag@@@std@@@std@@AEBW4LeverDirection@@@Z@4HA");
    dlsym_real("?$TSS0@?1??value@?$type_index@UScriptBeforeChatEvent@@X@entt@@SAIXZ@4HA");
    dlsym_real("?$TSS0@?1???$assign@$0A@@?$meta_factory@UVolumeDefinition@@U1@@entt@@AEAAXVmeta_any@2@0@Z@4HA");
    dlsym_real("?$TSS0@?1???$type_id@AEAU?$storage_adapter_mixin@V?$basic_storage@VEntityId@@UBlockRotationComponent@@V?$allocator@UBlockRotationComponent@@@std@@X@entt@@@entt@@@entt@@YAAEBVtype_info@1@XZ@4HA");
    dlsym_real("?$TSS0@?1???$type_id@VGoal@@VHoverGoal@@@@YA?AV?$typeid_t@VGoal@@@@XZ@4HA");
    dlsym_real("?node@?4??meta_template_info@?$meta_node@V?$TypedScriptClosure@$$A6A_NU?$TypedObjectHandle@VScriptActor@@@Scripting@@@Z$$V@Scripting@@@internal@entt@@CAPEAUmeta_template_node@34@XZ@4U534@A");
    dlsym_real("?HangingActor@VanillaItemTags@@2QBDB");
    dlsym_real("?node@?1???$conv@$MP6A?AV?$shared_ptr@UBlockComponentDescription@@@std@@AEBV?$shared_ptr@UBlockDestroyTimeDescription@@@2@@Z1??$castToBaseType@UBlockDestroyTimeDescription@@UBlockComponentDescription@@@CerealHelpers@@YA?AV12@0@Z@?$meta_factory@V?$shared_ptr@UBlockDestroyTimeDescription@@@std@@@entt@@QEAA?AV12@XZ@4Umeta_conv_node@internal@2@A");
    dlsym_real("?node@?1???$conv@$MP6AHW4GameTestFluidType@@@Z1??$constructUnderlyingType@H@?$EnumBindingBuilder@W4GameTestFluidType@@@Scripting@@SAH0@Z@?$meta_factory@W4GameTestFluidType@@@entt@@QEAA?AV12@XZ@4Umeta_conv_node@internal@2@A");
    dlsym_real("?$TSS0@?1???$type_id@VGoal@@VRandomHoverGoal@@@@YA?AV?$typeid_t@VGoal@@@@XZ@4HA");
    dlsym_real("?FUNCTION_NAME_SOFTENUM_NAME@CommandRegistry@@2PEBDEB");
    dlsym_real("?mBeehive@VanillaBlockTypes@@3V?$WeakPtr@VBlockLegacy@@@@A");
    dlsym_real("?$TSS0@?1??resolve@?$meta_node@U?$TypedObjectHandle@VScriptItemDurabilityComponent@@@Scripting@@@internal@entt@@SAPEAUmeta_type_node@34@XZ@4HA");
    dlsym_real("?$TSS0@?1???$base@VScriptActorComponent@@@?$meta_factory@VScriptMovementJumpComponent@@@entt@@QEAA?A_PXZ@4HA");
    dlsym_real("?value@?1??0?$type_index@U?$storage_adapter_mixin@V?$basic_storage@VEntityId@@VOutOfControlComponent@@V?$allocator@VOutOfControlComponent@@@std@@X@entt@@@entt@@X@entt@@SAIXZ@4IB");
    dlsym_real("?$TSS0@?1???$type_id@VScriptMovementJumpComponent@@@entt@@YAAEBVtype_info@1@XZ@4HA");
    dlsym_real("?$TSS0@?6???$data@$MPEQVolumeBoundsDefinition@@VBlockPos@@0M@$MPEQ1@V2@0M@Uas_ref_t@entt@@@?$meta_factory@UVolumeBoundsDefinition@@@entt@@QEAA?A_PI@Z@4HA");
    dlsym_real("?instance@?1???$type_id@AEAVScriptNavigationClimbComponent@@@entt@@YAAEBVtype_info@1@XZ@4V21@A");
    dlsym_real("?value@?1??0?$type_index@U?$TypedObjectHandle@VScriptGameTestConnectivity@@@Scripting@@X@entt@@SAIXZ@4IB");
    dlsym_real("?mWoodenDoorBirch@VanillaBlockTypes@@3V?$WeakPtr@VBlockLegacy@@@@A");
    dlsym_real("?node@?1??resolve@?$meta_node@V?$Result@V?$StrongTypedObjectHandle@VScriptBlock@@@Scripting@@@Scripting@@@internal@entt@@SAPEAUmeta_type_node@34@XZ@4U534@A");
    dlsym_real("?node@?1??resolve@?$meta_node@V?$TypedScriptClosure@$$A6AXXZ$$V@Scripting@@@internal@entt@@SAPEAUmeta_type_node@34@XZ@4U534@A");
    dlsym_real("?$TSS0@?1???$type_id@AEAU?$storage_adapter_mixin@V?$basic_storage@VEntityId@@V?$WeightedBiomeAttributes@UMutateBiomeTransformation@@@@V?$allocator@V?$WeightedBiomeAttributes@UMutateBiomeTransformation@@@@@std@@X@entt@@@entt@@@entt@@YAAEBVtype_info@1@XZ@4HA");
    dlsym_real("?$TSS0@?1???$type_id@$$CBV?$TypedScriptClosure@$$A6AXU?$TypedObjectHandle@VScriptGameTestHelper@@@Scripting@@@Z$$V@Scripting@@@entt@@YAAEBVtype_info@1@XZ@4HA");
    dlsym_real("?$TSS0@?1???$base@VScriptComponent@@@?$meta_factory@VScriptAgeableComponent@@@entt@@QEAA?A_PXZ@4HA");
    dlsym_real("?mCopperOre@VanillaBlockTypes@@3V?$WeakPtr@VBlockLegacy@@@@A");
    dlsym_real("?$TSS0@?1??value@?$type_index@VFreezingComponent@@X@entt@@SAIXZ@4HA");
    dlsym_real("?$TSS0@?1??value@?$type_index@V?$TypedScriptClosure@$$A6AXU?$TypedObjectHandle@UScriptChatEvent@@@Scripting@@@Z$$V@Scripting@@X@entt@@SAIXZ@4HA");
    dlsym_real("?value@?1??0?$type_index@UBlockDestroyTimeComponent@@X@entt@@SAIXZ@4IB");
}

inline void testStaticDlsym()
{
    // time: 20194.8 - time: 35094.8
    // time: 269.9   - time: 550.7
    // time: 541.8   - time: 286.2
    // time: 328.3   - time: 302.5
    // time: 280.1   - time: 267.3

    TestTimeLog(static_query);
    TestTimeLog(dlsym_query);
    TestTimeLog(static_query);
    TestTimeLog(dlsym_query);
    TestTimeLog(static_query);
    TestTimeLog(dlsym_query);
}

#include <MC/Level.hpp>
inline double getTickDeltaTime()
{
    double (Level::*rv)();
    *((void**)&rv) = dlsym_static("?getTickDeltaTime@Level@@QEBANXZ");
    return (Global<Level>->*rv)();
}

void dlsym_call()
{
    getTickDeltaTime();
    getTickDeltaTime();
    getTickDeltaTime();
    getTickDeltaTime();
    getTickDeltaTime();
    getTickDeltaTime();
    getTickDeltaTime();
    getTickDeltaTime();
    getTickDeltaTime();
    getTickDeltaTime();
    getTickDeltaTime();
    getTickDeltaTime();
    getTickDeltaTime();
    getTickDeltaTime();
    getTickDeltaTime();
    getTickDeltaTime();
    getTickDeltaTime();
    getTickDeltaTime();
    getTickDeltaTime();
    getTickDeltaTime();
    getTickDeltaTime();
    getTickDeltaTime();
    getTickDeltaTime();
    getTickDeltaTime();
    getTickDeltaTime();
    getTickDeltaTime();
    getTickDeltaTime();
    getTickDeltaTime();
    getTickDeltaTime();
    getTickDeltaTime();
    getTickDeltaTime();
    getTickDeltaTime();
    getTickDeltaTime();
    getTickDeltaTime();
    getTickDeltaTime();
    getTickDeltaTime();
}

void mcapi_call()
{
    Global<Level>->getTickDeltaTime();
    Global<Level>->getTickDeltaTime();
    Global<Level>->getTickDeltaTime();
    Global<Level>->getTickDeltaTime();
    Global<Level>->getTickDeltaTime();
    Global<Level>->getTickDeltaTime();
    Global<Level>->getTickDeltaTime();
    Global<Level>->getTickDeltaTime();
    Global<Level>->getTickDeltaTime();
    Global<Level>->getTickDeltaTime();
    Global<Level>->getTickDeltaTime();
    Global<Level>->getTickDeltaTime();
    Global<Level>->getTickDeltaTime();
    Global<Level>->getTickDeltaTime();
    Global<Level>->getTickDeltaTime();
    Global<Level>->getTickDeltaTime();
    Global<Level>->getTickDeltaTime();
    Global<Level>->getTickDeltaTime();
    Global<Level>->getTickDeltaTime();
    Global<Level>->getTickDeltaTime();
    Global<Level>->getTickDeltaTime();
    Global<Level>->getTickDeltaTime();
    Global<Level>->getTickDeltaTime();
    Global<Level>->getTickDeltaTime();
    Global<Level>->getTickDeltaTime();
    Global<Level>->getTickDeltaTime();
    Global<Level>->getTickDeltaTime();
    Global<Level>->getTickDeltaTime();
    Global<Level>->getTickDeltaTime();
    Global<Level>->getTickDeltaTime();
    Global<Level>->getTickDeltaTime();
    Global<Level>->getTickDeltaTime();
    Global<Level>->getTickDeltaTime();
    Global<Level>->getTickDeltaTime();
    Global<Level>->getTickDeltaTime();
    Global<Level>->getTickDeltaTime();
}

void testMCAPI()
{
    TestTimeLog(mcapi_call);
    TestTimeLog(dlsym_call);
    TestTimeLog(mcapi_call);
    TestTimeLog(dlsym_call);
    TestTimeLog(mcapi_call);
    TestTimeLog(dlsym_call);
};

#include <filesystem>
#include <fstream>
#include "TestNbt.h"
void verifyHashUnique()
{
    std::vector<__int64> hashs;
    std::ifstream file("bedrock_server_SymList.txt");
    bool hasError = false;
    if (file.is_open())
    {
        std::string sym;
        while (std::getline(file, sym))
        {
            auto hash = do_hash2(sym);
            if (std::find(hashs.begin(), hashs.end(), hash) != hashs.end())
            {
                logger.error(sym);
                hasError = true;
            }
            hashs.push_back(hash);
        }
        logger.info("total symbol: {}", hashs.size());
        if (!hasError)
            logger.info("hash verify success");
    }
    else
    {
        logger.error("file \"{}\" not found, hash verify will not be executed", "bedrock_server_SymList.txt");
    }
};
#else
inline void testStaticDlsym(){};
inline void testMCAPI(){};
#endif // ENABLE_TEST_DLSYM
//#include <MC/ItemDescriptor.hpp>
void entry()
{
    logger.consoleLevel = logger.warn.level;
    logger.fileLevel = logger.info.level;
    // ItemDescriptor i1;
    // ItemDescriptor i2;
    // i1 = i2;
    Event::ServerStartedEvent::subscribe([](Event::ServerStartedEvent const& ev) -> bool {
        testRegRecipe();
        testStaticDlsym();
        testMCAPI();
        TestNbt::test();
        TestCommandReg::test();
        TestDBStorage::test();
        EnumGenerator::gen();
        // verifyHashUnique();
        return true;
    });
    Event::RegCmdEvent::subscribe([](Event::RegCmdEvent const& ev) -> bool {
#ifdef ENABLE_TEST_DBSTORAGE
        RemovePlayerCommand::setup(*ev.mCommandRegistry);
        DBTestCommand::setup(*ev.mCommandRegistry);
#endif // ENABLE_TEST_DBSTORAGE
#ifdef ENABLE_TEST_AI
        AiTest::setupCommand(*ev.mCommandRegistry);
#endif // ENABLE_TEST_AI
        return true;
    });
}

// namespace
//{
// bool isEdu = false;
// }
// TClasslessInstanceHook(bool, "?isEducationEditionLevel@LevelData@@QEBA_NXZ")
//{
//     return isEdu;
// }
// TClasslessInstanceHook(void, "?setupStandardServer@ServerCommands@@YAXAEAVMinecraft@@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@1PEAVPermissionsFile@@@Z",
//                        class Minecraft& mc, std::string const&a2, std::string const& a3, class PermissionsFile* a4)
//{
//     isEdu = true;
//     original(this, mc, a2, a3, a4);
//     isEdu = false;
// }

// TClasslessInstanceHook(void, "?updateServerAnnouncement@ServerNetworkHandler@@QEAAXXZ")
//{
//#ifdef DEBUG
//
//    auto v8 = *dAccess<voids<>*>(this, 13 * 8);
//    auto motd = dAccess<char*>(this, 632);
//    using Fn = void (*)(void*, char *, std::string const&, unsigned int, int, int, char);
//    auto v9 = dAccess<Fn>(&v8, 24);
//    auto v10 = dAccess<int>(this, 188 * 4);
//    std::string levelName = "TestName";
//    v9(&v8, motd, levelName, 1, 12, v10, 1);
//#endif // DEBUG
//    //original(this);
// }

#ifdef ABILITYPRO

#include <MC/ServerPlayer.hpp>
#include <MC/Level.hpp>

class Ability
{

public:
    enum Options : unsigned char;
    enum Type;

    Type mType;
    int mValue;
    Options mOptions;

    MCAPI bool getBool() const;
    MCAPI float getFloat() const;
    MCAPI enum Ability::Type getType() const;
    MCAPI void setBool(bool);
};

class Abilities
{

public:
    std::unique_ptr<class PermissionsHandler> mPermissions;
    std::array<Ability, 18> mAbilities;
    std::array<Ability, 8> mCustomAbilityCache;
    int unk320;
    int unk324;
    int unk328;

public:
    MCAPI Abilities(class Abilities const&);
    MCAPI Abilities();
    MCAPI void addSaveData(class CompoundTag&) const;
    MCAPI void forEachAbility(class std::function<void(class Ability&, char const*)> const&, enum Ability::Options);
    MCAPI class Ability& getAbility(enum AbilitiesIndex);
    MCAPI class Ability const& getAbility(enum AbilitiesIndex) const;
    MCAPI bool getBool(enum AbilitiesIndex) const;
    MCAPI enum CommandPermissionLevel getCommandPermissions() const;
    MCAPI class Ability const& getCustomAbilityFromCache(enum AbilitiesIndex) const;
    MCAPI class Ability& getCustomAbilityFromCache(enum AbilitiesIndex);
    MCAPI enum PlayerPermissionLevel getPlayerPermissions() const;
    MCAPI bool isFlying() const;
    MCAPI bool loadSaveData(class CompoundTag const&);
    MCAPI class Abilities& operator=(class Abilities const&);
    MCAPI void setAbility(enum AbilitiesIndex, bool);
    MCAPI void setAbilityDiff(enum AbilitiesIndex, bool, bool&);
    MCAPI void setCommandPermissions(enum CommandPermissionLevel);
    MCAPI void setPlayerPermissions(enum PlayerPermissionLevel);
    MCAPI ~Abilities();
    MCAPI static char const* getAbilityName(enum AbilitiesIndex);
    MCAPI static enum AbilitiesIndex nameToAbilityIndex(std::string const&);

protected:
private:
    MCAPI void _registerAbilities();
    MCAPI static class std::array<char const*, 18> ABILITY_NAMES;
    MCAPI static std::string const TAG;

public:
inline static class std::array<char const*, 18>& ABILITY_NAMES_ = Abilities::ABILITY_NAMES;
};

inline class Abilities* getPlayerAbilities(struct ActorUniqueID const& a0)
{
    class Abilities* (Level::*rv)(struct ActorUniqueID const&);
    *((void**)&rv) = dlsym("?getPlayerAbilities@Level@@UEAAPEAVAbilities@@AEBUActorUniqueID@@@Z");
    return (Global<Level>->*rv)(std::forward<struct ActorUniqueID const&>(a0));
}

enum class AdventureFlag : int
{
    FlagWorldImmutable = 1,
    SettingsFlagsNoPvM = 2,
    SettingsFlagsNoMvP = 4,
    SettingsFlagsUnused = 8,
    SettingsFlagsShowNameTags = 16,
    FlagAutoJump = 32,
    FlagAllowFlight = 64,
    FlagNoClip = 128,
    FlagWorldBuilder = 256,
    FlagFlying = 512,
    FlagMuted = 1024,
};

enum class ActionPermission : int
{
    Mine = 1,
	DoorsAndSwitches = 2,
	OpenContainers = 4,
	AttackPlayers = 8,
	AttackMobs = 16,
	Operator = 32,
	Teleport = 64,
	Build = 128,
	Default = 256,
};

enum class PermissionLevel : int
{
    Visitor,
    Menber,
    Operator,
    Custom,
};
struct AdventureSettings;
inline struct AdventureSettings& getAdventureSettings()
{
    struct AdventureSettings& (Level::*rv)();
    *((void**)&rv) = dlsym("?getAdventureSettings@Level@@UEAAAEAUAdventureSettings@@XZ");
    return (Global<Level>->*rv)();
}

#include <MC/Packet.hpp>
class AdventureSettingsPacket : public Packet
{
public:
    uint64_t mFlag;
    CommandPermissionLevel mCommandPermissionLevel;
    int mActionPermissions;
    PermissionLevel mPermissionLevel;
    int mCustomStoredPermissions;
    ActorUniqueID mUniqueId;

    /*0*/ virtual ~AdventureSettingsPacket();
    /*1*/ virtual enum MinecraftPacketIds getId() const;
    /*2*/ virtual std::string getName() const;
    /*3*/ virtual void write(class BinaryStream&) const;
    /*4*/ virtual bool disallowBatching() const;
    /*5*/ virtual enum StreamReadResult _read(class ReadOnlyBinaryStream&);
    MCAPI AdventureSettingsPacket(struct AdventureSettings const&, class Abilities const&, struct ActorUniqueID, bool);
};

#include <MC/NetworkItemStackDescriptor.hpp>
class AddPlayerPacket : public Packet
{
public:
    std::vector<struct ActorLink> mActorLinks;         // 48
    std::string mName;                                 // 72
    mce::UUID mUuid;                                   // 104
    ActorUniqueID mUniqueId;                           // 120
    ActorRuntimeID mRuntimeId;                         // 128
    std::string mPlatformOnlineId;                     // 136
    Vec3 mPosition;                                    // 168
    Vec3 mVelocity;                                    // 180
    float mPitch;                                      // 192
    float mYaw;                                        // 196
    float mHeadYaw;                                    // 200
    std::vector<std::unique_ptr<DataItem>> mDataItems; // 208, only for read
    Abilities mAbilities;                              // 232
    std::string mDeviceId;                             // 568
    enum BuildPlatform mBuildPlatform;                 // 600
    NetworkItemStackDescriptor mCarriedItem;           // 608
    SynchedActorData* mActorData;                      // 736
public:
    /*0*/ virtual ~AddPlayerPacket();
    /*1*/ virtual enum MinecraftPacketIds getId() const;
    /*2*/ virtual std::string getName() const;
    /*3*/ virtual void write(class BinaryStream&) const;
    /*4*/ virtual bool disallowBatching() const;
    /*5*/ virtual enum StreamReadResult _read(class ReadOnlyBinaryStream&);
    MCAPI AddPlayerPacket(class Player&);
    MCAPI AddPlayerPacket();
};
//TClasslessInstanceHook(void, "?sendToClient@LoopbackPacketSender@@UEAAXAEBVNetworkIdentifier@@AEBVPacket@@E@Z", 
//    NetworkIdentifier const& nid, Packet const& pkt, unsigned char subId)
//{
//    if (pkt.getId() == MinecraftPacketIds::AdventureSettings) {
//        auto& packet = (AdventureSettingsPacket&)pkt;
//        logger.error("noclip: {}", (bool)((int)packet.mFlag & (int)AdventureFlag::FlagNoClip));
//        __debugbreak();
//    }
//    original(this, nid, pkt, subId);
//}

enum AbilitiesIndex : unsigned short
{
    Build = 0,
    Mine,
    DoorAndSwitches,
    OpenContainers,
    AttackPlayers,
    AttackMobs,
    Op,
    Teleport,
    Invulnerable,
    Flying,
    MayFly,
    InstaBuild,
    Lightning,
    FlySpeed,
    WalkSpeed,
    Mute,
    WorldBuilder,
    NoClip,
};
TClasslessInstanceHook(void, "?_sendInternal@NetworkHandler@@AEAAXAEBVNetworkIdentifier@@AEBVPacket@@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z",
              NetworkIdentifier& nid, class Packet& pkt, std::string const& data)
{

    if (pkt.getId() == MinecraftPacketIds::AdventureSettings)
    {
        auto names = Abilities::ABILITY_NAMES_;
        auto& packet = (AdventureSettingsPacket&)pkt;
        logger.error("noclip: {}", (bool)((int)packet.mFlag & (int)AdventureFlag::FlagNoClip));
        //__debugbreak();
    }
    original(this, nid, pkt, data);
}

TInstanceHook(void, "?write@AdventureSettingsPacket@@UEBAXAEAVBinaryStream@@@Z",
              AdventureSettingsPacket, class BinaryStream& bs)
{
    //this->mFlag = this->mFlag | (int)AdventureFlag::FlagNoClip;
    original(this, bs);
}

TInstanceHook(void, "?jumpFromGround@Player@@UEAAXXZ", Player)
{
    auto abilities = getPlayerAbilities(getUniqueID());
    auto noclip = abilities->getAbility(AbilitiesIndex::NoClip).getBool();
    logger.warn("noclip: {} -> {}", noclip, !noclip);
    abilities->setAbility(AbilitiesIndex::NoClip, !noclip);
    AdventureSettingsPacket pkt(getAdventureSettings(), *abilities, getUniqueID(), false);
    sendNetworkPacket(pkt);
    original(this);
}

void setPlayerAbility(Player& player, AbilitiesIndex index, bool value)
{
    ActorUniqueID uid = player.getUniqueID();
    auto abilities = getPlayerAbilities(uid);
    abilities->setAbility(index, value);
    AdventureSettingsPacket pkt(getAdventureSettings(), *abilities, uid, false);
    player.sendNetworkPacket(pkt);
}

using namespace RegisterCommandHelper;
class AbilityProCommand : public Command
{
    AbilitiesIndex mIndex;
    CommandSelector<Player> mPlayer;
    bool mSwitch;
    float mValue;

    virtual void execute(class CommandOrigin const& origin, class CommandOutput& output) const override
    {
        auto players = mPlayer.results(origin);
        std::string names = "";
        for (auto player : players) {
            names += ", " + player->getName();
            setPlayerAbility(*player, mIndex, mSwitch);
        }
        if (names.empty()) {
            output.error("%command.generic.noTarget");
        }
        else
        {
            names = names.substr(2);
            output.success(fmt::format("Success to set ability \"{}\" to {} for {}", magic_enum::enum_name(mIndex), mSwitch, names));
        }
    }

public:
    static void setup(CommandRegistry& registry)
    {
        registry.registerCommand("abilitypro", "Abilities Pro", CommandPermissionLevel::GameMasters, {CommandFlagValue::None}, {(CommandFlagValue)0x80});
        registry.addEnum<AbilitiesIndex>("AbilityPro", {
            {"build", AbilitiesIndex::Build},
            {"mine", AbilitiesIndex::Mine},
            {"doorandswitches", AbilitiesIndex::DoorAndSwitches},
            {"opencontainers", AbilitiesIndex::OpenContainers},
            {"attackplayers", AbilitiesIndex::AttackPlayers},
            {"attackmobs", AbilitiesIndex::AttackMobs},
            {"op", AbilitiesIndex::Op},
            {"teleport", AbilitiesIndex::Teleport},
            {"invulnerable", AbilitiesIndex::Invulnerable},
            {"flying", AbilitiesIndex::Flying},
            {"mayfly", AbilitiesIndex::MayFly},
            {"instabuild", AbilitiesIndex::InstaBuild},
            {"lightning", AbilitiesIndex::Lightning},
            //{"FlySpeed", AbilitiesIndex::FlySpeed},
            //{"WalkSpeed", AbilitiesIndex::WalkSpeed},
            {"mute", AbilitiesIndex::Mute},
            {"worldbuilder", AbilitiesIndex::WorldBuilder},
            {"noclip", AbilitiesIndex::NoClip},
            });
        
        auto playerParam = makeMandatory<AbilityProCommand>(&AbilityProCommand::mPlayer, "target");
        auto indexParam = makeMandatory<CommandParameterDataType::ENUM, AbilityProCommand>(&AbilityProCommand::mIndex, "ability", "AbilityPro");
        auto valueParam = makeMandatory<AbilityProCommand>(&AbilityProCommand::mSwitch, "value");

        registry.registerOverload<AbilityProCommand>("abilitypro", playerParam, indexParam, valueParam);
    }
};

bool inited = ([]() -> bool {
    Event::RegCmdEvent::subscribe_ref([](Event::RegCmdEvent const& ev) -> bool {
        AbilityProCommand::setup(*ev.mCommandRegistry);
        return true;
    });
    return true;
    })();


#endif // ABILITYPRO