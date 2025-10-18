#include "RecipeModel.h"
#include "RecipeModules.h"

using RecipesDB::Mat;
using RecipesDB::Sub;
using RecipesDB::Tool;
using RecipesDB::AddRecipe;

using namespace recipes;

void recipes::RegisterBowRecipes() {
    AddRecipe(L"Wooden Bow", {
        Mat(L"Oak", 3),
        Mat(L"Cowhide", 3),
        });
    AddRecipe(L"Bamboo Bow", {
        Mat(L"Bamboo", 15),
        Mat(L"Cowhide", 5),
        Mat(L"Gold Ore", 3),
        });
    AddRecipe(L"Iron Bow", {
        Mat(L"Cowhide", 8),
        Mat(L"Gold Bar", 1),
        Mat(L"Iron", 2),
        });
    AddRecipe(L"Steel Bow", {
        Mat(L"Cowhide", 10),
        Mat(L"Gold Bar", 2),
        Mat(L"Iron", 5),
        });
    AddRecipe(L"Long Bow", {
        Mat(L"Cowhide", 15),
        Mat(L"Gold Bar", 3),
        Mat(L"Iron", 7),
        Mat(L"Copper", 5),
        Tool(L"Anvil", 1),
        });
    AddRecipe(L"Light Crossbow", {
        Mat(L"Cowhide", 15),
        Mat(L"Gold Bar", 5),
        Mat(L"Silver Bar", 2),
        Mat(L"Iron", 10),
        Mat(L"Jade", 10),
        Mat(L"Copper", 7),
        Tool(L"Anvil", 1),
        });
    AddRecipe(L"Hunter's Bow", {
        Mat(L"Cowhide", 20),
        Mat(L"Gold Bar", 5),
        Mat(L"Silver Bar", 7),
        Mat(L"Iron", 11),
        Mat(L"Jade", 12),
        Mat(L"Copper", 10),
        Tool(L"Anvil", 1),
        });
    AddRecipe(L"Heavy Crossbow", {
        Sub(L"Light Crossbow", 1),
        Mat(L"Cowhide", 20),
        Mat(L"Premium Silk", 20),
        Mat(L"Satin", 15),
        Mat(L"Gold Bar", 9),
        Mat(L"Silver Bar", 7),
        Mat(L"Iron", 15),
        Mat(L"Jade", 14),
        Mat(L"Copper", 12),
        Mat(L"Lubricant", 1),
        Tool(L"Anvil", 1),
        Tool(L"Hammer", 1),
        });
    AddRecipe(L"Robin Hood", {
        Sub(L"Hunter's Bow", 1),
        Mat(L"Cowhide", 25),
        Mat(L"Premium Silk", 25),
        Mat(L"Satin", 20),
        Mat(L"Gold Bar", 9),
        Mat(L"Silver Bar", 7),
        Mat(L"Iron", 16),
        Mat(L"Jade", 16),
        Mat(L"Copper", 15),
        Mat(L"Lubricant", 3),
        Tool(L"Anvil", 1),
        Tool(L"Hammer", 1),
        });
    AddRecipe(L"Skill Crossbow", {
        Sub(L"Heavy Crossbow", 1),
        Mat(L"Cowhide", 25),
        Mat(L"Premium Silk", 30),
        Mat(L"Satin", 25),
        Mat(L"Gold Bar", 12),
        Mat(L"Silver Bar", 9),
        Mat(L"Iron", 21),
        Mat(L"Jade", 18),
        Mat(L"Copper", 20),
        Mat(L"Lubricant", 5),
        Tool(L"Anvil", 1),
        Tool(L"Hammer", 1),
        });
    AddRecipe(L"Elfin Bow", {
        Sub(L"Robin Hood", 1),
        Mat(L"Cowhide", 30),
        Mat(L"Premium Silk", 35),
        Mat(L"Satin", 30),
        Mat(L"Gold Bar", 12),
        Mat(L"Silver Bar", 15),
        Mat(L"Iron", 22),
        Mat(L"Jade", 20),
        Mat(L"Copper", 25),
        Mat(L"Lubricant", 7),
        Tool(L"Anvil", 1),
        Tool(L"Hammer", 1),
        Tool(L"Gimlet", 1),
        });
    AddRecipe(L"Composite Bow", {
        Sub(L"Skill Crossbow", 1),
        Mat(L"Cowhide", 35),
        Mat(L"Premium Silk", 40),
        Mat(L"Satin", 35),
        Mat(L"Gold Bar", 15),
        Mat(L"Silver Bar", 19),
        Mat(L"Iron", 30),
        Mat(L"Jade", 24),
        Mat(L"Copper", 35),
        Mat(L"Lubricant", 10),
        Tool(L"Anvil", 1),
        Tool(L"Hammer", 1),
        Tool(L"Gimlet", 1),
        });
    AddRecipe(L"Taebaek Bow", {
        Sub(L"Elfin Bow", 1),
        Mat(L"Cowhide", 40),
        Mat(L"Premium Silk", 45),
        Mat(L"Satin", 40),
        Mat(L"Gold Bar", 19),
        Mat(L"Silver Bar", 20),
        Mat(L"Iron", 32),
        Mat(L"Jade", 25),
        Mat(L"Copper", 36),
        Mat(L"Lubricant", 12),
        Tool(L"Anvil", 1),
        Tool(L"Hammer", 1),
        Tool(L"Gimlet", 1),
        });
    AddRecipe(L"Arbalest", {
        Sub(L"Composite Bow", 1),
        Mat(L"Cowhide", 45),
        Mat(L"Premium Silk", 60),
        Mat(L"Satin", 60),
        Mat(L"Gold Bar", 30),
        Mat(L"Silver Bar", 30),
        Mat(L"Iron", 35),
        Mat(L"Jade", 35),
        Mat(L"Copper", 50),
        Mat(L"Lubricant", 18),
        Tool(L"Anvil", 1),
        Tool(L"Hammer", 1),
        Tool(L"Gimlet", 1),
        Tool(L"Sawdust", 1),
        });
    AddRecipe(L"Thunderbolt Bow", {
        Sub(L"Taebaek Bow", 1),
        Mat(L"Cowhide", 50),
        Mat(L"Premium Silk", 65),
        Mat(L"Satin", 65),
        Mat(L"Gold Bar", 30),
        Mat(L"Silver Bar", 40),
        Mat(L"Iron", 35),
        Mat(L"Jade", 35),
        Mat(L"Copper", 50),
        Mat(L"Lubricant", 20),
        Tool(L"Anvil", 1),
        Tool(L"Hammer", 1),
        Tool(L"Gimlet", 1),
        Tool(L"Sawdust", 1),
        });
    AddRecipe(L"Dragon Claw", {
        Mat(L"Titanium",   30),
        Mat(L"Aramid",    120),
        Mat(L"Mahogany",  150),
        Mat(L"Bronze",     70),
        Mat(L"Lead",       60),
        Mat(L"Spiky Silk", 60),
        Mat(L"Black Silk", 60),
        Mat(L"Premium Silk", 200),
        Mat(L"Lubricant",  10),
        Tool(L"Anvil",      1),
        Tool(L"Hammer",     1),
        Tool(L"Gimlet",     1),
        Tool(L"Sawdust",    1),
        });
    AddRecipe(L"Nymph's Bow", {
        Mat(L"Titanium",   40),
        Mat(L"Aramid",    130),
        Mat(L"Mahogany",  160),
        Mat(L"Bronze",    120),
        Mat(L"Lead",      110),
        Mat(L"Spiky Silk",110),
        Mat(L"Black Silk",110),
        Mat(L"Premium Silk",250),
        Mat(L"Lubricant",  20),
        Tool(L"Anvil",      1),
        Tool(L"Hammer",     1),
        Tool(L"Gimlet",     1),
        Tool(L"Sawdust",    1),
        });
    AddRecipe(L"Paladin Flash Bow", {
        Mat(L"Titanium",   50),
        Mat(L"Aramid",    170),
        Mat(L"Mahogany",  200),
        Mat(L"Bronze",    130),
        Mat(L"Lead",      145),
        Mat(L"Spiky Silk",145),
        Mat(L"Black Silk",145),
        Mat(L"Feather",   100),
        Mat(L"Pine",      140),
        Mat(L"Premium Silk",270),
        Mat(L"Lubricant",  35),
        Tool(L"Anvil",      1),
        Tool(L"Hammer",     1),
        Tool(L"Gimlet",     1),
        Tool(L"Sawdust",    1),
        });
}