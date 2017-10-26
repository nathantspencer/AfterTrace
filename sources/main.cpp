#include <imgui.h>
#include "imgui_impl_glfw_gl3.h"
#include <stdio.h>
#include <GL/gl3w.h>
#include <GLFW/glfw3.h>

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

    // Toggle display of ImGui demo here!
    bool showImGuiDemo = true;
    bool showAdjustmentWindow = true;
    bool showDataWindow = true;
    
    // Background color
    ImVec4 clear_color = ImVec4(0.25f, 0.25f, 0.25f, 1.0f);

    // Main loop
    ImGui::PushStyleVar(ImGuiStyleVar_ChildWindowRounding, 0.0f);
    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
        ImGui_ImplGlfwGL3_NewFrame();

        // =================================vvv===============================
        // TODO: Move these windows to GUI
        // =================================vvv===============================
        
        // Adjustment Window
        ImGuiWindowFlags adjustmentWindowFlags = 0;
        adjustmentWindowFlags |= ImGuiWindowFlags_MenuBar;
        
        int width, height;
        glfwGetWindowSize(window, &width, &height);
        ImGui::SetNextWindowPos(ImVec2(0.0f, 0.0f), ImGuiCond_Once);
        ImGui::SetNextWindowSize(ImVec2(width / 3.0f, height), ImGuiCond_Once);
        ImGui::Begin("Adjustment Window", &showAdjustmentWindow, adjustmentWindowFlags);

        ImGui::Text("Scale, translate, & rotate models");
        ImGui::ColorEdit3("clear color", (float*)&clear_color);
        ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
        ImGui::End();
        
        // Data window
        ImGuiWindowFlags dataWindowFlags = 0;
        dataWindowFlags |= ImGuiWindowFlags_MenuBar;

        ImGui::SetNextWindowPos(ImVec2(width / 3.0f + 1.0f, 0.0f), ImGuiCond_Once);
        ImGui::SetNextWindowSize(ImVec2(width * 2.0f / 3.0f, height), ImGuiCond_Once);
        ImGui::Begin("Another Window", &showDataWindow, dataWindowFlags);

        if (ImGui::BeginMenuBar())
        {
            if (ImGui::BeginMenu("Menu"))
            {
                ImGui::MenuItem("Main menu bar", NULL, nullptr);
                ImGui::EndMenu();
            }
            ImGui::EndMenuBar();
        }
        ImGui::Text("Hello from another window!");
        ImGui::End();
        
        // ImGui demo window
        if (showImGuiDemo)
        {
            ImGui::SetNextWindowPos(ImVec2(650, 20), ImGuiCond_FirstUseEver);
            ImGui::ShowTestWindow(&showImGuiDemo);
        }
        
        // =================================^^^===============================

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
