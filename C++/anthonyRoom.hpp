#ifndef ANTHONY_ROOM_HPP
#define ANTHONY_ROOM_HPP

#include <iostream>
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

extern bool room3VIEWED[];
extern bool room3ZOOMEDVIEWED[];


/*!
 * @file 
 * @brief Header file for AnthonyRoom.cpp
 * @details This header file declares the functions and includes the necessary
 * headers for the Anthony Room module of the application. It handles
 * the functionality related to the Anthony Room.
 */

/**
 * @brief Runs the Anthony Room functionality.
 * @details This function initializes and manages the Anthony Room, which is a
 * specific part of the application. It is responsible for rendering
 * the room's interface, handling user inputs, and managing the
 * room's state.
 */
void runAnthony();

#endif // ANTHONY_ROOM_HPP
