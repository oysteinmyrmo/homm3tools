project(homm3decompress)

add_executable(homm3decompress main.cpp)
target_link_libraries(homm3decompress PRIVATE homm3tools)
