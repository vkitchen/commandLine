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

// Test set up
const std::string room1test[4] = {"art/room1/W1.txt","art/room1/W2.txt","art/room1/W3.txt","art/room1/W4.txt"};
const std::string room2test[4] = {"art/room2/W1.txt","art/room2/W2.txt","art/room2/W3.txt","art/room2/W4.txt"};
const std::string room3test[4] = {"art/room3/W1.txt","art/room3/W2.txt","art/room3/W3.txt","art/room3/W4.txt"};
const std::string room4test[4] = {"art/room4/W1.txt","art/room4/W2.txt","art/room4/W3.txt","art/room4/W4.txt"};

int artWidth = 0;
int artHeight = 0;
int roomNumber = 1;
int currentWallIndex = 0;
char** art = nullptr;
int totalConsoleHeight = 0;
int totalConsoleWidth = 0;
int  fullScreenTextBoxHeight = 0;
char input = 61;
bool running = true;


// Checks if the images for the rooms being rendered are the correct dimensions
bool imageSize(const std::string& filename, char** &art, int &artWidth, int &artHeight){
    art = readFileTo2DArray(filename, artWidth, artHeight);
    if(artHeight == 64 || artHeight == 0){
        std::cout << "ROOM ART <PASSED>" << std::endl;
        return true;
    }else{
        std::cout << "ROOM ART IS INCORRECT SIZE" << std::endl;
        return false;
    }
}

bool zoomCheck(){

    bool oscarZoomed = false;
    roomInputListenerOscar(&oscarZoomed);
    if(oscarZoomed != true){
        std::cout << "ZOOM FUNCTION FAILED" << std::endl;
        return true;
    } 
    currentWallIndex = 2;
    oscarZoomed = false;
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

    std::cout << "ZOOM FUNCTION PASSED" << std::endl;
    return false;
}

// main method to handle al ltests
int main(){
    
    bool failed = false;
    failed = zoomCheck();
    //tests for image sizes
    for(int i = 0; i < 4; i++){
        if(!imageSize(room1test[i], art, artWidth, artHeight)){
            failed = true;
        }
    }
        // tests for image sizes
    for(int i = 0; i < 4; i++){
        if(!imageSize(room2test[i], art, artWidth, artHeight)){
            failed = true;
        }
    }
        // tests for image sizes
    for(int i = 0; i < 4; i++){
        if(!imageSize(room3test[i], art, artWidth, artHeight)){
            failed = true;
        }
    }
        // tests for image sizes
    for(int i = 0; i < 4; i++){
        if(!imageSize(room4test[i], art, artWidth, artHeight)){
            failed = true;
        }
    }
    //Tests will pass once the 'renderBox' function has correct number of arguments


    if(failed){ 

        return 1;
    } else {
        
        return 0;
    }

}


