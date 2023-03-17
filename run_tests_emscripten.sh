#!/bin/sh -vx
set -e

mkdir -p build_emscripten
cd build_emscripten

emcmake cmake ..
cmake --build . --config Release --target homm3tests h3plotstests
ctest -C Release --verbose --output-on-failure .
