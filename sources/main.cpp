#include <GL/gl3w.h>
#include <GLFW/glfw3.h>

#include "Application.h"

#include <stdio.h>
#include <chrono>

#include <imgui.h>
#include "ImGuiImpl/imgui_impl_glfw_gl3.h"

static void error_callback(int error, const char* description)
{
    fprintf(stderr, "Error %d: %s\n", error, description);
}

int main(int, char**)
{
    // Set up window
    glfwSetErrorCallback(error_callback);
    if (!glfwInit())
        return 1;
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    
    #if __APPLE__
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    #endif
    
    GLFWwindow* window = glfwCreateWindow(1280, 720, "ImGui OpenGL3 example", NULL, NULL);
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1); // Enable vsync
    gl3wInit();

    // Setup ImGui binding
    ImGui_ImplGlfwGL3_Init(window, true);

    // Load Font
    ImGuiIO& io = ImGui::GetIO();
    io.Fonts->AddFontFromFileTTF("../../libs/imgui/extra_fonts/Cousine-Regular.ttf", 14.0f);
    
    // Background color
    ImVec4 clear_color = ImVec4(0.25f, 0.25f, 0.25f, 1.0f);
    
    // Start timer
    auto startTime = std::chrono::steady_clock::now();
    
    // Generate Application instance
    Application application = Application(window);

    // Main loop
    ImGui::PushStyleVar(ImGuiStyleVar_ChildWindowRounding, 0.0f);
    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
        ImGui_ImplGlfwGL3_NewFrame();
        
        // Calculate time delta in seconds
        auto currentTime = std::chrono::steady_clock::now();
        std::chrono::duration<double> duration = currentTime - startTime;
        float deltaSeconds = duration.count();
        
        // Call application update
        application.Update(deltaSeconds);

        // Rendering
        int display_w, display_h;
        glfwGetFramebufferSize(window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glClearColor(clear_color.x, clear_color.y, clear_color.z, clear_color.w);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui::Render();
        glfwSwapBuffers(window);
    }

    // Cleanup
    ImGui_ImplGlfwGL3_Shutdown();
    glfwTerminate();

    return 0;
}
