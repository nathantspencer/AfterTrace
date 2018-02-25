#pragma once

#include "IWindow.h"

/*! Makes `ImGui` calls to draw and populate the data window.
 *
 *  A single instance of this class is created and owned by `Application`.
 */
class DataWindow : public IWindow
{
    public:
    
        /*! The constructor for `DataWindow`.
         *
         *  @param glfwWindow a pointer to the parent `GLFWwindow`
         */
        DataWindow(GLFWwindow* glfwWindow);
    
        /*! The destructor for `DataWindow`.
         */
        ~DataWindow();
    
        /*! Update function for the data window containing `ImGui` calls to populate the window.
         *
         *  @param deltaSeconds the `float` number of seconds since the last update
         */
        void    Update(float deltaSeconds) override;
    
    private:

        const char* c_title;
        const int c_width;
};
