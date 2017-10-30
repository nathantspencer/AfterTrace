#include "DataWindow.h"

class IWindow;

DataWindow::~DataWindow()
{
}

void DataWindow::Update(float deltaSeconds)
{
    GetStylePainter()->PaintDataWindow();
    
    // initial geometry
    int glfwWidth, glfwHeight;
    glfwGetWindowSize(GetGlfwWindow(), &glfwWidth, &glfwHeight);
    ImGui::SetNextWindowPos(ImVec2(glfwWidth / 5.0f, 20.0f), ImGuiCond_Once);
    ImGui::SetNextWindowSize(ImVec2(4.0f * glfwWidth / 5.0f, glfwHeight), ImGuiCond_Once);
    
    if  (m_leftOffset == -1.0f)
    {
        m_leftOffset = glfwWidth / 4.0f;
    }
    
    ImGui::Begin(GetTitle(), NULL, GetFlags());
    
    // update geometry
    ImGui::SetWindowSize(ImVec2(glfwWidth - m_leftOffset, glfwHeight), ImGuiCond_Always);
    ImGui::SetWindowPos(ImVec2(m_leftOffset, 20.0f), ImGuiCond_Always);
    
    ImGui::Text("Your data live here.");
    ImGui::End();
}
