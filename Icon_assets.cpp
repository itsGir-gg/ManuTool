#include "icon_assets.h"
#include <windows.h>
#include <string>
#include <vector>

// Helper: get directory of current executable (no trailing slash)
static std::wstring GetExeDir()
{
    wchar_t buf[MAX_PATH];
    DWORD n = GetModuleFileNameW(nullptr, buf, _countof(buf));
    if (n == 0 || n == _countof(buf)) return {};
    std::wstring full(buf, n);
    size_t pos = full.find_last_of(L"\\/");
    if (pos == std::wstring::npos) return L".";
    return full.substr(0, pos);
}

// Helper: try loading an icon from a full path (tries with and without ".ico")
static HICON TryLoadFromPath(const std::wstring& fullpath, int cx = 24, int cy = 24)
{
    if (fullpath.empty()) return nullptr;
    // try exact path first
    HICON h = (HICON)LoadImageW(nullptr, fullpath.c_str(), IMAGE_ICON, cx, cy, LR_LOADFROMFILE | LR_DEFAULTSIZE | LR_SHARED);
    if (h) return h;

    // try adding .ico if missing
    if (fullpath.size() >= 4 && fullpath.substr(fullpath.size() - 4) == L".ico") return nullptr;
    std::wstring withExt = fullpath + L".ico";
    h = (HICON)LoadImageW(nullptr, withExt.c_str(), IMAGE_ICON, cx, cy, LR_LOADFROMFILE | LR_DEFAULTSIZE | LR_SHARED);
    return h;
}

// Main string-based loader (filesystem-first)
HICON LoadAppIconFromAssets(const std::wstring& nameOrPath)
{
    if (nameOrPath.empty()) return nullptr;

    // If it looks like an absolute or relative path (contains slash or backslash), try that first
    bool hasSlash = (nameOrPath.find(L'\\') != std::wstring::npos) || (nameOrPath.find(L'/') != std::wstring::npos);
    if (hasSlash) {
        // Try as given
        HICON h = TryLoadFromPath(nameOrPath, 24, 24);
        if (h) return h;

        // Try exe directory + given
        std::wstring exeDir = GetExeDir();
        if (!exeDir.empty()) {
            std::wstring joined = exeDir + L"\\" + nameOrPath;
            h = TryLoadFromPath(joined, 24, 24);
            if (h) return h;
        }
    }

    // Normalize name: convert forward slashes to backslashes
    std::wstring name = nameOrPath;
    for (auto& c : name) if (c == L'/') c = L'\\';

    std::wstring exeDir = GetExeDir();
    std::vector<std::wstring> candidates;

    // Candidate: exeDir\name
    if (!exeDir.empty()) candidates.push_back(exeDir + L"\\" + name);

    // Candidate: name (in current working dir)
    candidates.push_back(name);

    // Candidate: Assets\Icons\{name}
    candidates.push_back(L"Assets\\Icons\\" + name);
    // Candidate: Assets\Icons\crafting\{name}
    candidates.push_back(L"Assets\\Icons\\crafting\\" + name);

    // Candidate: try removing extension if present, then append .ico later in TryLoadFromPath
    size_t dot = name.find_last_of(L'.');
    if (dot != std::wstring::npos) {
        std::wstring base = name.substr(0, dot);
        if (!exeDir.empty()) candidates.push_back(exeDir + L"\\" + base);
        candidates.push_back(base);
        candidates.push_back(L"Assets\\Icons\\" + base);
        candidates.push_back(L"Assets\\Icons\\crafting\\" + base);
    }

    // Try each candidate
    for (const auto& c : candidates) {
        HICON h = TryLoadFromPath(c, 24, 24);
        if (h) return h;
    }

    // Not found
    return nullptr;
}

// Resource-aware overload: first try module resources, then fallback to filesystem candidates
HICON LoadAppIconFromAssets(HINSTANCE hInst, LPCWSTR nameOrId, int cx /*=24*/, int cy /*=24*/)
{
    if (hInst != nullptr && nameOrId != nullptr) {
        // Try loading resource directly from module - supports MAKEINTRESOURCE(ID) and string names
        HICON h = (HICON)LoadImageW(hInst, nameOrId, IMAGE_ICON, cx, cy, LR_DEFAULTCOLOR | LR_SHARED);
        if (h) return h;

        // Try RT_GROUP_ICON lookup and fallback
        HRSRC hResGroup = FindResourceW(hInst, nameOrId, RT_GROUP_ICON);
        if (!hResGroup) {
            // Try with ".ico" appended name (if nameOrId is a string)
            // If nameOrId is MAKEINTRESOURCE, this will likely fail quickly and fall through to filesystem tries.
            std::wstring maybeName;
            if (((ULONG_PTR)nameOrId) > 0xFFFF) { // heuristic: treat as string if pointer values are large (not MAKEINTRESOURCE)
                maybeName = std::wstring(nameOrId);
                HRSRC hResGroup2 = FindResourceW(hInst, maybeName.c_str(), RT_GROUP_ICON);
                if (hResGroup2) hResGroup = hResGroup2;
                else {
                    maybeName += L".ico";
                    HRSRC hResGroup3 = FindResourceW(hInst, maybeName.c_str(), RT_GROUP_ICON);
                    if (hResGroup3) hResGroup = hResGroup3;
                }
            }
        }
        if (hResGroup) {
            // If we found group icon, try LoadImage again (some systems need this)
            HICON h2 = (HICON)LoadImageW(hInst, nameOrId, IMAGE_ICON, cx, cy, LR_DEFAULTCOLOR | LR_SHARED);
            if (h2) return h2;
        }
    }

    // If we get here, resource loading failed or was not attempted; fall back to filesystem-like behavior.
    // Convert nameOrId to a std::wstring when possible and call the string overload.
    if (nameOrId && ((ULONG_PTR)nameOrId) > 0xFFFF) {
        // nameOrId is likely a pointer to a string
        std::wstring s(nameOrId);
        // Try filesystem candidates with requested size
        // Small helper: reuse TryLoadFromPath with requested size
        // Try direct candidates similar to string overload but with cx/cy
        bool hasSlash = (s.find(L'\\') != std::wstring::npos) || (s.find(L'/') != std::wstring::npos);
        if (hasSlash) {
            HICON h = TryLoadFromPath(s, cx, cy);
            if (h) return h;
            std::wstring exeDir = GetExeDir();
            if (!exeDir.empty()) {
                std::wstring joined = exeDir + L"\\" + s;
                h = TryLoadFromPath(joined, cx, cy);
                if (h) return h;
            }
        }
        // Build same candidate list
        std::wstring name = s;
        for (auto& c : name) if (c == L'/') c = L'\\';
        std::wstring exeDir = GetExeDir();
        std::vector<std::wstring> candidates;
        if (!exeDir.empty()) candidates.push_back(exeDir + L"\\" + name);
        candidates.push_back(name);
        candidates.push_back(L"Assets\\Icons\\" + name);
        candidates.push_back(L"Assets\\Icons\\crafting\\" + name);
        size_t dot = name.find_last_of(L'.');
        if (dot != std::wstring::npos) {
            std::wstring base = name.substr(0, dot);
            if (!exeDir.empty()) candidates.push_back(exeDir + L"\\" + base);
            candidates.push_back(base);
            candidates.push_back(L"Assets\\Icons\\" + base);
            candidates.push_back(L"Assets\\Icons\\crafting\\" + base);
        }
        for (const auto& c : candidates) {
            HICON h = TryLoadFromPath(c, cx, cy);
            if (h) return h;
        }
    }

    // If nameOrId is MAKEINTRESOURCE (numeric) or nothing matched, return nullptr.
    return nullptr;
}