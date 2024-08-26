        
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "inputListener.hpp"
#include "renderArt.hpp"
#include "textBox.hpp"
#include "optionsBox.hpp"
#include "terminalHelpers.hpp"
#include <conio.h>

int leftArrow = 75;
int rightArrow = 77;
int upArrow = 72;
int downArrow = 80;
int enter = 13;

void processInput() {
    if (_kbhit()) {
        input = _getch();
        if (input == 0 || input == 224) {
            input = _getch(); // Handle arrow keys
        }
    }
}

void roomLeftRightListener() {
        
    if (input == 'q') {
        running = false; // Quit the game
    } else if (input == leftArrow || input == rightArrow) { // Left or Right arrow keys
        if (input == leftArrow) { // Left arrow key
            currentWallIndex = (currentWallIndex - 1 + 4) % 4;
        } else if (input == rightArrow) { // Right arrow key
            currentWallIndex = (currentWallIndex + 1) % 4;
        }
    }
}

void roomInputListenerOscar() {
        
    if (input == 'q') {
        running = false; // Quit the game
    } else if (input == leftArrow || input == rightArrow) { // Left or Right arrow keys
        if (input == leftArrow) { // Left arrow key
            currentWallIndex = (currentWallIndex - 1 + 4) % 4;
        } else if (input == rightArrow) { // Right arrow key
            currentWallIndex = (currentWallIndex + 1) % 4;
        }
    }else if (input == enter && (currentWallIndex == 0 || currentWallIndex == 2)){
        clearWholeScreen();
        loadArt(room1ZOOMED[currentWallIndex], art, artWidth, artHeight);
        renderCenteredArt(art, artWidth, artHeight);
        std::string output = "4";            
        std::string borderChar = "#";
        renderBox(0, totalConsoleWidth, fullScreenTextBoxHeight, totalConsoleHeight, output, borderChar);
        zoomed = true;
    }else if (input == 'o' && zoomed == true){
        zoomed = false;
    }
}


int startMenuListener() {
    int upPressed = 1;
    int downPressed = 2;
    int enterPressed = 0;
    int nothingPressed = 3;

    if (input == enter) {
        return enterPressed;
    } else if (input == upArrow || input == downArrow) { // Up or Down arrow keys
        if (input == upArrow) { // Up arrow key
            return upPressed;
        } else if (input == downArrow) { // Down arrow key
            return downPressed;
        }
    }
    return nothingPressed;
}


std::string textInputListener(std::string partialWord) {
    std::string output = partialWord;

    // Check for letters (uppercase and lowercase) and space bar
    if ((input >= 'a' && input <= 'z') || 
        (input >= 'A' && input <= 'Z') ||  
        input == ' ') {
        output += input;  // Append valid character to output
    } else if (input == '\r') {  // Check for Enter key (carriage return)
        return output;  // Return the output when Enter is pressed
    }

    return output;
}

