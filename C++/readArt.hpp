#ifndef READART_HPP
#define READART_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
/*!
 * @file
 * @brief Header file for readArt.cpp
 * @details setter methods for the gobal variable 'art'
 */


/**
 * @brief Function to read a .txt file into a 2D array of char
 * 
 * @param filename [in] Path to desired .txt art file to be loaded into global variable 'art'
 * @param width [in] how wide (max number of characters in one line) the art work is
 * @param height [in] how many lines the art work is
 * @return char** that is the art in a big long string
 */
char** readFileTo2DArray(const std::string& filename, int &width, int &height);


/**
 * @brief Function to deallocate the 2D array
 * 
 * @param array [in] the global variable 'art' array
 * @param height [in] the amount of lines in the ASCII art
 */
void delete2DArray(char** array, int height);

#endif // READART_HPP
