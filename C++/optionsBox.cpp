#include <iostream>
#include <fstream>
#include <vector>
#include <conio.h>
#include <windows.h>
#include <string>
#include "optionsBox.hpp"
#include "inputListener.hpp"


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
std::vector<std::string> populateBoxMiddle(int boxWidth, int boxHeight, std::vector<std::string> displayedOptions) {
    std::vector<std::string> boxContent(boxHeight, std::string(boxWidth, ' '));

    int numOfOptions = displayedOptions.size(); // 

    int verticalPadding = 1; // One line padding from the top and bottom
    int horizontalPadding = 1; // One character padding from the left and right

    for (int i = 0; i < numOfOptions; ++i) {
        int contentLength = 0;
        if (displayedOptions[i].find("►") != std::string::npos) {
            contentLength = displayedOptions[i].size();
        } else {
            contentLength = getVisualLength(displayedOptions[i]);
        }

        //std::cout << contentLength << std::endl;

        int maxContentWidth = boxWidth - 2 * horizontalPadding;
        int maxContentHeight = boxHeight - 2 * verticalPadding;

        if (contentLength > maxContentWidth) {
            contentLength = maxContentWidth; // Truncate content if it's too wide
        }

        int startX = (boxWidth - contentLength) / 2;

        int startY = boxHeight / numOfOptions * (i + 1);

        

        for (int j = 0; j < boxHeight; ++j) {
            if (j == startY) {
                boxContent[j].replace(startX, contentLength, displayedOptions[i]);
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
void renderBox(int startX, int endX, int startY, int endY, std::vector<std::string> displayedOptions) {
    int boxHeight = endY - startY;
    int boxWidth = endX - startX;

    std::vector<std::string> boxContent = populateBoxMiddle(boxWidth, boxHeight, displayedOptions);

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
    std::string selectedOption = "";
    options = optionsIn;

    int printableLines = endY - startY - 3;  // lines that can be printed to within box, -1 due to line count starting at 1
    int numOfOptions = options.size();

    // makesleected versions of options
    std::vector<std::string> selectOptions(numOfOptions);
    for (int i = 0; i < numOfOptions; ++i) {
        selectOptions[i] = "< " + options[i] + " >";
    }
    
    int selectedIndex = 0;

    // make intial display with option 0 selected
    std::vector<std::string> displayedOptions;
    displayedOptions = populateDisplayedOptions(numOfOptions, selectedIndex, selectOptions);

    int upDown = 3;

    while (true) {

        renderBox(startX, endX, startY, endY, displayedOptions);

        processInput();
        
        upDown = startMenuListener();

        std::cout << upDown << "    " << selectedIndex << std::endl;

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

    
    options = {};

    return selectedIndex;
}