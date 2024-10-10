# Command Line

![Github Workflow Badge](https://github.com/oscar-crowe22/commandLine/actions/workflows/cmake.yml/badge.svg?event=push) [![codecov](https://codecov.io/gh/COSC345-CommandLine/commandLine/branch/main/graph/badge.svg?token=E3C333999Y)](https://codecov.io/gh/COSC345-CommandLine/commandLine) [![Codacy Badge](https://app.codacy.com/project/badge/Grade/7b3743b9fdc34a4280852c8614a1a1b1)](https://app.codacy.com/gh/COSC345-CommandLine/commandLine/dashboard?utm_source=gh&utm_medium=referral&utm_content=&utm_campaign=Badge_grade)

## Members:
- Lachlan Graham
- Oscar Crowe
- Callum Sullivan
- Anthony Deng

## Build steps (Windows)
1. mkdir build
2. cmake -B build
3. cmake --build build
4. .\build\C++\Debug\EscapeOwheo.exe

## About
Escape Owheo is a puzzle room game based in the Otago University Computer Science building. Your goal as the user is to escape the building by moving from room to room solving puzzles as you go. All the game art is based on rooms in the Owheo Building so hopefully if you've been their before it feels very familiar.

## Controls
- The + and - keys are used to zoom in and out of certain walls to reveal clues, or to input answers to puzzles.
- The left and right arrow keys are used to look around the walls of the room from side to side.
- ESC can be pressed to open a menu including a save function and a controls tab for a refresher if needed.

## Features
- The game implements a save function. At any point in the game if want to save your progress you can exit and a persitent save file will be generated. You can then load back into the game and pick up where you left off.
- The graphics are made using UTF8 encoding. This allows the game to be extremley visually pleasing even though it runs in the command line only.
- The game features 5 rooms. An intro room which serves as a tutorial, and then 4 main puzzle rooms each dedicated to a member of our team. They are desgined to get progresivley harder as you go. 