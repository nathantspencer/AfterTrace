#pragma once

#include "IWindow.h"

class AdjustmentWindow : public IWindow
{
    public:
    
        AdjustmentWindow(const char* title, bool& showWindow, GLFWwindow* glfwWindow) : IWindow(title, showWindow, glfwWindow) {};
        ~AdjustmentWindow();
    
        void    Update(float deltaSeconds) override;
    
    private:
    
};
