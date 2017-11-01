#include <GL/gl3w.h>
#include <GLFW/glfw3.h>

#include "Application.h"

#include <stdio.h>
#include <chrono>

#include <imgui.h>
#include "imgui_impl_glfw_gl3.h"



static void error_callback(int error, const char* description)
{
    fprintf(stderr, "Error %d: %s\n", error, description);
}

void Draw(GLFWwindow* window, float deltaSeconds)
{
    ImGui_ImplGlfwGL3_NewFrame();
    
    Application* application = static_cast<Application*>(glfwGetWindowUserPointer(window));
    application->Update(0.0f);
    
    // Rendering
    int display_w, display_h;
    glfwGetFramebufferSize(window, &display_w, &display_h);
    glViewport(0, 0, display_w, display_h);
    glClearColor(0.25f, 0.25f, 0.25f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    ImGui::Render();
    glfwSwapBuffers(window);
}

void framebuffer_size_callback(GLFWwindow* window , int width , int height)
{
   Draw(window, 0.0f);
}

int main(int, char**)
{
    glfwSetErrorCallback(error_callback);

    if (!glfwInit())
        return 1;
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    
    #if __APPLE__
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    #endif
    
    // Set up window
    GLFWwindow* window = glfwCreateWindow(1280, 720, "NeuroStudio", NULL, NULL);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    
    // Generate Application instance
    std::shared_ptr<Application> application = std::make_shared<Application>(window);
    glfwSetWindowUserPointer(window, application.get());

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1); // Enable vsync
    gl3wInit();

    // Setup ImGui binding
    ImGui_ImplGlfwGL3_Init(window, true);

    // Load Font
    ImGuiIO& io = ImGui::GetIO();
    io.Fonts->AddFontFromFileTTF("../../libs/imgui/extra_fonts/Cousine-Regular.ttf", 14.0f);
    
    auto lastTime = std::chrono::steady_clock::now();
    
    // Main loop
    ImGui::PushStyleVar(ImGuiStyleVar_ChildWindowRounding, 0.0f);
    while (!glfwWindowShouldClose(window))
    {
        // Calculate time delta in seconds
        auto currentTime = std::chrono::steady_clock::now();
        std::chrono::duration<double> duration = currentTime - lastTime;
        float deltaSeconds = duration.count();
        
        // Limit to 60 fps
        if (deltaSeconds < 1.0f / 60.0f)
        {
            continue;
        }
        
        // Do the heavy lifting
        lastTime = currentTime;
        glfwPollEvents();
        Draw(window, deltaSeconds);
    }

    // Cleanup
    ImGui_ImplGlfwGL3_Shutdown();
    glfwTerminate();

    return 0;
}
