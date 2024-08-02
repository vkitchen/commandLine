#ifndef RENDER_ART_HPP
#define RENDER_ART_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

extern char input;
extern bool running;
extern std::string room1[], room2[], room3[], room4[];


void loadAndRenderWall(const std::string& filename, char** &art, int &artWidth, int &artHeight);
void renderCenteredArt(char** art, int artWidth, int artHeight);

#endif // RENDER_ART_HPP
