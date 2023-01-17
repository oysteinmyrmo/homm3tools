cmake_minimum_required(VERSION 3.15)
project(homm3tools)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/modules/")

add_subdirectory(src/h3)
add_subdirectory(src/lib)
add_subdirectory(src/app)

enable_testing()
add_subdirectory(tests)
