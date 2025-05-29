#include "table.h"
void drawTable() {
    static char filtro[64] = "";
    ImGui::InputTextWithHint("##search", "Buscar processo...", filtro, IM_ARRAYSIZE(filtro));
    if (ImGui::BeginTable("ProcessTable", 5, ImGuiTableFlags_RowBg | ImGuiTableFlags_BordersInnerV | ImGuiTableFlags_Resizable | ImGuiTableFlags_ScrollY)) {
        ImGui::TableSetupColumn("PID");
        ImGui::TableSetupColumn("Nome");
        ImGui::TableSetupColumn("CPU (%)");
        ImGui::TableSetupColumn("Memoria (MB)");
        ImGui::TableSetupColumn("Status");
        ImGui::TableHeadersRow();

        ImGui::EndTable();
    }
}