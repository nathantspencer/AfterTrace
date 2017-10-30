#pragma once

#include "GUI/StylePainter.h"

class MainMenuBar
{
    public:
        MainMenuBar(StylePainter* stylePainter);
        ~MainMenuBar();
    
        void    Update(float deltaSeconds);
    
    private:
    
        StylePainter*   m_stylePainter;
};
