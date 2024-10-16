# Add source to this project's executable. 
# New files (.cpp & .hpp) created need to be added here
add_library (FileSystem 
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
# "saveOrLoadGame.cpp"
# "saveOrLoadGame.hpp"
"terminalHelpers.cpp"
"terminalHelpers.hpp"
"timer.cpp"
"timer.hpp"
"textBox.cpp"
"textBox.hpp"
"compat.cpp"
"compat.hpp"
)

add_executable (EscapeOwheo 
"main.cpp"
$<TARGET_OBJECTS:FileSystem>
)

add_executable (TestOwheo
"tests/test.cpp"
$<TARGET_OBJECTS:FileSystem>
)


set_property(TARGET EscapeOwheo PROPERTY CXX_STANDARD 20)
set_property(TARGET TestOwheo PROPERTY CXX_STANDARD 20)



add_test(NAME TestOwheo COMMAND TestOwheo)
# set_tests_properties(TestOwheo PROPERTIES WORKING_DIRECTORY ${CMAKE_BINARY_DIR})

# New .cpp files should be included here

target_include_directories(FileSystem PUBLIC ${CMAKE_CURRENT_LIST_DIR})

file(COPY ${CMAKE_SOURCE_DIR}/C++/art DESTINATION ${CMAKE_BINARY_DIR})

# Set the output directory for the executable to the root of the project
# set_target_properties(EscapeOwheo PROPERTIES
#     RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}"
#     RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_SOURCE_DIR}"
#     RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_SOURCE_DIR}"
#     RUNTIME_OUTPUT_DIRECTORY_MINSIZEREL "${CMAKE_SOURCE_DIR}"
#     RUNTIME_OUTPUT_DIRECTORY_RELWITHDEBINFO "${CMAKE_SOURCE_DIR}"
#     PDB_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/C++/Debug"
#     PDB_OUTPUT_DIRECTORY_DEBUG "${CMAKE_BINARY_DIR}/C++/Debug"
# )

# set_target_properties(TestOwheo PROPERTIES
#     RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}"
#     RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_SOURCE_DIR}"
#     RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_SOURCE_DIR}"
#     RUNTIME_OUTPUT_DIRECTORY_MINSIZEREL "${CMAKE_SOURCE_DIR}"
#     RUNTIME_OUTPUT_DIRECTORY_RELWITHDEBINFO "${CMAKE_SOURCE_DIR}"
#     PDB_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/C++/Debug"
#     PDB_OUTPUT_DIRECTORY_DEBUG "${CMAKE_BINARY_DIR}/C++/Debug"
# )

# TODO: Add tests and install targets if needed.
