#include <windows.h>
#include "clearScreen.h"

// Function to clear all lines in the console
void ClearScreen() {
    // Get the handle to the standard output
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hStdOut == INVALID_HANDLE_VALUE) {
        return;
    }

    // Get the console screen buffer info
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if (!GetConsoleScreenBufferInfo(hStdOut, &csbi)) {
        return;
    }

    // Calculate the size of the console screen buffer
    DWORD consoleSize = csbi.dwSize.X * csbi.dwSize.Y;

    // Set the cursor position to the top left corner
    COORD cursorHomeCoord = {0, 0};
    SetConsoleCursorPosition(hStdOut, cursorHomeCoord);

    // Fill the console screen buffer with spaces
    DWORD charsWritten;
    FillConsoleOutputCharacter(hStdOut, (TCHAR) ' ', consoleSize, cursorHomeCoord, &charsWritten);

    // Fill the console screen buffer with the current text attributes
    FillConsoleOutputAttribute(hStdOut, csbi.wAttributes, consoleSize, cursorHomeCoord, &charsWritten);

    // Set the cursor position back to the top left corner
    SetConsoleCursorPosition(hStdOut, cursorHomeCoord);
}
