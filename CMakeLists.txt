cmake_minimum_required(VERSION 3.8)
project(sdl2pp CXX C)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 11)

set(CMAKE_VERBOSE_MAKEFILE OFF)

enable_testing()

include_directories(src/ include/)

# https://cmake.org/cmake/help/v3.0/module/FindOpenGL.html
find_package(OpenGL REQUIRED)
# https://cmake.org/cmake/help/v3.0/module/FindGLEW.html
find_package(GLEW REQUIRED)

include(FindPkgConfig)
pkg_search_module(SDL2      REQUIRED sdl2)
pkg_search_module(SDL2IMAGE REQUIRED sdl2_image)
pkg_search_module(SDL2TTF   REQUIRED sdl2_ttf)
pkg_search_module(SDL2MIXER REQUIRED sdl2_mixer)
pkg_search_module(SDL2NET   REQUIRED SDL2_net)

########################################################################################################################
# lib CATCH
########################################################################################################################
# define program targets:
add_library( CatchMain OBJECT test/catchMain.cpp test/catch.hpp)
target_include_directories(CatchMain PUBLIC ${CMAKE_SOURCE_DIR}/extern/Catch2-master/single_include)

# CATCH Examples
########################################################################################################################
# multiple-file modules:
set( SOURCES_TEST_CATCH_020
        test/example/020-TestCase-1.cpp
        test/example/020-TestCase-2.cpp
        )
# sources to combine with 000-CatchMain.cpp:
set( SOURCES_TEST_CATCH_IDIOMATIC

        test/example/100-Fix-Section.cpp
        test/example/110-Fix-ClassFixture.cpp
        test/example/120-Bdd-ScenarioGivenWhenThen.cpp
        )
#TODO set to ignored
#test/example/030-Asn-Require-Check.cpp


########################################################################################################################
# lib sdl2pp
########################################################################################################################
set(SOURCES_LIB_SDL2PP
        src/libSDL2pp/Error.hpp
        src/libSDL2pp/Img/Error.hpp
        src/libSDL2pp/TTF/Error.hpp
        src/libSDL2pp/Mix/Error.hpp
        src/libSDL2pp/Net/Error.hpp
        src/libSDL2pp/SDL2.cpp
        src/libSDL2pp/SDL2.hpp
        src/libSDL2pp/Window.cpp
        src/libSDL2pp/Window.hpp
        src/libSDL2pp/Surface.cpp
        src/libSDL2pp/Surface.hpp
        src/libSDL2pp/Img/Image.cpp
        src/libSDL2pp/Img/Image.hpp
        src/libSDL2pp/Img/SDL2Image.cpp
        src/libSDL2pp/Img/SDL2Image.hpp
        src/libSDL2pp/Renderer.cpp
        src/libSDL2pp/Renderer.hpp
        src/libSDL2pp/Texture.cpp
        src/libSDL2pp/Texture.hpp
        src/libSDL2pp/TTF/SDL2TTF.cpp
        src/libSDL2pp/TTF/SDL2TTF.hpp
        src/libSDL2pp/TTF/Font.cpp
        src/libSDL2pp/TTF/Font.hpp
        src/libSDL2pp/Mix/SDL2Mixer.cpp
        src/libSDL2pp/Mix/SDL2Mixer.hpp
        src/libSDL2pp/Net/SDL2Net.cpp
        src/libSDL2pp/Net/SDL2Net.hpp)
set(SOURCES_TEST_SDL2PP
        )
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

add_executable(main_sdl2pp ${SOURCES_EXE_SDL2PP})
target_link_libraries(main_sdl2pp sdl2pp)

########################################################################################################################
# lib scheduling
########################################################################################################################
set(SOURCES_LIB_SCHEDULING
        extern/overloaded.hpp
        src/libScheduling/Printable.cpp
        src/libScheduling/Printable.hpp
        src/libScheduling/Process.cpp
        src/libScheduling/Process.hpp
        src/libScheduling/ProcessStatistics.cpp
        src/libScheduling/ProcessStatistics.hpp
        src/libScheduling/Scheduler.cpp
        src/libScheduling/Scheduler.hpp
        src/libScheduling/SchedulingStrategy.cpp
        src/libScheduling/SchedulingStrategy.hpp
        src/libScheduling/Strategies/RoundRobinStrategy.cpp
        src/libScheduling/Strategies/RoundRobinStrategy.hpp
        src/libScheduling/Strategies/ShortesJobFirstStrategy.cpp
        src/libScheduling/Strategies/ShortesJobFirstStrategy.hpp
        src/libScheduling/Strategies/FirstComeFirstServedStrategy.cpp
        src/libScheduling/Strategies/FirstComeFirstServedStrategy.hpp
        src/libScheduling/Strategies/PriorityStrategy.cpp
        src/libScheduling/Strategies/PriorityStrategy.hpp
        src/libScheduling/SystemTimerSubscriber.cpp
        src/libScheduling/SystemTimerSubscriber.hpp
        src/libScheduling/SystemTimer.cpp
        src/libScheduling/SystemTimer.hpp)
set(SOURCES_TEST_SCHEDULING
        test/libScheduling/testProcess.cpp
        test/libScheduling/testRoundRobin.cpp
        test/libScheduling/testScheduler.cpp)
set(SOURCES_EXE_SCHEDULING
        main_libScheduling.cpp)

add_library(scheduling ${SOURCES_LIB_SCHEDULING})

add_executable(main_scheduling ${SOURCES_EXE_SCHEDULING})
target_link_libraries(main_scheduling scheduling)

########################################################################################################################
# lib hexagon
########################################################################################################################
set(SOURCES_LIB_HEXAGON
        src/libHexagon/libhex.cpp
        src/libHexagon/libhex.hpp)
set(SOURCES_TEST_HEXAGON
        test/libHexagon/testHexagon.cpp
        )
set(SOURCES_EXE_HEXAGON
        main_libHexagon.cpp)

add_library(hexagon ${SOURCES_LIB_HEXAGON})

add_executable(main_hexagon ${SOURCES_EXE_HEXAGON})
target_link_libraries(main_hexagon hexagon)

########################################################################################################################
# Executeables and test
########################################################################################################################

# LazyFoo Tutorial
########################################################################################################################

add_executable(LazyFooTut LazyFooSDL2Tutorial/LazyFooTut.cpp)
target_link_libraries(LazyFooTut sdl2pp)

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
        kiss_sdl/kiss_widgets.c
        kiss_sdl/kiss_draw.c
        kiss_sdl/kiss_general.c
        kiss_sdl/kiss_posix.c)
target_link_libraries(kiss_example_01 sdl2pp)
add_executable(kiss_example_02 kiss_sdl/kiss_example2.c
        kiss_sdl/kiss_widgets.c
        kiss_sdl/kiss_draw.c
        kiss_sdl/kiss_general.c
        kiss_sdl/kiss_posix.c)
target_link_libraries(kiss_example_02 sdl2pp)


########################################################################################################################
# UNIT TEST
########################################################################################################################

set(SOURCE_TEST
        test/TestEngine.cpp)

add_executable( Test
        $<TARGET_OBJECTS:CatchMain>
        ${SOURCES_TEST_CATCH_020}
        ${SOURCES_TEST_CATCH_IDIOMATIC}
        ${SOURCES_TEST_SDL2PP}
        ${SOURCES_TEST_SCHEDULING}
        ${SOURCES_TEST_HEXAGON}
        ${SOURCE_TEST}
        )
target_include_directories(Test PUBLIC ${CMAKE_SOURCE_DIR}/extern/Catch2-master/single_include)
target_link_libraries(Test sdl2pp scheduling hexagon)
add_test( CATCH Test )
