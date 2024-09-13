#include "anthonyRoom.hpp"
#include "optionsBox.hpp"

/*!
 * @file
 * @brief anthonyRoom.cpp
 */

bool solvedAnthony = false;
std::string outputAnthony;
std::string borderCharAnthony;
std::string answerAnthony;
std::string instructionAnthony;


void runAnthony(){
    // need to reset these variables as they have been used by oscars room
    currentWallIndex = 0;
    zoomed = false;
    while (!solvedAnthony) {
        
        if(input == 'q'){
            running = false;
            return;
        }
        if(zoomed == false) {
            switch (currentWallIndex)
            {
            case 0:
                loadArt(room3[currentWallIndex], art, artWidth, artHeight);
                renderCenteredArt(art, artWidth, artHeight);
                outputAnthony = "ANTHONY ROOM WOOOOOO - Now think fast!";
                renderBox(0, totalConsoleWidth, fullScreenTextBoxHeight, totalConsoleHeight, outputAnthony);
                if(room3VIEWED[currentWallIndex] == false) room3VIEWED[currentWallIndex] = true;
                break;
            case 1:
                loadArt(room3[currentWallIndex], art, artWidth, artHeight);
                renderCenteredArt(art, artWidth, artHeight);
                outputAnthony = "Clue 1";         
                renderBox(0, totalConsoleWidth, fullScreenTextBoxHeight, totalConsoleHeight, outputAnthony);
                if(room3VIEWED[currentWallIndex] == false) room3VIEWED[currentWallIndex] = true;
                break;
            case 2:
                loadArt(room3[currentWallIndex], art, artWidth, artHeight);
                renderCenteredArt(art, artWidth, artHeight);
                outputAnthony = "Clue 2";            
                renderBox(0, totalConsoleWidth, fullScreenTextBoxHeight, totalConsoleHeight, outputAnthony);
                if(room3VIEWED[currentWallIndex] == false) room3VIEWED[currentWallIndex] = true;
                break;
            case 3:
                loadArt(room3[currentWallIndex], art, artWidth, artHeight);
                renderCenteredArt(art, artWidth, artHeight);
                outputAnthony = "Clue 3";
                renderBox(0, totalConsoleWidth, fullScreenTextBoxHeight, totalConsoleHeight, outputAnthony);
                if(room3VIEWED[currentWallIndex] == false) room3VIEWED[currentWallIndex] = true;
                break;
            default:
                break;
            }
        } else if (zoomed == true) {
            clearWholeScreen();
            loadArt(room3ZOOMED[currentWallIndex], art, artWidth, artHeight);
            renderCenteredArt(art, artWidth, artHeight);
            if(currentWallIndex == 0){
                outputAnthony = "solve this lol";
                renderBox(0, totalConsoleWidth, fullScreenTextBoxHeight, totalConsoleHeight, outputAnthony);
                if(room3ZOOMEDVIEWED[0] == false) room3ZOOMEDVIEWED[0] = true;
            }
            switch (currentWallIndex)
            {
            case 0:
                instructionAnthony = "input your answer:";
                renderBox(0, (totalConsoleWidth/5), (fullScreenTextBoxHeight - 5), fullScreenTextBoxHeight, instructionAnthony);
                answerAnthony = stringInputBox("");
                if (answerAnthony == "Area" || answerAnthony == "area") {
                    clearWholeScreen();
                    solvedAnthony = true;
                    return;
                } else if (input == 45) {
                    zoomed = false;
                    clearWholeScreen();
                    continue;
                }
                break;
            case 2: // zoom out
                if (input == 45) {
                    zoomed = false;
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
        roomInputListenerAnthony();
        // Clear the input
        
        // Testing purposes
        // if(input =='s') solvedAnthony = true;
        
        Sleep(20); // Delay to control game speed
    }
    // GAME LOOP
} 