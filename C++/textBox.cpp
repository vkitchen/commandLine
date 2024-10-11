#include <windows.h>
#include <iostream>
#include <thread>
#include <chrono>
#include<vector>
#include<fstream>
#include<string>
#include<conio.h>
#include"inputListener.hpp"
#include "textBox.hpp"

/*!
 * @file
 * @brief textBox.cpp
 */

// Function to convert string into vector with \n being the delimiter between indexs
std::vector<std::string> stringToVector(const std::string& inputedString) {
    std::vector<std::string> result;
    std::string temp;

    for (char ch : inputedString) {
        if (ch == '\n') {
            // add substring to results vector
            result.push_back(temp);
            temp.clear();
        } else {
            temp += ch; // append characyer to temp string
        }
    }

    //add final subsring if it exists
    if (!temp.empty()) {
        result.push_back(temp);
    }

    return result;
}

// Function that populates box with content fed into it
std::vector<std::string> populateBoxMiddle(int boxWidth, int boxHeight, const std::string& content) {
    std::vector<std::string> boxContent(boxHeight, std::string(boxWidth, ' '));

    int verticalPadding = 1; // One line padding from the top and bottom
    int horizontalPadding = 1; // One character padding from the left and right

    int contentLength = static_cast<int>(content.length());
    int maxContentWidth = boxWidth - 2 * horizontalPadding;
    int maxContentHeight = boxHeight - 2 * verticalPadding;

    if (contentLength > maxContentWidth) {
        contentLength = maxContentWidth; // Truncate content if it's too wide
    }

    int startX = (boxWidth - contentLength) / 2;
    int startY = (boxHeight - 1) / 2; // Place in the middle line for simplicity

    for (int i = 0; i < boxHeight; ++i) {
        boxContent[i][0] = '|';
        boxContent[i][boxWidth - 1] = '|';
    }

    boxContent[0] = std::string(boxWidth, '_');
    boxContent[boxHeight - 1] = std::string(boxWidth, '_');

    return boxContent;
}

//Function to add in instruction in bottom left hand corner of a rendered box
void renderHelperInstruction(const std::string& helperInstruction, int boxWidth, int boxHeight) {
    SHORT X = static_cast<SHORT>(boxWidth - helperInstruction.length() - 3);
    SHORT Y = static_cast<SHORT>(boxHeight - 3);

    if (X < 0) X = 0;
    if (Y < 0) Y = 0;

    COORD coord = {static_cast<SHORT>(X), static_cast<SHORT>(Y)};
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(console, coord);

    std::cout << helperInstruction;
    std::cout.flush();
}

// Function to render a text box with given text centered in the middle
// startX = top left x-coord
// endX   = bottom right x-coord
// startY = top left y-coord
// endY   = bottom right y-coord
void renderBox(int startX, int endX, int startY, int endY, const std::string& text, bool zoomedIn, bool wallSeen, bool zoomedWallSeen, const std::string& helperInstruction) {
    int boxHeight = endY - startY;
    int boxWidth = endX - startX;

    std::vector<std::string> boxContent = populateBoxMiddle(boxWidth, boxHeight, "");

    COORD coord;
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

    // Render box lines
    for (int i = 0; i < boxHeight; ++i) {
        coord = {static_cast<SHORT>(startX), static_cast<SHORT>(startY + i)};
        SetConsoleCursorPosition(console, coord);
        std::cout << boxContent[i] << std::endl;
    }

    std::vector<std::string> textList = stringToVector(text);

    for (int index = 0; index < textList.size(); index++) {
        // Non-blocking text rendering
        int startXText = static_cast<int>((boxWidth - textList[index].length()) / 2 + startX);
        int startYText = static_cast<int>((boxHeight / (textList.size()+1)) * (index + 1) + startY);
        coord = {static_cast<SHORT>(startXText), static_cast<SHORT>(startYText)};
        if(!zoomedIn && wallSeen == true || zoomedIn && zoomedWallSeen == true){
            
            SetConsoleCursorPosition(console, coord);
            std::cout << textList[index];
            std::cout.flush();
        }else{
            for (char c : textList[index]) {
                // Check for input before printing the next character
                if (_kbhit()) {
                    return;
                }

                coord = {static_cast<SHORT>(startXText++), static_cast<SHORT>(startYText)};
                SetConsoleCursorPosition(console, coord);
                std::cout << c;
                std::cout.flush();
                Sleep(5); // Adjust delay as needed
            }
        }
    }

    renderHelperInstruction(helperInstruction, endX, endY);


}
