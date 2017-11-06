#pragma once

#include <GLFW/glfw3.h>

#include "StylePainter.h"
#include "Window/IWindow.h"

#include <vector>

/*! Abstract class for window layouts, which manage window sizes and styles.
 */
class IWindowLayout
{
    public:
    
        /*! Constructor for `IWindowLayout`.
         *
         *  @param glfwWindow a pointer to the parent `GLFWwindow`
         */
        IWindowLayout(GLFWwindow* glfwWindow);
    
        /*! Virtual destructor for `IWindowLayout`.
         */
        virtual ~IWindowLayout();
    
    private:
    
        GLFWwindow*     m_glfwWindow;
        StylePainter    m_stylePainter;
    
        std::vector<IWindow>    m_windows;
};
