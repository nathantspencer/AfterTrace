#include "MainMenuBar.h"

#include <imgui.h>

MainMenuBar::MainMenuBar(StylePainter* stylePainter) : m_stylePainter(stylePainter)
{
}

MainMenuBar::~MainMenuBar()
{
}

void MainMenuBar::Update(float deltaSeconds)
{
    m_stylePainter->PaintMainMenuBar();
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
