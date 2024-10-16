#include "oscarRoom.hpp"
#include "optionsBox.hpp"

/*!
 * @file
 * @brief oscarRoom.cpp
 */

bool oscarSolved = false;
bool oscarZoomed = false;
std::string output;
std::string helperInstructionOscar;
std::string answer;
std::string instruction;


void runOscar(){
    roomNumber = 2;
    oscarZoomed = globalZoomed;
    while (!oscarSolved) {
        if (!running) return;
        if(oscarZoomed == false){
            helperInstructionOscar = "PRESS + TO ZOOM IN";
            switch (currentWallIndex)
            {
            case 0:
                loadArt(room1[currentWallIndex], art, artWidth, artHeight);
                renderCenteredArt(art, artWidth, artHeight);
                output = "Welcome to room 2! Zoom in on the computer to see the name of the cipher you will be performing, Within the room are two numbers you must combine to complete the cipher, and the actual cipher text you must decode, Good Luck!";
                renderBox(0, totalConsoleWidth, fullScreenTextBoxHeight, totalConsoleHeight, output, oscarZoomed, room1VIEWED[currentWallIndex], room1ZOOMEDVIEWED[currentWallIndex], helperInstructionOscar);
                if(room1VIEWED[currentWallIndex] == false) room1VIEWED[currentWallIndex] = true;
                break;
            case 1:
                loadArt(room1[currentWallIndex], art, artWidth, artHeight);
                renderCenteredArt(art, artWidth, artHeight);
                output = "Your first value is found by solving the equation on the board (modulus opperation).";            
                renderBox(0, totalConsoleWidth, fullScreenTextBoxHeight, totalConsoleHeight, output, oscarZoomed, room1VIEWED[currentWallIndex], room1ZOOMEDVIEWED[currentWallIndex], "");
                if(room1VIEWED[currentWallIndex] == false) room1VIEWED[currentWallIndex] = true;
                break;
            case 2:
                loadArt(room1[currentWallIndex], art, artWidth, artHeight);
                renderCenteredArt(art, artWidth, artHeight);
                output = "Take a closer look at the mountain, there could be something usefull on it.";            
                renderBox(0, totalConsoleWidth, fullScreenTextBoxHeight, totalConsoleHeight, output, oscarZoomed, room1VIEWED[currentWallIndex], room1ZOOMEDVIEWED[currentWallIndex], helperInstructionOscar);
                if(room1VIEWED[currentWallIndex] == false) room1VIEWED[currentWallIndex] = true;
                break;
            case 3:
                loadArt(room1[currentWallIndex], art, artWidth, artHeight);
                renderCenteredArt(art, artWidth, artHeight);
                output = "Your cipher text is 'bjurb', add the two hidden values together and shift each letter backwards by that value to decode the cipher.";            
                renderBox(0, totalConsoleWidth, fullScreenTextBoxHeight, totalConsoleHeight, output, oscarZoomed, room1VIEWED[currentWallIndex], room1ZOOMEDVIEWED[currentWallIndex], "");
                if(room1VIEWED[currentWallIndex] == false) room1VIEWED[currentWallIndex] = true;
                break;
            default:
                break;
            }
        } else if (oscarZoomed == true) {
            helperInstructionOscar = "PRESS - TO ZOOM OUT";
            switch (currentWallIndex) 
            {
            case 0:
                loadArt(room1ZOOMED[currentWallIndex], art, artWidth, artHeight);
                renderCenteredArt(art, artWidth, artHeight);
                instruction = "Input your cipher answer:";
                renderBox(0, (totalConsoleWidth/5), (fullScreenTextBoxHeight - 5), fullScreenTextBoxHeight, instruction, oscarZoomed, room1VIEWED[currentWallIndex], room1ZOOMEDVIEWED[currentWallIndex], "");
                answer = stringInputBox("");
                if (answer == "Owheo" || answer == "owheo") {
                    clearWholeScreen();
                    oscarZoomed = false;
                    currentWallIndex = 0;
                    oscarSolved = true;
                    break;
                } else if (input == 45) {
                    oscarZoomed = false;
                    clearWholeScreen();
                    continue;
                } else {
                    // This extra else statement makes it so any wrong input will reset the screen
                    // Could be better but works for now
                    continue;
                }
                break;
            case 2:   
                loadArt(room1ZOOMED[currentWallIndex], art, artWidth, artHeight);
                renderCenteredArt(art, artWidth, artHeight);
                output = "How lovely does Mt. Cargill look today :)";    
                renderBox(0, totalConsoleWidth, fullScreenTextBoxHeight, totalConsoleHeight, output, oscarZoomed, room1VIEWED[currentWallIndex], room1ZOOMEDVIEWED[currentWallIndex], helperInstructionOscar);
                if(room1ZOOMEDVIEWED[2] == false) room1ZOOMEDVIEWED[2] = true;   
                if (input == 45) {
                    oscarZoomed = false;
                    clearWholeScreen();
                    continue;
                }
                break;
            default:
                break;
            }
        }
        

        input = ' ';
        while(input == ' ' && !oscarSolved) processInput();

        roomInputListenerOscar(&oscarZoomed);
        // Clear the input
        
        if (running == false) {
            return;
        }
        msleep(20); // Delay to control game speed
    }
    // GAME LOOP
    if (!running) return;
    runLachlan(); // goes to next room after being solved
    return;
}
