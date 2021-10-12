#include "pch.h"
#include <mc/OffsetHelper.h>
#include "EnumGen.h"
#include "SymHelper.h"
#include "StrHelper.h"

using namespace std;

/*
ItemAcquisitionMethod
; private: static class std::unordered_map<enum ItemAcquisitionMethod, enum MinecraftEventing::AcquisitionMethod, struct std::hash<enum ItemAcquisitionMethod>, struct std::equal_to<enum ItemAcquisitionMethod>, class std::allocator<struct std::pair<enum ItemAcquisitionMethod const, enum MinecraftEventing::AcquisitionMethod>>> const MinecraftEventing::mAcquisitionMethodMap
?mAcquisitionMethodMap@MinecraftEventing@@0V?$unordered_map@W4ItemAcquisitionMethod@@W4AcquisitionMethod@MinecraftEventing@@U?$hash@W4ItemAcquisitionMethod@@@std@@U?$equal_to@W4ItemAcquisitionMethod@@@5@V?$allocator@U?$pair@$$CBW4ItemAcquisitionMethod@@W4AcquisitionMethod@MinecraftEventing@@@std@@@5@@std@@B

ItemUseMethod
.data:00007FF6B0E0E080 ; private: static class std::unordered_map<enum ItemUseMethod, enum MinecraftEventing::UseMethod, struct std::hash<enum ItemUseMethod>, struct std::equal_to<enum ItemUseMethod>, class std::allocator<struct std::pair<enum ItemUseMethod const, enum MinecraftEventing::UseMethod>>> const MinecraftEventing::mUseMethodMap
.data:00007FF6B0E0E080 ?mUseMethodMap@MinecraftEventing@@0V?$unordered_map@W4ItemUseMethod@@W4UseMethod@MinecraftEventing@@U?$hash@W4ItemUseMethod@@@std@@U?$equal_to@W4ItemUseMethod@@@5@V?$allocator@U?$pair@$$CBW4ItemUseMethod@@W4UseMethod@MinecraftEventing@@@std@@@5@@std@@Bdd?

.data:00007FF6B0E141F0 ; public: static class std::unordered_map<class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>>, enum EducationMetadata::ContentType, struct std::hash<class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>>>, struct std::equal_to<class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>>>, class std::allocator<struct std::pair<class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>> const, enum EducationMetadata::ContentType>>> const EducationMetadata::STRING_TO_CONTENT_TYPE
.data:00007FF6B0E141F0 ?STRING_TO_CONTENT_TYPE@EducationMetadata@@2V?$unordered_map@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@W4ContentType@EducationMetadata@@U?$hash@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@U?$equal_to@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@W4ContentType@EducationMetadata@@@std@@@2@@std@@Bdd?

.data:00007FF6B0E14230 ; public: static class std::unordered_map<class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>>, enum EducationMetadata::UserType, struct std::hash<class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>>>, struct std::equal_to<class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>>>, class std::allocator<struct std::pair<class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>> const, enum EducationMetadata::UserType>>> const EducationMetadata::STRING_TO_USER_TYPE
.data:00007FF6B0E14230 ?STRING_TO_USER_TYPE@EducationMetadata@@2V?$unordered_map@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@W4UserType@EducationMetadata@@U?$hash@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@U?$equal_to@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@W4UserType@EducationMetadata@@@std@@@2@@std@@Bdd?

.data:00007FF6B0E14540 ; private: static class std::unordered_map<class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>>, class std::vector<class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>>, class std::allocator<class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>>>>, struct std::hash<class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>>>, struct std::equal_to<class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>>>, class std::allocator<struct std::pair<class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>> const, class std::vector<class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>>, class std::allocator<class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>>>>>>> I18n::mFormatDictionary
.data:00007FF6B0E14540 ?mFormatDictionary@I18n@@0V?$unordered_map@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@2@U?$hash@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@U?$equal_to@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@2@@std@@@2@@std@@A dd ?

.data:00007FF6B0E14500 ; private: static class std::unordered_map<class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>>, class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>>, struct std::hash<class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>>>, struct std::equal_to<class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>>>, class std::allocator<struct std::pair<class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>> const, class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>>>>> I18n::mLanguageNames
.data:00007FF6B0E14500 ?mLanguageNames@I18n@@0V?$unordered_map@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@U?$hash@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@U?$equal_to@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@@2@@std@@A dd ?

.data:00007FF6B0E1AA20 ; private: static class std::unordered_map<class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>>, enum PackScope, struct std::hash<class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>>>, struct std::equal_to<class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>>>, class std::allocator<struct std::pair<class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>> const, enum PackScope>>> const PackManifest::STRING_TO_PACK_SCOPE
.data:00007FF6B0E1AA20 ?STRING_TO_PACK_SCOPE@PackManifest@@0V?$unordered_map@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@W4PackScope@@U?$hash@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@U?$equal_to@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@W4PackScope@@@std@@@2@@std@@B dd ?

.data:00007FF6B0E1ACC0 ; public: static class std::unordered_map<class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>>, class std::vector<char, class std::allocator<char>> const, struct std::hash<class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>>>, struct std::equal_to<class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>>>, class std::allocator<struct std::pair<class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>> const, class std::vector<char, class std::allocator<char>> const>>> PackManifestFactory::mAlternateContentKeys
.data:00007FF6B0E1ACC0 ?mAlternateContentKeys@PackManifestFactory@@2V?$unordered_map@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@$$CBV?$vector@DV?$allocator@D@std@@@2@U?$hash@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@U?$equal_to@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@$$CBV?$vector@DV?$allocator@D@std@@@2@@std@@@2@@std@@A dd ?

.data:00007FF6B0E1AB10 ; public: static class std::unordered_map<class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>>, class std::vector<char, class std::allocator<char>> const, struct std::hash<class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>>>, struct std::equal_to<class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>>>, class std::allocator<struct std::pair<class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>> const, class std::vector<char, class std::allocator<char>> const>>> PackManifestFactory::mContentKeys
.data:00007FF6B0E1AB10 ?mContentKeys@PackManifestFactory@@2V?$unordered_map@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@$$CBV?$vector@DV?$allocator@D@std@@@2@U?$hash@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@U?$equal_to@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@$$CBV?$vector@DV?$allocator@D@std@@@2@@std@@@2@@std@@A dd ?

.data:00007FF6B0E2D5B0 ; private: static class std::unordered_map<enum LogArea, bool, struct std::hash<enum LogArea>, struct std::equal_to<enum LogArea>, class std::allocator<struct std::pair<enum LogArea const, bool>>> const DebugEndPoint::mAssertAreas
.data:00007FF6B0E2D5B0 ?mAssertAreas@DebugEndPoint@@0V?$unordered_map@W4LogArea@@_NU?$hash@W4LogArea@@@std@@U?$equal_to@W4LogArea@@@3@V?$allocator@U?$pair@$$CBW4LogArea@@_N@std@@@3@@std@@B dd ?

.data:00007FF6B0E33F60 ; private: static class std::unordered_map<class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>>, enum DwellerRole, struct std::hash<class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>>>, struct std::equal_to<class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>>>, class std::allocator<struct std::pair<class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>> const, enum DwellerRole>>> const DwellerComponent::DWELLING_ROLES
.data:00007FF6B0E33F60 ?DWELLING_ROLES@DwellerComponent@@0V?$unordered_map@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@W4DwellerRole@@U?$hash@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@U?$equal_to@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@W4DwellerRole@@@std@@@2@@std@@B dd ?

.data:00007FF6B0E33F20 ; private: static class std::unordered_map<class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>>, enum DwellerComponent::DwellingType, struct std::hash<class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>>>, struct std::equal_to<class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>>>, class std::allocator<struct std::pair<class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>> const, enum DwellerComponent::DwellingType>>> const DwellerComponent::DWELLING_TYPES
.data:00007FF6B0E33F20 ?DWELLING_TYPES@DwellerComponent@@0V?$unordered_map@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@W4DwellingType@DwellerComponent@@U?$hash@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@U?$equal_to@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@W4DwellingType@DwellerComponent@@@std@@@2@@std@@B dd ?

.data:00007FF6B0E3A680 ; class std::unordered_map<unsigned __int64, class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>>, struct std::hash<unsigned __int64>, struct std::equal_to<unsigned __int64>, class std::allocator<struct std::pair<unsigned __int64 const, class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>>>>> IncomingDataHelpers::mPartialDataBuffers
.data:00007FF6B0E3A680 ?mPartialDataBuffers@IncomingDataHelpers@@3V?$unordered_map@_KV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$hash@_K@2@U?$equal_to@_K@2@V?$allocator@U?$pair@$$CB_KV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@2@@std@@A dd ?

.data:00007FF6B0E47910 ; private: static class std::unordered_map<enum ActorType, enum LevelSoundEvent, struct std::hash<enum ActorType>, struct std::equal_to<enum ActorType>, class std::allocator<struct std::pair<enum ActorType const, enum LevelSoundEvent>>> const ImitateMobSoundsComponent::imitateMobMap
.data:00007FF6B0E47910 ?imitateMobMap@ImitateMobSoundsComponent@@0V?$unordered_map@W4ActorType@@W4LevelSoundEvent@@U?$hash@W4ActorType@@@std@@U?$equal_to@W4ActorType@@@4@V?$allocator@U?$pair@$$CBW4ActorType@@W4LevelSoundEvent@@@std@@@4@@std@@B dd ?

.data:00007FF6B0E60030 ; private: static class std::unordered_map<enum MolangVariableIndex, class HashedString, struct std::hash<enum MolangVariableIndex>, struct std::equal_to<enum MolangVariableIndex>, class std::allocator<struct std::pair<enum MolangVariableIndex const, class HashedString>>> MolangVariable::mIndexToVariableNameMap
.data:00007FF6B0E60030 ?mIndexToVariableNameMap@MolangVariable@@0V?$unordered_map@W4MolangVariableIndex@@VHashedString@@U?$hash@W4MolangVariableIndex@@@std@@U?$equal_to@W4MolangVariableIndex@@@4@V?$allocator@U?$pair@$$CBW4MolangVariableIndex@@VHashedString@@@std@@@4@@std@@A dd ?

.data:00007FF6B0E6C0F0 ; class std::unordered_map<class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>>, struct FilterTest::Definition, struct std::hash<class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>>>, struct std::equal_to<class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>>>, class std::allocator<struct std::pair<class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>> const, struct FilterTest::Definition>>> sFilterMap
.data:00007FF6B0E6C0F0 ?sFilterMap@@3V?$unordered_map@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UDefinition@FilterTest@@U?$hash@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@U?$equal_to@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UDefinition@FilterTest@@@std@@@2@@std@@A dd ?

.data:00007FF6B0E71E30 ; class std::unordered_map<enum ActorType, struct ActorMapping, struct std::hash<enum ActorType>, struct std::equal_to<enum ActorType>, class std::allocator<struct std::pair<enum ActorType const, struct ActorMapping>>> ENTITY_TYPE_MAP
.data:00007FF6B0E71E30 ?ENTITY_TYPE_MAP@@3V?$unordered_map@W4ActorType@@UActorMapping@@U?$hash@W4ActorType@@@std@@U?$equal_to@W4ActorType@@@4@V?$allocator@U?$pair@$$CBW4ActorType@@UActorMapping@@@std@@@4@@std@@A db    ? ;

.data:00007FF6B0E72420 ; class std::unordered_map<class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>>, struct ActorFilterGroup::LegacyMapping, struct std::hash<class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>>>, struct std::equal_to<class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>>>, class std::allocator<struct std::pair<class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>> const, struct ActorFilterGroup::LegacyMapping>>> _environmentSubfilters
.data:00007FF6B0E72420 ?_environmentSubfilters@@3V?$unordered_map@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@ULegacyMapping@ActorFilterGroup@@U?$hash@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@U?$equal_to@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@ULegacyMapping@ActorFilterGroup@@@std@@@2@@std@@A dd ?

.data:00007FF6B0E78930 ; private: static class BidirectionalUnorderedMap<enum ItemAcquisitionMethod, class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>>> const ItemAcquisitionMethodMap::mMap
.data:00007FF6B0E78930 ?mMap@ItemAcquisitionMethodMap@@0V?$BidirectionalUnorderedMap@W4ItemAcquisitionMethod@@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@@B db    ? ;

.data:00007FF6B0E788B0 ; private: static class BidirectionalUnorderedMap<enum ItemUseMethod, class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>>> const ItemUseMethodMap::mMap
.data:00007FF6B0E788B0 ?mMap@ItemUseMethodMap@@0V?$BidirectionalUnorderedMap@W4ItemUseMethod@@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@@B db    ? ;

.data:00007FF6B0E7E830 ; private: static class BidirectionalUnorderedMap<enum ItemStackRequestActionType, class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>>> const ItemStackRequestAction::actionTypeMap
.data:00007FF6B0E7E830 ?actionTypeMap@ItemStackRequestAction@@0V?$BidirectionalUnorderedMap@W4ItemStackRequestActionType@@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@@B db    ? ;

.data:00007FF6B0E8A5F0 ; private: static class BidirectionalUnorderedMap<enum ParticleType, class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>>> const ParticleTypeMap::map
.data:00007FF6B0E8A5F0 ?map@ParticleTypeMap@@0V?$BidirectionalUnorderedMap@W4ParticleType@@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@@B db    ? ;

.data:00007FF6B0E8AAD0 ; private: static class BidirectionalUnorderedMap<enum ItemUseInventoryTransaction::ActionType, class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>>> const ItemUseInventoryTransaction::actionTypeMap
.data:00007FF6B0E8AAD0 ?actionTypeMap@ItemUseInventoryTransaction@@0V?$BidirectionalUnorderedMap@W4ActionType@ItemUseInventoryTransaction@@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@@B db    ? ;

.data:00007FF6B0E8AA50 ; private: static class BidirectionalUnorderedMap<enum InventoryTransactionError, class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>>> const InventoryTransaction::inventoryTransactionErrorMap
.data:00007FF6B0E8AA50 ?inventoryTransactionErrorMap@InventoryTransaction@@0V?$BidirectionalUnorderedMap@W4InventoryTransactionError@@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@@B db    ? ;

.data:00007FF6B0E906A0 ; private: static class std::unordered_map<unsigned int, class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>>, struct std::hash<unsigned int>, struct std::equal_to<unsigned int>, class std::allocator<struct std::pair<unsigned int const, class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>>>>> ActorPlacerItem::mCustomSpawnEggs
.data:00007FF6B0E906A0 ?mCustomSpawnEggs@ActorPlacerItem@@0V?$unordered_map@IV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$hash@I@2@U?$equal_to@I@2@V?$allocator@U?$pair@$$CBIV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@2@@std@@A dd ?

.data:00007FF6B0E90660 ; private: static class std::unordered_map<class HashedString, struct TextureUVCoordinateSet, struct std::hash<class HashedString>, struct std::equal_to<class HashedString>, class std::allocator<struct std::pair<class HashedString const, struct TextureUVCoordinateSet>>> ActorPlacerItem::mUVTextureMap
.data:00007FF6B0E90660 ?mUVTextureMap@ActorPlacerItem@@0V?$unordered_map@VHashedString@@UTextureUVCoordinateSet@@U?$hash@VHashedString@@@std@@U?$equal_to@VHashedString@@@4@V?$allocator@U?$pair@$$CBVHashedString@@UTextureUVCoordinateSet@@@std@@@4@@std@@A dd ?

.data:00007FF6B0E8A9D0 ; private: static class BidirectionalUnorderedMap<enum ComplexInventoryTransaction::Type, class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>>> const ComplexInventoryTransaction::transactionTypeMap
.data:00007FF6B0E8A9D0 ?transactionTypeMap@ComplexInventoryTransaction@@0V?$BidirectionalUnorderedMap@W4Type@ComplexInventoryTransaction@@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@@B db    ? ;

.data:00007FF6B0E96190 ; private: static class std::unordered_map<class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>>, class std::function<class std::unique_ptr<class OnHitSubcomponent, struct std::default_delete<class OnHitSubcomponent>> (void)>, struct std::hash<class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>>>, struct std::equal_to<class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>>>, class std::allocator<struct std::pair<class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>> const, class std::function<class std::unique_ptr<class OnHitSubcomponent, struct std::default_delete<class OnHitSubcomponent>> (void)>>>> ProjectileFactory::mSubcomponentMap
.data:00007FF6B0E96190 ?mSubcomponentMap@ProjectileFactory@@0V?$unordered_map@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$function@$$A6A?AV?$unique_ptr@VOnHitSubcomponent@@U?$default_delete@VOnHitSubcomponent@@@std@@@std@@XZ@2@U?$hash@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@U?$equal_to@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$function@$$A6A?AV?$unique_ptr@VOnHitSubcomponent@@U?$default_delete@VOnHitSubcomponent@@@std@@@std@@XZ@2@@std@@@2@@std@@A dd ?

.data:00007FF6B0EA79D0 ; private: static class std::unordered_map<int, int, struct std::hash<int>, struct std::equal_to<int>, class std::allocator<struct std::pair<int const, int>>> CompoundItem::mIdToSpecialCompound
.data:00007FF6B0EA79D0 ?mIdToSpecialCompound@CompoundItem@@0V?$unordered_map@HHU?$hash@H@std@@U?$equal_to@H@2@V?$allocator@U?$pair@$$CBHH@std@@@2@@std@@A dd ?

.data:00007FF6B0EA7A10 ; private: static class std::unordered_map<int, class ItemInstance, struct std::hash<int>, struct std::equal_to<int>, class std::allocator<struct std::pair<int const, class ItemInstance>>> CompoundItem::mTypeToSpecialCompound
.data:00007FF6B0EA7A10 ?mTypeToSpecialCompound@CompoundItem@@0V?$unordered_map@HVItemInstance@@U?$hash@H@std@@U?$equal_to@H@3@V?$allocator@U?$pair@$$CBHVItemInstance@@@std@@@3@@std@@A dd ?

.data:00007FF6B0EB9330 ; class std::unordered_map<enum ContainerEnumName, class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>>, struct ContainerEnumNameHasher, struct std::equal_to<enum ContainerEnumName>, class std::allocator<struct std::pair<enum ContainerEnumName const, class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>>>>> ContainerCollectionNameMap
.data:00007FF6B0EB9330 ?ContainerCollectionNameMap@@3V?$unordered_map@W4ContainerEnumName@@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UContainerEnumNameHasher@@U?$equal_to@W4ContainerEnumName@@@3@V?$allocator@U?$pair@$$CBW4ContainerEnumName@@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@3@@std@@A db    ? ;

.data:00007FF6B0EC51C0 ; private: static class BidirectionalUnorderedMap<enum ItemStackNetResult, class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>>> const ItemStackNetResultMap::mMap
.data:00007FF6B0EC51C0 ?mMap@ItemStackNetResultMap@@0V?$BidirectionalUnorderedMap@W4ItemStackNetResult@@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@@B db    ? ;

.data:00007FF6B0EC52C0 ; private: static class BidirectionalUnorderedMap<enum SparseContainerClient::PushSlotPredictionResult, class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>>> const SparseContainerClient::pushSlotPredictionResultMap
.data:00007FF6B0EC52C0 ?pushSlotPredictionResultMap@SparseContainerClient@@0V?$BidirectionalUnorderedMap@W4PushSlotPredictionResult@SparseContainerClient@@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@@B db    ? ;

.data:00007FF6B0EF28F0 ; private: static class std::unordered_map<class HashedString, class std::function<class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>> (short)>, struct std::hash<class HashedString>, struct std::equal_to<class HashedString>, class std::allocator<struct std::pair<class HashedString const, class std::function<class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>> (short)>>>> ItemRegistry::mComplexAliasLookupMap
.data:00007FF6B0EF28F0 ?mComplexAliasLookupMap@ItemRegistry@@0V?$unordered_map@VHashedString@@V?$function@$$A6A?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@F@Z@std@@U?$hash@VHashedString@@@3@U?$equal_to@VHashedString@@@3@V?$allocator@U?$pair@$$CBVHashedString@@V?$function@$$A6A?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@F@Z@std@@@std@@@3@@std@@A dd ?

.data:00007FF6B0EF27F0 ; private: static class std::unordered_map<int, class WeakPtr<class Item>, struct std::hash<int>, struct std::equal_to<int>, class std::allocator<struct std::pair<int const, class WeakPtr<class Item>>>> ItemRegistry::mIdToItemMap
.data:00007FF6B0EF27F0 ?mIdToItemMap@ItemRegistry@@0V?$unordered_map@HV?$WeakPtr@VItem@@@@U?$hash@H@std@@U?$equal_to@H@3@V?$allocator@U?$pair@$$CBHV?$WeakPtr@VItem@@@@@std@@@3@@std@@A dd ?

.data:00007FF6B0EF2870 ; private: static class std::unordered_map<class HashedString, struct ItemRegistry::ItemAlias, struct std::hash<class HashedString>, struct std::equal_to<class HashedString>, class std::allocator<struct std::pair<class HashedString const, struct ItemRegistry::ItemAlias>>> ItemRegistry::mItemAliasLookupMap
.data:00007FF6B0EF2870 ?mItemAliasLookupMap@ItemRegistry@@0V?$unordered_map@VHashedString@@UItemAlias@ItemRegistry@@U?$hash@VHashedString@@@std@@U?$equal_to@VHashedString@@@5@V?$allocator@U?$pair@$$CBVHashedString@@UItemAlias@ItemRegistry@@@std@@@5@@std@@A dd ?

.data:00007FF6B0EF2930 ; private: static class std::unordered_map<short, class HashedString, struct std::hash<short>, struct std::equal_to<short>, class std::allocator<struct std::pair<short const, class HashedString>>> ItemRegistry::mLegacyIDToNameMap
.data:00007FF6B0EF2930 ?mLegacyIDToNameMap@ItemRegistry@@0V?$unordered_map@FVHashedString@@U?$hash@F@std@@U?$equal_to@F@3@V?$allocator@U?$pair@$$CBFVHashedString@@@std@@@3@@std@@A dd ?

.data:00007FF6B0EF2830 ; private: static class std::unordered_map<class HashedString, class WeakPtr<class Item>, struct std::hash<class HashedString>, struct std::equal_to<class HashedString>, class std::allocator<struct std::pair<class HashedString const, class WeakPtr<class Item>>>> ItemRegistry::mNameToItemMap
.data:00007FF6B0EF2830 ?mNameToItemMap@ItemRegistry@@0V?$unordered_map@VHashedString@@V?$WeakPtr@VItem@@@@U?$hash@VHashedString@@@std@@U?$equal_to@VHashedString@@@4@V?$allocator@U?$pair@$$CBVHashedString@@V?$WeakPtr@VItem@@@@@std@@@4@@std@@A dd ?

.data:00007FF6B0EF28B0 ; private: static class std::unordered_map<unsigned __int64, struct ItemRegistry::ItemHashAlias, struct std::hash<unsigned __int64>, struct std::equal_to<unsigned __int64>, class std::allocator<struct std::pair<unsigned __int64 const, struct ItemRegistry::ItemHashAlias>>> ItemRegistry::mReverseAliasLookupMap
.data:00007FF6B0EF28B0 ?mReverseAliasLookupMap@ItemRegistry@@0V?$unordered_map@_KUItemHashAlias@ItemRegistry@@U?$hash@_K@std@@U?$equal_to@_K@4@V?$allocator@U?$pair@$$CB_KUItemHashAlias@ItemRegistry@@@std@@@4@@std@@A dd ?

.data:00007FF6B0F14D80 ; class std::unordered_map<class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>>, class std::function<void (int, class CompoundTag &)>, struct std::hash<class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>>>, struct std::equal_to<class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>>>, class std::allocator<struct std::pair<class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>> const, class std::function<void (int, class CompoundTag &)>>>> BlockSerializationUtils::BLOCK_REPLACE_DATA_MAP
.data:00007FF6B0F14D80 ?BLOCK_REPLACE_DATA_MAP@BlockSerializationUtils@@3V?$unordered_map@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$function@$$A6AXHAEAVCompoundTag@@@Z@2@U?$hash@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@U?$equal_to@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$function@$$A6AXHAEAVCompoundTag@@@Z@2@@std@@@2@@std@@A db    ? ;

.data:00007FF6B0F33A90 ; private: static class std::unordered_map<class HashedString, class std::function<class std::unique_ptr<class LootItemFunction, struct std::default_delete<class LootItemFunction>> (class Json::Value &, class std::vector<class std::unique_ptr<class LootItemCondition, struct std::default_delete<class LootItemCondition>>, class std::allocator<class std::unique_ptr<class LootItemCondition, struct std::default_delete<class LootItemCondition>>>> &)>, struct std::hash<class HashedString>, struct std::equal_to<class HashedString>, class std::allocator<struct std::pair<class HashedString const, class std::function<class std::unique_ptr<class LootItemFunction, struct std::default_delete<class LootItemFunction>> (class Json::Value &, class std::vector<class std::unique_ptr<class LootItemCondition, struct std::default_delete<class LootItemCondition>>, class std::allocator<class std::unique_ptr<class LootItemCondition, struct std::default_delete<class LootItemCondition>>>> &)>>>> const LootItemFunction::mLootingFunctions
.data:00007FF6B0F33A90 ?mLootingFunctions@LootItemFunction@@0V?$unordered_map@VHashedString@@V?$function@$$A6A?AV?$unique_ptr@VLootItemFunction@@U?$default_delete@VLootItemFunction@@@std@@@std@@AEAVValue@Json@@AEAV?$vector@V?$unique_ptr@VLootItemCondition@@U?$default_delete@VLootItemCondition@@@std@@@std@@V?$allocator@V?$unique_ptr@VLootItemCondition@@U?$default_delete@VLootItemCondition@@@std@@@std@@@2@@2@@Z@std@@U?$hash@VHashedString@@@3@U?$equal_to@VHashedString@@@3@V?$allocator@U?$pair@$$CBVHashedString@@V?$function@$$A6A?AV?$unique_ptr@VLootItemFunction@@U?$default_delete@VLootItemFunction@@@std@@@std@@AEAVValue@Json@@AEAV?$vector@V?$unique_ptr@VLootItemCondition@@U?$default_delete@VLootItemCondition@@@std@@@std@@V?$allocator@V?$unique_ptr@VLootItemCondition@@U?$default_delete@VLootItemCondition@@@std@@@std@@@2@@2@@Z@std@@@std@@@3@@std@@B dd ?

.data:00007FF6B0F39D80 ; private: static class std::unordered_map<class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>>, int, struct std::hash<class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>>>, struct std::equal_to<class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>>>, class std::allocator<struct std::pair<class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>> const, int>>> Potion::mPotionsByName
.data:00007FF6B0F39D80 ?mPotionsByName@Potion@@0V?$unordered_map@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@HU?$hash@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@U?$equal_to@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@H@std@@@2@@std@@A dd ?

.data:00007FF6B0F48680 ; class std::unordered_map<class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>>, class std::vector<class HashedString, class std::allocator<class HashedString>>, struct std::hash<class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>>>, struct std::equal_to<class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>>>, class std::allocator<struct std::pair<class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>> const, class std::vector<class HashedString, class std::allocator<class HashedString>>>>> const VanillaTagMaps::BlockNameIdToTagsMap
.data:00007FF6B0F48680 ?BlockNameIdToTagsMap@VanillaTagMaps@@3V?$unordered_map@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$vector@VHashedString@@V?$allocator@VHashedString@@@std@@@2@U?$hash@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@U?$equal_to@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$vector@VHashedString@@V?$allocator@VHashedString@@@std@@@2@@std@@@2@@std@@B db    ? ;

.data:00007FF6B0F486C0 ; class std::unordered_map<class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>>, class std::vector<class HashedString, class std::allocator<class HashedString>>, struct std::hash<class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>>>, struct std::equal_to<class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>>>, class std::allocator<struct std::pair<class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>> const, class std::vector<class HashedString, class std::allocator<class HashedString>>>>> const VanillaTagMaps::ItemNameIdToTagsMap
.data:00007FF6B0F486C0 ?ItemNameIdToTagsMap@VanillaTagMaps@@3V?$unordered_map@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$vector@VHashedString@@V?$allocator@VHashedString@@@std@@@2@U?$hash@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@U?$equal_to@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$vector@VHashedString@@V?$allocator@VHashedString@@@std@@@2@@std@@@2@@std@@B db    ? ;

.data:00007FF6B0F73FD0 ; private: static class std::unordered_map<int, class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>>, struct std::hash<int>, struct std::equal_to<int>, class std::allocator<struct std::pair<int const, class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>>>>> const JigsawEditorData::JOINT_TYPE_TO_NAME
.data:00007FF6B0F73FD0 ?JOINT_TYPE_TO_NAME@JigsawEditorData@@0V?$unordered_map@HV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$hash@H@2@U?$equal_to@H@2@V?$allocator@U?$pair@$$CBHV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@2@@std@@B dd ?

.data:00007FF6B0F79B30 ; public: static class std::unordered_map<class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>>, struct BlockComponentFactory::Constructor, struct std::hash<class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>>>, struct std::equal_to<class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>>>, class std::allocator<struct std::pair<class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>> const, struct BlockComponentFactory::Constructor>>> BlockComponentFactory::mRegisteredCerealComponents
.data:00007FF6B0F79B30 ?mRegisteredCerealComponents@BlockComponentFactory@@2V?$unordered_map@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UConstructor@BlockComponentFactory@@U?$hash@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@U?$equal_to@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UConstructor@BlockComponentFactory@@@std@@@2@@std@@A dd ?

.data:00007FF6B0FB5210 ; public: static class std::unordered_map<class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>>, class BlockGraphics *, struct std::hash<class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>>>, struct std::equal_to<class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>>>, class std::allocator<struct std::pair<class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>> const, class BlockGraphics *>>> BlockGraphics::mBlockLookupMap
.data:00007FF6B0FB5210 ?mBlockLookupMap@BlockGraphics@@2V?$unordered_map@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PEAVBlockGraphics@@U?$hash@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@U?$equal_to@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PEAVBlockGraphics@@@std@@@2@@std@@A dd ?

.data:00007FF6B0FB5270 ; private: static class std::unordered_map<unsigned int, class BlockGraphics *, struct std::hash<unsigned int>, struct std::equal_to<unsigned int>, class std::allocator<struct std::pair<unsigned int const, class BlockGraphics *>>> BlockGraphics::mBlocks
.data:00007FF6B0FB5270 ?mBlocks@BlockGraphics@@0V?$unordered_map@IPEAVBlockGraphics@@U?$hash@I@std@@U?$equal_to@I@3@V?$allocator@U?$pair@$$CBIPEAVBlockGraphics@@@std@@@3@@std@@A dd ?

.data:00007FF6B0EEC2B0 ; private: static class std::unordered_set<class ChunkPos, struct std::hash<class ChunkPos>, struct std::equal_to<class ChunkPos>, class std::allocator<class ChunkPos>> const Spawner::SPAWN_RING_OFFSETS
.data:00007FF6B0EEC2B0 ?SPAWN_RING_OFFSETS@Spawner@@0V?$unordered_set@VChunkPos@@U?$hash@VChunkPos@@@std@@U?$equal_to@VChunkPos@@@3@V?$allocator@VChunkPos@@@3@@std@@B dd ?

.data:00007FF6B0F39DC0 ; private: static class std::unordered_set<class PotionBrewing::Ingredient, struct std::hash<class PotionBrewing::Ingredient>, struct std::equal_to<class PotionBrewing::Ingredient>, class std::allocator<class PotionBrewing::Ingredient>> PotionBrewing::mValidIngredients
.data:00007FF6B0F39DC0 ?mValidIngredients@PotionBrewing@@0V?$unordered_set@VIngredient@PotionBrewing@@U?$hash@VIngredient@PotionBrewing@@@std@@U?$equal_to@VIngredient@PotionBrewing@@@4@V?$allocator@VIngredient@PotionBrewing@@@4@@std@@A dd ?

.data:00007FF6B0F39E00 ; private: static class std::unordered_set<class PotionBrewing::Ingredient, struct std::hash<class PotionBrewing::Ingredient>, struct std::equal_to<class PotionBrewing::Ingredient>, class std::allocator<class PotionBrewing::Ingredient>> PotionBrewing::mValidRecipeInputs
.data:00007FF6B0F39E00 ?mValidRecipeInputs@PotionBrewing@@0V?$unordered_set@VIngredient@PotionBrewing@@U?$hash@VIngredient@PotionBrewing@@@std@@U?$equal_to@VIngredient@PotionBrewing@@@4@V?$allocator@VIngredient@PotionBrewing@@@4@@std@@A dd ?







*/

#define LOG_VAR(var) std::cout << #var" :\t" << var << std::endl;

#define ITER_TYPE_MAP(typeMap) \
for (auto& [type, name] : typeMap) {\
cout << "    " << name << " = " << (int)type << "," << endl;\
}\

struct voids {
    void***** v[1000];
};

//链接：https://www.nowcoder.com/questionTerminal/5a776e2954f545e0bcc01e6b04ef5f1d
//来源：牛客网

/**
* 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
*
*
* @param newString string字符串
* @return string字符串
*/
string camelCase(string newString) {
    // write code here
    string res;
    int cnt = 0;
    if (newString == "") return "shopee";
    for (char ch : newString) {
        if (!isalpha(ch) && !isdigit(ch)) cnt++;
    }
    if (cnt == newString.size()) return "shopee";
    char ch = newString[0];
    int index = 0;
    if (!isalpha(ch) && !isdigit(ch)) {
        while (!isalpha(newString[index]) && !isdigit(newString[index])) index++;
        res += tolower(newString[index]);
        index++;
    }
    else if (isalpha(ch)) res += tolower(ch), index++;
    else res += ch, index++;
    for (int i = index; i < newString.size(); i++) {
        char ch = newString[i];
        if (!isalpha(ch) && !isdigit(ch)) {
            if (i == newString.size() - 1) continue;
            while (!isalpha(newString[i]) && !isdigit(newString[i])) i++;
            res += toupper(newString[i]);
        }
        else if (isalpha(ch)) res += tolower(ch);
        else res += ch;
    }
    return res;
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
        auto enumName = camelCase("m_" + blockName.substr(blockName.find(':') + 1));
        //LOG_VAR(blockName)
        //LOG_VAR(blockItemId)
        //LOG_VAR(offset)
        std::cout << "    " << enumName << " = " << blockItemId << ", // " << blockName << std::endl;
    }
    std::cout << "};" << std::endl;
}

void genItemStackRequestActionType() {
    string typeName;
    cout << "enum ItemStackRequestActionType : char {" << endl;
    for (int t = 0; t < MAXBYTE; t++) {
        typeName = SymCall("?getActionTypeName@ItemStackRequestAction@@SA?BV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@W4ItemStackRequestActionType@@@Z",
            string&, string&, byte)(typeName, (byte)t);
        if (typeName != "Unknown Action")
            cout << "    " << typeName << " = " << t << "," << endl;
    }
    cout << "};" << endl;
}

void genComplexInventoryTransactionType() {
    string typeName;
    cout << "enum ComplexInventoryTransactionType : unsigned int {" << endl;
    for (unsigned int t = 0; t < MAXBYTE; t++) {
        SymCall("?getTransactionTypeName@ComplexInventoryTransaction@@SA?BV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@W4Type@1@@Z",
            string&, string&, unsigned int)(typeName, t);
        if (typeName != "Unknown Type")
            cout << "    " << typeName << " = " << t << "," << endl;
    }
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
    cout << "enum ContainerCollectionNameMap : char {" << endl;
    auto containerNameMap = (unordered_map<char, string>*)dlsym("?ContainerCollectionNameMap@@3V?$unordered_map@W4ContainerEnumName@@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UContainerEnumNameHasher@@U?$equal_to@W4ContainerEnumName@@@3@V?$allocator@U?$pair@$$CBW4ContainerEnumName@@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@3@@std@@A");

    for (auto& ctn : *containerNameMap) {
        string enumName = StrHelper::toCamelCase(ctn.second);
        cout << "    " << enumName << " = " << (int)ctn.first << ", //" << ctn.second << endl;
    }
    cout << "};" << endl;
}
void genContainerOffset() {
    cout << "enum ContainerOffset : char {" << endl;
    auto containerNameMap = (unordered_map<char, string>*)dlsym("?ContainerCollectionNameMap@@3V?$unordered_map@W4ContainerEnumName@@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UContainerEnumNameHasher@@U?$equal_to@W4ContainerEnumName@@@3@V?$allocator@U?$pair@$$CBW4ContainerEnumName@@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@3@@std@@A");

    for (auto& ctn : *containerNameMap) {
        string enumName = StrHelper::toCamelCase(ctn.second);
        char fakeContainer[49];
        fakeContainer[48] = ctn.first;
        char offset = SymCall("?_getContainerOffset@PlayerUIContainerModel@@MEBAHXZ", char, void*)((void*)fakeContainer);
        if(offset)
            cout << "    " << enumName << " = " << (int)offset << ", //" << ctn.second << endl;
    }
    cout << "};" << endl;
}

void genLegacyIDToNameMap() {
    cout << "enum LegacyIDToNameMap : char {" << endl;
    auto containerNameMap = (unordered_map<short, HashedString>*)dlsym(
        "?mLegacyIDToNameMap@ItemRegistry@@0V?$unordered_map@FVHashedString@@U?$hash@F@std@@U?$equal_to@F@3@V?$allocator@U?$pair@$$CBFVHashedString@@@std@@@3@@std@@A"
    );

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
    auto nameIdMap = (map<int, string>*)dlsym(
        "?mClassIdMap@BlockActor@@0V?$map@W4BlockActorType@@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@W4BlockActorType@@@3@V?$allocator@U?$pair@$$CBW4BlockActorType@@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@3@@std@@B"
    );
    auto idNameMap = (map<string, int>*)dlsym(
        "?mIdClassMap@BlockActor@@0V?$map@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@W4BlockActorType@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@W4BlockActorType@@@std@@@2@@std@@B"
    );

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
        void**** filler[112 / 8 + 1];
    };
    auto mEnchantments = (vector<unique_ptr<Enchant>>*)dlsym(
        "?mEnchants@Enchant@@2V?$vector@V?$unique_ptr@VEnchant@@U?$default_delete@VEnchant@@@std@@@std@@V?$allocator@V?$unique_ptr@VEnchant@@U?$default_delete@VEnchant@@@std@@@std@@@2@@std@@A"
    );
    for (auto& enptr : *mEnchantments) {
        Enchant* en = enptr.get();
        auto a = (voids*)en;
        char id = dAccess<char>(en, 8);
        int freq = dAccess<int>(en, 12);
        char a8 = dAccess<char>(en, 16); //cost?
        int a6 = dAccess<int>(en, 20);
        int a7 = dAccess<int>(en, 24);
        short maxLevel = dAccess<short>(en, 28);
        if (maxLevel > 0)
            *(short*)(((uintptr_t)en) + 28) = 10;
        string nameKey = dAccess<string>(en, 32);
        string name = dAccess<string>(en, 72);
        //SymCall("?getDescriptionId@Enchant@@QEBA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ",
        //    string&, Enchant*, string&)(en, name);
        //auto hstr = HashedString(name.c_str());
        //char id =SymCall("?getEnchantmentId@EnchantUtils@@SA?AW4Type@Enchant@@AEBVHashedString@@@Z",
        //    char, HashedString&)(hstr);
        cout << "    " << name << " = " << (int)id << ", // max level: " << maxLevel << ", frequency: " << freq
            << ", name key : " << nameKey << endl;
    }
    cout << "};" << endl;
}


void genEffectType() {
    void* eff;
    HashedString hstr = HashedString("");
    SymCall("?getDisplayName@MobEffectInstance@@QEBA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ",
        HashedString&, void*, HashedString&)(eff, hstr);
    cout << hstr.getString() << endl;

    cout << "enum EffectType : short {" << endl;
    for (short t = MININT16; t < MAXINT16; t++) {
        auto effect = SymCall("?getById@MobEffect@@SAPEAV1@H@Z",
            class Effect*, short)(t);
        if (!effect)
            continue;
        auto& unk8 = dAccess<short>(effect, 8); //id
        auto& unk12 = dAccess<char>(effect, 12);
        auto& effectName = dAccess<string>(effect, 32); // effect type name?
        auto& unk68 = dAccess<float>(effect, 68);
        auto& name = dAccess<string>(effect, 80); // effect name
        auto& unk112 = dAccess<string>(effect, 112);
        auto& unk144 = dAccess<char>(effect, 144);
        auto& fullName = dAccess<HashedString>(effect, 152); //full name
        cout << "    " << name << " = " << (int)t << ", // effect: " << effectName << endl;
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
    cout << "enum ActorDagageCause : unsigned int {" << endl;
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

void genEnum()
{
    //genBlockType();
    //genItemStackRequestActionType();
    //genComplexInventoryTransactionType();
    genContainerType();
    //genActorType();
    //genItemStackNetResult();
    //genContainerCollectionNameMap();
    //genContainerOffset();
    //genLegacyIDToNameMap();
    //genParticleType();
    //genBlockActorType();
    //genJigsawStructureMap(); //x
    //genEnchantType();
    //genEffectType();
    //genDamageCause();
    genBlockGeometry();
}

