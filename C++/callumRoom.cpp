#include "callumRoom.hpp"
#include "optionsBox.hpp"

/*!
 * @file
 * @brief callumRoom.cpp
 */

bool solvedCallum = false;
bool callumZoomed = false;
std::string outputCallum;


void runCallum(){
    roomNumber = 4;
    callumZoomed = globalZoomed;
    while (!solvedCallum) {
        

        if(input == 'q'){
            running = false;
            return;
        }
        if(callumZoomed == false){
            switch (currentWallIndex)
            {
            case 0:
                loadArt(room4[currentWallIndex], art, artWidth, artHeight);
                renderCenteredArt(art, artWidth, artHeight);
                outputCallum = "CALLUM ROOM WOOOOOO";
                renderBox(0, totalConsoleWidth, fullScreenTextBoxHeight, totalConsoleHeight, outputCallum, callumZoomed, room4VIEWED[currentWallIndex], room4ZOOMEDVIEWED[currentWallIndex]);
                if(room4VIEWED[currentWallIndex] == false) room4VIEWED[currentWallIndex] = true;
                break;
            case 1:
                loadArt(room4[currentWallIndex], art, artWidth, artHeight);
                renderCenteredArt(art, artWidth, artHeight);
                outputCallum = "CALLUM ROOM WOOOOOO";         
                renderBox(0, totalConsoleWidth, fullScreenTextBoxHeight, totalConsoleHeight, outputCallum, callumZoomed, room4VIEWED[currentWallIndex], room4ZOOMEDVIEWED[currentWallIndex]);            if(room4VIEWED[currentWallIndex] == false) room4VIEWED[currentWallIndex] = true;
                break;
            case 2:
                loadArt(room4[currentWallIndex], art, artWidth, artHeight);
                renderCenteredArt(art, artWidth, artHeight);
                outputCallum = "CALLUM ROOM WOOOOOO";            
                renderBox(0, totalConsoleWidth, fullScreenTextBoxHeight, totalConsoleHeight, outputCallum, callumZoomed, room4VIEWED[currentWallIndex], room4ZOOMEDVIEWED[currentWallIndex]);            if(room4VIEWED[currentWallIndex] == false) room4VIEWED[currentWallIndex] = true;
                break;
            case 3:
                loadArt(room4[currentWallIndex], art, artWidth, artHeight);
                renderCenteredArt(art, artWidth, artHeight);
                outputCallum = "CALLUM ROOM WOOOOOO";
                renderBox(0, totalConsoleWidth, fullScreenTextBoxHeight, totalConsoleHeight, outputCallum, callumZoomed, room4VIEWED[currentWallIndex], room4ZOOMEDVIEWED[currentWallIndex]);
                if(room4VIEWED[currentWallIndex] == false) room4VIEWED[currentWallIndex] = true;
                break;
            default:
                break;
            }
        }
        
        input = ' ';
        while(input == ' ') processInput();
        roomInputListenerCallum(&callumZoomed);
                // Clear the input
        
        if (running == false) {
            return;
        }
        Sleep(20); // Delay to control game speed
    }
    // GAME LOOP
} 