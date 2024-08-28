# CMakeList.txt : CMake project for cmakeci, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (cmakeci 
"main.cpp"
"inputListener.cpp"
"inputListener.hpp"
"optionsBox.cpp"
"optionsBox.hpp"
"oscarRoom.cpp"
"oscarRoom.hpp"
"readArt.cpp"
"readArt.hpp"
"renderArt.cpp"
"renderArt.hpp"
"startScreen.cpp"
"startScreen.hpp"
"terminalHelpers.cpp"
"terminalHelpers.hpp"
"textBox.cpp"
"textBox.hpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET cmakeci PROPERTY CXX_STANDARD 20)
endif()

add_library(src STATIC 
inputListener.cpp
optionsBox.cpp
oscarRoom.cpp
readArt.cpp
renderArt.cpp
startScreen.cpp
terminalHelpers.cpp
textBox.cpp)
target_include_directories(src PUBLIC ${CMAKE_CURRENT_LIST_DIR})

# TODO: Add tests and install targets if needed.