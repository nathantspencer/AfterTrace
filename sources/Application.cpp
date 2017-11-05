#include "Application.h"
#include "GUI/Window/IWindow.h"

#include <imgui.h>

Application::Application(GLFWwindow* glfwWindow) :
    m_glfwWindow(glfwWindow),
    m_mainMenuBar(&m_stylePainter),
    m_adjustmentWindow("Adjustment Window", &m_stylePainter, m_glfwWindow),
    m_renderOptionsWindow("Render Options Window", &m_stylePainter, m_glfwWindow),
    m_renderWindow("Render Window", &m_stylePainter, m_glfwWindow),
    m_dataWindow("Data Window", &m_stylePainter, m_glfwWindow),
    m_stylePainter(),
    c_showImguiDemo(false)
{
    int windowFlags = 0;
    windowFlags |= ImGuiWindowFlags_NoResize;
    windowFlags |= ImGuiWindowFlags_NoMove;
    windowFlags |= ImGuiWindowFlags_NoCollapse;
    windowFlags |= ImGuiWindowFlags_ShowBorders;
    
    m_adjustmentWindow.SetFlags(windowFlags);
    m_renderOptionsWindow.SetFlags(windowFlags);
    m_renderWindow.SetFlags(windowFlags);
    m_dataWindow.SetFlags(windowFlags);
}

Application::~Application()
{
}

void Application::Update(float deltaSeconds)
{
    ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);
    
    m_mainMenuBar.Update(deltaSeconds);
    m_adjustmentWindow.Update(deltaSeconds);
    m_renderOptionsWindow.Update(deltaSeconds);
    m_renderWindow.Update(deltaSeconds);
    m_dataWindow.Update(deltaSeconds);
    
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
