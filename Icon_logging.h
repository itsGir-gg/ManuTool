#pragma once

#include <string>
#include <windows.h>
#include <commctrl.h>

void UILogW(const std::wstring& msg);
void LogImageListInfo(HIMAGELIST hImgList, const std::wstring& context);