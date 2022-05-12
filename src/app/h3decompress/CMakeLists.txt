project(h3decompress)

add_executable(h3decompress main.cpp)
target_link_libraries(h3decompress PRIVATE homm3tools)

install(TARGETS h3decompress)

include(release)
install_release_dir(h3decompress)
