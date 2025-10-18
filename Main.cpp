// ManuTool/Main.cpp
// Complete app with robust icon + embedded-recipes support.
// Added: fallback to embedded categories resource (IDR_CATEGORIES) when ManuTool headers are not present.
// This makes the EXE standalone (no external ManuTool folder required) if you embed data/categories.txt
// as a RCDATA resource (see note below).
//
// Expectations:
// - resource.h must define IDR_RECIPES and (optionally) IDR_CATEGORIES and IDI_MANUTOOL.
// - If you want the EXE to show categories without shipping ManoTool/*.h, embed a categories file (see notes).
//
// Categories resource format (simple TSV):
// Each line: <Category>\t<Item Name>
// Example:
// Helmet	Weak Leather Helmet
// Helmet	Strong Leather Helmet
//
// If the runtime finds the ManuTool folder it will parse headers as before; otherwise it will try the embedded resource.

#include <windows.h>
#include <commctrl.h>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>

#pragma comment(lib, "Comctl32.lib")
#pragma comment(lib, "dwmapi.lib")

#include "resource.h" // must define IDR_RECIPES, and optionally IDR_CATEGORIES, IDI_MANUTOOL

struct InputLine { char type; std::wstring name; int qty; };
struct Recipe { std::wstring name; int yield; std::vector<InputLine> inputs; };

static std::vector<Recipe> g_recipes;
static HWND g_hTree = nullptr;
static HWND g_hDetails = nullptr;
static HIMAGELIST g_hImgList = nullptr;
static HICON g_hIconLarge = nullptr;
static HICON g_hIconSmall = nullptr;

// UI controls
static HWND g_hQtyEdit = nullptr;
static HWND g_hQtySpin = nullptr;
static HWND g_hHeader = nullptr;
static HWND g_hQtyLabel = nullptr;

// icon cache map (fullpath -> image list index)
static std::unordered_map<std::wstring, int> g_iconIndexMap;

// Control IDs
static constexpr int TV_ID = 1001;
static constexpr int EDIT_ID = 1002;
static constexpr int IDM_FILE_EXIT = 4001;
static constexpr int IDM_HELP_ABOUT = 4002;
static constexpr int IDM_VIEW_DARKMODE = 4003;
static constexpr int IDC_QTY_EDIT = 2001;
static constexpr int IDC_QTY_SPIN = 2002;
static constexpr int IDC_HEADER = 2003;
static constexpr int IDC_QTY_LABEL = 2004;

// Dark mode
static bool g_darkMode = false;
static HBRUSH g_hbrDarkWnd = nullptr;
static HBRUSH g_hbrDarkEdit = nullptr;

static const COLORREF COL_DARK_BG = RGB(30, 30, 30);
static const COLORREF COL_DARK_EDIT = RGB(42, 42, 42);
static const COLORREF COL_DARK_TEXT = RGB(240, 240, 240);
static const COLORREF COL_LIGHT_BG = RGB(255, 255, 255);
static const COLORREF COL_LIGHT_TEXT = RGB(0, 0, 0);

// ----------------- small helpers ------------------------------------------

static std::wstring GetExeDir()
{
    wchar_t buf[MAX_PATH]{};
    DWORD n = GetModuleFileNameW(nullptr, buf, MAX_PATH);
    if (n == 0 || n == MAX_PATH) return L"";
    std::wstring full(buf, (size_t)n);
    size_t pos = full.find_last_of(L"\\/");
    if (pos == std::wstring::npos) return L"";
    return full.substr(0, pos);
}

static std::wstring Trim(const std::wstring& s) {
    size_t a = 0;
    while (a < s.size() && iswspace(s[a])) ++a;
    size_t b = s.size();
    while (b > a && iswspace(s[b - 1])) --b;
    return s.substr(a, b - a);
}

static bool iequals_substr(const std::wstring& s, const std::wstring& sub) {
    if (sub.empty() || s.size() < sub.size()) return false;
    std::wstring sl = s; std::transform(sl.begin(), sl.end(), sl.begin(), ::towlower);
    std::wstring subl = sub; std::transform(subl.begin(), subl.end(), subl.begin(), ::towlower);
    return sl.find(subl) != std::wstring::npos;
}

static std::wstring MakeFileVariant(const std::wstring& name, int variant)
{
    std::wstring out = name;
    if (variant == 2) {
        for (auto& c : out) if (c == L' ') c = L'_';
    }
    else if (variant == 3) {
        out.erase(std::remove(out.begin(), out.end(), L' '), out.end());
    }
    else if (variant == 4) {
        for (auto& c : out) {
            if (c == L' ') c = L'_';
            else if (iswpunct(c)) c = L'_';
            else c = towlower(c);
        }
    }
    std::wstring cleaned;
    for (wchar_t ch : out) {
        if (iswalnum(ch) || ch == L'_' || ch == L' ' || ch == L'-') cleaned.push_back(ch);
    }
    return cleaned;
}

// ----------------- image list / icons -------------------------------------

static void EnsureImageList(HWND hTree) {
    if (!g_hImgList) {
        const int iconSize = 24;
        g_hImgList = ImageList_Create(iconSize, iconSize, ILC_COLOR32 | ILC_MASK, 64, 16);
        TreeView_SetImageList(hTree, g_hImgList, TVSIL_NORMAL);
        TreeView_SetItemHeight(hTree, iconSize + 8);
    }
}

// Load app icon helper (tries embedded resource IDI_MANUTOOL then common paths)
static HICON LoadAppIconFromAssets(HINSTANCE hInst, const wchar_t* icoName, int cx, int cy)
{
#ifdef IDI_MANUTOOL
    HICON hRes = (HICON)LoadImageW(hInst, MAKEINTRESOURCEW(IDI_MANUTOOL), IMAGE_ICON, cx, cy, LR_DEFAULTCOLOR);
    if (hRes) return hRes;
#endif

    std::wstring exeDir = GetExeDir();
    std::vector<std::wstring> candidates;
    if (!exeDir.empty()) {
        candidates.push_back(exeDir + L"\\Assets\\Icons\\crafting\\" + icoName);
        candidates.push_back(exeDir + L"\\assets\\icons\\" + icoName);
    }
    candidates.push_back(std::wstring(L"Assets\\Icons\\crafting\\") + icoName);
    candidates.push_back(std::wstring(L"assets\\icons\\") + icoName);

    for (const auto& full : candidates) {
        if (GetFileAttributesW(full.c_str()) == INVALID_FILE_ATTRIBUTES) continue;
        HICON h = (HICON)LoadImageW(nullptr, full.c_str(), IMAGE_ICON, cx, cy, LR_LOADFROMFILE | LR_DEFAULTSIZE | LR_SHARED);
        if (h) return h;
    }
    return nullptr;
}

// Load individual item icons (cached)
static int LoadAndCacheIconForItem(const std::wstring& itemName, const std::wstring& category)
{
    if (!g_hImgList) return -1;

    // Prepare base search paths (working dir relative + exe dir variants)
    std::wstring exeDir = GetExeDir();
    std::wstring relCrafting = L"Assets\\Icons\\crafting\\";
    std::wstring basePaths[4];
    basePaths[0] = relCrafting;
    basePaths[1] = relCrafting + category + L"\\";
    if (!exeDir.empty()) {
        basePaths[2] = exeDir + L"\\" + relCrafting;
        basePaths[3] = exeDir + L"\\" + relCrafting + category + L"\\";
    }

    // Build candidate filenames (literal-preserving + normalized variants)
    std::vector<std::wstring> candidateNames;

    // literal-preserving variants
    std::wstring noSpaces = itemName;
    noSpaces.erase(std::remove(noSpaces.begin(), noSpaces.end(), L' '), noSpaces.end());
    candidateNames.push_back(noSpaces + L".ico");

    std::wstring underscores = itemName;
    for (auto& c : underscores) if (c == L' ') c = L'_';
    candidateNames.push_back(underscores + L".ico");

    std::wstring lowUnd = underscores;
    std::transform(lowUnd.begin(), lowUnd.end(), lowUnd.begin(), ::towlower);
    candidateNames.push_back(lowUnd + L".ico");

    std::wstring removedBracket = itemName;
    removedBracket.erase(std::remove(removedBracket.begin(), removedBracket.end(), L'['), removedBracket.end());
    removedBracket.erase(std::remove(removedBracket.begin(), removedBracket.end(), L']'), removedBracket.end());
    removedBracket.erase(std::remove(removedBracket.begin(), removedBracket.end(), L' '), removedBracket.end());
    candidateNames.push_back(removedBracket + L".ico");

    // canonical variants produced by MakeFileVariant
    for (int variant = 1; variant <= 4; ++variant) {
        std::wstring candidateBase = MakeFileVariant(itemName, variant);
        if (!candidateBase.empty()) candidateNames.push_back(candidateBase + L".ico");
    }

    // Remove duplicates while preserving order
    std::vector<std::wstring> uniqCandidates;
    std::unordered_set<std::wstring> seen; // <-- ensure <unordered_set> is included at top of file
    for (const auto& c : candidateNames) {
        if (seen.insert(c).second) uniqCandidates.push_back(c);
    }
    candidateNames.swap(uniqCandidates);

    // 1) Try disk-based loading for each candidate name in each base path
    for (const auto& fname : candidateNames) {
        for (const auto& p : basePaths) {
            if (p.empty()) continue;
            std::wstring full = p + fname;
            // Check cache by the exact full path
            auto it = g_iconIndexMap.find(full);
            if (it != g_iconIndexMap.end()) return it->second;

            // File exists?
            if (GetFileAttributesW(full.c_str()) == INVALID_FILE_ATTRIBUTES) continue;

            // Try load from file
            HICON hIcon = (HICON)LoadImageW(nullptr, full.c_str(), IMAGE_ICON, 24, 24, LR_LOADFROMFILE | LR_DEFAULTSIZE | LR_SHARED);
            if (!hIcon) continue;

            int idx = ImageList_AddIcon(g_hImgList, hIcon);
            g_iconIndexMap.emplace(full, idx);
            return idx;
        }
    }

    // 2) Disk lookup failed - try embedded resources.
    // Resource generator uses names like: icon_<SafeBasename> (safe: non-alnum -> underscore, prefixed with "icon_")
    HINSTANCE hInst = GetModuleHandleW(nullptr);
    for (const auto& fname : candidateNames) {
        // derive base filename (strip any path components; candidateNames are basenames already but be defensive)
        std::wstring base = fname;
        size_t slash = base.find_last_of(L"/\\");
        if (slash != std::wstring::npos) base = base.substr(slash + 1);

        // remove extension
        size_t dot = base.find_last_of(L'.');
        std::wstring nameNoExt = (dot == std::wstring::npos) ? base : base.substr(0, dot);

        // sanitize to match generator: replace non-alnum with '_' and prefix "icon_"
        std::wstring resName = L"icon_";
        for (wchar_t ch : nameNoExt) {
            if (iswalnum(ch) || ch == L'_') resName.push_back(ch);
            else resName.push_back(L'_');
        }

        // Check cache by resource key
        std::wstring resKey = L"resource:" + resName;
        auto itRes = g_iconIndexMap.find(resKey);
        if (itRes != g_iconIndexMap.end()) return itRes->second;

        // Try load embedded ICON resource by string name
        HICON hIcon = (HICON)LoadImageW(hInst, resName.c_str(), IMAGE_ICON, 24, 24, LR_DEFAULTCOLOR | LR_SHARED);
        if (!hIcon) {
            // also try with extension appended to resource name just in case generator used that form
            std::wstring resWithExt = resName + L".ico";
            hIcon = (HICON)LoadImageW(hInst, resWithExt.c_str(), IMAGE_ICON, 24, 24, LR_DEFAULTCOLOR | LR_SHARED);
        }

        if (hIcon) {
            int idx = ImageList_AddIcon(g_hImgList, hIcon);
            g_iconIndexMap.emplace(resKey, idx);
            return idx;
        }
    }

    // 3) Nothing found
    return -1;
}

// ----------------- embedded resource helpers -------------------------------

// Read RCDATA resource as UTF-8 string
static std::string ReadResourceAsUTF8String(HINSTANCE hInst, int resourceId)
{
    HRSRC hRes = FindResourceW(hInst, MAKEINTRESOURCEW(resourceId), RT_RCDATA);
    if (!hRes) return std::string();
    HGLOBAL hData = LoadResource(hInst, hRes);
    if (!hData) return std::string();
    DWORD size = SizeofResource(hInst, hRes);
    if (size == 0) return std::string();
    const char* p = static_cast<const char*>(LockResource(hData));
    if (!p) return std::string();
    return std::string(p, p + size);
}

// Convert UTF-8 -> UTF-16
static std::wstring Utf8ToW(const std::string& s)
{
    if (s.empty()) return std::wstring();
    int n = MultiByteToWideChar(CP_UTF8, 0, s.data(), (int)s.size(), nullptr, 0);
    if (n <= 0) return std::wstring();
    std::wstring w; w.resize(n);
    MultiByteToWideChar(CP_UTF8, 0, s.data(), (int)s.size(), &w[0], n);
    return w;
}

// Read embedded categories resource (IDR_CATEGORIES) expecting TSV: Category<TAB>Item per line
static std::vector<std::pair<std::wstring, std::vector<std::wstring>>> ReadCategoriesFromResource()
{
    std::vector<std::pair<std::wstring, std::vector<std::wstring>>> out;
#ifdef IDR_CATEGORIES
    HINSTANCE hInst = GetModuleHandleW(nullptr);
    std::string utf8 = ReadResourceAsUTF8String(hInst, IDR_CATEGORIES);
    if (utf8.empty()) return out;
    std::wstring content = Utf8ToW(utf8);
    std::wistringstream wss(content);
    std::wstring line;
    std::map<std::wstring, std::vector<std::wstring>> mapcat;
    while (std::getline(wss, line)) {
        if (!line.empty() && line.back() == L'\r') line.pop_back();
        if (line.empty()) continue;
        size_t tab = line.find(L'\t');
        if (tab == std::wstring::npos) continue;
        std::wstring cat = Trim(line.substr(0, tab));
        std::wstring item = Trim(line.substr(tab + 1));
        if (cat.empty() || item.empty()) continue;
        mapcat[cat].push_back(item);
    }
    for (auto& kv : mapcat) out.emplace_back(kv.first, kv.second);
#endif
    return out;
}

// ----------------- recipes loading (disk first, fallback to embedded) -----

bool load_recipes(const wchar_t* path) {
    g_recipes.clear();

    std::wstring content_w;
    std::wifstream fi(path);
    if (fi.is_open()) {
        std::wstringstream ss; ss << fi.rdbuf();
        content_w = ss.str();
    }
    else {
        HINSTANCE hInst = GetModuleHandleW(nullptr);
#ifdef IDR_RECIPES
        std::string utf8 = ReadResourceAsUTF8String(hInst, IDR_RECIPES);
        if (utf8.empty()) return false;
        content_w = Utf8ToW(utf8);
        if (content_w.empty()) return false;
#else
        return false;
#endif
    }

    auto push_recipe_from_lines = [&](const std::vector<std::wstring>& lines) {
        Recipe cur; cur.yield = 1;
        for (const auto& rawline : lines) {
            std::wstring line = rawline;
            while (!line.empty() && (line.back() == L'\r' || line.back() == L'\n')) line.pop_back();
            if (line.rfind(L"Name:", 0) == 0) {
                cur.name = line.substr(5);
                while (!cur.name.empty() && cur.name.front() == L' ') cur.name.erase(cur.name.begin());
            }
            else if (line.rfind(L"Yield:", 0) == 0) {
                std::wstring v = line.substr(6);
                while (!v.empty() && v.front() == L' ') v.erase(v.begin());
                cur.yield = (int)wcstol(v.c_str(), nullptr, 10);
            }
            else if (line.rfind(L"Input:", 0) == 0) {
                std::wstring v = line.substr(6);
                while (!v.empty() && v.front() == L' ') v.erase(v.begin());
                size_t p1 = v.find(L'|');
                size_t p2 = (p1 == std::wstring::npos) ? std::wstring::npos : v.find(L'|', p1 + 1);
                if (p1 != std::wstring::npos && p2 != std::wstring::npos) {
                    InputLine il;
                    il.type = (char)v[0];
                    il.name = v.substr(p1 + 1, p2 - (p1 + 1));
                    il.qty = (int)wcstol(v.substr(p2 + 1).c_str(), nullptr, 10);
                    cur.inputs.push_back(il);
                }
            }
        }
        if (!cur.name.empty()) g_recipes.push_back(std::move(cur));
        };

    std::vector<std::wstring> curBlock;
    std::wistringstream wss(content_w);
    std::wstring line;
    bool inRecipe = false;
    while (std::getline(wss, line)) {
        if (!line.empty() && line.back() == L'\r') line.pop_back();
        if (line == L"===RECIPE===") {
            if (inRecipe) push_recipe_from_lines(curBlock);
            curBlock.clear();
            inRecipe = true;
            continue;
        }
        if (!inRecipe) continue;
        curBlock.push_back(line);
    }
    if (inRecipe && !curBlock.empty()) push_recipe_from_lines(curBlock);

    return !g_recipes.empty();
}

static const Recipe* find_recipe_by_name(const std::wstring& name) {
    for (const auto& r : g_recipes) if (r.name == name) return &r;
    return nullptr;
}

// ----------------- Flattening logic --------------------------------------

static void accumulate_requirements_recursive(
    const std::wstring& recipeName,
    long long requestedQty,
    std::map<std::wstring, long long>& materials,
    std::set<std::wstring>& tools,
    std::set<std::wstring>& stack,
    std::vector<std::wstring>& warnings)
{
    if (stack.find(recipeName) != stack.end()) {
        warnings.push_back(L"Cycle detected with recipe: " + recipeName);
        return;
    }

    const Recipe* rec = find_recipe_by_name(recipeName);
    if (!rec) {
        materials[recipeName] += requestedQty;
        return;
    }

    int yield = rec->yield > 0 ? rec->yield : 1;
    long long batches = (requestedQty + yield - 1) / yield; // ceil

    stack.insert(recipeName);

    for (const auto& inp : rec->inputs) {
        if (inp.type == 'M') {
            long long add = batches * (long long)inp.qty;
            materials[inp.name] += add;
        }
        else if (inp.type == 'T') {
            if (inp.qty > 0) tools.insert(inp.name);
        }
        else if (inp.type == 'S') {
            long long subReq = batches * (long long)inp.qty;
            if (subReq <= 0) continue;
            accumulate_requirements_recursive(inp.name, subReq, materials, tools, stack, warnings);
        }
        else {
            long long add = batches * (long long)inp.qty;
            materials[inp.name] += add;
        }
    }

    stack.erase(recipeName);
}

static std::wstring FlattenAndFormatRequirements(const std::wstring& recipeName, long long quantity = 1)
{
    std::map<std::wstring, long long> materials;
    std::set<std::wstring> tools;
    std::set<std::wstring> stack;
    std::vector<std::wstring> warnings;

    accumulate_requirements_recursive(recipeName, quantity, materials, tools, stack, warnings);

    std::wstringstream ss;
    ss << L"Recipe: " << recipeName << L"\r\n";
    ss << L"Quantity: " << quantity << L"\r\n\r\n";

    if (!tools.empty()) {
        ss << L"Tools:\r\n";
        for (const auto& t : tools) ss << L"  - " << t << L"\r\n";
        ss << L"\r\n";
    }

    if (!materials.empty()) {
        ss << L"Materials:\r\n";
        for (const auto& kv : materials) ss << L"  - " << kv.first << L" x " << kv.second << L"\r\n";
        ss << L"\r\n";
    }
    else {
        ss << L"(no materials)\r\n\r\n";
    }

    if (!warnings.empty()) {
        ss << L"Warnings:\r\n";
        for (const auto& w : warnings) ss << L"  - " << w << L"\r\n";
        ss << L"\r\n";
    }

    return ss.str();
}

// ----------------- headers parsing & fallback --------------------------------

// Original header-scanning function (unchanged)
static std::vector<std::pair<std::wstring, std::vector<std::wstring>>> discover_categories_from_headers(const std::wstring& dirPath)
{
    std::vector<std::pair<std::wstring, std::vector<std::wstring>>> out;
    std::wstring pattern = dirPath;
    if (!pattern.empty() && (pattern.back() != L'\\' && pattern.back() != L'/')) pattern += L"\\";
    pattern += L"items*.h";

    WIN32_FIND_DATAW fd;
    HANDLE h = FindFirstFileW(pattern.c_str(), &fd);
    if (h == INVALID_HANDLE_VALUE) {
        pattern = dirPath;
        if (!pattern.empty() && (pattern.back() != L'\\' && pattern.back() != L'/')) pattern += L"\\";
        pattern += L"Items*.h";
        h = FindFirstFileW(pattern.c_str(), &fd);
        if (h == INVALID_HANDLE_VALUE) return out;
    }

    do {
        if (fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) continue;
        std::wstring filename = fd.cFileName;
        std::wstring stem = filename;
        size_t dot = stem.find_last_of(L'.');
        if (dot != std::wstring::npos) stem = stem.substr(0, dot);
        std::wstring cat;
        size_t us = stem.find(L'_');
        if (us != std::wstring::npos && us + 1 < stem.size()) cat = stem.substr(us + 1);
        else {
            std::wstring lower = stem; std::transform(lower.begin(), lower.end(), lower.begin(), ::towlower);
            if (lower.rfind(L"items", 0) == 0 && stem.size() > 5) cat = stem.substr(5);
            else cat = stem;
        }
        if (cat.empty()) cat = stem;

        std::wstring fullpath = dirPath;
        if (!fullpath.empty() && (fullpath.back() != L'\\' && fullpath.back() != L'/')) fullpath += L"\\";
        fullpath += filename;

        std::wifstream fi(fullpath);
        if (!fi.is_open()) continue;
        std::wstringstream ss; ss << fi.rdbuf();
        std::wstring content = ss.str();

        std::vector<std::wstring> items;
        size_t pos = 0;
        while (true) {
            size_t p = content.find(L"L\"", pos);
            if (p == std::wstring::npos) break;
            size_t q = p + 2;
            std::wstring buf;
            while (q < content.size()) {
                if (content[q] == L'"') break;
                buf.push_back(content[q]); ++q;
            }
            pos = q + 1;
            std::wstring name = Trim(buf);
            if (name.empty()) continue;
            if (iequals_substr(name, L"Base") || iequals_substr(name, L"Compound")) continue;
            if (std::find(items.begin(), items.end(), name) == items.end()) items.push_back(name);
        }
        if (!items.empty()) out.emplace_back(cat, std::move(items));
    } while (FindNextFileW(h, &fd));
    FindClose(h);
    return out;
}

// Wrapper: try header scan, if none found try embedded categories resource
static std::vector<std::pair<std::wstring, std::vector<std::wstring>>> discover_categories_with_fallback(const std::wstring& searchDir)
{
    auto fromHeaders = discover_categories_from_headers(searchDir);
    if (!fromHeaders.empty()) return fromHeaders;
    // fallback to embedded resource if present
#ifdef IDR_CATEGORIES
    auto fromResource = ReadCategoriesFromResource();
    if (!fromResource.empty()) return fromResource;
#endif
    // nothing found
    return {};
}

// ----------------- UI / theme functions -----------------------------------

static void ApplyTheme(HWND hWnd)
{
    if (!g_hbrDarkWnd) g_hbrDarkWnd = CreateSolidBrush(COL_DARK_BG);
    if (!g_hbrDarkEdit) g_hbrDarkEdit = CreateSolidBrush(COL_DARK_EDIT);

    if (hWnd) {
        BOOL val = g_darkMode ? TRUE : FALSE;
        HMODULE hDwm = LoadLibraryW(L"dwmapi.dll");
        if (hDwm) {
            typedef HRESULT(WINAPI* PFNDwmSetWindowAttribute)(HWND, DWORD, LPCVOID, DWORD);
            PFNDwmSetWindowAttribute pfn = (PFNDwmSetWindowAttribute)GetProcAddress(hDwm, "DwmSetWindowAttribute");
            if (pfn) {
                DWORD attr1 = 20; pfn(hWnd, attr1, &val, sizeof(val));
                DWORD attr2 = 19; pfn(hWnd, attr2, &val, sizeof(val));
            }
            FreeLibrary(hDwm);
        }
    }

    if (g_hTree) {
        if (g_darkMode) {
            TreeView_SetBkColor(g_hTree, COL_DARK_BG);
            TreeView_SetTextColor(g_hTree, COL_DARK_TEXT);
            TreeView_SetLineColor(g_hTree, RGB(80, 80, 80));
        }
        else {
            TreeView_SetBkColor(g_hTree, COLORREF(-1));
            TreeView_SetTextColor(g_hTree, COL_LIGHT_TEXT);
            TreeView_SetLineColor(g_hTree, COLORREF(-1));
        }
    }

    if (g_hDetails) InvalidateRect(g_hDetails, nullptr, TRUE);
    if (g_hTree) InvalidateRect(g_hTree, nullptr, TRUE);
    if (g_hQtyEdit) InvalidateRect(g_hQtyEdit, nullptr, TRUE);
    if (g_hHeader) InvalidateRect(g_hHeader, nullptr, TRUE);
    if (g_hQtyLabel) InvalidateRect(g_hQtyLabel, nullptr, TRUE);
    InvalidateRect(hWnd, nullptr, TRUE);
    UpdateWindow(hWnd);
}

static void CleanupThemeResources()
{
    if (g_hbrDarkWnd) { DeleteObject(g_hbrDarkWnd); g_hbrDarkWnd = nullptr; }
    if (g_hbrDarkEdit) { DeleteObject(g_hbrDarkEdit); g_hbrDarkEdit = nullptr; }
}

// ----------------- UI population & helpers --------------------------------

static void populate_tree_with_categories(HWND hTree, const std::vector<std::pair<std::wstring, std::vector<std::wstring>>>& cats) {
    TreeView_DeleteAllItems(hTree);
    EnsureImageList(hTree);

    TVINSERTSTRUCTW tvis{};
    for (const auto& kv : cats) {
        const std::wstring& category = kv.first;
        tvis.hParent = TVI_ROOT;
        tvis.hInsertAfter = TVI_LAST;

        TVITEMW catItem{};
        catItem.mask = TVIF_TEXT | TVIF_IMAGE | TVIF_SELECTEDIMAGE;
        catItem.pszText = const_cast<LPWSTR>(category.c_str());
        catItem.iImage = I_IMAGENONE;
        catItem.iSelectedImage = I_IMAGENONE;
        tvis.item = catItem;

        HTREEITEM hCat = (HTREEITEM)SendMessageW(hTree, TVM_INSERTITEMW, 0, (LPARAM)&tvis);

        for (const auto& name : kv.second) {
            TVINSERTSTRUCTW child{};
            child.hParent = hCat;
            child.hInsertAfter = TVI_LAST;

            TVITEMW cit{};
            cit.mask = TVIF_TEXT;

            int imgIndex = LoadAndCacheIconForItem(name, category);
            if (imgIndex >= 0) {
                cit.mask |= TVIF_IMAGE | TVIF_SELECTEDIMAGE;
                cit.iImage = imgIndex;
                cit.iSelectedImage = imgIndex;
            }

            cit.pszText = const_cast<LPWSTR>(name.c_str());
            child.item = cit;
            SendMessageW(hTree, TVM_INSERTITEMW, 0, (LPARAM)&child);
        }

        TreeView_Expand(hTree, hCat, TVE_COLLAPSE);
    }
}

static long long GetRequestedQuantity()
{
    if (!g_hQtyEdit) return 1;
    wchar_t buf[64]{};
    GetWindowTextW(g_hQtyEdit, buf, (int)_countof(buf));
    long long q = 0;
    if (buf[0] != L'\0') q = _wtoi64(buf);
    if (q <= 0) q = 1;
    return q;
}

static std::wstring GetSelectedTreeItemName()
{
    if (!g_hTree) return L"";
    HTREEITEM hSel = (HTREEITEM)SendMessageW(g_hTree, TVM_GETNEXTITEM, TVGN_CARET, 0);
    if (!hSel) return L"";
    TVITEMW it{};
    wchar_t buf[512]{};
    it.hItem = hSel;
    it.mask = TVIF_TEXT;
    it.pszText = buf;
    it.cchTextMax = _countof(buf);
    if (!TreeView_GetItem(g_hTree, &it)) return L"";
    return std::wstring(buf);
}

static void show_details_for_item(const std::wstring& name) {
    long long qty = GetRequestedQuantity();
    std::wstring out = FlattenAndFormatRequirements(name, qty);
    SetWindowTextW(g_hDetails, out.c_str());
}

// ----------------- Window procedure ---------------------------------------

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg) {
    case WM_CREATE: {
        HMENU hMenuBar = CreateMenu();

        HMENU hFile = CreatePopupMenu();
        AppendMenuW(hFile, MF_STRING, IDM_FILE_EXIT, L"Exit");
        AppendMenuW(hMenuBar, MF_POPUP, (UINT_PTR)hFile, L"File");

        HMENU hOptions = CreatePopupMenu();
        AppendMenuW(hOptions, MF_STRING, IDM_VIEW_DARKMODE, L"Dark Mode");
        AppendMenuW(hMenuBar, MF_POPUP, (UINT_PTR)hOptions, L"Options");

        HMENU hHelp = CreatePopupMenu();
        AppendMenuW(hHelp, MF_STRING, IDM_HELP_ABOUT, L"About");
        AppendMenuW(hMenuBar, MF_POPUP, (UINT_PTR)hHelp, L"Help");

        SetMenu(hWnd, hMenuBar);

        g_hHeader = CreateWindowW(L"STATIC", L"Select a recipe", WS_CHILD | WS_VISIBLE | SS_LEFT,
            10, 10, 300, 20, hWnd, (HMENU)IDC_HEADER, nullptr, nullptr);

        g_hQtyLabel = CreateWindowW(L"STATIC", L"Quantity", WS_CHILD | WS_VISIBLE | SS_LEFT,
            250, 10, 70, 20, hWnd, (HMENU)IDC_QTY_LABEL, nullptr, nullptr);

        g_hQtyEdit = CreateWindowW(L"EDIT", L"1",
            WS_CHILD | WS_VISIBLE | WS_BORDER | ES_NUMBER | ES_RIGHT,
            330, 8, 60, 22, hWnd, (HMENU)IDC_QTY_EDIT, nullptr, nullptr);

        g_hQtySpin = CreateWindowExW(0, UPDOWN_CLASSW, nullptr,
            WS_CHILD | WS_VISIBLE | UDS_ALIGNRIGHT | UDS_SETBUDDYINT | UDS_ARROWKEYS,
            392, 8, 16, 22, hWnd, (HMENU)IDC_QTY_SPIN, nullptr, nullptr);

        if (g_hQtySpin && g_hQtyEdit) {
            SendMessageW(g_hQtySpin, UDM_SETBUDDY, (WPARAM)g_hQtyEdit, 0);
            SendMessageW(g_hQtySpin, UDM_SETRANGE32, (WPARAM)1, (LPARAM)1000000);
            SendMessageW(g_hQtySpin, UDM_SETPOS32, 0, (LPARAM)1);
        }

        g_hTree = CreateWindowExW(WS_EX_CLIENTEDGE, WC_TREEVIEWW, L"",
            WS_CHILD | WS_VISIBLE | TVS_HASBUTTONS | TVS_LINESATROOT | TVS_SHOWSELALWAYS,
            10, 35, 320, 400, hWnd, (HMENU)TV_ID, nullptr, nullptr);

        g_hDetails = CreateWindowW(L"EDIT", nullptr,
            WS_CHILD | WS_VISIBLE | ES_MULTILINE | ES_AUTOVSCROLL | ES_READONLY | WS_BORDER | WS_VSCROLL,
            340, 35, 380, 400, hWnd, (HMENU)EDIT_ID, nullptr, nullptr);

        // Discover categories: try ManuTool folder first, else embedded resource
        std::wstring searchDir = L"ManuTool";
        std::wstring exeDir = GetExeDir();
        std::wstring alt = exeDir;
        if (!alt.empty() && (alt.back() != L'\\' && alt.back() != L'/')) alt += L"\\";
        alt += L"ManuTool";

        WIN32_FIND_DATAW fd;
        std::wstring probe = searchDir + L"\\*";
        bool found = (FindFirstFileW(probe.c_str(), &fd) != INVALID_HANDLE_VALUE);
        if (!found) {
            probe = alt + L"\\*";
            if (FindFirstFileW(probe.c_str(), &fd) != INVALID_HANDLE_VALUE) searchDir = alt;
        }

        auto cats = discover_categories_with_fallback(searchDir);
        populate_tree_with_categories(g_hTree, cats);

        ApplyTheme(hWnd);

        HMENU hm = GetMenu(hWnd);
        if (hm) CheckMenuItem(hm, IDM_VIEW_DARKMODE, MF_BYCOMMAND | (g_darkMode ? MF_CHECKED : MF_UNCHECKED));
        break;
    }

    case WM_COMMAND:
        if (HIWORD(wParam) == EN_CHANGE && LOWORD(wParam) == IDC_QTY_EDIT) {
            std::wstring sel = GetSelectedTreeItemName();
            if (!sel.empty()) show_details_for_item(sel);
        }

        switch (LOWORD(wParam)) {
        case IDM_FILE_EXIT:
            DestroyWindow(hWnd);
            return 0;
        case IDM_HELP_ABOUT:
            MessageBoxW(hWnd,
                L"GoonZu Manufacturing Tool\nVersion: 0.1\nAuthor: itsGir",
                L"About GoonZu Manufacturing Tool", MB_OK | MB_ICONINFORMATION);
            return 0;
        case IDM_VIEW_DARKMODE:
            g_darkMode = !g_darkMode;
            {
                HMENU hm = GetMenu(hWnd);
                if (hm) CheckMenuItem(hm, IDM_VIEW_DARKMODE, MF_BYCOMMAND | (g_darkMode ? MF_CHECKED : MF_UNCHECKED));
            }
            ApplyTheme(hWnd);
            return 0;
        default:
            break;
        }
        break;

    case WM_NOTIFY: {
        NMHDR* nm = (NMHDR*)lParam;
        if (nm->hwndFrom == g_hQtySpin && nm->code == UDN_DELTAPOS) {
            std::wstring sel = GetSelectedTreeItemName();
            if (!sel.empty()) show_details_for_item(sel);
            return 0;
        }
        if (nm->hwndFrom == g_hTree && nm->code == TVN_SELCHANGEDW) {
            NMTREEVIEWW* ntv = (NMTREEVIEWW*)lParam;
            HTREEITEM sel = ntv->itemNew.hItem;
            if (!sel) break;
            TVITEMW tvi{};
            wchar_t textbuf[512]{};
            tvi.hItem = sel;
            tvi.mask = TVIF_CHILDREN | TVIF_TEXT;
            tvi.pszText = textbuf;
            tvi.cchTextMax = _countof(textbuf);
            if (TreeView_GetItem(g_hTree, &tvi)) {
                if (tvi.cChildren > 0) {
                    UINT state = TreeView_GetItemState(g_hTree, sel, TVIS_EXPANDED);
                    if (state & TVIS_EXPANDED) TreeView_Expand(g_hTree, sel, TVE_COLLAPSE);
                    else TreeView_Expand(g_hTree, sel, TVE_EXPAND);
                    return 0;
                }
                else {
                    show_details_for_item(textbuf);
                    return 0;
                }
            }
            else {
                TVITEMW it{}; wchar_t tmp[512]{};
                it.hItem = sel; it.mask = TVIF_TEXT; it.pszText = tmp; it.cchTextMax = _countof(tmp);
                SendMessageW(g_hTree, TVM_GETITEMW, 0, (LPARAM)&it);
                show_details_for_item(tmp);
                return 0;
            }
        }
        break;
    }

    case WM_CTLCOLORSTATIC: {
        HDC hdc = (HDC)wParam;
        if (g_darkMode) {
            SetTextColor(hdc, COL_DARK_TEXT);
            SetBkMode(hdc, TRANSPARENT);
            if (!g_hbrDarkWnd) g_hbrDarkWnd = CreateSolidBrush(COL_DARK_BG);
            return (LRESULT)g_hbrDarkWnd;
        }
        else {
            SetTextColor(hdc, COL_LIGHT_TEXT);
            SetBkMode(hdc, TRANSPARENT);
            return (LRESULT)GetSysColorBrush(COLOR_WINDOW);
        }
    }

    case WM_CTLCOLOREDIT: {
        HDC hdc = (HDC)wParam;
        if (g_darkMode) {
            SetTextColor(hdc, COL_DARK_TEXT);
            SetBkColor(hdc, COL_DARK_EDIT);
            if (!g_hbrDarkEdit) g_hbrDarkEdit = CreateSolidBrush(COL_DARK_EDIT);
            return (LRESULT)g_hbrDarkEdit;
        }
        else {
            SetTextColor(hdc, COL_LIGHT_TEXT);
            SetBkColor(hdc, COL_LIGHT_BG);
            return (LRESULT)GetSysColorBrush(COLOR_WINDOW);
        }
    }

    case WM_ERASEBKGND: {
        HDC hdc = (HDC)wParam;
        RECT rc; GetClientRect(hWnd, &rc);
        if (g_darkMode) {
            if (!g_hbrDarkWnd) g_hbrDarkWnd = CreateSolidBrush(COL_DARK_BG);
            FillRect(hdc, &rc, g_hbrDarkWnd);
            return 1;
        }
        else {
            HBRUSH hbr = GetSysColorBrush(COLOR_WINDOW);
            FillRect(hdc, &rc, hbr);
            return 1;
        }
    }

    case WM_SIZE: {
        RECT rc; GetClientRect(hWnd, &rc);
        MoveWindow(g_hHeader, 10, 10, 300, 20, TRUE);
        MoveWindow(g_hQtyLabel, 250, 10, 70, 20, TRUE);
        MoveWindow(g_hQtyEdit, 330, 8, 60, 22, TRUE);
        MoveWindow(g_hQtySpin, 392, 8, 16, 22, TRUE);
        int treeW = 340;
        MoveWindow(g_hTree, 10, 35, treeW - 20, rc.bottom - 45, TRUE);
        MoveWindow(g_hDetails, treeW + 10, 35, rc.right - (treeW + 20), rc.bottom - 45, TRUE);
        break;
    }

    case WM_DESTROY:
        if (g_hImgList) { ImageList_Destroy(g_hImgList); g_hImgList = nullptr; }
        CleanupThemeResources();
        PostQuitMessage(0);
        return 0;
    }

    return DefWindowProcW(hWnd, msg, wParam, lParam);
}

// ----------------- main ----------------------------------------------------

int WINAPI wWinMain(HINSTANCE hInst, HINSTANCE, PWSTR, int nCmdShow) {
    INITCOMMONCONTROLSEX icc{ sizeof(icc), ICC_TREEVIEW_CLASSES | ICC_STANDARD_CLASSES | ICC_UPDOWN_CLASS };
    InitCommonControlsEx(&icc);

    const wchar_t* recipePath = L"data/recipes.txt";
    if (!load_recipes(recipePath)) {
        // With embedded fallback there will be no popup unless both disk and resource are missing.
        MessageBoxW(nullptr, L"No recipes found in data/recipes.txt and no embedded recipes resource found.", L"No recipes", MB_OK | MB_ICONINFORMATION);
    }

    // Load app icons (tries embedded resource IDI_MANUTOOL then files)
    g_hIconLarge = LoadAppIconFromAssets(hInst, L"EvilRaccoonHammer.ico", 32, 32);
    g_hIconSmall = LoadAppIconFromAssets(hInst, L"EvilRaccoonHammer.ico", 16, 16);
    if (!g_hIconLarge) g_hIconLarge = (HICON)LoadIconW(nullptr, IDI_APPLICATION);
    if (!g_hIconSmall) g_hIconSmall = g_hIconLarge;

    WNDCLASSEXW wcx{}; wcx.cbSize = sizeof(wcx);
    wcx.lpfnWndProc = WndProc;
    wcx.hInstance = hInst;
    wcx.lpszClassName = L"ManuToolMinimal";
    wcx.hIcon = g_hIconLarge;
    wcx.hIconSm = g_hIconSmall;
    wcx.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wcx.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    RegisterClassExW(&wcx);

    HWND hWnd = CreateWindowW(wcx.lpszClassName, L"GoonZu Manufacturing Tool v0.1",
        WS_OVERLAPPEDWINDOW | WS_VISIBLE, CW_USEDEFAULT, CW_USEDEFAULT, 900, 600,
        nullptr, nullptr, hInst, nullptr);

    if (g_hIconLarge) SendMessageW(hWnd, WM_SETICON, ICON_BIG, (LPARAM)g_hIconLarge);
    if (g_hIconSmall) SendMessageW(hWnd, WM_SETICON, ICON_SMALL, (LPARAM)g_hIconSmall);

    ShowWindow(hWnd, nCmdShow);

    MSG msg;
    while (GetMessageW(&msg, nullptr, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessageW(&msg);
    }
    return 0;
}