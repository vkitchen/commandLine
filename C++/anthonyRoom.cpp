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

// test

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
                outputAnthony = "Welcome to room 1, you will be attempting to find a mystery word based on the cluues given by other walls, zoom into this image to submit your answer when you think you have it!";
                renderBox(0, totalConsoleWidth, fullScreenTextBoxHeight, totalConsoleHeight, outputAnthony);
                if(room3VIEWED[currentWallIndex] == false) room3VIEWED[currentWallIndex] = true;
                break;
            case 1:
                loadArt(room3[currentWallIndex], art, artWidth, artHeight);
                renderCenteredArt(art, artWidth, artHeight);
                outputAnthony = "B X H";         
                renderBox(0, totalConsoleWidth, fullScreenTextBoxHeight, totalConsoleHeight, outputAnthony);
                if(room3VIEWED[currentWallIndex] == false) room3VIEWED[currentWallIndex] = true;
                break;
            case 2:
                loadArt(room3[currentWallIndex], art, artWidth, artHeight);
                renderCenteredArt(art, artWidth, artHeight);
                outputAnthony = "A world full of regions and ______'s ...";            
                renderBox(0, totalConsoleWidth, fullScreenTextBoxHeight, totalConsoleHeight, outputAnthony);
                if(room3VIEWED[currentWallIndex] == false) room3VIEWED[currentWallIndex] = true;
                break;
            case 3:
                loadArt(room3[currentWallIndex], art, artWidth, artHeight);
                renderCenteredArt(art, artWidth, artHeight);
                outputAnthony = "______ fifty one";
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
            switch (currentWallIndex)
            {
            case 0:
                instructionAnthony = "input your answer:";
                renderBox(0, (totalConsoleWidth/5), (fullScreenTextBoxHeight - 5), fullScreenTextBoxHeight, instructionAnthony);
                answerAnthony = stringInputBox("");
                if (answerAnthony == "Area" || answerAnthony == "area") {
                    zoomed = false;
                    clearWholeScreen();
                    solvedAnthony = true;
                    return;
                } else if (input == 45) {
                    zoomed = false;
                    clearWholeScreen();
                    continue;
                } else {
                    // This extra else statement makes it so any wrong input will reset the screen
                    // Could be better but works for now
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