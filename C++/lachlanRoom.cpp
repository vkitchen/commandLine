#include "lachlanRoom.hpp"
#include "optionsBox.hpp"

/*!
 * @file
 * @brief lachlanRoom.cpp
 */

bool solvedLachlan = false;
std::string outputLachlan;


void runLachlan(){
 currentWallIndex = 0;
 while (!solvedLachlan) {
        

        if(input == 'q'){
            running = false;
            return;
        }
        switch (currentWallIndex)
        {
        case 0:
            loadArt(room2[currentWallIndex], art, artWidth, artHeight);
            renderCenteredArt(art, artWidth, artHeight);
            outputLachlan = "LACHLANDS ROOM WOOOOOO";
            renderBox(0, totalConsoleWidth, fullScreenTextBoxHeight, totalConsoleHeight, outputLachlan);
            if(room2VIEWED[currentWallIndex] == false) room2VIEWED[currentWallIndex] = true;
            break;
        case 1:
            loadArt(room2[currentWallIndex], art, artWidth, artHeight);
            renderCenteredArt(art, artWidth, artHeight);
            outputLachlan = "LACHLANDS ROOM WOOOOOO";         
            renderBox(0, totalConsoleWidth, fullScreenTextBoxHeight, totalConsoleHeight, outputLachlan);
            if(room2VIEWED[currentWallIndex] == false) room2VIEWED[currentWallIndex] = true;
            break;
        case 2:
            loadArt(room2[currentWallIndex], art, artWidth, artHeight);
            renderCenteredArt(art, artWidth, artHeight);
            outputLachlan = "LACHLANDS ROOM WOOOOOO";            
            renderBox(0, totalConsoleWidth, fullScreenTextBoxHeight, totalConsoleHeight, outputLachlan);
            if(room2VIEWED[currentWallIndex] == false) room2VIEWED[currentWallIndex] = true;
            break;
        case 3:
            loadArt(room2[currentWallIndex], art, artWidth, artHeight);
            renderCenteredArt(art, artWidth, artHeight);
            outputLachlan = "LACHLANDS ROOM WOOOOOO";
            renderBox(0, totalConsoleWidth, fullScreenTextBoxHeight, totalConsoleHeight, outputLachlan);
            if(room2VIEWED[currentWallIndex] == false) room2VIEWED[currentWallIndex] = true;
            break;
        default:
            break;
        }
        

        input = ' ';
        while(input == ' ') processInput();
        roomInputListenerLachlan();
                // Clear the input
        
        if(input =='s') solvedLachlan = true;
        Sleep(20); // Delay to control game speed
    }
    // GAME LOOP
} 