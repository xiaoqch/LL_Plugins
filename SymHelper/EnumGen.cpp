#include "pch.h"
#include <mc/OffsetHelper.h>
#include "EnumGen.h"
#include "SymHelper.h"
#include "StrHelper.h"
#include <nbt-from-lxl/NBT.h>
#include <mc/Item.h>
//#include <wangheader/HumanoidMonster.hpp>
//#include <wangheader/MobEffect.hpp>
#include <lbpch.h>
using namespace std;

/*
ItemAcquisitionMethod
unordered_map<enum ItemAcquisitionMethod, enum MinecraftEventing::AcquisitionMethod> const MinecraftEventing::mAcquisitionMethodMap
?mAcquisitionMethodMap@MinecraftEventing@@0V?$unordered_map@W4ItemAcquisitionMethod@@W4AcquisitionMethod@MinecraftEventing@@U?$hash@W4ItemAcquisitionMethod@@@std@@U?$equal_to@W4ItemAcquisitionMethod@@@5@V?$allocator@U?$pair@$$CBW4ItemAcquisitionMethod@@W4AcquisitionMethod@MinecraftEventing@@@std@@@5@@std@@B

ItemUseMethod
unordered_map<enum ItemUseMethod, enum MinecraftEventing::UseMethod> const MinecraftEventing::mUseMethodMap
?mUseMethodMap@MinecraftEventing@@0V?$unordered_map@W4ItemUseMethod@@W4UseMethod@MinecraftEventing@@U?$hash@W4ItemUseMethod@@@std@@U?$equal_to@W4ItemUseMethod@@@5@V?$allocator@U?$pair@$$CBW4ItemUseMethod@@W4UseMethod@MinecraftEventing@@@std@@@5@@std@@B dd?

STRING_TO_CONTENT_TYPE
unordered_map<string, enum EducationMetadata::ContentType> const EducationMetadata::STRING_TO_CONTENT_TYPE
?STRING_TO_CONTENT_TYPE@EducationMetadata@@2V?$unordered_map@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@W4ContentType@EducationMetadata@@U?$hash@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@U?$equal_to@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@W4ContentType@EducationMetadata@@@std@@@2@@std@@B

STRING_TO_USER_TYPE
unordered_map<string, enum EducationMetadata::UserType> const EducationMetadata::STRING_TO_USER_TYPE
?STRING_TO_USER_TYPE@EducationMetadata@@2V?$unordered_map@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@W4UserType@EducationMetadata@@U?$hash@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@U?$equal_to@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@W4UserType@EducationMetadata@@@std@@@2@@std@@B

mFormatDictionary
unordered_map<string, vector<string>> I18n::mFormatDictionary
?mFormatDictionary@I18n@@0V?$unordered_map@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@2@U?$hash@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@U?$equal_to@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@2@@std@@@2@@std@@A

mLanguageNames
unordered_map<string, string> I18n::mLanguageNames
?mLanguageNames@I18n@@0V?$unordered_map@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@U?$hash@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@U?$equal_to@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@@2@@std@@A

STRING_TO_PACK_SCOPE
unordered_map<string, enum PackScope> const PackManifest::STRING_TO_PACK_SCOPE
?STRING_TO_PACK_SCOPE@PackManifest@@0V?$unordered_map@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@W4PackScope@@U?$hash@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@U?$equal_to@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@W4PackScope@@@std@@@2@@std@@B

mAlternateContentKeys
unordered_map<string, vector<char> const> PackManifestFactory::mAlternateContentKeys
?mAlternateContentKeys@PackManifestFactory@@2V?$unordered_map@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@$$CBV?$vector@DV?$allocator@D@std@@@2@U?$hash@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@U?$equal_to@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@$$CBV?$vector@DV?$allocator@D@std@@@2@@std@@@2@@std@@A

mContentKeys
unordered_map<string, vector<char> const> PackManifestFactory::mContentKeys
?mContentKeys@PackManifestFactory@@2V?$unordered_map@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@$$CBV?$vector@DV?$allocator@D@std@@@2@U?$hash@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@U?$equal_to@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@$$CBV?$vector@DV?$allocator@D@std@@@2@@std@@@2@@std@@A

mAssertAreas
unordered_map<enum LogArea, bool> const DebugEndPoint::mAssertAreas
?mAssertAreas@DebugEndPoint@@0V?$unordered_map@W4LogArea@@_NU?$hash@W4LogArea@@@std@@U?$equal_to@W4LogArea@@@3@V?$allocator@U?$pair@$$CBW4LogArea@@_N@std@@@3@@std@@B

DWELLING_ROLES
unordered_map<string, enum DwellerRole> const DwellerComponent::DWELLING_ROLES
?DWELLING_ROLES@DwellerComponent@@0V?$unordered_map@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@W4DwellerRole@@U?$hash@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@U?$equal_to@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@W4DwellerRole@@@std@@@2@@std@@B

DWELLING_TYPES
unordered_map<string, enum DwellerComponent::DwellingType> const DwellerComponent::DWELLING_TYPES
?DWELLING_TYPES@DwellerComponent@@0V?$unordered_map@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@W4DwellingType@DwellerComponent@@U?$hash@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@U?$equal_to@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@W4DwellingType@DwellerComponent@@@std@@@2@@std@@B

mPartialDataBuffers
unordered_map<unsigned __int64, string> IncomingDataHelpers::mPartialDataBuffers
?mPartialDataBuffers@IncomingDataHelpers@@3V?$unordered_map@_KV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$hash@_K@2@U?$equal_to@_K@2@V?$allocator@U?$pair@$$CB_KV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@2@@std@@A

imitateMobMap
unordered_map<enum ActorType, enum LevelSoundEvent> const ImitateMobSoundsComponent::imitateMobMap
?imitateMobMap@ImitateMobSoundsComponent@@0V?$unordered_map@W4ActorType@@W4LevelSoundEvent@@U?$hash@W4ActorType@@@std@@U?$equal_to@W4ActorType@@@4@V?$allocator@U?$pair@$$CBW4ActorType@@W4LevelSoundEvent@@@std@@@4@@std@@B

mIndexToVariableNameMap
unordered_map<enum MolangVariableIndex, class HashedString> MolangVariable::mIndexToVariableNameMap
?mIndexToVariableNameMap@MolangVariable@@0V?$unordered_map@W4MolangVariableIndex@@VHashedString@@U?$hash@W4MolangVariableIndex@@@std@@U?$equal_to@W4MolangVariableIndex@@@4@V?$allocator@U?$pair@$$CBW4MolangVariableIndex@@VHashedString@@@std@@@4@@std@@A

sFilterMap
unordered_map<string, struct FilterTest::Definition> sFilterMap
?sFilterMap@@3V?$unordered_map@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UDefinition@FilterTest@@U?$hash@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@U?$equal_to@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UDefinition@FilterTest@@@std@@@2@@std@@A

ENTITY_TYPE_MAP
unordered_map<enum ActorType, struct ActorMapping> ENTITY_TYPE_MAP
?ENTITY_TYPE_MAP@@3V?$unordered_map@W4ActorType@@UActorMapping@@U?$hash@W4ActorType@@@std@@U?$equal_to@W4ActorType@@@4@V?$allocator@U?$pair@$$CBW4ActorType@@UActorMapping@@@std@@@4@@std@@A

_environmentSubfilters
unordered_map<string, struct ActorFilterGroup::LegacyMapping> _environmentSubfilters
?_environmentSubfilters@@3V?$unordered_map@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@ULegacyMapping@ActorFilterGroup@@U?$hash@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@U?$equal_to@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@ULegacyMapping@ActorFilterGroup@@@std@@@2@@std@@A

ItemAcquisitionMethodMap
BidirectionalUnorderedMap<enum ItemAcquisitionMethod, string> const ItemAcquisitionMethodMap::mMap
?mMap@ItemAcquisitionMethodMap@@0V?$BidirectionalUnorderedMap@W4ItemAcquisitionMethod@@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@@B

ItemUseMethodMap
BidirectionalUnorderedMap<enum ItemUseMethod, string> const ItemUseMethodMap::mMap
?mMap@ItemUseMethodMap@@0V?$BidirectionalUnorderedMap@W4ItemUseMethod@@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@@B

actionTypeMap
BidirectionalUnorderedMap<enum ItemStackRequestActionType, string> const ItemStackRequestAction::actionTypeMap
?actionTypeMap@ItemStackRequestAction@@0V?$BidirectionalUnorderedMap@W4ItemStackRequestActionType@@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@@B

ParticleTypeMap
BidirectionalUnorderedMap<enum ParticleType, string> const ParticleTypeMap::map
?map@ParticleTypeMap@@0V?$BidirectionalUnorderedMap@W4ParticleType@@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@@B

actionTypeMap
BidirectionalUnorderedMap<enum ItemUseInventoryTransaction::ActionType, string> const ItemUseInventoryTransaction::actionTypeMap
?actionTypeMap@ItemUseInventoryTransaction@@0V?$BidirectionalUnorderedMap@W4ActionType@ItemUseInventoryTransaction@@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@@B

inventoryTransactionErrorMap
BidirectionalUnorderedMap<enum InventoryTransactionError, string> const InventoryTransaction::inventoryTransactionErrorMap
?inventoryTransactionErrorMap@InventoryTransaction@@0V?$BidirectionalUnorderedMap@W4InventoryTransactionError@@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@@B

mCustomSpawnEggs
unordered_map<unsigned int, string> ActorPlacerItem::mCustomSpawnEggs
?mCustomSpawnEggs@ActorPlacerItem@@0V?$unordered_map@IV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$hash@I@2@U?$equal_to@I@2@V?$allocator@U?$pair@$$CBIV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@2@@std@@A

mUVTextureMap
unordered_map<class HashedString, struct TextureUVCoordinateSet> ActorPlacerItem::mUVTextureMap
?mUVTextureMap@ActorPlacerItem@@0V?$unordered_map@VHashedString@@UTextureUVCoordinateSet@@U?$hash@VHashedString@@@std@@U?$equal_to@VHashedString@@@4@V?$allocator@U?$pair@$$CBVHashedString@@UTextureUVCoordinateSet@@@std@@@4@@std@@A

transactionTypeMap
BidirectionalUnorderedMap<enum ComplexInventoryTransaction::Type, string> const ComplexInventoryTransaction::transactionTypeMap
?transactionTypeMap@ComplexInventoryTransaction@@0V?$BidirectionalUnorderedMap@W4Type@ComplexInventoryTransaction@@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@@B

mSubcomponentMap
unordered_map<string, function<unique_ptr<class OnHitSubcomponent> (void)>> ProjectileFactory::mSubcomponentMap
?mSubcomponentMap@ProjectileFactory@@0V?$unordered_map@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$function@$$A6A?AV?$unique_ptr@VOnHitSubcomponent@@U?$default_delete@VOnHitSubcomponent@@@std@@@std@@XZ@2@U?$hash@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@U?$equal_to@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$function@$$A6A?AV?$unique_ptr@VOnHitSubcomponent@@U?$default_delete@VOnHitSubcomponent@@@std@@@std@@XZ@2@@std@@@2@@std@@A

mIdToSpecialCompound
unordered_map<int, int> CompoundItem::mIdToSpecialCompound
?mIdToSpecialCompound@CompoundItem@@0V?$unordered_map@HHU?$hash@H@std@@U?$equal_to@H@2@V?$allocator@U?$pair@$$CBHH@std@@@2@@std@@A

mTypeToSpecialCompound
unordered_map<int, class ItemInstance> CompoundItem::mTypeToSpecialCompound
?mTypeToSpecialCompound@CompoundItem@@0V?$unordered_map@HVItemInstance@@U?$hash@H@std@@U?$equal_to@H@3@V?$allocator@U?$pair@$$CBHVItemInstance@@@std@@@3@@std@@A

unordered_map<enum ContainerEnumName, string, struct ContainerEnumNameHasher> ContainerCollectionNameMap
?ContainerCollectionNameMap@@3V?$unordered_map@W4ContainerEnumName@@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UContainerEnumNameHasher@@U?$equal_to@W4ContainerEnumName@@@3@V?$allocator@U?$pair@$$CBW4ContainerEnumName@@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@3@@std@@A

ItemStackNetResultMap
BidirectionalUnorderedMap<enum ItemStackNetResult, string> const ItemStackNetResultMap::mMap
?mMap@ItemStackNetResultMap@@0V?$BidirectionalUnorderedMap@W4ItemStackNetResult@@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@@B

pushSlotPredictionResultMap
BidirectionalUnorderedMap<enum SparseContainerClient::PushSlotPredictionResult, string> const SparseContainerClient::pushSlotPredictionResultMap
?pushSlotPredictionResultMap@SparseContainerClient@@0V?$BidirectionalUnorderedMap@W4PushSlotPredictionResult@SparseContainerClient@@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@@B

mComplexAliasLookupMap
unordered_map<class HashedString, function<string (short)>> ItemRegistry::mComplexAliasLookupMap
?mComplexAliasLookupMap@ItemRegistry@@0V?$unordered_map@VHashedString@@V?$function@$$A6A?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@F@Z@std@@U?$hash@VHashedString@@@3@U?$equal_to@VHashedString@@@3@V?$allocator@U?$pair@$$CBVHashedString@@V?$function@$$A6A?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@F@Z@std@@@std@@@3@@std@@A

mIdToItemMap
unordered_map<int, class WeakPtr<class Item>> ItemRegistry::mIdToItemMap
?mIdToItemMap@ItemRegistry@@0V?$unordered_map@HV?$WeakPtr@VItem@@@@U?$hash@H@std@@U?$equal_to@H@3@V?$allocator@U?$pair@$$CBHV?$WeakPtr@VItem@@@@@std@@@3@@std@@A

mItemAliasLookupMap
unordered_map<class HashedString, struct ItemRegistry::ItemAlias> ItemRegistry::mItemAliasLookupMap
?mItemAliasLookupMap@ItemRegistry@@0V?$unordered_map@VHashedString@@UItemAlias@ItemRegistry@@U?$hash@VHashedString@@@std@@U?$equal_to@VHashedString@@@5@V?$allocator@U?$pair@$$CBVHashedString@@UItemAlias@ItemRegistry@@@std@@@5@@std@@A

mLegacyIDToNameMap
unordered_map<short, class HashedString> ItemRegistry::mLegacyIDToNameMap
?mLegacyIDToNameMap@ItemRegistry@@0V?$unordered_map@FVHashedString@@U?$hash@F@std@@U?$equal_to@F@3@V?$allocator@U?$pair@$$CBFVHashedString@@@std@@@3@@std@@A

mNameToItemMap
unordered_map<class HashedString, class WeakPtr<class Item>> ItemRegistry::mNameToItemMap
?mNameToItemMap@ItemRegistry@@0V?$unordered_map@VHashedString@@V?$WeakPtr@VItem@@@@U?$hash@VHashedString@@@std@@U?$equal_to@VHashedString@@@4@V?$allocator@U?$pair@$$CBVHashedString@@V?$WeakPtr@VItem@@@@@std@@@4@@std@@A

mReverseAliasLookupMap
unordered_map<unsigned __int64, struct ItemRegistry::ItemHashAlias> ItemRegistry::mReverseAliasLookupMap
?mReverseAliasLookupMap@ItemRegistry@@0V?$unordered_map@_KUItemHashAlias@ItemRegistry@@U?$hash@_K@std@@U?$equal_to@_K@4@V?$allocator@U?$pair@$$CB_KUItemHashAlias@ItemRegistry@@@std@@@4@@std@@A

BLOCK_REPLACE_DATA_MAP
unordered_map<string, function<void (int, class CompoundTag &)>> BlockSerializationUtils::BLOCK_REPLACE_DATA_MAP
?BLOCK_REPLACE_DATA_MAP@BlockSerializationUtils@@3V?$unordered_map@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$function@$$A6AXHAEAVCompoundTag@@@Z@2@U?$hash@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@U?$equal_to@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$function@$$A6AXHAEAVCompoundTag@@@Z@2@@std@@@2@@std@@A

mLootingFunctions
unordered_map<class HashedString, function<unique_ptr<class LootItemFunction> (class Json::Value &, vector<unique_ptr<class LootItemCondition>> &)>> const LootItemFunction::mLootingFunctions
?mLootingFunctions@LootItemFunction@@0V?$unordered_map@VHashedString@@V?$function@$$A6A?AV?$unique_ptr@VLootItemFunction@@U?$default_delete@VLootItemFunction@@@std@@@std@@AEAVValue@Json@@AEAV?$vector@V?$unique_ptr@VLootItemCondition@@U?$default_delete@VLootItemCondition@@@std@@@std@@V?$allocator@V?$unique_ptr@VLootItemCondition@@U?$default_delete@VLootItemCondition@@@std@@@std@@@2@@2@@Z@std@@U?$hash@VHashedString@@@3@U?$equal_to@VHashedString@@@3@V?$allocator@U?$pair@$$CBVHashedString@@V?$function@$$A6A?AV?$unique_ptr@VLootItemFunction@@U?$default_delete@VLootItemFunction@@@std@@@std@@AEAVValue@Json@@AEAV?$vector@V?$unique_ptr@VLootItemCondition@@U?$default_delete@VLootItemCondition@@@std@@@std@@V?$allocator@V?$unique_ptr@VLootItemCondition@@U?$default_delete@VLootItemCondition@@@std@@@std@@@2@@2@@Z@std@@@std@@@3@@std@@B

mPotionsByName
unordered_map<string, int> Potion::mPotionsByName
?mPotionsByName@Potion@@0V?$unordered_map@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@HU?$hash@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@U?$equal_to@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@H@std@@@2@@std@@A

BlockNameIdToTagsMap
unordered_map<string, vector<class HashedString>> const VanillaTagMaps::BlockNameIdToTagsMap
?BlockNameIdToTagsMap@VanillaTagMaps@@3V?$unordered_map@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$vector@VHashedString@@V?$allocator@VHashedString@@@std@@@2@U?$hash@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@U?$equal_to@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$vector@VHashedString@@V?$allocator@VHashedString@@@std@@@2@@std@@@2@@std@@B

ItemNameIdToTagsMap
unordered_map<string, vector<class HashedString>> const VanillaTagMaps::ItemNameIdToTagsMap
?ItemNameIdToTagsMap@VanillaTagMaps@@3V?$unordered_map@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$vector@VHashedString@@V?$allocator@VHashedString@@@std@@@2@U?$hash@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@U?$equal_to@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$vector@VHashedString@@V?$allocator@VHashedString@@@std@@@2@@std@@@2@@std@@B

JOINT_TYPE_TO_NAME
unordered_map<int, string> const JigsawEditorData::JOINT_TYPE_TO_NAME
?JOINT_TYPE_TO_NAME@JigsawEditorData@@0V?$unordered_map@HV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$hash@H@2@U?$equal_to@H@2@V?$allocator@U?$pair@$$CBHV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@2@@std@@B

mRegisteredCerealComponents
unordered_map<string, struct BlockComponentFactory::Constructor> BlockComponentFactory::mRegisteredCerealComponents
?mRegisteredCerealComponents@BlockComponentFactory@@2V?$unordered_map@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UConstructor@BlockComponentFactory@@U?$hash@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@U?$equal_to@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UConstructor@BlockComponentFactory@@@std@@@2@@std@@A

mBlockLookupMap
unordered_map<string, class BlockGraphics *> BlockGraphics::mBlockLookupMap
?mBlockLookupMap@BlockGraphics@@2V?$unordered_map@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PEAVBlockGraphics@@U?$hash@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@U?$equal_to@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PEAVBlockGraphics@@@std@@@2@@std@@A

mBlocks
unordered_map<unsigned int, class BlockGraphics *> BlockGraphics::mBlocks
?mBlocks@BlockGraphics@@0V?$unordered_map@IPEAVBlockGraphics@@U?$hash@I@std@@U?$equal_to@I@3@V?$allocator@U?$pair@$$CBIPEAVBlockGraphics@@@std@@@3@@std@@A

SPAWN_RING_OFFSETS
unordered_set<class ChunkPos> const Spawner::SPAWN_RING_OFFSETS
?SPAWN_RING_OFFSETS@Spawner@@0V?$unordered_set@VChunkPos@@U?$hash@VChunkPos@@@std@@U?$equal_to@VChunkPos@@@3@V?$allocator@VChunkPos@@@3@@std@@B

mValidIngredients
unordered_set<class PotionBrewing::Ingredient> PotionBrewing::mValidIngredients
?mValidIngredients@PotionBrewing@@0V?$unordered_set@VIngredient@PotionBrewing@@U?$hash@VIngredient@PotionBrewing@@@std@@U?$equal_to@VIngredient@PotionBrewing@@@4@V?$allocator@VIngredient@PotionBrewing@@@4@@std@@A

mValidRecipeInputs
unordered_set<class PotionBrewing::Ingredient> PotionBrewing::mValidRecipeInputs
?mValidRecipeInputs@PotionBrewing@@0V?$unordered_set@VIngredient@PotionBrewing@@U?$hash@VIngredient@PotionBrewing@@@std@@U?$equal_to@VIngredient@PotionBrewing@@@4@V?$allocator@VIngredient@PotionBrewing@@@4@@std@@A

.data:00007FF6B0EF2330 ; private: static class std::vector<class SharedPtr<class Item>, class std::allocator<class SharedPtr<class Item>>> ItemRegistry::mItemRegistry
.data:00007FF6B0EF2330 ?mItemRegistry@ItemRegistry@@0V?$vector@V?$SharedPtr@VItem@@@@V?$allocator@V?$SharedPtr@VItem@@@@@std@@@std@@A

.data:00007FF6B0EF2348 ; public: static class std::vector<class SharedPtr<class Item>, class std::allocator<class SharedPtr<class Item>>> ItemRegistry::mDeadItemRegistry
.data:00007FF6B0EF2348 ?mDeadItemRegistry@ItemRegistry@@2V?$vector@V?$SharedPtr@VItem@@@@V?$allocator@V?$SharedPtr@VItem@@@@@std@@@std@@A

.data:00007FF6B0EF2440 ; private: static class std::vector<class HashedString, class std::allocator<class HashedString>> ItemRegistry::mAttachableDefinitions
.data:00007FF6B0EF2440 ?mAttachableDefinitions@ItemRegistry@@0V?$vector@VHashedString@@V?$allocator@VHashedString@@@std@@@std@@A

.data:00007FF6B0F04C38 ; private: static class std::vector<class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>>, class std::allocator<class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>>>> EnchantUtils::mEnchantmentNames
.data:00007FF6B0F04C38 ?mEnchantmentNames@EnchantUtils@@0V?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@A xmmword ?

.data:00007FF6B0F39928 ; private: static class std::vector<class PotionBrewing::Ingredient, class std::allocator<class PotionBrewing::Ingredient>> PotionBrewing::mValidContainers
.data:00007FF6B0F39928 ?mValidContainers@PotionBrewing@@0V?$vector@VIngredient@PotionBrewing@@V?$allocator@VIngredient@PotionBrewing@@@std@@@std@@A

.data:00007FF6B0F485D0 ; private: static class std::vector<enum ActorDamageCause, class std::allocator<enum ActorDamageCause>> const ShieldItemUtils::mAlwaysBlockableDamageCauses
.data:00007FF6B0F485D0 ?mAlwaysBlockableDamageCauses@ShieldItemUtils@@0V?$vector@W4ActorDamageCause@@V?$allocator@W4ActorDamageCause@@@std@@@std@@B

?playerPermissionLevelToString@PermissionsHandler@@SA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEBW4PlayerPermissionLevel@@@Z

; public: static class std::vector<class Motive const *, class std::allocator<class Motive const *>> Motive::getAllMotivesAsList(void)
?getAllMotivesAsList@Motive@@SA?AV?$vector@PEBVMotive@@V?$allocator@PEBVMotive@@@std@@@std@@XZ proc near

.data:00007FF6B0E78A70 ; __int64 ItemStack::EMPTY_ITEM[17]
.data:00007FF6B0E78A70 ?EMPTY_ITEM@ItemStack@@2V1@B dq ?       ; DATA XREF: _dynamic_initializer_for__ItemStack__EMPTY_ITEM__+4↑o


.data:00007FF6B0EEA330 ; void *BlockTypeRegistry::mBlockLookupMap
.data:00007FF6B0EEA330 ?mBlockLookupMap@BlockTypeRegistry@@0V?$map@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$SharedPtr@VBlockLegacy@@@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$SharedPtr@VBlockLegacy@@@@@std@@@2@@std@@A dq ?

.data:00007FF6B0EEA340 ; struct EntityRegistryOwned *BlockTypeRegistry::mEntities
.data:00007FF6B0EEA340 ?mEntities@BlockTypeRegistry@@0V?$OwnerPtrT@UEntityRegistryRefTraits@@@@A dq ?


lookupActualEntityType
BiomeRegistry::lookupById
 BlockTypeRegistry::lookupByName

*/

#define LOG_VAR(var) std::cout << #var" :\t" << var << std::endl;

#define ITER_TYPE_MAP(typeMap) \
for (auto& [type, name] : typeMap) {\
cout << "    " << name << " = " << (int)type << "," << endl;\
}\

namespace I18n {
    string get(string const& key) {
        string str;
        return SymCall("?get@I18n@@SA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEBV23@@Z",
            string&, string&, string const&)(str, key);
    }
    string get(string const& key, vector<string>& var) {
        string str;
        return SymCall("?get@I18n@@SA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEBV23@AEBV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@3@@Z",
            string&, string&, string const&, vector<string>&)(str, key, var);
    }
}

struct voids {
    void***** v[1000];
};

short getBlockItemId(BlockLegacy* bll) {
    return SymCall("?getBlockItemId@BlockLegacy@@QEBAFXZ", short, BlockLegacy*)(bll);
}

BlockLegacy* getFromWeakPtr(void* weakptr) {
    return SymCall("?get@?$WeakPtr@VBlockLegacy@@@@QEBAPEAVBlockLegacy@@XZ", BlockLegacy*, void*)(weakptr);
}
Block* getBlockFromLegacy(BlockLegacy* bl) {
    return SymCall("?getRenderBlock@BlockLegacy@@UEBAAEBVBlock@@XZ", Block*, BlockLegacy*)(bl);
}

void genBlockType() {
    uintptr_t weakPtrBlockLegacyStart = (uintptr_t)dlsym("?mAir@BedrockBlockTypes@@3V?$WeakPtr@VBlockLegacy@@@@A");
    uintptr_t weakPtrBlockLegacyEnd = (uintptr_t)dlsym("?mSculkShrieker@VanillaBlockTypes@@3V?$WeakPtr@VBlockLegacy@@@@A");
    size_t size = sizeof(weakPtrBlockLegacyStart);
    std::cout << "enum BlockType : short{" << std::endl;
    for (uintptr_t ptr = weakPtrBlockLegacyStart; ptr <= weakPtrBlockLegacyEnd; ptr += size) {
        auto blockLegacy = getFromWeakPtr((void*)ptr);
        if (!blockLegacy) {
            //cout << (ptr - weakPtrBlockLegacyStart) / 8 << endl;
            continue;
        }
        auto blockName = offBlockLegacy::getFullName(blockLegacy);
        auto blockItemId = getBlockItemId(blockLegacy);
        auto block = getBlockFromLegacy(blockLegacy);
        auto offset = (ptr - weakPtrBlockLegacyStart) / 8;
        string tmp = "m_" + blockName.substr(blockName.find(':') + 1);
        auto enumName = StrHelper::toCamelCase(tmp);
        //LOG_VAR(blockName)
        //LOG_VAR(blockItemId)
        //LOG_VAR(offset)
        std::cout << "    " << enumName << " = " << blockItemId << ", // " << blockName << std::endl;
    }
    std::cout << "};" << std::endl;
}

void genItemStackRequestActionType() {
    auto actionTypeMap = (unordered_map<char, string>*)dlsym("?actionTypeMap@ItemStackRequestAction@@0V?$BidirectionalUnorderedMap@W4ItemStackRequestActionType@@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@@B");
    
    cout << "enum ItemStackRequestActionType : char {" << endl;
    ITER_TYPE_MAP(*actionTypeMap);
    cout << "};" << endl;
}

void genComplexInventoryTransactionType() {
    auto transactionTypeMap = (unordered_map<char, string>*)dlsym("?transactionTypeMap@ComplexInventoryTransaction@@0V?$BidirectionalUnorderedMap@W4Type@ComplexInventoryTransaction@@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@@B");

    cout << "enum ComplexInventoryTransactionType : unsigned int {" << endl;
    ITER_TYPE_MAP(*transactionTypeMap)
    cout << "};" << endl;
}

void genContainerType() {
    auto containerTypeMap = (unordered_map<char, string>*)dlsym("?containerTypeMap@Container@@1V?$BidirectionalUnorderedMap@W4ContainerType@@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@@B");

    cout << "enum class ContainerType : char {" << endl;
    ITER_TYPE_MAP(*containerTypeMap);
    cout << "};" << endl;
}

void genActorType() {
    string typeName;
    cout << "enum ActorType : unsigned short {" << endl;
    for (int t = 0; t < MAXUINT16; t++) {
        string entityType;
        string nameSpace;
        SymCall("?EntityTypeToStringAndNamespace@@YAXW4ActorType@@AEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@1@Z",
            void, unsigned short, string&, string&)(t, entityType, nameSpace);
        if (entityType != "unknown")
            cout << "    " << entityType << " = " << t << ", // " << nameSpace << ":" << entityType << endl;
    }
    cout << "};" << endl;
}

void genItemStackNetResult() {
    auto itemStackNetResultMap = (unordered_map<char, string>*)dlsym("?mMap@ItemStackNetResultMap@@0V?$BidirectionalUnorderedMap@W4ItemStackNetResult@@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@@B");

    cout << "enum ItemStackNetResult : char {" << endl;
    ITER_TYPE_MAP(*itemStackNetResultMap);
    cout << "};" << endl;
}

void genContainerCollectionNameMap() {
    auto containerNameMap = (unordered_map<char, string>*)dlsym("?ContainerCollectionNameMap@@3V?$unordered_map@W4ContainerEnumName@@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UContainerEnumNameHasher@@U?$equal_to@W4ContainerEnumName@@@3@V?$allocator@U?$pair@$$CBW4ContainerEnumName@@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@3@@std@@A");

    cout << "enum ContainerCollectionNameMap : char {" << endl;
    for (auto& ctn : *containerNameMap) {
        string enumName = StrHelper::toCamelCase(ctn.second);
        cout << "    " << enumName << " = " << (int)ctn.first << ", //" << ctn.second << endl;
    }
    cout << "};" << endl;
}
void genContainerOffset() {
    auto containerNameMap = (unordered_map<char, string>*)dlsym("?ContainerCollectionNameMap@@3V?$unordered_map@W4ContainerEnumName@@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UContainerEnumNameHasher@@U?$equal_to@W4ContainerEnumName@@@3@V?$allocator@U?$pair@$$CBW4ContainerEnumName@@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@3@@std@@A");

    cout << "enum ContainerOffset : char {" << endl;
    for (auto& ctn : *containerNameMap) {
        string enumName = StrHelper::toCamelCase(ctn.second);
        char fakeContainer[49] = {};
        fakeContainer[48] = ctn.first;
        char offset = SymCall("?_getContainerOffset@PlayerUIContainerModel@@MEBAHXZ", char, void*)((void*)fakeContainer);
        if(offset)
            cout << "    " << enumName << " = " << (int)offset << ", //" << ctn.second << endl;
    }
    cout << "};" << endl;
}

void genLegacyIDToNameMap() {
    auto containerNameMap = (unordered_map<short, HashedString>*)dlsym("?mLegacyIDToNameMap@ItemRegistry@@0V?$unordered_map@FVHashedString@@U?$hash@F@std@@U?$equal_to@F@3@V?$allocator@U?$pair@$$CBFVHashedString@@@std@@@3@@std@@A");

    cout << "enum LegacyIDToNameMap : char {" << endl;
    for (auto& ctn : *containerNameMap)
        cout << "    " << ctn.second.getString() << " = " << (int)ctn.first << "," << endl;
    cout << "};" << endl;
}

void genParticleType() {
    auto particleTypeMap = (unordered_map<char, string>*)dlsym("?map@ParticleTypeMap@@0V?$BidirectionalUnorderedMap@W4ParticleType@@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@@B");

    cout << "enum class ParticleType : unsigned int {" << endl;
    ITER_TYPE_MAP(*particleTypeMap);
    cout << "};" << endl;
}

void genBlockActorType() {
    cout << "enum BlockActorType : char {" << endl;
    auto nameIdMap = (map<int, string>*)dlsym("?mClassIdMap@BlockActor@@0V?$map@W4BlockActorType@@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@W4BlockActorType@@@3@V?$allocator@U?$pair@$$CBW4BlockActorType@@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@3@@std@@B");
    auto idNameMap = (map<string, int>*)dlsym("?mIdClassMap@BlockActor@@0V?$map@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@W4BlockActorType@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@W4BlockActorType@@@std@@@2@@std@@B");

    for (auto& mapIter : *nameIdMap) {
        if (idNameMap->at(mapIter.second) != mapIter.first)
            cout << "Error: " << endl;
        cout << "    " << mapIter.second << " = " << (int)mapIter.first << "," << endl;
    }
    cout << "};" << endl;
}


//void genJigsawStructureMap() {
//    cout << "enum JigsawStructureMap : char {" << endl;
//    auto man= SymCall("?getJigsawStructureRegistry@Level@@UEBAAEBVJigsawStructureRegistry@@XZ",
//        void*, Level*)(getLevel());
//    auto ele = SymCall("?getJigsawStructureElementRegistry@JigsawStructureRegistry@@QEAAAEAVJigsawStructureElementRegistry@@XZ",
//        void*, void*)(man);
//    auto nameIdMap = dAccess< map<string, int>*>(ele, 24);
//
//    for (auto& mapIter : *nameIdMap)
//        cout << "    " << mapIter.first << " = " << (int)mapIter.second << "," << endl;
//    cout << "};" << endl;
//}


void genEnchantType() {
    cout << "enum EnchantType : char {" << endl;
    //auto mEnchantmentNames = (vector<string>*)dlsym(
    //    "?mEnchantmentNames@EnchantUtils@@0V?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@A"
    //);
    //for (auto& name : *mEnchantmentNames) {
    //    auto hname = HashedString(name.c_str());
    //    char id = SymCall("?getEnchantmentId@EnchantUtils@@SA?AW4Type@Enchant@@AEBVHashedString@@@Z",
    //        char, HashedString&)(hname);
    //    cout << "    " << name << " = " << (int)id << "," << endl;
    //}
    class Enchant {
    public:
        char type; //8
        //char filler[3]; //9
        int frequency; //12
        char isLootable; //16
        //char filler2[3];
        int primarySlots; //20
        int secondarySlots; //24
        int maxLevel; //28
        string stringId; //32
        HashedString description; //64
        char isAvailable; //112

        virtual ~Enchant()=0;
        virtual bool isCompatibleWith(int /*enum Enchant::Type*/) = 0;
        virtual int getMinCost(int) = 0;
        virtual int getMaxCost(int) = 0;
        // {bedrock_server_mod.exe!`anonymous namespace'::availableSetCountOfOne(void)}
        virtual void* availableSetCountOfOne() = 0;
        virtual int getMaxLevel(void) = 0;
        virtual int getDamageProtection(int, class ActorDamageSource const&) = 0;
        virtual float getDamageBonus(int, class Actor const&) = 0;
        virtual void doPostAttack(class Actor&, class Actor&, int) = 0;
        virtual void doPostHurt(class ItemInstance&, class Actor&, class Actor&, int) = 0;
        virtual void unk_vfn_10() = 0;
        virtual void unk_vfn_11() = 0;
        virtual void unk_vfn_12() = 0;
        virtual void unk_vfn_13() = 0;
        virtual bool _isValidEnchantmentTypeForCategory(int /*enum Enchant::Type*/) = 0;

        string getDisplayName() {
            return I18n::get(stringId);
        }
    };
    auto mEnchantments = (vector<unique_ptr<Enchant>>*)dlsym(
        "?mEnchants@Enchant@@2V?$vector@V?$unique_ptr@VEnchant@@U?$default_delete@VEnchant@@@std@@@std@@V?$allocator@V?$unique_ptr@VEnchant@@U?$default_delete@VEnchant@@@std@@@std@@@2@@std@@A"
    );
    //cout << "type,frequency,isLootable,primarySlots,secondarySlots,maxLevel,stringId,description,isAvailable" << endl;
    for (auto& enptr : *mEnchantments) {
        Enchant* ench = enptr.get();
        string enumName = StrHelper::toCamelCase("m_" + ench->description.getString()).substr(1);
        cout << "    " << enumName << " = " << (int)ench->type << ", //"
            << "maxLevel: " << ench->getMaxLevel()
            << ", frequency: " << ench->frequency
            << ", name: " << ench->getDisplayName()
            << ", description: " << ench->description.getString()
            << endl;
        //cout << (int)ench->type << "," << ench->frequency << "," << (int)ench->isLootable << ","
        //    << ench->primarySlots << "," << ench->secondarySlots << "," << ench->getMaxLevel() << "," 
        //    << ench->getDisplayName() << "," << ench->description.getString() << "," << (int)ench->isAvailable << endl;
    }
    cout << "};" << endl;
}


void genEffectType() {
    class MobEffect {
    public:
        struct FactorCalculationData {
            bool padding_duration;
            float factor_target;//4
            int factor_current;//8
            char filler[80 - 12];//12
            int change_timestamp;//80
            float factor_previous;//84
            bool had_last_tick;//88
            bool had_applied;//89
            Tag* save() {
                Tag* tag = Tag::createTag(TagType::Compound);
                SymCall("?save@FactorCalculationData@MobEffect@@QEBA?AV?$unique_ptr@VCompoundTag@@U?$default_delete@VCompoundTag@@@std@@@std@@XZ",
                    Tag**, FactorCalculationData*, Tag**)(this, &tag);
                return tag;
            }
        };
        int id; // 8
        bool isHarmful; //12
        float colorR;//16
        float colorG;//20
        float colorB;//24
        int unk28;//28, 0x3f800000
        string locName;//32
        int icon;//64
        float durationModifier;//isHarmful?0.5:1.0
        char unk72;
        string resourceName;//80
        string iconName;//112
        void* unk144;
        HashedString componentName;//152
        shared_ptr<class Amplifier> valueAmplifier;//200
        shared_ptr<Amplifier> durationAmplifier;//216
        vector<pair<class Attribute const*, shared_ptr<class AttributeBuffer>>> attributeBuffs;//232
        vector<pair<Attribute*, shared_ptr<class AttributeModifier>>> attributeModifiers;//256
        FactorCalculationData fcd;//280

        virtual ~MobEffect()=0;
        virtual void applyEffects(Actor*, int, int) = 0;
        virtual void removeEffects(Actor*) = 0;
        virtual void applyInstantaneousEffect(Actor*, Actor*, Actor*, int, float) = 0;
        virtual void unk_vfn_4() = 0;
        virtual float getAttributeModifierValue(int, class AttributeModifier const&) = 0;

        string getDisplayName() {
            return I18n::get(locName);
        }
    };//376

    auto mMobEffects = (MobEffect**)dlsym("?mMobEffects@MobEffect@@2PAV?$unique_ptr@VMobEffect@@U?$default_delete@VMobEffect@@@std@@@std@@A");

    cout << "enum EffectType : short {" << endl;
    for (auto index = 0;;++index) {
        auto effect = mMobEffects[index];
        if (!effect)
            break;
        string enumName = StrHelper::toCamelCase("m_" + effect->resourceName).substr(1);
        string str = TagToSNBT(effect->fcd.save());
        cout << "    " << enumName << " = " << effect->id << ", //"
            //<< "componentName: " << effect->componentName.getString()
            << "resourceName: " << effect->resourceName
            << ", name: " << effect->getDisplayName()
            << endl;
    }
    cout << "};" << endl;
}

void genDamageCause() {
    cout << "enum ActorDagageCause : unsigned int {" << endl;
    for (unsigned int t = 0; t < MAXUINT16; t++) {
        auto& typeName = SymCall("?lookupCauseName@ActorDamageSource@@SAAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@W4ActorDamageCause@@@Z",
            string&, unsigned int)(t);
        char newType = SymCall("?lookupCause@ActorDamageSource@@SA?AW4ActorDamageCause@@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z",
            char, string&)(typeName);
        if (t == newType)
            cout << "    " << typeName << " = " << (int)t << "," << endl;
    }
    cout << "};" << endl;
}

void genBlockGeometry() {
    cout << "enum BlockGeometry : unsigned int {" << endl;
    unordered_map<string, class BlockGraphics*> mBlockLookupMap = 
        *(unordered_map<string, class BlockGraphics*>*)dlsym(
        "?mBlockLookupMap@BlockGraphics@@2V?$unordered_map@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PEAVBlockGraphics@@U?$hash@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@U?$equal_to@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PEAVBlockGraphics@@@std@@@2@@std@@A"
    );
    map<string, class Model*> mModels = *(map<string, class Model*>*)dlsym(
        "?mModels@BlockGraphics@@0V?$map@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$unique_ptr@UModel@BlockGeometry@@U?$default_delete@UModel@BlockGeometry@@@std@@@2@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$unique_ptr@UModel@BlockGeometry@@U?$default_delete@UModel@BlockGeometry@@@std@@@2@@std@@@2@@std@@A"
    );
    map<string, class TessellatedModel*> mTessellatedModels = *(map<string, class TessellatedModel*>*)dlsym(
        "?mTessellatedModels@BlockGraphics@@0V?$map@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$unique_ptr@VTessellatedModel@BlockGeometry@@U?$default_delete@VTessellatedModel@BlockGeometry@@@std@@@2@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$unique_ptr@VTessellatedModel@BlockGeometry@@U?$default_delete@VTessellatedModel@BlockGeometry@@@std@@@2@@std@@@2@@std@@A"
    );
    unordered_map<unsigned int, class BlockGraphics*> mBlocks = *(unordered_map<unsigned int, class BlockGraphics*>*)dlsym(
        "?mBlocks@BlockGraphics@@0V?$unordered_map@IPEAVBlockGraphics@@U?$hash@I@std@@U?$equal_to@I@3@V?$allocator@U?$pair@$$CBIPEAVBlockGraphics@@@std@@@3@@std@@A"
    );
    void** mTerrainTextureAtlas = (void**)dlsym(
        "?mTerrainTextureAtlas@BlockGraphics@@1V?$weak_ptr@VAtlasItemManager@@@std@@A"
    );


    cout << "};" << endl;
}

vector<string> getActorDebugText(Actor* actor) {
    vector<string> text;
    SymCall("?getDebugText@Actor@@UEAAXAEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@@Z",
        void, Actor*, vector<string>&)(actor, text);
    return text;
}

bool setStatusFlag(Actor* actor, int flag, bool val) {
    return SymCall("?setStatusFlag@Actor@@QEAA_NW4ActorFlags@@_N@Z",
        bool, Actor*, int, bool)(actor, flag, val);
}

void genActorFlags(Actor* actor) {
    cout << "enum class ActorFlags : int {" << endl;
    int flagMax = 97;
    for (int i = 0; i <= flagMax; ++i) {
        setStatusFlag(actor, i, false);
    }
    for (int i = 0; i <= flagMax; ++i) {
        if(i!=0)
            setStatusFlag(actor, i-1, false);
        setStatusFlag(actor, i, true);
        auto text = getActorDebugText(actor);
        if (text.size() < 6)
            continue;
        string flagName = text[5].substr(1);
        string enumName = StrHelper::toCamelCase("m_" + flagName).substr(1);
        //cout << "    " << camelName << " = " << (int)i << "," << endl;
        cout << "    {ActorFlags::" << flagName << ", \"" << flagName << "\"}," << endl;
    }
    cout << "};" << endl;
}

void genActorCategory() {
    SymCall("?entityCategoryFromString@@YA?AW4ActorCategory@@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z",
        int, string const&)("");
    auto tmp = dlsym("?mFeatureToggles@FeatureToggles@@0V?$unique_ptr@VFeatureToggles@@U?$default_delete@VFeatureToggles@@@std@@@std@@A");
    auto tmp2 = dlsym("?mMutex@?$ServiceLocator@VEducationOptions@@@@0Vshared_mutex@std@@A");
    auto offset = (uintptr_t)tmp2 - (uintptr_t)tmp;
    auto m = (unordered_map<string, int>*)((uintptr_t)tmp + 0x18);
    cout << m->size() << endl;
}

void genEnum()
{
    //genBlockType();
    //genItemStackRequestActionType();
    //genComplexInventoryTransactionType();
    //genContainerType();
    //genActorType();
    //genItemStackNetResult();
    //genContainerCollectionNameMap();
    //genContainerOffset();
    //genLegacyIDToNameMap();
    //genParticleType();
    //genBlockActorType();
    //genJigsawStructureMap(); //x
    genActorCategory();
    genEnchantType();
    genEffectType();
    //genDamageCause();
    genBlockGeometry();
}


/*
struct ItemDescriptor {
    void* weakptr_item;
    void* unk8;
    void* unk16;
    Block* block;
    int16_t aux;
    byte unk34; //vaild?
    byte unk35; //need _resolveImpl
    char unk36[4];
    string* unk40;
    void* unk48;
    void* unk56;
    int64_t unk64;//block 15,
    inline string getSerializedNameAndAux() {
        string name;
        return SymCall("?getSerializedNameAndAux@ItemDescriptor@@QEBA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ",
            string&, ItemDescriptor*, string&)(this, name);
    }
};//72

typedef int ItemStackNetIdVariant;

struct NetworkItemStackDescriptor {
    ItemDescriptor descriptor;//16
    short unk88;//16+72=88
    char filler90[6];//90
    char unk96;//96
    char filler97[3];//97
    ItemStackNetIdVariant variant100;//100
    char filler104[4];
    int unk108;//108
    string unk112;//112
};

struct InventoryAction {
    int type;
    int unk4;
    int unk8;//8
    int unk12;//12

    NetworkItemStackDescriptor descriptor1;//16

    //ItemDescriptor descriptor;//16
    //short unk88;//16+72=88
    //char filler90[6];//90
    //char unk96;//96
    //char filler97[3];//97
    //ItemStackNetIdVariant variant100;//100
    //char filler104[4];
    //int unk108;//108
    //string unk112;//112

    NetworkItemStackDescriptor descriptor2;//144

    //ItemDescriptor descriptor2;//144
    //short unk216;//144+72=216
    //char filler218[6];//218
    //byte unk224;//224
    //char filler225[3];//225
    //ItemStackNetIdVariant unk228;//228
    //char filler232[4];
    //int unk236;//236
    //string unk240;//240

    ItemStack item1;//272
    void* unk408;
    ItemStack item2;//416
    void* unk552;
}; //560

string getString(void* source) {
    string str;
    return SymCall("?toString@InventorySource@@QEBA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ",
        string&, void*, string&)(source, str);
}

THook(void, "?addAction@InventoryTransaction@@QEAAXAEBVInventoryAction@@@Z",
    class InventoryTransaction* _this, InventoryAction* action) {
    cout << action->type << endl;
    if(&action->item1)
    cout << "Item1: " << action->item1.toString() << endl;
    if (&action->item2)
    cout << "Item2: " << action->item2.toString() << endl;
    cout << endl;
    unordered_map<int, vector<InventoryAction>>& actions = dAccess<unordered_map<int, vector<InventoryAction>>,0>(_this);
    if (actions.size() > 0) {
        auto& b = actions.begin()->second;
    }
    if (action->type != 99999)
        return original(_this, action);
    original(_this, action);
}
*/

/*
THook(void, "??1SemVersion@@QEAA@XZ",void* _this){
    original(_this);
}
class RuntimeLightingManager;
THook(void*, "?updateBlockLight@RuntimeLightingManager@@QEAAXAEBVBlockPos@@UBrightness@@111_N@Z",
    RuntimeLightingManager* _this, BlockPos* bpos, char* oldBrightness, char* newBrightness, char* oldAbsorption, char* newAbsorption, bool isSkyLight){
    LOG_VAR(bpos->toString());
    LOG_VAR((int)*oldBrightness);
    LOG_VAR((int)*newBrightness);
    LOG_VAR((int)*oldAbsorption);
    LOG_VAR((int)*newAbsorption);
    LOG_VAR((int)isSkyLight);
    *newBrightness = 15;
    auto rtn = original(_this, bpos, oldBrightness, newBrightness, oldAbsorption, newAbsorption, isSkyLight);
    LOG_VAR(rtn);
    cout << endl;
    return rtn;
}

THook(void, "?onStepOn@Block@@QEBAXAEAVActor@@AEBVBlockPos@@@Z",
    Block* _this, Actor* actor, BlockPos* bpos){
    cout << "onStepOn:" << endl;
    LOG_VAR(_this->toDebugString());
    LOG_VAR(((Vec3)actor->getPos()).toString());
    LOG_VAR(bpos->toString());
    original(_this, actor, bpos);
    cout << endl;
}

THook(void, "?onStepOff@Block@@QEBAXAEAVActor@@AEBVBlockPos@@@Z",
    Block* _this, Actor* actor, BlockPos* bpos) {
    cout << "onStepOff:" << endl;
    LOG_VAR(_this->toDebugString());
    LOG_VAR(((Vec3)actor->getPos()).toString());
    LOG_VAR(bpos->toString());
    original(_this, actor, bpos);
    cout << endl;
}
struct BlockPosTrackerComponent {
    int status;
    int x;
    int y;
    int z;
    BlockPos getBpos() {
        return { x, y + 1, z };
    }
};
//THook(void, "?_tickBlockPosTrackerComponent@BlockPosTrackerSystem@@SAXPEAVActor@@AEAVBlockPosTrackerComponent@@@Z",
//    Actor* actor, BlockPosTrackerComponent* bptc) {
//    BlockPos& oldBpos = *(BlockPos*)(&bptc->x);
//    Vec3 newPos = actor->getPos();
//    if (newPos.toBlockPos() == oldBpos) {
//        return original(actor, bptc);
//    }
//    cout << "_tickBlockPosTrackerComponent:" << endl;
//    LOG_VAR(newPos.toString());
//    LOG_VAR(oldBpos.toString());
//    original(actor, bptc);
//    cout << endl;
//}

void updateBlockLight(RuntimeLightingManager* _this, BlockPos* bpos, char oldBrightness, char newBrightness) {
    char oldAbsorption = 0;
    char newAbsorption = 0;
    SymCall("?updateBlockLight@RuntimeLightingManager@@QEAAXAEBVBlockPos@@UBrightness@@111_N@Z",
        void*, RuntimeLightingManager*, BlockPos*, char&, char&, char&, char&, bool)(_this, bpos, oldBrightness, newBrightness, oldAbsorption, oldAbsorption, false);
}

THook(void, "?move@Player@@UEAAXAEBVVec3@@@Z",
    Player* _this, const Vec3* v) {
    original(_this, v);
    auto& pos = dAccess<Vec3>(_this, 0x4E0);
    auto& prevPos = dAccess<Vec3>(_this, 0x4EC);
    BlockPos bpos = pos.toBlockPos();
    BlockPos prevBpos = prevPos.toBlockPos();
    if(bpos==prevBpos)
        return;
    Dimension* dim = SymCall("?getDimension@Actor@@QEBAAEAVDimension@@XZ",
        Dimension*, Actor*)(_this);
    RuntimeLightingManager* rlm = dAccess<RuntimeLightingManager*>(dim, 0x4D8); // IDA Dimension::flushRunTimeLighting
    updateBlockLight(rlm, &bpos, 0, 15);
    updateBlockLight(rlm, &prevBpos,15, 0);
    SymCall("?flushRunTimeLighting@Level@@UEAAXXZ", void, Level*)(offPlayer::getLevel(_this));
    cout << "Player::move" << endl;
    LOG_VAR(_this->getNameTag());
    LOG_VAR(bpos.toString());
    LOG_VAR(prevBpos.toString());
    cout << endl;
}



//THook(void, "?onStandOn@Block@@QEBAXAEAVActor@@AEBVBlockPos@@@Z",
//    Block* _this, Actor* actor, BlockPos* bpos) {
//    cout << "onStandOn" << endl;
//    LOG_VAR(_this->toDebugString());
//    LOG_VAR(((Vec3)actor->getPos()).toString());
//    LOG_VAR(bpos->toString());
//    original(_this, actor, bpos);
//    cout << endl;
//}

*/

//Sprinting
//bool isSprinting(Mob* mob) {
//    return SymCall("?isSprinting@Mob@@QEBA_NXZ",
//        bool, Mob*)(mob);
//}
////
//void setSprinting(Mob* mob, bool sprinting) {
//    SymCall("?setSprinting@Mob@@UEAAX_N@Z", 
//        void, Mob*, bool)(mob, sprinting);
//}

//THook(void, "?move@Player@@UEAAXAEBVVec3@@@Z",
//    Player* _this, Vec3* v) {
//    if ((v->x!=0||v->z!=0)&&!isSprinting(_this)) {
//        LOG_VAR(v->toString());
//        cout << "setSprinting(true)" << endl;
//        setSprinting(_this, true);
//    }
//    //if (isSprinting(_this)) {
//    //    cout << "setSprinting(false)" << endl;
//    //    setSprinting(_this, false);
//    //}
//    original(_this, v);
//}

/*
THook(void, "?sendPlayerMove@PlayerEventCoordinator@@QEAAXAEAVPlayer@@@Z",
    class PlayerEventCoordinator* _this, Player* player) {
    cout << "sendPlayerMove: " << player->getNameTag() << endl;
    original(_this, player);
}
THook(void, "?sendPlayerInput@ClientPlayerEventCoordinator@@QEAAXAEAUIPlayerMovementProxy@@AEAVMoveInputHandler@@@Z",
    class ClientPlayerEventCoordinator* _this, struct IPlayerMovementProxy* a1, struct MoveInputHandler* a2) {
    cout << "sendPlayerInput: " << endl;
    original(_this, a1, a2);
}
THook(void, "?sendPlayerAuthInputReceived@ServerPlayerEventCoordinator@@QEAAXAEAVPlayer@@AEBVPlayerAuthInputPacket@@@Z",
    class ClientPlayerEventCoordinator* _this, struct IPlayerMovementProxy* a1, struct MoveInputHandler* a2) {
    cout << "sendPlayerAuthInputReceived: " << endl;
    original(_this, a1, a2);
}
THook(void, "?sendPlayerAuthInputApplied@ServerPlayerEventCoordinator@@QEAAXAEAVPlayer@@AEBVPlayerAuthInputPacket@@@Z",
    class ClientPlayerEventCoordinator* _this, struct IPlayerMovementProxy* a1, struct MoveInputHandler* a2) {
    cout << "sendPlayerAuthInputApplied: " << endl;
    original(_this, a1, a2);
}
*/

/*
THook(void, "?move@Player@@UEAAXAEBVVec3@@@Z",
    Player* _this, Vec3* v) {
    original(_this, v);
    auto& pos = dAccess<Vec3>(_this, 0x4E0);
    auto& prevPos = dAccess<Vec3>(_this, 0x4EC);
    bool isMoving = SymCall("?isMoving@Actor@@QEBA_NXZ", bool, Actor*)(_this);
    if (false&&isMoving) {
        LOG_VAR(_this->getNameTag());
        LOG_VAR(v->toString());
        LOG_VAR(pos.toString());
        LOG_VAR(prevPos.toString());
    }
    if (isSprinting(_this))
        setSprinting(_this, false);
}

THook(void, "?setSprinting@Mob@@UEAAX_N@Z",
    Mob* mob, bool sprinting) {
    LOG_VAR(isSprinting(mob));
    LOG_VAR(sprinting);
    original(mob, sprinting);
    cout << endl;
}
*/

//THook(Block*, "?tryGetStateFromLegacyData@BlockLegacy@@QEBAPEBVBlock@@G@Z",
//    BlockLegacy* _this, int64_t state) {
//    LOG_VAR(offBlockLegacy::getFullName(_this));
//    LOG_VAR((void*)state);
//    auto rtn = original(_this, state);
//    LOG_VAR(offBlock::getFullName(rtn));
//    return rtn;
//}