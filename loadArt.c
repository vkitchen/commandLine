#include <stdio.h>
#include <stdlib.h>
#include "loadArt.h"

// Function to load a text file into a dynamically allocated array
char* loadArt(const char* filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return NULL;
    }

    // Seek to the end of the file to determine its size
    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    rewind(file);

    // Allocate memory for the file content
    char *buffer = (char*)malloc((fileSize + 1) * sizeof(char));
    if (buffer == NULL) {
        perror("Error allocating memory");
        fclose(file);
        return NULL;
    }

    // Read the file content into the buffer
    size_t bytesRead = fread(buffer, sizeof(char), fileSize, file);
    buffer[bytesRead] = '\0'; // Null-terminate the string

    // Check for reading errors
    if (ferror(file)) {
        perror("Error reading file");
        free(buffer);
        fclose(file);
        return NULL;
    }

    fclose(file);
    return buffer;
}

// Function to print the char array, ignoring newline characters
void printArt(const char* art) {
    while (*art != '\0') {
        if (*art != '\n') {
            putchar(*art);
        }
        art++;
    }
}