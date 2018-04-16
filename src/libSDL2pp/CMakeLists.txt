cmake_minimum_required(VERSION 3.8)
project(sdl2pp CXX C)
########################################################################################################################
# lib sdl2pp
########################################################################################################################


# https://cmake.org/cmake/help/v3.0/module/FindOpenGL.html
find_package(OpenGL REQUIRED)
# https://cmake.org/cmake/help/v3.0/module/FindGLEW.html
find_package(GLEW REQUIRED)

include(FindPkgConfig)
pkg_search_module(SDL2 REQUIRED sdl2)
pkg_search_module(SDL2IMAGE REQUIRED sdl2_image)
pkg_search_module(SDL2TTF REQUIRED sdl2_ttf)
pkg_search_module(SDL2MIXER REQUIRED sdl2_mixer)
pkg_search_module(SDL2NET REQUIRED SDL2_net)


set(SOURCES_LIB_SDL2PP
        ../stdLib_helper.cpp
        ../stdLib_helper.hpp
        src/Error.hpp
        src/Img/Error.hpp
        src/TTF/Error.hpp
        src/Mix/Error.hpp
        src/Net/Error.hpp
        src/SDL2.cpp
        src/SDL2.hpp
        src/Window.cpp
        src/Window.hpp
        src/Surface.cpp
        src/Surface.hpp
        src/Img/ImageSurface.cpp
        src/Img/ImageSurface.hpp
        src/Img/SDL2Image.cpp
        src/Img/SDL2Image.hpp
        src/Renderer.cpp
        src/Renderer.hpp
        src/Texture.cpp
        src/Texture.hpp
        src/TTF/SDL2TTF.cpp
        src/TTF/SDL2TTF.hpp
        src/TTF/Font.cpp
        src/TTF/Font.hpp
        src/Mix/SDL2Mixer.cpp
        src/Mix/SDL2Mixer.hpp
        src/Net/SDL2Net.cpp
        src/Net/SDL2Net.hpp
        src/Img/ImageTexture.cpp
        src/Img/ImageTexture.hpp
        )
set(SOURCES_TEST_SDL2PP
        test/catchMain.cpp
        test/TestEngine.cpp)
set(SOURCES_EXE_SDL2PP
        main_libSDL2pp.cpp)

add_library(sdl2pp ${SOURCES_LIB_SDL2PP})
include_directories(
        ${SDL2_INCLUDE_DIRS}
        ${SDL2IMAGE_INCLUDE_DIRS}
        ${SDL2TTF_INCLUDE_DIRS}
        ${SDL2MIXER_INCLUDE_DIRS}
        ${SDL2NET_INCLUDE_DIRS}
        ${OPENGL_INCLUDE_DIR}
        ${GLEW_INCLUDE_DIRS})
target_link_libraries(sdl2pp
        ${SDL2_LIBRARIES}
        ${SDL2IMAGE_LIBRARIES}
        ${SDL2TTF_LIBRARIES}
        ${SDL2MIXER_LIBRARIES}
        ${SDL2NET_LIBRARIES}
        ${OPENGL_LIBRARIES}
        ${GLEW_LIBRARIES})
target_link_libraries(sdl2pp RTTR::Core_Lib)     # rttr as static library

add_executable(main_sdl2pp ${SOURCES_EXE_SDL2PP})
target_link_libraries(main_sdl2pp sdl2pp)

add_executable(TestSdl2pp
        $<TARGET_OBJECTS:CatchMain>
        ${SOURCES_TEST_SDL2PP})

#target_include_directories(Test PUBLIC ${CMAKE_SOURCE_DIR}/extern)
add_test(CATCH_TestSdl2pp TestSdl2pp)
