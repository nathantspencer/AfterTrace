#include "AdjustmentWindow.h"

class IWindow;

AdjustmentWindow::~AdjustmentWindow()
{
}

void AdjustmentWindow::Update(float deltaSeconds)
{
    GetStylePainter()->PaintAdjustmentWindow();
    
    ImGui::Begin(GetTitle(), NULL, GetFlags());
    
    // initial geometry
    int glfwWidth, glfwHeight;
    glfwGetWindowSize(GetGlfwWindow(), &glfwWidth, &glfwHeight);
    ImGui::SetWindowPos(ImVec2(0.0f, 20.0f), ImGuiCond_Once);
    ImGui::SetWindowSize(ImVec2(glfwWidth / 6.0f, glfwHeight), ImGuiCond_Once);
    
    // update geometry
    ImVec2 currentWindowSize = ImGui::GetWindowSize();
    ImGui::SetWindowSize(ImVec2(currentWindowSize.x, glfwHeight), ImGuiCond_Always);
    
    ImGui::Text("Scale, translate, rotate models etc.");
    
    ImGui::End();
}
