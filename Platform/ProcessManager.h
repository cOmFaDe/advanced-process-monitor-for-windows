#pragma once
#include "ProcessInfo.h"
#include <vector>

class ProcessManager {
public:
    std::vector<ProcessInfo> GetProcessList();
};
