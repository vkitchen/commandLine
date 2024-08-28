#include "oscarRoom.hpp"
#include "optionsBox.hpp"

/*!
 * @file
 * @brief oscarRoom.cpp
 */

bool solved = false;
std::string output;
std::string borderChar;
std::string answer;
std::string instruction;


void runOscar(){

    while (!solved) {
        

        if(input == 'q'){
            running = false;
            return;
        }
        if(zoomed == false){
            switch (currentWallIndex)
            {
            case 0:
                clearWholeScreen();
                loadArt(room1[currentWallIndex], art, artWidth, artHeight);
                renderCenteredArt(art, artWidth, artHeight);
                output = "Zoom in on the computer to see the name of the cipher you will be performing, there are two hidden values you must use to surmise the answer. You should type your answer into the screen (text box)";
                renderBox(0, totalConsoleWidth, fullScreenTextBoxHeight, totalConsoleHeight, output);
                if(room1VIEWED[currentWallIndex] == false) room1VIEWED[currentWallIndex] = true;
                break;
            case 1:
                clearWholeScreen();
                loadArt(room1[currentWallIndex], art, artWidth, artHeight);
                renderCenteredArt(art, artWidth, artHeight);
                output = "mod opperator?";            
                renderBox(0, totalConsoleWidth, fullScreenTextBoxHeight, totalConsoleHeight, output);
                if(room1VIEWED[currentWallIndex] == false) room1VIEWED[currentWallIndex] = true;
                break;
            case 2:
                clearWholeScreen();
                loadArt(room1[currentWallIndex], art, artWidth, artHeight);
                renderCenteredArt(art, artWidth, artHeight);
                output = "Take a closer look at the mountain, there could be something usefull on it";            
                renderBox(0, totalConsoleWidth, fullScreenTextBoxHeight, totalConsoleHeight, output);
                if(room1VIEWED[currentWallIndex] == false) room1VIEWED[currentWallIndex] = true;
                break;
            case 3:
                clearWholeScreen();
                loadArt(room1[currentWallIndex], art, artWidth, artHeight);
                renderCenteredArt(art, artWidth, artHeight);
                output = "Your cipher text is bjurb, combine the two hidden values to obtain the original shift of your text";            
                renderBox(0, totalConsoleWidth, fullScreenTextBoxHeight, totalConsoleHeight, output);
                if(room1VIEWED[currentWallIndex] == false) room1VIEWED[currentWallIndex] = true;
                break;
            default:
                break;
            }
        } else if (zoomed == true) {
            clearWholeScreen();
            loadArt(room1ZOOMED[currentWallIndex], art, artWidth, artHeight);
            renderCenteredArt(art, artWidth, artHeight);
            if(currentWallIndex == 2){
                output = "How lovely does Mt. Cargill look today :)";    
                renderBox(0, totalConsoleWidth, fullScreenTextBoxHeight, totalConsoleHeight, output);
                if(room1ZOOMEDVIEWED[2] == false) room1ZOOMEDVIEWED[2] = true;     
            }
            switch (currentWallIndex) 
            {
            case 0:
                instruction = "input your cipher answer:";
                renderBox(0, (totalConsoleWidth/5), (fullScreenTextBoxHeight - 5), fullScreenTextBoxHeight, instruction);
                answer = stringInputBox("");
                if (answer == "Owheo" || answer == "owheo") {
                    clearWholeScreen();
                    std::string output = "!!! YOU WIN !!!";            
                    renderBox(0, totalConsoleWidth, 0, totalConsoleHeight, output);
                } else if (input == 45) {
                    zoomed = false;
                    continue;
                }
                break;
            case 2:   
                if (input == 45) {
                    zoomed = false;
                    continue;
                }
                break;
            default:
                break;
            }
        }
        

        input = ' ';
        while(input == ' ') processInput();

        roomInputListenerOscar();
        // Clear the input
        

        Sleep(20); // Delay to control game speed
    }
    // GAME LOOP
} 