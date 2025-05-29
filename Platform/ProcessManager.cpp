#include "ProcessManager.h"
#include <Windows.h>
#include <winternl.h>
#include <iostream>
#ifndef STATUS_INFO_LENGTH_MISMATCH
#define STATUS_INFO_LENGTH_MISMATCH ((NTSTATUS)0xC0000004)
#endif

typedef NTSTATUS(WINAPI* PNtQuerySystemInformation)(
    SYSTEM_INFORMATION_CLASS, PVOID, ULONG, PULONG);

std::vector<ProcessInfo> ProcessManager::GetProcessList() {
    std::vector<ProcessInfo> processList;

    HMODULE hNtDll = GetModuleHandleA("ntdll.dll");
    if (!hNtDll) return processList;

    auto NtQuerySystemInformation = reinterpret_cast<PNtQuerySystemInformation>(
        GetProcAddress(hNtDll, "NtQuerySystemInformation"));
    if (!NtQuerySystemInformation) return processList;

    ULONG bufferSize = 0x10000;
    std::vector<BYTE> buffer(bufferSize);
    NTSTATUS status;

    while ((status = NtQuerySystemInformation(SystemProcessInformation,
        buffer.data(), bufferSize, &bufferSize)) == STATUS_INFO_LENGTH_MISMATCH) {
        buffer.resize(bufferSize);
    }

    if (status != 0) return processList;

    auto* spi = reinterpret_cast<SYSTEM_PROCESS_INFORMATION*>(buffer.data());

    while (true) {
        ProcessInfo info;
        info.pid = static_cast<DWORD>(reinterpret_cast<ULONG_PTR>(spi->UniqueProcessId));
        info.threadCount = spi->NumberOfThreads;
        info.name = spi->ImageName.Buffer ?
            std::wstring(spi->ImageName.Buffer, spi->ImageName.Length / sizeof(WCHAR)) :
            L"(Sistema)";

        processList.push_back(info);

        if (!spi->NextEntryOffset) break;

        spi = reinterpret_cast<SYSTEM_PROCESS_INFORMATION*>(
            reinterpret_cast<BYTE*>(spi) + spi->NextEntryOffset);
    }

    return processList;
}
