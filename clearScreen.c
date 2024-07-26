#include "clearScreen.h"
#include <stdlib.h> // for system()

void ClearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}
