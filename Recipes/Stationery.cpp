#include "RecipeModel.h"
#include "RecipeModules.h"

using RecipesDB::Mat;
using RecipesDB::Sub;
using RecipesDB::Tool;
using RecipesDB::AddRecipe;

using namespace recipes;

void recipes::RegisterStationeryRecipes() {
    AddRecipe(L"Ink Stick", {
        Mat(L"Sesame Oil", 4),
        Mat(L"Charcoal", 2),
        Tool(L"Mortar", 1),
        });
    AddRecipe(L"Ink Stone", {
        Mat(L"Clay-slate Stone", 30),
        });
    AddRecipe(L"Writing Brush", {
        Mat(L"Animal Fur", 40),
        Mat(L"Bamboo", 10),
        });
}