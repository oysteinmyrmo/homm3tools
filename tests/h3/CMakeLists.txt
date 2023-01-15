add_executable(homm3tests
    ${catch2_SOURCE_DIR}/src/catch_with_main.cpp
    test-artifacts.cpp
    test-creatures.cpp
    test-hero-experience.cpp
    test-hero-movement.cpp
    test-hero-movement-gigantic.cpp
    test-hero-player.cpp
    test-hero-town.cpp
    test-kingdom-army-strength.cpp
    test-primary-skills.cpp
    test-prison.cpp
    test-resources.cpp
    test-savefile.cpp
    test-secondary-skills.cpp
    test-spell-points.cpp
    test-spells.cpp
    test-towns.cpp
    test-town-names.cpp
)

target_link_libraries(homm3tests PRIVATE homm3tools)
target_include_directories(homm3tests PRIVATE ${catch2_SOURCE_DIR}/single_include)
add_test(NAME homm3tests COMMAND homm3tests)
