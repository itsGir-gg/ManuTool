#include "RecipeModel.h"
#include "RecipeModules.h"

using RecipesDB::Mat;
using RecipesDB::Sub;
using RecipesDB::Tool;
using RecipesDB::AddRecipe;

using namespace recipes;

void recipes::RegisterPotteryRecipes() {
    AddRecipe(L"Bowl", {
        Mat(L"Clay", 40),
        Mat(L"Glaze", 10),
        Mat(L"Charcoal", 2),
        });
    AddRecipe(L"Medicine Bowl", {
        Mat(L"Clay", 40),
        Mat(L"Glaze", 10),
        Mat(L"Charcoal", 2),
        });
    AddRecipe(L"Pottery", {
        Mat(L"Clay", 40),
        Mat(L"Glaze", 20),
        Mat(L"Charcoal", 4),
        });
    AddRecipe(L"Plate", {
        Mat(L"Clay", 16),
        Mat(L"Glaze", 10),
        Mat(L"Charcoal", 4),
        });
    AddRecipe(L"Grinding Stone", {
        Mat(L"Clay-slate Stone", 30),
        Mat(L"Oak", 6),
        });
    AddRecipe(L"Mortar", {
        Mat(L"Clay-slate Stone", 60),
        });
    AddRecipe(L"Brass Crafting Dish", {
        Mat(L"Brass", 10),
        Mat(L"Charcoal", 20),
        Tool(L"Hammer", 1),
        });
}