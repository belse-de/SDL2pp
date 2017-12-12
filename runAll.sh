#! /usr/bin/bash

for i in cmake-build-debug/LazyFooSDL2Tutorial_*; do
    [ -f "$i" ] || break
    (cd LazyFooSDL2Tutorial; ../$i)
done
