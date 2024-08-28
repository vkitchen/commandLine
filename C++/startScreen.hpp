#ifndef START_SCREEN_HPP
#define START_SCREEN_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

/*!
 * @file
 * @brief Header file for startScreen.cpp
 * @details Creates and displays the start screen
 */


extern char input;
extern bool running;
extern char** art;
extern int artWidth, artHeight;
extern bool running;

/**
 * @brief Creates and displays the start screen
 * 
 */
void startScreen();

#endif // START_SCREEN_HPP
