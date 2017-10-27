#include "IWindow.h"

IWindow::IWindow(const char* title, GLFWwindow* glfwWindow) :
    m_title(title),
    m_flags(0),
    m_glfwWindow(glfwWindow)
{
}

IWindow::~IWindow()
{
}

void IWindow::SetNormalizedInitialSize(glm::vec2 normalizedInitialSize)
{
    m_normalizedInitialSize = normalizedInitialSize;
}

void IWindow::SetNormalizedInitialPosition(glm::vec2 normalizedInitialPosition)
{
    m_normalizedInitialPosition = normalizedInitialPosition;
}

void IWindow::SetFlags(ImGuiWindowFlags flags)
{
    m_flags = flags;
}

const char* IWindow::GetTitle() const
{
    return m_title;
}

ImGuiWindowFlags IWindow::GetFlags() const
{
    return m_flags;
}

GLFWwindow* IWindow::GetGlfwWindow() const
{
    return m_glfwWindow;
}
