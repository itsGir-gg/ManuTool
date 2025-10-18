#include "RecipeModel.h"
#include "RecipeModules.h"

using RecipesDB::Mat;
using RecipesDB::Sub;
using RecipesDB::Tool;
using RecipesDB::AddRecipe;

using namespace recipes;

void recipes::RegisterMedicineRecipes() {
    AddRecipe(L"Weak HP Potion", 5, { Mat(L"Horn", 1), Mat(L"Bean Root", 1), Mat(L"Love Vine", 1), Tool(L"Bowl", 1), Tool(L"Medicine Bowl", 1) } );
    AddRecipe(L"Mediocre HP Potion", 4, { Mat(L"Adlay Seed", 2), Mat(L"Orange Peel", 1), Mat(L"Walnut Root", 1), Mat(L"Okara", 1), Tool(L"Bowl", 1), Tool(L"Medicine Bowl", 1)} );
    AddRecipe(L"Average HP Potion", 4, { Mat(L"Ginseng", 1), Mat(L"Bean Root", 1), Mat(L"Walnut Root", 1), Mat(L"Love Vine", 4), Tool(L"Bowl", 1), Tool(L"Medicine Bowl", 1) });
    AddRecipe(L"Strong HP Potion", 4, { Mat(L"Horn", 2), Mat(L"Bean Root", 1), Mat(L"Walnut Root", 1), Mat(L"Madder Seed", 4), Tool(L"Bowl", 1), Tool(L"Medicine Bowl", 1) });
    AddRecipe(L"Super HP Potion", 4, { Mat(L"Ginseng", 2), Mat(L"Madder Seed", 2), Mat(L"Adlay Seed", 1), Mat(L"Mushroom", 1), Mat(L"Bean Root", 1), Tool(L"Bowl", 1), Tool(L"Medicine Bowl", 1) });
    AddRecipe(L"Weak MP Potion", 4, { Mat(L"Ginseng", 2), Mat(L"Walnut Root", 1), Tool(L"Bowl", 1), Tool(L"Medicine Bowl", 1) });
    AddRecipe(L"Average MP Potion", 3, { Mat(L"Pickled Ginseng", 1), Mat(L"Adlay Seed", 1), Mat(L"Mushroom", 1), Tool(L"Bowl", 1), Tool(L"Medicine Bowl", 1) });
    AddRecipe(L"Strong MP Potion", 4, { Mat(L"Horn", 3), Mat(L"Walnut Root", 2), Mat(L"Mushroom", 1), Mat(L"Button Mushroom", 3), Mat(L"Bean Root", 2),Tool(L"Bowl", 1), Tool(L"Medicine Bowl", 1) });
    AddRecipe(L"Super MP Potion", 4, { Mat(L"Mushroom", 2), Mat(L"Okara", 1), Mat(L"Walnut Root", 2), Mat(L"Love Vine", 3), Mat(L"Lily Root", 3), Tool(L"Bowl", 1), Tool(L"Medicine Bowl", 1) });
    AddRecipe(L"Digestive Pill", 1, { Mat(L"Bean Root", 1), Mat(L"Adlay Seed", 1), Mat(L"Walnut Root", 1), Mat(L"Ginseng", 1), Mat(L"Orange Peel", 1), Tool(L"Bowl", 1), Tool(L"Medicine Bowl", 1) });
    AddRecipe(L"Stomach Pill", 1, { Mat(L"Bean Root", 2), Mat(L"Orange Peel", 2), Mat(L"Lily Root", 2), Tool(L"Bowl", 1), Tool(L"Medicine Bowl", 1) });
    AddRecipe(L"Anti-cancer Pill", 1, { Mat(L"Bean Root", 2), Mat(L"Adlay Seed", 2), Mat(L"Okara", 2), Mat(L"Orange Peel", 2), Tool(L"Bowl", 1), Tool(L"Medicine Bowl", 1) });
    AddRecipe(L"Glaze", 4, { Mat(L"Limestone", 2)});
    AddRecipe(L"Stinky soup(60 seconds)", 3, { Mat(L"Garlic", 3), Mat(L"Poisonous Bottle", 2), Mat(L"Mushroom", 1), Tool(L"Bowl", 1), Tool(L"Medicine Bowl", 1) });
    AddRecipe(L"Gold Soup", 1, { Mat(L"Mushroom", 3), Mat(L"Walnut Root", 3), Mat(L"Adlay Seed", 3), Tool(L"Bowl", 1), Tool(L"Medicine Bowl", 1) });
    AddRecipe(L"Polisher", 1, { Mat(L"Lily Root", 5), Mat(L"Okara", 5), Mat(L"Vinegar", 5), Tool(L"Bowl", 1), Tool(L"Medicine Bowl", 1) });
    AddRecipe(L"Bleach", 1, { Mat(L"Lily Root", 5), Mat(L"Okara", 5), Mat(L"Limestone", 5), Tool(L"Bowl", 1), Tool(L"Medicine Bowl", 1) });
    AddRecipe(L"Leather Protector", 1, { Mat(L"Lily Root", 5), Mat(L"Okara", 5), Mat(L"Soy Bean Milk", 5), Tool(L"Bowl", 1), Tool(L"Medicine Bowl", 1) });
    AddRecipe(L"Lubricant", 1, { Mat(L"Lily Root", 5), Mat(L"Okara", 5), Mat(L"Sesame Oil", 5), Tool(L"Bowl", 1), Tool(L"Medicine Bowl", 1) });
    AddRecipe(L"Hypertension Pill", 1, { Mat(L"Adlay Seed", 4), Mat(L"Love Vine", 2), Mat(L"Okara", 1), Tool(L"Bowl", 1), Tool(L"Medicine Bowl", 1) });
    AddRecipe(L"Cold Pill", 1, { Mat(L"Lily Root", 3), Mat(L"Orange Peel", 3), Mat(L"Bean Root", 2), Mat(L"Horn", 2), Tool(L"Bowl", 1), Tool(L"Medicine Bowl", 1) });
    AddRecipe(L"Headache Pill", 1, { Mat(L"Okara", 3), Mat(L"Walnut Root", 2), Mat(L"Orange Peel", 1), Mat(L"Mushroom", 1), Tool(L"Bowl", 1), Tool(L"Medicine Bowl", 1) });
    AddRecipe(L"Strange HP Potion for Summons", 4, { Mat(L"Mushroom", 1), Mat(L"Adlay Seed", 1), Mat(L"Snowball", 1), Mat(L"Madder Seed", 1), Tool(L"Bowl", 1), Tool(L"Medicine Bowl", 1) });
    AddRecipe(L"Mysterious HP Potion for Summons", 4, { Mat(L"Adlay Seed", 2), Mat(L"Bean Root", 2), Mat(L"Ginseng", 1), Mat(L"Orange Peel", 1), Mat(L"Snowball", 2), Tool(L"Bowl", 1), Tool(L"Medicine Bowl", 1) });
    AddRecipe(L"MP Potion for Summoned Monster", 5, { Mat(L"Mushroom", 1), Mat(L"Ginseng", 1), Mat(L"Orange Peel", 1), Mat(L"Walnut Root", 2), Mat(L"Skeleton Bat Tooth", 1), Tool(L"Bowl", 1), Tool(L"Medicine Bowl", 1) });
    AddRecipe(L"Antidotes", 1, { Mat(L"Bean Root", 5), Mat(L"Love Vine", 10), Mat(L"Madder Seed", 15), Tool(L"Bowl", 1), Tool(L"Medicine Bowl", 1) });
}