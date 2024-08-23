#ifndef INPUT_LISTENER__HPP
#define INPUT_LISTENER__HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

extern int currentWallIndex, totalConsoleWidth, fullScreenTextBoxHeight, totalConsoleHeight, roomNumber;
extern char input;
extern std::vector<std::string> options;
extern bool zoomed;

void roomLeftRightListener();
int startMenuListener();
void processInput();
void roomInputListenerOscar();

#endif // INPUT_LISTENER__HPP
