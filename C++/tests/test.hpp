#ifndef TEST_HPP
#define TEST_HPP

#include <iostream>
#include <stdexcept>
#include <fstream>
#include <vector>
#include <conio.h>
#include <windows.h>
#include <cstring>
#include "../renderArt.hpp"
#include "../readArt.hpp"
#include "../terminalHelpers.hpp"
#include "../textBox.hpp"
#include "../inputListener.hpp"
#include "../startScreen.hpp"


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
extern const int numWalls;
extern const std::string room1[];
extern const std::string room2[];
extern const std::string room3[];
extern const std::string room4[];
extern int imageHeight_TEST;
extern int imageWidth_TEST;

void testMain();

bool imageSize(const std::string& filename, char** &art, int &artWidth, int &artHeight);

#endif // TEEST_HPP
