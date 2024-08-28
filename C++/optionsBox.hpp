#ifndef OPTIONS_BOX_HPP
#define OPTIONS_BOX_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
/*!
 * @file
 * @brief optionsBox.cpp
 */

extern int totalConsoleHeight, totalConsoleWidth;

/**
 * @brief Creates and displays box with options to select
 * @details 
 * @param startX [in] top left X coord of box
 * @param endX [in] bottom right X coord of box
 * @param startY [in] top left Y coord of box
 * @param endY [in] bottom right Y coord of box
 * @param options [in] string array of options to be displayed and chosen from
 * @return int returned is index of option chosen in inputed array
 */
int renderOptionsBox(int startX, int endX, int startY, int endY, std::vector<std::string> options);

/**
 * @brief 
 * 
 * @param wordIn 
 * @return std::string 
 */
std::string stringInputBox(std::string wordIn);

#endif // OPTIONS_BOX_HPP
