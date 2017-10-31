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
    
        /*! Abstract class for GUI windows within the `GLFWwindow`.
         *
         *  A single instance of this class is created by `Application` and passed to the `GUI`
         *  elements it owns.
         */
        IWindow(const char* title, StylePainter* stylePainter, GLFWwindow* glfwWindow);
    
        /*! Virtual destructor for `IWindow`.
         */
        virtual ~IWindow();
    
        /*! Pure virtual update function, should contain `ImGui` calls to draw the window.
         *
         *  @param deltaSeconds the `float` number of seconds since the last update
         */
        virtual void    Update(float deltaSeconds) = 0;

        void                SetFlags(ImGuiWindowFlags flags);
        const char*         GetTitle() const;
        ImGuiWindowFlags    GetFlags() const;
        GLFWwindow*         GetGlfwWindow() const;
        StylePainter*       GetStylePainter() const;
    
    private:
    
        const char*         m_title;
        ImGuiWindowFlags    m_flags;
        GLFWwindow*         m_glfwWindow;
        StylePainter*       m_stylePainter;
};
