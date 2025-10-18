#include "RecipeModel.h"
#include "RecipeModules.h"

using RecipesDB::Mat;
using RecipesDB::Sub;
using RecipesDB::Tool;
using RecipesDB::AddRecipe;

using namespace recipes;

void recipes::RegisterCrystalRecipes() {
    AddRecipe(L"Ruby Crystal[F]", {
        Mat(L"Ruby", 5),
        Mat(L"Lithium", 2),
        Mat(L"Strange Fire Powder", 3),
        Mat(L"crystal additive", 5),
        });
    AddRecipe(L"Topaz Crystal[F]", {
        Mat(L"Topaz", 5),
        Mat(L"Lithium", 2),
        Mat(L"Strange Land Powder", 3),
        Mat(L"crystal additive", 5),
        });
    AddRecipe(L"Amethyst Crystal[F]", {
        Mat(L"Amethyst", 5),
        Mat(L"Lithium", 2),
        Mat(L"Strange Wind Powder", 3),
        Mat(L"crystal additive", 5),
        });
    AddRecipe(L"Diamond Crystal[F]", {
        Mat(L"Diamond", 5),
        Mat(L"Lithium", 2),
        Mat(L"Strange unattributable Powder", 3),
        Mat(L"crystal additive", 5),
        });
    AddRecipe(L"Pearl Crystal[F]", {
        Mat(L"Pearl", 5),
        Mat(L"Lithium", 2),
        Mat(L"Strange unattributable Powder", 3),
        Mat(L"crystal additive", 5),
        });
    AddRecipe(L"Sapphire Crystal[F]", {
        Mat(L"Sapphire", 5),
        Mat(L"Lithium", 2),
        Mat(L"Strange Water Powder", 3),
        Mat(L"crystal additive", 5),
        });
    AddRecipe(L"Ruby Crystal[E]", {
        Mat(L"Ruby", 20),
        Mat(L"Lithium", 4),
        Mat(L"Argon", 2),
        Mat(L"Strange Fire Powder", 7),
        Mat(L"crystal additive", 10),
        Tool(L"Composition Tool", 1),
        });
    AddRecipe(L"Topaz Crystal[E]", {
        Mat(L"Topaz", 20),
        Mat(L"Lithium", 4),
        Mat(L"Argon", 2),
        Mat(L"Strange Land Powder", 7),
        Mat(L"crystal additive", 10),
        Tool(L"Composition Tool", 1),
        });
    AddRecipe(L"Amethyst Crystal[E]", {
        Mat(L"Amethyst", 20),
        Mat(L"Lithium", 4),
        Mat(L"Argon", 2),
        Mat(L"Strange Wind Powder", 7),
        Mat(L"crystal additive", 10),
        Tool(L"Composition Tool", 1),
        });
    AddRecipe(L"Diamond Crystal[E]", {
        Mat(L"Diamond", 20),
        Mat(L"Lithium", 4),
        Mat(L"Argon", 2),
        Mat(L"Strange unattributable Powder", 7),
        Mat(L"crystal additive", 10),
        Tool(L"Composition Tool", 1),
        });
    AddRecipe(L"Pearl Crystal[E]", {
        Mat(L"Pearl", 20),
        Mat(L"Lithium", 4),
        Mat(L"Argon", 2),
        Mat(L"Strange unattributable Powder", 7),
        Mat(L"crystal additive", 10),
        Tool(L"Composition Tool", 1),
        });
    AddRecipe(L"Sapphire Crystal[E]", {
        Mat(L"Sapphire", 20),
        Mat(L"Lithium", 4),
        Mat(L"Argon", 2),
        Mat(L"Strange Water Powder", 7),
        Mat(L"crystal additive", 10),
        Tool(L"Composition Tool", 1),
        });
    AddRecipe(L"Ruby Crystal[D]", {
        Mat(L"Ruby", 35),
        Mat(L"Lithium", 5),
        Mat(L"Argon", 3),
        Mat(L"Selenium", 2),
        Mat(L"Strange Fire Powder", 10),
        Mat(L"crystal additive", 15),
        Tool(L"Saw", 1),
        Tool(L"Composition Tool", 1),
        });
    AddRecipe(L"Topaz Crystal[D]", {
        Mat(L"Topaz", 35),
        Mat(L"Lithium", 5),
        Mat(L"Argon", 3),
        Mat(L"Selenium", 2),
        Mat(L"Strange Land Powder", 10),
        Mat(L"crystal additive", 15),
        Tool(L"Saw", 1),
        Tool(L"Composition Tool", 1),
        });
    AddRecipe(L"Amethyst Crystal[D]", {
        Mat(L"Amethyst", 35),
        Mat(L"Lithium", 5),
        Mat(L"Argon", 3),
        Mat(L"Selenium", 2),
        Mat(L"Strange Wind Powder", 10),
        Mat(L"crystal additive", 15),
        Tool(L"Saw", 1),
        Tool(L"Composition Tool", 1),
        });
    AddRecipe(L"Diamond Crystal[D]", {
        Mat(L"Diamond", 35),
        Mat(L"Lithium", 5),
        Mat(L"Argon", 3),
        Mat(L"Selenium", 2),
        Mat(L"Strange unattributable Powder", 10),
        Mat(L"crystal additive", 15),
        Tool(L"Saw", 1),
        Tool(L"Composition Tool", 1),
        });
    AddRecipe(L"Pearl Crystal[D]", {
        Mat(L"Pearl", 35),
        Mat(L"Lithium", 5),
        Mat(L"Argon", 3),
        Mat(L"Selenium", 2),
        Mat(L"Strange unattributable Powder", 10),
        Mat(L"crystal additive", 15),
        Tool(L"Saw", 1),
        Tool(L"Composition Tool", 1),
        });
    AddRecipe(L"Sapphire Crystal[D]", {
        Mat(L"Sapphire", 35),
        Mat(L"Lithium", 5),
        Mat(L"Argon", 3),
        Mat(L"Selenium", 2),
        Mat(L"Strange Water Powder", 10),
        Mat(L"crystal additive", 15),
        Tool(L"Saw", 1),
        Tool(L"Composition Tool", 1),
        });
    AddRecipe(L"Ruby Crystal[C]", {
        Mat(L"Ruby", 55),
        Mat(L"Argon", 4),
        Mat(L"Selenium", 3),
        Mat(L"Rubidium", 2),
        Mat(L"Mysterical Fire Powder", 5),
        Mat(L"crystal additive", 20),
        Tool(L"Saw", 1),
        Tool(L"Composition Tool", 1),
        });
    AddRecipe(L"Topaz Crystal[C]", {
        Mat(L"Topaz", 55),
        Mat(L"Argon", 4),
        Mat(L"Selenium", 3),
        Mat(L"Rubidium", 2),
        Mat(L"Mysterical Land Powder", 5),
        Mat(L"crystal additive", 20),
        Tool(L"Saw", 1),
        Tool(L"Composition Tool", 1),
        });
    AddRecipe(L"Amethyst Crystal[C]", {
        Mat(L"Amethyst", 55),
        Mat(L"Argon", 4),
        Mat(L"Selenium", 3),
        Mat(L"Rubidium", 2),
        Mat(L"Mysterical Wind Powder", 5),
        Mat(L"crystal additive", 20),
        Tool(L"Saw", 1),
        Tool(L"Composition Tool", 1),
        });
    AddRecipe(L"Diamond Crystal[C]", {
        Mat(L"Diamond", 55),
        Mat(L"Argon", 4),
        Mat(L"Selenium", 3),
        Mat(L"Rubidium", 2),
        Mat(L"Mysterical unattributable Powder", 5),
        Mat(L"crystal additive", 20),
        Tool(L"Saw", 1),
        Tool(L"Composition Tool", 1),
        });
    AddRecipe(L"Pearl Crystal[C]", {
        Mat(L"Pearl", 55),
        Mat(L"Argon", 4),
        Mat(L"Selenium", 3),
        Mat(L"Rubidium", 2),
        Mat(L"Mysterical unattributable Powder", 5),
        Mat(L"crystal additive", 20),
        Tool(L"Saw", 1),
        Tool(L"Composition Tool", 1),
        });
    AddRecipe(L"Sapphire Crystal[C]", {
        Mat(L"Sapphire", 55),
        Mat(L"Argon", 5),
        Mat(L"Selenium", 4),
        Mat(L"Rubidium", 2),
        Mat(L"Mysterical Water Powder", 5),
        Mat(L"crystal additive", 20),
        Tool(L"Saw", 1),
        Tool(L"Composition Tool", 1),
        });
    AddRecipe(L"Ruby Crystal[B]", {
        Mat(L"Ruby", 75),
        Mat(L"Argon", 5),
        Mat(L"Selenium", 4),
        Mat(L"Rubidium", 2),
        Mat(L"Mysterical Fire Powder", 7),
        Mat(L"crystal additive", 25),
        Tool(L"Saw", 1),
        Tool(L"Composition Tool", 1),
        });
    AddRecipe(L"Topaz Crystal[B]", {
        Mat(L"Topaz", 75),
        Mat(L"Argon", 5),
        Mat(L"Selenium", 4),
        Mat(L"Rubidium", 2),
        Mat(L"Mysterical Land Powder", 7),
        Mat(L"crystal additive", 25),
        Tool(L"Saw", 1),
        Tool(L"Composition Tool", 1),
        });
    AddRecipe(L"Amethyst Crystal[B]", {
        Mat(L"Amethyst", 75),
        Mat(L"Argon", 5),
        Mat(L"Selenium", 4),
        Mat(L"Rubidium", 2),
        Mat(L"Mysterical Wind Powder", 7),
        Mat(L"crystal additive", 25),
        Tool(L"Saw", 1),
        Tool(L"Composition Tool", 1),
        });
    AddRecipe(L"Diamond Crystal[B]", {
        Mat(L"Diamond", 75),
        Mat(L"Argon", 5),
        Mat(L"Selenium", 4),
        Mat(L"Rubidium", 2),
        Mat(L"Mysterical unattributable Powder", 7),
        Mat(L"crystal additive", 25),
        Tool(L"Saw", 1),
        Tool(L"Composition Tool", 1),
        });
    AddRecipe(L"Pearl Crystal[B]", {
        Mat(L"Pearl", 75),
        Mat(L"Argon", 5),
        Mat(L"Selenium", 4),
        Mat(L"Rubidium", 2),
        Mat(L"Mysterical unattributable Powder", 7),
        Mat(L"crystal additive", 25),
        Tool(L"Saw", 1),
        Tool(L"Composition Tool", 1),
        });
    AddRecipe(L"Sapphire Crystal[B]", {
        Mat(L"Sapphire", 75),
        Mat(L"Argon", 5),
        Mat(L"Selenium", 4),
        Mat(L"Rubidium", 2),
        Mat(L"Mysterical Water Powder", 7),
        Mat(L"crystal additive", 25),
        Tool(L"Saw", 1),
        Tool(L"Composition Tool", 1),
        });
    AddRecipe(L"Ruby Crystal[A]", {
        Mat(L"Ruby", 100),
        Mat(L"Selenium", 5),
        Mat(L"Rubidium", 4),
        Mat(L"Strontium", 2),
        Mat(L"Mysterical Fire Powder", 10),
        Mat(L"crystal additive", 30),
        Tool(L"Saw", 1),
        Tool(L"Composition Tool", 1),
        });
    AddRecipe(L"Topaz Crystal[A]", {
        Mat(L"Topaz", 100),
        Mat(L"Selenium", 5),
        Mat(L"Rubidium", 4),
        Mat(L"Strontium", 2),
        Mat(L"Mysterical Land Powder", 10),
        Mat(L"crystal additive", 30),
        Tool(L"Saw", 1),
        Tool(L"Composition Tool", 1),
        });
    AddRecipe(L"Amethyst Crystal[A]", {
        Mat(L"Amethyst", 100),
        Mat(L"Selenium", 5),
        Mat(L"Rubidium", 4),
        Mat(L"Strontium", 2),
        Mat(L"Mysterical Wind Powder", 10),
        Mat(L"crystal additive", 30),
        Tool(L"Saw", 1),
        Tool(L"Composition Tool", 1),
        });
    AddRecipe(L"Diamond Crystal[A]", {
        Mat(L"Diamond", 100),
        Mat(L"Selenium", 5),
        Mat(L"Rubidium", 4),
        Mat(L"Strontium", 2),
        Mat(L"Mysterical unattributable Powder", 10),
        Mat(L"crystal additive", 30),
        Tool(L"Saw", 1),
        Tool(L"Composition Tool", 1),
        });
    AddRecipe(L"Pearl Crystal[A]", {
        Mat(L"Pearl", 100),
        Mat(L"Selenium", 5),
        Mat(L"Rubidium", 4),
        Mat(L"Strontium", 2),
        Mat(L"Mysterical unattributable Powder", 10),
        Mat(L"crystal additive", 30),
        Tool(L"Saw", 1),
        Tool(L"Composition Tool", 1),
        });
    AddRecipe(L"Sapphire Crystal[A]", {
        Mat(L"Sapphire", 100),
        Mat(L"Selenium", 5),
        Mat(L"Rubidium", 4),
        Mat(L"Strontium", 2),
        Mat(L"Mysterical Water Powder", 10),
        Mat(L"crystal additive", 30),
        Tool(L"Saw", 1),
        Tool(L"Composition Tool", 1),
        });
    AddRecipe(L"Ruby Crystal[S1]", {
        Mat(L"Ruby", 125),
        Mat(L"Rubidium", 5),
        Mat(L"Strontium", 3),
        Mat(L"Cadium", 2),
        Mat(L"Illusionary Fire Powder", 5),
        Mat(L"crystal additive", 30),
        Tool(L"Saw", 1),
        Tool(L"Composition Tool", 1),
        });
    AddRecipe(L"Topaz Crystal[S1]", {
        Mat(L"Topaz", 125),
        Mat(L"Rubidium", 5),
        Mat(L"Strontium", 3),
        Mat(L"Cadium", 2),
        Mat(L"Illusionary Land Powder", 5),
        Mat(L"crystal additive", 30),
        Tool(L"Saw", 1),
        Tool(L"Composition Tool", 1),
        });
    AddRecipe(L"Amethyst Crystal[S1]", {
        Mat(L"Amethyst", 125),
        Mat(L"Rubidium", 5),
        Mat(L"Strontium", 3),
        Mat(L"Cadium", 2),
        Mat(L"Illusionary Wind Powder", 5),
        Mat(L"crystal additive", 30),
        Tool(L"Saw", 1),
        Tool(L"Composition Tool", 1),
        });
    AddRecipe(L"Diamond Crystal[S1]", {
        Mat(L"Diamond", 125),
        Mat(L"Rubidium", 5),
        Mat(L"Strontium", 3),
        Mat(L"Cadium", 2),
        Mat(L"Illusionary unattributable Powder", 5),
        Mat(L"crystal additive", 30),
        Tool(L"Saw", 1),
        Tool(L"Composition Tool", 1),
        });
    AddRecipe(L"Pearl Crystal[S1]", {
        Mat(L"Pearl", 125),
        Mat(L"Rubidium", 5),
        Mat(L"Strontium", 3),
        Mat(L"Cadium", 2),
        Mat(L"Illusionary unattributable Powder", 5),
        Mat(L"crystal additive", 30),
        Tool(L"Saw", 1),
        Tool(L"Composition Tool", 1),
        });
    AddRecipe(L"Sapphire Crystal[S1]", {
        Mat(L"Sapphire", 125),
        Mat(L"Rubidium", 5),
        Mat(L"Strontium", 3),
        Mat(L"Cadium", 2),
        Mat(L"Illusionary Water Powder", 5),
        Mat(L"crystal additive", 30),
        Tool(L"Saw", 1),
        Tool(L"Composition Tool", 1),
        });
    AddRecipe(L"Ruby Crystal[S2]", {
        Mat(L"Ruby", 150),
        Mat(L"Strontium", 4),
        Mat(L"Cadium", 3),
        Mat(L"Fradium", 2),
        Mat(L"Illusionary Fire Powder", 10),
        Mat(L"crystal additive", 30),
        Tool(L"Saw", 1),
        Tool(L"Composition Tool", 1),
        });
    AddRecipe(L"Topaz Crystal[S2]", {
        Mat(L"Topaz", 150),
        Mat(L"Strontium", 4),
        Mat(L"Cadium", 3),
        Mat(L"Fradium", 2),
        Mat(L"Illusionary Land Powder", 10),
        Mat(L"crystal additive", 30),
        Tool(L"Saw", 1),
        Tool(L"Composition Tool", 1),
        });
    AddRecipe(L"Amethyst Crystal[S2]", {
        Mat(L"Amethyst", 150),
        Mat(L"Strontium", 4),
        Mat(L"Cadium", 3),
        Mat(L"Fradium", 2),
        Mat(L"Illusionary Wind Powder", 10),
        Mat(L"crystal additive", 30),
        Tool(L"Saw", 1),
        Tool(L"Composition Tool", 1),
        });
    AddRecipe(L"Diamond Crystal[S2]", {
        Mat(L"Diamond", 150),
        Mat(L"Strontium", 4),
        Mat(L"Cadium", 3),
        Mat(L"Fradium", 2),
        Mat(L"Illusionary unattributable Powder", 10),
        Mat(L"crystal additive", 30),
        Tool(L"Saw", 1),
        Tool(L"Composition Tool", 1),
        });
    AddRecipe(L"Pearl Crystal[S2]", {
        Mat(L"Pearl", 150),
        Mat(L"Strontium", 4),
        Mat(L"Cadium", 3),
        Mat(L"Fradium", 2),
        Mat(L"Illusionary unattributable Powder", 10),
        Mat(L"crystal additive", 30),
        Tool(L"Saw", 1),
        Tool(L"Composition Tool", 1),
        });
    AddRecipe(L"Sapphire Crystal[S2]", {
        Mat(L"Sapphire", 150),
        Mat(L"Strontium", 4),
        Mat(L"Cadium", 3),
        Mat(L"Fradium", 2),
        Mat(L"Illusionary Water Powder", 10),
        Mat(L"crystal additive", 30),
        Tool(L"Saw", 1),
        Tool(L"Composition Tool", 1),
        });
}