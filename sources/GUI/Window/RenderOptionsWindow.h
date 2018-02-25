#pragma once

#include "IWindow.h"

/*! Makes `ImGui` calls to draw and populate the render options window.
 *
 *  A single instance of this class is created and owned by `Application`.
 */
class RenderOptionsWindow : public IWindow
{
    public:
    
        /*! The constructor for `RenderOptionsWindow`.
         *
         *  @param glfwWindow a pointer to the parent `GLFWwindow`
         */
        RenderOptionsWindow(GLFWwindow* glfwWindow);

        /*! The destructor for `RenderOptionsWindow`.
         */
        ~RenderOptionsWindow();
    
        /*! Update function for the render options window containing `ImGui` calls to populate the window.
         *
         *  @param deltaSeconds the `float` number of seconds since the last update
         */
        void    Update(float deltaSeconds) override;
    
    private:
    
        const char* c_title;
};
