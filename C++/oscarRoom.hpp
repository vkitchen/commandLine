#ifndef OSCAR_ROOM_HPP
#define OSCAR_ROOM_HPP

/**
 * @file oscar_room.hpp
 * @brief Header file for the Oscar Room module.
 *
 * This header file declares the functions and includes the necessary
 * headers for the Oscar Room module of the application. It handles
 * the functionality related to the Oscar Room.
 */

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
#include "test.hpp"

/**
 * @brief Runs the Oscar Room functionality.
 *
 * This function initializes and manages the Oscar Room, which is a
 * specific part of the application. It is responsible for rendering
 * the room's interface, handling user inputs, and managing the
 * room's state.
 */
void runOscar();

#endif // OSCAR_ROOM_HPP
