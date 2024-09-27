#ifndef RENDER_ART_HPP
#define RENDER_ART_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stdexcept>

/*!
 * @file
 * @brief Header file for renderArt.cpp
 * @details Provides other files the ability to display .txt file art to the terminal
 */


extern char input;
extern bool running;
extern const std::string room0[];
extern const std::string room0ZOOMED[];
extern const std::string room1[];
extern const std::string room1ZOOMED[];
extern const std::string room2ZOOMED[];
extern const std::string room2[];
extern const std::string room3[];
extern const std::string room3ZOOMED[];
extern const std::string room4[];
extern char** art;
extern int artWidth, artHeight;
extern bool testMode;

/**
 * @brief Loads art to be used/printed
 * @details stores ASCII art in labal variable art, also sets artWidth and artHeight
 * @param filename path to .txt file containing art you wish to load and later use
 * @param art [in] string for art to be stored as for printing
 * @param artWidth [in] the width of the txt file (largest amount of characters before /n)
 * @param artHeight [in] amount of lines in txt file
 */
void loadArt(const std::string& filename, char** &art, int &artWidth, int &artHeight);

/**
 * @brief Prints art to center of the terminal
 * @details loadArt must be called first to initialized the 'art' global variable
 * 
 * @param art [in] string for art to be read and printed from
 * @param artWidth [in] the width of the txt file (largest amount of characters before /n)
 * @param artHeight [in] amount of lines in txt file
 */
void renderCenteredArt(char** art, int artWidth, int artHeight);

/**
 * @brief Prints art to the terminal
 * @details can print art wherever suits with the top left corner being given by startX and startY
 * 
 * @param art [in] string for art to be read and printed from
 * @param artWidth [in] the width of the txt file (largest amount of characters before /n)
 * @param artHeight [in] amount of lines in txt file
 * @param startX [in] 
 * @param startY [in]
 */
void renderArt(char** art, int artWidth, int artHeight, int startX, int startY);

#endif // RENDER_ART_HPP

