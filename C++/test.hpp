#ifndef TEST_HPP
#define TEST_HPP

#include <iostream>
#include <stdexcept>
#include <fstream>
#include <vector>
#include <conio.h>
#include <windows.h>
#include <cstring>
#include "renderArt.hpp"
#include "readArt.hpp"
#include "terminalHelpers.hpp"
#include "textBox.hpp"
#include "inputListener.hpp"
#include "startScreen.hpp"


extern std::string listenerType;
extern int roomNumber;
extern int currentWallIndex;
extern char** art;
extern int artWidth, artHeight;
extern int totalConsoleHeight;
extern int totalConsoleWidth;
extern int  fullScreenTextBoxHeight;
extern char input;
extern bool running;

void testMain();

bool imageSize(int artHeight, int artWidth);

#endif // TEEST_HPP
