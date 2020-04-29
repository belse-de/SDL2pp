cmake_minimum_required(VERSION 3.8)
project(sdl2pp_widget CXX C)
########################################################################################################################
# lib widget
########################################################################################################################

include(FindPkgConfig)
pkg_search_module(SDL2 REQUIRED sdl2)
pkg_search_module(SDL2IMAGE REQUIRED sdl2_image)
pkg_search_module(SDL2TTF REQUIRED sdl2_ttf)
include_directories(
        ${SDL2_INCLUDE_DIRS}
        ${SDL2IMAGE_INCLUDE_DIRS}
        ${SDL2TTF_INCLUDE_DIRS})

set(SOURCES_LIB_WIDGET
        src/Rect.hpp
        src/Point.hpp
        src/PointRect.hpp
        src/Base.cpp
        src/Base.hpp
        src/Window.cpp
        src/Window.hpp
        src/Textbox.cpp
        src/Textbox.hpp
        src/Button.cpp
        src/Button.hpp
        src/Image.cpp
        src/Image.hpp)
set(SOURCES_TEST_WIDGET
        test/catchMain.cpp
        test/testWidget.cpp
        test/testWidget_PointRect.cpp
        test/testWidget_Base.cpp)
set(SOURCES_EXE_WIDGET
        main_libWidget.cpp)


add_library(widget ${SOURCES_LIB_WIDGET})

add_executable(main_widget ${SOURCES_EXE_WIDGET})
target_link_libraries(main_widget sdl2pp widget)

add_executable(TestWidget
        $<TARGET_OBJECTS:CatchMain>
        ${SOURCES_TEST_WIDGET})
target_include_directories(TestWidget PUBLIC ${CMAKE_SOURCE_DIR}/extern)
target_link_libraries(TestWidget sdl2pp widget)
add_test(CATCH_TestWidget TestWidget)
