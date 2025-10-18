#include "RecipeModel.h"
#include "RecipeModules.h"

using RecipesDB::Mat;
using RecipesDB::Sub;
using RecipesDB::Tool;
using RecipesDB::AddRecipe;

using namespace recipes;

void recipes::RegisterIronwareRecipes() {
    AddRecipe(L"Hammer", {
        Mat(L"Iron", 6),
        Mat(L"Oak", 20),
        Mat(L"Coal", 6),
        Tool(L"Anvil", 1),
        });
    AddRecipe(L"Anvil", {
        Mat(L"Iron", 10),
        Mat(L"Coal", 10),
        });
    AddRecipe(L"Saw", {
        Mat(L"Iron", 4),
        Mat(L"Oak", 20),
        Mat(L"Coal", 6),
        Tool(L"Anvil", 1),
        Tool(L"Hammer", 1),
        });
    AddRecipe(L"Scissor", {
        Mat(L"Iron", 6),
        Mat(L"Oak", 6),
        Tool(L"Anvil", 1),
        Tool(L"Hammer", 1),
        });
    AddRecipe(L"Needle", {
        Mat(L"Iron", 2),
        Mat(L"Charcoal", 10),
        Tool(L"Anvil", 1),
        Tool(L"Hammer", 1),
        });
    AddRecipe(L"Gimlet", {
        Mat(L"Iron", 2),
        Mat(L"Charcoal", 10),
        Mat(L"Oak", 10),
        Tool(L"Anvil", 1),
        Tool(L"Hammer", 1),
        });
    AddRecipe(L"Flat Iron", {
        Mat(L"Iron", 6),
        Mat(L"Oak", 20),
        Mat(L"Coal", 6),
        Tool(L"Anvil", 1),
        Tool(L"Hammer", 1),
        });
    AddRecipe(L"Iron Pot", {
        Mat(L"Iron", 10),
        Mat(L"Coal", 10),
        Tool(L"Anvil", 1),
        Tool(L"Hammer", 1),
        });
    AddRecipe(L"Sawdust", {
        Mat(L"Iron", 10),
        Mat(L"Oak", 40),
        Tool(L"Anvil", 1),
        Tool(L"Hammer", 1),
        Tool(L"Saw", 1),
        });
    AddRecipe(L"Sickle", {
        Mat(L"Iron", 5),
        Mat(L"Oak", 10),
        Tool(L"Anvil", 1),
        Tool(L"Hammer", 1),
        Tool(L"Saw", 1),
        });
    AddRecipe(L"Hoe", {
        Mat(L"Iron", 5),
        Mat(L"Oak", 10),
        Tool(L"Anvil", 1),
        Tool(L"Hammer", 1),
        Tool(L"Saw", 1),
        });
    AddRecipe(L"Composition Tool", {
        Mat(L"Iron Ore", 10),
        Mat(L"Coal", 10),
        Mat(L"Charcoal", 10),
        Tool(L"Anvil", 1),
        Tool(L"Hammer", 1),
        });
    AddRecipe(L"Cutting Tool", {
        Mat(L"Gold Bar", 30),
        Mat(L"Premium Silk", 80),
        Mat(L"Lead", 30),
        Mat(L"Oak", 60),
        });
    AddRecipe(L"Craft Shelf", {
        Mat(L"Diamond", 30),
        Mat(L"Ruby", 30),
        Mat(L"Pine", 80),
        Mat(L"Premium Silk", 60),
        });
}