#include "anthonyRoom.hpp"
#include "optionsBox.hpp"

/*!
 * @file
 * @brief anthonyRoom.cpp
 */

bool solvedAnthony = false;
bool anthonyZoomed = false;
std::string outputAnthony;
std::string borderCharAnthony;
std::string lowerCaseStrAnt;
std::string answerAnthony;
std::string instructionAnthony;
std::string helperInstructionAnthony;

// test

void runAnthony(){
    roomNumber = 1;
    helperInstructionAnthony = "PRESS + TO ZOOM IN";
    anthonyZoomed = globalZoomed;
    while (!solvedAnthony) {
        if (!running) return;
        if(anthonyZoomed == false) {
            switch (currentWallIndex)
            {
            case 0:
                loadArt(room3[currentWallIndex], art, artWidth, artHeight);
                renderCenteredArt(art, artWidth, artHeight);
                outputAnthony = "Welcome to room 1, you will be attempting to find a single mystery word, each wall hides a clue to what that word is, when you think youve solved the puzzle zoom in on this door and enter your answer.";
                renderBox(0, totalConsoleWidth, fullScreenTextBoxHeight, totalConsoleHeight, outputAnthony, anthonyZoomed, room3VIEWED[currentWallIndex], room3ZOOMEDVIEWED[currentWallIndex], helperInstructionAnthony);
                if(room3VIEWED[currentWallIndex] == false) room3VIEWED[currentWallIndex] = true;
                break;
            case 1:
                loadArt(room3[currentWallIndex], art, artWidth, artHeight);
                renderCenteredArt(art, artWidth, artHeight);
                outputAnthony = "Is someone doing calculations on this whiteboard?";
                renderBox(0, totalConsoleWidth, fullScreenTextBoxHeight, totalConsoleHeight, outputAnthony, anthonyZoomed, room3VIEWED[currentWallIndex], room3ZOOMEDVIEWED[currentWallIndex], helperInstructionAnthony);
                if(room3VIEWED[currentWallIndex] == false) room3VIEWED[currentWallIndex] = true;
                break;
            case 2:
                loadArt(room3[currentWallIndex], art, artWidth, artHeight);
                renderCenteredArt(art, artWidth, artHeight);
                outputAnthony = "A world full of regions and ______'s ...";            
                renderBox(0, totalConsoleWidth, fullScreenTextBoxHeight, totalConsoleHeight, outputAnthony, anthonyZoomed, room3VIEWED[currentWallIndex], room3ZOOMEDVIEWED[currentWallIndex], "");
                if(room3VIEWED[currentWallIndex] == false) room3VIEWED[currentWallIndex] = true;
                break;
            case 3:
                loadArt(room3[currentWallIndex], art, artWidth, artHeight);
                renderCenteredArt(art, artWidth, artHeight);
                outputAnthony = "What a cool poster what's it showing? ";
                renderBox(0, totalConsoleWidth, fullScreenTextBoxHeight, totalConsoleHeight, outputAnthony, anthonyZoomed, room3VIEWED[currentWallIndex], room3ZOOMEDVIEWED[currentWallIndex], helperInstructionAnthony);
                if(room3VIEWED[currentWallIndex] == false) room3VIEWED[currentWallIndex] = true;
                break;
            default:
                break;
            }
        } else if (anthonyZoomed == true) {
            helperInstructionAnthony = "PRESS - TO ZOOM OUT";
            switch (currentWallIndex)
            {
            case 0:
                loadArt(room3ZOOMED[currentWallIndex], art, artWidth, artHeight);
                renderCenteredArt(art, artWidth, artHeight);
                instructionAnthony = "Input your answer:";
                renderBox(0, (totalConsoleWidth/5), (fullScreenTextBoxHeight - 5), fullScreenTextBoxHeight, instructionAnthony, anthonyZoomed, room3VIEWED[currentWallIndex], room3ZOOMEDVIEWED[currentWallIndex], "");
                answerAnthony = stringInputBox("");
                for (char c : answerAnthony) {
                    lowerCaseStrAnt += static_cast<char>(std::tolower(static_cast<unsigned char>(c))); // Convert each character to lowercase
                }

                if (lowerCaseStrAnt == "area") {
                    anthonyZoomed = false;
                    clearWholeScreen();
                    solvedAnthony = true;
                    currentWallIndex = 0;
                    break;
                } else if (input == 45) {
                    anthonyZoomed = false;
                    clearWholeScreen();
                    continue;
                } else {
                    // This extra else statement makes it so any wrong input will reset the screen
                    // Could be better but works for now
                   // clearWholeScreen();
                    continue;
                }
                break;
            case 1:   
                loadArt(room3ZOOMED[currentWallIndex], art, artWidth, artHeight);
                renderCenteredArt(art, artWidth, artHeight);
                outputAnthony = "Huh, someone's using the base X height formula. I wonder, what do you get when you multiply the base and the height of that shape???";    
                renderBox(0, totalConsoleWidth, fullScreenTextBoxHeight, totalConsoleHeight, outputAnthony, anthonyZoomed, room3VIEWED[currentWallIndex], room3ZOOMEDVIEWED[currentWallIndex], "");
                if(room3ZOOMEDVIEWED[1] == false) room3ZOOMEDVIEWED[1] = true;   
                if (input == 45) {
                    anthonyZoomed = false;
                    clearWholeScreen();
                    continue;
                }
                break;
            case 3:   
                loadArt(room3ZOOMED[currentWallIndex], art, artWidth, artHeight);
                renderCenteredArt(art, artWidth, artHeight);
                outputAnthony = "Looks like a UFO lighting up the number 51, I swear this place hides aliens there... ";    
                renderBox(0, totalConsoleWidth, fullScreenTextBoxHeight, totalConsoleHeight, outputAnthony, anthonyZoomed, room3VIEWED[currentWallIndex], room3ZOOMEDVIEWED[currentWallIndex], "");
                if(room3ZOOMEDVIEWED[3] == false) room3ZOOMEDVIEWED[3] = true;   
                if (input == 45) {
                    anthonyZoomed = false;
                    clearWholeScreen();
                    continue;
                }
                break;
            default:
                break;
            }
        }

        input = ' ';
        while(input == ' ' && !solvedAnthony) processInput();

        roomInputListenerAnthony(&anthonyZoomed);

        Sleep(20); // Delay to control game speed
    }
    // GAME LOOP
    if (!running) return;
    runOscar(); // goes to next room after being solved
    return;
} 