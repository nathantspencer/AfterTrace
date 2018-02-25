#include "IWindowLayout.h"

IWindowLayout::IWindowLayout(GLFWwindow* glfwWindow) :
    m_windows(),
    m_glfwWindow(glfwWindow),
    m_stylePainter()
{
}

IWindowLayout::~IWindowLayout()
{
}

std::map<std::string, std::shared_ptr<IWindow> > IWindowLayout::GetWindows()
{
    return m_windows;
}

GLFWwindow* IWindowLayout::GetGlfwWindow()
{
    return m_glfwWindow;
}

StylePainter* IWindowLayout::GetStylePainter()
{
    return &m_stylePainter;
}

void IWindowLayout::SetWindows(std::map<std::string, std::shared_ptr<IWindow> > windows)
{
    m_windows = windows;
}
