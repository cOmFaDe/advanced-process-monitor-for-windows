#pragma once
#include <string>
#include <Windows.h>

struct ProcessInfo {
    std::wstring name;
    DWORD pid;
    DWORD threadCount;
};
