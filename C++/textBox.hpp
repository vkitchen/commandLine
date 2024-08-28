#ifndef TEXT_BOX_HPP
#define TEXT_BOX_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

/*!
 * @file
 * @brief Header file for textBox.cpp
 * @details Provides other files the ability to create and display boxes containing non-interactive text 
 */


extern int totalConsoleHeight, totalConsoleWidth;

/**
 * @brief renders test box on screen with text
 * @details makes text appear in middle of box with scrolling effect
 * @param startX [in] top left X coord of box
 * @param endX [in] bottom right X coord of box
 * @param startY [in] top left Y coord of box
 * @param endY [in] bottom right Y coord of box
 * @param text [in] text to be displayed on screen
 */
void renderBox(int startX, int endX, int startY, int endY, const std::string& text);

#endif // TEXT_BOX_HPP
