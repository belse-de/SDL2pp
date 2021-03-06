cmake_minimum_required(VERSION 3.8)
project(sdl2pp CXX C)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 11)
set(CMAKE_VERBOSE_MAKEFILE OFF)

enable_testing()

include_directories(src/ include/ extern/)

set(UPDATE_DISCONNECTED_IF_AVAILABLE "UPDATE_DISCONNECTED 1")
#include(extern/DownloadProject/DownloadProject.cmake)
#download_project(
#        PROJ rttr
#        GIT_REPOSITORY  https://github.com/rttrorg/rttr
#        GIT_TAG master
#        ${UPDATE_DISCONNECTED_IF_AVAILABLE}
#        )
# we do not install or package RTTR
#set(BUILD_RTTR_DYNAMIC ON)
#set(BUILD_STATIC ON)
#set(BUILD_INSTALLER OFF)
#set(BUILD_PACKAGE OFF)
#add_subdirectory(${rttr_SOURCE_DIR} ${rttr_BINARY_DIR})
#include_directories("${rttr_SOURCE_DIR}/src" "${rttr_BINARY_DIR}/src")

#download_project(
#        PROJ boost_magic_get
#        GIT_REPOSITORY  https://github.com/apolukhin/magic_get.git
#        GIT_TAG master
#        ${UPDATE_DISCONNECTED_IF_AVAILABLE}
#)
#include_directories("${boost_magic_get_SOURCE_DIR}/include")

########################################################################################################################
# lib CATCH
########################################################################################################################
# define program targets:
add_library(CatchMain OBJECT extern/catch.hpp)
target_include_directories(CatchMain PUBLIC ${CMAKE_SOURCE_DIR}/extern)

# CATCH Examples
########################################################################################################################
# multiple-file modules:
set(SOURCES_TEST_CATCH_020
        test/example/020-TestCase-1.cpp
        test/example/020-TestCase-2.cpp
        )
# sources to combine with 000-CatchMain.cpp:
set(SOURCES_TEST_CATCH_IDIOMATIC
        test/example/100-Fix-Section.cpp
        test/example/110-Fix-ClassFixture.cpp
        test/example/120-Bdd-ScenarioGivenWhenThen.cpp
        )
#TODO set to ignored
#test/example/030-Asn-Require-Check.cpp


########################################################################################################################
# lib sdl2pp
########################################################################################################################
add_subdirectory(src/libSDL2pp)

########################################################################################################################
# lib scheduling
########################################################################################################################
add_subdirectory(src/libScheduling)

########################################################################################################################
# lib hexagon
########################################################################################################################
add_subdirectory(src/libHexagon)

########################################################################################################################
# lib widget
########################################################################################################################
add_subdirectory(src/libWidget)

########################################################################################################################
# examples
########################################################################################################################
add_subdirectory(src/examples)

########################################################################################################################
# Executeables and test
########################################################################################################################

# LazyFoo Tutorial
########################################################################################################################
add_executable(LFTut2_19 LazyFooSDL2Tutorial/19_gamepads_and_joysticks/19_gamepads_and_joysticks.cpp)
target_link_libraries(LFTut2_19 sdl2pp)

add_executable(LFTut2_20 LazyFooSDL2Tutorial/20_force_feedback/20_force_feedback.cpp)
target_link_libraries(LFTut2_20 sdl2pp)
add_executable(LFTut2_21 LazyFooSDL2Tutorial/21_sound_effects_and_music/21_sound_effects_and_music.cpp)
target_link_libraries(LFTut2_21 sdl2pp)
add_executable(LFTut2_22 LazyFooSDL2Tutorial/22_timing/22_timing.cpp)
target_link_libraries(LFTut2_22 sdl2pp)
add_executable(LFTut2_23 LazyFooSDL2Tutorial/23_advanced_timers/23_advanced_timers.cpp)
target_link_libraries(LFTut2_23 sdl2pp)
add_executable(LFTut2_24 LazyFooSDL2Tutorial/24_calculating_frame_rate/24_calculating_frame_rate.cpp)
target_link_libraries(LFTut2_24 sdl2pp)
add_executable(LFTut2_25 LazyFooSDL2Tutorial/25_capping_frame_rate/25_capping_frame_rate.cpp)
target_link_libraries(LFTut2_25 sdl2pp)
add_executable(LFTut2_26 LazyFooSDL2Tutorial/26_motion/26_motion.cpp)
target_link_libraries(LFTut2_26 sdl2pp)
add_executable(LFTut2_27 LazyFooSDL2Tutorial/27_collision_detection/27_collision_detection.cpp)
target_link_libraries(LFTut2_27 sdl2pp)
add_executable(LFTut2_28 LazyFooSDL2Tutorial/28_per-pixel_collision_detection/28_per-pixel_collision_detection.cpp)
target_link_libraries(LFTut2_28 sdl2pp)
add_executable(LFTut2_29 LazyFooSDL2Tutorial/29_circular_collision_detection/29_circular_collision_detection.cpp)
target_link_libraries(LFTut2_29 sdl2pp)

add_executable(LFTut2_30 LazyFooSDL2Tutorial/30_scrolling/30_scrolling.cpp)
target_link_libraries(LFTut2_30 sdl2pp)
add_executable(LFTut2_31 LazyFooSDL2Tutorial/31_scrolling_backgrounds/31_scrolling_backgrounds.cpp)
target_link_libraries(LFTut2_31 sdl2pp)
add_executable(LFTut2_32 LazyFooSDL2Tutorial/32_text_input_and_clipboard_handling/32_text_input_and_clipboard_handling.cpp)
target_link_libraries(LFTut2_32 sdl2pp)
add_executable(LFTut2_33 LazyFooSDL2Tutorial/33_file_reading_and_writing/33_file_reading_and_writing.cpp)
target_link_libraries(LFTut2_33 sdl2pp)
#
#
add_executable(LFTut2_35 LazyFooSDL2Tutorial/35_window_events/35_window_events.cpp)
target_link_libraries(LFTut2_35 sdl2pp)
add_executable(LFTut2_36 LazyFooSDL2Tutorial/36_multiple_windows/36_multiple_windows.cpp)
target_link_libraries(LFTut2_36 sdl2pp)
add_executable(LFTut2_37 LazyFooSDL2Tutorial/37_multiple_displays/37_multiple_displays.cpp)
target_link_libraries(LFTut2_37 sdl2pp)
add_executable(LFTut2_38 LazyFooSDL2Tutorial/38_particle_engines/38_particle_engines.cpp)
target_link_libraries(LFTut2_38 sdl2pp)
add_executable(LFTut2_39 LazyFooSDL2Tutorial/39_tiling/39_tiling.cpp)
target_link_libraries(LFTut2_39 sdl2pp)

add_executable(LFTut2_40 LazyFooSDL2Tutorial/40_texture_manipulation/40_texture_manipulation.cpp)
target_link_libraries(LFTut2_40 sdl2pp)
add_executable(LFTut2_41 LazyFooSDL2Tutorial/41_bitmap_fonts/41_bitmap_fonts.cpp)
target_link_libraries(LFTut2_41 sdl2pp)
add_executable(LFTut2_42 LazyFooSDL2Tutorial/42_texture_streaming/42_texture_streaming.cpp)
target_link_libraries(LFTut2_42 sdl2pp)
add_executable(LFTut2_43 LazyFooSDL2Tutorial/43_render_to_texture/43_render_to_texture.cpp)
target_link_libraries(LFTut2_43 sdl2pp)
add_executable(LFTut2_44 LazyFooSDL2Tutorial/44_frame_independent_movement/44_frame_independent_movement.cpp)
target_link_libraries(LFTut2_44 sdl2pp)
add_executable(LFTut2_45 LazyFooSDL2Tutorial/45_timer_callbacks/45_timer_callbacks.cpp)
target_link_libraries(LFTut2_45 sdl2pp)
add_executable(LFTut2_46 LazyFooSDL2Tutorial/46_multithreading/46_multithreading.cpp)
target_link_libraries(LFTut2_46 sdl2pp)
add_executable(LFTut2_47 LazyFooSDL2Tutorial/47_semaphores/47_semaphores.cpp)
target_link_libraries(LFTut2_47 sdl2pp)
add_executable(LFTut2_48 LazyFooSDL2Tutorial/48_atomic_operations/48_atomic_operations.cpp)
target_link_libraries(LFTut2_48 sdl2pp)
add_executable(LFTut2_49 LazyFooSDL2Tutorial/49_mutexes_and_conditions/49_mutexes_and_conditions.cpp)
target_link_libraries(LFTut2_49 sdl2pp)

add_executable(LFTut2_50 LazyFooSDL2Tutorial/50_SDL_and_opengl_2/50_SDL_and_opengl_2.cpp)
target_link_libraries(LFTut2_50 sdl2pp)
add_executable(LFTut2_51 LazyFooSDL2Tutorial/51_SDL_and_modern_opengl/51_SDL_and_modern_opengl.cpp)
target_link_libraries(LFTut2_51 sdl2pp)

# Kiss Tutorial
########################################################################################################################

add_executable(kiss_example_01 kiss_sdl/kiss_example1.c
        kiss_sdl/kiss_sdl.h
        kiss_sdl/kiss_widgets.c
        kiss_sdl/kiss_draw.c
        kiss_sdl/kiss_general.c
        kiss_sdl/kiss_posix.c)
target_link_libraries(kiss_example_01 sdl2pp)
add_executable(kiss_example_02 kiss_sdl/kiss_example2.c
        kiss_sdl/kiss_sdl.h
        kiss_sdl/kiss_widgets.c
        kiss_sdl/kiss_draw.c
        kiss_sdl/kiss_general.c
        kiss_sdl/kiss_posix.c)
target_link_libraries(kiss_example_02 sdl2pp)


########################################################################################################################
# UNIT TEST
########################################################################################################################

set(SOURCE_TEST
        src/libSDL2pp/test/TestEngine.cpp
        src/compile_time_loop.hpp
        test/test_compTimeLoop.cpp
        test/test_smoothingFunctions.cpp)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fconcepts")
add_executable(Test
        $<TARGET_OBJECTS:CatchMain>
        test/catchMain.cpp
        ${SOURCES_TEST_CATCH_020}
        ${SOURCES_TEST_CATCH_IDIOMATIC}
        ${SOURCES_TEST_SDL2PP}
        ${SOURCES_TEST_SCHEDULING}
        ${SOURCES_TEST_HEXAGON}
        ${SOURCES_TEST_WIDGET}
        ${SOURCE_TEST}
        )
#target_include_directories(Test PUBLIC ${CMAKE_SOURCE_DIR}/extern)
target_link_libraries(Test sdl2pp scheduling hexagon widget)
add_test(CATCH Test)

set(SOURCE_SVG_PLAYGROUND
        main_svg_playground.cpp )
add_executable(svg_playground ${SOURCE_SVG_PLAYGROUND})
