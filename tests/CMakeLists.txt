configure_file(test_data.h.in "${CMAKE_BINARY_DIR}/test_data.h")
include_directories("${CMAKE_BINARY_DIR}")

add_executable(test-hero-movement test-hero-movement.cpp)
target_link_libraries(test-hero-movement PRIVATE homm3tools)
add_test(NAME test-hero-movement COMMAND test-hero-movement)

add_executable(test-hero-movement-gigantic test-hero-movement-gigantic.cpp)
target_link_libraries(test-hero-movement-gigantic PRIVATE homm3tools)
add_test(NAME test-hero-movement-gigantic COMMAND test-hero-movement-gigantic)

add_executable(test-creatures test-creatures.cpp)
target_link_libraries(test-creatures PRIVATE homm3tools)
add_test(NAME test-creatures COMMAND test-creatures)

add_executable(test-spell-points test-spell-points.cpp)
target_link_libraries(test-spell-points PRIVATE homm3tools)
add_test(NAME test-spell-points COMMAND test-spell-points)

add_executable(test-primary-skills test-primary-skills.cpp)
target_link_libraries(test-primary-skills PRIVATE homm3tools)
add_test(NAME test-primary-skills COMMAND test-primary-skills)

add_executable(test-hero-player test-hero-player.cpp)
target_link_libraries(test-hero-player PRIVATE homm3tools)
add_test(NAME test-hero-player COMMAND test-hero-player)

add_executable(test-hero-town test-hero-town.cpp)
target_link_libraries(test-hero-town PRIVATE homm3tools)
add_test(NAME test-hero-town COMMAND test-hero-town)

add_executable(test-prison test-prison.cpp)
target_link_libraries(test-prison PRIVATE homm3tools)
add_test(NAME test-prison COMMAND test-prison)

add_executable(test-towns test-towns.cpp)
target_link_libraries(test-towns PRIVATE homm3tools)
add_test(NAME test-towns COMMAND test-towns)

add_executable(test-savefile test-savefile.cpp)
target_link_libraries(test-savefile PRIVATE homm3tools)
add_test(NAME test-savefile COMMAND test-savefile)

add_executable(test-kingdom-army-strength test-kingdom-army-strength.cpp)
target_link_libraries(test-kingdom-army-strength PRIVATE homm3tools)
add_test(NAME test-kingdom-army-strength COMMAND test-kingdom-army-strength)
