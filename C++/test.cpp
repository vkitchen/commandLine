#include "test.hpp"

// Checks if the images for the rooms being rendered are the correct dimensions
bool imageSize(const std::string& filename, char** &art, int &artWidth, int &artHeight){
    // loop through walls in room 1
    // get their corrosponding array
    // test the size of the array to determine height / width
    // if one fails crash
    art = readFileTo2DArray(filename, artWidth, artHeight);
    if(artWidth == 660 && artHeight == 64){
        return true;
    }else{
        throw std::runtime_error("Incorrect image size in " + filename + ", expcted (660 x 63) -> UTF8");
        return false;
    }
}

// main method to handle al ltests
int testArt(){

    // tests for image sizes
    for(int i = 0 ; i < 4; i++){
        if(!imageSize(room1[i], art, artWidth, artHeight)){
            std::cout << "Incorrect image size in room1[" << i << "]" << std::endl; 
            return 1;
        }
    }
    std::cout << "ALL ROOM ART IS CORRECT <<<< TEST PASSED >>>>>" << std::endl;
    return 0;
}

int testMain(){
    
    // tests for image sizes
    int result = testArt();
    return result;
}

