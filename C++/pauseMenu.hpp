#ifndef PAUSE_MENU_HPP
#define PAUSE_MENU_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "textBox.hpp"
#include "startScreen.hpp"
#include "renderArt.hpp"
#include "optionsBox.hpp"
#include "terminalHelpers.hpp"
#include "saveOrLoadGame.hpp"
#include <windows.h>


/*!
 * @file
 * @brief Header file for pauseMenu.cpp
 * @details Creates and displays the pause menu
 */


extern char input;
extern bool running;
extern char** art;
extern int artWidth, artHeight;
extern bool running;

/**
 * @brief Creates and displays the pause menu
 * 
 */
void pauseMenu(bool currentRoomZoomed);

#endif // PAUSE_MENU_HPP
