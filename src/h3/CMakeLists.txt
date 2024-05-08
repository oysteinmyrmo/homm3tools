set(homm3tools_files
    artifacts.cpp
    artifacts.h
    creatures.cpp
    creatures.h
    difficulty.cpp
    difficulty.h
    hero.cpp
    hero.h
    packed_structs.h
    player.cpp
    player.h
    savefile.cpp
    savefile.h
    secondary_skills.cpp
    secondary_skills.h
    spells.cpp
    spells.h
    stats.cpp
    stats.h
    town.cpp
    town.h
    value_reader.cpp
    value_reader.h
)

add_library(homm3tools STATIC ${homm3tools_files})
target_include_directories(homm3tools PUBLIC "${CMAKE_CURRENT_LIST_DIR}/..")

find_package(ZLIB)

if(ZLIB_FOUND)
    target_link_libraries(homm3tools PRIVATE z)
else()

    include(FetchContent)

    FetchContent_Declare(
        zlib
        GIT_REPOSITORY https://github.com/madler/zlib.git
        GIT_TAG        cacf7f1d4e3d44d871b605da3b647f07d718623f # v1.2.11
    )

    FetchContent_MakeAvailable(zlib)

    # zlib renames zconf.h to zconf.h.included for us, which makes the zconf.h file missing
    # when including zlib.h. To remedy this, we simply rename back if it is renamed by zlib.
    # This is stupid.
    if(EXISTS ${zlib_SOURCE_DIR}/zconf.h.included)
        message(STATUS "Renaming ${zlib_SOURCE_DIR}/zconf.h.included back to zconf.h to make zlib compile.")
        file(RENAME ${zlib_SOURCE_DIR}/zconf.h.included ${zlib_SOURCE_DIR}/zconf.h)
    endif()

    target_link_libraries(homm3tools PRIVATE zlibstatic)
    target_include_directories(homm3tools PRIVATE "${zlib_SOURCE_DIR}")
endif()
