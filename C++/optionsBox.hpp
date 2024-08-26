#ifndef OPTIONS_BOX_HPP
#define OPTIONS_BOX_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

extern int totalConsoleHeight, totalConsoleWidth;

int renderOptionsBox(int startX, int endX, int startY, int endY, std::vector<std::string> options);
std::string stringInputBox(std::string wordIn);

#endif // OPTIONS_BOX_HPP
