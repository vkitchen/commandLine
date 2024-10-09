#include "textBox.hpp"
#include "startScreen.hpp"
#include "renderArt.hpp"
#include "optionsBox.hpp"
#include "terminalHelpers.hpp"
#include "saveOrLoadGame.hpp"
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

    loadingGraphics();

    std::string title = "build/art/startScreen/Escape-Owheo.txt";

    loadArt(title, art, artWidth, artHeight);
    int startXTitle = (totalConsoleWidth - artWidth/3) / 2;
    int startYTitle = (startYBox - artHeight) / 2;
    renderArt(art, artWidth, artHeight, startXTitle, startYTitle);
    //std::vector<std::string> options = {"NEW GAME", "LOAD GAME", "SR STATS", "SETTINGS", "EXIT"};
    std::vector<std::string> options = {"NEW GAME", "LOAD GAME", "EXIT"};

    int selectedIndex = renderOptionsBox(startXBox, endXBox, startYBox, endYBox, options);

    switch (selectedIndex) {
        case 0: 
            // New Game selected, run the intro
            clearWholeScreen();
            runIntro();
            //runLachlan();
            break;

        case 1: {
            std::vector<std::string> saves = getSaveFilesList();
            if (saves.empty()) {
                std::string noSaves = "No Save Game Data Found";
                renderBox(startXBox, endXBox, startYBox, endYBox, noSaves, FALSE, FALSE, FALSE, "");
                Sleep(1000);
                clearWholeScreen();
                startScreen();
            }
            
            int selectedSave = renderOptionsBox(startXBox, endXBox, startYBox, endYBox, saves);
            if (selectedSave == 50) {
                break;
            }
            
            saveFileName = saves[selectedSave];

            loadGame(saveFileName);

            clearWholeScreen();
            loadingGraphics();
            clearWholeScreen();

            switch (roomNumber) {
                case 0:
                    runIntro();
                    break;
                case 1:
                    runAnthony();
                    break;
                case 2:
                    runOscar();
                    break;
                case 3:
                    runLachlan();
                    break;
                case 4:
                    //runCallum();
                    break;
            }
        }
            break;

        // case 2:
        //     std::cout << "SR STATS" << std::endl;
        //     // SR STATS Selected.  TODO
        //     break;

    	// case 3:
        //     std::cout << "" << std::endl;
        //     // Settings Selected.  TODO
        //     break;

        case 2:
            // Exit selected
            running = false;
            break;       
        case 50:
            startScreen();
            break;
        default:
            std::string noSaves = "Broke Start";
            Sleep(1000);
            renderBox(startXBox, endXBox, startYBox, endYBox, noSaves, FALSE, FALSE, FALSE, "");
            break;
    }
}