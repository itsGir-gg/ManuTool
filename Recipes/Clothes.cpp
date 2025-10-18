#include "RecipeModel.h"
#include "RecipeModules.h"

using RecipesDB::Mat;
using RecipesDB::Sub;
using RecipesDB::Tool;
using RecipesDB::AddRecipe;

using namespace recipes;

void recipes::RegisterClothesRecipes() {
    AddRecipe(L"Traveler Suit[Avatar]", {
        Mat(L"Cowhide", 5),
        Mat(L"Feather", 6),
        Mat(L"Animal Fur", 6),
        Mat(L"Bamboo", 2),
        Mat(L"Amber", 2),
        Tool(L"Flat Iron", 1),
        });
    AddRecipe(L"School Uniform[Avatar]", {
        Mat(L"Cowhide", 10),
        Mat(L"Feather", 12),
        Mat(L"Animal Fur", 9),
        Mat(L"Bamboo", 4),
        Mat(L"Amber", 4),
        Tool(L"Flat Iron", 1),
        });
    AddRecipe(L"Cheering Suit[Avatar]", {
        Mat(L"Cowhide", 15),
        Mat(L"Feather", 18),
        Mat(L"Animal Fur", 12),
        Mat(L"Bamboo", 6),
        Mat(L"Amber", 6),
        Tool(L"Flat Iron", 1),
        });
    AddRecipe(L"Craftsman Suit[Avatar]", {
        Mat(L"Cowhide", 20),
        Mat(L"Feather", 24),
        Mat(L"Animal Fur", 15),
        Mat(L"Bamboo", 8),
        Mat(L"Amber", 8),
        Tool(L"Flat Iron", 1),
        });
    AddRecipe(L"Adventurer Suit[Avatar]", {
        Mat(L"Silk", 17),
        Mat(L"Feather", 30),
        Mat(L"Animal Fur", 18),
        Mat(L"Bamboo", 10),
        Mat(L"Coral", 4),
        Mat(L"Ramie", 3),
        Tool(L"Flat Iron", 1),
        Tool(L"Cutting Tool", 1),
        });
}