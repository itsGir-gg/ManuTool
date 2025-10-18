#include "RecipeModel.h"
#include "RecipeModules.h"

using RecipesDB::Mat;
using RecipesDB::Sub;
using RecipesDB::Tool;
using RecipesDB::AddRecipe;

using namespace recipes;

void recipes::RegisterTools() {
    RecipesDB::Add(Recipe{ L"Anvil", {} });
    RecipesDB::Add(Recipe{ L"Hammer", {} });
    RecipesDB::Add(Recipe{ L"Saw", {} });
    RecipesDB::Add(Recipe{ L"Sawdust", {} });
    RecipesDB::Add(Recipe{ L"Pottery", {} });
    RecipesDB::Add(Recipe{ L"Bowl", {} });
    RecipesDB::Add(Recipe{ L"Medicine Bowl", {} });
}