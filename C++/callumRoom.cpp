#include "callumRoom.hpp"
#include "optionsBox.hpp"
#include <string>
#include <vector>

namespace
{
    bool solvedCallum = false;
    bool callumZoomed = false;
    int currentBookPage = 0;
    const int totalBookPages = 5;
    std::string outputCallum, helperInstructionCallum;
    const std::string roomAnswer = "1234"; // Placeholder code

    void renderWall(int wallIndex, bool zoomed)
    {
        std::string filename;
        if (!zoomed)
        {
            filename = room4[wallIndex];
        }
        else
        {
            switch (wallIndex)
            {
            case 2: // i3
                filename = room4ZOOMED[0];
                break;
            case 4: // i5 (book)
                filename = room4ZOOMED[currentBookPage];
                break;
            case 5: // i6
                filename = room4ZOOMED[6];
                break;
            case 6: // i7
                filename = room4ZOOMED[7];
                break;
            default:
                filename = room4[wallIndex]; // Fallback to unzoomed if not zoomable
            }
        }
        loadArt(filename, art, artWidth, artHeight);
        renderCenteredArt(art, artWidth, artHeight);
        if (zoomed && !room4ZOOMEDVIEWED[wallIndex])
            room4ZOOMEDVIEWED[wallIndex] = true;
        if (!zoomed && !room4VIEWED[wallIndex])
            room4VIEWED[wallIndex] = true;
    }

    void renderBox(const std::string &output, bool zoomed, int wallIndex)
    {
        ::renderBox(0, totalConsoleWidth, fullScreenTextBoxHeight, totalConsoleHeight,
                    output, zoomed, room3VIEWED[wallIndex], room3ZOOMEDVIEWED[wallIndex],
                    zoomed ? "PRESS - TO ZOOM OUT" : "PRESS + TO ZOOM IN");
    }

    void handleUnzoomedWall(int wallIndex)
    {
        renderWall(wallIndex, false);
        switch (wallIndex)
        {
        case 0:
            outputCallum = "Wall 1 description";
            break;
        case 1:
            outputCallum = "Wall 2 description";
            break;
        case 2:
            outputCallum = "Wall 3 description (can be zoomed)";
            break;
        case 3:
            outputCallum = "Wall 4 description";
            break;
        case 4:
            outputCallum = "Wall 5 description (can be zoomed)";
            break;
        case 5:
            outputCallum = "Wall 6 description (can be zoomed)";
            break;
        case 6:
            outputCallum = "Wall 7 description (can be zoomed)";
            break;
        default:
            outputCallum = "Unknown wall";
            break;
        }
        renderBox(outputCallum, false, wallIndex);
    }

    void handleZoomedWall3()
    {
        outputCallum = "Zoomed view of Wall 3";
        renderBox(outputCallum, true, 2);
    }

    void handleZoomedWall5()
    {
        std::string bookContent[totalBookPages] = {
            "Page 1 content",
            "Page 2 content",
            "Page 3 content",
            "Page 4 content",
            "Page 5 content"};
        outputCallum = "Book page " + std::to_string(currentBookPage + 1) + " of " + std::to_string(totalBookPages) + ":\n\n" + bookContent[currentBookPage];
        renderBox(outputCallum, true, 4);
        helperInstructionCallum = "Use LEFT and RIGHT arrow keys to turn pages. PRESS - TO ZOOM OUT";
        ::renderBox(0, totalConsoleWidth, totalConsoleHeight - 3, totalConsoleHeight, helperInstructionCallum, true, room3VIEWED[4], room3ZOOMEDVIEWED[4], "");
    }

    void handleZoomedWall6()
    {
        outputCallum = "Zoomed view of Wall 6";
        renderBox(outputCallum, true, 5);
    }

    void handleZoomedWall7()
    {
        outputCallum = "Enter the code:";
        renderBox(outputCallum, true, 6);
        std::string userInput = stringInputBox("");
        if (userInput == roomAnswer)
        {
            solvedCallum = true;
            outputCallum = "Correct code! Room solved.";
        }
        else
        {
            outputCallum = "Incorrect code. Try again.";
        }
        renderBox(outputCallum, true, 6);
    }

    void handleZoomedWall(int wallIndex)
    {
        renderWall(wallIndex, true);
        switch (wallIndex)
        {
        case 2:
            handleZoomedWall3();
            break;
        case 4:
            handleZoomedWall5();
            break;
        case 5:
            handleZoomedWall6();
            break;
        case 6:
            handleZoomedWall7();
            break;
        default:
            outputCallum = "This wall cannot be zoomed";
            renderBox(outputCallum, true, wallIndex);
            break;
        }
    }

    void processCallumInput()
    {
        processInput();
        if (callumZoomed && currentWallIndex == 4)
        {
            if (input == 75 && currentBookPage > 0)
            { // Left arrow
                currentBookPage--;
            }
            else if (input == 77 && currentBookPage < totalBookPages - 1)
            { // Right arrow
                currentBookPage++;
            }
        }
    }
}

void runCallum()
{
    roomNumber = 4;
    callumZoomed = globalZoomed;
    currentWallIndex = 0;
    while (!solvedCallum)
    {
        if (input == 'q')
        {
            running = false;
            return;
        }

        if (!callumZoomed)
        {
            handleUnzoomedWall(currentWallIndex);
        }
        else
        {
            handleZoomedWall(currentWallIndex);
        }

        input = ' ';
        processCallumInput();

        if (input == '+' && !callumZoomed)
        {
            callumZoomed = true;
        }
        else if (input == '-' && callumZoomed)
        {
            callumZoomed = false;
        }
        else if (input == 77)
        { // Right arrow
            currentWallIndex = (currentWallIndex + 1) % 7;
        }
        else if (input == 75)
        { // Left arrow
            currentWallIndex = (currentWallIndex - 1 + 7) % 7;
        }

        if (!running)
            return;
        Sleep(20); // Delay to control game speed
    }
    // GAME LOOP
    // Go to next room after being solved
}