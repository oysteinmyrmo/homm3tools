set(homm3tools_files
    creatures.cpp
    creatures.h
    hero.cpp
    hero.h
    savefile.cpp
    savefile.h
    stats.cpp
    stats.h
    value_reader.h
)

add_library(homm3tools STATIC ${homm3tools_files})
target_link_libraries(homm3tools PRIVATE z)
target_include_directories(homm3tools PUBLIC "${CMAKE_CURRENT_LIST_DIR}/..")
