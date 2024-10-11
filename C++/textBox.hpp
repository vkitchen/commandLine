/*!
 * @file
 * @brief Header file for textBox.cpp
 * @details Provides other files the ability to create and display boxes containing non-interactive text 
*/

#ifndef TEXT_BOX_HPP
#define TEXT_BOX_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <string>


extern int totalConsoleHeight, totalConsoleWidth;
extern bool room1VIEWED[];
extern bool room1ZOOMEDVIEWED[];
extern bool room2VIEWED[];
extern bool room2ZOOMEDVIEWED[];
extern bool room3VIEWED[];
extern bool room3ZOOMEDVIEWED[];

/**
 * @brief renders test box on screen with text
 * @details makes text appear in middle of box with scrolling effect
 * @param startX [in] top left X coord of box
 * @param endX [in] bottom right X coord of box
 * @param startY [in] top left Y coord of box
 * @param endY [in] bottom right Y coord of box
 * @param text [in] text to be displayed on screen
 */
void renderBox(int startX, int endX, int startY, int endY, const std::string& text, bool zoomedIn, bool wallSeen, bool zoomedWallSeen, const std::string& helperInstruction);

/**
 * @brief renders test box on screen with text
 * @details makes text appear in middle of box with scrolling effect
 * @param helperInstruction [in] text to be displayed in bottom right of box
 * @param boxWidth [in] width of displayed box (amount of characters)
 * @param boxHeight [in] height of displayed box (amount of lines)
 */
void renderHelperInstruction(const std::string& helperInstruction, int boxWidth, int boxHeight);

#endif // TEXT_BOX_HPP