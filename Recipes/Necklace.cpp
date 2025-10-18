#include "RecipeModel.h"
#include "RecipeModules.h"

using RecipesDB::Mat;
using RecipesDB::Sub;
using RecipesDB::Tool;
using RecipesDB::AddRecipe;

using namespace recipes;

void recipes::RegisterNecklaceRecipes() {
    AddRecipe(L"Apprentice Knight Necklace", {
        Mat(L"Amethyst", 30),
        Mat(L"Coal", 30),
        Mat(L"Thread Bobbin", 20),
        Mat(L"Resin", 22),
        Mat(L"Sword Technique[BGN]", 1),
        Mat(L"Spear Technique[BGN]", 1),
        Mat(L"Axe Technique[BGN]", 1),
        Mat(L"Bow Technique[BGN]", 1),
        Mat(L"Gun Technique[BGN]", 1),
        Mat(L"Cane Technique[BGN]", 1),
        Tool(L"Sawdust", 1),
        });
    AddRecipe(L"Apprentice Weapon Artisan Necklace", {
        Mat(L"Aquamarine", 40),
        Mat(L"Coal", 40),
        Mat(L"Thread Bobbin", 25),
        Mat(L"Resin", 30),
        Mat(L"Sword Manufacture[BGN]", 1),
        Mat(L"Spear Manufacture[BGN]", 1),
        Mat(L"Axe Manufacture[BGN]", 1),
        Mat(L"Bow Manufacture[BGN]", 1),
        Mat(L"Gun Manufacture[BGN]", 1),
        Mat(L"Cane Manufacture[BGN]", 1),
        Tool(L"Sawdust", 1),
        });
    AddRecipe(L"Apprentice Armor Artisan Necklace", {
        Mat(L"Aquamarine", 30),
        Mat(L"Coal", 35),
        Mat(L"Thread Bobbin", 30),
        Mat(L"Resin", 26),
        Mat(L"Armor Manufacture[BGN]", 1),
        Mat(L"Helmet Manufacture[BGN]", 1),
        Mat(L"Belt Manufacture[BGN]", 1),
        Mat(L"Shoe Manufacture[BGN]", 1),
        Tool(L"Sawdust", 1),
        });
    AddRecipe(L"Apprenticeship Maker's Necklace", {
        Mat(L"Topaz", 40),
        Mat(L"Coal", 25),
        Mat(L"Thread Bobbin", 35),
        Mat(L"Resin", 18),
        Mat(L"Crystal Manufacture[BGN]", 1),
        Mat(L"Ironware Manufacture[BGN]", 1),
        Mat(L"Tool Manufacture[BGN]", 1),
        Mat(L"Medicine Prescription[BGN]", 1),
        Mat(L"Recipes[BGN]", 1),
        Tool(L"Sawdust", 1),
        });
    AddRecipe(L"Apprenticeship Technician's Necklace", {
        Mat(L"Topaz", 30),
        Mat(L"Coal", 20),
        Mat(L"Thread Bobbin", 40),
        Mat(L"Resin", 14),
        Mat(L"Farming Technique[BGN]", 1),
        Mat(L"Mining Technique[BGN]", 1),
        Mat(L"Fishing Technique[BGN]", 1),
        Tool(L"Sawdust", 1),
        });
    AddRecipe(L"Apprenticeship Cutter's Necklace", {
        Mat(L"Pearl", 40),
        Mat(L"Coal", 40),
        Mat(L"Thread Bobbin", 45),
        Mat(L"Resin", 30),
        Mat(L"Clothes Manufacture[BGN]", 1),
        Mat(L"Hat Manufacture[BGN]", 1),
        Mat(L"Cloak Manufacture[BGN]", 1),
        Tool(L"Sawdust", 1),
        });
    AddRecipe(L"Jewel Novice's Necklace", {
        Mat(L"Ruby", 40),
        Mat(L"Coal", 50),
        Mat(L"Thread Bobbin", 50),
        Mat(L"Resin", 30),
        Mat(L"Ring Manufacture[BGN]", 1),
        Mat(L"Necklace Manufacture[BGN]", 1),
        Tool(L"Sawdust", 1),
        });
    AddRecipe(L"Other Novice Technician's Necklace", {
        Mat(L"Amethyst", 30),
        Mat(L"Coal", 15),
        Mat(L"Thread Bobbin", 55),
        Mat(L"Resin", 10),
        Mat(L"Summon Technique[BGN]", 1),
        Mat(L"Capture Technique[BGN]", 1),
        Mat(L"Horse Training[BGN]", 1),
        Tool(L"Sawdust", 1),
        });
    AddRecipe(L"Expert Mercenary's Necklace", {
        Mat(L"Amethyst", 65),
        Mat(L"Gold Ore", 50),
        Mat(L"Silver Thread", 30),
        Mat(L"Resin", 45),
        Mat(L"Sword Technique[INT]", 1),
        Mat(L"Spear Technique[INT]", 1),
        Mat(L"Axe Technique[INT]", 1),
        Mat(L"Bow Technique[INT]", 1),
        Mat(L"Gun Technique[INT]", 1),
        Mat(L"Cane Technique[INT]", 1),
        Tool(L"Sawdust", 1),
        });
    AddRecipe(L"Expert Weapon Master's Necklace", {
        Mat(L"Aquamarine", 80),
        Mat(L"Gold Ore", 60),
        Mat(L"Silver Thread", 40),
        Mat(L"Resin", 54),
        Mat(L"Sword Manufacture[INT]", 1),
        Mat(L"Spear Manufacture[INT]", 1),
        Mat(L"Axe Manufacture[INT]", 1),
        Mat(L"Bow Manufacture[INT]", 1),
        Mat(L"Gun Manufacture[INT]", 1),
        Mat(L"Cane Manufacture[INT]", 1),
        Tool(L"Sawdust", 1),
        Tool(L"Craft Shelf", 1),
        });
    AddRecipe(L"Expert Armor Master's Necklace", {
        Mat(L"Aquamarine", 65),
        Mat(L"Gold Ore", 55),
        Mat(L"Silver Thread", 35),
        Mat(L"Resin", 50),
        Mat(L"Armor Manufacture[INT]", 1),
        Mat(L"Helmet Manufacture[INT]", 1),
        Mat(L"Belt Manufacture[INT]", 1),
        Mat(L"Shoe Manufacture[INT]", 1),
        Tool(L"Sawdust", 1),
        Tool(L"Craft Shelf", 1),
        });
    AddRecipe(L"Expert Manufacturer's Necklace", {
        Mat(L"Topaz", 80),
        Mat(L"Gold Ore", 45),
        Mat(L"Silver Thread", 25),
        Mat(L"Resin", 42),
        Mat(L"Crystal Manufacture[INT]", 1),
        Mat(L"Ironware Manufacture[INT]", 1),
        Mat(L"Tool Manufacture[INT]", 1),
        Mat(L"Medicine Prescription[INT]", 1),
        Mat(L"Recipes[INT]", 1),
        Tool(L"Sawdust", 1),
        Tool(L"Craft Shelf", 1),
        });
    AddRecipe(L"Expert Technician's Necklace", {
        Mat(L"Topaz", 65),
        Mat(L"Gold Ore", 40),
        Mat(L"Silver Thread", 20),
        Mat(L"Resin", 38),
        Mat(L"Farming Technique[INT]", 1),
        Mat(L"Mining Technique[INT]", 1),
        Mat(L"Fishing Technique[INT]", 1),
        Tool(L"Sawdust", 1),
        Tool(L"Craft Shelf", 1),
        });
    AddRecipe(L"Expert Cutter's Necklace", {
        Mat(L"Pearl", 80),
        Mat(L"Gold Ore", 55),
        Mat(L"Silver Thread", 35),
        Mat(L"Resin", 50),
        Mat(L"Clothes Manufacture[INT]", 1),
        Mat(L"Hat Manufacture[INT]", 1),
        Mat(L"Cloak Manufacture[INT]", 1),
        Tool(L"Sawdust", 1),
        Tool(L"Craft Shelf", 1),
        });
    AddRecipe(L"Expert Jewel Maker's Necklace", {
        Mat(L"Ruby", 80),
        Mat(L"Gold Ore", 55),
        Mat(L"Silver Thread", 35),
        Mat(L"Resin", 50),
        Mat(L"Ring Manufacture[INT]", 1),
        Mat(L"Necklace Manufacture[INT]", 1),
        Tool(L"Sawdust", 1),
        Tool(L"Craft Shelf", 1),
        });
    AddRecipe(L"Other Skillful Technician's Necklace", {
        Mat(L"Amethyst", 65),
        Mat(L"Gold Ore", 35),
        Mat(L"Silver Thread", 15),
        Mat(L"Resin", 34),
        Mat(L"Summon Technique[INT]", 1),
        Mat(L"Capture Technique[INT]", 1),
        Mat(L"Horse Training[INT]", 1),
        Tool(L"Sawdust", 1),
        Tool(L"Craft Shelf", 1),
        });
    AddRecipe(L"Knights Leader's Necklace", {
        Mat(L"Amethyst", 130),
        Mat(L"Gold Bar", 21),
        Mat(L"Gold Thread", 45),
        Mat(L"Pine", 50),
        Mat(L"Sword Technique[ADV]", 1),
        Mat(L"Spear Technique[ADV]", 1),
        Mat(L"Axe Technique[ADV]", 1),
        Mat(L"Bow Technique[ADV]", 1),
        Mat(L"Gun Technique[ADV]", 1),
        Mat(L"Cane Technique[ADV]", 1),
        Tool(L"Sawdust", 1),
        Tool(L"Craft Shelf", 1),
        });
    AddRecipe(L"Dwarf Weapon Master's Necklace", {
        Mat(L"Aquamarine", 160),
        Mat(L"Gold Bar", 25),
        Mat(L"Gold Thread", 55),
        Mat(L"Pine", 60),
        Mat(L"Sword Manufacture[ADV]", 1),
        Mat(L"Spear Manufacture[ADV]", 1),
        Mat(L"Axe Manufacture[ADV]", 1),
        Mat(L"Bow Manufacture[ADV]", 1),
        Mat(L"Gun Manufacture[ADV]", 1),
        Mat(L"Cane Manufacture[ADV]", 1),
        Tool(L"Sawdust", 1),
        Tool(L"Craft Shelf", 1),
        });
    AddRecipe(L"Dwarf Armor Master's Necklace", {
        Mat(L"Aquamarine", 130),
        Mat(L"Gold Bar", 23),
        Mat(L"Gold Thread", 50),
        Mat(L"Pine", 55),
        Mat(L"Armor Manufacture[ADV]", 1),
        Mat(L"Helmet Manufacture[ADV]", 1),
        Mat(L"Belt Manufacture[ADV]", 1),
        Mat(L"Shoe Manufacture[ADV]", 1),
        Tool(L"Sawdust", 1),
        Tool(L"Craft Shelf", 1),
        });
    AddRecipe(L"Manufacturing Master's Necklace", {
        Mat(L"Topaz", 160),
        Mat(L"Gold Bar", 19),
        Mat(L"Gold Thread", 40),
        Mat(L"Pine", 45),
        Mat(L"Crystal Manufacture[ADV]", 1),
        Mat(L"Ironware Manufacture[ADV]", 1),
        Mat(L"Tool Manufacture[ADV]", 1),
        Mat(L"Medicine Prescription[ADV]", 1),
        Mat(L"Recipes[ADV]", 1),
        Tool(L"Sawdust", 1),
        Tool(L"Craft Shelf", 1),
        });
    AddRecipe(L"Technic Master's Necklace", {
        Mat(L"Topaz", 130),
        Mat(L"Gold Bar", 17),
        Mat(L"Gold Thread", 35),
        Mat(L"Pine", 40),
        Mat(L"Farming Technique[ADV]", 1),
        Mat(L"Mining Technique[ADV]", 1),
        Mat(L"Fishing Technique[INT]", 3),
        Tool(L"Sawdust", 1),
        Tool(L"Craft Shelf", 1),
        });
    AddRecipe(L"Cutting Master's Necklace", {
        Mat(L"Pearl", 160),
        Mat(L"Gold Bar", 25),
        Mat(L"Gold Thread", 55),
        Mat(L"Pine", 60),
        Mat(L"Clothes Manufacture[ADV]", 1),
        Mat(L"Hat Manufacture[ADV]", 1),
        Mat(L"Cloak Manufacture[ADV]", 1),
        Tool(L"Sawdust", 1),
        Tool(L"Craft Shelf", 1),
        });
    AddRecipe(L"Jewel Master's Necklace", {
        Mat(L"Ruby", 160),
        Mat(L"Gold Bar", 25),
        Mat(L"Gold Thread", 55),
        Mat(L"Pine", 60),
        Mat(L"Ring Manufacture[ADV]", 1),
        Mat(L"Necklace Manufacture[ADV]", 1),
        Tool(L"Sawdust", 1),
        Tool(L"Craft Shelf", 1),
        });
    AddRecipe(L"Other Master Technician's Necklace", {
        Mat(L"Amethyst", 130),
        Mat(L"Gold Bar", 15),
        Mat(L"Gold Thread", 30),
        Mat(L"Pine", 35),
        Mat(L"Summon Technique[ADV]", 1),
        Mat(L"Capture Technique[ADV]", 1),
        Mat(L"Horse Training[ADV]", 1),
        Tool(L"Sawdust", 1),
        Tool(L"Craft Shelf", 1),
        });
    AddRecipe(L"Frozen Necklace", {
        Mat(L"Aquamarine", 200),
        Mat(L"Gold Bar", 27),
        Mat(L"Snowball", 40),
        Mat(L"Pine", 65),
        Mat(L"Water Stone", 25),
        Mat(L"Blue Stone Piece", 10),
        Tool(L"Sawdust", 1),
        Tool(L"Craft Shelf", 1),
        });
    AddRecipe(L"Flame Necklace", {
        Mat(L"Ruby", 215),
        Mat(L"Gold Bar", 29),
        Mat(L"Sorcerer's eye", 40),
        Mat(L"Pine", 70),
        Mat(L"Fire Stone", 25),
        Mat(L"Red Stone Piece", 10),
        Tool(L"Sawdust", 1),
        Tool(L"Craft Shelf", 1),
        });
    AddRecipe(L"Dragon Knight Necklace", {
        Mat(L"Amethyst", 230),
        Mat(L"Gold Bar", 31),
        Mat(L"Ruby", 40),
        Mat(L"Pine", 75),
        Mat(L"Blessing Stone", 25),
        Mat(L"Black Stone", 35),
        Tool(L"Sawdust", 1),
        Tool(L"Craft Shelf", 1),
        });
    AddRecipe(L"Abel Necklace", {
        Mat(L"Topaz", 245),
        Mat(L"Gold Bar", 33),
        Mat(L"Pearl", 40),
        Mat(L"Pine", 80),
        Mat(L"Blessing Stone", 25),
        Mat(L"Golden Stone Piece", 10),
        Tool(L"Sawdust", 1),
        Tool(L"Craft Shelf", 1),
        });
    AddRecipe(L"Vampire Necklace[Avatar]", {
        Mat(L"Pearl", 160),
        Mat(L"Gold Bar", 15),
        Mat(L"Ruby", 40),
        Mat(L"Pine", 40),
        Mat(L"Blessing Stone", 25),
        Mat(L"Black Stone", 25),
        Tool(L"Sawdust", 1),
        Tool(L"Craft Shelf", 1),
        });
    AddRecipe(L"Dark Knight Necklace", {
        Mat(L"Diamond", 350),
        Mat(L"Gold Bar", 40),
        Mat(L"Pearl", 40),
        Mat(L"Pine", 90),
        Mat(L"Blessing Stone", 25),
        Mat(L"Black Stone", 10),
        Mat(L"Golden Stone Piece", 10),
        Tool(L"Sawdust", 1),
        Tool(L"Craft Shelf", 1),
        });
}