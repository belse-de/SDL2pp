//
// Created by belse on 01.01.18.
//

#ifndef SDL2PP_NET_SDL2NET_HPP
#define SDL2PP_NET_SDL2NET_HPP

namespace SDL2pp::Net {
    class SDL2Net {
    public:
        SDL2Net();

        virtual ~SDL2Net();

        static bool wasInit();

    private:
        static bool isInit_;

    };
};

#endif //SDL2PP_NET_SDL2NET_HPP
