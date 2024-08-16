#ifndef RENDER_ART_HPP
#define RENDER_ART_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stdexcept>

extern char input;
extern bool running;
extern const std::string room1[];
extern const std::string room2[];
extern const std::string room3[];
extern const std::string room4[];
extern char** art;
extern int artWidth, artHeight;
extern bool testMode;


void loadArt(const std::string& filename, char** &art, int &artWidth, int &artHeight);
void renderCenteredArt(char** art, int artWidth, int artHeight);
void renderArt(char** art, int artWidth, int artHeight, int startX, int startY);

#endif // RENDER_ART_HPP
