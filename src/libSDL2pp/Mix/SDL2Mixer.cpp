//
// Created by belse on 31.12.17.
//

#include "SDL2pp/Mix/SDL2Mixer.hpp"

#include <SDL_mixer.h>
#include <SDL2pp/Mix/Error.hpp>

using namespace SDL2pp::Mix;

SDL2Mixer::SDL2Mixer() :
    SDL2Mixer(MIX_INIT_FLAC | MIX_INIT_MOD | MIX_INIT_MP3 | MIX_INIT_OGG,
              MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 2, 1024) {
}

SDL2Mixer::SDL2Mixer(int fileFormats, int frequency, uint16_t playbackFormat, int channels, int chunksize) {
    if (Mix_OpenAudio(frequency, playbackFormat, channels, chunksize) == -1) {
        throw Error("SDL_mixer could not initialize audio!");
    }

    if (( Mix_Init(fileFormats) & fileFormats) != fileFormats) {
        throw Error("SDL_mixer could not initialize all file formats!");
    }
}

SDL2Mixer::~SDL2Mixer() {
    int frequency;
    uint16_t format;
    int channels;
    int timesOpened = Mix_QuerySpec(&frequency, &format, &channels);
    if (timesOpened > 0) { Mix_CloseAudio(); }

    // indicate that we are ready to unload the dynamically loaded libraries
    // force a quit
    timesOpened = Mix_QuerySpec(&frequency, &format, &channels);
    if (timesOpened <= 0) {
        Mix_Quit();
    }
}



