#include "compat.hpp"
#include "textBox.hpp"
#include "startScreen.hpp"
#include "renderArt.hpp"
#include "optionsBox.hpp"
#include "terminalHelpers.hpp"
#include "saveOrLoadGame.hpp"

/*!
 * @file
 * @brief startScreen.cpp
 */


void startScreen() {
    int startXBox = totalConsoleWidth * 2 / 5;
    int endXBox = totalConsoleWidth * 3 / 5;
    int startYBox = (totalConsoleHeight * 1 / 3) + 1;
    int endYBox = totalConsoleHeight - 1;
    

    std::string title = "build/art/startScreen/Escape-Owheo.txt";

    loadArt(title, art, artWidth, artHeight);
    int startXTitle = (totalConsoleWidth - artWidth/3) / 2;
    int startYTitle = (startYBox - artHeight) / 2;
    renderArt(art, artWidth, artHeight, startXTitle, startYTitle);
    //std::vector<std::string> options = {"NEW GAME", "LOAD GAME", "SR STATS", "SETTINGS", "EXIT"};
    std::vector<std::string> options = {"PLAY", "EXIT"};
    input  = ' ';
    int selectedIndex = renderOptionsBox(startXBox, endXBox, startYBox, endYBox, options);

    switch (selectedIndex) {
        case 0: 
            // New Game selected, run the intro
            clearWholeScreen();
            currentWallIndex = 0;
            globalZoomed = 0;
            roomNumber = 0;
            runIntro();
            //runCallum();
            //runOscar();
            break;

        // case 1: {
        //     std::vector<std::string> saves = getSaveFilesList();
        //     if (saves.empty()) {
        //         std::string noSaves = "No Save Game Data Found";
        //         renderBox(startXBox, endXBox, startYBox, endYBox, noSaves, FALSE, FALSE, FALSE, "");
        //         Sleep(1000);
        //         clearWholeScreen();
        //         startScreen();
        //     }
            
        //     int selectedSave = renderOptionsBox(startXBox, endXBox, startYBox, endYBox, saves);
        //     if (selectedSave == 50) {
        //         startScreen();
        //         break;
        //     }
            
        //     saveFileName = saves[selectedSave];

        //     loadGame(saveFileName);

        //     clearWholeScreen();
        //     //loadingGraphics();
        //     clearWholeScreen();

        //     switch (roomNumber) {
        //         case 0:
        //             runIntro();
        //             break;
        //         case 1:
        //             runAnthony();
        //             break;
        //         case 2:
        //             runOscar();
        //             break;
        //         case 3:
        //             runLachlan();
        //             break;
        //         case 4:
        //             runCallum();
        //             break;
        //     }
        // }
        //     break;

        case 1:
            if(running != false){
                running = false;
            };
            break;       
        default:
            std::string noSaves = "Broke Start";
            msleep(1000);
            renderBox(startXBox, endXBox, startYBox, endYBox, noSaves, FALSE, FALSE, FALSE, "");
            break;
    }
}
