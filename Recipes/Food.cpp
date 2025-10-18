#include "RecipeModel.h"
#include "RecipeModules.h"

using RecipesDB::Mat;
using RecipesDB::Sub;
using RecipesDB::Tool;
using RecipesDB::AddRecipe;

using namespace recipes;

void recipes::RegisterFoodRecipes() {
    AddRecipe(L"Half Moon Dumpling", 5, { Mat(L"Flour", 1 ), Mat(L"Sesame Oil", 1), Mat(L"Honey", 2)});
    AddRecipe(L"Skewers", 5, { Mat(L"Beef", 2), Mat(L"Onion", 1), Mat(L"Shitake Mushroom", 2) });
    AddRecipe(L"Rice Ball", 5, { Mat(L"Rice", 2), Mat(L"Salt", 1), Mat(L"Sesame Seed", 1) });
    AddRecipe(L"Bread", 3, { Mat(L"Flour", 3), Mat(L"Salt", 1)});
    AddRecipe(L"Meat Dumpling", 3, { Mat(L"Flour", 3), Mat(L"Salt", 1), Mat(L"Pork", 5) });
    AddRecipe(L"Moon Cake", 3, { Mat(L"Flour", 3), Mat(L"Sweet Potato", 1), Mat(L"Sesame Oil", 1), Mat(L"Honey", 2) });
    AddRecipe(L"Sausage", 3, { Mat(L"Pork", 3), Mat(L"Salt", 1)});
    AddRecipe(L"Rice Cake Soup", 5, { Mat(L"Rice Cake", 1), Mat(L"Beef", 6), Mat(L"Salt", 1) });
    AddRecipe(L"Beef Soup", 4, { Mat(L"Rice", 1), Mat(L"Radish", 1), Mat(L"Beef", 2), Mat(L"Garlic", 2), Mat(L"Shitake Mushroom", 2)});
    AddRecipe(L"Abalone Congee", 3, { Mat(L"Rice", 1), Mat(L"Abalone", 5), Mat(L"Sea Slug", 5), Mat(L"Garlic", 2), Mat(L"Sesame Seed", 1), Mat(L"Salt", 1), Tool(L"Pottery", 1) });
    AddRecipe(L"Japanese Dumpling", 8, { Mat(L"Flour", 1), Mat(L"Pork", 5), Mat(L"Carrot", 1), Mat(L"Cucumber", 1), Mat(L"Onion", 2), Mat(L"Chinese Noodles", 1), Tool(L"Pottery", 1) });
    AddRecipe(L"Beef Rib", 5, { Mat(L"Beef", 6), Mat(L"Soy Sauce", 1), Mat(L"Garlic", 5), Mat(L"Carrot", 3), Mat(L"Honey", 2), Mat(L"Onion", 2), Mat(L"Radish", 1), Tool(L"Plate", 1) });
    AddRecipe(L"Seafood Hotpot", 5, { Mat(L"Parsley", 3), Mat(L"Radish", 1), Mat(L"Sea Slug", 3), Mat(L"Abalone", 3), Mat(L"Soy Sauce", 2), Mat(L"Octopus", 3), Tool(L"Pottery", 1) });
    AddRecipe(L"Starch Noodle", 4, { Mat(L"Pork", 5), Mat(L"Chinese Noodles", 1), Mat(L"Shitake Mushroom", 2), Mat(L"Salt", 1), Mat(L"Cucumber", 1), Tool(L"Plate", 1) });
    AddRecipe(L"Shabu Shabu", 5, { Mat(L"Beef", 6), Mat(L"Parsley", 2), Mat(L"Sea Slug", 2), Mat(L"Abalone", 2), Mat(L"Soy Sauce", 1), Tool(L"Brass Crafting Dish", 1) });
    AddRecipe(L"Chicken Soup", 4, { Mat(L"Chicken", 3), Mat(L"Garlic", 2), Mat(L"Rice", 1), Mat(L"Sesame Seed", 1), Mat(L"Salt", 1), Tool(L"Pottery", 1) });
    AddRecipe(L"Crucian Carp Spicy Soup", 4, { Mat(L"Crucian Carp", 4), Mat(L"Potato", 2), Mat(L"Radish", 1), Mat(L"Onion", 2), Mat(L"Salt", 1), Tool(L"Iron Pot", 1) });
    AddRecipe(L"Catfish Spicy Soup", 4, { Mat(L"Catfish", 4), Mat(L"Potato", 2), Mat(L"Radish", 1), Mat(L"Onion", 2), Mat(L"Salt", 1), Mat(L"Parsley", 2),Tool(L"Iron Pot", 1) });
    AddRecipe(L"Carp Soup", 4, { Mat(L"Carp", 4), Mat(L"Parsley", 2), Mat(L"Onion", 2), Mat(L"Potato", 2), Mat(L"Radish", 1), Mat(L"Shitake Mushroom", 2), Mat(L"Salt", 1), Tool(L"Iron Pot", 1) });
    AddRecipe(L"Pancake", 4, { Mat(L"Prawn", 2), Mat(L"Potato", 5), Mat(L"Flour", 1), Mat(L"Sesame Oil", 1), Mat(L"Carrot", 1), Mat(L"Salt", 1), Tool(L"Plate", 1) });
    AddRecipe(L"Eel BBQ", 4, { Mat(L"Eel", 2), Mat(L"Charcoal", 1), Mat(L"Sesame Oil", 1), Mat(L"Soy Sauce", 1), Mat(L"Garlic", 2), Mat(L"Onion", 2), Tool(L"Plate", 1) });
    AddRecipe(L"Hard Boiled Mackerel", 4, { Mat(L"Mackerel", 2), Mat(L"Soy Sauce", 1), Mat(L"Garlic", 3), Mat(L"Onion", 3), Mat(L"Radish", 1), Mat(L"Sesame Oil", 1),Tool(L"Plate", 1) });
    AddRecipe(L"Feed A", { Mat(L"Rice", 1), Mat(L"Shitake Mushroom", 1), Mat(L"Sweet Potato", 1), Mat(L"Carrot", 1), Mat(L"Sesame Seed", 1), Mat(L"Pork", 1), Mat(L"Salt", 1), Mat(L"Crucian Carp", 1), Mat(L"Octopus", 1), Mat(L"Mackerel", 1), Tool(L"Iron Pot", 1) });
    AddRecipe(L"Feed B", { Mat(L"Radish", 1), Mat(L"Mung Bean", 1), Mat(L"Onion", 1), Mat(L"Garlic", 1), Mat(L"Wheat", 1), Mat(L"Beef", 1), Mat(L"Sea Slug", 1), Mat(L"Catfish", 1), Mat(L"Prawn", 1), Tool(L"Iron Pot", 1) });
    AddRecipe(L"Feed C", { Mat(L"Parsley", 1), Mat(L"Potato", 1), Mat(L"Cucumber", 1), Mat(L"Bean", 1), Mat(L"Chicken", 1), Mat(L"Honey", 1), Mat(L"Abalone", 1), Mat(L"Carp", 1), Mat(L"Eel", 1), Tool(L"Iron Pot", 1) });
    AddRecipe(L"Easy Feed", 2, { Mat(L"Feed A", 3), Mat(L"Feed B", 3), Mat(L"Feed C", 3), Tool(L"Grinding Stone", 1), Tool(L"Mortar", 1) });
}