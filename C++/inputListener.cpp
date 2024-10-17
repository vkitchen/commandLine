        
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "compat.hpp"
#include "inputListener.hpp"
#include "renderArt.hpp"
#include "textBox.hpp"
#include "optionsBox.hpp"
#include "pauseMenu.hpp"
#include "terminalHelpers.hpp"

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
int backspace = 8;
int esc = 27;

void processInput() {
    if (_kbhit()) {
        input = _getch();
        if (input == 0 || input == 224) {
            input = _getch(); // Handle arrow keys
        }
    }
}

// NO LONGER NEED RE: CODE COV
// void roomLeftRightListener() {
        
//     if (input == 'q') {
//         running = false; // Quit the game
//     } else if (input == leftArrow || input == rightArrow) { // Left or Right arrow keys
//         if (input == leftArrow) { // Left arrow key
//             currentWallIndex = (currentWallIndex - 1 + 4) % 4;
//         } else if (input == rightArrow) { // Right arrow key
//             currentWallIndex = (currentWallIndex + 1) % 4;
//         }
//     }
// }

void roomInputListenerIntro(bool* introZoomed) {
        
    if (input == esc) {
        pauseMenu(introZoomed); // display pause menu
    } else if ((input == leftArrow || input == rightArrow) && *introZoomed == false) { // Left or Right arrow keys if not zoomed in
        if (input == leftArrow) { // Left arrow key
            currentWallIndex = (currentWallIndex - 1 + 4) % 4;
        } else if (input == rightArrow) { // Right arrow key
            currentWallIndex = (currentWallIndex + 1) % 4;
        }
    } else if (input == plusSymbol && (currentWallIndex == 0 || currentWallIndex == 2)){ // should only zoom on wall 0 and 2
        clearWholeScreen();
        *introZoomed = true;
    }
}


void roomInputListenerOscar(bool* oscarZoomed) {
        
    if (input == esc) {
        pauseMenu(oscarZoomed); // display pause menu
    } else if ((input == leftArrow || input == rightArrow) && *oscarZoomed == false) { // Left or Right arrow keys if not zoomed in
        if (input == leftArrow) { // Left arrow key
            currentWallIndex = (currentWallIndex - 1 + 4) % 4;
        } else if (input == rightArrow) { // Right arrow key
            currentWallIndex = (currentWallIndex + 1) % 4;
        }
    } else if (input == plusSymbol && (currentWallIndex == 0 || currentWallIndex == 2)){ // should only zoom on wall 0 and 2
        clearWholeScreen();
        *oscarZoomed = true;
    }
}

void roomInputListenerLachlan(bool* timerRunning, bool* lachlanZoomed, bool* doorOpen, bool* lachlanSolved) {
        
    if (input == esc) {
        pauseMenu(lachlanZoomed); // display pause menu
    } else if ((input == leftArrow || input == rightArrow) && *lachlanZoomed == false) { // Left or Right arrow keys if not zoomed in
        if (input == leftArrow) { // Left arrow key
            currentWallIndex = (currentWallIndex - 1 + 4) % 4;
        } else if (input == rightArrow) { // Right arrow key
            currentWallIndex = (currentWallIndex + 1) % 4;
        }
    } else if (input == plusSymbol && *lachlanZoomed != true){ // should only zoom on wall 0 and 2
        clearWholeScreen();
        *lachlanZoomed = true;
    } else if (input == minusSymbol && *lachlanZoomed == true) {
        *lachlanZoomed = false;
    } else if ((input == 89 || input == 121) && *lachlanZoomed == true && currentWallIndex == 0 && !(*doorOpen)) { // Y or y, while doorClosed: Starts timer
        *timerRunning = true;
    } else if ((input == 89 || input == 121) && *lachlanZoomed == true && currentWallIndex == 0 && *doorOpen) {
        *lachlanSolved = true;
    } else if ((input == 78 || input == 110) && *lachlanZoomed == true && currentWallIndex == 0) { // N or n: exit view
        *lachlanZoomed = false;
    }
}

void roomInputListenerAnthony(bool* anthonyZoomed) {
        
    if (input == esc) {
        pauseMenu(anthonyZoomed); // display pause menu
    } else if ((input == leftArrow || input == rightArrow) && !(*anthonyZoomed)) { // Left or Right arrow keys if not zoomed in
        if (input == leftArrow) { // Left arrow key
            currentWallIndex = (currentWallIndex - 1 + 4) % 4;
        } else if (input == rightArrow) { // Right arrow key
            currentWallIndex = (currentWallIndex + 1) % 4;
        }
    } else if (input == plusSymbol && (currentWallIndex == 0 || currentWallIndex == 1 || currentWallIndex == 3)) { // zoom only on locked door
        clearWholeScreen();
        *anthonyZoomed = true;
    }
}

void roomInputListenerCallum(bool* callumZoomed, int* currentWallIndex, int* currentBookIndex, std::string* userAnswer) {
    if (input == esc) {
        pauseMenu(callumZoomed);
    } else if ((input == leftArrow || input == rightArrow) && !(*callumZoomed)) {
        if (input == leftArrow) {
            *currentWallIndex = (*currentWallIndex - 1 + 7) % 7;
        } else if (input == rightArrow) {
            *currentWallIndex = (*currentWallIndex + 1) % 7;
        }
    } else if (input == plusSymbol && !(*callumZoomed) && (*currentWallIndex == 2 || *currentWallIndex == 4 || *currentWallIndex == 5 || *currentWallIndex == 6)) {
        clearWholeScreen();
        *callumZoomed = true;
    } else if (input == minusSymbol && *callumZoomed) {
        *callumZoomed = false;
        *userAnswer = ""; // Reset the user answer when zooming out
        clearWholeScreen();
    } else if (*callumZoomed && *currentWallIndex == 4) {
        if (input == leftArrow) {
            *currentBookIndex = (*currentBookIndex - 1 + 5) % 5;
        } else if (input == rightArrow) {
            *currentBookIndex = (*currentBookIndex + 1) % 5;
        }
    }

}



int upDownEnterListener() {
    int upPressed = 1;
    int downPressed = 2;
    int nothingPressed = 3;
    int enterPressed = 0;
   
    if (input == esc || input == minusSymbol) {
        return 50;
    }
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


std::string textInputListener(const std::string& partialWord) {
    std::string output = partialWord;

    // Check for letters (uppercase and lowercase) and space bar
    if (((input >= 'a' && input <= 'z') || 
        (input >= 'A' && input <= 'Z') ||  
        (input >= '0' && input <= '9')) 
        && 
        ((input != leftArrow) || 
        (input != rightArrow))) {
        output += input;  // Append valid character to output
    } else if (input == backspace && output.length() > 0){
        output.pop_back();
    } else if (input == enter || input == minusSymbol) {  // Check for Enter key (carriage return)
        return output;  // Return the output when Enter is pressed
    }

    return output;
}

