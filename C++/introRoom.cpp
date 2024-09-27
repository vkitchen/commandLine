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
std::string instructionIntro;

// test

void runIntro(){
    while (!solvedIntro) {
        
        if(input == 'q'){
            running = false;
            return;
        }
        if(introZoomed == false) {
            switch (currentWallIndex)
            {
            case 0:
                loadArt(room0[currentWallIndex], art, artWidth, artHeight);
                renderCenteredArt(art, artWidth, artHeight);
                outputIntro = "Welcome to escape owheo! you can zoom in with the + key and zoom back out with the - key to get some more detail";
                renderBox(0, totalConsoleWidth, fullScreenTextBoxHeight, totalConsoleHeight, outputIntro, introZoomed, room0VIEWED[currentWallIndex], room0ZOOMEDVIEWED[currentWallIndex]);
                if(room0VIEWED[currentWallIndex] == false) room0VIEWED[currentWallIndex] = true;
                break;
            case 1:
                loadArt(room0[currentWallIndex], art, artWidth, artHeight);
                renderCenteredArt(art, artWidth, artHeight);
                outputIntro = "Every puzzle room will have 4 walls, Do you recognise where you are?";
                renderBox(0, totalConsoleWidth, fullScreenTextBoxHeight, totalConsoleHeight, outputIntro, introZoomed, room0VIEWED[currentWallIndex], room0ZOOMEDVIEWED[currentWallIndex]);
                if(room0VIEWED[currentWallIndex] == false) room0VIEWED[currentWallIndex] = true;
                break;
            case 2:
                loadArt(room0[currentWallIndex], art, artWidth, artHeight);
                renderCenteredArt(art, artWidth, artHeight);
                outputIntro = "If youve looked at all the walls zoom into the key pad and enter 'start' to enter the first floor. Good Luck!";            
                renderBox(0, totalConsoleWidth, fullScreenTextBoxHeight, totalConsoleHeight, outputIntro, introZoomed, room0VIEWED[currentWallIndex], room0ZOOMEDVIEWED[currentWallIndex]);
                if(room0VIEWED[currentWallIndex] == false) room0VIEWED[currentWallIndex] = true;
                break;
            case 3:
                loadArt(room0[currentWallIndex], art, artWidth, artHeight);
                renderCenteredArt(art, artWidth, artHeight);
                outputIntro = "To complete levels answers must be input, usally you will zoom into a wall and be instructed to enter your input";
                renderBox(0, totalConsoleWidth, fullScreenTextBoxHeight, totalConsoleHeight, outputIntro, introZoomed, room0VIEWED[currentWallIndex], room0ZOOMEDVIEWED[currentWallIndex]);
                if(room0VIEWED[currentWallIndex] == false) room0VIEWED[currentWallIndex] = true;
                break;
            default:
                break;
            }
        }else if(introZoomed == true){
            clearWholeScreen();
            loadArt(room0ZOOMED[currentWallIndex], art, artWidth, artHeight);
            renderCenteredArt(art, artWidth, artHeight);
            if(currentWallIndex == 0){
                outputIntro = "well done, if you want to look at other walls use the left and right arrow keys. Zoom back out and give it a try ...";    
                renderBox(0, totalConsoleWidth, fullScreenTextBoxHeight, totalConsoleHeight, outputIntro, introZoomed, room0VIEWED[currentWallIndex], room0ZOOMEDVIEWED[currentWallIndex]);
                if(room0ZOOMEDVIEWED[1] == false) room0ZOOMEDVIEWED[1] = true;     
            }
            switch (currentWallIndex)
            {
            case 2:
                instructionIntro = "input your answer:";
                renderBox(0, (totalConsoleWidth/5), (fullScreenTextBoxHeight - 5), fullScreenTextBoxHeight, instructionIntro, introZoomed, room0VIEWED[currentWallIndex], room0ZOOMEDVIEWED[currentWallIndex]);
                answerIntro = stringInputBox("");
                if (answerIntro == "start" || answerIntro == "Start") {
                    introZoomed = false;
                    clearWholeScreen();
                    solvedIntro = true;
                    currentWallIndex = 0;
                    return;
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
        while(input == ' ') processInput();
        roomInputListenerIntro(&introZoomed);

        // Testing purposes
        // if(input =='s') solvedIntro = true;
        
        Sleep(20); // Delay to control game speed
    }
    // GAME LOOP
} 