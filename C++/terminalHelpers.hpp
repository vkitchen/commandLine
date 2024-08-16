#ifndef TERMINAL_HELPERS_HPP
#define TERMINAL_HELPERS_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

extern int totalConsoleHeight, totalConsoleWidth, fullScreenTextBoxHeight;

void getFullScreenDimensions();

void hideCursor();

void clearWholeScreen();

void clearPartialScreen(int startY, int endY);

void setFullScreen();

void enableUTF8Console();

void setConsoleFontSize(int sizeX, int sizeY);

#endif // TERMINAL_HELPERS_HPP
