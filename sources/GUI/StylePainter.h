#pragma once

#include <imgui.h>
#include <map>
#include <string>

/*! Applies `ImGui` styles to other GUI elements.
 *
 *  A single instance of this class is created by `Application` and passed to the `GUI`
 *  elements it owns.
 */
class StylePainter
{
  public:
    
    /*! The constructor for `StylePainter`.
     */
    StylePainter();
    
    /*! The destructor for `StylePainter`.
     */
    ~StylePainter();
    
    /*! Applies `ImGui` styles used by the `AdjustmentWindow` class.
     *
     *  This function should be called just before `ImGui::Begin()` in order to apply the
     *  appropriate styles to the new window it creates.
     */
    void    PaintAdjustmentWindow();
    
    /*! Applies `ImGui` styles used by the `RenderOptionsWindow` class.
     *
     *  This function should be called just before `ImGui::Begin()` in order to apply the
     *  appropriate styles to the new window it creates.
     */
    void    PaintRenderOptionsWindow();
    
    /*! Applies `ImGui` styles used by the `DataWindow` class.
     *
     *  This function should be called just before `ImGui::Begin()` in order to apply the
     *  appropriate styles to the new window it creates.
     */
    void    PaintDataWindow();
    
    /*! Applies `ImGui` styles used by the `MainMenuBar` class.
     *
     *  This function should be called just before `ImGui::Begin()` in order to apply the
     *  appropriate styles to the new window it creates.
     */
    void    PaintMainMenuBar();
    
  private:
    
    std::map<std::string, ImVec4>   m_colors;
};
