#ifndef INPUT_LISTENER__HPP
#define INPUT_LISTENER__HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

/*!
 * @file
 * @brief Header file for inputListener.cpp
 * @details Provides other files the ability to listen for input from user. Depending on what 
 * funciton is used, the input listened to, and the effect that the input has will
 */


extern int currentWallIndex, totalConsoleWidth, fullScreenTextBoxHeight, totalConsoleHeight, roomNumber;
extern char input;
extern std::vector<std::string> options;
extern bool zoomed;

/**
 * @brief Listens for char input from keyboard
 * @details char input used to iteratively build word by adding keypressed to partialInput.
 * Can place in whie loop when called and listen for global variable 'input' to check if is = to your confirm key
 * @param partialWord [in] Should be intialised with "", unless you feel like having a pre-completed word
 * @return std::string of completed word wanting to be inputed in text box
 */
std::string textInputListener(std::string partialWord);

/**
 * @brief listens for left and right arrow keys being pressed
 * @details Updates global variable 'currentWallIndex' depending on the key pressed
 */
void roomLeftRightListener();

/**
 * @brief Listens for up, down, and enter keys when in the start menu
 * @return int that signifies whether up (1), down (2), enter (0), or nothing (3) was pressed
 */
int startMenuListener();

/**
 * @brief Setter for global variable 'input'
 * @details listens for the next keyboard press
 */
void processInput();

/**
 * @brief Listens and responds to input inside of Oscars Room
 * @details Listens for left and right arrows for navigation between walls. Listens for enter on zoomable walls.
 * Listens for 'o' when zoomed in, and stops listening for left and right input when zoomed in
 */
void roomInputListenerOscar(bool* oscarZoomed);

/**
 * @brief Listens and responds to input inside of Lachlans Room
 * @details Listens for left and right arrows for navigation between walls. Listens for enter on zoomable walls.
 * Listens for 'o' when zoomed in, and stops listening for left and right input when zoomed in
 */
void roomInputListenerLachlan(bool* timerRunning, bool* lachlanZoomed, bool* doorOpen, bool* lachlanSolved);

/**
 * @brief Listens and responds to input inside of Anthonys Room
 * @details Listens for left and right arrows for navigation between walls. Listens for enter on zoomable walls.
 * Listens for 'o' when zoomed in, and stops listening for left and right input when zoomed in
 */
void roomInputListenerAnthony(bool* anthonyZoomed);

/**
 * @brief Listens and responds to input inside of callum Room
 * @details Listens for left and right arrows for navigation between walls. Listens for enter on zoomable walls.
 * Listens for 'o' when zoomed in, and stops listening for left and right input when zoomed in
 */
void roomInputListenerCallum(bool* callumZoomed);

#endif // INPUT_LISTENER__HPP
