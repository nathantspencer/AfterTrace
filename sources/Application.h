#pragma once

#include <GLFW/glfw3.h>

#include "GUI/Window/AdjustmentWindow.h"

class Application
{
    public:
    
        Application(GLFWwindow* glfwWindow);
        ~Application();
    
        void    Init();
        void    Update(float deltaSeconds);
    
    private:
    
        GLFWwindow* m_glfwWindow;
    
        bool   m_showAdjustmentWindow;
        bool   m_showDataWindow;
        bool   m_showImGuiDemoWindow;
    
        AdjustmentWindow*   m_adjustmentWindow;
};
