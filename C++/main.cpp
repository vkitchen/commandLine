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
#include "optionsBox.hpp"
#include "oscarRoom.hpp"
#include "lachlanRoom.hpp"
#include "anthonyRoom.hpp"
#include "callumRoom.hpp"
#include "introRoom.hpp"
//#include <mmsystem.h>

// comment to make pipeline run
// Room set up
const int numWalls = 4;

//Intro room
/*
-------------------------------------------------------------------------------------
ALL OF THIS ART STILL NEEDS TO BE REPLACED
IN THE INTRO ROOM ONLY
-------------------------------------------------------------------------------------
*/
const std::string room0[numWalls] = {"build/art/intro/W1.txt", "build/art/intro/W2.txt", "build/art/intro/W4.txt", "build/art/intro/W3.txt"};  
const std::string room0ZOOMED[numWalls] = {"build/art/intro/zoomed/W1Zoom.txt", "", "build/art/intro/zoomed/keypadZoom.txt", ""};
bool room0VIEWED[numWalls] = {false, false, false, false};
bool room0ZOOMEDVIEWED[numWalls] = {false, false, false, false};

//Oscars room
const std::string room1[numWalls] = {"build/art/room1/W1.txt", "build/art/room1/W2.txt", "build/art/room1/W3.txt", "build/art/room1/W4.txt"};  
const std::string room1ZOOMED[numWalls] = {"build/art/room1/zoomed/W1Zoom.txt", "", "build/art/room1/zoomed/W3Zoom.txt", ""};
bool room1VIEWED[numWalls] = {false, false, false, false};
bool room1ZOOMEDVIEWED[numWalls] = {false, false, false, false};

// Lachlans Room
const std::string room2[numWalls] = {"build/art/room2/W1.txt", "build/art/room2/W2.txt", "build/art/room2/W3.txt", "build/art/room2/W4.txt"}; 
const std::string room2ZOOMED[8] = {"build/art/room2/Zoomed/W1Z5.txt", "build/art/room2/Zoomed/W2Zoom.txt", "build/art/room2/Zoomed/W3Zoom.txt", "build/art/room2/Zoomed/W4Zoom.txt", "build/art/room2/Zoomed/W1Z4.txt", "build/art/room2/Zoomed/W1Z3.txt", "build/art/room2/Zoomed/W1Z2.txt", "build/art/room2/Zoomed/W1Z1.txt"};
bool room2VIEWED[numWalls] = {false, false, false, false};
bool room2ZOOMEDVIEWED[numWalls] = {false, false, false, false};

// Anthonys Room
const std::string room3[numWalls] = {"build/art/room3/W1.txt", "build/art/room3/W2.txt", "build/art/room3/W3.txt", "build/art/room3/W4.txt"};
const std::string room3ZOOMED[numWalls] = {"build/art/room3/zoomed/W1Zoom.txt", "build/art/room3/zoomed/W2Zoom.txt", "", "build/art/room3/zoomed/W4Zoom.txt"};
bool room3VIEWED[numWalls] = {false, false, false, false};
bool room3ZOOMEDVIEWED[numWalls] = {false, false, false, false};

// Callum Room
const std::string room4[7] = {"build/art/room4/i1.txt", "build/art/room4/i2.txt", "build/art/room4/i3.txt", "build/art/room4/i4.txt", "build/art/room4/i5.txt", "build/art/room4/i6.txt", "build/art/room4/i7.txt"};
const std::string room4ZOOMED[8] = {"build/art/room4/zoomed/i3Zoom.txt", "build/art/room4/zoomed/i3Zoom.txt", "build/art/room4/zoomed/i3Zoom.txt", "build/art/room4/zoomed/i3Zoom.txt", "build/art/room4/zoomed/i3Zoom.txt", "build/art/room4/zoomed/i6Zoom.txt", "build/art/room4/zoomed/i7Zoom.txt"};	
const std::string room4BookArray[5] = {"build/art/room4/zoomed/BookZoom1.txt", "build/art/room4/zoomed/BookZoom2.txt", "build/art/room4/zoomed/BookZoom3.txt", "build/art/room4/zoomed/BookZoom4.txt", "build/art/room4/zoomed/BookZoom5.txt"};
bool room4VIEWED[7] = {false, false, false, false, false, false, false};
bool room4ZOOMEDVIEWED[8] = {false, false, false, false, false, false, false, false};

std::string saveFileName;
std::string listenerType = "RoomLeftRight";
int roomNumber = 0;
int currentWallIndex = 0;
char** art = nullptr;
int artWidth = 0, artHeight = 0;
int totalConsoleHeight = 0;
int totalConsoleWidth = 0;
int  fullScreenTextBoxHeight = 0;
char input = ' ';
bool running = true;
bool globalZoomed = false;

std::vector<std::string> currentWall;

int main(int argc, char* argv[]) {

// Terminal setups
    enableUTF8Console();
    setFullScreen();
    getFullScreenDimensions();
    hideCursor();
    clearWholeScreen();
    
    startScreen(); // Display Start Screen for input

    clearWholeScreen();

    return 0;
}
