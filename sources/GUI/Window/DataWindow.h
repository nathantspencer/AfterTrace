#pragma once

#include "IWindow.h"
#include "GUI/StylePainter.h"

class DataWindow : public IWindow
{
    public:
    
        DataWindow(const char* title,  StylePainter* stylePainter, GLFWwindow* glfwWindow) :
            IWindow(title, stylePainter, glfwWindow), m_leftOffset(-1.0f) {};
        ~DataWindow();
    
        void    Update(float deltaSeconds) override;
    
    private:

        float m_leftOffset;
};
