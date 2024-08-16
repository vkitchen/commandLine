#include <iostream>
#include <fstream>
#include <vector>
#include <conio.h>
#include <windows.h>
#include <cstring>
#include "renderArt.hpp"
#include "readArt.hpp"
#include "terminalHelpers.hpp"
#include "textBox.hpp"
#include "inputListener.hpp"
#include "startScreen.hpp"
#include "test.hpp"

// Room set up
const int numWalls = 4;
const std::string room1[numWalls] = {"art/room4/ascii-art (10).txt", "art/room4/ascii-art (10).txt", "art/room4/ascii-art (10).txt", "art/room4/ascii-art (10).txt"};
const std::string room2[numWalls] = {"art/f1r1w2.txt", "art/f1r1w3.txt", "art/f1r1w4.txt", "art/skull.txt"};
const std::string room3[numWalls] = {"art/f1r1w2.txt", "art/f1r1w3.txt", "art/f1r1w4.txt", "art/skull.txt"};
const std::string room4[numWalls] = {"art/f1r1w2.txt", "art/f1r1w3.txt", "art/f1r1w4.txt", "art/skull.txt"};

std::string listenerType = "RoomLeftRight";
int roomNumber = 1;
int currentWallIndex = 0;
char** art = nullptr;
int artWidth = 0, artHeight = 0;
int totalConsoleHeight = 0;
int totalConsoleWidth = 0;
int  fullScreenTextBoxHeight = 0;
char input = ' ';
bool running = true;
bool testMode = false;



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





int main(int argc, char* argv[]) {
    for(int i = 1; i < argc; i++){
        if(std::strcmp(argv[i], "-t") == 0){
            testMode = true;
        }
    }
    // Terminal setups
    enableUTF8Console();
    setFullScreen();
    getFullScreenDimensions();
    hideCursor();
    clearWholeScreen();

    //std::cout << totalConsoleHeight + " " + totalConsoleWidth << std::endl;

    startScreen();

    // Below code is jank, but when hit new game need to intialise from start screen the room
    loadArt(room1[currentWallIndex], art, artWidth, artHeight);
    renderCenteredArt(art, artWidth, artHeight);
    std::string output = "Room " + std::to_string(roomNumber) + " Wall " + std::to_string(currentWallIndex + 1);
    std::string borderChar = "#";
    renderBox(0, totalConsoleWidth, fullScreenTextBoxHeight, totalConsoleHeight, output, borderChar); 

    while (running) {
        
        processInput();
        //std::cout << "TCH =" << textBoxHeight << ", HEIGHT=" << totalConsoleHeight << std::endl;

        roomLeftRightListener();

        
        // Clear the input
        input = ' ';

        Sleep(20); // Delay to control game speed
    }

    return 0;
}
