#include "RecipeModel.h"
#include "RecipeModules.h"

using RecipesDB::Mat;
using RecipesDB::Sub;
using RecipesDB::Tool;
using RecipesDB::AddRecipe;

using namespace recipes;

void recipes::RegisterAxeRecipes() {
    AddRecipe(L"Stone Axe", {
        Mat(L"Oak", 1),
        Mat(L"Clay-slate Stone", 10),
        });
    AddRecipe(L"Bronze Axe", {
        Mat(L"Oak", 3),
        Mat(L"Coal", 1),
        Mat(L"Clay-slate Stone", 20),
        Mat(L"Gold Ore", 2),
        });
    AddRecipe(L"Steel Axe", {
        Mat(L"Oak", 5),
        Mat(L"Coal", 2),
        Mat(L"Copper", 5),
        Mat(L"Clay-slate Stone", 30),
        Mat(L"Gold Ore", 3),
        Mat(L"Iron Ore", 3),
        });
    AddRecipe(L"Silver Axe", {
        Mat(L"Oak", 9),
        Mat(L"Gold Bar", 1),
        Mat(L"Silver Bar", 2),
        Mat(L"Iron", 1),
        Mat(L"Coal", 3),
        Mat(L"Copper", 10),
        Mat(L"Clay-slate Stone", 35),
        });
    AddRecipe(L"Golden Axe", {
        Mat(L"Oak", 13),
        Mat(L"Gold Bar", 2),
        Mat(L"Silver Bar", 2),
        Mat(L"Iron", 2),
        Mat(L"Coal", 5),
        Mat(L"Copper", 20),
        Mat(L"Clay-slate Stone", 40),
        Tool(L"Anvil", 1),
        });
    AddRecipe(L"Morningstar", {
        Mat(L"Gold Bar", 2),
        Mat(L"Silver Bar", 2),
        Mat(L"Iron", 8),
        Mat(L"Coal", 13),
        Mat(L"Copper", 25),
        Mat(L"Jade", 5),
        Mat(L"Clay-slate Stone", 40),
        Mat(L"Coral", 5),
        Tool(L"Anvil", 1),
        });
    AddRecipe(L"Battle Axe", {
        Mat(L"Charcoal", 10),
        Mat(L"Gold Bar", 3),
        Mat(L"Silver Bar", 3),
        Mat(L"Iron", 12),
        Mat(L"Copper", 30),
        Mat(L"Jade", 7),
        Mat(L"Clay-slate Stone", 40),
        Mat(L"Coral", 10),
        Tool(L"Anvil", 1),
        });
    AddRecipe(L"Golden Hammer", {
        Sub(L"Morningstar", 1),
        Mat(L"Gold Bar", 4),
        Mat(L"Silver Bar", 4),
        Mat(L"Iron", 16),
        Mat(L"Coal", 21),
        Mat(L"Copper", 35),
        Mat(L"Jade", 9),
        Mat(L"Clay-slate Stone", 45),
        Mat(L"Coral", 15),
        Mat(L"Polisher", 1),
        Tool(L"Anvil", 1),
        Tool(L"Hammer", 1),
        });
    AddRecipe(L"Great Silver Axe", {
        Sub(L"Battle Axe", 1),
        Mat(L"Charcoal", 20),
        Mat(L"Gold Bar", 5),
        Mat(L"Silver Bar", 5),
        Mat(L"Iron", 20),
        Mat(L"Copper", 40),
        Mat(L"Jade", 10),
        Mat(L"Clay-slate Stone", 47),
        Mat(L"Coral", 20),
        Mat(L"Polisher", 3),
        Tool(L"Anvil", 1),
        Tool(L"Hammer", 1),
        });
    AddRecipe(L"War Hammer", {
        Sub(L"Golden Hammer", 1),
        Mat(L"Gold Bar", 6),
        Mat(L"Silver Bar", 6),
        Mat(L"Iron", 24),
        Mat(L"Coal", 29),
        Mat(L"Copper", 45),
        Mat(L"Jade", 13),
        Mat(L"Clay-slate Stone", 50),
        Mat(L"Coral", 25),
        Mat(L"Polisher", 5),
        Tool(L"Anvil", 1),
        Tool(L"Hammer", 1),
        });
    AddRecipe(L"Great Golden Axe", {
        Sub(L"Great Silver Axe", 1),
        Mat(L"Charcoal", 30),
        Mat(L"Gold Bar", 7),
        Mat(L"Silver Bar", 7),
        Mat(L"Iron", 28),
        Mat(L"Copper", 50),
        Mat(L"Jade", 15),
        Mat(L"Clay-slate Stone", 50),
        Mat(L"Coral", 30),
        Mat(L"Polisher", 7),
        Tool(L"Anvil", 1),
        Tool(L"Hammer", 1),
        Tool(L"Saw", 1),
        });
    AddRecipe(L"Angel's Axe", {
        Sub(L"War Hammer", 1),
        Mat(L"Gold Bar", 8),
        Mat(L"Silver Bar", 8),
        Mat(L"Iron", 32),
        Mat(L"Coal", 37),
        Mat(L"Copper", 55),
        Mat(L"Jade", 19),
        Mat(L"Clay-slate Stone", 53),
        Mat(L"Coral", 40),
        Mat(L"Polisher", 10),
        Tool(L"Anvil", 1),
        Tool(L"Hammer", 1),
        Tool(L"Saw", 1),
        });
    AddRecipe(L"Taebaek Axe", {
        Sub(L"Great Golden Axe", 1),
        Mat(L"Charcoal", 40),
        Mat(L"Gold Bar", 9),
        Mat(L"Silver Bar", 9),
        Mat(L"Iron", 36),
        Mat(L"Copper", 60),
        Mat(L"Jade", 20),
        Mat(L"Clay-slate Stone", 57),
        Mat(L"Coral", 45),
        Mat(L"Polisher", 12),
        Tool(L"Anvil", 1),
        Tool(L"Hammer", 1),
        Tool(L"Saw", 1),
        });
    AddRecipe(L"Iron Soul", {
        Sub(L"Angel's Axe", 1),
        Mat(L"Gold Bar", 15),
        Mat(L"Silver Bar", 15),
        Mat(L"Iron", 60),
        Mat(L"Coal", 65),
        Mat(L"Copper", 60),
        Mat(L"Jade", 30),
        Mat(L"Clay-slate Stone", 65),
        Mat(L"Coral", 55),
        Mat(L"Polisher", 18),
        Tool(L"Anvil", 1),
        Tool(L"Hammer", 1),
        Tool(L"Saw", 1),
        Tool(L"Sawdust", 1),
        });
    AddRecipe(L"Spirit Axe", {
        Sub(L"Taebaek Axe", 1),
        Mat(L"Charcoal", 50),
        Mat(L"Gold Bar", 20),
        Mat(L"Silver Bar", 20),
        Mat(L"Iron", 60),
        Mat(L"Copper", 60),
        Mat(L"Jade", 30),
        Mat(L"Clay-slate Stone", 70),
        Mat(L"Coral", 60),
        Mat(L"Polisher", 20),
        Tool(L"Anvil", 1),
        Tool(L"Hammer", 1),
        Tool(L"Saw", 1),
        Tool(L"Sawdust", 1),
        });
    AddRecipe(L"Earthquaker", {
        Mat(L"Titanium",  180),
        Mat(L"Aramid",     30),
        Mat(L"Mahogany",   90),
        Mat(L"Bronze",    110),
        Mat(L"Lead",      110),
        Mat(L"Spiky Silk", 10),
        Mat(L"Black Silk", 20),
        Mat(L"Coral",     200),
        Mat(L"Polisher",   10),
        Tool(L"Anvil", 1),
        Tool(L"Hammer", 1),
        Tool(L"Saw", 1),
        Tool(L"Sawdust", 1),
        });
    AddRecipe(L"Red Moon Axe", {
        Mat(L"Titanium",  190),
        Mat(L"Aramid",     40),
        Mat(L"Mahogany",  100),
        Mat(L"Bronze",    160),
        Mat(L"Lead",      160),
        Mat(L"Spiky Silk", 60),
        Mat(L"Black Silk", 70),
        Mat(L"Coral",     250),
        Mat(L"Polisher",   20),
        Tool(L"Anvil", 1),
        Tool(L"Hammer", 1),
        Tool(L"Saw", 1),
        Tool(L"Sawdust", 1),
        });
    AddRecipe(L"Paladin Golden Axe", {
        Mat(L"Titanium",  230),
        Mat(L"Aramid",     60),
        Mat(L"Mahogany",  130),
        Mat(L"Bronze",    170),
        Mat(L"Lead",      170),
        Mat(L"Black Silk", 80),
        Mat(L"Embroidered Thread Bobbin", 80),
        Mat(L"Coral",     270),
        Mat(L"Polisher",   35),
        Tool(L"Anvil", 1),
        Tool(L"Hammer", 1),
        Tool(L"Saw", 1),
        Tool(L"Sawdust", 1),
        });
}