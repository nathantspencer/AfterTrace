#include "IWindow.h"

IWindow::IWindow(GLFWwindow* glfwWindow) :
    m_flags(0),
    m_glfwWindow(glfwWindow)
{
}

IWindow::~IWindow()
{
}

void IWindow::SetFlags(ImGuiWindowFlags flags)
{
    m_flags = flags;
}

ImGuiWindowFlags IWindow::GetFlags() const
{
    return m_flags;
}

GLFWwindow* IWindow::GetGlfwWindow() const
{
    return m_glfwWindow;
}
