#pragma once

#include "IWindow.h"

/*! Makes `ImGui` calls to draw and populate the render window.
 *
 *  A single instance of this class is created and owned by `Application`.
 */
class RenderWindow : public IWindow
{
    public:
    
        /*! The constructor for `RenderWindow`.
         *
         *  @param glfwWindow a pointer to the parent `GLFWwindow`
         */
        RenderWindow(GLFWwindow* glfwWindow);
    
        /*! The destructor for `RenderWindow`.
         */
        ~RenderWindow();
    
        /*! Update function for the render options window containing `ImGui` calls to populate the window.
         *
         *  @param deltaSeconds the `float` number of seconds since the last update
         */
        void Update(float deltaSeconds) override;
    
    private:
    
        const char* c_title;
};
