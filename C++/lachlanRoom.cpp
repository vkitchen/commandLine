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
bool lachlanZoomed = false;

const int totalTimerSeconds = 120; // 2 minute timer
std::chrono::steady_clock::time_point timeAtStartTime;

std::string outputLachlan;


std::chrono::steady_clock::time_point startTimer() {
    return std::chrono::steady_clock::now();
}

int checkRemainingTime(std::chrono::steady_clock::time_point startTime, int totalSeconds) {
    std::chrono::steady_clock::time_point currentTime = std::chrono::steady_clock::now();

    int elapsedTime = std::chrono::duration_cast<std::chrono::seconds>(currentTime - startTime).count();

    int remainingTime = totalSeconds - elapsedTime;

    if (remainingTime < 0) { 
        remainingTime = 0;
    }

    return remainingTime;
}

void printRemainingTime(int remainingTime) {
    int minutes = remainingTime / 60;
    int seconds = remainingTime % 60;

    std::string timeString = std::to_string(minutes) + ":" + std::to_string(seconds);

    renderBox(0, (totalConsoleWidth/5), (fullScreenTextBoxHeight - 5), fullScreenTextBoxHeight, timeString, lachlanZoomed, room2VIEWED[currentWallIndex], room2ZOOMEDVIEWED[currentWallIndex]);
}

void runLachlan()
{
    currentWallIndex = 0;
    while (!solvedLachlan)
    {
        //clearWholeScreen();
        if (input == 'q')
        {
            running = false;
            return;
        }
        if (lachlanZoomed == false)
        {
            switch (currentWallIndex)
            {
            case 0:
                loadArt(room2[currentWallIndex], art, artWidth, artHeight);
                renderCenteredArt(art, artWidth, artHeight);
                outputLachlan = "LACHLANDS ROOM WOOOOOO";
                renderBox(0, totalConsoleWidth, fullScreenTextBoxHeight, totalConsoleHeight, outputLachlan, lachlanZoomed, room2VIEWED[currentWallIndex], room2ZOOMEDVIEWED[currentWallIndex]);
                if (room2VIEWED[currentWallIndex] == false)
                    room2VIEWED[currentWallIndex] = true;
                break;
            case 1:
                loadArt(room2[currentWallIndex], art, artWidth, artHeight);
                renderCenteredArt(art, artWidth, artHeight);
                outputLachlan = "LACHLANDS ROOM WOOOOOO";
                renderBox(0, totalConsoleWidth, fullScreenTextBoxHeight, totalConsoleHeight, outputLachlan, lachlanZoomed, room2VIEWED[currentWallIndex], room2ZOOMEDVIEWED[currentWallIndex]);
                if (room2VIEWED[currentWallIndex] == false)
                    room2VIEWED[currentWallIndex] = true;
                break;
            case 2:
                loadArt(room2[currentWallIndex], art, artWidth, artHeight);
                renderCenteredArt(art, artWidth, artHeight);
                outputLachlan = "LACHLANDS ROOM WOOOOOO";
                renderBox(0, totalConsoleWidth, fullScreenTextBoxHeight, totalConsoleHeight, outputLachlan, lachlanZoomed, room2VIEWED[currentWallIndex], room2ZOOMEDVIEWED[currentWallIndex]);
                if (room2VIEWED[currentWallIndex] == false)
                    room2VIEWED[currentWallIndex] = true;
                break;
            case 3:
                loadArt(room2[currentWallIndex], art, artWidth, artHeight);
                renderCenteredArt(art, artWidth, artHeight);
                outputLachlan = "LACHLANDS ROOM WOOOOOO";
                renderBox(0, totalConsoleWidth, fullScreenTextBoxHeight, totalConsoleHeight, outputLachlan, lachlanZoomed, room2VIEWED[currentWallIndex], room2ZOOMEDVIEWED[currentWallIndex]);
                if (room2VIEWED[currentWallIndex] == false)
                    room2VIEWED[currentWallIndex] = true;
                break;
            default:
                break;
            }
        } else if (lachlanZoomed == true) {
            loadArt(room2ZOOMED[currentWallIndex], art, artWidth, artHeight);
            renderCenteredArt(art, artWidth, artHeight);

            switch (currentWallIndex) 
            {
            case 0:
                if (!timerRunning) {
                    outputLachlan = "Flip the timer? (Y/N)";
                    renderBox(0, totalConsoleWidth, fullScreenTextBoxHeight, totalConsoleHeight, outputLachlan, lachlanZoomed, room2VIEWED[currentWallIndex], room2ZOOMEDVIEWED[currentWallIndex]);
                    roomInputListenerLachlan(&timerRunning, &lachlanZoomed);
                    if(room1ZOOMEDVIEWED[0] == false) room1ZOOMEDVIEWED[0] = true;
                    if (timerRunning) {
                        timeAtStartTime = startTimer();
                    }
                } else if (timerRunning) {
                    outputLachlan = "Man's looking suss";
                    renderBox(0, totalConsoleWidth, fullScreenTextBoxHeight, totalConsoleHeight, outputLachlan, lachlanZoomed, room2VIEWED[currentWallIndex], room2ZOOMEDVIEWED[currentWallIndex]);
                    //clearWholeScreen();
                    //int hourglassIndex = 4 + (((checkRemainingTime(timeAtStartTime,totalTimerSeconds))*(8-4)) / (totalTimerSeconds));
                    //loadArt(room2ZOOMED[hourglassIndex], art, artWidth, artHeight);
                    //renderCenteredArt(art, artWidth, artHeight);
                    // TODO: print timer and update timer in main loop of Lachlan room
                } 
                if (input == 45) {
                    lachlanZoomed = false;
                    clearWholeScreen();
                    continue;
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
        if (input == ' ') {
            processInput();
        }
        roomInputListenerLachlan(&timerRunning, &lachlanZoomed);

        if (timerRunning) {
            int timeToPrint = checkRemainingTime(timeAtStartTime, totalTimerSeconds);
            if (timeToPrint > 0) {
                printRemainingTime(timeToPrint);
            } else {
                timerRunning = false;
            }
        }
        if (input == 's') {
            solvedLachlan = true;
        }
        Sleep(20); // Delay to control game speed
    }
    // GAME LOOP
}