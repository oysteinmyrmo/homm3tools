#!/bin/sh -vx
set -e

mkdir -p build_emscripten
cd build_emscripten

emcmake cmake ..
cmake --build . --config Debug --target homm3tests h3plotstests
cp ../test.html tests/h3
cd tests/h3
emrun test.html
