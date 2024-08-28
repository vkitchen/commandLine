#include "oscarRoom.hpp"
#include "optionsBox.hpp"

/*!
 * @file
 * @brief oscarRoom.cpp
 */

bool solved = false;
std::string output;
std::string borderChar;
std::string answer;


void runOscar(){

    while (!solved) {
        

        if(input == 'q'){
            running = false;
            return;
        }
        if(zoomed == false){
            switch (currentWallIndex)
            {
            case 0:
                clearWholeScreen();
                loadArt(room1[currentWallIndex], art, artWidth, artHeight);
                renderCenteredArt(art, artWidth, artHeight);
                output = "Welcome to the first room at owheo, welcome to hell there should be a door";
                renderBox(0, totalConsoleWidth, fullScreenTextBoxHeight, totalConsoleHeight, output);
                break;
            case 1:
                clearWholeScreen();
                loadArt(room1[currentWallIndex], art, artWidth, artHeight);
                renderCenteredArt(art, artWidth, artHeight);
                output = "Hopefully you just turned right, if not im wrong";            
                renderBox(0, totalConsoleWidth, fullScreenTextBoxHeight, totalConsoleHeight, output);
                break;
            case 2:
                clearWholeScreen();
                loadArt(room1[currentWallIndex], art, artWidth, artHeight);
                renderCenteredArt(art, artWidth, artHeight);
                output = "3";            
                renderBox(0, totalConsoleWidth, fullScreenTextBoxHeight, totalConsoleHeight, output);
                break;
            case 3:
                clearWholeScreen();
                loadArt(room1[currentWallIndex], art, artWidth, artHeight);
                renderCenteredArt(art, artWidth, artHeight);
                output = "4";            
                renderBox(0, totalConsoleWidth, fullScreenTextBoxHeight, totalConsoleHeight, output);
                break;
            default:
                break;
            }
        } else if (zoomed == true) {
            clearWholeScreen();
            loadArt(room1ZOOMED[currentWallIndex], art, artWidth, artHeight);
            renderCenteredArt(art, artWidth, artHeight);
            switch (currentWallIndex) 
            {
            case 0:
                answer = stringInputBox("");
                if (answer == "Owheo") {
                    clearWholeScreen();
                    std::string output = "!!! YOU WIN !!!";            
                    renderBox(0, totalConsoleWidth, fullScreenTextBoxHeight, totalConsoleHeight, output);
                }
                break;
            case 2:
                output = "zoomd";            
                renderBox(0, totalConsoleWidth, fullScreenTextBoxHeight, totalConsoleHeight, output);
                break;
            default:
                break;
            }
        }
        

        input = ' ';
        while(input == ' ') processInput();

        roomInputListenerOscar();
        // Clear the input
        

        Sleep(20); // Delay to control game speed
    }
    // GAME LOOP
} 