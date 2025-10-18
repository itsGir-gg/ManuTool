#include "RecipeModel.h"
#include "RecipeModules.h"

using RecipesDB::Mat;
using RecipesDB::Sub;
using RecipesDB::Tool;
using RecipesDB::AddRecipe;

using namespace recipes;

void recipes::RegisterCloakRecipes() {
    AddRecipe(L"Amethyst Cloak[Avatar]", {
        Mat(L"Cowhide", 6),
        Mat(L"Thread Bobbin", 6),
        Mat(L"Feather", 8),
        Mat(L"Resin", 2),
        Mat(L"Copper", 3),
        Tool(L"Flat Iron", 1),
        });
    AddRecipe(L"School Bag[Avatar]", {
        Mat(L"Cowhide", 9),
        Mat(L"Thread Bobbin", 9),
        Mat(L"Feather", 12),
        Mat(L"Resin", 4),
        Mat(L"Copper", 6),
        Tool(L"Flat Iron", 1),
        });
    AddRecipe(L"Cheering Cloak[Avatar]", {
        Mat(L"Cowhide", 12),
        Mat(L"Thread Bobbin", 12),
        Mat(L"Feather", 15),
        Mat(L"Resin", 6),
        Mat(L"Copper", 9),
        Tool(L"Flat Iron", 1),
        });
    AddRecipe(L"Angel Wings[Avatar]", {
        Mat(L"Embroidered Thread Bobbin", 11),
        Mat(L"Blue Thread", 16),
        Mat(L"Feather", 18),
        Mat(L"Resin", 8),
        Mat(L"Copper", 12),
        Tool(L"Flat Iron", 1),
        });
    AddRecipe(L"Adventurer Cloak[Avatar]", {
        Mat(L"Embroidered Thread Bobbin", 14),
        Mat(L"Blue Thread", 20),
        Mat(L"Feather", 21),
        Mat(L"Resin", 10),
        Mat(L"Sulfur", 5),
        Mat(L"Clay", 10),
        Tool(L"Flat Iron", 1),
        Tool(L"Cutting Tool", 1),
        });
    AddRecipe(L"Devil Wings[Avatar]", {
        Mat(L"Embroidered Thread Bobbin", 17),
        Mat(L"Blue Thread", 24),
        Mat(L"Feather", 24),
        Mat(L"Resin", 12),
        Mat(L"Sulfur", 10),
        Mat(L"Clay", 15),
        Tool(L"Flat Iron", 1),
        Tool(L"Cutting Tool", 1),
        });
    AddRecipe(L"Goblin King's Cloak[Avatar]", {
        Mat(L"Ramie", 20),
        Mat(L"Spiky Silk", 15),
        Mat(L"Blue Thread", 24),
        Mat(L"Resin", 14),
        Mat(L"Sulfur", 15),
        Mat(L"Clay", 20),
        Tool(L"Flat Iron", 1),
        Tool(L"Cutting Tool", 1),
        });
    AddRecipe(L"Frozen Cape[Avatar]", {
        Mat(L"Water Stone", 15),
        Mat(L"Spiky Silk", 25),
        Mat(L"Black Silk", 15),
        Mat(L"Resin", 18),
        Mat(L"Blue Stone Piece", 8),
        Mat(L"Snowball", 30),
        Tool(L"Flat Iron", 1),
        Tool(L"Cutting Tool", 1),
        });
    AddRecipe(L"Flame Cape[Avatar]", {
        Mat(L"Fire Stone", 15),
        Mat(L"Spiky Silk", 30),
        Mat(L"Black Silk", 18),
        Mat(L"Resin", 24),
        Mat(L"Red Stone Piece", 8),
        Mat(L"Sorcerer's eye", 30),
        Tool(L"Flat Iron", 1),
        Tool(L"Cutting Tool", 1),
        });
    AddRecipe(L"Dragon Knight's Wing[Avatar]", {
        Mat(L"Blessing Stone", 15),
        Mat(L"Spiky Silk", 35),
        Mat(L"Black Silk", 21),
        Mat(L"Resin", 26),
        Mat(L"Black Stone", 25),
        Mat(L"Diamond", 30),
        Tool(L"Flat Iron", 1),
        Tool(L"Cutting Tool", 1),
        });
    AddRecipe(L"Abel Knights Cape[Avatar]", {
        Mat(L"Blessing Stone", 15),
        Mat(L"Spiky Silk", 40),
        Mat(L"Black Silk", 24),
        Mat(L"Resin", 28),
        Mat(L"Golden Stone Piece", 8),
        Mat(L"Pearl", 30),
        Tool(L"Flat Iron", 1),
        Tool(L"Cutting Tool", 1),
        });
    AddRecipe(L"Vampire Cloak[Avatar]", {
        Mat(L"Blessing Stone", 15),
        Mat(L"Spiky Silk", 15),
        Mat(L"Black Silk", 15),
        Mat(L"Resin", 24),
        Mat(L"Black Stone", 15),
        Mat(L"Amethyst", 30),
        Tool(L"Flat Iron", 1),
        Tool(L"Cutting Tool", 1),
        });
    AddRecipe(L"Archangel's Wing[Avatar]", {
        Mat(L"Ramie", 18),
        Mat(L"Spiky Silk", 20),
        Mat(L"Blue Thread", 27),
        Mat(L"Resin", 16),
        Mat(L"Sulfur", 20),
        Sub(L"Angel Wings[Avatar]", 1),
        Tool(L"Flat Iron", 1),
        Tool(L"Cutting Tool", 1),
        });
    AddRecipe(L"Satan's Wing[Avatar]", {
        Mat(L"Ramie", 27),
        Mat(L"Spiky Silk", 32),
        Mat(L"Blue Thread", 17),
        Mat(L"Resin", 22),
        Mat(L"Sulfur", 25),
        Sub(L"Devil Wings[Avatar]", 1),
        Tool(L"Flat Iron", 1),
        Tool(L"Cutting Tool", 1),
        });
    AddRecipe(L"Dark Knight Cloak[Avatar]", {
        Mat(L"Blessing Stone", 15),
        Mat(L"Spiky Silk", 50),
        Mat(L"Black Silk", 30),
        Mat(L"Resin", 32),
        Mat(L"Golden Stone Piece", 5),
        Mat(L"Black Stone", 30),
        Mat(L"Diamond", 30),
        Tool(L"Flat Iron", 1),
        Tool(L"Cutting Tool", 1),
        });
}