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
    
        GLFWwindow* GetGlfwWindow();
    
    private:
    
        GLFWwindow* m_glfwWindow;
    
        AdjustmentWindow    m_adjustmentWindow;
};
