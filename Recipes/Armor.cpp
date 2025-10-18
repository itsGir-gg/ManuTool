#include "RecipeModel.h"
#include "RecipeModules.h"

using RecipesDB::Mat;
using RecipesDB::Sub;
using RecipesDB::Tool;
using RecipesDB::AddRecipe;

using namespace recipes;

void recipes::RegisterArmorRecipes() {
    AddRecipe(L"Weak Leather Armor", {
        Mat(L"Cowhide", 3),
        Mat(L"Coal", 1),
        Mat(L"Iron Ore", 3),
        });
    AddRecipe(L"Strong Leather Armor", {
        Mat(L"Cowhide", 5),
        Mat(L"Coal", 5),
        Mat(L"Iron Ore", 5),
        });
    AddRecipe(L"Wooden Armor", {
        Mat(L"Oak", 15),
        Mat(L"Steel", 3),
        Mat(L"Coal", 10),
        Mat(L"Gold Ore", 3),
        });
    AddRecipe(L"Bone Armor", {
        Mat(L"Cowhide", 15),
        Mat(L"Gold Bar", 2),
        Mat(L"Steel", 1),
        Mat(L"Coal", 20),
        Mat(L"Animal Bones", 60),
        });
    AddRecipe(L"Bronze Armor", {
        Mat(L"Cowhide", 15),
        Mat(L"Gold Bar", 2),
        Mat(L"Steel", 4),
        Mat(L"Coal", 20),
        Mat(L"Copper", 20),
        Tool(L"Needle", 1),
        });
    AddRecipe(L"Iron Armor", {
        Mat(L"Cowhide", 25),
        Mat(L"Silk", 10),
        Mat(L"Gold Bar", 3),
        Mat(L"Silver Bar", 2),
        Mat(L"Steel", 10),
        Mat(L"Coal", 25),
        Mat(L"Jade", 5),
        Mat(L"Copper", 25),
        Mat(L"Leather Protector", 1),
        Tool(L"Needle", 1),
        });
    AddRecipe(L"Moonlight Armor", {
        Mat(L"Cowhide", 25),
        Mat(L"Silk", 10),
        Mat(L"Gold Bar", 3),
        Mat(L"Silver Bar", 2),
        Mat(L"Steel", 20),
        Mat(L"Coal", 25),
        Mat(L"Jade",7),
        Mat(L"Copper", 30),
        Mat(L"Leather Protector", 3),
        Tool(L"Needle", 1),
        Tool(L"Scissor", 1),
        });
    AddRecipe(L"Metal Armor", {
        Sub(L"Iron Armor", 1),
        Mat(L"Cowhide", 30),
        Mat(L"Silk", 20),
        Mat(L"Gold Bar", 5),
        Mat(L"Silver Bar", 4),
        Mat(L"Steel",30),
        Mat(L"Coal", 30),
        Mat(L"Jade", 10),
        Mat(L"Copper", 40),
        Mat(L"Leather Protector", 7),
        Tool(L"Needle", 1),
        Tool(L"Scissor", 1),
        });
    AddRecipe(L"Taebaek Armor", {
        Sub(L"Moonlight Armor", 1),
        Mat(L"Cowhide", 30),
        Mat(L"Silk", 20),
        Mat(L"Gold Bar", 5),
        Mat(L"Silver Bar", 4),
        Mat(L"Steel",50),
        Mat(L"Coal", 30),
        Mat(L"Jade", 10),
        Mat(L"Copper", 40),
        Mat(L"Leather Protector", 10),
        Tool(L"Needle", 1),
        Tool(L"Scissor", 1),
        });
    AddRecipe(L"White Plate Armor", {
        Sub(L"Metal Armor", 1),
        Mat(L"Cowhide", 30),
        Mat(L"Silk", 30),
        Mat(L"Gold Bar", 10),
        Mat(L"Silver Bar", 10),
        Mat(L"Steel",70),
        Mat(L"Coal", 35),
        Mat(L"Jade", 30),
        Mat(L"Copper", 45),
        Mat(L"Leather Protector", 12),
        Tool(L"Needle", 1),
        Tool(L"Scissor", 1),
        });
    AddRecipe(L"Black Carabinieer Armor", {
        Sub(L"Taebaek Armor", 1),
        Mat(L"Cowhide", 30),
        Mat(L"Silk", 30),
        Mat(L"Gold Bar", 10),
        Mat(L"Silver Bar", 10),
        Mat(L"Steel",80),
        Mat(L"Coal", 35),
        Mat(L"Jade", 30),
        Mat(L"Copper", 50),
        Mat(L"Leather Protector", 15),
        Tool(L"Needle", 1),
        Tool(L"Scissor", 1),
        Tool(L"Saw", 1),
        });
    AddRecipe(L"Frozen Armor", {
        Sub(L"White Plate Armor", 1),
        Mat(L"Cowhide", 40),
        Mat(L"Silk", 40),
        Mat(L"Gold Bar", 40),
        Mat(L"Silver Bar", 60),
        Mat(L"Steel",90),
        Mat(L"Coal", 40),
        Mat(L"Jade", 50),
        Mat(L"Copper", 60),
        Mat(L"Leather Protector", 20),
        Tool(L"Needle", 1),
        Tool(L"Scissor", 1),
        Tool(L"Saw", 1),
        });
    AddRecipe(L"Flame Armor", {
        Sub(L"Black Carabinieer Armor", 1),
        Mat(L"Cowhide", 40),
        Mat(L"Silk", 40),
        Mat(L"Gold Bar", 80),
        Mat(L"Silver Bar", 60),
        Mat(L"Steel",150),
        Mat(L"Coal", 60),
        Mat(L"Jade", 50),
        Mat(L"Copper", 100),
        Mat(L"Leather Protector", 20),
        Tool(L"Needle", 1),
        Tool(L"Scissor", 1),
        Tool(L"Saw", 1),
        Tool(L"Flat Iron", 1),
        });
    AddRecipe(L"Dragon Knight Armor", {
        Mat(L"Titanium",  160),
        Mat(L"Aramid",     60),
        Mat(L"Mahogany",   80),
        Mat(L"Bronze",     30),
        Mat(L"Lead",       50),
        Mat(L"Spiky Accessory", 50),
        Mat(L"Spiky Silk", 80),
        Mat(L"Black Silk", 40),
        Mat(L"Steel",    200),
        Mat(L"Leather Protector",  10),
        Tool(L"Needle", 1),
        Tool(L"Scissor", 1),
        Tool(L"Saw", 1),
        Tool(L"Flat Iron", 1),
        });
    AddRecipe(L"Abel Knight Armor", {
        Mat(L"Titanium",  170),
        Mat(L"Aramid",     70),
        Mat(L"Mahogany",   90),
        Mat(L"Bronze",     80),
        Mat(L"Lead",      100),
        Mat(L"Spiky Accessory", 80),
        Mat(L"Spiky Silk", 130),
        Mat(L"Black Silk",90),
        Mat(L"Steel",    250),
        Mat(L"Leather Protector",  20),
        Tool(L"Needle", 1),
        Tool(L"Scissor", 1),
        Tool(L"Saw", 1),
        Tool(L"Flat Iron", 1),
        });
    AddRecipe(L"Dark Knight's Armor", {
        Mat(L"Cobalt",  300),
        Mat(L"Dinosaur Leather", 120),
        Mat(L"Titanium", 180),
        Mat(L"Mahogany", 100),
        Mat(L"Bronze",     70),
        Mat(L"Spiky Accessory", 100),
        Mat(L"Lead",80),
        Mat(L"Spiky Silk", 130),
        Mat(L"Steel",    300),
        Mat(L"Leather Protector",  50),
        Tool(L"Needle", 1),
        Tool(L"Scissor", 1),
        Tool(L"Saw", 1),
        Tool(L"Flat Iron", 1),
        });
    AddRecipe(L"Vampire Armor", {
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
    AddRecipe(L"Cuirassier Armor", {
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