#include <iostream>
#include <fstream>
#include <vector>
//#include <conio.h>
#include <windows.h>
#include <cstring>
#include "renderArt.hpp"
#include "readArt.hpp"
#include "terminalHelpers.hpp"
#include "textBox.hpp"
#include "inputListener.hpp"
#include "startScreen.hpp"
#include "test.hpp"
#include "optionsBox.hpp"
#include "oscarRoom.hpp"

// Room set up
const int numWalls = 4;
const std::string room1[numWalls] = {"art/room1/W1.txt", "art/room1/W2.txt", "art/room1/W3.txt", "art/room1/W4.txt"};
const std::string room1ZOOMED[numWalls] = {"art/room1/zoomed/W1Zoom.txt", "", "art/room1/zoomed/W3Zoom.txt", ""};
bool room1VIEWED[numWalls] = {false, false, false, false};
bool room1ZOOMEDVIEWED[numWalls] = {false, false, false, false};


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
bool zoomed = false;

std::vector<std::string> currentWall;

int main(int argc, char* argv[]) {
    for(int i = 1; i < argc; i++){
        if(std::strcmp(argv[i], "-t") == 0){
            testMain();
            return 0;
        }
    }


// Terminal setups
    enableUTF8Console();
    setFullScreen();
    getFullScreenDimensions();
    hideCursor();
    clearWholeScreen();


    startScreen(); // Display Start Screen for input
    if (running == false) {
        return 0;
    }
    clearWholeScreen();
    runOscar();
    // Below code is jank, but when hit new game need to intialise from start screen the room

    clearWholeScreen();
    std::string output = "Thank you for playing Escape Owheo Alpha :)";            
    renderBox(0, totalConsoleWidth, 0, totalConsoleHeight, output);

    return 0;
}
