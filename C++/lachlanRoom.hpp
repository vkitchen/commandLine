#ifndef LACHLAN_ROOM_HPP
#define LACHLAN_ROOM_HPP

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

extern bool room2VIEWED[];
extern bool room2ZOOMEDVIEWED[];


/*!
 * @file 
 * @brief Header file for lachlanRoom.cpp
 * @details This header file declares the functions and includes the necessary
 * headers for the Lachlan Room module of the application. It handles
 * the functionality related to the Lachlan Room.
 */

/**
 * @brief Runs the Lachlan Room functionality.
 * @details This function initializes and manages the Lachlan Room, which is a
 * specific part of the application. It is responsible for rendering
 * the room's interface, handling user inputs, and managing the
 * room's state.
 */
void runLachlan();

#endif // LACHLAN_ROOM_HPP
