#include <implot.h>
#include "themes/theme.h"
#include <ImGuiFileDialog.h>
#include "UI/init.h"
#include "UI/table.h"
#include "UI/menuBar.h"
int main() {
    
    GLFWwindow* window = ImGuiSetup::InitWindow(1280, 720, "Advanced Process Manager");
    if (!window) return -1;


    if (!ImGuiSetup::InitImGui(window)) {
        ImGuiSetup::Shutdown(window);
        return -1;
    }


    ImGuiIO& io = ImGui::GetIO(); (void)io;
    io.Fonts->AddFontFromFileTTF("assets/fonts/Roboto-Regular.ttf", 18.0f);
    io.Fonts->AddFontFromFileTTF("assets/fonts/JetBrainsMono-Bold.ttf", 18.0f);
    mainTheme();

    
    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
        ImGuiSetup::NewFrame();
        


        

        ImGui::Begin("Main Window - Process");
        StartUpdateThread();
        drawTable();
        drawBar();
        



        ImGui::End();
        ImGuiSetup::Render(window);
    }

    ImGuiSetup::Shutdown(window);
    return 0;
}