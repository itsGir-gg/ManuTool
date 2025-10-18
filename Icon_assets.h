#pragma once

#include <windows.h>
#include <string>

// Attempts to load an HICON given either a path or a logical asset name.
// Returns an HICON on success (caller should NOT DestroyIcon the returned handle
// if the icon was loaded with LR_SHARED), or nullptr on failure.
//
// Overloads:
//  - LoadAppIconFromAssets(const std::wstring& nameOrPath)
//      Tries file-system locations (path, exe-dir, Assets\Icons, etc.)
//
//  - LoadAppIconFromAssets(HINSTANCE hInst, LPCWSTR nameOrId, int cx = 24, int cy = 24)
//      Tries to load from the given module's resources (nameOrId may be MAKEINTRESOURCE(id))
//      or falls back to the same file-system candidates as the string overload.
HICON LoadAppIconFromAssets(const std::wstring& nameOrPath);
HICON LoadAppIconFromAssets(HINSTANCE hInst, LPCWSTR nameOrId, int cx = 24, int cy = 24);