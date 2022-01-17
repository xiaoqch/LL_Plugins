#include "pch.h"
#include "TestRegRecipe.h"
#include <EventAPI.h>
#include "TestDBStorage.h"

LARGE_INTEGER freq_;
auto INITPERFORMANCE = QueryPerformanceFrequency(&freq_);

LARGE_INTEGER begin_time;
LARGE_INTEGER end_time;
inline double ns_time() {
    return (end_time.QuadPart - begin_time.QuadPart) * 1000000.0 / freq_.QuadPart;
}

#define TestTimeLog(func, ...)\
QueryPerformanceCounter(&begin_time);\
func(__VA_ARGS__);\
QueryPerformanceCounter(&end_time);\
logger.warn("  {}\t time: {}", #func, ns_time());

inline void static_query() {
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
inline void dlsym_query() {
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

inline void testStaticDlsym() {
    //time: 20194.8 - time: 35094.8
    //time: 269.9   - time: 550.7
    //time: 541.8   - time: 286.2
    //time: 328.3   - time: 302.5
    //time: 280.1   - time: 267.3

    TestTimeLog(static_query);
    TestTimeLog(dlsym_query);
    TestTimeLog(static_query);
    TestTimeLog(dlsym_query);
    TestTimeLog(static_query);
    TestTimeLog(dlsym_query);
}

#include <MC/Level.hpp>
inline double getTickDeltaTime() {
    double (Level::*rv)();
    *((void**)&rv) = dlsym_static("?getTickDeltaTime@Level@@QEBANXZ");
    return (Global<Level>->*rv)();
}

void dlsym_call() {
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

void mcapi_call() {
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

void testMCAPI() {
    TestTimeLog(mcapi_call);
    TestTimeLog(dlsym_call);
    TestTimeLog(mcapi_call);
    TestTimeLog(dlsym_call);
    TestTimeLog(mcapi_call);
    TestTimeLog(dlsym_call);
};

#include <filesystem>
#include <fstream>
#include "AiTest.h"
void verifyHashUnique() {
    std::vector<__int64> hashs;
    std::ifstream file("bedrock_server_SymList.txt");
    bool hasError = false;
    if (file.is_open()) {
        std::string sym;
        while (std::getline(file, sym))
        {
            auto hash = do_hash2(sym);
            if (std::find(hashs.begin(), hashs.end(), hash) != hashs.end()) {
                logger.error(sym);
                hasError = true;
            }
            hashs.push_back(hash);
        }
        logger.info("total symbol: {}", hashs.size());
        if (!hasError)
            logger.info("hash verify success");
    }
    else {
        logger.error("file \"{}\" not found, hash verify will not be executed", "bedrock_server_SymList.txt");
    }
};
void entry() {
    Event::ServerStartedEvent::subscribe([](Event::ServerStartedEvent const& ev)->bool {
        dlsym_static("?EVENT_BEGIN@ActorDefinitionIdentifier@@2V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@B");
        testRegRecipe();
        testStaticDlsym();
        testMCAPI();
        //verifyHashUnique();
        return true;
        });
    Event::RegCmdEvent::subscribe([](Event::RegCmdEvent const& ev)->bool {
        RemovePlayerCommand::setup(*ev.mCommandRegistry);
        AiTest::setupCommand(*ev.mCommandRegistry);
        return true;
        });
}