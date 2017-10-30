#pragma once

#include <GLFW/glfw3.h>

#include "GUI/MenuBar/MainMenuBar.h"
#include "GUI/Window/AdjustmentWindow.h"
#include "GUI/Window/DataWindow.h"

class Application
{
    public:
    
        Application(GLFWwindow* glfwWindow);
        ~Application();
    
        void    Update(float deltaSeconds);
    
        GLFWwindow* GetGlfwWindow();
    
    private:
    
        GLFWwindow* m_glfwWindow;
    
        MainMenuBar         m_mainMenuBar;
        AdjustmentWindow    m_adjustmentWindow;
        DataWindow          m_dataWindow;
    
        StylePainter        m_stylePainter;
    
        const bool          c_showImguiDemo;
};
