cmake_minimum_required(VERSION 2.6)
 
set (CMAKE_CXX_STANDARD 14)
 
# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
 
# Move the executable generated in bin folder
set(EXECUTABLE_OUTPUT_PATH bin/${CMAKE_BUILD_TYPE})
 
# Add all the source files in the variable source_files
file (GLOB_RECURSE source_files src/*)
 
# Link runTests with what we want to test and the GTest and pthread library
add_executable(main ${source_files})
               
target_link_libraries(main ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES} pthread)
