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
    ImGui::EndMainMenuBar();
}
