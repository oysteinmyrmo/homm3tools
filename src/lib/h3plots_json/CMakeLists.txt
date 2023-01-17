include(FetchContent)

FetchContent_Declare(
    json_struct
    GIT_REPOSITORY https://github.com/jorgen/json_struct
    GIT_TAG        bb94319b1d63058d70dad45114a08950f6b0d977
)

FetchContent_MakeAvailable(json_struct)

set(homm3plot_json_files
    json_interface.cpp
    json_interface.h
)

add_library(homm3plots_json STATIC ${homm3plot_json_files})
target_include_directories(homm3plots_json PUBLIC "${json_struct_SOURCE_DIR}/include")
target_link_libraries(homm3plots_json PUBLIC homm3plots)
