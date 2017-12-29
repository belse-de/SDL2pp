#! /usr/bin/bash
set -e

for i in cmake-build-debug/LFTut2_*; do
    [ -f "$i" ] || break
    (cd LazyFooSDL2Tutorial; ../$i)
done

for i in cmake-build-debug/kiss_example_*; do
    [ -f "$i" ] || break
    (cd kiss_sdl; ../$i)
done
