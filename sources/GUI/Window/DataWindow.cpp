#include "DataWindow.h"

class IWindow;

DataWindow::DataWindow(GLFWwindow* glfwWindow) :
    IWindow(glfwWindow),
    c_title("Data Window"),
    c_width(400)
{
}

DataWindow::~DataWindow()
{
}

void DataWindow::Update(float deltaSeconds)
{
    int glfwWidth, glfwHeight;
    glfwGetWindowSize(GetGlfwWindow(), &glfwWidth, &glfwHeight);
    ImGui::SetNextWindowPos(ImVec2(glfwWidth - c_width, 20.0f), ImGuiCond_Always);
    ImGui::SetNextWindowSize(ImVec2(c_width, glfwHeight - 20.0f), ImGuiCond_Always);
    
    ImGui::Begin(c_title, NULL, GetFlags());
    
    ImGui::Text("Your data live here.");
    ImGui::End();
}
