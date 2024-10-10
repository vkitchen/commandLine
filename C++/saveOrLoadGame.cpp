#define _CRT_SECURE_NO_WARNINGS
#include "saveOrLoadGame.hpp"

int startXBoxSave = totalConsoleWidth * 2 / 5;
int endXBoxSave = totalConsoleWidth * 3 / 5;
int startYBoxSave = (totalConsoleHeight * 2 / 6) + 1;
int endYBoxSave = (totalConsoleHeight * 4 / 6) - 1;

std::string getCurrentTimeAsString() {
    // get Unix time
    std::time_t currentTime = std::time(nullptr);

    std::tm localTime;
    localtime_s(&localTime, &currentTime);

    char buffer[100];

    std::strftime(buffer, sizeof(buffer), "%Y-%m-%d_%H-%M-%S", &localTime);

    std::cout << std::string(buffer) << std::endl;

    return std::string(buffer);
}

bool createDirectoryIfNeeded(const std::string& dir) {
    //Attempt to make directory
    if (_mkdir(dir.c_str()) == -1) {

        if (errno != EEXIST) {
            // tell me why you failed you turd
            char errBuff[256];
            std::cerr << "Failed to create directory: " << dir << std::endl;
            std::cerr << "Error: " << strerror_s(errBuff, sizeof(errBuff), errno) << std::endl;
            return false;
        }
    }
    return true;
}
// returns 0 on succesful save and exit
// returns 1 on failed save and exit
// returns 2 on failed save and no exit
int saveGame(bool currentRoomZoomed) {
    int choice;
    std::string directory = "saveStates";
    if (!createDirectoryIfNeeded(directory)) {
        std::cerr << "Directory creation failed" << std::endl;
        choice = 1;
    }

    // saveFileName = directory + "/save_" + getCurrentTimeAsString() + ".txt";
    saveFileName = directory + "/save_" + getCurrentTimeAsString() + ".txt";
    std::ofstream outFile(saveFileName);
    if (!outFile.is_open()) {
        std::string promptForNoSave = "Game failed to save. Please select option:";
        renderBox(startXBoxSave, endXBoxSave, startYBoxSave, ((totalConsoleHeight * 2 / 6) + 1), promptForNoSave, TRUE, TRUE, TRUE, "");
        std::vector<std::string> yesOrNo = {"EXIT GAME WITHOUT SAVING", "RETURN TO GAME"};
        choice = renderOptionsBox(startXBoxSave, endXBoxSave, ((totalConsoleHeight * 2 / 6) + 1), endYBoxSave, yesOrNo);

        switch (choice) {
            case 0:
                return 1;
                break;
            case 1:
                return 2;
                break;
        }       
    }

    outFile << "roomNumber=" << roomNumber << std::endl;
    outFile << "currentWallIndex=" << currentWallIndex << std::endl;
    outFile << "currentRoomZoomed=" << (currentRoomZoomed ? 1 : 0) << std::endl;

    outFile.close();

    return 0;
}

void loadGame(const std::string& saveFileName) {
    std::ifstream inFile("saveStates/" + saveFileName);
    if (!inFile) {
        std::cerr << "Failed to open save file: " + saveFileName << std::endl;
        Sleep(1000);
        return;
    }

    std::string line;
    while (std::getline(inFile, line)) {
        size_t pos = line.find("=");
        if (pos == std::string::npos) {
            continue; // skips invalid lines
        }

        std::string key = line.substr(0, pos);
        std::string value = line.substr(pos + 1);
        clearWholeScreen();
        if (key == "roomNumber") {
            roomNumber = std::stoi(value);
            std::cout << roomNumber << std::endl;
            Sleep(1000);
        } else if (key == "currentWallIndex") {
            currentWallIndex = std::stoi(value);
            std::cout << roomNumber << std::endl;
            Sleep(1000);
        } else if (key == "currentRoomZoomed") {
            globalZoomed = std::stoi(value);
            std::cout << roomNumber << std::endl;
            Sleep(1000);
        }
    }

    inFile.close();
}

std::string convertTCHARToString(TCHAR* tcharArray) {
    #ifdef UNICODE
    char buffer [MAX_PATH];
    WideCharToMultiByte(CP_ACP, 0, tcharArray, -1, buffer, MAX_PATH, NULL, NULL);
    return std::string(buffer);
    #else
    return std::string(tcharArray);
    #endif
}

std::vector<std::string> getSaveFilesList() {
    std::vector<std::string> fileList;

    WIN32_FIND_DATA findFileData;
    HANDLE hFind = FindFirstFile(TEXT("saveStates\\*.txt"), &findFileData);

    if (hFind == INVALID_HANDLE_VALUE) {
        std::cerr << "Failed to open directory or no .txt files found." << std::endl;
        return fileList;
    }

    do {
        fileList.push_back(convertTCHARToString(findFileData.cFileName));
    } while (FindNextFile(hFind, &findFileData) != 0);

    FindClose(hFind);

    return fileList;
}