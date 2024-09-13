#include "lachlanRoom.hpp"
#include "optionsBox.hpp"
#include <chrono>
#include <sstream>
#include <iostream>

/*!
 * @file
 * @brief lachlanRoom.cpp
 */

bool solvedLachlan = false;
bool timerRunning = false;

int totalTimerSeconds = 120; // 2 minute timer
std::chrono::time_point<std::chrono::steady_clock> timeAtStartTime;

std::string outputLachlan;


std::chrono::time_point<std::chrono::steady_clock> startTimer() {
    return std::chrono::steady_clock::now();
}

int checkRemainingTime(std::chrono::time_point<std::chrono::steady_clock> startTime, int totalSeconds) {
    auto currentTime = std::chrono::steady_clock::now();

    auto elapsedTime = std::chrono::duration_cast<std::chrono::seconds>(currentTime - startTime).count();

    int remainingTime = totalSeconds - elapsedTime;

    if (remainingTime < 0) { remainingTime = 0;}

    return remainingTime;
}

void printRemainingTime(int remainingTime) {
    int minutes = remainingTime / 60;
    int seconds = remainingTime % 60;

    std::string timeString = std::to_string(minutes) + ":" + std::to_string(seconds);

    renderBox(0, (totalConsoleWidth/5), (fullScreenTextBoxHeight - 5), fullScreenTextBoxHeight, timeString);
}

void runLachlan()
{
    zoomed = false;
    currentWallIndex = 0;
    while (!solvedLachlan)
    {

        if (input == 'q')
        {
            running = false;
            return;
        }
        if (zoomed == false)
        {
            switch (currentWallIndex)
            {
            case 0:
                loadArt(room2[currentWallIndex], art, artWidth, artHeight);
                renderCenteredArt(art, artWidth, artHeight);
                outputLachlan = "LACHLANDS ROOM WOOOOOO";
                renderBox(0, totalConsoleWidth, fullScreenTextBoxHeight, totalConsoleHeight, outputLachlan);
                if (room2VIEWED[currentWallIndex] == false)
                    room2VIEWED[currentWallIndex] = true;
                break;
            case 1:
                loadArt(room2[currentWallIndex], art, artWidth, artHeight);
                renderCenteredArt(art, artWidth, artHeight);
                outputLachlan = "LACHLANDS ROOM WOOOOOO";
                renderBox(0, totalConsoleWidth, fullScreenTextBoxHeight, totalConsoleHeight, outputLachlan);
                if (room2VIEWED[currentWallIndex] == false)
                    room2VIEWED[currentWallIndex] = true;
                break;
            case 2:
                loadArt(room2[currentWallIndex], art, artWidth, artHeight);
                renderCenteredArt(art, artWidth, artHeight);
                outputLachlan = "LACHLANDS ROOM WOOOOOO";
                renderBox(0, totalConsoleWidth, fullScreenTextBoxHeight, totalConsoleHeight, outputLachlan);
                if (room2VIEWED[currentWallIndex] == false)
                    room2VIEWED[currentWallIndex] = true;
                break;
            case 3:
                loadArt(room2[currentWallIndex], art, artWidth, artHeight);
                renderCenteredArt(art, artWidth, artHeight);
                outputLachlan = "LACHLANDS ROOM WOOOOOO";
                renderBox(0, totalConsoleWidth, fullScreenTextBoxHeight, totalConsoleHeight, outputLachlan);
                if (room2VIEWED[currentWallIndex] == false)
                    room2VIEWED[currentWallIndex] = true;
                break;
            default:
                break;
            }
        } else if (zoomed == true) {
            clearWholeScreen();
            loadArt(room2ZOOMED[currentWallIndex], art, artWidth, artHeight);
            renderCenteredArt(art, artWidth, artHeight);

            switch (currentWallIndex) 
            {
            case 0:
                if (!timerRunning) {
                    outputLachlan = "Flip the timer? (Y/N)";
                    renderBox(0, totalConsoleWidth, fullScreenTextBoxHeight, totalConsoleHeight, outputLachlan);
                    roomInputListenerLachlan(&timerRunning);
                    if (timerRunning) {
                        timeAtStartTime = startTimer();
                    }
                } else if (timerRunning) {
                    clearWholeScreen();
                    int hourglassIndex = 4 + (((checkRemainingTime(timeAtStartTime,totalTimerSeconds))*(8-4)) / (totalTimerSeconds));
                    loadArt(room2ZOOMED[hourglassIndex], art, artWidth, artHeight);
                    renderCenteredArt(art, artWidth, artHeight);
                    // TODO: print timer and update timer in main loop of Lachlan room
                }
                break;
            case 2:   

                break;
            default:
                break;
            }
        }

        // Clear the input
        input = ' ';
        while (input == ' ') {
            processInput();
        }
        roomInputListenerLachlan(&timerRunning);
        
        if (timerRunning) {
            int timeToPrint = checkRemainingTime(timeAtStartTime, totalTimerSeconds);
            printRemainingTime(timeToPrint);
        }

        if (input == 's') {
            solvedLachlan = true;
        }
        Sleep(20); // Delay to control game speed
    }
    // GAME LOOP
}