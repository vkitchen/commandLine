#include "callumRoom.hpp"
#include "optionsBox.hpp"
#include "inputListener.hpp"
#include <sstream>

bool solvedCallum = false;
bool callumZoomed = false;
int currentBookIndex = 0;

std::string outputCallum, helperInstructionCallum;
std::string userAnswer = "";
std::string doorCode = "2314";

void renderCallumRoom()
{
    loadArt(room4[currentWallIndex], art, artWidth, artHeight);
    renderCenteredArt(art, artWidth, artHeight);
    if (room4VIEWED[currentWallIndex] == false)
        room4VIEWED[currentWallIndex] = true;
}

void renderCallumZoomed()
{
    if (currentWallIndex == 4)
    {
        loadArt(room4BookArray[currentBookIndex], art, artWidth, artHeight);
    }
    else
    {
        loadArt(room4ZOOMED[currentWallIndex], art, artWidth, artHeight);
    }
    renderCenteredArt(art, artWidth, artHeight);
    if (room4ZOOMEDVIEWED[currentWallIndex] == false)
        room4ZOOMEDVIEWED[currentWallIndex] = true;
}

bool canZoom(int wallIndex)
{
    return wallIndex == 2 || wallIndex == 4 || wallIndex == 5 || wallIndex == 6;
}

void runCallum()
{
    roomNumber = 4;
    globalZoomed = callumZoomed;

    while (!solvedCallum)
    {
        if (!callumZoomed)
        {
            helperInstructionCallum = canZoom(currentWallIndex) ? "PRESS + TO ZOOM IN" : "";
            renderCallumRoom();
            outputCallum = "Owheo's hallway! what secrets does it hold?";
            renderBox(0, totalConsoleWidth, fullScreenTextBoxHeight, totalConsoleHeight, outputCallum, callumZoomed, room4VIEWED[currentWallIndex], room4ZOOMEDVIEWED[currentWallIndex], helperInstructionCallum);
        }
        else
        {
            helperInstructionCallum = "PRESS - TO ZOOM OUT";
            renderCallumZoomed();

            switch (currentWallIndex)
            {
            case 2:
                outputCallum = "Huh, what a weird riddle. Maybe this helps with something else.";
                break;
            case 4:
                outputCallum = "Whats in this book? (Use the arrow keys to look through the pages)";
                break;
            case 5:
                outputCallum = "Some weird symbols on the wall. What do they mean?";
                break;
            case 6:
                outputCallum = "Enter the 4 digit code:";
                if (input != 45) // Only process input if not zooming out
                {
                    renderBox(0, (totalConsoleWidth / 5), (fullScreenTextBoxHeight - 5), fullScreenTextBoxHeight, outputCallum, callumZoomed, room1VIEWED[currentWallIndex], room1ZOOMEDVIEWED[currentWallIndex], "");
                    userAnswer = stringInputBox("");
                    if (userAnswer == doorCode)
                    {
                        solvedCallum = true;
                        callumZoomed = false;
                        currentWallIndex = 0;
                        clearWholeScreen();
                        break;
                    }
                    else
                    {
                        clearWholeScreen();
                        continue;
                    }
                }
                break;
            }

            if(!solvedCallum){
                renderBox(0, totalConsoleWidth, fullScreenTextBoxHeight, totalConsoleHeight, outputCallum, callumZoomed, room4VIEWED[currentWallIndex], room4ZOOMEDVIEWED[currentWallIndex], helperInstructionCallum);
            }
        }

        input = ' ';
        while (input == ' ' && !solvedCallum)
            processInput();

        roomInputListenerCallum(&callumZoomed, &currentWallIndex, &currentBookIndex, &userAnswer);

        if (!running)
            return;
        Sleep(20);

    }

    // Next room logic here
    runOscar();
    
}