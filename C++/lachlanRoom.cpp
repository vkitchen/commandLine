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
bool doorOpen = false;

const std::vector<std::string> bodyParts = {"HEAD", "SHOULDER", "KNEE", "TOE"};
std::string tempAnswer;
std::vector<std::string> bodyPartsCopy;



std::string roomAnswer = "HEADSHOULDERKNEETOE";

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
    std::string timeString;
    int minutes = remainingTime / 60;
    int seconds = remainingTime % 60;

    if (seconds < 10) {
        timeString = std::to_string(minutes) + ":0" + std::to_string(seconds);
    } else {
        timeString = std::to_string(minutes) + ":" + std::to_string(seconds);
    }

    renderBox((totalConsoleWidth/5)*4, totalConsoleWidth, (fullScreenTextBoxHeight - 5), fullScreenTextBoxHeight, timeString, lachlanZoomed, room2VIEWED[currentWallIndex], room2ZOOMEDVIEWED[currentWallIndex]);
}

void runLachlan()
{
    roomNumber = 3;
    lachlanZoomed = globalZoomed;
    while (!solvedLachlan)
    {
        //clearWholeScreen();

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
                outputLachlan = "\u266A \u266B  Head, shoulders, knees, and toes  \u266B \u266A";
                renderBox(0, totalConsoleWidth, fullScreenTextBoxHeight, totalConsoleHeight, outputLachlan, lachlanZoomed, room2VIEWED[currentWallIndex], room2ZOOMEDVIEWED[currentWallIndex]);
                if (room2VIEWED[currentWallIndex] == false)
                    room2VIEWED[currentWallIndex] = true;
                break;
            case 2:
                loadArt(room2[currentWallIndex], art, artWidth, artHeight);
                renderCenteredArt(art, artWidth, artHeight);
                outputLachlan = "Crazy that a turtle made this";
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
            if(room2ZOOMEDVIEWED[currentWallIndex] == false) room2ZOOMEDVIEWED[currentWallIndex] = true;
            switch (currentWallIndex) 
            {
            case 0:
                if (!timerRunning && !doorOpen) {
                    outputLachlan = "Flip the timer? (Y/N)";
                    renderBox(0, totalConsoleWidth, fullScreenTextBoxHeight, totalConsoleHeight, outputLachlan, lachlanZoomed, room2VIEWED[currentWallIndex], room2ZOOMEDVIEWED[currentWallIndex]);
                    roomInputListenerLachlan(&timerRunning, &lachlanZoomed, &doorOpen, &solvedLachlan);
                    if (timerRunning) {
                        timeAtStartTime = startTimer();
                    }
                } else if (timerRunning && !doorOpen) {
                    outputLachlan = "Man's looking suss";
                    renderBox(0, totalConsoleWidth, fullScreenTextBoxHeight, totalConsoleHeight, outputLachlan, lachlanZoomed, room2VIEWED[currentWallIndex], room2ZOOMEDVIEWED[currentWallIndex]);
                    //clearWholeScreen();
                    //int hourglassIndex = 4 + (((checkRemainingTime(timeAtStartTime,totalTimerSeconds))*(8-4)) / (totalTimerSeconds));
                    //loadArt(room2ZOOMED[hourglassIndex], art, artWidth, artHeight);
                    //renderCenteredArt(art, artWidth, artHeight);
                } else if (doorOpen) {
                    outputLachlan = "Escape Owheo? (Y/N)";
                    renderBox(0, totalConsoleWidth, fullScreenTextBoxHeight, totalConsoleHeight, outputLachlan, lachlanZoomed, room2VIEWED[currentWallIndex], room2ZOOMEDVIEWED[currentWallIndex]);
                    roomInputListenerLachlan(&timerRunning, &lachlanZoomed, &doorOpen, &solvedLachlan);
                }
                if (input == 45) {
                    lachlanZoomed = false;
                    clearWholeScreen();
                    continue;
                }
                break;
            case 2:   
                if (!timerRunning) {
                    outputLachlan = "Art goes crazy";
                    renderBox(0, totalConsoleWidth, fullScreenTextBoxHeight, totalConsoleHeight, outputLachlan, lachlanZoomed, room2VIEWED[currentWallIndex], room2ZOOMEDVIEWED[currentWallIndex]);
                }
                else if (timerRunning && !doorOpen) {
                    if (bodyPartsCopy.size() == 0) {
                        tempAnswer = "";
                        bodyPartsCopy = bodyParts;
                    }
                    outputLachlan = "Buttons have appeared over some body parts. What order do you press them?";
                    renderBox(0, (totalConsoleWidth/5)*4, (fullScreenTextBoxHeight - 5), fullScreenTextBoxHeight, outputLachlan, lachlanZoomed, room2VIEWED[currentWallIndex], room2ZOOMEDVIEWED[currentWallIndex]);
                    int selectedBodyPart = renderOptionsBox(0, totalConsoleWidth, fullScreenTextBoxHeight, totalConsoleHeight, bodyPartsCopy);
                    tempAnswer = tempAnswer + bodyPartsCopy[selectedBodyPart];
                    bodyPartsCopy.erase(bodyPartsCopy.begin() + selectedBodyPart);

                    if (tempAnswer == roomAnswer) {
                        doorOpen = true;
                        timerRunning = false;
                        clearWholeScreen();
                    }
                }
                if (input == 45) {
                    lachlanZoomed = false;
                    clearWholeScreen();
                    continue;
                }
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
        roomInputListenerLachlan(&timerRunning, &lachlanZoomed, &doorOpen, &solvedLachlan);

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
        if (running == false) {
            return;
        }
        Sleep(20); // Delay to control game speed
    }
    // GAME LOOP
    //runCallum(); // goes to next room after being solved
}