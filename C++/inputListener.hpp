/*!
 * @file
 * @brief Header file for inputListener.cpp
 * @details Provides other files the ability to listen for input from user. Depending on what 
 * function is used, the input listened to, and the effect that the input has will
 */

#ifndef INPUT_LISTENER_HPP
#define INPUT_LISTENER_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <string>


extern int currentWallIndex;
extern int totalConsoleWidth;
extern int fullScreenTextBoxHeight;
extern int totalConsoleHeight;
extern int roomNumber;
extern char input;
extern std::vector<std::string> options;
extern bool globalZoomed;

/**
 * @brief Listens for char input from keyboard
 * @details char input used to iteratively build word by adding keypressed to partialInput.
 * Can place in whie loop when called and listen for global variable 'input' to check if is = to your confirm key
 * @param partialWord [in] Should be intialised with "", unless you feel like having a pre-completed word
 * @return std::string of completed word wanting to be inputed in text box
 */
std::string textInputListener(const std::string& partialWord);

/**
 * @brief listens for left and right arrow keys being pressed
 * @details Updates global variable 'currentWallIndex' depending on the key pressed
 */
void roomLeftRightListener();

/**
 * @brief Listens for up, down, and enter keys when in the start menu
 * @return int that signifies whether up (1), down (2), enter (0), or nothing (3) was pressed
 */
int upDownEnterListener();

/**
 * @brief Setter for global variable 'input'
 * @details listens for the next keyboard press
 */
void processInput();

/**
 * @brief Listens and responds to input inside of Intro Room
 * @details Listens for left and right arrows for navigation between walls. Listens for enter on zoomable walls.
 * Listens for '-' when zoomed in, and stops listening for left and right input when zoomed in
 * @param IntroZoomed [in] bool values stating whether view for Intro Room is zoomed in (true) or not (false)
 */
void roomInputListenerIntro(bool* IntroZoomed);

/**
 * @brief Listens and responds to input inside of Oscars Room
 * @details Listens for left and right arrows for navigation between walls. Listens for enter on zoomable walls.
 * Listens for '-' when zoomed in, and stops listening for left and right input when zoomed in
 * @param oscarZoomed [in] bool values stating whether view for Oscars Room is zoomed in (true) or not (false)
 */
void roomInputListenerOscar(bool* oscarZoomed);

/**
 * @brief Listens and responds to input inside of Lachlans Room
 * @details Listens for left and right arrows for navigation between walls. Listens for enter on zoomable walls.
 * Listens for '-' when zoomed in, and stops listening for left and right input when zoomed in. 
 * Also listens for 'y' or 'n' when zoomed into specific walls
 * @param timerRunning [in] tells listener wheter timer is running
 * @param lachlanZoomed [in] bool values stating whether view for Lachlans Room is zoomed in (true) or not (false)
 * @param oscarZoomed [in] tells listener if door is open in room
 * @param lachlanSolved [in] bool values stating whether view for Lachlans Room is solved (true) or not (false)
 */
void roomInputListenerLachlan(bool* timerRunning, bool* lachlanZoomed, bool* doorOpen, bool* lachlanSolved);

/**
 * @brief Listens and responds to input inside of Anthonys Room
 * @details Listens for left and right arrows for navigation between walls. Listens for enter on zoomable walls.
 * Listens for '-' when zoomed in, and stops listening for left and right input when zoomed in
 * @param anthonyZoomed [in] bool values stating whether view for Anthonys Room is zoomed in (true) or not (false)
 */
void roomInputListenerAnthony(bool* anthonyZoomed);

/**
 * @brief Listens and responds to input inside of callum Room
 * @details Listens for left and right arrows for navigation between walls. Listens for enter on zoomable walls.
 * Listens for '-' when zoomed in, and stops listening for left and right input when zoomed in
 * @param timerRunning [in] tells listener wheter timer is running
 * @param lachlanZoomed [in] bool values stating whether view for Lachlans Room is zoomed in (true) or not (false)
 * @param oscarZoomed [in] tells listener if door is open in room
 * @param lachlanSolved [in] bool values stating whether view for Lachlans Room is solved (true) or not (false)
 */
void roomInputListenerCallum(bool* callumZoomed, int* currentWallIndex, int* currentBookIndex, std::string* userAnswer);

#endif // INPUT_LISTENER_HPP
