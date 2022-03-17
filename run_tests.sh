#!/bin/sh -vx
set -e

mkdir -p build
cd build

cmake ..
cmake --build . --config Release --target homm3tests
ctest -C Release --verbose --output-on-failure .
