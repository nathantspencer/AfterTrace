#pragma once

#include "IWindow.h"

/*! Makes `ImGui` calls to draw and populate the Render Window.
 *
 *  A single instance of this class is created and owned by `Application`.
 */
class RenderWindow : public IWindow
{
    public:
    
        /*! The constructor for `RenderWindow`.
         *
         *  @param title the string title of the render options window
         *  @param stylePainter a pointer to the `stylePainter` that styles the window
         *  @param glfwWindow a pointer to the parent `GLFWwindow`
         */
        RenderWindow(const char* title, StylePainter* stylePainter, GLFWwindow* glfwWindow) :
            IWindow(title, stylePainter, glfwWindow) {};
    
        /*! The destructor for `RenderWindow`.
         */
        ~RenderWindow();
    
        /*! Update function for the render options window containing `ImGui` calls to populate the window.
         *
         *  @param deltaSeconds the `float` number of seconds since the last update
         */
        void    Update(float deltaSeconds) override;
    
    private:
    
};
