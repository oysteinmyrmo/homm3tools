add_executable(h3plotstests
    ${catch2_SOURCE_DIR}/src/catch_with_main.cpp
    test-json-and-cpp-plots-equal.cpp
)

target_link_libraries(h3plotstests PRIVATE homm3plots homm3plots_json)
target_include_directories(h3plotstests PRIVATE ${catch2_SOURCE_DIR}/single_include)
add_test(NAME h3plotstests COMMAND h3plotstests)
