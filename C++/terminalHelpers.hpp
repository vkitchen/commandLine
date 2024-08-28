#ifndef TERMINAL_HELPERS_HPP
#define TERMINAL_HELPERS_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

/*!
 * @file
 * @brief Header file for terminalHelpers.cpp
 * @details Provides other files the ability to get details about the teminal, manipulate basic settings, and clear the screen
 */


extern int totalConsoleHeight, totalConsoleWidth, fullScreenTextBoxHeight;

/**
 * @brief Get the and set full screen width and height global variables
 * @details Global variables affected = totalConsoleHeight, totalConsoleWidth, fullScreenTextBoxHeight
 */
void getFullScreenDimensions();

/**
 * @brief Hides console cursor from view
 * @details Intended for smoother rendering of images and transition between images
 */
void hideCursor();

/**
 * @brief Clears whole terminal to be empty
 * @details Clears terminal by printing ' ' in every available char space
 */
void clearWholeScreen();

/**
 * @brief Clears selected range of lines from terminal
 * @details Can only be used to clear consecutive lines, if want two seperate blocks of lies with lines in the middle unaffected, call function twice.
 * Lines are counted form top of creen to bottom of screen
 * @param startY [in]  Line clearing beginning from and including this line
 * @param endY [in] Line clearing ending and including this line
 */
void clearPartialScreen(int startY, int endY);

/**
 * @brief Makes comand prompt window fullscreen
 * @details Leaves generic windows outer boarder in place
 */
void setFullScreen();

/**
 * @brief Enables console to print UTF-8 for image printing
 * @details All images generated using UTF-8, causes issues when UTF-8 and ASCII text are present together
 */
void enableUTF8Console();


#endif // TERMINAL_HELPERS_HPP
