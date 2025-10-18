#include "RecipeModel.h"
#include "RecipeModules.h"

using RecipesDB::Mat;
using RecipesDB::Sub;
using RecipesDB::Tool;
using RecipesDB::AddRecipe;

using namespace recipes;

void recipes::RegisterShoeRecipes() {
    AddRecipe(L"JP Straw Shoes", {
        Mat(L"Straw", 15),
        });
    AddRecipe(L"Straw Shoes", {
        Mat(L"Straw", 20),
        Mat(L"Cowhide", 10),
        });
    AddRecipe(L"Round Shoes", {
        Mat(L"Straw", 30),
        Mat(L"Cowhide", 10),
        });
    AddRecipe(L"Wooden Shoes", {
        Mat(L"Oak", 45),
        });
    AddRecipe(L"Leather Shoes", {
        Mat(L"Cowhide", 30),
        Mat(L"Silk", 30),
        Mat(L"Thread Bobbin", 10),
        Mat(L"Cotton", 10),
        Tool(L"Needle", 1),
        });
    AddRecipe(L"Wooden Boots", {
        Mat(L"Cowhide", 30),
        Mat(L"Silk", 30),
        Mat(L"Embroidered Thread Bobbin", 60),
        Mat(L"Satin", 60),
        Mat(L"Thread Bobbin", 15),
        Mat(L"Cotton", 30),
        Tool(L"Needle", 1),
        });
    AddRecipe(L"Aquatic Boots", {
        Mat(L"Cowhide", 30),
        Mat(L"Silk", 40),
        Mat(L"Embroidered Thread Bobbin", 60),
        Mat(L"Satin", 60),
        Mat(L"Thread Bobbin", 30),
        Mat(L"Cotton", 30),
        Tool(L"Needle", 1),
        Tool(L"Scissor", 1),
        });
    AddRecipe(L"Rapid Shoes", {
        Mat(L"Cowhide", 50),
        Mat(L"Silk", 40),
        Mat(L"Embroidered Thread Bobbin", 100),
        Mat(L"Satin", 80),
        Mat(L"Thread Bobbin", 45),
        Mat(L"Cotton", 40),
        Mat(L"Bleach", 1),
        Tool(L"Needle", 1),
        Tool(L"Scissor", 1),
        });
    AddRecipe(L"Glass Shoes", {
        Mat(L"Cowhide", 50),
        Mat(L"Silk", 45),
        Mat(L"Embroidered Thread Bobbin", 100),
        Mat(L"Satin", 100),
        Mat(L"Thread Bobbin", 60),
        Mat(L"Cotton", 40),
        Mat(L"Bleach", 2),
        Tool(L"Needle", 1),
        Tool(L"Scissor", 1),
        });
    AddRecipe(L"Black Shoes", {
        Sub(L"Rapid Shoes", 1),
        Mat(L"Embroidered Thread Bobbin", 120),
        Mat(L"Satin", 120),
        Mat(L"Premium Silk", 40),
        Mat(L"Gold Thread", 30),
        Mat(L"Silver Thread", 30),
        Mat(L"Thread Bobbin", 75),
        Mat(L"Cotton", 60),
        Mat(L"Amethyst", 30),
        Mat(L"Bleach", 5),
        Tool(L"Needle", 1),
        Tool(L"Scissor", 1),
        });
    AddRecipe(L"Green Shoes", {
        Sub(L"Glass Shoes", 1),
        Mat(L"Embroidered Thread Bobbin", 120),
        Mat(L"Satin", 120),
        Mat(L"Premium Silk", 40),
        Mat(L"Gold Thread", 30),
        Mat(L"Silver Thread", 30),
        Mat(L"Thread Bobbin", 90),
        Mat(L"Cotton", 60),
        Mat(L"Amethyst", 30),
        Mat(L"Bleach", 6),
        Tool(L"Needle", 1),
        Tool(L"Scissor", 1),
        Tool(L"Gimlet", 1),
        });
    AddRecipe(L"Red Shoes", {
        Sub(L"Black Shoes", 1),
        Mat(L"Embroidered Thread Bobbin", 140),
        Mat(L"Satin", 140),
        Mat(L"Premium Silk", 50),
        Mat(L"Gold Thread", 70),
        Mat(L"Silver Thread", 70),
        Mat(L"Thread Bobbin", 110),
        Mat(L"Cotton", 80),
        Mat(L"Amethyst", 40),
        Mat(L"Bleach", 10),
        Tool(L"Needle", 1),
        Tool(L"Scissor", 1),
        Tool(L"Gimlet", 1),
        });
    AddRecipe(L"Brown Shoes", {
        Sub(L"Green Shoes", 1),
        Mat(L"Embroidered Thread Bobbin", 140),
        Mat(L"Satin", 140),
        Mat(L"Premium Silk", 50),
        Mat(L"Gold Thread", 70),
        Mat(L"Silver Thread", 70),
        Mat(L"Thread Bobbin", 120),
        Mat(L"Cotton", 80),
        Mat(L"Amethyst", 50),
        Mat(L"Bleach", 10),
        Tool(L"Needle", 1),
        Tool(L"Scissor", 1),
        Tool(L"Gimlet", 1),
        Tool(L"Flat Iron", 1),
        });
    AddRecipe(L"Frozen Shoes", {
        Sub(L"Red Shoes", 1),
        Mat(L"Embroidered Thread Bobbin", 150),
        Mat(L"Satin", 150),
        Mat(L"Premium Silk", 70),
        Mat(L"Gold Thread", 80),
        Mat(L"Silver Thread", 80),
        Mat(L"Thread Bobbin", 120),
        Mat(L"Cotton", 80),
        Mat(L"Amethyst", 100),
        Mat(L"Bleach", 12),
        Tool(L"Needle", 1),
        Tool(L"Scissor", 1),
        Tool(L"Gimlet", 1),
        Tool(L"Flat Iron", 1),
        });
    AddRecipe(L"Flame Shoes", {
        Sub(L"Brown Shoes", 1),
        Mat(L"Embroidered Thread Bobbin", 200),
        Mat(L"Satin", 200),
        Mat(L"Premium Silk", 90),
        Mat(L"Gold Thread", 110),
        Mat(L"Silver Thread", 110),
        Mat(L"Thread Bobbin", 130),
        Mat(L"Cotton", 110),
        Mat(L"Amethyst", 120),
        Mat(L"Bleach", 15),
        Tool(L"Needle", 1),
        Tool(L"Scissor", 1),
        Tool(L"Gimlet", 1),
        Tool(L"Flat Iron", 1),
        });
    AddRecipe(L"Dragon Knight Shoes", {
        Mat(L"Titanium",   20),
        Mat(L"Aramid",    160),
        Mat(L"Mahogany",  120),
        Mat(L"Spiky Accessory", 50),
        Mat(L"Spiky Silk",100),
        Mat(L"Black Silk",100),
        Mat(L"Amethyst",  200),
        Mat(L"Bleach",  10),
        Tool(L"Needle", 1),
        Tool(L"Scissor", 1),
        Tool(L"Gimlet", 1),
        Tool(L"Flat Iron", 1),
        });
    AddRecipe(L"Abel Knight Shoe", {
        Mat(L"Titanium",   30),
        Mat(L"Aramid",    170),
        Mat(L"Mahogany",  130),
        Mat(L"Spiky Accessory", 80),
        Mat(L"Spiky Silk",150),
        Mat(L"Black Silk",150),
        Mat(L"Amethyst",  250),
        Mat(L"Bleach",  20),
        Tool(L"Needle", 1),
        Tool(L"Scissor", 1),
        Tool(L"Gimlet", 1),
        Tool(L"Flat Iron", 1),
        });
    AddRecipe(L"Vampire Shoes", {
        Mat(L"Black Stone", 80),
        Mat(L"Blessing Stone", 25),
        Mat(L"Premium Silk", 50),
        Mat(L"Gold Thread", 70),
        Mat(L"Silver Thread", 70),
        Mat(L"Thread Bobbin", 120),
        Mat(L"Cotton", 80),
        Mat(L"Amethyst",  50),
        Mat(L"Bleach",  10),
        Tool(L"Needle", 1),
        Tool(L"Scissor", 1),
        Tool(L"Saw", 1),
        Tool(L"Flat Iron", 1),
        });
}