#include <iostream>
#include <stdexcept>

// Checks if the images for the rooms being rendered are the correct dimensions
bool imageSize(int artWidth, int artHeight){

    if(artWidth == 660 && artHeight == 68){
        return true;
    }else{
        std::cout << artHeight << std::endl;
        throw std::runtime_error("Incorrect image size, expcted (660 x 63) -> UTF8");
    }
}

