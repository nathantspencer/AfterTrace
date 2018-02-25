#include "AdjustmentWindow.h"

class IWindow;

AdjustmentWindow::AdjustmentWindow(GLFWwindow* glfwWindow) :
    IWindow(glfwWindow),
    c_title("Adjustment Window"),
    c_width(300)
{
}

AdjustmentWindow::~AdjustmentWindow()
{
}

void AdjustmentWindow::Update(float deltaSeconds)
{
    ImGui::Begin(c_title, NULL, GetFlags());
    
    int glfwWidth, glfwHeight;
    glfwGetWindowSize(GetGlfwWindow(), &glfwWidth, &glfwHeight);
    ImGui::SetWindowPos(ImVec2(0.0f, 20.0f), ImGuiCond_Once);
    ImGui::SetWindowSize(ImVec2(c_width, glfwHeight - 20.0f), ImGuiCond_Always);
    
    ImGui::Text("Scale, translate, rotate models etc.");
    
    ImGui::End();
}
