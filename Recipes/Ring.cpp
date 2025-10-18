#include "RecipeModel.h"
#include "RecipeModules.h"

using RecipesDB::Mat;
using RecipesDB::Sub;
using RecipesDB::Tool;
using RecipesDB::AddRecipe;

using namespace recipes;

void recipes::RegisterRingRecipes() {
    AddRecipe(L"Ring of Oger", {
        Mat(L"Ruby", 30),
        Mat(L"Coral", 10),
        Mat(L"Amber", 8),
        Mat(L"Brass", 3),
        Tool(L"Sawdust", 1),
        });
    AddRecipe(L"Ring of Intelligence", {
        Mat(L"Diamond", 35),
        Mat(L"Coral", 15),
        Mat(L"Amber", 14),
        Mat(L"Brass", 6),
        Tool(L"Sawdust", 1),
        });
    AddRecipe(L"Ring of Thunder", {
        Mat(L"Aquamarine", 40),
        Mat(L"Topaz", 15),
        Mat(L"Amber", 20),
        Mat(L"Brass", 9),
        Tool(L"Sawdust", 1),
        });
    AddRecipe(L"Ring of Stamina", {
        Mat(L"Pearl", 45),
        Mat(L"Coal", 20),
        Mat(L"Amber", 26),
        Mat(L"Brass", 12),
        Tool(L"Sawdust", 1),
        });
    AddRecipe(L"Rucky Ring[Avatar]", {
        Mat(L"Amethyst", 50),
        Mat(L"Coal", 25),
        Mat(L"Amber", 32),
        Mat(L"Brass", 15),
        Tool(L"Sawdust", 1),
        });
    AddRecipe(L"Ring of Knights", {
        Mat(L"Ruby", 55),
        Mat(L"Coral", 12),
        Mat(L"Silver Ore", 38),
        Mat(L"Brass", 18),
        Mat(L"Lead", 20),
        Tool(L"Sawdust", 1),
        });
    AddRecipe(L"Ring of Magicians", {
        Mat(L"Diamond", 60),
        Mat(L"Coral", 15),
        Mat(L"Silver Ore", 44),
        Mat(L"Brass", 21),
        Mat(L"Lead", 25),
        Tool(L"Sawdust", 1),
        Tool(L"Craft Shelf", 1),
        });
    AddRecipe(L"Ring of Lightning", {
        Mat(L"Aquamarine", 65),
        Mat(L"Topaz", 30),
        Mat(L"Silver Ore", 50),
        Mat(L"Brass", 24),
        Mat(L"Lead", 30),
        Tool(L"Sawdust", 1),
        Tool(L"Craft Shelf", 1),
        });
    AddRecipe(L"Ring of Angel", {
        Mat(L"Pearl", 70),
        Mat(L"Coral", 21),
        Mat(L"Silver Ore", 56),
        Mat(L"Brass", 27),
        Mat(L"Lead", 35),
        Tool(L"Sawdust", 1),
        Tool(L"Craft Shelf", 1),
        });
    AddRecipe(L"Ring of Abundance", {
        Mat(L"Amethyst", 75),
        Mat(L"Coral", 24),
        Mat(L"Silver Ore", 62),
        Mat(L"Brass", 30),
        Mat(L"Lead", 40),
        Tool(L"Sawdust", 1),
        Tool(L"Craft Shelf", 1),
        });
    AddRecipe(L"Ring of Destroyer", {
        Mat(L"Ruby", 80),
        Mat(L"Spiky Silk", 30),
        Mat(L"Gold Ore", 68),
        Mat(L"Brass", 33),
        Mat(L"Lead", 45),
        Mat(L"Bronze", 10),
        Tool(L"Sawdust", 1),
        Tool(L"Craft Shelf", 1),
        });
    AddRecipe(L"Ring of Philosopher", {
        Mat(L"Diamond", 85),
        Mat(L"Spiky Silk", 40),
        Mat(L"Gold Ore", 74),
        Mat(L"Brass", 36),
        Mat(L"Lead", 50),
        Mat(L"Bronze", 15),
        Tool(L"Sawdust", 1),
        Tool(L"Craft Shelf", 1),
        });
    AddRecipe(L"Ring of Storm", {
        Mat(L"Aquamarine", 90),
        Mat(L"Topaz", 45),
        Mat(L"Gold Ore", 80),
        Mat(L"Brass", 39),
        Mat(L"Lead", 55),
        Mat(L"Bronze", 20),
        Tool(L"Sawdust", 1),
        Tool(L"Craft Shelf", 1),
        });
    AddRecipe(L"Ring of Guardian", {
        Mat(L"Pearl", 95),
        Mat(L"Spiky Silk", 50),
        Mat(L"Gold Ore", 86),
        Mat(L"Brass", 42),
        Mat(L"Lead", 60),
        Mat(L"Bronze", 25),
        Tool(L"Sawdust", 1),
        Tool(L"Craft Shelf", 1),
        });
    AddRecipe(L"Ring of Master", {
        Mat(L"Amethyst", 100),
        Mat(L"Spiky Silk", 60),
        Mat(L"Gold Ore", 92),
        Mat(L"Brass", 45),
        Mat(L"Lead", 65),
        Mat(L"Bronze", 30),
        Tool(L"Sawdust", 1),
        Tool(L"Craft Shelf", 1),
        });
    AddRecipe(L"Frozen Ring", {
        Mat(L"Blue Stone Piece", 5),
        Mat(L"Snowball", 15),
        Mat(L"Water Stone", 10),
        Mat(L"Brass", 48),
        Mat(L"Lead", 70),
        Mat(L"Bronze", 35),
        Tool(L"Sawdust", 1),
        Tool(L"Craft Shelf", 1),
        });
    AddRecipe(L"Flame Ring", {
        Mat(L"Red Stone Piece", 5),
        Mat(L"Sorcerer's Eye", 15),
        Mat(L"Fire Stone", 10),
        Mat(L"Brass", 51),
        Mat(L"Lead", 75),
        Mat(L"Bronze", 40),
        Tool(L"Sawdust", 1),
        Tool(L"Craft Shelf", 1),
        });
    AddRecipe(L"Dragon Knight Ring", {
        Mat(L"Black Stone", 20),
        Mat(L"Diamond", 30),
        Mat(L"Blessing Stone", 10),
        Mat(L"Brass", 54),
        Mat(L"Lead", 80),
        Mat(L"Bronze", 45),
        Tool(L"Sawdust", 1),
        Tool(L"Craft Shelf", 1),
        });
    AddRecipe(L"Abel Ring", {
        Mat(L"Golden Stone Piece", 5),
        Mat(L"Pearl", 30),
        Mat(L"Blessing Stone", 10),
        Mat(L"Brass", 57),
        Mat(L"Lead", 85),
        Mat(L"Bronze", 50),
        Tool(L"Sawdust", 1),
        Tool(L"Craft Shelf", 1),
        });
    AddRecipe(L"Vampire Ring[Avatar]", {
        Mat(L"Black Stone", 10),
        Mat(L"Amethyst", 30),
        Mat(L"Blessing Stone", 10),
        Mat(L"Brass", 60),
        Mat(L"Lead", 90),
        Mat(L"Bronze", 55),
        Tool(L"Sawdust", 1),
        Tool(L"Craft Shelf", 1),
        });
    AddRecipe(L"Dark Knight Ring[Avartar]", {
        Mat(L"Golden Stone Piece", 5),
        Mat(L"Black Stone", 5),
        Mat(L"Diamond", 50),
        Mat(L"Blessing Stone", 10),
        Mat(L"Brass", 65),
        Mat(L"Lead", 95),
        Mat(L"Bronze", 60),
        Tool(L"Sawdust", 1),
        Tool(L"Craft Shelf", 1),
        });
}