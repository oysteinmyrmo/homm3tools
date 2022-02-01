file(COPY test_data DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

add_executable(test-hero-movement test-hero-movement.cpp)
target_link_libraries(test-hero-movement PRIVATE homm3tools)
add_test(NAME test-hero-movement COMMAND test-hero-movement)
