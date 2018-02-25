#include "MainMenuBar.h"

#include <imgui.h>

MainMenuBar::MainMenuBar()
{
}

MainMenuBar::~MainMenuBar()
{
}

void MainMenuBar::Update(float deltaSeconds)
{
    ImGui::BeginMainMenuBar();
    
    if (ImGui::BeginMenu("File"))
    {
        ImGui::MenuItem("Dummy Menu Item");
        ImGui::EndMenu();
    }
    
    if (ImGui::BeginMenu("Edit"))
    {
        ImGui::MenuItem("Dummy Menu Item");
        ImGui::EndMenu();
    }
    
    if (ImGui::BeginMenu("View"))
    {
        ImGui::MenuItem("Dummy Menu Item");
        ImGui::EndMenu();
    }
    
    ImGui::EndMainMenuBar();
}
