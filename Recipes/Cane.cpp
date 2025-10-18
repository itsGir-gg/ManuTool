#include "RecipeModel.h"
#include "RecipeModules.h"

using RecipesDB::Mat;
using RecipesDB::Sub;
using RecipesDB::Tool;
using RecipesDB::AddRecipe;

using namespace recipes;

void recipes::RegisterCaneRecipes() {
    AddRecipe(L"Bamboo Cane", {
        Mat(L"Bamboo", 10),
        Mat(L"Sulfur", 1),
        });
    AddRecipe(L"Apprentice Cane", {
        Mat(L"Oak", 2),
        Mat(L"Sulfur", 5),
        Mat(L"Gold Ore", 1),
        Mat(L"Silver Ore", 1),
        Mat(L"Iron Ore", 3),
        });
    AddRecipe(L"Wizard Cane", {
        Mat(L"Oak", 3),
        Mat(L"Sulfur", 10),
        Mat(L"Gold Ore", 4),
        Mat(L"Silver Ore", 4),
        Mat(L"Iron Ore", 4),
        });
    AddRecipe(L"Fisher's Cane", {
        Mat(L"Oak", 5),
        Mat(L"Cowhide", 3),
        Mat(L"Gold Bar", 3),
        Mat(L"Silver Bar", 3),
        Mat(L"Iron", 2),
        Mat(L"Jade", 7),
        Mat(L"Sulfur", 15),
        });
    AddRecipe(L"Master Cane", {
        Mat(L"Oak", 7),
        Mat(L"Cowhide", 5),
        Mat(L"Gold Bar", 5),
        Mat(L"Silver Bar", 5),
        Mat(L"Iron", 4),
        Mat(L"Jade", 10),
        Mat(L"Sulfur", 20),
        Tool(L"Anvil", 1),
        });
    AddRecipe(L"Snake Cane", {
        Mat(L"Charcoal", 3),
        Mat(L"Satin", 30),
        Mat(L"Cotton", 5),
        Mat(L"Gold Bar", 10),
        Mat(L"Silver Bar", 10),
        Mat(L"Iron", 5),
        Mat(L"Jade", 15),
        Mat(L"Sulfur", 25),
        Tool(L"Anvil", 1),
        });
    AddRecipe(L"Ivory Cane", {
        Mat(L"Charcoal", 5),
        Mat(L"Premium Silk", 30),
        Mat(L"Cotton", 10),
        Mat(L"Gold Bar", 15),
        Mat(L"Silver Bar", 12),
        Mat(L"Iron", 7),
        Mat(L"Jade", 15),
        Mat(L"Sulfur", 30),
        Tool(L"Anvil", 1),
        });
    AddRecipe(L"Wing Cane", {
        Sub(L"Snake Cane", 1),
        Mat(L"Charcoal", 9),
        Mat(L"Satin", 45),
        Mat(L"Cotton", 15),
        Mat(L"Gold Bar", 17),
        Mat(L"Silver Bar", 17),
        Mat(L"Iron", 10),
        Mat(L"Jade", 20),
        Mat(L"Sulfur", 35),
        Mat(L"Lubricant", 1),
        Tool(L"Anvil", 1),
        Tool(L"Hammer", 1),
        });
    AddRecipe(L"Hermit's Cane", {
        Sub(L"Ivory Cane", 1),
        Mat(L"Charcoal", 10),
        Mat(L"Premium Silk", 45),
        Mat(L"Cotton", 20),
        Mat(L"Gold Bar", 20),
        Mat(L"Silver Bar", 18),
        Mat(L"Iron", 12),
        Mat(L"Jade", 22),
        Mat(L"Sulfur", 37),
        Mat(L"Lubricant", 3),
        Tool(L"Anvil", 1),
        Tool(L"Hammer", 1),
        });
    AddRecipe(L"Star Cane", {
        Sub(L"Wing Cane", 1),
        Mat(L"Charcoal", 15),
        Mat(L"Satin", 55),
        Mat(L"Cotton", 25),
        Mat(L"Gold Bar", 23),
        Mat(L"Silver Bar", 23),
        Mat(L"Iron",15),
        Mat(L"Jade", 25),
        Mat(L"Sulfur", 40),
        Mat(L"Lubricant", 5),
        Tool(L"Anvil", 1),
        Tool(L"Hammer", 1),
        });
    AddRecipe(L"Spirit Cane", {
        Sub(L"Hermit's Cane", 1),
        Mat(L"Charcoal",    15),
        Mat(L"Premium Silk", 55),
        Mat(L"Cotton",      30),
        Mat(L"Gold Bar",    25),
        Mat(L"Silver Bar",  24),
        Mat(L"Iron",        17),
        Mat(L"Jade",        28),
        Mat(L"Sulfur",      43),
        Mat(L"Lubricant",    7),
        Tool(L"Anvil",       1),
        Tool(L"Hammer",      1),
        Tool(L"Gimlet",      1),
        });
    AddRecipe(L"Golden Spear Cane", {
        Sub(L"Star Cane",   1),
        Mat(L"Charcoal",   24),
        Mat(L"Satin",      70),
        Mat(L"Cotton",     40),
        Mat(L"Gold Bar",   35),
        Mat(L"Silver Bar", 33),
        Mat(L"Iron",       30),
        Mat(L"Jade",       40),
        Mat(L"Sulfur",     60),
        Mat(L"Lubricant",  10),
        Tool(L"Anvil",      1),
        Tool(L"Hammer",     1),
        Tool(L"Gimlet",     1),
        });
    AddRecipe(L"Taebaek Cane", {
        Sub(L"Spirit Cane", 1),
        Mat(L"Charcoal",   25),
        Mat(L"Premium Silk", 70),
        Mat(L"Cotton",     45),
        Mat(L"Gold Bar",   35),
        Mat(L"Silver Bar", 35),
        Mat(L"Iron",       30),
        Mat(L"Jade",       45),
        Mat(L"Sulfur",     60),
        Mat(L"Lubricant",  12),
        Tool(L"Anvil",      1),
        Tool(L"Hammer",     1),
        Tool(L"Gimlet",     1),
        });
    AddRecipe(L"Orchestra Tact", {
        Sub(L"Golden Spear Cane", 1),
        Mat(L"Charcoal",   30),
        Mat(L"Satin",      80),
        Mat(L"Cotton",     55),
        Mat(L"Gold Bar",   45),
        Mat(L"Silver Bar", 50),
        Mat(L"Iron",       35),
        Mat(L"Jade",       50),
        Mat(L"Sulfur",     70),
        Mat(L"Lubricant",  18),
        Tool(L"Anvil",      1),
        Tool(L"Hammer",     1),
        Tool(L"Gimlet",     1),
        Tool(L"Sawdust",    1),
        });
    AddRecipe(L"Fairy Cane", {
        Sub(L"Taebaek Cane", 1),
        Mat(L"Charcoal",     35),
        Mat(L"Premium Silk", 80),
        Mat(L"Cotton",       60),
        Mat(L"Gold Bar",     50),
        Mat(L"Silver Bar",   50),
        Mat(L"Iron",         35),
        Mat(L"Jade",         55),
        Mat(L"Sulfur",       70),
        Mat(L"Lubricant",    20),
        Tool(L"Anvil",      1),
        Tool(L"Hammer",     1),
        Tool(L"Gimlet",     1),
        Tool(L"Sawdust",    1),
        });
    AddRecipe(L"Heaven's Judgement", {
        Mat(L"Titanium",   20),
        Mat(L"Aramid",    120),
        Mat(L"Mahogany",  160),
        Mat(L"Bronze",     10),
        Mat(L"Lead",       10),
        Mat(L"Spiky Silk",120),
        Mat(L"Black Silk",110),
        Mat(L"Cotton",     200),
        Mat(L"Lubricant",  10),
        Tool(L"Anvil",      1),
        Tool(L"Hammer",     1),
        Tool(L"Gimlet",     1),
        Tool(L"Sawdust",    1),
        });
    AddRecipe(L"Undine Cane", {
        Mat(L"Titanium",   30),
        Mat(L"Aramid",    130),
        Mat(L"Mahogany",  170),
        Mat(L"Bronze",     60),
        Mat(L"Lead",       60),
        Mat(L"Spiky Silk",170),
        Mat(L"Black Silk",160),
        Mat(L"Cotton",    250),
        Mat(L"Lubricant",  20),
        Tool(L"Anvil",      1),
        Tool(L"Hammer",     1),
        Tool(L"Gimlet",     1),
        Tool(L"Sawdust",    1),
        });
    AddRecipe(L"Paladin moonlight Cane", {
        Mat(L"Titanium",    50),
        Mat(L"Aramid",     160),
        Mat(L"Mahogany",   210),
        Mat(L"Lead",        80),
        Mat(L"Black Silk", 150),
        Mat(L"Spiky Silk", 190),
        Mat(L"Limestone",  110),
        Mat(L"Clay",       130),
        Mat(L"Cotton",     270),
        Mat(L"Lubricant",   35),
        Tool(L"Anvil",       1),
        Tool(L"Hammer",      1),
        Tool(L"Gimlet",     1),
        Tool(L"Sawdust",    1),
        });
}