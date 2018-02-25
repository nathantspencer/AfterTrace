#pragma once

#include "IWindow.h"

/*! Makes `ImGui` calls to draw and populate the adjustment window.
 *
 *  A single instance of this class is created and owned by `Application`.
 */
class AdjustmentWindow : public IWindow
{
    public:
    
        /*! The constructor for `AdjustmentWindow`.
         *
         *  @param glfwWindow a pointer to the parent `GLFWwindow`
         */
        AdjustmentWindow(GLFWwindow* glfwWindow);
    
        /*! The destructor for `AdjustmentWindow`.
         */
        ~AdjustmentWindow();
    
        /*! Update function for the adjustment window containing `ImGui` calls to populate the window.
         *
         *  @param deltaSeconds the `float` number of seconds since the last update
         */
        void    Update(float deltaSeconds) override;
    
    private:
    
        const char* c_title;
        const int c_width;
};
