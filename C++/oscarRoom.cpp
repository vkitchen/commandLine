#include "oscarRoom.hpp"

bool solved = false;
std::string output;
std::string borderChar;

void runOscar(){

    while (!solved) {
        

        if(input == 'q'){
            running = false;
            return;
        }
        switch (currentWallIndex)
        {
        case 0:
            loadArt(room1[currentWallIndex], art, artWidth, artHeight);
            renderCenteredArt(art, artWidth, artHeight);
            output = "Welcome to the first room at owheo, welcome to hell there should be a door";
            borderChar = "#";
            renderBox(0, totalConsoleWidth, fullScreenTextBoxHeight, totalConsoleHeight, output, borderChar);
            break;
        case 1:
            loadArt(room1[currentWallIndex], art, artWidth, artHeight);
            renderCenteredArt(art, artWidth, artHeight);
            output = "Hopefully you just turned right, if not im wrong";            
            borderChar = "#";
            renderBox(0, totalConsoleWidth, fullScreenTextBoxHeight, totalConsoleHeight, output, borderChar);
            break;
        case 2:
            loadArt(room1[currentWallIndex], art, artWidth, artHeight);
            renderCenteredArt(art, artWidth, artHeight);
            output = "3";            
            borderChar = "#";
            renderBox(0, totalConsoleWidth, fullScreenTextBoxHeight, totalConsoleHeight, output, borderChar);
            break;
        case 3:
            loadArt(room1[currentWallIndex], art, artWidth, artHeight);
            renderCenteredArt(art, artWidth, artHeight);
            output = "4";            
            borderChar = "#";
            renderBox(0, totalConsoleWidth, fullScreenTextBoxHeight, totalConsoleHeight, output, borderChar);
            break;
        default:
            break;
        }

        input = ' ';
        while(input == ' ') processInput();

        roomInputListenerOscar();
        // Clear the input
        

        Sleep(20); // Delay to control game speed
    }
    // GAME LOOP
} 