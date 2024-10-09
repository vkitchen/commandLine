#include <iostream>
#include <stdexcept>
#include <fstream>
#include <vector>
#include <conio.h>
#include <windows.h>
#include <cstring>
#include <filesystem>
#include <iostream>
#include "../renderArt.hpp"
#include "../readArt.hpp"
#include "../terminalHelpers.hpp"
#include "../textBox.hpp"
#include "../inputListener.hpp"
#include "../startScreen.hpp"

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
const std::string room2ZOOMED[8] = {"build/art/room2/Zoomed/W1Z5.txt", "build/art/room2/Zoomed/W2Zoom.txt", "build/art/room2/Zoomed/W3Zoom.txt", "build/art/room2/Zoomed/W4Zoom.txt", "art/room2/Zoomed/W1Z4.txt", "art/room2/Zoomed/W1Z3.txt", "art/room2/Zoomed/W1Z2.txt", "art/room2/Zoomed/W1Z1.txt"};
bool room2VIEWED[numWalls] = {false, false, false, false};
bool room2ZOOMEDVIEWED[numWalls] = {false, false, false, false};

// Anthonys Room
const std::string room3[numWalls] = {"build/art/room3/W1.txt", "build/art/room3/W2.txt", "build/art/room3/W3.txt", "build/art/room3/W4.txt"};
const std::string room3ZOOMED[numWalls] = {"build/art/room3/zoomed/W1Zoom.txt", "build/art/room3/zoomed/W2Zoom.txt", "", "build/art/room3/zoomed/W4Zoom.txt"};
bool room3VIEWED[numWalls] = {false, false, false, false};
bool room3ZOOMEDVIEWED[numWalls] = {false, false, false, false};

// Callum Room
const std::string room4[numWalls] = {"build/art/room4/W1.txt", "build/art/room4/W2.txt", "build/art/room4/W3.txt", "build/art/room4/W4.txt"}; 
bool room4VIEWED[numWalls] = {false, false, false, false};
bool room4ZOOMEDVIEWED[numWalls] = {false, false, false, false};

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


// Checks if the images for the rooms being rendered are the correct dimensions
bool imageSize(const std::string& filename, char** &art, int &artWidth, int &artHeight){
    art = readFileTo2DArray(filename, artWidth, artHeight);
    if(artHeight == 64 || artHeight == 0){
        return true;
    }else{
        return false;
    }
}

bool imageSizeCheck(){
    //tests for image sizes
    bool failed = false;
    for(int i = 0; i < 4; i++){
        if(!imageSize(room1[i], art, artWidth, artHeight)){
            failed = true;
        }
    }
        // tests for image sizes
    for(int i = 0; i < 4; i++){
        if(!imageSize(room2[i], art, artWidth, artHeight)){
            failed = true;
        }
    }
        // tests for image sizes
    for(int i = 0; i < 4; i++){
        if(!imageSize(room3[i], art, artWidth, artHeight)){
            failed = true;
        }
    }
        // tests for image sizes
    for(int i = 0; i < 4; i++){
        if(!imageSize(room4[i], art, artWidth, artHeight)){
            failed = true;
        }
    }
    if(failed){
        std::cout << "ROOM ART IS INCORRECT SIZE" << std::endl;
        return true;
    } 
    std::cout << "ROOM ART FUNCTION PASSED" << std::endl;
    return false;
}

// testing zoom nputs are handled correctly for different rooms
bool zoomCheck(){
    input = 61;
    bool oscarZoomed = false;
    roomInputListenerOscar(&oscarZoomed);
    if(oscarZoomed != true){
        std::cout << "ZOOM FUNCTION FAILED" << std::endl;
        return true;
    } 
    currentWallIndex = 1;
    oscarZoomed = false;
    roomInputListenerOscar(&oscarZoomed);
    if(oscarZoomed != false){
        std::cout << "ZOOM FUNCTION FAILED" << std::endl;
        return true;
    } 
    currentWallIndex = 3;
    bool anthonyZoomed = false;
    roomInputListenerAnthony(&anthonyZoomed);
    if(anthonyZoomed != true){
        std::cout << "ZOOM FUNCTION FAILED" << std::endl;
        return true;
    } 
    currentWallIndex = 2;
    anthonyZoomed = false;
    roomInputListenerAnthony(&anthonyZoomed);
    if(anthonyZoomed != false){
        std::cout << "ZOOM FUNCTION FAILED" << std::endl;
        return true;
    } 

    std::cout << "ZOOM FUNCTION PASSED" << std::endl;
    return false;
}

// test wall index movments are handled correctly for different rooms
bool wallIndexCheck(){
    currentWallIndex = 0;
    input = 77; // look right 
    bool oscarZoomed = false;
    roomInputListenerOscar(&oscarZoomed);
    if(currentWallIndex != 1){
        std::cout << "ZOOM FUNCTION FAILED" << std::endl;
        return true;
    } 

    currentWallIndex = 0;
    input = 75; // look right 
    bool anthonyZoomed = false;
    roomInputListenerAnthony(&anthonyZoomed);
    if(currentWallIndex != 3){
        std::cout << "ZOOM FUNCTION FAILED" << std::endl;
        return true;
    } 

    currentWallIndex = 1;
    input = 75; // look right when zoomed in (should stay the same) 
    anthonyZoomed = true;
    roomInputListenerAnthony(&anthonyZoomed);
    if(currentWallIndex != 1){
        std::cout << "ZOOM FUNCTION FAILED" << std::endl;
        return true;
    } 

    currentWallIndex = 1;
    input = 75; // look right when zoomed in (should stay the same) 
    bool callumZoomed = true;
    roomInputListenerCallum(&callumZoomed);
    if(currentWallIndex != 1){
        std::cout << "ZOOM FUNCTION FAILED" << std::endl;
        return true;
    } 
    std::cout << "WALL INDEX FUNCTION PASSED" << std::endl;
    return false;
}

// test wall index movments are handled correctly for different rooms
bool startMenu(){
    input = 77; //  right 
    int res = upDownEnterListener();
    // user navigates right which isnt possible and therefore should return nothing
    if(res == 2 || res == 1){
        std::cout << "START MENU FUNCTION FAILED" << std::endl;
        return true;
    } 

    input = 75; //  left 
    res = upDownEnterListener();
    // user navigates left which isnt possible
    if(res != 3){
        std::cout << "START MENU FUNCTION FAILED" << std::endl;
        return true;
    } 

    input = 80; //  down
    res = upDownEnterListener();
    // user navigates left which isnt possible
    if(res != 2){
        std::cout << "START MENU FUNCTION FAILED" << std::endl;
        return true;
    } 
    std::cout << "START MENU FUNCTION PASSED" << std::endl;
    return false;
}

// test wall index movments are handled correctly for different rooms
bool textInput(){
    input = 'e'; //  right 
    std::string test_output = textInputListener("finish m");
    // user navigates right which isnt possible and therefore should return nothing
    if(test_output != "finish me"){
        std::cout << "USER TEXT INPUT FUNCTION FAILED" << std::endl;
        return true;
    } 
    std::cout << "USER TEXT INPUT FUNCTION PASSED" << std::endl;
    return false;
}

bool hideCursorCheck() {
    hideCursor();
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    if (GetConsoleCursorInfo(console, &cursorInfo)) {
        if (cursorInfo.bVisible == true) {
            std::cout << "HIDE CURSOR FUNCTION FAILED" << std::endl;
            return true;
        }
    }
    std::cout << "HIDE CURSOR FUNCTION PASSED" << std::endl;
    return false;
}

// main method to handle al ltests
int main(){
    
    bool failed = false;
    failed = zoomCheck();
    failed = wallIndexCheck();
    failed = imageSizeCheck();
    failed = startMenu();
    failed = textInput();
    failed = hideCursorCheck();
    
    if(failed){ 

        return 1;
    } else {
        
        return 0;
    }

}


