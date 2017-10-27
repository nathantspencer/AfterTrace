#include "Application.h"
#include "GUI/Window/IWindow.h"

#include <imgui.h>

Application::Application(GLFWwindow* glfwWindow) :
    m_glfwWindow(glfwWindow),
    m_adjustmentWindow("Adjustment Window", m_glfwWindow),
    m_dataWindow("Data Window", m_glfwWindow),
    c_showImguiDemo(false)
{
    int windowFlags = 0;
    windowFlags |= ImGuiWindowFlags_NoResize;
    windowFlags |= ImGuiWindowFlags_NoMove;
    windowFlags |= ImGuiWindowFlags_NoCollapse;
    windowFlags |= ImGuiWindowFlags_ShowBorders;
    m_adjustmentWindow.SetFlags(windowFlags);
    m_dataWindow.SetFlags(windowFlags);
}

Application::~Application()
{
}

void Application::Update(float deltaSeconds)
{
    ImGui::BeginMainMenuBar();
    ImGui::EndMainMenuBar();
    
    m_adjustmentWindow.Update(deltaSeconds);
    m_dataWindow.Update(deltaSeconds);
    
    if (c_showImguiDemo)
    {
        ImGui::SetNextWindowPos(ImVec2(650, 20), ImGuiCond_FirstUseEver);
        ImGui::ShowTestWindow(NULL);
    }
}

GLFWwindow* Application::GetGlfwWindow()
{
    return m_glfwWindow;
}
