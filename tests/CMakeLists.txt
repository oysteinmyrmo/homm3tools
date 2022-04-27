configure_file(test_data.h.in "${CMAKE_BINARY_DIR}/test_data.h")
include_directories("${CMAKE_BINARY_DIR}")

include(FetchContent)

FetchContent_Declare(
    catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG        216713a4066b79d9803d374f261ccb30c0fb451f # v2.13.8
)

FetchContent_MakeAvailable(catch2)
set(CATCH2_DIR "${catch2_SOURCE_DIR}")

add_executable(homm3tests
    ${CATCH2_DIR}/src/catch_with_main.cpp
    test-creatures.cpp
    test-hero-experience.cpp
    test-hero-movement.cpp
    test-hero-movement-gigantic.cpp
    test-hero-player.cpp
    test-hero-town.cpp
    test-kingdom-army-strength.cpp
    test-primary-skills.cpp
    test-prison.cpp
    test-savefile.cpp
    test-secondary-skills.cpp
    test-spell-points.cpp
    test-spells.cpp
    test-towns.cpp
)

target_link_libraries(homm3tests PRIVATE homm3tools)
target_include_directories(homm3tests PRIVATE ${CATCH2_DIR}/single_include)
add_test(NAME homm3tests COMMAND homm3tests)
