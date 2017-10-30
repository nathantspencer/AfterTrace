#pragma once

#include "IWindow.h"

class AdjustmentWindow : public IWindow
{
    public:
    
        AdjustmentWindow(const char* title, StylePainter* stylePainter, GLFWwindow* glfwWindow) :
            IWindow(title, stylePainter, glfwWindow) {};
        ~AdjustmentWindow();
    
        void    Update(float deltaSeconds) override;
    
    private:
    
        void    SetWindowGeometry();
};
