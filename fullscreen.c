#include <windows.h>
#include "fullscreen.h"

// Function to simulate a key press
void PressKey(WORD key, BOOL bExtended) {
    INPUT input = {0};
    if (bExtended) {
        input.ki.dwFlags = KEYEVENTF_EXTENDEDKEY;
    }
    input.type = INPUT_KEYBOARD;
    input.ki.wVk = key;
    SendInput(1, &input, sizeof(INPUT));
}

// Function to simulate a key release
void ReleaseKey(WORD key, BOOL bExtended) {
    INPUT input = {0};
    if (bExtended) {
        input.ki.dwFlags = KEYEVENTF_EXTENDEDKEY;
    }
    input.type = INPUT_KEYBOARD;
    input.ki.wVk = key;
    input.ki.dwFlags = KEYEVENTF_KEYUP;
    SendInput(1, &input, sizeof(INPUT));
}

// Function to make the window full screen
void FullScreen() {
    // Simulate Alt + Enter to make the window full screen
    PressKey(VK_MENU, FALSE);   // Alt key down
    PressKey(VK_RETURN, FALSE); // Enter key down
    ReleaseKey(VK_RETURN, FALSE); // Enter key up
    ReleaseKey(VK_MENU, FALSE);  // Alt key up
}


