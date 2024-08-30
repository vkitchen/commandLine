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
const std::string room[2] = {"../art/room1/W1.txt", "../art/tests/W2.txt"};

int artWidth = 0;
int artHeight = 0;
char** art = nullptr;

// Checks if the images for the rooms being rendered are the correct dimensions
bool imageSize(const std::string& filename, char** &art, int &artWidth, int &artHeight){
    // loop through walls in room 1
    // get their corrosponding array
    // test the size of the array to determine height / width
    // if one fails crash
    art = readFileTo2DArray(filename, artWidth, artHeight);
    if(artHeight == 64){
        return true;
    }else{
        return false;
    }
}

// main method to handle al ltests
int main(){
    
    bool failed = false;
    
    // tests for image sizes
    if(!imageSize(room[0], art, artWidth, artHeight)){
        failed = true;
    }
    if(!imageSize(room[1], art, artWidth, artHeight)){
        failed = true;
    }
       
    if(failed){ 
        std::cout << "ROOM ART IS INCORRECT SIZE" << std::endl;
        return 1;
    } else {
        std::cout << "ROOM ART <PASSED>" << std::endl;
        return 0;
    }

}


