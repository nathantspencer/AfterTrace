#pragma once

#include <GLFW/glfw3.h>

#include "GUI/MenuBar/MainMenuBar.h"
#include "GUI/Window/AdjustmentWindow.h"
#include "GUI/Window/DataWindow.h"

/*! The main application class.
 *
 *  While not strictly enforced, this class is to be used as a singleton.
 */
class Application
{
    public:
    
        /*! The constructor for `Application`.
         *
         *  @param glfwWindow a pointer to the `GLFWwindow` in which the application runs
         */
        Application(GLFWwindow* glfwWindow);
    
        /*! The destructor for `Application`.
         */
        ~Application();
    
        /*! Main application update call.
         *
         *  The update functions of other classes owned by `Application` are called within this function,
         *  including GUI elements.
         *
         *  @param deltaSeconds the `float` number of seconds since the last update
         */
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
