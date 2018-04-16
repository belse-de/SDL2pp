//
// Created by belse on 27.12.17.
//

#ifndef SDL2PP_SDL2TTF_HPP
#define SDL2PP_SDL2TTF_HPP

namespace SDL2pp::TTF {
    class SDL2TTF {
    public:
        SDL2TTF();

        virtual ~SDL2TTF();

        static bool wasInit();

        //TODO: add Font loading and handling; font destructor may not be called after lib destructor

    private:
        static bool isInit_;
    };
};

#endif //SDL2PP_SDL2TTF_HPP
