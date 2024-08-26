#include "textBox.hpp"
#include "startScreen.hpp"
#include "renderArt.hpp"
#include "optionsBox.hpp"

void startScreen() {
    int startXBox = totalConsoleWidth * 2 / 5;
    int endXBox = totalConsoleWidth * 3 / 5;
    int startYBox = (totalConsoleHeight * 1 / 3) + 1;
    int endYBox = totalConsoleHeight - 1;

    std::string title = "art/room4/Escape-Owheo.txt";
    loadArt(title, art, artWidth, artHeight);
    int startXTitle = (totalConsoleWidth - artWidth/3) / 2;
    int startYTitle = (startYBox - artHeight) / 2;
    renderArt(art, artWidth, artHeight, startXTitle, startYTitle);

    std::vector<std::string> options = {"NEW GAME", "LOAD GAME", "SR STATS", "SETTINGS", "EXIT"};

    int selectedIndex = renderOptionsBox(startXBox, endXBox, startYBox, endYBox, options);

    switch (selectedIndex) {
        case 0:
            // New Game selected, break to return to main.cpp and enter main game loop
            input = ' ';
            break;

        case 1:
            std::cout << "LOAD GAME" << std::endl;
            // Load Game Selected. TODO
            break;

        case 2:
            std::cout << "SR STATS" << std::endl;
            // SR STATS Selected.  TODO
            break;

    	case 3:
            std::cout << "" << std::endl;
            // Settings Selected.  TODO
            break;

        case 4:
            // Exit selected
            running = false;
            
    }
}