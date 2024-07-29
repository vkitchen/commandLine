#ifndef TEXT_BOX_HPP
#define TEXT_BOX_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

extern int totalConsoleHeight, totalConsoleWidth;

void renderBox(int startX, int endX, int startY, int endY, std::string& text);

#endif // TEXT_BOX_HPP
