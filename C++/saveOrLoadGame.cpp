#include "saveOrLoadGame.hpp"

void saveGame(bool currentRoomZoomed) {
    std::time_t now = std::time(nullptr);
    saveFileName = "saveStates/save_" + std::to_string(now) + ".txt";

    std::ofstream outFile(saveFileName);
    if (!outFile) {
        std::cerr << "Failed to create save file." << std::endl;
        return;
    }

    outFile << "roomNumber=" << roomNumber << std::endl;
    outFile << "currentWallIndex=" << currentWallIndex << std::endl;
    outFile << "currentRoomZoomed=" << currentRoomZoomed << std::endl;

    outFile.close();
}

void loadGame(const std::string& saveFileName) {
    std::ifstream inFile("saveStates/" + saveFileName);
    if (!inFile) {
        std::cerr << "Failed to open save file: " + saveFileName << std::endl;
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

        if (key == "roomNumber") {
            roomNumber = std::stoi(value);
        } else if (key == "currentWallIndex") {
            currentWallIndex = std::stoi(value);
        } else if (key == "currentRoomZoomed") {
            globalZoomed = std::stoi(value);
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