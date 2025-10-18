#include "RecipeModel.h"
#include "RecipeModules.h"

using RecipesDB::Mat;
using RecipesDB::Sub;
using RecipesDB::Tool;
using RecipesDB::AddRecipe;

using namespace recipes;

void recipes::RegisterBeltRecipes() {
    AddRecipe(L"Weak Leather Belt", {
        Mat(L"Cowhide", 5),
        Mat(L"Steel", 1),
        });
    AddRecipe(L"Strong Leather Belt", {
        Mat(L"Cowhide", 5),
        Mat(L"Steel", 2),
        });
    AddRecipe(L"Wooden Belt", {
        Mat(L"Oak", 25),
        Mat(L"Steel", 4),
        Mat(L"Coal", 10),
        });
    AddRecipe(L"Bone Belt", {
        Mat(L"Cowhide", 15),
        Mat(L"Gold Bar", 1),
        Mat(L"Coal", 15),
        Mat(L"Animal Bones", 50),
        });
    AddRecipe(L"Bronze Belt", {
        Sub(L"Wooden Belt", 1),
        Mat(L"Cowhide", 15),
        Mat(L"Gold Bar", 2),
        Mat(L"Silver Bar", 2),
        Mat(L"Steel", 10),
        Mat(L"Coal", 15),
        Mat(L"Jade", 3),
        Mat(L"Copper", 15),
        Mat(L"Bleach", 1),
        Tool(L"Needle", 1),
        });
    AddRecipe(L"Heavy Metal Belt", {
        Sub(L"Bone Belt", 1),
        Mat(L"Cowhide", 20),
        Mat(L"Silk", 5),
        Mat(L"Gold Bar", 4),
        Mat(L"Silver Bar", 4),
        Mat(L"Steel", 20),
        Mat(L"Coal", 20),
        Mat(L"Jade", 5),
        Mat(L"Copper", 30),
        Mat(L"Bleach", 3),
        Tool(L"Needle", 1),
        });
    AddRecipe(L"Moonshine Belt", {
        Sub(L"Bronze Belt", 1),
        Mat(L"Cowhide", 20),
        Mat(L"Silk", 6),
        Mat(L"Gold Bar", 6),
        Mat(L"Silver Bar", 4),
        Mat(L"Steel", 22),
        Mat(L"Coal", 20),
        Mat(L"Jade", 8),
        Mat(L"Copper", 35),
        Mat(L"Bleach", 4),
        Tool(L"Needle", 1),
        });
    AddRecipe(L"Sturdy Metal Belt", {
        Sub(L"Heavy Metal Belt", 1),
        Mat(L"Cowhide", 23),
        Mat(L"Silk", 8),
        Mat(L"Gold Bar", 8),
        Mat(L"Silver Bar", 6),
        Mat(L"Steel", 25),
        Mat(L"Coal", 23),
        Mat(L"Jade", 12),
        Mat(L"Copper", 40),
        Mat(L"Bleach", 5),
        Tool(L"Needle", 1),
        Tool(L"Scissor", 1),
        });
    AddRecipe(L"Taebaek Belt", {
        Sub(L"Moonshine Belt", 1),
        Mat(L"Cowhide", 25),
        Mat(L"Silk", 10),
        Mat(L"Gold Bar", 10),
        Mat(L"Silver Bar", 8),
        Mat(L"Steel", 30),
        Mat(L"Coal", 25),
        Mat(L"Jade", 15),
        Mat(L"Copper", 45),
        Mat(L"Bleach", 7),
        Tool(L"Needle", 1),
        Tool(L"Scissor", 1),
        });
    AddRecipe(L"Comet Belt", {
        Sub(L"Sturdy Metal Belt", 1),
        Mat(L"Cowhide", 30),
        Mat(L"Silk", 20),
        Mat(L"Gold Bar", 25),
        Mat(L"Silver Bar", 25),
        Mat(L"Steel", 50),
        Mat(L"Coal", 50),
        Mat(L"Jade", 30),
        Mat(L"Copper", 60),
        Mat(L"Bleach", 10),
        Tool(L"Needle", 1),
        Tool(L"Scissor", 1),
        });
    AddRecipe(L"Black Plate Belt", {
        Sub(L"Taebaek Belt", 1),
        Mat(L"Cowhide", 40),
        Mat(L"Silk", 30),
        Mat(L"Gold Bar", 35),
        Mat(L"Silver Bar", 40),
        Mat(L"Steel", 55),
        Mat(L"Coal", 60),
        Mat(L"Jade", 40),
        Mat(L"Copper", 70),
        Mat(L"Bleach", 11),
        Tool(L"Needle", 1),
        Tool(L"Scissor", 1),
        });
    AddRecipe(L"Frozen Belt", {
        Sub(L"Comet Belt", 1),
        Mat(L"Cowhide", 50),
        Mat(L"Silk", 40),
        Mat(L"Gold Bar", 50),
        Mat(L"Silver Bar", 70),
        Mat(L"Steel", 70),
        Mat(L"Coal", 60),
        Mat(L"Jade", 50),
        Mat(L"Copper", 80),
        Mat(L"Bleach", 12),
        Tool(L"Needle", 1),
        Tool(L"Scissor", 1),
        Tool(L"Gimlet", 1),
        });
    AddRecipe(L"Flame Belt", {
        Sub(L"Black Plate Belt", 1),
        Mat(L"Cowhide", 70),
        Mat(L"Silk", 50),
        Mat(L"Gold Bar", 60),
        Mat(L"Silver Bar", 80),
        Mat(L"Steel", 110),
        Mat(L"Coal", 80),
        Mat(L"Jade", 70),
        Mat(L"Copper", 100),
        Mat(L"Bleach", 15),
        Tool(L"Needle", 1),
        Tool(L"Scissor", 1),
        Tool(L"Gimlet", 1),
        });
    AddRecipe(L"Dragon Knight Belt", {
        Mat(L"Titanium",  100),
        Mat(L"Aramid",    100),
        Mat(L"Mahogany",  100),
        Mat(L"Bronze",     20),
        Mat(L"Lead",       20),
        Mat(L"Spiky Accessory", 50),
        Mat(L"Spiky Silk", 80),
        Mat(L"Black Silk", 80),
        Mat(L"Steel",    200),
        Mat(L"Bleach",  10),
        Tool(L"Needle", 1),
        Tool(L"Scissor", 1),
        Tool(L"Gimlet", 1),
        Tool(L"Flat Iron", 1),
        });
    AddRecipe(L"Abel Knight Belt", {
        Mat(L"Titanium",  110),
        Mat(L"Aramid",    110),
        Mat(L"Mahogany",  110),
        Mat(L"Bronze",     70),
        Mat(L"Lead",       70),
        Mat(L"Spiky Accessory", 80),
        Mat(L"Spiky Silk", 130),
        Mat(L"Black Silk", 130),
        Mat(L"Steel",    250),
        Mat(L"Bleach",  20),
        Tool(L"Needle", 1),
        Tool(L"Scissor", 1),
        Tool(L"Gimlet", 1),
        Tool(L"Flat Iron", 1),
        });
    AddRecipe(L"Dark Knight's Belt", {
        Mat(L"Cobalt", 210),
        Mat(L"White Gold", 140),
        Mat(L"Aramid", 140),
        Mat(L"Mahogany", 100),
        Mat(L"Lead", 70),
        Mat(L"Spiky Accessory", 100),
        Mat(L"Spiky Silk", 100),
        Mat(L"Black Silk", 100),
        Mat(L"Silver Thread", 300),
        Mat(L"Bleach",  50),
        Tool(L"Needle", 1),
        Tool(L"Scissor", 1),
        Tool(L"Saw", 1),
        Tool(L"Flat Iron", 1),
        });
    AddRecipe(L"Vampire Belt", {
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
    AddRecipe(L"Cuirassier Belt", {
        Mat(L"Ruby", 80),
        Mat(L"Blue Thread", 80),
        Mat(L"Coal",   100),
        Mat(L"Cowhide", 100),
        Mat(L"Steel",  80),
        Mat(L"Silk", 40),
        Mat(L"Gold Bar", 40),
        Mat(L"Silver Bar", 32),
        Mat(L"Jade", 60),
        Mat(L"Bleach",  28),
        Tool(L"Needle", 1),
        Tool(L"Scissor", 1),
        Tool(L"Saw", 1),
        Tool(L"Flat Iron", 1),
        });
}