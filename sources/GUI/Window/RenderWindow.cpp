#include "RenderWindow.h"

class IWindow;

RenderWindow::~RenderWindow()
{
}

void RenderWindow::Update(float deltaSeconds)
{
    GetStylePainter()->PaintRenderWindow();
    
    ImGui::Begin(GetTitle(), NULL, GetFlags());
    
    int glfwWidth, glfwHeight;
    glfwGetWindowSize(GetGlfwWindow(), &glfwWidth, &glfwHeight);
    ImGui::SetWindowPos(ImVec2(300.0f, 20.0f), ImGuiCond_Once);
    ImGui::SetWindowSize(ImVec2(glfwWidth - 700.0f, glfwHeight - 220.0f), ImGuiCond_Always);
    
    ImGui::Text("Your models are rendered here.");
    
    ImGui::End();
}
