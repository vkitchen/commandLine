        
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

/*!
 * @file
 * @brief inputListener.cpp
 */

int leftArrow = 75;
int rightArrow = 77;
int upArrow = 72;
int downArrow = 80;
int enter = 13;
int plusSymbol = 61;
int minusSymbol = 45;

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
    } else if ((input == leftArrow || input == rightArrow) && zoomed == false) { // Left or Right arrow keys if not zoomed in
        if (input == leftArrow) { // Left arrow key
            currentWallIndex = (currentWallIndex - 1 + 4) % 4;
        } else if (input == rightArrow) { // Right arrow key
            currentWallIndex = (currentWallIndex + 1) % 4;
        }
    } else if (input == plusSymbol && (currentWallIndex == 0 || currentWallIndex == 2)){ // should only zoom on wall 0 and 2
        clearWholeScreen();
        zoomed = true;
    }
}


int startMenuListener() {
    int upPressed = 1;
    int downPressed = 2;
    int nothingPressed = 3;
    int enterPressed = 0;
   

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
    } else if (input == enter || input == minusSymbol) {  // Check for Enter key (carriage return)
        return output;  // Return the output when Enter is pressed
    }

    return output;
}

