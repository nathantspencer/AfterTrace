#pragma once

#include "GUI/StylePainter.h"

/*! Draws `ImGui` elements for the main menu bar on each update.
 *
 *  A single instance of this class is created by `Application`.
 */
class MainMenuBar
{
    public:
    
        /*! The constructor for `MainMenuBar`.
         */
        MainMenuBar();
    
        /*! The deconstructor for `MainMenuBar`.
         */
        ~MainMenuBar();
    
        /*! Contains the `ImGui` calls that draw the main menu bar.
         *
         *  @param deltaSeconds the `float` number of seconds since the last update
         */
        void    Update(float deltaSeconds);
};
