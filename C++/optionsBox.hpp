#ifndef OPTIONS_BOX_HPP
#define OPTIONS_BOX_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
/*!
 * @file
 * @brief Header file for optionsBox.cpp
 * @details Provides other files the ability to create and display interactive boxes on screen
 */

extern int totalConsoleHeight, totalConsoleWidth;

/**
 * @brief Creates and displays box with options to select
 * @details Evenly disperses the options in a vertical fashion (For Now)
 * @param startX [in] top left X coord of box
 * @param endX [in] bottom right X coord of box
 * @param startY [in] top left Y coord of box
 * @param endY [in] bottom right Y coord of box
 * @param options [in] string array of options to be displayed and chosen from
 * @return int returned is index of option chosen in inputed array
 */
int renderOptionsBox(int startX, int endX, int startY, int endY, std::vector<std::string> options);

/**
 * @brief Creates and displays box that user can input word into
 * @details only listens for char (a-Z) and " " input. 
 * Needs to be calle din while loop that is checking global varibel 'input' is not your desired terminating key press
 * @param wordIn 
 * @return std::string 
 */
std::string stringInputBox(std::string wordIn);

#endif // OPTIONS_BOX_HPP
