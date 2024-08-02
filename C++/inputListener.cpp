        
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "inputListener.hpp"
#include "renderArt.hpp"

void chooseAndUseInput(int currentWallIndex, char input, std::string& listenerType) {
        
        if (input == 'q') {
            running = false; // Quit the game
        } else if (input == 75 || input == 77) { // Left or Right arrow keys
            if (input == 75) { // Left arrow key
                currentWallIndex = (currentWallIndex - 1 + 4) % 4;
            } else if (input == 77) { // Right arrow key
                currentWallIndex = (currentWallIndex + 1) % 4;
            }
            loadAndRenderWall(room1[currentWallIndex], art, artWidth, artHeight);
        }

}