cmake_minimum_required(VERSION 3.14)

# Set project name
project(commandLine)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add executable
add_executable(test_executable
    inputListener.cpp
    inputListener.hpp
    main.cpp
    optionsBox.cpp
    optionsBox.hpp
    oscarRoom.cpp
    oscarRoom.hpp
    readArt.cpp
    readArt.hpp
    renderArt.cpp
    renderArt.hpp
    startScreen.cpp
    startScreen.hpp
    terminalHelpers.cpp
    terminalHelpers.hpp
    test.cpp
    test.hpp
    textBox.cpp
    textBox.hpp
)

# Add coverage flags if we're on GCC/Clang
if (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fprofile-arcs -ftest-coverage")
endif()

# Add tests
enable_testing()
set(CTEST_OUTPUT_ON_FAILURE TRUE)

add_test(NAME TestRun COMMAND test_executable)
