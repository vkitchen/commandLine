#ifndef TIMER_HPP
#define TIMER_HPP

#include <chrono>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "textBox.hpp"
#include "renderArt.hpp"
#include "readArt.hpp"
#include "terminalHelpers.hpp"

extern int currentWallIndex;
extern std::chrono::steady_clock::time_point timeAtStartTime;

/*!
 * @file
 * @brief Header file for timer.cpp
 * @details sette and getter methods for the timer functionality
 */


/**
 * @brief Sets beginning time for timer
 * 
 * @return time_point of when the timer was started (when this function is called)
 */
void startTimer();


/**
 * @brief check remining time form running timer
 * 
 * @param startTime the chrono time of when the timer was started using startTimer()
 * @param totalSeconds the maximum total amount of time the timer can run for 
 * @return int of how many seconds remain on timer
 */
int checkRemainingTime(std::chrono::steady_clock::time_point startTime, int totalSeconds);


/**
 * @brief Print remianing time to timer to screen, formated to mm:ss
 * 
 * @param remainingTime [in] amount of remaining time in seconds
 */
void printRemainingTime(int remainingTime, bool currentRoomZoomed);

#endif // TIMER_HPP
