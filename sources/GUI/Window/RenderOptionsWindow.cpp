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
    ImGui::SetWindowPos(ImVec2(0.0f, 20.0f + glfwHeight / 2.0f), ImGuiCond_Once);
    ImGui::SetWindowSize(ImVec2(c_width, (glfwHeight / 2.0f) - 20.0f), ImGuiCond_Once);
    
    ImGui::Text("Adjust render settings.");
    
    ImGui::End();
}
