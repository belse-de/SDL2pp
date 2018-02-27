//
// Created by belse on 31.12.17.
//

#ifndef SDL2PP_SDL2MIXER_HPP
#define SDL2PP_SDL2MIXER_HPP

#include <cstdint>
#include <SDL_mixer.h>

namespace SDL2pp::Mix {
    class SDL2Mixer {
    public:
        SDL2Mixer();
        SDL2Mixer(int fileFormats, // = MIX_INIT_FLAC | MIX_INIT_MOD | MIX_INIT_MP3 | MIX_INIT_OGG | MIX_INIT_MID,
                  int frequency =  MIX_DEFAULT_FREQUENCY,
                  uint16_t playbackFormat = MIX_DEFAULT_FORMAT,
                  int channels = 2, int chunksize = 1024);

        virtual ~SDL2Mixer();

    private:
        int featureFlags_ = 0;

    };
};


#endif //SDL2PP_SDL2MIXER_HPP
