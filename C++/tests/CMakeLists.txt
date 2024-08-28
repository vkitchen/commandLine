# CMakeList.txt : CMake project for cmakeci, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (test_executable "test.cpp")
# target_link_libraries(test src unity)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET test_executable PROPERTY CXX_STANDARD 20)
endif()

add_test(test_executable test_executable)

# TODO: Add tests and install targets if needed.