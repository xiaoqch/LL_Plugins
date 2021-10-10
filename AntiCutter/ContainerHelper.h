#pragma once

class SparseContainer;
class ContainerScreenContext;

enum class ContainerEnumName : unsigned char {
    beaconPaymentItems              = 8,  //beacon_payment_items
    anvilInputItems                 = 0,  //anvil_input_items
    anvilMaterialItems              = 1,  //anvil_material_items
    anvilResultItems                = 2,  //anvil_result_items
    smithingTableInputItems         = 3,  //smithing_table_input_items
    smithingTableMaterialItems      = 4,  //smithing_table_material_items
    smithingTableResultItems        = 5,  //smithing_table_result_items
    armorItems                      = 6,  //armor_items
    containerItems                  = 7,  //container_items
    brewingInputItem                = 9,  //brewing_input_item
    brewingResultItems              = 10, //brewing_result_items
    brewingFuelItem                 = 11, //brewing_fuel_item
    combinedHotbarAndInventoryItems = 12, //combined_hotbar_and_inventory_items
    craftingInputItems              = 13, //crafting_input_items
    craftingOutputItems             = 14, //crafting_output_items
    recipeConstruction              = 15, //recipe_construction
    recipeNature                    = 16, //recipe_nature
    recipeItems                     = 17, //recipe_items
    recipeSearch                    = 18, //recipe_search
    recipeSearchBar                 = 19, //recipe_search_bar
    recipeEquipment                 = 20, //recipe_equipment
    enchantingInputItems            = 21, //enchanting_input_items
    enchantingLapisItems            = 22, //enchanting_lapis_items
    furnaceFuelItems                = 23, //furnace_fuel_items
    furnaceIngredientItems          = 24, //furnace_ingredient_items
    furnaceOutputItems              = 25, //furnace_output_items
    horseEquipItems                 = 26, //horse_equip_items
    hotbarItems                     = 27, //hotbar_items
    inventoryItems                  = 28, //inventory_items
    tradeIngredient1Items           = 30, //trade_ingredient1_items
    tradeIngredient2Items           = 31, //trade_ingredient2_items
    tradeResultItem                 = 32, //trade_result_item
    containerItems2                  = 29, //container_items
    offhandItems                    = 33, //offhand_items
    compcreateInput                 = 34, //compcreate_input
    compcreateOutput                = 35, //compcreate_output
    elemconstructOutput             = 36, //elemconstruct_output
    matreduceInput                  = 37, //matreduce_input
    matreduceOutput                 = 38, //matreduce_output
    labtableInput                   = 39, //labtable_input
    loomInputItems                  = 40, //loom_input_items
    loomDyeItems                    = 41, //loom_dye_items
    loomMaterialItems               = 42, //loom_material_items
    loomResultItems                 = 43, //loom_result_items
    furnaceIngredientItems2          = 44, //furnace_ingredient_items
    furnaceIngredientItems3          = 45, //furnace_ingredient_items
    trade2Ingredient1Item           = 46, //trade2_ingredient1_item
    trade2Ingredient2Item           = 47, //trade2_ingredient2_item
    trade2ResultItem                = 48, //trade2_result_item
    grindstoneInputItems            = 49, //grindstone_input_items
    grindstoneAdditionalItems       = 50, //grindstone_additional_items
    grindstoneResultItems           = 51, //grindstone_result_items
    stonecutterInputItems           = 52, //stonecutter_input_items
    stonecutterResultItems          = 53, //stonecutter_result_items
    cartographyInputItems           = 54, //cartography_input_items
    cartographyAdditionalItems      = 55, //cartography_additional_items
    cartographyResultItems          = 56, //cartography_result_items
    containerItems3                  = 57, //container_items
    cursorItems                     = 58, //cursor_items
    creativeOutputItems             = 59, //creative_output_items
};

enum class ContainerOffset : char {
    beaconPaymentItems         = 27, //beacon_payment_items
    anvilInputItems            = 1,  //anvil_input_items
    anvilMaterialItems         = 2,  //anvil_material_items
    smithingTableInputItems    = 51, //smithing_table_input_items
    smithingTableMaterialItems = 52, //smithing_table_material_items
    enchantingInputItems       = 14, //enchanting_input_items
    enchantingLapisItems       = 15, //enchanting_lapis_items
    tradeIngredient1Items      = 6,  //trade_ingredient1_items
    tradeIngredient2Items      = 7,  //trade_ingredient2_items
    compcreateInput            = 18, //compcreate_input
    matreduceInput             = 8,  //matreduce_input
    matreduceOutput            = 41, //matreduce_output
    loomInputItems             = 9,  //loom_input_items
    loomDyeItems               = 10, //loom_dye_items
    loomMaterialItems          = 11, //loom_material_items
    trade2Ingredient1Item      = 4,  //trade2_ingredient1_item
    trade2Ingredient2Item      = 5,  //trade2_ingredient2_item
    grindstoneInputItems       = 16, //grindstone_input_items
    grindstoneAdditionalItems  = 17, //grindstone_additional_items
    stonecutterInputItems      = 3,  //stonecutter_input_items
    cartographyInputItems      = 12, //cartography_input_items
    cartographyAdditionalItems = 13, //cartography_additional_items
    creativeOutputItems        = 50, //creative_output_items
};

enum class ContainerType : char {
    NONE                   = -9,
    INVENTORY              = -1,
    CONTAINER              = 0,
    WORKBENCH              = 1,
    FURNACE                = 2,
    ENCHANTMENT            = 3,
    BREWING_STAND          = 4,
    ANVIL                  = 5,
    DISPENSER              = 6,
    DROPPER                = 7,
    HOPPER                 = 8,
    CAULDRON               = 9,
    MINECART_CHEST         = 10,
    MINECART_HOPPER        = 11,
    HORSE                  = 12,
    MINECART_COMMAND_BLOCK = 16,
    JUKEBOX                = 17,
    COMPOUND_CREATOR       = 20,
    ELEMENT_CONSTRUCTOR    = 21,
    MATERIAL_REDUCER       = 22,
    LAB_TABLE              = 23,
    BLAST_FURNACE          = 27,
    SMOKER                 = 28,
    STONECUTTER            = 29,
    HUD                    = 31,
    SMITHING_TABLE         = 33,
};


ItemStack* getItemFromSparseContainer(SparseContainer* ctn, ContainerOffset offset);

ContainerType getScreenContainerType(ContainerScreenContext* context);