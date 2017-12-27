cmake_minimum_required(VERSION 3.8)
project(SDL2pp CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_VERBOSE_MAKEFILE ON)

include_directories(include/ src/)
set(SOURCE_FILES
        library.cpp library.h
        include/SDL2pp/Error.hpp
        include/SDL2pp/Img/Error.hpp
        include/SDL2pp/TTF/Error.hpp
        src/SDL2.cpp src/SDL2.hpp
        src/Window.cpp src/Window.hpp
        src/Surface.cpp src/Surface.hpp
        src/Image.cpp src/Image.hpp
        src/SDL2Image.cpp src/SDL2Image.hpp
        src/Renderer.cpp src/Renderer.hpp
        src/Texture.cpp src/Texture.hpp
        src/SDL2TTF.cpp src/SDL2TTF.hpp src/Font.cpp src/Font.hpp)
add_library(SDL2pp ${SOURCE_FILES})

include(FindPkgConfig)
pkg_search_module(SDL2      REQUIRED sdl2)
pkg_search_module(SDL2IMAGE REQUIRED SDL2_image)
pkg_search_module(SDL2TTF   REQUIRED SDL2_ttf)

include_directories(
        ${SDL2_INCLUDE_DIRS}
        ${SDL2IMAGE_INCLUDE_DIRS}
        ${SDL2TTF_INCLUDE_DIRS})
target_link_libraries(SDL2pp
        ${SDL2_LIBRARIES}
        ${SDL2IMAGE_LIBRARIES}
        ${SDL2TTF_LIBRARIES})


enable_testing()

add_executable(LazyFooSDL2Tutorial_01 LazyFooSDL2Tutorial/01_hello_SDL/01_hello_SDL.cpp)
target_link_libraries(LazyFooSDL2Tutorial_01 SDL2pp)
add_executable(LazyFooSDL2Tutorial_02 LazyFooSDL2Tutorial/02_getting_an_image_on_the_screen/02_getting_an_image_on_the_screen.cpp)
target_link_libraries(LazyFooSDL2Tutorial_02 SDL2pp)
add_executable(LazyFooSDL2Tutorial_03 LazyFooSDL2Tutorial/03_event_driven_programming/03_event_driven_programming.cpp)
target_link_libraries(LazyFooSDL2Tutorial_03 SDL2pp)
add_executable(LazyFooSDL2Tutorial_04 LazyFooSDL2Tutorial/04_key_presses/04_key_presses.cpp)
target_link_libraries(LazyFooSDL2Tutorial_04 SDL2pp)
add_executable(LazyFooSDL2Tutorial_05 LazyFooSDL2Tutorial/05_optimized_surface_loading_and_soft_stretching/05_optimized_surface_loading_and_soft_stretching.cpp)
target_link_libraries(LazyFooSDL2Tutorial_05 SDL2pp)
add_executable(LazyFooSDL2Tutorial_06 LazyFooSDL2Tutorial/06_extension_libraries_and_loading_other_image_formats/06_extension_libraries_and_loading_other_image_formats.cpp)
target_link_libraries(LazyFooSDL2Tutorial_06 SDL2pp)
add_executable(LazyFooSDL2Tutorial_07 LazyFooSDL2Tutorial/07_texture_loading_and_rendering/07_texture_loading_and_rendering.cpp)
target_link_libraries(LazyFooSDL2Tutorial_07 SDL2pp)
add_executable(LazyFooSDL2Tutorial_08 LazyFooSDL2Tutorial/08_geometry_rendering/08_geometry_rendering.cpp)
target_link_libraries(LazyFooSDL2Tutorial_08 SDL2pp)
add_executable(LazyFooSDL2Tutorial_09 LazyFooSDL2Tutorial/09_the_viewport/09_the_viewport.cpp)
target_link_libraries(LazyFooSDL2Tutorial_09 SDL2pp)
add_executable(LazyFooSDL2Tutorial_10 LazyFooSDL2Tutorial/10_color_keying/10_color_keying.cpp)
target_link_libraries(LazyFooSDL2Tutorial_10 SDL2pp)

add_executable(LazyFooSDL2Tutorial_11 LazyFooSDL2Tutorial/11_clip_rendering_and_sprite_sheets/11_clip_rendering_and_sprite_sheets.cpp)
target_link_libraries(LazyFooSDL2Tutorial_11 SDL2pp)
add_executable(LazyFooSDL2Tutorial_12 LazyFooSDL2Tutorial/12_color_modulation/12_color_modulation.cpp)
target_link_libraries(LazyFooSDL2Tutorial_12 SDL2pp)
add_executable(LazyFooSDL2Tutorial_13 LazyFooSDL2Tutorial/13_alpha_blending/13_alpha_blending.cpp)
target_link_libraries(LazyFooSDL2Tutorial_13 SDL2pp)
add_executable(LazyFooSDL2Tutorial_14 LazyFooSDL2Tutorial/14_animated_sprites_and_vsync/14_animated_sprites_and_vsync.cpp)
target_link_libraries(LazyFooSDL2Tutorial_14 SDL2pp)
add_executable(LazyFooSDL2Tutorial_15 LazyFooSDL2Tutorial/15_rotation_and_flipping/15_rotation_and_flipping.cpp)
target_link_libraries(LazyFooSDL2Tutorial_15 SDL2pp)
add_executable(LazyFooSDL2Tutorial_16 LazyFooSDL2Tutorial/16_true_type_fonts/16_true_type_fonts.cpp)
target_link_libraries(LazyFooSDL2Tutorial_16 SDL2pp)

add_test( LazyFoo_01 LazyFooSDL2Tutorial_01 )
add_test( LazyFoo_02 LazyFooSDL2Tutorial_02 )
add_test( LazyFoo_03 LazyFooSDL2Tutorial_03 )
add_test( LazyFoo_04 LazyFooSDL2Tutorial_04 )
add_test( LazyFoo_05 LazyFooSDL2Tutorial_05 )
add_test( LazyFoo_06 LazyFooSDL2Tutorial_06 )
add_test( LazyFoo_07 LazyFooSDL2Tutorial_07 )
add_test( LazyFoo_08 LazyFooSDL2Tutorial_08 )
add_test( LazyFoo_09 LazyFooSDL2Tutorial_09 )

add_test( LazyFoo_10 LazyFooSDL2Tutorial_10 )
add_test( LazyFoo_11 LazyFooSDL2Tutorial_11 )
add_test( LazyFoo_12 LazyFooSDL2Tutorial_12 )
add_test( LazyFoo_13 LazyFooSDL2Tutorial_13 )
add_test( LazyFoo_14 LazyFooSDL2Tutorial_14 )
add_test( LazyFoo_15 LazyFooSDL2Tutorial_15 )
add_test( LazyFoo_16 LazyFooSDL2Tutorial_16 )
add_test( LazyFoo_17 LazyFooSDL2Tutorial_17 )
add_test( LazyFoo_18 LazyFooSDL2Tutorial_18 )
add_test( LazyFoo_19 LazyFooSDL2Tutorial_19 )

add_test( LazyFoo_20 LazyFooSDL2Tutorial_20 )
add_test( LazyFoo_21 LazyFooSDL2Tutorial_21 )
add_test( LazyFoo_22 LazyFooSDL2Tutorial_22 )
add_test( LazyFoo_23 LazyFooSDL2Tutorial_23 )
add_test( LazyFoo_24 LazyFooSDL2Tutorial_24 )
add_test( LazyFoo_25 LazyFooSDL2Tutorial_25 )
add_test( LazyFoo_26 LazyFooSDL2Tutorial_26 )
add_test( LazyFoo_27 LazyFooSDL2Tutorial_27 )
add_test( LazyFoo_28 LazyFooSDL2Tutorial_28 )
add_test( LazyFoo_29 LazyFooSDL2Tutorial_29 )

add_test( LazyFoo_30 LazyFooSDL2Tutorial_30 )
add_test( LazyFoo_31 LazyFooSDL2Tutorial_31 )
add_test( LazyFoo_32 LazyFooSDL2Tutorial_32 )
add_test( LazyFoo_33 LazyFooSDL2Tutorial_33 )
add_test( LazyFoo_34 LazyFooSDL2Tutorial_34 )
add_test( LazyFoo_35 LazyFooSDL2Tutorial_35 )
add_test( LazyFoo_36 LazyFooSDL2Tutorial_36 )
add_test( LazyFoo_37 LazyFooSDL2Tutorial_37 )
add_test( LazyFoo_38 LazyFooSDL2Tutorial_38 )
add_test( LazyFoo_39 LazyFooSDL2Tutorial_39 )

add_test( LazyFoo_40 LazyFooSDL2Tutorial_40 )
add_test( LazyFoo_41 LazyFooSDL2Tutorial_41 )
add_test( LazyFoo_42 LazyFooSDL2Tutorial_42 )
add_test( LazyFoo_43 LazyFooSDL2Tutorial_43 )
add_test( LazyFoo_44 LazyFooSDL2Tutorial_44 )
add_test( LazyFoo_45 LazyFooSDL2Tutorial_45 )
add_test( LazyFoo_46 LazyFooSDL2Tutorial_46 )
add_test( LazyFoo_47 LazyFooSDL2Tutorial_47 )
add_test( LazyFoo_48 LazyFooSDL2Tutorial_48 )
add_test( LazyFoo_49 LazyFooSDL2Tutorial_49 )

add_test( LazyFoo_50 LazyFooSDL2Tutorial_50 )
add_test( LazyFoo_51 LazyFooSDL2Tutorial_51 )
