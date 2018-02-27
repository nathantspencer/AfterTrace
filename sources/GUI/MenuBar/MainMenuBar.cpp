#include "MainMenuBar.h"

#include <imgui.h>
#include <nfd.h>

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
        if (ImGui::MenuItem("Open"))
        {
            nfdchar_t* selectedFile;
            nfdresult_t result = NFD_OpenDialog(NULL, NULL, &selectedFile);
            
            if (result == NFD_OKAY)
            {
            }
        }
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
