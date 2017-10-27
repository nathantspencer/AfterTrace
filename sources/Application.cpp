#include "Application.h"
#include "GUI/Window/IWindow.h"

#include <imgui.h>

Application::Application(GLFWwindow* glfwWindow) :
    m_glfwWindow(glfwWindow),
    m_adjustmentWindow("Adjustment Window", m_glfwWindow),
    m_dataWindow("Data Window", m_glfwWindow)
{
    int adjustmentWindowFlags = 0;
    adjustmentWindowFlags |= ImGuiWindowFlags_NoResize;
    adjustmentWindowFlags |= ImGuiWindowFlags_NoMove;
    adjustmentWindowFlags |= ImGuiWindowFlags_NoCollapse;
    m_adjustmentWindow.SetFlags(adjustmentWindowFlags);
    
    int dataWindowFlags = adjustmentWindowFlags;
    dataWindowFlags |= ImGuiWindowFlags_MenuBar;
    m_dataWindow.SetFlags(dataWindowFlags);
}

Application::~Application()
{
}

void Application::Update(float deltaSeconds)
{
    m_adjustmentWindow.Update(deltaSeconds);
    m_dataWindow.Update(deltaSeconds);
    
    /*
    // Data window
    ImGuiWindowFlags dataWindowFlags = 0;
    dataWindowFlags |= ImGuiWindowFlags_MenuBar;
    
    ImGui::SetNextWindowPos(ImVec2(width / 3.0f + 1.0f, 0.0f), ImGuiCond_Once);
    ImGui::SetNextWindowSize(ImVec2(width * 2.0f / 3.0f, height), ImGuiCond_Once);
    ImGui::Begin("Another Window", &m_showDataWindow, dataWindowFlags);
    
    if (ImGui::BeginMenuBar())
    {
        if (ImGui::BeginMenu("Menu"))
        {
            ImGui::MenuItem("Main menu bar", NULL, nullptr);
            ImGui::EndMenu();
        }
        ImGui::EndMenuBar();
    }
    ImGui::Text("Hello from another window!");
    ImGui::End();
    
    // ImGui demo window
    if (m_showImGuiDemoWindow)
    {
        ImGui::SetNextWindowPos(ImVec2(650, 20), ImGuiCond_FirstUseEver);
        ImGui::ShowTestWindow(&m_showImGuiDemoWindow);
    }
     */
}

GLFWwindow* Application::GetGlfwWindow()
{
    return m_glfwWindow;
}
