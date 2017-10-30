#include "StylePainter.h"

StylePainter::StylePainter() :
    m_colors(std::map<std::string, ImVec4>())
{
    m_colors["gray"]        = ImVec4(0.24f, 0.24f, 0.29f, 1.00f);
    m_colors["darkGray"]    = ImVec4(0.11f, 0.12f, 0.15f, 1.00f);
    m_colors["purple"]      = ImVec4(0.25f, 0.25f, 0.40f, 1.00f);
    m_colors["lightPurple"] = ImVec4(0.30f, 0.30f, 0.44f, 1.00f);
    m_colors["whiteShadow"] = ImVec4(1.00f, 1.00f, 1.00f, 0.10f);
    m_colors["blackShadow"] = ImVec4(0.00f, 0.00f, 0.00f, 0.40f);
    m_colors["offWhite"]    = ImVec4(0.91f, 0.90f, 0.92f, 1.00f);
}

StylePainter::~StylePainter()
{
}

void StylePainter::PaintDataWindow()
{
    auto& style = ImGui::GetStyle();
    style.Colors[ImGuiCol_Text]             = m_colors["offWhite"];
    style.Colors[ImGuiCol_WindowBg]         = m_colors["darkGray"];
    style.Colors[ImGuiCol_Border]           = m_colors["blackShadow"];
    style.Colors[ImGuiCol_BorderShadow]     = m_colors["whiteShadow"];
    style.Colors[ImGuiCol_TitleBg]          = m_colors["purple"];
    style.Colors[ImGuiCol_TitleBgActive]    = m_colors["lightPurple"];
}

void StylePainter::PaintAdjustmentWindow()
{
    auto& style = ImGui::GetStyle();
    style.Colors[ImGuiCol_Text]             = m_colors["offWhite"];
    style.Colors[ImGuiCol_WindowBg]         = m_colors["gray"];
    style.Colors[ImGuiCol_Border]           = m_colors["blackShadow"];
    style.Colors[ImGuiCol_BorderShadow]     = m_colors["whiteShadow"];
    style.Colors[ImGuiCol_TitleBg]          = m_colors["purple"];
    style.Colors[ImGuiCol_TitleBgActive]    = m_colors["lightPurple"];
}
