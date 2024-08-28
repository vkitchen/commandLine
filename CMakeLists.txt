cmake_minimum_required(VERSION 3.14)

# Set project name
project(commandLine)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Specify source files
add_executable(main_executable
    C++/inputListener.cpp
    C++/inputListener.hpp
    C++/main.cpp
    C++/optionsBox.cpp
    C++/optionsBox.hpp
    C++/oscarRoom.cpp
    C++/oscarRoom.hpp
    C++/readArt.cpp
    C++/readArt.hpp
    C++/renderArt.cpp
    C++/renderArt.hpp
    C++/startScreen.cpp
    C++/startScreen.hpp
    C++/terminalHelpers.cpp
    C++/terminalHelpers.hpp
    # C++/test.cpp
    # C++/test.hpp
    C++/textBox.cpp
    C++/textBox.hpp
)

# Add test executable
add_executable(test_executable
    C++/test.cpp
    C++/test.hpp
)

# Add tests
enable_testing()
set(CTEST_OUTPUT_ON_FAILURE TRUE)

add_test(NAME TestRun COMMAND test_executable WORKING_DIRECTORY C++)
