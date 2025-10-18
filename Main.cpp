// Minimal Win32 GUI that loads data/recipes.txt (simple format) and displays recipes.
// This is intentionally small and dependency-free. Build with CMake (Visual Studio).

#include <windows.h>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

struct InputLine { char type; std::wstring name; int qty; };
struct Recipe { std::wstring name; int yield; std::vector<InputLine> inputs; };

static std::vector<Recipe> g_recipes;
static HWND g_hList = nullptr;
static HWND g_hDetails = nullptr;

std::wstring to_w(const std::string& s) {
    int n = MultiByteToWideChar(CP_UTF8, 0, s.c_str(), -1, nullptr, 0);
    std::wstring w; w.resize(n);
    MultiByteToWideChar(CP_UTF8, 0, s.c_str(), -1, &w[0], n);
    if (!w.empty()) w.pop_back();
    return w;
}

bool load_recipes(const wchar_t* path) {
    g_recipes.clear();
    std::wifstream fi(path);
    if (!fi.is_open()) return false;
    std::wstring line;
    Recipe cur;
    bool inRecipe = false;
    while (std::getline(fi, line)) {
        // trim
        while (!line.empty() && (line.back() == L'\r' || line.back() == L'\n')) line.pop_back();
        if (line == L"===RECIPE===") {
            if (inRecipe) g_recipes.push_back(cur);
            cur = Recipe{};
            cur.yield = 1;
            inRecipe = true;
            continue;
        }
        if (!inRecipe) continue;
        if (line.rfind(L"Name:", 0) == 0) {
            cur.name = line.substr(5);
            while (!cur.name.empty() && cur.name.front() == L' ') cur.name.erase(cur.name.begin());
        }
        else if (line.rfind(L"Yield:", 0) == 0) {
            std::wstring v = line.substr(6);
            while (!v.empty() && v.front() == L' ') v.erase(v.begin());
            cur.yield = wcstol(v.c_str(), nullptr, 10);
        }
        else if (line.rfind(L"Input:", 0) == 0) {
            std::wstring v = line.substr(6);
            while (!v.empty() && v.front() == L' ') v.erase(v.begin());
            // format: X|Name|Qty
            size_t p1 = v.find(L'|');
            size_t p2 = (p1 == std::wstring::npos) ? std::wstring::npos : v.find(L'|', p1 + 1);
            if (p1 != std::wstring::npos && p2 != std::wstring::npos) {
                InputLine il;
                il.type = (char)v[0];
                il.name = v.substr(p1 + 1, p2 - (p1 + 1));
                il.qty = wcstol(v.substr(p2 + 1).c_str(), nullptr, 10);
                cur.inputs.push_back(il);
            }
        }
    }
    if (inRecipe) g_recipes.push_back(cur);
    return !g_recipes.empty();
}

void populate_list() {
    if (!g_hList) return;
    SendMessageW(g_hList, LB_RESETCONTENT, 0, 0);
    for (size_t i = 0; i < g_recipes.size(); ++i) {
        SendMessageW(g_hList, LB_ADDSTRING, 0, (LPARAM)g_recipes[i].name.c_str());
    }
}

void show_recipe_details(int idx) {
    if (!g_hDetails) return;
    std::wstring txt;
    if (idx >= 0 && idx < (int)g_recipes.size()) {
        const Recipe& r = g_recipes[idx];
        txt = L"Recipe: " + r.name + L"\r\nYield: " + std::to_wstring(r.yield) + L"\r\n\r\n";
        for (auto& in : r.inputs) {
            std::wstring typ = (in.type == 'M') ? L"Material" : (in.type == 'T') ? L"Tool" : L"Sub";
            txt += typ + L": " + in.name + L" x " + std::to_wstring(in.qty) + L"\r\n";
        }
    }
    else {
        txt = L"(no recipe)";
    }
    SetWindowTextW(g_hDetails, txt.c_str());
}

// Simple window
LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg) {
    case WM_CREATE: {
        // Listbox left
        g_hList = CreateWindowW(L"LISTBOX", nullptr, WS_CHILD | WS_VISIBLE | LBS_NOTIFY | WS_VSCROLL,
            10, 10, 280, 400, hWnd, (HMENU)1001, nullptr, nullptr);
        // Details right (multiline readonly edit)
        g_hDetails = CreateWindowW(L"EDIT", nullptr, WS_CHILD | WS_VISIBLE | ES_MULTILINE | ES_AUTOVSCROLL | ES_READONLY | WS_BORDER | WS_VSCROLL,
            300, 10, 380, 400, hWnd, (HMENU)1002, nullptr, nullptr);
        populate_list();
        break;
    }
    case WM_COMMAND:
        if (HIWORD(wParam) == LBN_SELCHANGE && LOWORD(wParam) == 1001) {
            int sel = (int)SendMessageW(g_hList, LB_GETCURSEL, 0, 0);
            show_recipe_details(sel);
        }
        break;
    case WM_SIZE: {
        RECT rc; GetClientRect(hWnd, &rc);
        MoveWindow(g_hList, 10, 10, 280, rc.bottom - 20, TRUE);
        MoveWindow(g_hDetails, 300, 10, rc.right - 310, rc.bottom - 20, TRUE);
        break;
    }
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProcW(hWnd, msg, wParam, lParam);
}

int WINAPI wWinMain(HINSTANCE hInst, HINSTANCE, PWSTR, int nCmdShow) {
    // load recipes from data/recipes.txt
    const wchar_t* recipePath = L"data/recipes.txt";
    wchar_t buf[512];
    if (!load_recipes(recipePath)) {
        MessageBoxW(nullptr, L"No recipes found in data/recipes.txt. Run scripts/extract_recipes.py first.", L"No recipes", MB_OK | MB_ICONINFORMATION);
    }

    WNDCLASSW wc = {};
    wc.lpfnWndProc = WndProc;
    wc.hInstance = hInst;
    wc.lpszClassName = L"ManuToolMinimal";
    RegisterClassW(&wc);

    HWND hWnd = CreateWindowW(wc.lpszClassName, L"ManuTool (minimal)", WS_OVERLAPPEDWINDOW | WS_VISIBLE,
        CW_USEDEFAULT, CW_USEDEFAULT, 720, 480, nullptr, nullptr, hInst, nullptr);

    ShowWindow(hWnd, nCmdShow);

    MSG msg;
    while (GetMessageW(&msg, nullptr, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessageW(&msg);
    }
    return 0;
}