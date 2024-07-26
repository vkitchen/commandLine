#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include "fullscreen.h"
#include "clearScreen.h"
#include "loadArt.h"


// Function to get console size
void GetConsoleSize(int *width, int *height) {
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hStdOut == INVALID_HANDLE_VALUE) {
        return;
    }

    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if (!GetConsoleScreenBufferInfo(hStdOut, &csbi)) {
        return;
    }

    *width = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    *height = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
}

int main() {
    // Wait for 0.5 seconds to give the user time to focus on the Command Prompt window
    Sleep(500);

    // Make the window full screen
    FullScreen();

    // Wait for 0.2 second to ensure the full screen transition is complete
    Sleep(200);

    // Clear all lines in the console
    ClearScreen();

    // Get and print the console size
    int width, height;

    const char* filename = "ASCII_Art/artTest1.txt"; // Replace with your file name
    char* fileContent = loadArt(filename);

    if (fileContent == NULL) {
        return 1;
    }

    GetConsoleSize(&width, &height);
    printf("Console size: %d x %d\n", width, height);
    printArt(fileContent);
    free(fileContent); // Free the allocated memory

    return 0;
}
