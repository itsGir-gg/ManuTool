#include "icon_logging.h"
#include <fstream>
#include <sstream>
#include <windows.h>

// Simple Create directory helper (best-effort)
static void EnsureDataDirectoryExists()
{
    // Try CreateDirectoryW - if it already exists, GetLastError returns ERROR_ALREADY_EXISTS.
    // Use a simple path relative to the EXE: "data"
    LPCWSTR dir = L"data";
    if (!CreateDirectoryW(dir, nullptr)) {
        DWORD err = GetLastError();
        if (err != ERROR_ALREADY_EXISTS) {
            // ignore other errors - logging is best-effort
        }
    }
}

static std::wstring GetTimestampW()
{
    std::wstringstream ss;
    SYSTEMTIME st;
    GetLocalTime(&st);
    ss << st.wYear << L"-"
        << (st.wMonth < 10 ? L"0" : L"") << st.wMonth << L"-"
        << (st.wDay < 10 ? L"0" : L"") << st.wDay << L" "
        << (st.wHour < 10 ? L"0" : L"") << st.wHour << L":"
        << (st.wMinute < 10 ? L"0" : L"") << st.wMinute << L":"
        << (st.wSecond < 10 ? L"0" : L"") << st.wSecond;
    return ss.str();
}

void UILogW(const std::wstring& msg)
{
    try {
        EnsureDataDirectoryExists();
        std::wofstream of(L"data\\icon_ui.log", std::ios::app);
        if (!of) return;
        of << L"[" << GetTimestampW() << L"] " << msg << L"\n";
    }
    catch (...) {
        // best-effort logging, swallow any exceptions
    }
}

void LogImageListInfo(HIMAGELIST hImgList, const std::wstring& context)
{
    if (!hImgList) {
        UILogW(context + L": ImageList handle is NULL");
        return;
    }

    int count = ImageList_GetImageCount(hImgList);
    UILogW(context + L": ImageList count=" + std::to_wstring(count));

    int toDump = (count < 5) ? count : 5;
    for (int i = 0; i < toDump; ++i) {
        HICON h = ImageList_GetIcon(hImgList, i, ILD_NORMAL);
        intptr_t handleInt = (intptr_t)h;
        UILogW(context + L": ImageList icon[" + std::to_wstring(i) + L"] handle=" + std::to_wstring(handleInt));
        if (h) DestroyIcon(h); // ImageList_GetIcon returns a copied handle; free it
    }
}