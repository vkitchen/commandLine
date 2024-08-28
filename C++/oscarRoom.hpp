#ifndef OSCAR_ROOM_HPP
#define OSCAR_ROOM_HPP

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

extern bool room1VIEWED[];
extern bool room1ZOOMEDVIEWED[];

/*!
 * @file 
 * @brief Header file for oscarRoom.cpp
 * @details This header file declares the functions and includes the necessary
 * headers for the Oscar Room module of the application. It handles
 * the functionality related to the Oscar Room.
 */

/**
 * @brief Runs the Oscar Room functionality.
 * @details This function initializes and manages the Oscar Room, which is a
 * specific part of the application. It is responsible for rendering
 * the room's interface, handling user inputs, and managing the
 * room's state.
 */
void runOscar();

#endif // OSCAR_ROOM_HPP
