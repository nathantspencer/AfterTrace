#include "Application.h"
#include "GUI/Window/IWindow.h"
#include "GUI/MainWindowLayout.h"

#include <imgui.h>

Application::Application(GLFWwindow* glfwWindow) :
    m_glfwWindow(glfwWindow),
    m_windowLayout(std::make_unique<MainWindowLayout>(glfwWindow)),
    c_showImguiDemo(false)
{
}

Application::~Application()
{
}

void Application::Update(float deltaSeconds)
{
    ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);
    
    m_windowLayout->Update(deltaSeconds);
    
    if (c_showImguiDemo)
    {
        ImGui::SetNextWindowPos(ImVec2(650, 20), ImGuiCond_FirstUseEver);
        ImGui::ShowTestWindow(NULL);
    }
    
    ImGui::PopStyleVar();
}

GLFWwindow* Application::GetGlfwWindow()
{
    return m_glfwWindow;
}
