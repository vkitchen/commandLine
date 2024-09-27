#ifndef INTRO_ROOM_HPP
#define INTRO_ROOM_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <conio.h>
#include <windows.h>
#include <cstring>
#include "renderArt.hpp"
#include "saveOrLoadGame.hpp"
#include "readArt.hpp"
#include "terminalHelpers.hpp"
#include "textBox.hpp"
#include "inputListener.hpp"
#include "startScreen.hpp"

extern bool room0VIEWED[];
extern bool room0ZOOMEDVIEWED[];


/*!
 * @file 
 * @brief Header file for introRoom.cpp
 * @details This header file declares the functions and includes the necessary
 * headers for the Anthony Room module of the application. It handles
 * the functionality related to the intro Room.
 */

/**
 * @brief Runs the intro Room functionality.
 * @details This function initializes and manages the intro Room, which is a
 * specific part of the application. It is responsible for rendering
 * the room's interface, handling user inputs, and managing the
 * room's state.
 */
void runIntro();

#endif // ANTHONY_ROOM_HPP
