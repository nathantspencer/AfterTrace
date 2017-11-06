#include "IWindowLayout.h"

IWindowLayout::IWindowLayout(GLFWwindow* glfwWindow) :
    m_glfwWindow(glfwWindow),
    m_stylePainter(),
    m_windows()
{
}

IWindowLayout::~IWindowLayout()
{
}
