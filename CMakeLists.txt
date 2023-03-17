cmake_minimum_required(VERSION 3.15)
project(homm3tools)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/modules/")

# TODO: Remove or set only for Emscripten. Only for debugging Emscripten!
add_compile_options(-g3 -O0)
add_link_options(-sASSERTIONS=1 -sSAFE_HEAP=1 -sSTACK_SIZE=2097152)


add_subdirectory(src/h3)
add_subdirectory(src/lib)

if(NOT EMSCRIPTEN)
    add_subdirectory(src/app)
endif()

enable_testing()
add_subdirectory(tests)
