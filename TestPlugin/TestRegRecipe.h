#pragma once

#ifdef ENABLE_TEST_RECIPES
void testRegRecipe();
#else
inline void testRegRecipe(){};
#endif // ENABLE_TEST_RECIPES
