#include <windows.h>
#include <iostream>
#include "textBox.hpp"

// Function that populates box with content fed into it
std::vector<std::string> populateBoxMiddle(int boxWidth, int boxHeight, const std::string& content, std::string& borderChar) {
    std::vector<std::string> boxContent(boxHeight, std::string(boxWidth, ' '));

    int verticalPadding = 1; // One line padding from the top and bottom
    int horizontalPadding = 1; // One character padding from the left and right

    int contentLength = content.length();
    int maxContentWidth = boxWidth - 2 * horizontalPadding;
    int maxContentHeight = boxHeight - 2 * verticalPadding;

    if (contentLength > maxContentWidth) {
        contentLength = maxContentWidth; // Truncate content if it's too wide
    }

    int startX = (boxWidth - contentLength) / 2;
    int startY = (boxHeight - 1) / 2; // Place in the middle line for simplicity

    for (int i = 0; i < boxHeight; ++i) {
        if (i == startY) {
            boxContent[i].replace(startX, contentLength, content.substr(0, contentLength));
        }
        boxContent[i][0] = '|';
        boxContent[i][boxWidth - 1] = '|';
    }

    boxContent[0] = std::string(boxWidth, '_');
    boxContent[boxHeight - 1] = std::string(boxWidth, '_');

    return boxContent;
}

// Function to render a text box of a with given text ceneter in the middle
// startX = top left x-coord
// endX   = bottom right x-coord
// startY = top left y-coord
// endY   = bottom right y-coord
void renderBox(int startX, int endX, int startY, int endY, std::string& text, std::string& borderChar) {
    int boxHeight = endY - startY;
    int boxWidth = endX - startX;

    std::vector<std::string> boxContent = populateBoxMiddle(boxWidth, boxHeight, text, borderChar);

    COORD coord; 
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

    // Render box lines
    for (int i = 0; i < boxHeight; ++i) {
        coord = {static_cast<SHORT>(startX), static_cast<SHORT>(startY + i)};
        SetConsoleCursorPosition(console, coord);
        std::cout << boxContent[i] << std::endl;
    }
} 

void makeBoxArray(int height, int width) {
    char** array = new char*[height];
    for (int i = 0; i < height; i++) {
        array[i] = new char[width + 1]; // +1 for null terminator
        std::fill(array[i], array[i] + width, ' '); // Fill with spaces
        array[i][width] = '\0'; // Null terminator
    }
}
