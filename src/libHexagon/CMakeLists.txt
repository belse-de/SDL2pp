cmake_minimum_required(VERSION 3.8)
project(sdl2pp_hexagon CXX C)

########################################################################################################################
# lib hexagon
########################################################################################################################
set(SOURCES_LIB_HEXAGON
        src/libhex.cpp
        src/libhex.hpp)
set(SOURCES_TEST_HEXAGON
        test/catchMain.cpp
        test/testHexagon.cpp
        )
set(SOURCES_EXE_HEXAGON
        main_libHexagon.cpp)

add_library(hexagon ${SOURCES_LIB_HEXAGON})

add_executable(main_hexagon ${SOURCES_EXE_HEXAGON})
target_link_libraries(main_hexagon hexagon)

add_executable(TestHexagon
        $<TARGET_OBJECTS:CatchMain>
        ${SOURCES_TEST_HEXAGON}
        )
target_link_libraries(TestHexagon hexagon)
add_test(CATCH_TestHexagon TestHexagon)
