#ifndef READART_HPP
#define READART_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

// Function to read a .txt file into a 2D array of chars
char** readFileTo2DArray(const std::string& filename, int &width, int &height);

// Function to deallocate the 2D array
void delete2DArray(char** array, int height);

#endif // READART_HPP
