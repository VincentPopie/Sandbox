cmake_minimum_required(VERSION 2.6)
 
set (CMAKE_CXX_STANDARD 11)
 
# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
 
 
set(EXECUTABLE_OUTPUT_PATH bin/${CMAKE_BUILD_TYPE})
 
# Link runTests with what we want to test and the GTest and pthread library
add_executable(main src/main.cpp src/Foo.hpp src/Widget.cpp)
               
target_link_libraries(main ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES} pthread)
