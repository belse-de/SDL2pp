//
// Created by belse on 31.12.17.
//

#include <iostream>
#include <chrono>

using namespace std::chrono_literals;

#include <SDL_image.h>
#include <SDL_mixer.h>

#include <libSDL2pp/src/SDL2.hpp>
#include <libSDL2pp/src/Img/SDL2Image.hpp>
#include <libSDL2pp/src/Img/Error.hpp>
#include <libSDL2pp/src/TTF/SDL2TTF.hpp>
#include <libSDL2pp/src/TTF/Error.hpp>
#include <libSDL2pp/src/Mix/SDL2Mixer.hpp>
#include <libSDL2pp/src/Mix/Error.hpp>
#include <libSDL2pp/src/Net/SDL2Net.hpp>
#include <libSDL2pp/src/Net/Error.hpp>

#include "catch.hpp"

// sdl2 sdl2_image sdl2_ttf sdl2_mixer sdl2_net sdl2_gfx
TEST_CASE( "SDL2_IMG init", "[img]" ) {
    SDL2pp::SDL2 sdl;

    SECTION("without arguments") {
        try {
            SDL2pp::Img::SDL2Image img;
        } catch (SDL2pp::Img::Error &e) {
            std::cerr << e.what() << std::endl;
            FAIL();
        }
    }

    SECTION("with jpg") {
        SDL2pp::Img::SDL2Image img(IMG_INIT_JPG);
    }

    SECTION("with png") {
        SDL2pp::Img::SDL2Image img(IMG_INIT_PNG);
    }

    SECTION("with tif") {
        SDL2pp::Img::SDL2Image img(IMG_INIT_TIF);
    }

    SECTION("with jpg, png") {
        SDL2pp::Img::SDL2Image img(IMG_INIT_JPG | IMG_INIT_PNG);
    }

    SECTION("with jpg, tif") {
        SDL2pp::Img::SDL2Image img(IMG_INIT_JPG | IMG_INIT_TIF);
    }

    SECTION("with png, tif") {
        SDL2pp::Img::SDL2Image img(IMG_INIT_PNG | IMG_INIT_TIF);
    }

    SECTION("with jpg, png, tif") {
        SDL2pp::Img::SDL2Image img(IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF);
    }
}

TEST_CASE( "SDL2_TTF init", "[ttf]"){
    SDL2pp::SDL2 sdl;

    SECTION( "without arguments" ) {
        CHECK_FALSE( SDL2pp::TTF::SDL2TTF::wasInit() );
        SDL2pp::TTF::SDL2TTF ttf;
        REQUIRE( SDL2pp::TTF::SDL2TTF::wasInit() );
    }

    SECTION( "double init" ) {
        CHECK( not SDL2pp::TTF::SDL2TTF::wasInit() );
        SDL2pp::TTF::SDL2TTF ttf;
        CHECK( SDL2pp::TTF::SDL2TTF::wasInit() );

        try{
            SDL2pp::TTF::SDL2TTF ttf_error;
            FAIL( "Double Init should fail!" );
        } catch (SDL2pp::TTF::Error &e) {
            SUCCEED();
        }
    }
}


TEST_CASE( "SDL2_MIX init", "[mix]"){
    SDL2pp::SDL2 sdl;

    SECTION( "without arguments" ) {
        SDL2pp::Mix::SDL2Mixer mix;
    }

    SECTION( "with flac" ) {
        SDL2pp::Mix::SDL2Mixer mix(MIX_INIT_FLAC);
    }
    SECTION( "with mod" ) {
        SDL2pp::Mix::SDL2Mixer mix(MIX_INIT_MOD);
    }
    SECTION( "with mp3" ) {
        SDL2pp::Mix::SDL2Mixer mix(MIX_INIT_MP3);
    }
    SECTION( "with ogg" ) {
        SDL2pp::Mix::SDL2Mixer mix(MIX_INIT_OGG);
    }
    SECTION( "with flac, mod" ) {
        SDL2pp::Mix::SDL2Mixer mix(MIX_INIT_FLAC | MIX_INIT_MOD);
    }
    SECTION( "with flac, mp3" ) {
        SDL2pp::Mix::SDL2Mixer mix(MIX_INIT_FLAC | MIX_INIT_MP3);
    }
    SECTION( "with flac, ogg" ) {
        SDL2pp::Mix::SDL2Mixer mix(MIX_INIT_FLAC | MIX_INIT_OGG);
    }
    SECTION( "with mod, mp3" ) {
        SDL2pp::Mix::SDL2Mixer mix(MIX_INIT_MOD | MIX_INIT_MP3);
    }
    SECTION( "with mod, ogg" ) {
        SDL2pp::Mix::SDL2Mixer mix(MIX_INIT_MOD | MIX_INIT_OGG);
    }
    SECTION( "with mp3, ogg" ) {
        SDL2pp::Mix::SDL2Mixer mix(MIX_INIT_MP3 | MIX_INIT_OGG);
    }

    SECTION( "multiple times" ){
        SDL2pp::Mix::SDL2Mixer mix_f(MIX_INIT_FLAC);
        SDL2pp::Mix::SDL2Mixer mix_m(MIX_INIT_MOD);
        SDL2pp::Mix::SDL2Mixer mix_3(MIX_INIT_MP3);
        SDL2pp::Mix::SDL2Mixer mix_o(MIX_INIT_OGG);
        SDL2pp::Mix::SDL2Mixer mix;
    }
}

TEST_CASE( "SDL2_NET init", "[net]"){
    SDL2pp::SDL2 sdl;
    SECTION( "without arguments" ) {
        SDL2pp::Net::SDL2Net net;
    }

    SECTION( "double init" ) {

        SDL2pp::Net::SDL2Net net;
        try {
            SDL2pp::Net::SDL2Net net_error;
            FAIL("Double Init should fail!");
        } catch (SDL2pp::Net::Error &e) {
            SUCCEED("Second init failed!");
        }
        //FIXME: FAIL( "Double Init should fail! fall through..." );
    }
}
