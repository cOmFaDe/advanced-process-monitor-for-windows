#include "table.h"
#include <thread>
#include <chrono>
#include <mutex>
#include "../Platform/ProcessManager.h"

std::vector<ProcessInfo> ProcessList;
std::mutex processMutex;
bool running = true;
bool threadStarted = false;
std::thread updateThread;

void updateProcessThread() {
    while (running) {
        ProcessManager pm;
        auto list = pm.GetProcessList();

        {
            std::lock_guard<std::mutex> lock(processMutex);
            ProcessList = list;
        }

        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

void StartUpdateThread() {
    if (!threadStarted) {
        threadStarted = true;
        updateThread = std::thread(updateProcessThread);
        updateThread.detach();
    }
}

void drawTable() {
    static char filtro[64] = "";
    ImGui::InputTextWithHint("##search", "Buscar processo...", filtro, IM_ARRAYSIZE(filtro));

    if (ImGui::BeginTable("ProcessTable", 3, ImGuiTableFlags_RowBg | ImGuiTableFlags_BordersInnerV | ImGuiTableFlags_Resizable | ImGuiTableFlags_ScrollY)) {
        ImGui::TableSetupColumn("PID");
        ImGui::TableSetupColumn("Nome");
        ImGui::TableSetupColumn("Threads");
        ImGui::TableHeadersRow();

        std::lock_guard<std::mutex> lock(processMutex);
        for (const auto& proc : ProcessList) {
            std::wstring wname = proc.name;
            std::string name(wname.begin(), wname.end());

            if (strlen(filtro) > 0 && name.find(filtro) == std::string::npos)
                continue;

            ImGui::TableNextRow();
            ImGui::TableNextColumn(); ImGui::Text("%lu", proc.pid);
            ImGui::TableNextColumn(); ImGui::Text("%ls", proc.name.c_str());
            ImGui::TableNextColumn(); ImGui::Text("%u", proc.threadCount);
        }

        ImGui::EndTable();
    }
}