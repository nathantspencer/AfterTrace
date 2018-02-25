#pragma once

#include <GLFW/glfw3.h>

#include "StylePainter.h"
#include "Window/IWindow.h"

/*! Abstract class for window layouts, which manage window sizes and styles.
 */
class IWindowLayout
{
    public:
    
        /*! The constructor for `IWindowLayout`.
         *
         *  @param glfwWindow a pointer to the parent `GLFWwindow`
         */
        IWindowLayout(GLFWwindow* glfwWindow);
    
        /*! Virtual destructor for `IWindowLayout`.
         */
        virtual ~IWindowLayout();
    
        /*! Pure virtual update function, should contain `ImGui` calls to draw the windows contained in the layout.
         *
         *  @param deltaSeconds the `float` number of seconds since the last update
         */
        virtual void Update(float deltaSeconds) = 0;
    
    protected:
    
        std::map<std::string, std::shared_ptr<IWindow> > GetWindows();
        GLFWwindow* GetGlfwWindow();
        StylePainter* GetStylePainter();
    
        void SetWindows(std::map<std::string, std::shared_ptr<IWindow> > windows);
    
    private:
    
        std::map<std::string, std::shared_ptr<IWindow> > m_windows;
        GLFWwindow* m_glfwWindow;
        StylePainter m_stylePainter;

};
