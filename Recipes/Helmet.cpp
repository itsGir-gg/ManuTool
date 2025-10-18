#include "RecipeModel.h"
#include "RecipeModules.h"

using RecipesDB::Mat;
using RecipesDB::Sub;
using RecipesDB::Tool;
using RecipesDB::AddRecipe;

using namespace recipes;

void recipes::RegisterHelmetRecipes() {
    AddRecipe(L"Weak Leather Helmet", {
        Mat(L"Cowhide", 3),
        Mat(L"Iron Ore", 2),
        });
    AddRecipe(L"Strong Leather Helmet", {
        Mat(L"Cowhide", 5),
        Mat(L"Iron Ore", 4),
        });
    AddRecipe(L"Wooden Helmet", {
        Mat(L"Oak", 15),
        Mat(L"Steel", 2),
        Mat(L"Coal", 10),
        Mat(L"Gold Ore", 3),
        });
    AddRecipe(L"Bone Helmet", {
        Mat(L"Cowhide", 7),
        Mat(L"Gold Bar", 2),
        Mat(L"Coal", 20),
        Mat(L"Animal Bones", 50),
        });
    AddRecipe(L"Bronze Helmet", {
        Mat(L"Cowhide", 10),
        Mat(L"Silk", 5),
        Mat(L"Gold Bar", 4),
        Mat(L"Steel", 5),
        Mat(L"Coal", 20),
        Mat(L"Copper", 20),
        Tool(L"Needle", 1),
        });
    AddRecipe(L"Iron Helmet", {
        Mat(L"Cowhide", 15),
        Mat(L"Silk", 10),
        Mat(L"Gold Bar", 4),
        Mat(L"Silver Bar", 1),
        Mat(L"Steel", 8),
        Mat(L"Coal", 20),
        Mat(L"Copper", 5),
        Mat(L"Leather Protector", 1),
        Tool(L"Needle", 1),
        });
    AddRecipe(L"Moonlight Helmet", {
        Mat(L"Cowhide", 15),
        Mat(L"Silk", 10),
        Mat(L"Gold Bar", 5),
        Mat(L"Silver Bar", 3),
        Mat(L"Steel", 15),
        Mat(L"Coal", 20),
        Mat(L"Copper", 10),
        Mat(L"Leather Protector", 3),
        Tool(L"Needle", 1),
        Tool(L"Scissor", 1),
        });
    AddRecipe(L"Metal Helmet", {
        Sub(L"Iron Helmet", 1),
        Mat(L"Cowhide", 20),
        Mat(L"Silk", 15),
        Mat(L"Gold Bar", 6),
        Mat(L"Silver Bar", 4),
        Mat(L"Steel",25),
        Mat(L"Coal", 30),
        Mat(L"Jade", 10),
        Mat(L"Copper", 15),
        Mat(L"Leather Protector", 7),
        Tool(L"Needle", 1),
        Tool(L"Scissor", 1),
        });
    AddRecipe(L"Taebaek Helmet", {
        Sub(L"Moonlight Helmet", 1),
        Mat(L"Cowhide", 20),
        Mat(L"Silk", 15),
        Mat(L"Gold Bar", 7),
        Mat(L"Silver Bar", 5),
        Mat(L"Steel",40),
        Mat(L"Coal", 30),
        Mat(L"Jade", 10),
        Mat(L"Copper", 20),
        Mat(L"Leather Protector", 10),
        Tool(L"Needle", 1),
        Tool(L"Scissor", 1),
        });
    AddRecipe(L"White Plate Helm", {
        Sub(L"Metal Helmet", 1),
        Mat(L"Cowhide", 30),
        Mat(L"Silk", 30),
        Mat(L"Gold Bar", 10),
        Mat(L"Silver Bar", 10),
        Mat(L"Steel",70),
        Mat(L"Coal", 35),
        Mat(L"Jade", 30),
        Mat(L"Copper", 30),
        Mat(L"Leather Protector", 12),
        Tool(L"Needle", 1),
        Tool(L"Scissor", 1),
        });
    AddRecipe(L"Black Head Guard", {
        Sub(L"Taebaek Helmet", 1),
        Mat(L"Cowhide", 30),
        Mat(L"Silk", 30),
        Mat(L"Gold Bar", 10),
        Mat(L"Silver Bar", 10),
        Mat(L"Steel",80),
        Mat(L"Coal", 35),
        Mat(L"Jade", 40),
        Mat(L"Copper", 40),
        Mat(L"Leather Protector", 15),
        Tool(L"Needle", 1),
        Tool(L"Scissor", 1),
        Tool(L"Saw", 1),
        });
    AddRecipe(L"Frozen Helmet", {
        Sub(L"White Plate Helm", 1),
        Mat(L"Cowhide", 35),
        Mat(L"Silk", 35),
        Mat(L"Gold Bar", 30),
        Mat(L"Silver Bar", 60),
        Mat(L"Steel",90),
        Mat(L"Coal", 60),
        Mat(L"Jade", 50),
        Mat(L"Copper", 40),
        Mat(L"Leather Protector", 20),
        Tool(L"Needle", 1),
        Tool(L"Scissor", 1),
        Tool(L"Saw", 1),
        });
    AddRecipe(L"Flame Helmet", {
        Sub(L"Black Head Guard", 1),
        Mat(L"Cowhide", 35),
        Mat(L"Silk", 35),
        Mat(L"Gold Bar", 40),
        Mat(L"Silver Bar", 60),
        Mat(L"Steel",130),
        Mat(L"Coal", 70),
        Mat(L"Jade", 50),
        Mat(L"Copper", 90),
        Mat(L"Leather Protector", 20),
        Tool(L"Needle", 1),
        Tool(L"Scissor", 1),
        Tool(L"Saw", 1),
        Tool(L"Flat Iron", 1),
        });
    AddRecipe(L"Dragon Knight Helmet", {
        Mat(L"Titanium",  120),
        Mat(L"Aramid",     80),
        Mat(L"Mahogany",  100),
        Mat(L"Bronze",     50),
        Mat(L"Lead",       30),
        Mat(L"Spiky Accessory", 50),
        Mat(L"Spiky Silk", 40),
        Mat(L"Black Silk", 80),
        Mat(L"Steel",    200),
        Mat(L"Leather Protector",  10),
        Tool(L"Needle", 1),
        Tool(L"Scissor", 1),
        Tool(L"Saw", 1),
        Tool(L"Flat Iron", 1),
        });
    AddRecipe(L"Abel Knight Helmet", {
        Mat(L"Titanium",  130),
        Mat(L"Aramid",     90),
        Mat(L"Mahogany",  110),
        Mat(L"Bronze",    100),
        Mat(L"Lead",       80),
        Mat(L"Spiky Accessory", 80),
        Mat(L"Spiky Silk", 90),
        Mat(L"Black Silk",130),
        Mat(L"Steel",    250),
        Mat(L"Leather Protector",  20),
        Tool(L"Needle", 1),
        Tool(L"Scissor", 1),
        Tool(L"Saw", 1),
        Tool(L"Flat Iron", 1),
        });
    AddRecipe(L"Vampire Helmet", {
        Mat(L"Black Stone", 80),
        Mat(L"Blessing Stone", 25),
        Mat(L"Steel",  120),
        Mat(L"Coal",   120),
        Mat(L"Gold Bar", 50),
        Mat(L"Silver Bar", 50),
        Mat(L"Cowhide", 150),
        Mat(L"Silk", 80),
        Mat(L"Jade", 60),
        Mat(L"Leather Protector",  60),
        Tool(L"Needle", 1),
        Tool(L"Scissor", 1),
        Tool(L"Saw", 1),
        Tool(L"Flat Iron", 1),
        });
    AddRecipe(L"Cuirassier Helmet", {
        Mat(L"Blue Thread", 80),
        Mat(L"Ruby", 80),
        Mat(L"Steel",  120),
        Mat(L"Coal",   120),
        Mat(L"Gold Bar", 50),
        Mat(L"Silver Bar", 50),
        Mat(L"Cowhide", 150),
        Mat(L"Silk", 80),
        Mat(L"Jade", 60),
        Mat(L"Leather Protector",  60),
        Tool(L"Needle", 1),
        Tool(L"Scissor", 1),
        Tool(L"Saw", 1),
        Tool(L"Flat Iron", 1),
        });
}