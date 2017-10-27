#include "Application.h"
#include "GUI/Window/IWindow.h"

#include <imgui.h>

Application::Application(GLFWwindow* glfwWindow) :
    m_glfwWindow(glfwWindow),
    m_showAdjustmentWindow(true),
    m_showDataWindow(true),
    m_showImGuiDemoWindow(true)
{
    m_adjustmentWindow = new AdjustmentWindow("Adjustment Window", m_showAdjustmentWindow, m_glfwWindow);
    int adjustmentWindowFlags = 0;
    adjustmentWindowFlags |= ImGuiWindowFlags_MenuBar;
    m_adjustmentWindow->SetFlags(adjustmentWindowFlags);
}

Application::~Application()
{
    delete m_adjustmentWindow;
    m_adjustmentWindow = nullptr;
}

void Application::Update(float deltaSeconds)
{
    m_adjustmentWindow->Update(deltaSeconds);
    
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
    
    // =================================^^^===============================
     */
}
