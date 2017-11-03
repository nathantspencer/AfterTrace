#include "DataWindow.h"

class IWindow;

DataWindow::~DataWindow()
{
}

void DataWindow::Update(float deltaSeconds)
{
    GetStylePainter()->PaintDataWindow();
    
    int glfwWidth, glfwHeight;
    glfwGetWindowSize(GetGlfwWindow(), &glfwWidth, &glfwHeight);
    ImGui::SetNextWindowPos(ImVec2(glfwWidth - c_width, 20.0f), ImGuiCond_Always);
    ImGui::SetNextWindowSize(ImVec2(c_width, glfwHeight), ImGuiCond_Once);
    
    ImGui::Begin(GetTitle(), NULL, GetFlags());
    
    ImGui::Text("Your data live here.");
    ImGui::End();
}
