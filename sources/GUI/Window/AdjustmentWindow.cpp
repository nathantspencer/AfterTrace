#include "AdjustmentWindow.h"

class IWindow;

AdjustmentWindow::~AdjustmentWindow()
{
}

void AdjustmentWindow::Update(float deltaSeconds)
{
    ImGui::Begin(GetTitle(), NULL, GetFlags());
    SetWindowGeometry();
    ImGui::Text("Scale, translate, rotate models etc.");
    ImGui::End();
}

void AdjustmentWindow::SetWindowGeometry()
{
    // initial geometry
    int glfwWidth, glfwHeight;
    glfwGetWindowSize(GetGlfwWindow(), &glfwWidth, &glfwHeight);
    ImGui::SetWindowPos(ImVec2(0.0f, 0.0f), ImGuiCond_Once);
    ImGui::SetWindowSize(ImVec2(glfwWidth / 4.0f, glfwHeight), ImGuiCond_Once);
    
    // geometry for resized glfwWindow
    ImVec2 currentWindowSize = ImGui::GetWindowSize();
    ImGui::SetWindowSize(ImVec2(currentWindowSize.x, glfwHeight), ImGuiCond_Always);
}
