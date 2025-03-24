#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <Windows.h>
#include <TlHelp32.h>
#include <vector>
#include <string>


std::string WStringParaString(const std::wstring& wstr) {
	if (wstr.empty()) return "";

	int tamanhoNecessario = WideCharToMultiByte(CP_UTF8, 0, wstr.c_str(), -1, nullptr, 0, nullptr, nullptr);
	std::string str(tamanhoNecessario, 0);
	WideCharToMultiByte(CP_UTF8, 0, wstr.c_str(), -1, &str[0], tamanhoNecessario, nullptr, nullptr);

	return str;
}

std::vector<std::pair<DWORD, std::wstring>> ObterListaProcessos() {
	std::vector<std::pair<DWORD, std::wstring>> processos;
	HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

	if (hSnap == INVALID_HANDLE_VALUE) {
		std::cerr << "Erro criando snapshot dos processos.\n";
		return processos;
	}

	PROCESSENTRY32 pe32;
	pe32.dwSize = sizeof(PROCESSENTRY32);

	if (Process32First(hSnap, &pe32)) {
		do {
			processos.emplace_back(pe32.th32ProcessID, pe32.szExeFile);
		} while (Process32Next(hSnap, &pe32));
	}

	CloseHandle(hSnap);
	return processos;
}



int main()
{
	// glfw stuff
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	
	GLFWwindow* window = glfwCreateWindow(800, 800, "Advanced Monitor", NULL, NULL);
	
	if (window == NULL)
	{
		std::cout << "Falha ao criar Janela do GLFW" << std::endl;
		glfwTerminate();
		return -1;
	}
	
	glfwMakeContextCurrent(window);

	
	gladLoadGL();
	
	//x = 0, y = 0, to x = 800, y = 800
	glViewport(0, 0, 800, 800);


	//imgui stuff
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	ImGui::StyleColorsDark();
	ImGui_ImplGlfw_InitForOpenGL(window, true);
	ImGui_ImplOpenGL3_Init("#version 330");

	

	

	
	while (!glfwWindowShouldClose(window))
	{
		
		glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
		
		glClear(GL_COLOR_BUFFER_BIT);

		
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();
		char buffer[128];
		ImGui::Begin("Monitor de processos avancado.");

		ImGui::BeginMainMenuBar();
		if (ImGui::BeginMenu("File")) {
			ImGui::MenuItem("Novo");
			ImGui::MenuItem("Abrir");
			ImGui::EndMenu();
		}
		if (ImGui::BeginMenu("System Informations")) {
			
			ImGui::EndMenu();
		}
		ImGui::EndMainMenuBar();
		auto processos = ObterListaProcessos();
		
		for (const auto& p : processos) {
			std::string nomeProcesso = WStringParaString(p.second);
			const char* s = nomeProcesso.c_str();
			std::string pidStr = std::to_string(p.first);
			if (ImGui::BeginMenu(s)) {
				ImGui::MenuItem(pidStr.c_str());
				ImGui::EndMenu();
			}
		}
		
		
		ImGui::End();

		
		

		
		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

		
		glfwSwapBuffers(window);
		
		glfwPollEvents();
	}

	
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();

	
	glfwDestroyWindow(window);
	
	glfwTerminate();
	return 0;
}