set(h3handicap_files
    handicap.cpp
    handicap.h
)

add_library(h3handicap STATIC ${h3handicap_files})
target_include_directories(h3handicap PUBLIC "${CMAKE_CURRENT_LIST_DIR}/..")
target_link_libraries(h3handicap PUBLIC homm3tools)
