#include "textBox.hpp"
#include "startScreen.hpp"
#include "renderArt.hpp"
#include "optionsBox.hpp"
#include "terminalHelpers.hpp"
#include <windows.h>

/*!
 * @file
 * @brief startScreen.cpp
 */

void startScreen() {
    int startXBox = totalConsoleWidth * 2 / 5;
    int endXBox = totalConsoleWidth * 3 / 5;
    int startYBox = (totalConsoleHeight * 1 / 3) + 1;
    int endYBox = totalConsoleHeight - 1;



    const double probability = 0.1; // 10% chance
    const int arraysize = 26860;
    std::vector<std::vector<char>> array(85, std::vector<char>(316));

    std::string title = "art/startScreen/Escape-Owheo.txt";

    // Create a 2D vector of chars
    std::srand(static_cast<unsigned>(1));
    for(int i = 0; i < 85; i++){
        for(int j = 0 ; j < 316; j++){
            float randomchoice = static_cast<float>(std::rand()) / RAND_MAX;

            if(randomchoice < 0.1){
                array[i][j] = '1' + (std::rand() % 9);
            }else{
                array[i][j] = ' ';
            }
        }

    }
    char* ptrarray[85];
    for(int i = 0; i< 85; i++){
        ptrarray[i] = array[i].data();
    }
    int frames = 0;
    while(frames < 1){
        for(int i = 0; i < 85; i++){
            for(int j = 0 ; j < 316; j++){
                std::cout << ptrarray[i][j];
                
            }
             Sleep(10);
        }
        frames ++;
    }
    loadArt(title, art, artWidth, artHeight);
    int startXTitle = (totalConsoleWidth - artWidth/3) / 2;
    int startYTitle = (startYBox - artHeight) / 2;
    renderArt(art, artWidth, artHeight, startXTitle, startYTitle);
    //std::vector<std::string> options = {"NEW GAME", "LOAD GAME", "SR STATS", "SETTINGS", "EXIT"};
    std::vector<std::string> options = {"NEW GAME", "EXIT"};

    int selectedIndex = renderOptionsBox(startXBox, endXBox, startYBox, endYBox, options);

    switch (selectedIndex) {
        case 0: 
            // New Game selected, break to return to main.cpp and enter main game loop
            input = ' ';
            break;

        // case 1:
        //     std::cout << "LOAD GAME" << std::endl;
        //     // Load Game Selected. TODO
        //     break;

        // case 2:
        //     std::cout << "SR STATS" << std::endl;
        //     // SR STATS Selected.  TODO
        //     break;

    	// case 3:
        //     std::cout << "" << std::endl;
        //     // Settings Selected.  TODO
        //     break;

        case 1:
            // Exit selected
            running = false;
            
            
    }
}