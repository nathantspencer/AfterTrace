#include "AdjustmentWindow.h"

class IWindow;

AdjustmentWindow::~AdjustmentWindow()
{
}

void AdjustmentWindow::Update(float deltaSeconds)
{
    int width, height;
    glfwGetWindowSize(GetGlfwWindow(), &width, &height);
    ImGui::SetNextWindowPos(ImVec2(0.0f, 0.0f), ImGuiCond_Once);
    ImGui::SetNextWindowSize(ImVec2(width / 3.0f, height), ImGuiCond_Once);
    ImGui::Begin(GetTitle(), &GetShowWindow(), GetFlags());
    
    ImGui::Text("Scale, translate, rotate models etc.");
    ImGui::End();
}
