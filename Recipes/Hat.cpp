#include "RecipeModel.h"
#include "RecipeModules.h"

using RecipesDB::Mat;
using RecipesDB::Sub;
using RecipesDB::Tool;
using RecipesDB::AddRecipe;

using namespace recipes;

void recipes::RegisterHatRecipes() {
    AddRecipe(L"Traveler Hat[Avatar]", {
        Mat(L"Thread Bobbin", 5),
        Mat(L"Feather", 6),
        Mat(L"Animal Fur", 6),
        Mat(L"Bamboo", 2),
        Mat(L"Coal", 2),
        Tool(L"Gimlet", 1),
        });
    AddRecipe(L"School Hat[Avatar]", {
        Mat(L"Thread Bobbin", 10),
        Mat(L"Feather", 12),
        Mat(L"Animal Fur", 9),
        Mat(L"Bamboo", 4),
        Mat(L"Coal", 4),
        Tool(L"Gimlet", 1),
        });
    AddRecipe(L"Cheering Hat[Avatar]", {
        Mat(L"Thread Bobbin", 15),
        Mat(L"Feather", 18),
        Mat(L"Animal Fur", 12),
        Mat(L"Bamboo", 6),
        Mat(L"Coal", 6),
        Tool(L"Gimlet", 1),
        });
    AddRecipe(L"Craftsman Hat[Avatar]", {
        Mat(L"Thread Bobbin", 20),
        Mat(L"Feather", 24),
        Mat(L"Animal Fur", 15),
        Mat(L"Bamboo", 8),
        Mat(L"Coal", 8),
        Tool(L"Gimlet", 1),
        });
    AddRecipe(L"Adventurer Hat[Avatar]", {
        Mat(L"Cotton", 10),
        Mat(L"Feather", 30),
        Mat(L"Animal Fur", 18),
        Mat(L"Bamboo", 10),
        Mat(L"Jade", 4),
        Mat(L"Ramie", 3),
        Tool(L"Gimlet", 1),
        Tool(L"Cutting Tool", 1),
        });
}