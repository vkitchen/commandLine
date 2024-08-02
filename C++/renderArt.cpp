#include <windows.h>
#include "renderArt.hpp"
#include "readArt.hpp"
#include "terminalHelpers.hpp"


void renderCenteredArt(char** art, int artWidth, int artHeight) {
    int startX = (totalConsoleWidth - artWidth) / 2;
    int startY = (totalConsoleHeight * 4 / 5 - artHeight) / 2;

    clearPartialScreen(0, totalConsoleHeight * 4 / 5 - 1); // Clear the screen area above the box


    for (int i = 0; i < artHeight; ++i) {
        COORD coord = {static_cast<SHORT>(startX), static_cast<SHORT>(startY + i)};
        HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleCursorPosition(console, coord);
        std::cout << art[i];
    }
}


void loadAndRenderWall(const std::string& filename, char** &art, int &artWidth, int &artHeight) {
    // Deallocate the previous 2D array
    if (art != nullptr) {
        delete2DArray(art, artHeight);
    }

    // Load the new wall
    art = readFileTo2DArray(filename, artWidth, artHeight);
    renderCenteredArt(art, artWidth, artHeight);
}