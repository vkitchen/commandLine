#ifndef INPUT_LISTENER__HPP
#define INPUT_LISTENER__HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

extern int currentWallIndex, totalConsoleWidth, fullScreenTextBoxHeight, totalConsoleHeight, roomNumber;


void chooseAndUseInput(char input, std::string& listenerType);

#endif // INPUT_LISTENER__HPP
