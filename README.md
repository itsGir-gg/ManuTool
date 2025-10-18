```markdown
# GoonZu ManuTool — Clean-start helper

Goal
- Start a fresh, minimal repo while keeping the recipes and icons you care about.
- Provide a tiny viewer app so you can confirm the recipes were preserved.

What I prepared
- scripts/extract_recipes.py : extracts recipes from existing C++ files under ManuTool/Recipes and emits a simple data/recipes.txt file.
- data/recipes.txt : (output) the canonical recipes file used by the new minimal app.
- src/main.cpp + CMakeLists.txt : a minimal Win32 GUI (ListBox + details view) that reads data/recipes.txt and shows recipe names + ingredients.
- assets/icons/ : place your icons here (the minimal app will try to load icons if present).
- .gitignore : repository ignore rules.

How to use (recommended safe sequence)

1) Backup current repo (very important)
   - Copy your repo folder somewhere, or create a local branch:
     git checkout -b backup-before-clean

2) Create a fresh branch to work in:
   git checkout -b clean-start

3) Add the files from this patch to your repo (drop them into repository root).

4) Extract recipes from your current code:
   - Make sure you have Python 3 installed.
   - From repo root:
     python scripts/extract_recipes.py --src ManuTool/Recipes --out data/recipes.txt

   This scans all .cpp files under the given source dir and writes a simple recipes text file. Inspect data/recipes.txt to verify your recipes were found.

5) Copy your icons/resources
   - Find the icons you want to keep (in your old repo they might be in ManuTool/res or similar).
   - Copy them to assets/icons/ (create that directory if it doesn’t exist).
   - Filenames should be regular image/icon files (.ico, .png). The minimal app will attempt to load `.ico` files from that folder if present.

6) Build the minimal app (CMake)
   - Windows (Developer Command Prompt) example:
     mkdir build
     cd build
     cmake -G "Visual Studio 17 2022" ..
     cmake --build . --config Release

   - Or open the generated solution in Visual Studio and run.

7) Run the app
   - The app displays a list of recipes on the left; selecting a recipe displays its ingredient lines on the right.
   - This is a small viewer only — no edit/save/build features. Once you confirm recipes are present, you can proceed to rebuild a clean full app from this foundation.

Notes about rewriting history / removing old blobs
- This “clean start” approach keeps your original repository intact. If you want to *remove* big historical blobs (.vs/ipch) from the *remote* history (GitHub) so the remote is small and clean, you’ll still need to run history-cleaning (git-filter-repo or BFG) as discussed earlier. I can prepare a safe step-by-step script to remove .vs/ipch from history if you want that next.

If you want I can:
- Open a PR/branch with these files in your repo (I cannot push without your permission / credentials).
- Or provide an automated PowerShell script to run the extraction + create a new “clean” branch for you.

If you’re ready, apply these files and run the extractor. If anything fails, paste the extractor output and any errors and I’ll iterate.
```