#ifndef SAVE_OR_LOAD_GAME_HPP
#define SAVE_OR_LOAD_GAME_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstring>
#include <ctime>
#include <direct.h>
#include <cerrno>
#include "optionsBox.hpp"
#include "introRoom.hpp"
#include "oscarRoom.hpp"
#include "lachlanRoom.hpp"
#include "anthonyRoom.hpp"
#include "callumRoom.hpp"

/*!
 * @file
 * @brief Header file for saveOrLoadGame.cpp
 * @details Saves game state to txt file or Loads game state from txt file
 */


extern char input;
extern bool running;
extern char** art;
extern int artWidth, artHeight;
extern bool running;
extern int currentWallIndex;
extern int roomNumber;
extern bool globalZoomed;
extern std::string saveFileName;

/**
 * @brief 
 * 
 */
int saveGame(bool currentRoomZoomed);

/**
 * @brief 
 * 
 */
void loadGame(const std::string& saveFileName);

/**
 * @brief 
 * 
 */
std::vector<std::string> getSaveFilesList();

#endif // SAVE_OR_LOAD_GAME_HPP
