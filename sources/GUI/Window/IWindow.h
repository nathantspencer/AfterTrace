#pragma once

#include <GLFW/glfw3.h>

#include <imgui.h>
#include <glm/vec2.hpp>
#include <string>

class IWindow
{
    public:
    
        IWindow(const char* title, bool& showWindow, GLFWwindow* glfwWindow);
        ~IWindow();
    
        virtual void    Update(float deltaSeconds) = 0;
    
        void    SetNormalizedInitialSize(glm::vec2 normalizedInitialSize);
        void    SetNormalizedInitialPosition(glm::vec2 normalizedInitialPosition);
        void    SetFlags(ImGuiWindowFlags flags);
    
        const char*         GetTitle() const;
        bool&               GetShowWindow() const;
        ImGuiWindowFlags    GetFlags() const;
        GLFWwindow*         GetGlfwWindow() const;
    
    private:
    
        const char*         m_title;
        bool&               m_showWindow;
        ImGuiWindowFlags    m_flags;
    
        glm::vec2   m_normalizedInitialSize;
        glm::vec2   m_normalizedInitialPosition;
    
        GLFWwindow* m_glfwWindow;
};
