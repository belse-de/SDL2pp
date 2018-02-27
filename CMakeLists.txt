cmake_minimum_required(VERSION 3.8)
project(SDL2pp CXX C)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_VERBOSE_MAKEFILE OFF)

include_directories(include/ src/)
set(SOURCE_FILES
        library.cpp library.h
        include/libSDL2pp/Error.hpp
        include/libSDL2pp/Img/Error.hpp
        include/libSDL2pp/TTF/Error.hpp
        include/libSDL2pp/Mix/Error.hpp
        include/libSDL2pp/Net/Error.hpp
        src/libSDL2pp/SDL2.cpp include/libSDL2pp/SDL2.hpp
        src/libSDL2pp/Window.cpp src/libSDL2pp/Window.hpp
        src/libSDL2pp/Surface.cpp include/libSDL2pp/Surface.hpp
        src/libSDL2pp/Image.cpp include/libSDL2pp/Img/Image.hpp
        src/libSDL2pp/Img/SDL2Image.cpp include/libSDL2pp/Img/SDL2Image.hpp
        src/libSDL2pp/Renderer.cpp include/libSDL2pp/Renderer.hpp
        src/libSDL2pp/Texture.cpp include/libSDL2pp/Texture.hpp
        src/libSDL2pp/TTF/SDL2TTF.cpp include/libSDL2pp/TTF/SDL2TTF.hpp
        src/libSDL2pp/TTF/Font.cpp include/libSDL2pp/TTF/Font.hpp
        src/libSDL2pp/Mix/SDL2Mixer.cpp include/libSDL2pp/Mix/SDL2Mixer.hpp
        include/libSDL2pp/Net/SDL2Net.cpp include/libSDL2pp/Net/SDL2Net.hpp)
add_library(SDL2pp ${SOURCE_FILES})

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

include_directories(
        ${SDL2_INCLUDE_DIRS}
        ${SDL2IMAGE_INCLUDE_DIRS}
        ${SDL2TTF_INCLUDE_DIRS}
        ${SDL2MIXER_INCLUDE_DIRS}
        ${SDL2NET_INCLUDE_DIRS}
        ${OPENGL_INCLUDE_DIR}
        ${GLEW_INCLUDE_DIRS})
target_link_libraries(SDL2pp
        ${SDL2_LIBRARIES}
        ${SDL2IMAGE_LIBRARIES}
        ${SDL2TTF_LIBRARIES}
        ${SDL2MIXER_LIBRARIES}
        ${SDL2NET_LIBRARIES}
        ${OPENGL_LIBRARIES}
        ${GLEW_LIBRARIES})



add_executable(LazyFooTut LazyFooSDL2Tutorial/LazyFooTut.cpp)
target_link_libraries(LazyFooTut SDL2pp)

add_executable(LFTut2_19 LazyFooSDL2Tutorial/19_gamepads_and_joysticks/19_gamepads_and_joysticks.cpp)
target_link_libraries(LFTut2_19 SDL2pp)

add_executable(LFTut2_20 LazyFooSDL2Tutorial/20_force_feedback/20_force_feedback.cpp)
target_link_libraries(LFTut2_20 SDL2pp)
add_executable(LFTut2_21 LazyFooSDL2Tutorial/21_sound_effects_and_music/21_sound_effects_and_music.cpp)
target_link_libraries(LFTut2_21 SDL2pp)
add_executable(LFTut2_22 LazyFooSDL2Tutorial/22_timing/22_timing.cpp)
target_link_libraries(LFTut2_22 SDL2pp)
add_executable(LFTut2_23 LazyFooSDL2Tutorial/23_advanced_timers/23_advanced_timers.cpp)
target_link_libraries(LFTut2_23 SDL2pp)
add_executable(LFTut2_24 LazyFooSDL2Tutorial/24_calculating_frame_rate/24_calculating_frame_rate.cpp)
target_link_libraries(LFTut2_24 SDL2pp)
add_executable(LFTut2_25 LazyFooSDL2Tutorial/25_capping_frame_rate/25_capping_frame_rate.cpp)
target_link_libraries(LFTut2_25 SDL2pp)
add_executable(LFTut2_26 LazyFooSDL2Tutorial/26_motion/26_motion.cpp)
target_link_libraries(LFTut2_26 SDL2pp)
add_executable(LFTut2_27 LazyFooSDL2Tutorial/27_collision_detection/27_collision_detection.cpp)
target_link_libraries(LFTut2_27 SDL2pp)
add_executable(LFTut2_28 LazyFooSDL2Tutorial/28_per-pixel_collision_detection/28_per-pixel_collision_detection.cpp)
target_link_libraries(LFTut2_28 SDL2pp)
add_executable(LFTut2_29 LazyFooSDL2Tutorial/29_circular_collision_detection/29_circular_collision_detection.cpp)
target_link_libraries(LFTut2_29 SDL2pp)

add_executable(LFTut2_30 LazyFooSDL2Tutorial/30_scrolling/30_scrolling.cpp)
target_link_libraries(LFTut2_30 SDL2pp)
add_executable(LFTut2_31 LazyFooSDL2Tutorial/31_scrolling_backgrounds/31_scrolling_backgrounds.cpp)
target_link_libraries(LFTut2_31 SDL2pp)
add_executable(LFTut2_32 LazyFooSDL2Tutorial/32_text_input_and_clipboard_handling/32_text_input_and_clipboard_handling.cpp)
target_link_libraries(LFTut2_32 SDL2pp)
add_executable(LFTut2_33 LazyFooSDL2Tutorial/33_file_reading_and_writing/33_file_reading_and_writing.cpp)
target_link_libraries(LFTut2_33 SDL2pp)
#
#
add_executable(LFTut2_35 LazyFooSDL2Tutorial/35_window_events/35_window_events.cpp)
target_link_libraries(LFTut2_35 SDL2pp)
add_executable(LFTut2_36 LazyFooSDL2Tutorial/36_multiple_windows/36_multiple_windows.cpp)
target_link_libraries(LFTut2_36 SDL2pp)
add_executable(LFTut2_37 LazyFooSDL2Tutorial/37_multiple_displays/37_multiple_displays.cpp)
target_link_libraries(LFTut2_37 SDL2pp)
add_executable(LFTut2_38 LazyFooSDL2Tutorial/38_particle_engines/38_particle_engines.cpp)
target_link_libraries(LFTut2_38 SDL2pp)
add_executable(LFTut2_39 LazyFooSDL2Tutorial/39_tiling/39_tiling.cpp)
target_link_libraries(LFTut2_39 SDL2pp)

add_executable(LFTut2_40 LazyFooSDL2Tutorial/40_texture_manipulation/40_texture_manipulation.cpp)
target_link_libraries(LFTut2_40 SDL2pp)
add_executable(LFTut2_41 LazyFooSDL2Tutorial/41_bitmap_fonts/41_bitmap_fonts.cpp)
target_link_libraries(LFTut2_41 SDL2pp)
add_executable(LFTut2_42 LazyFooSDL2Tutorial/42_texture_streaming/42_texture_streaming.cpp)
target_link_libraries(LFTut2_42 SDL2pp)
add_executable(LFTut2_43 LazyFooSDL2Tutorial/43_render_to_texture/43_render_to_texture.cpp)
target_link_libraries(LFTut2_43 SDL2pp)
add_executable(LFTut2_44 LazyFooSDL2Tutorial/44_frame_independent_movement/44_frame_independent_movement.cpp)
target_link_libraries(LFTut2_44 SDL2pp)
add_executable(LFTut2_45 LazyFooSDL2Tutorial/45_timer_callbacks/45_timer_callbacks.cpp)
target_link_libraries(LFTut2_45 SDL2pp)
add_executable(LFTut2_46 LazyFooSDL2Tutorial/46_multithreading/46_multithreading.cpp)
target_link_libraries(LFTut2_46 SDL2pp)
add_executable(LFTut2_47 LazyFooSDL2Tutorial/47_semaphores/47_semaphores.cpp)
target_link_libraries(LFTut2_47 SDL2pp)
add_executable(LFTut2_48 LazyFooSDL2Tutorial/48_atomic_operations/48_atomic_operations.cpp)
target_link_libraries(LFTut2_48 SDL2pp)
add_executable(LFTut2_49 LazyFooSDL2Tutorial/49_mutexes_and_conditions/49_mutexes_and_conditions.cpp)
target_link_libraries(LFTut2_49 SDL2pp)

add_executable(LFTut2_50 LazyFooSDL2Tutorial/50_SDL_and_opengl_2/50_SDL_and_opengl_2.cpp)
target_link_libraries(LFTut2_50 SDL2pp)
add_executable(LFTut2_51 LazyFooSDL2Tutorial/51_SDL_and_modern_opengl/51_SDL_and_modern_opengl.cpp)
target_link_libraries(LFTut2_51 SDL2pp)

add_executable(kiss_example_01 kiss_sdl/kiss_example1.c
        kiss_sdl/kiss_widgets.c
        kiss_sdl/kiss_draw.c
        kiss_sdl/kiss_general.c
        kiss_sdl/kiss_posix.c)
target_link_libraries(kiss_example_01 SDL2pp)
add_executable(kiss_example_02 kiss_sdl/kiss_example2.c
        kiss_sdl/kiss_widgets.c
        kiss_sdl/kiss_draw.c
        kiss_sdl/kiss_general.c
        kiss_sdl/kiss_posix.c)
target_link_libraries(kiss_example_02 SDL2pp)


enable_testing()
# multiple-file modules:
set( SOURCES_TEST_020
        test/example/020-TestCase-1.cpp
        test/example/020-TestCase-2.cpp
        )

# sources to combine with 000-CatchMain.cpp:
set( SOURCES_TEST_IDIOMATIC
        test/example/030-Asn-Require-Check.cpp
        test/example/100-Fix-Section.cpp
        test/example/110-Fix-ClassFixture.cpp
        test/example/120-Bdd-ScenarioGivenWhenThen.cpp
        )
# define program targets:
add_library( CatchMain OBJECT test/catchMain.cpp test/catch.hpp)
target_include_directories( CatchMain PRIVATE test )

add_executable( TestCase
        ${SOURCES_TEST_020}
        ${SOURCES_TEST_IDIOMATIC}
        $<TARGET_OBJECTS:CatchMain>
        test/catch.hpp)
target_include_directories( TestCase PRIVATE test )
set_property(TARGET TestCase PROPERTY CXX_STANDARD 11)
add_test( CATCH TestCase )

set(SOURCE_TEST
        test/TestEngine.cpp)
add_executable( Test
        ${SOURCE_TEST}
        $<TARGET_OBJECTS:CatchMain>
        test/catch.hpp)
target_link_libraries(Test SDL2pp)
add_test(FullTestSuite Test)
