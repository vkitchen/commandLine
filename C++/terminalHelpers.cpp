#include <windows.h>
#include "terminalHelpers.hpp"


// Sets global variables in main.cpp to the amount of characters in the terminal wide and how many lines
void getFullScreenDimensions() {
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    if (GetConsoleScreenBufferInfo(console, &csbi)) {
        totalConsoleWidth = csbi.srWindow.Right - csbi.srWindow.Left;
        totalConsoleHeight = csbi.srWindow.Bottom - csbi.srWindow.Top;
        fullScreenTextBoxHeight = totalConsoleHeight * 4 / 5;
    } else {
        totalConsoleWidth = 0;
        totalConsoleHeight = 0;
    }
}

// Makes cursor of terminal clear for printing without it jittering everywhere
void hideCursor() {
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(console, &cursorInfo);
    cursorInfo.bVisible = false; // Set the cursor visibility to false
    SetConsoleCursorInfo(console, &cursorInfo);
}


// Clears whole screen
void clearWholeScreen() {
    // Get console handle
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

    // Get console screen buffer info
    CONSOLE_SCREEN_BUFFER_INFO screen;
    GetConsoleScreenBufferInfo(console, &screen);

    // Calculate the total number of characters in the console
    DWORD consoleSize = screen.dwSize.X * screen.dwSize.Y;

    // Initialize variables for clearing console
    COORD topLeft = {0, 0};
    DWORD written;

    // Fill the entire console screen with spaces (effectively clearing it)
    FillConsoleOutputCharacterA(console, ' ', consoleSize, topLeft, &written);

    // Set the color attributes for all console characters (standard white text)
    FillConsoleOutputAttribute(console, screen.wAttributes, consoleSize, topLeft, &written);

    // Set the cursor position back to the top left of the console
    SetConsoleCursorPosition(console, topLeft);
}


// Clears partial amount of lines 
void clearPartialScreen(int startY, int endY) {
    COORD coord;
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD charsWritten;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(console, &csbi);
    DWORD consoleSize = csbi.dwSize.X;

    for (int y = startY; y <= endY; ++y) {
        coord = {0, static_cast<SHORT>(y)};
        FillConsoleOutputCharacter(console, ' ', consoleSize, coord, &charsWritten);
        FillConsoleOutputAttribute(console, csbi.wAttributes, consoleSize, coord, &charsWritten);
    }
}

void setFullScreen() {
    HWND consoleWindow = GetConsoleWindow(); // Get the console window handle
    ShowWindow(consoleWindow, SW_MAXIMIZE);  // Maximize the console windo
}

void enableUTF8Console() {
    // Set the console output code page to UTF-8
    if (!SetConsoleOutputCP(CP_UTF8)) {
        std::cerr << "Error setting UTF-8 code page." << std::endl;
    } else {
        std::cout << "UTF-8 encoding enabled for the console." << std::endl;
    }

    // Set the console input code page to UTF-8
    if (!SetConsoleCP(CP_UTF8)) {
        std::cerr << "Error setting UTF-8 input code page." << std::endl;
    }
}
