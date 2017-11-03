#pragma once

#include "IWindow.h"

/*! Makes `ImGui` calls to draw and populate the Data Window.
 *
 *  A single instance of this class is created and owned by `Application`.
 */
class DataWindow : public IWindow
{
    public:
    
        /*! The constructor for `DataWindow`.
         *
         *  @param title the string title of the data window
         *  @param stylePainter a pointer to the `stylePainter` that styles the window
         *  @param glfwWindow a pointer to the parent `GLFWwindow`
         */
        DataWindow(const char* title,  StylePainter* stylePainter, GLFWwindow* glfwWindow) :
            IWindow(title, stylePainter, glfwWindow), c_width(400) {};
    
        /*! The destructor for `DataWindow`.
         */
        ~DataWindow();
    
        /*! Update function for the data window containing `ImGui` calls to populate the window.
         *
         *  @param deltaSeconds the `float` number of seconds since the last update
         */
        void    Update(float deltaSeconds) override;
    
    private:

        const int c_width;
};
