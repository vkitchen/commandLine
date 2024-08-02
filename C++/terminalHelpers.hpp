#ifndef TERMINAL_HELPERS_HPP
#define TERMINAL_HELPERS_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

extern int totalConsoleHeight, totalConsoleWidth, textBoxHeight;

void getFullScreenDimensions();

void hideCursor();

void clearWholeScreen();

void clearPartialScreen(int startY, int endY);

void setFullScreen();

#endif // TERMINAL_HELPERS_HPP
