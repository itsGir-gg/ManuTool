#include "RecipeModel.h"
#include "RecipeModules.h"

using RecipesDB::Mat;
using RecipesDB::Sub;
using RecipesDB::Tool;
using RecipesDB::AddRecipe;

using namespace recipes;

void recipes::RegisterCompoundMaterials() {
    // Food
    AddRecipe(L"Flour", { Mat(L"Wheat", 2) });
    AddRecipe(L"Sesame Oil", 2, { Mat(L"Sesame Seed", 5) });
    AddRecipe(L"Soy Bean Milk", { Mat(L"Bean", 1 ), Mat(L"Mung Bean", 1), Mat(L"Honey", 1)});
    AddRecipe(L"Bean Paste", 2, { Mat(L"Bean", 3), Mat(L"Straw", 3)});
    AddRecipe(L"Rice Cake", 3, { Mat(L"Rice", 2), Mat(L"Salt", 1) });
    AddRecipe(L"Vinegar", { Mat(L"Rice", 2), Mat(L"Bean Paste", 1) });
    AddRecipe(L"Soy Sauce", 2, { Mat(L"Salt", 1), Mat(L"Bean Paste", 2) });
    AddRecipe(L"Chinese Noodles", 2, { Mat(L"Mung Bean", 2), Mat(L"Potato", 1), Mat(L"Sweet Potato", 1) });
    // Medicine
    AddRecipe(L"Pickled Ginseng", { Mat(L"Ginseng", 4) });
    // Other
    AddRecipe(L"Spiky Accesory", { Mat(L"Aquamarine", 6), Mat(L"Spiky Silk", 6) });
}