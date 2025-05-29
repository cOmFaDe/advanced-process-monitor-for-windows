#include "menuBar.h"
#include "GLFW/glfw3.h"
void drawBar() {
	if (ImGui::BeginMainMenuBar()) {
		if (ImGui::BeginMenu("Arquivos")) {
			if (ImGui::MenuItem("Abrir processo")) {

			}
			if (ImGui::MenuItem("Administrador")) {

			}
			if (ImGui::MenuItem("Injetar DLL")) {

			}
			if (ImGui::MenuItem("Dump")) {

			}
			if (ImGui::MenuItem("Logs")) {

			}
			if (ImGui::MenuItem("Sair", "ALT + F4")) {
				
			}
			ImGui::EndMenu();
		}
		if (ImGui::BeginMenu("Processos")) {
			if (ImGui::MenuItem("Atualizar lista")) {

			}
			if (ImGui::MenuItem("Finalizar processo")) {

			}
			if (ImGui::MenuItem("Finalizar arvore")) {

			}
			if (ImGui::MenuItem("Suspender/retomar")) {

			}
			if (ImGui::MenuItem("Definir prioridade")) {

			}
			if (ImGui::MenuItem("Definir afinidade")) {

			}
			if (ImGui::MenuItem("Propriedades")) {

			}
			ImGui::EndMenu();
		}
		if (ImGui::BeginMenu("Performance")) {
			if (ImGui::MenuItem("Monitor")) {

			}
			if (ImGui::MenuItem("Analise desempenho")) {

			}
			if (ImGui::MenuItem("Otimizar memoria")) {

			}
			ImGui::EndMenu();
		}
		if (ImGui::BeginMenu("Rede")) {
			if (ImGui::MenuItem("Conexoes ativas")) {

			}
			if (ImGui::MenuItem("Monitor de banda")) {

			}
			if (ImGui::MenuItem("Bloquear conexao")) {

			}
			ImGui::EndMenu();
		}
		if (ImGui::BeginMenu("Servicos")) {
			if (ImGui::MenuItem("Listar servicos")) {

			}
			if (ImGui::MenuItem("Iniciar/parar")) {

			}
			if (ImGui::MenuItem("Editar inicializacao")) {

			}
			ImGui::EndMenu();
		}
		if (ImGui::BeginMenu("Ferramentas")) {
			if (ImGui::MenuItem("Injecao de codigo")) {

			}
			if (ImGui::MenuItem("Editor de memoria")) {

			}
			if (ImGui::MenuItem("Scanner de assinatura")) {

			}
			if (ImGui::MenuItem("Gerenciador de hook")) {

			}
			ImGui::EndMenu();
		}
		if (ImGui::BeginMenu("Visualizacao")) {
			if (ImGui::MenuItem("Temas")) {

			}
			if (ImGui::MenuItem("Layout")) {

			}
			if (ImGui::MenuItem("Colunas")) {

			}
			if (ImGui::MenuItem("Agrupamento")) {

			}
			ImGui::EndMenu();
		}
		if (ImGui::BeginMenu("Ajuda")) {
			if (ImGui::MenuItem("Documentacao")) {

			}
			if (ImGui::MenuItem("Atualizacao")) {

			}
			if (ImGui::MenuItem("Sobre")) {

			}
			ImGui::EndMenu();
		}
		ImGui::EndMainMenuBar();
	}
}