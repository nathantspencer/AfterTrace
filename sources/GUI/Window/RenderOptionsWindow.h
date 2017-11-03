#pragma once

#include "IWindow.h"

/*! Makes `ImGui` calls to draw and populate the Render Options Window.
 *
 *  A single instance of this class is created and owned by `Application`.
 */
class RenderOptionsWindow : public IWindow
{
    public:
    
        /*! The constructor for `RenderOptionsWindow`.
         *
         *  @param title the string title of the render options window
         *  @param stylePainter a pointer to the `stylePainter` that styles the window
         *  @param glfwWindow a pointer to the parent `GLFWwindow`
         */
        RenderOptionsWindow(const char* title, StylePainter* stylePainter, GLFWwindow* glfwWindow) :
            IWindow(title, stylePainter, glfwWindow), c_width(300) {};
    
        /*! The destructor for `RenderOptionsWindow`.
         */
        ~RenderOptionsWindow();
    
        /*! Update function for the render options window containing `ImGui` calls to populate the window.
         *
         *  @param deltaSeconds the `float` number of seconds since the last update
         */
        void    Update(float deltaSeconds) override;
    
    private:
    
        int c_width;
};
