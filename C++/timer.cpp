#define _CRT_SECURE_NO_WARNINGS
#include "timer.hpp"

std::chrono::steady_clock::time_point timeAtStartTime; 

void startTimer() {
    timeAtStartTime = std::chrono::steady_clock::now();
}

int checkRemainingTime(std::chrono::steady_clock::time_point startTime, int totalSeconds) {
    std::chrono::steady_clock::time_point currentTime = std::chrono::steady_clock::now();

    size_t elapsedTime_data = std::chrono::duration_cast<std::chrono::seconds>(currentTime - startTime).count();
    int elapsedTime = static_cast<int>(elapsedTime_data);
    int remainingTime = totalSeconds - elapsedTime;

    if (remainingTime < 0) { 
        remainingTime = 0;
    }

    return remainingTime;
}

void printRemainingTime(int remainingTime, bool currentRoomZoomed) {
    std::string timeString;
    int minutes = remainingTime / 60;
    int seconds = remainingTime % 60;

    if (seconds < 10) {
        timeString = std::to_string(minutes) + ":0" + std::to_string(seconds);
    } else {
        timeString = std::to_string(minutes) + ":" + std::to_string(seconds);
    }

    renderBox((totalConsoleWidth/7)*6, totalConsoleWidth, (fullScreenTextBoxHeight - 5), fullScreenTextBoxHeight, timeString, currentRoomZoomed, room2VIEWED[currentWallIndex], room2ZOOMEDVIEWED[currentWallIndex], "");
}