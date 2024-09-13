#include "anthonyRoom.hpp"
#include "optionsBox.hpp"

/*!
 * @file
 * @brief anthonyRoom.cpp
 */

bool solvedAnthony = false;
std::string outputAnthony;


void runAnthony(){
 currentWallIndex = 0;
 while (!solvedAnthony) {
        

        if(input == 'q'){
            running = false;
            return;
        }
        switch (currentWallIndex)
        {
        case 0:
            loadArt(room3[currentWallIndex], art, artWidth, artHeight);
            renderCenteredArt(art, artWidth, artHeight);
            outputAnthony = "ANTHONY ROOM WOOOOOO";
            renderBox(0, totalConsoleWidth, fullScreenTextBoxHeight, totalConsoleHeight, outputAnthony);
            if(room3VIEWED[currentWallIndex] == false) room3VIEWED[currentWallIndex] = true;
            break;
        case 1:
            loadArt(room3[currentWallIndex], art, artWidth, artHeight);
            renderCenteredArt(art, artWidth, artHeight);
            outputAnthony = "ANTHONY ROOM WOOOOOO";         
            renderBox(0, totalConsoleWidth, fullScreenTextBoxHeight, totalConsoleHeight, outputAnthony);
            if(room3VIEWED[currentWallIndex] == false) room3VIEWED[currentWallIndex] = true;
            break;
        case 2:
            loadArt(room3[currentWallIndex], art, artWidth, artHeight);
            renderCenteredArt(art, artWidth, artHeight);
            outputAnthony = "ANTHONY ROOM WOOOOOO";            
            renderBox(0, totalConsoleWidth, fullScreenTextBoxHeight, totalConsoleHeight, outputAnthony);
            if(room3VIEWED[currentWallIndex] == false) room3VIEWED[currentWallIndex] = true;
            break;
        case 3:
            loadArt(room3[currentWallIndex], art, artWidth, artHeight);
            renderCenteredArt(art, artWidth, artHeight);
            outputAnthony = "ANTHONY ROOM WOOOOOO";
            renderBox(0, totalConsoleWidth, fullScreenTextBoxHeight, totalConsoleHeight, outputAnthony);
            if(room3VIEWED[currentWallIndex] == false) room3VIEWED[currentWallIndex] = true;
            break;
        default:
            break;
        }
        

        input = ' ';
        while(input == ' ') processInput();
        roomInputListenerAnthony();
                // Clear the input
        if(input =='s') solvedAnthony = true;
        Sleep(20); // Delay to control game speed
    }
    // GAME LOOP
} 