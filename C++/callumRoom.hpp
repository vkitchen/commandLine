#ifndef CALLUM_ROOM_HPP
#define CALLUM_ROOM_HPP

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

extern bool room4VIEWED[];
extern bool room4ZOOMEDVIEWED[];


/*!
 * @file 
 * @brief Header file for CallumRoom.cpp
 * @details This header file declares the functions and includes the necessary
 * headers for the Callum Room module of the application. It handles
 * the functionality related to the Callum Room.
 */

/**
 * @brief Runs the Callum Room functionality.
 * @details This function initializes and manages the Callum Room, which is a
 * specific part of the application. It is responsible for rendering
 * the room's interface, handling user inputs, and managing the
 * room's state.
 */
void runCallum();

#endif // CALLUM_ROOM_HPP
