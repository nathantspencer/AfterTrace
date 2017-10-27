#pragma once

#include "IWindow.h"

class AdjustmentWindow : public IWindow
{
    public:
    
        AdjustmentWindow(const char* title, GLFWwindow* glfwWindow) : IWindow(title, glfwWindow) {};
        ~AdjustmentWindow();
    
        void    Update(float deltaSeconds) override;
    
    private:
    
        void    SetWindowGeometry();
};
