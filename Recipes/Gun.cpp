#include "RecipeModel.h"
#include "RecipeModules.h"

using RecipesDB::Mat;
using RecipesDB::Sub;
using RecipesDB::Tool;
using RecipesDB::AddRecipe;

using namespace recipes;

void recipes::RegisterGunRecipes() {
    AddRecipe(L"Rifle", {
        Mat(L"Oak", 5),
        Mat(L"Cowhide", 3),
        });
    AddRecipe(L"Stylish Rifle", {
        Mat(L"Oak", 7),
        Mat(L"Coal", 5),
        Mat(L"Gold Ore", 4),
        Mat(L"Silver Ore", 4),
        Mat(L"Iron Ore", 4),
        });
    AddRecipe(L"Warrior's Gun", {
        Mat(L"Oak", 9),
        Mat(L"Gold Bar", 2),
        Mat(L"Silver Bar", 2),
        Mat(L"Iron", 3),
        Mat(L"Coal", 7),
        });
    AddRecipe(L"Meteorite Gun", {
        Mat(L"Oak", 12),
        Mat(L"Gold Bar", 3),
        Mat(L"Silver Bar", 3),
        Mat(L"Iron", 5),
        Mat(L"Coal", 9),
        });
    AddRecipe(L"Thunderbolt Gun", {
        Mat(L"Oak", 14),
        Mat(L"Gold Bar", 4),
        Mat(L"Silver Bar", 4),
        Mat(L"Iron", 7),
        Mat(L"Coal", 15),
        Tool(L"Anvil", 1),
        });
    AddRecipe(L"Musketeer's Gun", {
        Mat(L"Charcoal", 5),
        Mat(L"Silk", 5),
        Mat(L"Gold Bar", 20),
        Mat(L"Iron", 8),
        Mat(L"Coal", 15),
        Mat(L"Copper", 10),
        Mat(L"Coal", 6),
        Tool(L"Anvil", 1),
        });
    AddRecipe(L"Dragon Shotgun", {
        Mat(L"Charcoal", 10),
        Mat(L"Silk", 10),
        Mat(L"Silver Bar", 20),
        Mat(L"Iron", 9),
        Mat(L"Coal", 19),
        Mat(L"Jade", 10),
        Mat(L"Copper", 15),
        Mat(L"Sulfur", 12),
        Tool(L"Anvil", 1),
        });
    AddRecipe(L"Grenade Launcher", {
        Sub(L"Musketeer's Gun", 1),
        Mat(L"Charcoal", 15),
        Mat(L"Silk", 15),
        Mat(L"Gold Bar", 30),
        Mat(L"Iron", 10),
        Mat(L"Coal", 20),
        Mat(L"Jade", 10),
        Mat(L"Copper", 20),
        Mat(L"Sulfur", 20),
        Mat(L"Lubricant", 1),
        Tool(L"Anvil", 1),
        Tool(L"Hammer", 1),
        });
    AddRecipe(L"Earthquake Launcher", {
        Sub(L"Dragon Shotgun", 1),
        Mat(L"Charcoal", 19),
        Mat(L"Silk", 15),
        Mat(L"Silver Bar", 30),
        Mat(L"Iron", 11),
        Mat(L"Coal", 24),
        Mat(L"Jade", 20),
        Mat(L"Copper", 25),
        Mat(L"Sulfur", 26),
        Mat(L"Lubricant", 3),
        Tool(L"Anvil", 1),
        Tool(L"Hammer", 1),
        });
    AddRecipe(L"Burst Shotgun", {
        Sub(L"Grenade Launcher", 1),
        Mat(L"Charcoal", 25),
        Mat(L"Silk", 25),
        Mat(L"Gold Bar", 45),
        Mat(L"Iron", 12),
        Mat(L"Coal", 25),
        Mat(L"Jade", 30),
        Mat(L"Copper", 30),
        Mat(L"Sulfur", 30),
        Mat(L"Lubricant", 5),
        Tool(L"Anvil", 1),
        Tool(L"Hammer", 1),
        });
    AddRecipe(L"Dragon Rifle", {
        Sub(L"Earthquake Launcher", 1),
        Mat(L"Charcoal", 35),
        Mat(L"Silk", 35),
        Mat(L"Silver Bar", 45),
        Mat(L"Iron", 13),
        Mat(L"Coal", 29),
        Mat(L"Jade", 40),
        Mat(L"Copper", 35),
        Mat(L"Sulfur", 38),
        Mat(L"Lubricant", 7),
        Tool(L"Anvil", 1),
        Tool(L"Hammer", 1),
        Tool(L"Gimlet", 1),
        });
    AddRecipe(L"Sniper's Rifle", {
        Sub(L"Burst Shotgun", 1),
        Mat(L"Charcoal", 35),
        Mat(L"Silk", 35),
        Mat(L"Gold Bar", 55),
        Mat(L"Iron", 14),
        Mat(L"Coal", 30),
        Mat(L"Jade", 40),
        Mat(L"Copper", 40),
        Mat(L"Sulfur", 45),
        Mat(L"Lubricant", 10),
        Tool(L"Anvil", 1),
        Tool(L"Hammer", 1),
        Tool(L"Gimlet", 1),
        });
    AddRecipe(L"Taebaek Cannon", {
        Sub(L"Dragon Rifle", 1),
        Mat(L"Charcoal", 45),
        Mat(L"Silk", 45),
        Mat(L"Silver Bar", 60),
        Mat(L"Iron", 30),
        Mat(L"Coal", 34),
        Mat(L"Jade", 50),
        Mat(L"Copper", 45),
        Mat(L"Sulfur", 49),
        Mat(L"Lubricant", 12),
        Tool(L"Anvil", 1),
        Tool(L"Hammer", 1),
        Tool(L"Gimlet", 1),
        });
    AddRecipe(L"Hellfire", {
        Sub(L"Sniper's Rifle", 1),
        Mat(L"Charcoal", 45),
        Mat(L"Silk", 50),
        Mat(L"Gold Bar", 60),
        Mat(L"Iron", 40),
        Mat(L"Coal", 50),
        Mat(L"Jade", 60),
        Mat(L"Copper", 50),
        Mat(L"Sulfur", 70),
        Mat(L"Lubricant", 18),
        Tool(L"Anvil", 1),
        Tool(L"Hammer", 1),
        Tool(L"Gimlet", 1),
        Tool(L"Sawdust", 1),
        });
    AddRecipe(L"Heavy Wind Gun", {
        Sub(L"Taebaek Cannon", 1),
        Mat(L"Charcoal", 50),
        Mat(L"Silk", 50),
        Mat(L"Silver Bar", 70),
        Mat(L"Iron", 50),
        Mat(L"Coal", 55),
        Mat(L"Jade", 70),
        Mat(L"Copper", 55),
        Mat(L"Sulfur", 70),
        Mat(L"Lubricant", 20),
        Tool(L"Anvil", 1),
        Tool(L"Hammer", 1),
        Tool(L"Gimlet", 1),
        Tool(L"Sawdust", 1),
        });
    AddRecipe(L"Desperado", {
        Mat(L"Titanium",  130),
        Mat(L"Aramid",    150),
        Mat(L"Mahogany",   20),
        Mat(L"Bronze",     60),
        Mat(L"Lead",       80),
        Mat(L"Spiky Silk", 50),
        Mat(L"Black Silk", 60),
        Mat(L"Copper",    200),
        Mat(L"Lubricant",  10),
        Tool(L"Anvil",      1),
        Tool(L"Hammer",     1),
        Tool(L"Gimlet",     1),
        Tool(L"Sawdust",    1),
        });
    AddRecipe(L"Heart Gun", {
        Mat(L"Titanium",  140),
        Mat(L"Aramid",    160),
        Mat(L"Mahogany",   30),
        Mat(L"Bronze",    110),
        Mat(L"Lead",      130),
        Mat(L"Spiky Silk",100),
        Mat(L"Black Silk",110),
        Mat(L"Copper",    250),
        Mat(L"Lubricant",  20),
        Tool(L"Anvil",      1),
        Tool(L"Hammer",     1),
        Tool(L"Gimlet",     1),
        Tool(L"Sawdust",    1),
        });
    AddRecipe(L"Paladin Golden Scope Gun", {
        Mat(L"Titanium",  200),
        Mat(L"Aramid",     60),
        Mat(L"Mahogany",  160),
        Mat(L"Bronze",    140),
        Mat(L"Lead",      160),
        Mat(L"Spiky Silk",120),
        Mat(L"Sulfur",    140),
        Mat(L"Brass",     100),
        Mat(L"Coal",      270),
        Mat(L"Lubricant",  35),
        Tool(L"Anvil",      1),
        Tool(L"Hammer",     1),
        Tool(L"Gimlet",     1),
        Tool(L"Sawdust",    1),
        });
}