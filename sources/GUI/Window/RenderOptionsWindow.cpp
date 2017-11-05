#include "RenderOptionsWindow.h"

class IWindow;

RenderOptionsWindow::~RenderOptionsWindow()
{
}

void RenderOptionsWindow::Update(float deltaSeconds)
{
    GetStylePainter()->PaintRenderOptionsWindow();
    
    ImGui::Begin(GetTitle(), NULL, GetFlags());
    
    int glfwWidth, glfwHeight;
    glfwGetWindowSize(GetGlfwWindow(), &glfwWidth, &glfwHeight);
    ImGui::SetWindowPos(ImVec2(300.0f, glfwHeight - 200.f), ImGuiCond_Always);
    ImGui::SetWindowSize(ImVec2(glfwWidth - 700.0f, 200.0f), ImGuiCond_Always);
    
    ImGui::Text("Adjust render settings.");
    
    ImGui::End();
}
