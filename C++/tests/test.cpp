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
char** art = nullptr;

// Checks if the images for the rooms being rendered are the correct dimensions
bool imageSize(const std::string& filename, char** &art, int &artWidth, int &artHeight){
    art = readFileTo2DArray(filename, artWidth, artHeight);
    if(artHeight == 64 || artHeight == 0){
        return true;
    }else{
        return false;
    }
}

// main method to handle al ltests
int main(){
    
    bool failed = false;
    
    // tests for image sizes
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


    if(failed){ 
        std::cout << "ROOM ART IS INCORRECT SIZE" << std::endl;
        return 1;
    } else {
        std::cout << "ROOM ART <PASSED>" << std::endl;
        return 0;
    }

}


