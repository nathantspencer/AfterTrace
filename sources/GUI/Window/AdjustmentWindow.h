#pragma once

#include "IWindow.h"

/*! Makes `ImGui` calls to draw and populate the Adjustment Window.
 *
 *  A single instance of this class is created and owned by `Application`.
 */
class AdjustmentWindow : public IWindow
{
    public:
    
        /*! The constructor for `AdjustmentWindow`.
         *
         *  @param title the string title of the Data Window
         *  @param stylePainter a pointer to the `stylePainter` that styles the window
         *  @param glfwWindow a pointer to the parent `GLFWwindow`
         */
        AdjustmentWindow(const char* title, StylePainter* stylePainter, GLFWwindow* glfwWindow) :
            IWindow(title, stylePainter, glfwWindow), c_width(300) {};
    
        /*! The destructor for `AdjustmentWindow`.
         */
        ~AdjustmentWindow();
    
        /*! Update function for the adjustment window containing `ImGui` calls to populate the window.
         *
         *  @param deltaSeconds the `float` number of seconds since the last update
         */
        void    Update(float deltaSeconds) override;
    
    private:
    
        int c_width;
};
