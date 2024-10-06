#ifndef OPTIONS_BOX_HPP
#define OPTIONS_BOX_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <chrono>
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
 * @brief Creates and displays box with options to select
 * @details Evenly disperses the options in a vertical fashion (For Now)
 * @param startX [in] top left X coord of box
 * @param endX [in] bottom right X coord of box
 * @param startY [in] top left Y coord of box
 * @param endY [in] bottom right Y coord of box
 * @param optionsIn [in] string array of options to be displayed and chosen from
 * @param timerRunning [in] bool of whether the timer is running, checks if rendering of timer needed
 * @param totalTimerSeconds [in] the amount of time allocated to the timer
 * @param currentRoomZoomed [in] bool current rooms zoom status
 * @return int returned is index of option chosen in inputed array
 */
int renderOptionsBox(int startX, int endX, int startY, int endY, std::vector<std::string> optionsIn, bool* timerRunning, const int totalTimerSeconds, bool currentRoomZoomed);

/**
 * @brief Creates and displays box that user can input word into
 * @details only listens for char (a-Z) and " " input. 
 * Needs to be calle din while loop that is checking global varibel 'input' is not your desired terminating key press
 * @param wordIn 
 * @return std::string 
 */
std::string stringInputBox(std::string wordIn);

#endif // OPTIONS_BOX_HPP
