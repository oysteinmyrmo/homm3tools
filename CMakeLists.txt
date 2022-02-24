cmake_minimum_required(VERSION 3.11)
project(homm3tools)
set(CMAKE_CXX_STANDARD 20)

add_subdirectory(src/h3)
add_subdirectory(src/app)

enable_testing()
add_subdirectory(tests)
