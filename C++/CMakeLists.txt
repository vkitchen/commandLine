# CMakeList.txt : CMake project for cmake, include source and define
# project specific logic here.
#
# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()



project (commandLine)

include(CTest)



# Add source to this project's executable. 
# New files (.cpp & .hpp) created need to be added here
add_executable (EscapeOwheo 
"main.cpp"
"inputListener.cpp"
"inputListener.hpp"
"optionsBox.cpp"
"optionsBox.hpp"
"introRoom.cpp"
"introRoom.hpp"
"pauseMenu.cpp"
"pauseMenu.hpp"
"oscarRoom.cpp"
"oscarRoom.hpp"
"callumRoom.cpp"
"callumRoom.hpp"
"anthonyRoom.cpp"
"anthonyRoom.hpp"
"lachlanRoom.cpp"
"lachlanRoom.hpp"
"readArt.cpp"
"readArt.hpp"
"renderArt.cpp"
"renderArt.hpp"
"startScreen.cpp"
"startScreen.hpp"
"saveOrLoadGame.cpp"
"saveOrLoadGame.hpp"
"terminalHelpers.cpp"
"terminalHelpers.hpp"
"timer.cpp"
"timer.hpp"
"textBox.cpp"
"textBox.hpp"
)

add_executable (TestOwheo 
"tests/test.cpp"
"inputListener.cpp"
"inputListener.hpp"
"optionsBox.cpp"
"optionsBox.hpp"
"introRoom.cpp"
"introRoom.hpp"
"pauseMenu.cpp"
"pauseMenu.hpp"
"oscarRoom.cpp"
"oscarRoom.hpp"
"callumRoom.cpp"
"callumRoom.hpp"
"anthonyRoom.cpp"
"anthonyRoom.hpp"
"lachlanRoom.cpp"
"lachlanRoom.hpp"
"readArt.cpp"
"readArt.hpp"
"renderArt.cpp"
"renderArt.hpp"
"startScreen.cpp"
"startScreen.hpp"
"saveOrLoadGame.cpp"
"saveOrLoadGame.hpp"
"terminalHelpers.cpp"
"terminalHelpers.hpp"
"timer.cpp"
"timer.hpp"
"textBox.cpp"
"textBox.hpp"
)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET EscapeOwheo PROPERTY CXX_STANDARD 20)
endif()


# New .cpp files should be included here
add_library(src STATIC 
inputListener.cpp
optionsBox.cpp
introRoom.cpp
oscarRoom.cpp
anthonyRoom.cpp
lachlanRoom.cpp
callumRoom.cpp
readArt.cpp
renderArt.cpp
startScreen.cpp
saveOrLoadGame.cpp
timer.cpp
tests/test.cpp
pauseMenu.cpp
terminalHelpers.cpp
textBox.cpp)
target_include_directories(src PUBLIC ${CMAKE_CURRENT_LIST_DIR})

file(COPY ${CMAKE_SOURCE_DIR}/art DESTINATION ${CMAKE_BINARY_DIR})
# configure_file(${CMAKE_CURRENT_SOURCE_DIR}/art ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)

# TODO: Add tests and install targets if needed.