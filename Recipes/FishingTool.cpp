#include "RecipeModel.h"
#include "RecipeModules.h"

using RecipesDB::Mat;
using RecipesDB::Sub;
using RecipesDB::Tool;
using RecipesDB::AddRecipe;

using namespace recipes;

void recipes::RegisterFishingToolRecipes() {
    AddRecipe(L"Fishing Rod", {
        Mat(L"Bamboo", 10),
        Mat(L"Iron Ore", 3),
        Mat(L"Animal Bones", 3),
        });
    AddRecipe(L"Fisherman's Rod", {
        Mat(L"Bamboo", 30),
        Mat(L"Topaz", 10),
        Mat(L"Polisher", 1),
        Mat(L"Iron", 2),
        Mat(L"Animal Bones", 10),
        Mat(L"Aquamarine", 10),
        });
}