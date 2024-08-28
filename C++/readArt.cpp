#include "readArt.hpp"

/*!
 * @file
 * @brief readArt.cpp
 */

int imgHeight_TEST = 0;
int imgWidth_TEST = 0;

// Function to read a .txt file into a 2D array of chars
char** readFileTo2DArray(const std::string& filename, int &width, int &height) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return nullptr;
    }

    std::vector<std::string> lines;
    std::string line;
    width = 0;
    height = 0;

    // Read file line by line
    while (getline(file, line)) {
        lines.push_back(line);
        if (line.length() > width) {
            width = line.length();
        }
        height++;
    }
    file.close();

    // Allocate 2D array
    char** array = new char*[height];
    for (int i = 0; i < height; i++) {
        array[i] = new char[width + 1]; // +1 for null terminator
        std::fill(array[i], array[i] + width, ' '); // Fill with spaces
        array[i][width] = '\0'; // Null terminator
    }

    // Copy lines into the 2D array
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < lines[i].length(); j++) {
            array[i][j] = lines[i][j];
        }
    }
    return array;
}

// Function to deallocate the 2D array
void delete2DArray(char** array, int height) {
    for (int i = 0; i < height; i++) {
        delete[] array[i];
    }
    delete[] array;
}
