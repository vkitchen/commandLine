#include "introRoom.hpp"
#include "optionsBox.hpp"

/*!
 * @file
 * @brief introRoom.cpp
 */

bool solvedIntro = false;
bool introZoomed = false;
std::string outputIntro;
std::string borderCharIntro;
std::string answerIntro;
std::string instructionIntro, helperInstructionIntro;

// test

void runIntro(){
    introZoomed = globalZoomed;
    while (!solvedIntro) {
        if (!running) return;
        if(introZoomed == false) {
            helperInstructionIntro = "PRESS + TO ZOOM IN";
            switch (currentWallIndex)
            {
            case 0:
                loadArt(room0[currentWallIndex], art, artWidth, artHeight);
                renderCenteredArt(art, artWidth, artHeight);
                outputIntro = "Welcome to Escape Owheo! You can zoom in with the + key and zoom back out with the - key to get some more detail";
                renderBox(0, totalConsoleWidth, fullScreenTextBoxHeight, totalConsoleHeight, outputIntro, introZoomed, room0VIEWED[currentWallIndex], room0ZOOMEDVIEWED[currentWallIndex], helperInstructionIntro);
                if(room0VIEWED[currentWallIndex] == false) room0VIEWED[currentWallIndex] = true;
                break;
            case 1:
                loadArt(room0[currentWallIndex], art, artWidth, artHeight);
                renderCenteredArt(art, artWidth, artHeight);
                outputIntro = "Every puzzle room will have 4 walls, Do you recognise where you are?";
                renderBox(0, totalConsoleWidth, fullScreenTextBoxHeight, totalConsoleHeight, outputIntro, introZoomed, room0VIEWED[currentWallIndex], room0ZOOMEDVIEWED[currentWallIndex], "");
                if(room0VIEWED[currentWallIndex] == false) room0VIEWED[currentWallIndex] = true;
                break;
            case 2:
                loadArt(room0[currentWallIndex], art, artWidth, artHeight);
                renderCenteredArt(art, artWidth, artHeight);
                outputIntro = "If you have looked at all the walls zoom in and enter 'START' to load the first floor. Good Luck!\n"
                "You can always check these controls by pressing 'ESC'";            
                renderBox(0, totalConsoleWidth, fullScreenTextBoxHeight, totalConsoleHeight, outputIntro, introZoomed, room0VIEWED[currentWallIndex], room0ZOOMEDVIEWED[currentWallIndex], helperInstructionIntro);
                if(room0VIEWED[currentWallIndex] == false) room0VIEWED[currentWallIndex] = true;
                break;
            case 3:
                loadArt(room0[currentWallIndex], art, artWidth, artHeight);
                renderCenteredArt(art, artWidth, artHeight);
                outputIntro = "To complete levels answers must be input, usally you will zoom into a wall and be instructed to enter your input";
                renderBox(0, totalConsoleWidth, fullScreenTextBoxHeight, totalConsoleHeight, outputIntro, introZoomed, room0VIEWED[currentWallIndex], room0ZOOMEDVIEWED[currentWallIndex], "");
                if(room0VIEWED[currentWallIndex] == false) room0VIEWED[currentWallIndex] = true;
                break;
            default:
                break;
            }
        }else if(introZoomed == true){
            helperInstructionIntro = "PRESS + TO ZOOM OUT";
            loadArt(room0ZOOMED[currentWallIndex], art, artWidth, artHeight);
            renderCenteredArt(art, artWidth, artHeight);
            switch (currentWallIndex)
            {
            case 2:
                instructionIntro = "input your answer:";
                renderBox(0, (totalConsoleWidth/5), (fullScreenTextBoxHeight - 5), fullScreenTextBoxHeight, instructionIntro, introZoomed, TRUE, TRUE, "");
                answerIntro = stringInputBox("");
                if (answerIntro == "start" || answerIntro == "Start" || answerIntro == "START") {
                    introZoomed = false;
                    clearWholeScreen();
                    solvedIntro = true;
                    currentWallIndex = 0;
                    break;
                } else if (input == 45) {
                    introZoomed = false;
                    clearWholeScreen();
                    continue;
                } else {
                    // This extra else statement makes it so any wrong input will reset the screen
                    // Could be better but works for now
                   // clearWholeScreen();
                    continue;
                }
                break;
            case 0:
                outputIntro = "well done, if you want to look at other walls use the left and right arrow keys. Zoom back out and give it a try ...";    
                renderBox(0, totalConsoleWidth, fullScreenTextBoxHeight, totalConsoleHeight, outputIntro, introZoomed, room0VIEWED[currentWallIndex], room0ZOOMEDVIEWED[currentWallIndex], helperInstructionIntro);
                if(room0ZOOMEDVIEWED[currentWallIndex] == false) room0ZOOMEDVIEWED[currentWallIndex] = true;        
                if (input == 45) {
                    introZoomed = false;
                    clearWholeScreen();
                    continue;
                }
                break;
            default:
                break;
            }
        }

        input = ' ';
        if(input == ' ' && !solvedIntro) processInput();
        roomInputListenerIntro(&introZoomed);

        // Testing purposes
        // if(input =='s') solvedIntro = true;
        
        Sleep(20); // Delay to control game speed
    }
    if (!running) return;
    // GAME LOOP
    runAnthony(); // goes to next room after being solved
} 