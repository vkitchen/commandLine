cmake_minimum_required(VERSION 3.14)

# Set project name
project(commandLine)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add source files
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
    C++/test.cpp
    C++/test.hpp
    C++/textBox.cpp
    C++/textBox.hpp
)

# Add test files
add_executable(test_executable
    C++/test.cpp
    C++/test.hpp
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
