#include "RecipeModel.h"
#include "RecipeModules.h"

using RecipesDB::Mat;
using RecipesDB::Sub;
using RecipesDB::Tool;
using RecipesDB::AddRecipe;

using namespace recipes;

void recipes::RegisterSpearRecipes() {
    AddRecipe(L"Bamboo Spear", {
        Mat(L"Bamboo", 10),
        });
    AddRecipe(L"Apprentice Spear", {
        Mat(L"Oak", 3),
        Mat(L"Cowhide", 3),
        Mat(L"Silk", 2),
        Mat(L"Copper", 4),
        });
    AddRecipe(L"Half-moon Spear", {
        Mat(L"Oak", 5),
        Mat(L"Cowhide", 4),
        Mat(L"Silk", 3),
        Mat(L"Coal", 1),
        Mat(L"Copper", 9),
        Mat(L"Iron Ore", 4),
        });
    AddRecipe(L"Moon Spear", {
        Mat(L"Oak", 10),
        Mat(L"Cowhide", 4),
        Mat(L"Silk", 4),
        Mat(L"Gold Bar", 2),
        Mat(L"Silver Bar", 1),
        Mat(L"Iron", 3),
        Mat(L"Coal", 3),
        Mat(L"Copper", 12),
        });
    AddRecipe(L"Dragon Spear", {
        Mat(L"Oak", 15),
        Mat(L"Cowhide", 6),
        Mat(L"Silk", 8),
        Mat(L"Gold Bar", 3),
        Mat(L"Silver Bar", 2),
        Mat(L"Iron", 4),
        Mat(L"Coal", 5),
        Mat(L"Copper", 20),
        Tool(L"Anvil", 1),
        });
    AddRecipe(L"Barchha", {
        Mat(L"Oak", 20),
        Mat(L"Cowhide", 6),
        Mat(L"Silk", 8),
        Mat(L"Gold Bar", 7),
        Mat(L"Silver Bar", 7),
        Mat(L"Iron", 5),
        Mat(L"Copper", 20),
        Mat(L"Amber", 2),
        Tool(L"Anvil", 1),
        });
    AddRecipe(L"Iron-fist", {
        Mat(L"Charcoal", 5),
        Mat(L"Cowhide", 9),
        Mat(L"Silk", 12),
        Mat(L"Gold Bar", 10),
        Mat(L"Silver Bar", 10),
        Mat(L"Iron", 7),
        Mat(L"Coal", 20),
        Mat(L"Copper", 25),
        Mat(L"Amber", 5),
        Tool(L"Anvil", 1),
        });
    AddRecipe(L"Wing Spear", {
        Sub(L"Barchha", 1),
        Mat(L"Oak", 30),
        Mat(L"Cowhide", 9),
        Mat(L"Silk", 12),
        Mat(L"Gold Bar", 10),
        Mat(L"Silver Bar", 10),
        Mat(L"Iron", 7),
        Mat(L"Copper", 25),
        Mat(L"Amber", 7),
        Mat(L"Polisher", 1),
        Tool(L"Anvil", 1),
        });
    AddRecipe(L"Grand Scythe", {
        Sub(L"Iron-fist", 1),
        Mat(L"Charcoal", 9),
        Mat(L"Cowhide", 15),
        Mat(L"Silk", 15),
        Mat(L"Gold Bar", 10),
        Mat(L"Silver Bar", 10),
        Mat(L"Iron", 10),
        Mat(L"Coal", 12),
        Mat(L"Amber", 10),
        Mat(L"Polisher", 3),
        Tool(L"Anvil", 1),
        Tool(L"Hammer", 1),
        });
    AddRecipe(L"Scorpion", {
        Sub(L"Wing Spear", 1),
        Mat(L"Oak", 50),
        Mat(L"Cowhide", 16),
        Mat(L"Silk", 19),
        Mat(L"Gold Bar", 15),
        Mat(L"Silver Bar", 15),
        Mat(L"Iron", 13),
        Mat(L"Copper", 30),
        Mat(L"Amber", 12),
        Mat(L"Polisher", 5),
        Tool(L"Anvil", 1),
        Tool(L"Hammer", 1),
        });
    AddRecipe(L"Moon Spirit Spear", {
        Sub(L"Grand Scythe", 1),
        Mat(L"Charcoal", 11),
        Mat(L"Cowhide", 20),
        Mat(L"Silk", 20),
        Mat(L"Gold Bar", 15),
        Mat(L"Silver Bar", 15),
        Mat(L"Iron", 15),
        Mat(L"Coal", 15),
        Mat(L"Amber", 15),
        Mat(L"Polisher", 7),
        Tool(L"Anvil", 1),
        Tool(L"Hammer", 1),
        Tool(L"Saw", 1),
        });
    AddRecipe(L"Grand Screw Spear", {
        Sub(L"Scorpion", 1),
        Mat(L"Oak", 60),
        Mat(L"Cowhide", 21),
        Mat(L"Silk", 25),
        Mat(L"Gold Bar", 25),
        Mat(L"Silver Bar", 25),
        Mat(L"Iron", 25),
        Mat(L"Copper", 40),
        Mat(L"Amber", 20),
        Mat(L"Polisher", 10),
        Tool(L"Anvil", 1),
        Tool(L"Hammer", 1),
        Tool(L"Saw", 1),
        });
    AddRecipe(L"Bardiche", {
        Sub(L"Moon Spirit Spear", 1),
        Mat(L"Charcoal", 13),
        Mat(L"Cowhide", 27),
        Mat(L"Silk", 27),
        Mat(L"Gold Bar", 30),
        Mat(L"Silver Bar", 30),
        Mat(L"Iron", 27),
        Mat(L"Coal", 18),
        Mat(L"Amber", 22),
        Mat(L"Polisher", 12),
        Tool(L"Anvil", 1),
        Tool(L"Hammer", 1),
        Tool(L"Saw", 1),
        });
    AddRecipe(L"Halberd", {
        Sub(L"Grand Screw Spear", 1),
        Mat(L"Oak", 70),
        Mat(L"Cowhide", 40),
        Mat(L"Silk", 40),
        Mat(L"Gold Bar", 40),
        Mat(L"Silver Bar", 40),
        Mat(L"Iron", 37),
        Mat(L"Copper", 60),
        Mat(L"Amber", 60),
        Mat(L"Polisher", 18),
        Tool(L"Anvil", 1),
        Tool(L"Hammer", 1),
        Tool(L"Saw", 1),
        Tool(L"Sawdust", 1),
        });
    AddRecipe(L"Lightning Spear", {
        Sub(L"Bardiche", 1),
        Mat(L"Charcoal", 20),
        Mat(L"Cowhide", 40),
        Mat(L"Silk", 40),
        Mat(L"Gold Bar", 45),
        Mat(L"Silver Bar", 45),
        Mat(L"Iron", 37),
        Mat(L"Coal", 30),
        Mat(L"Amber", 60),
        Mat(L"Polisher", 20),
        Tool(L"Anvil", 1),
        Tool(L"Hammer", 1),
        Tool(L"Saw", 1),
        Tool(L"Sawdust", 1),
        });
    AddRecipe(L"Holy Lance", {
        Mat(L"Titanium",  100),
        Mat(L"Aramid",    120),
        Mat(L"Mahogany",   80),
        Mat(L"Bronze",     80),
        Mat(L"Lead",      100),
        Mat(L"Spiky Silk", 40),
        Mat(L"Black Silk", 30),
        Mat(L"Amber",     200),
        Mat(L"Polisher",   10),
        Tool(L"Anvil", 1),
        Tool(L"Hammer", 1),
        Tool(L"Saw", 1),
        Tool(L"Sawdust", 1),
        });
    AddRecipe(L"Unisus Spear", {
        Mat(L"Titanium",  110),
        Mat(L"Aramid",    130),
        Mat(L"Mahogany",   90),
        Mat(L"Bronze",    130),
        Mat(L"Lead",      150),
        Mat(L"Spiky Silk", 90),
        Mat(L"Black Silk", 80),
        Mat(L"Amber",     250),
        Mat(L"Polisher",   20),
        Tool(L"Anvil", 1),
        Tool(L"Hammer", 1),
        Tool(L"Saw", 1),
        Tool(L"Sawdust", 1),
        });
    AddRecipe(L"Paladin Cross Spear", {
        Mat(L"Titanium",  140),
        Mat(L"Aramid",    120),
        Mat(L"Mahogany",  160),
        Mat(L"Lead",      140),
        Mat(L"Black Silk",170),
        Mat(L"Spiky Silk",110),
        Mat(L"Animal Bones", 140),
        Mat(L"Charcoal", 100),
        Mat(L"Amber",     270),
        Mat(L"Polisher",   35),
        Tool(L"Anvil", 1),
        Tool(L"Hammer", 1),
        Tool(L"Saw", 1),
        Tool(L"Sawdust", 1),
        });
}