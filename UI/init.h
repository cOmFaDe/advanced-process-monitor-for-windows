#ifndef IMGUI_SETUP_H
#define IMGUI_SETUP_H

#include <glad/glad.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
#include <imgui_impl_opengl3_loader.h>
#include <GLFW/glfw3.h>
#include <imgui.h>

struct ImGuiContext;
struct GLFWwindow;

namespace ImGuiSetup {
    
    GLFWwindow* InitWindow(int width, int height, const char* title);

    
    bool InitImGui(GLFWwindow* window, const char* glsl_version = "#version 330");

    
    void Shutdown(GLFWwindow* window);

    
    void NewFrame();

    
    void Render(GLFWwindow* window);
}

#endif