file(COPY test_data DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

add_executable(test-hero-movement test-hero-movement.cpp)
target_link_libraries(test-hero-movement PRIVATE homm3tools)
add_test(NAME test-hero-movement COMMAND test-hero-movement)

add_executable(test-hero-movement-gigantic test-hero-movement-gigantic.cpp)
target_link_libraries(test-hero-movement-gigantic PRIVATE homm3tools)
add_test(NAME test-hero-movement-gigantic COMMAND test-hero-movement-gigantic)
