#include "RecipeModel.h"
#include "RecipeModules.h"

using RecipesDB::Mat;
using RecipesDB::Sub;
using RecipesDB::Tool;
using RecipesDB::AddRecipe;

using namespace recipes;

void recipes::RegisterAmmunitionRecipes() {
    AddRecipe(L"Arrow", 200, {
        Mat(L"Bamboo", 1),
        Mat(L"Iron Ore", 1),
        Mat(L"Feather", 1),
        });
    AddRecipe(L"Bullet", 200, {
        Mat(L"Copper", 1),
        Mat(L"Coal", 1),
        Mat(L"Sulfur", 1),
        });
}