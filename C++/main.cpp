#include <iostream>
#include <fstream>
#include <vector>
#include <conio.h>
#include <windows.h>
#include "renderArt.hpp"
#include "readArt.hpp"
#include "terminalHelpers.hpp"
#include "textBox.hpp"

const int numWalls = 4;
int totalConsoleHeight = 0;
int totalConsoleWidth = 0;
int  textBoxHeight = 0;
char input = ' ';
bool running = true;


std::vector<std::string> currentWall;

void loadWall(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    currentWall.clear();
    std::string line;
    while (getline(file, line)) {
        currentWall.push_back(line);
    }
    file.close();
}

void renderWall() {
    COORD topLeft = {0, 0};
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(console, topLeft);

    for (const auto& line : currentWall) {
        std::cout << line << std::endl;
    }
}

void processInput(char &input) {
    if (_kbhit()) {
        input = _getch();
        if (input == 0 || input == 224) {
            input = _getch(); // Handle arrow keys
        }
    }
}


// void updateWall(char input) {
//     clearScreen();
//     if (input == 75) { // Left arrow key
//         currentWallIndex = (currentWallIndex - 1 + numWalls) % numWalls;
//         loadWall(wallFiles[currentWallIndex]);
//     } else if (input == 77) { // Right arrow key
//         currentWallIndex = (currentWallIndex + 1) % numWalls;
//         loadWall(wallFiles[currentWallIndex]);
//     }
// }





int main() {


    const std::string wallFiles[numWalls] = {"art/skull.txt", "art/demon.txt", "art/artTest3.txt", "art/artTest4.txt"};
    int currentWallIndex = 0;
    char** art = nullptr;
    int artWidth = 0, artHeight = 0;

    setFullScreen();
    getFullScreenDimensions();
    hideCursor();
    clearWholeScreen();
    loadAndRenderWall(wallFiles[currentWallIndex], art, artWidth, artHeight);
    renderCenteredArt(art, artWidth, artHeight);

    std::string test = "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX";
    std::string test2 = "%";
    std::string test3 = "ESCAPE OWHEOOOOOOOOOOOO";
    while (running) {
        
        renderBox(0, totalConsoleWidth, textBoxHeight, totalConsoleHeight, test3, test2); 
        processInput(input);
        //std::cout << "TCH =" << textBoxHeight << ", HEIGHT=" << totalConsoleHeight << std::endl;




        // Clear the input
        input = ' ';

        Sleep(20); // Delay to control game speed
    }

    return 0;
}
