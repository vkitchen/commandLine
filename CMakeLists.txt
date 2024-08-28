cmake_minimum_required(VERSION 3.14)

# Set project name
project(commandLine)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Specify source files
add_executable(EscapeOwheo
    C++/main.cpp
    C++/inputListener.cpp
    C++/optionsBox.cpp
    C++/oscarRoom.cpp
    C++/readArt.cpp
    C++/renderArt.cpp
    C++/startScreen.cpp
    C++/terminalHelpers.cpp
    C++/textBox.cpp
)

add_executable(Tests 
    C++/test.cpp
)
