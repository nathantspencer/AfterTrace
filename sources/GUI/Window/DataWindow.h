#pragma once

#include "IWindow.h"

class DataWindow : public IWindow
{
    public:
    
        DataWindow(const char* title, GLFWwindow* glfwWindow) : IWindow(title, glfwWindow), m_leftOffset(-1.0f) {};
        ~DataWindow();
    
        void    Update(float deltaSeconds) override;
    
    private:

        float m_leftOffset;
};
