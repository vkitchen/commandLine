#include "lachlanRoom.hpp"
#include "optionsBox.hpp"
#include "timer.hpp"
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

const std::vector<std::string> bodyParts = {"HEAD", "SHOULDER", "KNEE", "TOE", "EXIT TO SEARCH ROOM AGAIN"};
std::string tempAnswer;
std::vector<std::string> bodyPartsCopy;
std::string outputLachlan, helperInstructionLachlan;


std::string roomAnswer = "TOEKNEEHEADSHOULDER";

const int totalTimerSeconds = 90; // 2 minute timer




void runLachlan()
{
    roomNumber = 3;
    lachlanZoomed = globalZoomed;
    while (!solvedLachlan)
    {
        //clearWholeScreen();

        if (lachlanZoomed == false)
        {
            helperInstructionLachlan = "PRESS + TO ZOOM IN";
            switch (currentWallIndex)
            {
            case 0:
                loadArt(room2[currentWallIndex], art, artWidth, artHeight);
                renderCenteredArt(art, artWidth, artHeight);
                outputLachlan = "A door with a weird lock on it";
                renderBox(0, totalConsoleWidth, fullScreenTextBoxHeight, totalConsoleHeight, outputLachlan, lachlanZoomed, room2VIEWED[currentWallIndex], room2ZOOMEDVIEWED[currentWallIndex], helperInstructionLachlan);
                if (room2VIEWED[currentWallIndex] == false)
                    room2VIEWED[currentWallIndex] = true;
                break;
            case 1:
                loadArt(room2[currentWallIndex], art, artWidth, artHeight);
                renderCenteredArt(art, artWidth, artHeight);
                outputLachlan = "There is quiet music coming from those speakers...";
                renderBox(0, totalConsoleWidth, fullScreenTextBoxHeight, totalConsoleHeight, outputLachlan, lachlanZoomed, room2VIEWED[currentWallIndex], room2ZOOMEDVIEWED[currentWallIndex], helperInstructionLachlan);
                if (room2VIEWED[currentWallIndex] == false)
                    room2VIEWED[currentWallIndex] = true;
                break;
            case 2:
                loadArt(room2[currentWallIndex], art, artWidth, artHeight);
                renderCenteredArt(art, artWidth, artHeight);
                outputLachlan = "Crazy that a turtle made this";
                renderBox(0, totalConsoleWidth, fullScreenTextBoxHeight, totalConsoleHeight, outputLachlan, lachlanZoomed, room2VIEWED[currentWallIndex], room2ZOOMEDVIEWED[currentWallIndex], helperInstructionLachlan);
                if (room2VIEWED[currentWallIndex] == false)
                    room2VIEWED[currentWallIndex] = true;
                break;
            case 3:
                loadArt(room2[currentWallIndex], art, artWidth, artHeight);
                renderCenteredArt(art, artWidth, artHeight);
                outputLachlan = "Somebody is bad at anatomy";
                renderBox(0, totalConsoleWidth, fullScreenTextBoxHeight, totalConsoleHeight, outputLachlan, lachlanZoomed, room2VIEWED[currentWallIndex], room2ZOOMEDVIEWED[currentWallIndex], helperInstructionLachlan);
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
            helperInstructionLachlan = "PRESS - TO ZOOM OUT";
            switch (currentWallIndex) 
            {
            case 0:
                if (!timerRunning && !doorOpen) {
                    outputLachlan = "Flip the timer? (Y/N)";
                    renderBox(0, totalConsoleWidth, fullScreenTextBoxHeight, totalConsoleHeight, outputLachlan, lachlanZoomed, room2VIEWED[currentWallIndex], room2ZOOMEDVIEWED[currentWallIndex], helperInstructionLachlan);
                    roomInputListenerLachlan(&timerRunning, &lachlanZoomed, &doorOpen, &solvedLachlan);
                } else if (timerRunning && (checkRemainingTime(timeAtStartTime,totalTimerSeconds) == 0)) {
                    startTimer();  
                } else if (timerRunning && !doorOpen) {
                    outputLachlan = "Man's looking suss";
                    renderBox(0, totalConsoleWidth, fullScreenTextBoxHeight, totalConsoleHeight, outputLachlan, lachlanZoomed, room2VIEWED[currentWallIndex], room2ZOOMEDVIEWED[currentWallIndex], helperInstructionLachlan);
                    int hourglassIndex = 4 + (((checkRemainingTime(timeAtStartTime,totalTimerSeconds))*(7-4)) / (totalTimerSeconds));
                    
                    loadArt(room2ZOOMED[hourglassIndex], art, artWidth, artHeight);
                    renderCenteredArt(art, artWidth, artHeight);
                } else if (doorOpen) {
                    outputLachlan = "Escape Owheo? (Y/N)";
                    renderBox(0, totalConsoleWidth, fullScreenTextBoxHeight, totalConsoleHeight, outputLachlan, lachlanZoomed, room2VIEWED[currentWallIndex], room2ZOOMEDVIEWED[currentWallIndex], "Press Enter");
                    roomInputListenerLachlan(&timerRunning, &lachlanZoomed, &doorOpen, &solvedLachlan);
                }
                if (input == 45) {
                    lachlanZoomed = false;
                    clearWholeScreen();
                    continue;
                }
                break;
            case 1:
                outputLachlan = "\u266A \u266B  Head, shoulders, knees, and toes  \u266B \u266A";
                renderBox(0, totalConsoleWidth, fullScreenTextBoxHeight, totalConsoleHeight, outputLachlan, lachlanZoomed, room2VIEWED[currentWallIndex], room2ZOOMEDVIEWED[currentWallIndex], helperInstructionLachlan);
                break;
            case 2:   
                if (!timerRunning) {
                    outputLachlan = "Art goes crazy";
                    renderBox(0, totalConsoleWidth, fullScreenTextBoxHeight, totalConsoleHeight, outputLachlan, lachlanZoomed, room2VIEWED[currentWallIndex], room2ZOOMEDVIEWED[currentWallIndex], helperInstructionLachlan);
                }
                if (doorOpen) {
                    outputLachlan = "I think I heard a click from the door";
                    renderBox(0, totalConsoleWidth, fullScreenTextBoxHeight, totalConsoleHeight, outputLachlan, lachlanZoomed, room2VIEWED[currentWallIndex], room2ZOOMEDVIEWED[currentWallIndex], helperInstructionLachlan);
                }
                else if (timerRunning && !doorOpen) {
                    if (bodyPartsCopy.size() == 1 || bodyPartsCopy.size() == 0) {
                        tempAnswer = "";
                        bodyPartsCopy = bodyParts;
                    }

                    outputLachlan = "Buttons have appeared over some body parts. What order do you press them?";
                    renderBox(0, (totalConsoleWidth/7)*6, (fullScreenTextBoxHeight - 5), fullScreenTextBoxHeight, outputLachlan, lachlanZoomed, room2VIEWED[currentWallIndex], room2ZOOMEDVIEWED[currentWallIndex], "");
                    int selectedBodyPart = renderOptionsBox(0, totalConsoleWidth, fullScreenTextBoxHeight, totalConsoleHeight, bodyPartsCopy, &timerRunning, totalTimerSeconds, lachlanZoomed);
                    tempAnswer = tempAnswer + bodyPartsCopy[selectedBodyPart];

                    if (bodyPartsCopy[selectedBodyPart] == "EXIT TO SEARCH ROOM AGAIN") {
                        bodyPartsCopy = bodyParts;
                        lachlanZoomed = false;
                        clearWholeScreen();
                        break;
                    }

                    bodyPartsCopy.erase(bodyPartsCopy.begin() + selectedBodyPart);

                    if (tempAnswer == roomAnswer) {
                        doorOpen = true;
                        timerRunning = false;
                        clearWholeScreen();
                    }
                }
                break;
            case 3:
                outputLachlan = "I wonder if this is important information...";
                renderBox(0, totalConsoleWidth, fullScreenTextBoxHeight, totalConsoleHeight, outputLachlan, lachlanZoomed, room2VIEWED[currentWallIndex], room2ZOOMEDVIEWED[currentWallIndex], helperInstructionLachlan);
                break;
            default:
                break;
            }
        }

        if (timerRunning) {
            int timeToPrint = checkRemainingTime(timeAtStartTime, totalTimerSeconds);
            if (timeToPrint > 0) {
                printRemainingTime(timeToPrint, lachlanZoomed);
            } else {
                timerRunning = false;
            }
        }

        // Clear the input
        input = ' ';
        if (input == ' ') {
            processInput();
        }
        roomInputListenerLachlan(&timerRunning, &lachlanZoomed, &doorOpen, &solvedLachlan);

        if (running == false) {
            return;
        }
        Sleep(20); // Delay to control game speed
    }
    // GAME LOOP
    //runCallum(); // goes to next room after being solved
}