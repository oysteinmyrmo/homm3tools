configure_file(test_data.h.in "${CMAKE_BINARY_DIR}/test_data.h")
include_directories("${CMAKE_BINARY_DIR}")

include(FetchContent)

FetchContent_Declare(
    catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG        216713a4066b79d9803d374f261ccb30c0fb451f # v2.13.8
)

FetchContent_MakeAvailable(catch2)

add_subdirectory(h3)
