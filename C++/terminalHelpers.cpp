#include <windows.h>
#include "terminalHelpers.hpp"


// Sets global variables in main.cpp to the amount of characters in the terminal wide and how many lines
void getFullScreenDimensions() {
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    if (GetConsoleScreenBufferInfo(console, &csbi)) {
        totalConsoleWidth = csbi.srWindow.Right - csbi.srWindow.Left + 1;
        totalConsoleHeight = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
        textBoxHeight = totalConsoleHeight * 4 / 5;
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
    COORD topLeft = {0, 0};
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screen;
    DWORD written;

    GetConsoleScreenBufferInfo(console, &screen);
    FillConsoleOutputCharacterA(console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written);
    FillConsoleOutputAttribute(console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
                                screen.dwSize.X * screen.dwSize.Y, topLeft, &written);
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
