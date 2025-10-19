#include "icon_logging.h"
#include <windows.h>

// No-op logging to avoid startup I/O overhead.
// Keeps the API so all existing calls compile unchanged.

void UILogW(const std::wstring& /*msg*/)
{
    // logging disabled
}

void LogImageListInfo(HIMAGELIST /*hImgList*/, const std::wstring& /*context*/)
{
    // logging disabled
}