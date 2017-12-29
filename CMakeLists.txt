cmake_minimum_required(VERSION 3.8)
project(SDL2pp CXX C)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_VERBOSE_MAKEFILE OFF)

include_directories(include/ src/)
set(SOURCE_FILES
        library.cpp library.h
        include/SDL2pp/Error.hpp
        include/SDL2pp/Img/Error.hpp
        include/SDL2pp/TTF/Error.hpp
        src/SDL2.cpp include/SDL2pp/SDL2.hpp
        src/Window.cpp include/SDL2pp/Window.hpp
        src/Surface.cpp include/SDL2pp/Surface.hpp
        src/Image.cpp include/SDL2pp/Img/Image.hpp
        src/SDL2Image.cpp include/SDL2pp/Img/SDL2Image.hpp
        src/Renderer.cpp include/SDL2pp/Renderer.hpp
        src/Texture.cpp include/SDL2pp/Texture.hpp
        src/SDL2TTF.cpp include/SDL2pp/TTF/SDL2TTF.hpp
        src/Font.cpp include/SDL2pp/TTF/Font.hpp)
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

include_directories(
        ${SDL2_INCLUDE_DIRS}
        ${SDL2IMAGE_INCLUDE_DIRS}
        ${SDL2TTF_INCLUDE_DIRS}
        ${SDL2MIXER_INCLUDE_DIRS}
        ${OPENGL_INCLUDE_DIR}
        ${GLEW_INCLUDE_DIRS})
target_link_libraries(SDL2pp
        ${SDL2_LIBRARIES}
        ${SDL2IMAGE_LIBRARIES}
        ${SDL2TTF_LIBRARIES}
        ${SDL2MIXER_LIBRARIES}
        ${OPENGL_LIBRARIES}
        ${GLEW_LIBRARIES})



enable_testing()

add_executable(LFTut2_01 LazyFooSDL2Tutorial/01_hello_SDL/01_hello_SDL.cpp)
target_link_libraries(LFTut2_01 SDL2pp)
add_executable(LFTut2_02 LazyFooSDL2Tutorial/02_getting_an_image_on_the_screen/02_getting_an_image_on_the_screen.cpp)
target_link_libraries(LFTut2_02 SDL2pp)
add_executable(LFTut2_03 LazyFooSDL2Tutorial/03_event_driven_programming/03_event_driven_programming.cpp)
target_link_libraries(LFTut2_03 SDL2pp)
add_executable(LFTut2_04 LazyFooSDL2Tutorial/04_key_presses/04_key_presses.cpp)
target_link_libraries(LFTut2_04 SDL2pp)
add_executable(LFTut2_05 LazyFooSDL2Tutorial/05_optimized_surface_loading_and_soft_stretching/05_optimized_surface_loading_and_soft_stretching.cpp)
target_link_libraries(LFTut2_05 SDL2pp)
add_executable(LFTut2_06 LazyFooSDL2Tutorial/06_extension_libraries_and_loading_other_image_formats/06_extension_libraries_and_loading_other_image_formats.cpp)
target_link_libraries(LFTut2_06 SDL2pp)
add_executable(LFTut2_07 LazyFooSDL2Tutorial/07_texture_loading_and_rendering/07_texture_loading_and_rendering.cpp)
target_link_libraries(LFTut2_07 SDL2pp)
add_executable(LFTut2_08 LazyFooSDL2Tutorial/08_geometry_rendering/08_geometry_rendering.cpp)
target_link_libraries(LFTut2_08 SDL2pp)
add_executable(LFTut2_09 LazyFooSDL2Tutorial/09_the_viewport/09_the_viewport.cpp)
target_link_libraries(LFTut2_09 SDL2pp)

add_executable(LFTut2_10 LazyFooSDL2Tutorial/10_color_keying/10_color_keying.cpp)
target_link_libraries(LFTut2_10 SDL2pp)
add_executable(LFTut2_11 LazyFooSDL2Tutorial/11_clip_rendering_and_sprite_sheets/11_clip_rendering_and_sprite_sheets.cpp)
target_link_libraries(LFTut2_11 SDL2pp)
add_executable(LFTut2_12 LazyFooSDL2Tutorial/12_color_modulation/12_color_modulation.cpp)
target_link_libraries(LFTut2_12 SDL2pp)
add_executable(LFTut2_13 LazyFooSDL2Tutorial/13_alpha_blending/13_alpha_blending.cpp)
target_link_libraries(LFTut2_13 SDL2pp)
add_executable(LFTut2_14 LazyFooSDL2Tutorial/14_animated_sprites_and_vsync/14_animated_sprites_and_vsync.cpp)
target_link_libraries(LFTut2_14 SDL2pp)
add_executable(LFTut2_15 LazyFooSDL2Tutorial/15_rotation_and_flipping/15_rotation_and_flipping.cpp)
target_link_libraries(LFTut2_15 SDL2pp)
add_executable(LFTut2_16 LazyFooSDL2Tutorial/16_true_type_fonts/16_true_type_fonts.cpp)
target_link_libraries(LFTut2_16 SDL2pp)
add_executable(LFTut2_17 LazyFooSDL2Tutorial/17_mouse_events/17_mouse_events.cpp)
target_link_libraries(LFTut2_17 SDL2pp)
add_executable(LFTut2_18 LazyFooSDL2Tutorial/18_key_states/18_key_states.cpp)
target_link_libraries(LFTut2_18 SDL2pp)
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

add_test( LazyFoo_01 LFTut2_01 )
add_test( LazyFoo_02 LFTut2_02 )
add_test( LazyFoo_03 LFTut2_03 )
add_test( LazyFoo_04 LFTut2_04 )
add_test( LazyFoo_05 LFTut2_05 )
add_test( LazyFoo_06 LFTut2_06 )
add_test( LazyFoo_07 LFTut2_07 )
add_test( LazyFoo_08 LFTut2_08 )
add_test( LazyFoo_09 LFTut2_09 )

add_test( LazyFoo_10 LFTut2_10 )
add_test( LazyFoo_11 LFTut2_11 )
add_test( LazyFoo_12 LFTut2_12 )
add_test( LazyFoo_13 LFTut2_13 )
add_test( LazyFoo_14 LFTut2_14 )
add_test( LazyFoo_15 LFTut2_15 )
add_test( LazyFoo_16 LFTut2_16 )
add_test( LazyFoo_17 LFTut2_17 )
add_test( LazyFoo_18 LFTut2_18 )
add_test( LazyFoo_19 LFTut2_19 )

add_test( LazyFoo_20 LFTut2_20 )
add_test( LazyFoo_21 LFTut2_21 )
add_test( LazyFoo_22 LFTut2_22 )
add_test( LazyFoo_23 LFTut2_23 )
add_test( LazyFoo_24 LFTut2_24 )
add_test( LazyFoo_25 LFTut2_25 )
add_test( LazyFoo_26 LFTut2_26 )
add_test( LazyFoo_27 LFTut2_27 )
add_test( LazyFoo_28 LFTut2_28 )
add_test( LazyFoo_29 LFTut2_29 )

add_test( LazyFoo_30 LFTut2_30 )
add_test( LazyFoo_31 LFTut2_31 )
add_test( LazyFoo_32 LFTut2_32 )
add_test( LazyFoo_33 LFTut2_33 )
#
add_test( LazyFoo_35 LFTut2_35 )
add_test( LazyFoo_36 LFTut2_36 )
add_test( LazyFoo_37 LFTut2_37 )
add_test( LazyFoo_38 LFTut2_38 )
add_test( LazyFoo_39 LFTut2_39 )

add_test( LazyFoo_40 LFTut2_40 )
add_test( LazyFoo_41 LFTut2_41 )
add_test( LazyFoo_42 LFTut2_42 )
add_test( LazyFoo_43 LFTut2_43 )
add_test( LazyFoo_44 LFTut2_44 )
add_test( LazyFoo_45 LFTut2_45 )
add_test( LazyFoo_46 LFTut2_46 )
add_test( LazyFoo_47 LFTut2_47 )
add_test( LazyFoo_48 LFTut2_48 )
add_test( LazyFoo_49 LFTut2_49 )

add_test( LazyFoo_50 LFTut2_50 )
add_test( LazyFoo_51 LFTut2_51 )

add_test( kiss_01 kiss_example_01 )
add_test( kiss_02 kiss_example_02 )
