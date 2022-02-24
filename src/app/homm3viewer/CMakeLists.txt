project(homm3viewer)

include(FetchContent)
FetchContent_Declare(
    imgui
    GIT_REPOSITORY https://github.com/ocornut/imgui.git
    GIT_TAG        c71a50deb5ddf1ea386b91e60fa2e4a26d080074 # v1.87
)
FetchContent_MakeAvailable(imgui)

add_executable(homm3viewer main.cpp)
target_include_directories(homm3viewer PRIVATE "${imgui_SOURCE_DIR}")
