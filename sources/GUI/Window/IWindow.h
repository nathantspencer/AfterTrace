#pragma once

#include <GLFW/glfw3.h>

#include "GUI/StylePainter.h"

#include <imgui.h>
#include <glm/vec2.hpp>
#include <string>

/*! Abstract class for GUI windows within the `GLFWwindow`.
 */
class IWindow
{
    public:
    
        /*! The constructor for `IWindow`.
         *
         *  @param glfwWindow a pointer to the parent `GLFWwindow`
         */
        IWindow(GLFWwindow* glfwWindow);
    
        /*! Virtual destructor for `IWindow`.
         */
        virtual ~IWindow();
    
        /*! Pure virtual update function, should contain `ImGui` calls to draw the window.
         *
         *  @param deltaSeconds the `float` number of seconds since the last update
         */
        virtual void Update(float deltaSeconds) = 0;

        void SetFlags(ImGuiWindowFlags flags);
    
    protected:
    
        ImGuiWindowFlags GetFlags() const;
        GLFWwindow* GetGlfwWindow() const;
    
    private:
    
        ImGuiWindowFlags m_flags;
        GLFWwindow* m_glfwWindow;
};
