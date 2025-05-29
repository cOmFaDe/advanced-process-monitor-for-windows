```markdown
# 🧠 Advanced Process Monitor for Windows
```
![image](https://github.com/user-attachments/assets/01272164-b9c5-4b2f-b28e-86c420126c3a)
```Baixíssimo consumo de ram e processador!```
![image](https://github.com/user-attachments/assets/513f4d6d-c7d0-40e3-80ea-677a0f6894ef)

```

> Ferramenta gráfica moderna para monitoramento de processos no Windows — desenvolvida em C++ com ImGui e GLFW.

---

## ✨ Funcionalidades

- 🔍 Visualização **em tempo real** dos processos ativos no sistema.
- 🎨 Interface leve e moderna com **temas customizáveis**.
- 📦 Arquitetura **modular** e de fácil manutenção.
- ⚡ Baixo uso de recursos — ideal para debugging e monitoramento técnico.

---

## 🧰 Tecnologias

| Linguagem | Interface | Sistema | Outros |
|----------:|-----------|---------|--------|
| C++       | Dear ImGui | Windows | GLFW   |
| C         | ImPlot     |         | stb    |

---

## 📁 Estrutura

```

advanced-process-monitor-for-windows/
├── core/           # Lógica principal do monitor

├── libs/           # Bibliotecas externas (ImGui, ImPlot, stb, etc)

├── themes/         # Temas personalizados da interface

├── assets/         # Fontes, ícones, imagens

├── main.cpp        # Ponto de entrada

└── README.md       # Você está aqui :)

````

---

## 🛠️ Como Compilar

1. **Clone o repositório**
   ```bash
   git clone https://github.com/cOmFaDe/advanced-process-monitor-for-windows.git
   cd advanced-process-monitor-for-windows


2. **Configure o ambiente**

   * Use uma IDE como Visual Studio ou CMake.
   * Certifique-se de ter um compilador C++17+.
   * As dependências já estão incluídas em `libs/`.

3. **Compile o projeto**

   * Na IDE: abra e execute.
   * No terminal (com `g++`, por exemplo):

     
     g++ -Ilibs -Icore -o monitor.exe main.cpp core/*.cpp libs/imgui/*.cpp -lgdi32 -lopengl32
     

---

## 🚧 Status

⚠️ Este projeto está em desenvolvimento ativo. Contribuições e feedbacks são **muito bem-vindos**!

---

## 🤝 Contribuindo

```bash
# Fork e clone o repositório
git clone https://github.com/seu-usuario/advanced-process-monitor-for-windows.git

# Crie uma branch de feature
git checkout -b minha-nova-feature

# Commit e push
git commit -m "Adiciona nova funcionalidade"
git push origin minha-nova-feature
```

Abra um Pull Request com sua melhoria 🚀

---



## 📬 Contato

Criado com ❤️ por [cOmFaDe](https://github.com/cOmFaDe)
Para sugestões, dúvidas ou colaborações, fique à vontade para abrir uma issue!

---

> *"Monitorar processos nunca foi tão visual."* 💻

```

---

```
