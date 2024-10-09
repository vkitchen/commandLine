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

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET TestOwheo PROPERTY CXX_STANDARD 20)
endif()


add_test(NAME TestOwheo COMMAND TestOwheo)
# set_tests_properties(TestOwheo PROPERTIES WORKING_DIRECTORY ${CMAKE_BINARY_DIR})

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

file(COPY ${CMAKE_SOURCE_DIR}/C++/art DESTINATION ${CMAKE_BINARY_DIR})

# TODO: Add tests and install targets if needed.