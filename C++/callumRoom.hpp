/*!
 * @file 
 * @brief Header file for CallumRoom.cpp
 * @details This header file declares the functions and includes the necessary
 * headers for the Callum Room module of the application. It handles
 * the functionality related to the Callum Room.
 */

#ifndef CALLUM_ROOM_HPP
#define CALLUM_ROOM_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include "compat.hpp"
#include "renderArt.hpp"
#include "readArt.hpp"
#include "terminalHelpers.hpp"
#include "saveOrLoadGame.hpp"
#include "textBox.hpp"
#include "inputListener.hpp"
#include "startScreen.hpp"

extern bool room4VIEWED[];
extern bool room4ZOOMEDVIEWED[];


/**
 * @brief Runs the Callum Room.
 * @details This function initializes and manages the Callum Room, which is a
 * specific part of the application. It is responsible for rendering
 * the room's interface, handling user inputs, and managing the
 * room's state.
 */
void runCallum();

/**
 * @brief Renders the zoomed-out walls of Callums rooms
 * @details This function displays Callums Rooms walls to screen, 
 * its own function due to the number of walls being larger than other rooms
 */
void renderCallumRoom();

/**
 * @brief Renders the zoomed-in walls of Callums rooms
 * @details This function renders the zoomed in walls of callums room
 */
void renderCallumZoomed();

/**
 * @brief Checks the wall is able to be zoomed in on
 * @details checks the wall is able to be zoomed in on
 */
bool canZoom(int wallIndex);

#endif // CALLUM_ROOM_HPP
