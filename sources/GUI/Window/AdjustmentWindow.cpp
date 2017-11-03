#include "AdjustmentWindow.h"

class IWindow;

AdjustmentWindow::~AdjustmentWindow()
{
}

void AdjustmentWindow::Update(float deltaSeconds)
{
    GetStylePainter()->PaintAdjustmentWindow();
    
    ImGui::Begin(GetTitle(), NULL, GetFlags());
    
    int glfwWidth, glfwHeight;
    glfwGetWindowSize(GetGlfwWindow(), &glfwWidth, &glfwHeight);
    ImGui::SetWindowPos(ImVec2(0.0f, 20.0f), ImGuiCond_Once);
    ImGui::SetWindowSize(ImVec2(c_width, glfwHeight / 2.0f), ImGuiCond_Once);
    
    ImGui::Text("Scale, translate, rotate models etc.");
    
    ImGui::End();
}
