#pragma once

#include <GLFW/glfw3.h>

#include "GUI/IWindowLayout.h"

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
    
        std::unique_ptr<IWindowLayout> m_windowLayout;
    
        const bool c_showImguiDemo;
};
