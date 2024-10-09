#include <iostream>
#include <fstream>
#include <vector>
#include <conio.h>
#include <windows.h>
#include <string>
#include "optionsBox.hpp"
#include "inputListener.hpp"
#include "timer.hpp"

/*!
 * @file
 * @brief optionsBox.cpp
 */

std::vector<std::string> options;


int getVisualLength(const std::string& input) {
    int visualLength = 0;
    for (size_t i = 0; i < input.size();) {
        unsigned char c = input[i];
        if ((c & 0x80) == 0) {
            // 1-byte character (ASCII)
            visualLength += 1;
            i += 1;
        } else if ((c & 0xE0) == 0xC0) {
            // 2-byte character
            visualLength += 1;
            i += 2;
        } else if ((c & 0xF0) == 0xE0) {
            // 3-byte character
            visualLength += 1;
            i += 3;
        } else if ((c & 0xF8) == 0xF0) {
            // 4-byte character
            visualLength += 1;
            i += 4;
        } else {
            // Handle unexpected byte sequences safely
            visualLength += 1;
            i += 1;
            std::cout << "uuuuuh" << std::endl;
        }
    }
    return visualLength;
}


// Function that populates box with content fed into it
std::vector<std::string> populateBoxMiddle(int boxWidth, int boxHeight, std::vector<std::string> displayedOptions, int startY) {
    std::vector<std::string> boxContent(boxHeight, std::string(boxWidth, ' '));

    size_t numOfOptions_data = displayedOptions.size(); // 
    int numOfOptions = static_cast<int>(numOfOptions_data);

    int verticalPadding = 1; // One line padding from the top and bottom
    int horizontalPadding = 1; // One character padding from the left and right

    for (int i = 0; i < numOfOptions; ++i) {
        int contentLength = 0;
        if (displayedOptions[i].find("►") != std::string::npos) {
            contentLength = static_cast<int>(displayedOptions[i].size());
        } else {
            contentLength = static_cast<int>(getVisualLength(displayedOptions[i]));
        }

        //std::cout << contentLength << std::endl;

        int maxContentWidth = boxWidth - 2 * horizontalPadding;
        int maxContentHeight = boxHeight - 2 * verticalPadding;

        if (contentLength > maxContentWidth) {
            contentLength = maxContentWidth; // Truncate content if it's too wide
        }

        int startXText = (boxWidth - contentLength) / 2;

        int startYText = (boxHeight / (numOfOptions+1)) * (i + 1);
        

        for (int j = 0; j < boxHeight; ++j) {
            if (j == startYText) {
                boxContent[j].replace(startXText, contentLength, displayedOptions[i]);
            }
            boxContent[j][0] = '|';
            boxContent[j][boxWidth - 1] = '|';
        }
    }

    boxContent[0] = std::string(boxWidth, '=');
    boxContent[boxHeight - 1] = std::string(boxWidth, '=');

    return boxContent;
}

// Function to render a text box of a with given text ceneter in the middle
// startX = top left x-coord
// endX   = bottom right x-coord
// startY = top left y-coord
// endY   = bottom right y-coord
void renderBoxOptions(int startX, int endX, int startY, int endY, std::vector<std::string> displayedOptions) {
    int boxHeight = endY - startY;
    int boxWidth = endX - startX;

    std::vector<std::string> boxContent = populateBoxMiddle(boxWidth, boxHeight, displayedOptions, startY);

    COORD coord; 
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

    // Render box lines
    for (int i = 0; i < boxHeight; ++i) {
        coord = {static_cast<SHORT>(startX), static_cast<SHORT>(startY + i)};
        SetConsoleCursorPosition(console, coord);
        std::cout << boxContent[i] << std::endl;
    }
} 


std::vector<std::string> populateDisplayedOptions (int numOfOptions, int selectedIndex, std::vector<std::string> selectOptions) {
    std::vector<std::string> displayedOptions(numOfOptions);
    for (int i = 0; i < numOfOptions; i++) {
        if (i == selectedIndex) {
            displayedOptions[selectedIndex] = selectOptions[selectedIndex];
        } else {
            displayedOptions[i] = options[i];
        }
    }
    return displayedOptions;
}


int renderOptionsBox(int startX, int endX, int startY, int endY, std::vector<std::string> optionsIn) {

    options = optionsIn;
    int numOfOptions = static_cast<int>(options.size());
    
    std::string selectedOption = "";
    int selectedIndex = 0;

    // make selected versions of options
    std::vector<std::string> selectOptions(numOfOptions);
    for (int i = 0; i < numOfOptions; ++i) {
        selectOptions[i] = "< " + options[i] + " >";
    }

    // make intial display with option 0 initally selected
    std::vector<std::string> displayedOptions;
    displayedOptions = populateDisplayedOptions(numOfOptions, selectedIndex, selectOptions);

    int upDown = 3;

    while (true) {

        renderBoxOptions(startX, endX, startY, endY, displayedOptions);

        processInput();
        
        upDown = upDownEnterListener();

        if (upDown == 1) { // up arrow was pressed
            selectedIndex = (selectedIndex - 1 + numOfOptions) % numOfOptions;
            displayedOptions = populateDisplayedOptions(numOfOptions, selectedIndex, selectOptions);
        } else if (upDown == 2) { // Down Arrow was pressed
            selectedIndex = (selectedIndex + 1) % numOfOptions;
            displayedOptions = populateDisplayedOptions(numOfOptions, selectedIndex, selectOptions);
        } else if (upDown == 0) { //enter was pressed
            break;
        } else if (upDown == 50) {
            selectedIndex = 50;
            break;
        }

        input = ' ';

        Sleep(20);

    }

    input = ' ';
    options = {};

    return selectedIndex;
}

int renderOptionsBox(int startX, int endX, int startY, int endY, std::vector<std::string> optionsIn, bool* timerRunning, const int totalTimerSeconds, bool currentRoomZoomed) {
    
    options = optionsIn;
    int numOfOptions = static_cast<int>(options.size());
    
    std::string selectedOption = "";
    int selectedIndex = 0;

    // make selected versions of options
    std::vector<std::string> selectOptions(numOfOptions);
    for (int i = 0; i < numOfOptions; ++i) {
        selectOptions[i] = "< " + options[i] + " >";
    }

    // make intial display with option 0 initally selected
    std::vector<std::string> displayedOptions;
    displayedOptions = populateDisplayedOptions(numOfOptions, selectedIndex, selectOptions);

    int upDown = 3;

    while (true) {

        if (*timerRunning) {
            int timeToPrint = checkRemainingTime(timeAtStartTime, totalTimerSeconds);
            if (timeToPrint > 0) {
                printRemainingTime(timeToPrint, currentRoomZoomed);
            } else {
                *timerRunning = false;
            }
        }

        renderBoxOptions(startX, endX, startY, endY, displayedOptions);

        processInput();
        
        upDown = upDownEnterListener();

        if (upDown == 1) { // up arrow was pressed
            selectedIndex = (selectedIndex - 1 + numOfOptions) % numOfOptions;
            displayedOptions = populateDisplayedOptions(numOfOptions, selectedIndex, selectOptions);
        } else if (upDown == 2) { // Down Arrow was pressed
            selectedIndex = (selectedIndex + 1) % numOfOptions;
            displayedOptions = populateDisplayedOptions(numOfOptions, selectedIndex, selectOptions);
        } else if (upDown == 0) { //enter was pressed
            break;
        } 

        input = ' ';

        Sleep(20);

    }

    input = ' ';
    options = {};

    return selectedIndex;
}

std::string stringInputBox(std::string wordIn) {
    std::vector<std::string> word(1);
    word[0] = wordIn;
    while (true) {
        // Render the text box with current input
        renderBoxOptions(0, totalConsoleWidth, fullScreenTextBoxHeight, totalConsoleHeight, word);// Assuming default console sizes for example
        Sleep(20);

        if (input == '^') {
            processInput();
        }

        // Get next input string
        std::string nextInput = textInputListener(word[0]);

        // Check if Enter was pressed (handled inside textInputListener)
        if (!nextInput.empty() && input == 13 || input == 45) {
            break;
        }

        // Update the input for the next loop iteration
        word[0] = nextInput;

        input = '^';
    }
    
    return word[0];
}
