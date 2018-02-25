#pragma once

#include "IWindowLayout.h"
#include "MenuBar/MainMenuBar.h"

/*! An implementation of `IWindowLayout` for management of the main window system.
 *
 *  Creates and manages the data, render, render options, and adjustment windows.
 */
class MainWindowLayout : public IWindowLayout
{
    public:
    
        /*! The constructor for `MainWindowLayout`.
         *
         *  Creates the data, render, render options, and adjustment windows.
         *
         *  @param glfwWindow a pointer to the parent `GLFWwindow`
         */
        MainWindowLayout(GLFWwindow* glfwWindow);
    
        /*! The destructor for `MainWindowLayout`.
         */
        ~MainWindowLayout();
    
        /*! Update function for the main window system which manages window size and calls child updates.
         *
         *  @param deltaSeconds the `float` number of seconds since the last update
         */
        void Update(float deltaSeconds) override;
    
    private:
    
        MainMenuBar m_mainMenuBar;
};
