#NI C++ Coding Assignment
cmake_minimum_required(VERSION 3.9)
project(tilemap_editor CXX)
set(CMAKE_CXX_STANDARD 17)


# AudioEffect Lib
set(TILEMAP_EDITOR_SOURCE_LIB
       )
set(TILEMAP_EDITOR_LIB_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
add_library(tilemap_editor_lib ${TILEMAP_EDITOR_SOURCE_LIB})
target_include_directories(tilemap_editor_lib INTERFACE ${TILEMAP_EDITOR_LIB_INCLUDE_DIR})


# Prepare "Catch" library for other executables
#set(CATCH_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/extern)
#add_library(Catch INTERFACE)
#target_include_directories(Catch INTERFACE ${CATCH_INCLUDE_DIR})
# should be given by parent project

# unit test executable
set(TILEMAP_EDITOR_SOURCE_TEST
        )
add_executable(tilemap_editor_CatchTest ${TILEMAP_EDITOR_SOURCE_TEST})
target_link_libraries(tilemap_editor_CatchTest tilemap_editor_lib Catch)
add_test(TEST_tilemap_editor tilemap_editor_CatchTest)
enable_testing()

set(TILEMAP_EDITOR_SOURCE_MAIN
        )
add_executable(tilemap_editor ${TILEMAP_EDITOR_SOURCE_MAIN})
target_link_libraries(tilemap_editor tilemap_editor_lib Catch)
