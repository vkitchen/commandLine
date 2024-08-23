#include <windows.h>
#include <iostream>
#include <stdexcept>
#include "renderArt.hpp"
#include "readArt.hpp"
#include "terminalHelpers.hpp"
#include "test.hpp"

extern bool testMode;


void renderCenteredArt(char** art, int artWidth, int artHeight) {
    // if(testMode){
    //     try{
    //         bool res = imageSize(artWidth, artHeight);
    //     }catch(const std::runtime_error& e){
    //         std::cerr << e.what() << std::endl;
    //         running = false;
    //     }
    // }
    
    int startX = (totalConsoleWidth - (artWidth / 3)) / 2;  // artWidth needs to be /3 due to UTF8 using 3 bytes, but artWidth being 1 byte
    int startY = (totalConsoleHeight * 4 / 5 - artHeight) / 2;

    //clearWholeScreen();

    for (int i = 0; i < artHeight; ++i) {
        COORD coord = {static_cast<SHORT>(startX), static_cast<SHORT>(startY + i)};
        HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleCursorPosition(console, coord);
        std::cout << art[i];
    }
}

void renderArt(char** art, int artWidth, int artHeight, int startX, int startY) {

    //clearWholeScreen();

    for (int i = 0; i < artHeight; ++i) {
        COORD coord = {static_cast<SHORT>(startX), static_cast<SHORT>(startY + i)};
        HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleCursorPosition(console, coord);
        std::cout << art[i];
    }    
}


void loadArt(const std::string& filename, char** &art, int &artWidth, int &artHeight) {
    // Deallocate the previous 2D array
    if (art != nullptr) {
        delete2DArray(art, artHeight);
    }

    // Load the new wall
    art = readFileTo2DArray(filename, artWidth, artHeight);
    //renderCenteredArt(art, artWidth, artHeight);
}