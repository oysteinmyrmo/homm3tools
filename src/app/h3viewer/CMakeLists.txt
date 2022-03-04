# Inspired by https://github.com/ocornut/imgui/blob/master/examples/example_glfw_metal/Makefile
project(h3viewer)
enable_language(OBJCXX)
include(FetchContent)

set(CMAKE_OBJCXX_FLAGS "${CMAKE_OBJCXX_FLAGS} -ObjC++ -fobjc-weak -fobjc-arc")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fobjc-weak")

FetchContent_Declare(
    imgui
    GIT_REPOSITORY https://github.com/ocornut/imgui.git
    GIT_TAG        c71a50deb5ddf1ea386b91e60fa2e4a26d080074 # v1.87
)
FetchContent_MakeAvailable(imgui)
set(IMGUI_DIR "${imgui_SOURCE_DIR}")

set(IMGUI_SOURCES
    ${IMGUI_DIR}/imgui.cpp
    ${IMGUI_DIR}/imgui_demo.cpp
    ${IMGUI_DIR}/imgui_draw.cpp
    ${IMGUI_DIR}/imgui_tables.cpp
    ${IMGUI_DIR}/imgui_widgets.cpp
    ${IMGUI_DIR}/backends/imgui_impl_glfw.cpp
    ${IMGUI_DIR}/backends/imgui_impl_metal.mm
)

FetchContent_Declare(
    glfw
    GIT_REPOSITORY https://github.com/glfw/glfw.git
    GIT_TAG        7d5a16ce714f0b5f4efa3262de22e4d948851525 # v3.3.6
)
FetchContent_MakeAvailable(glfw)
set(GLFW_DIR "${glfw_SOURCE_DIR}")

# ImGui developer suggests using ImPlot here: https://github.com/ocornut/imgui/issues/632#issuecomment-738946252
FetchContent_Declare(
    implot
    GIT_REPOSITORY https://github.com/epezent/implot
    GIT_TAG        b47c8bacdbc78bc521691f70666f13924bb522ab # v0.13
)
FetchContent_MakeAvailable(implot)
set(IMPLOT_DIR "${implot_SOURCE_DIR}")

set(IMPLOT_SOURCES
    ${IMPLOT_DIR}/implot.cpp
    ${IMPLOT_DIR}/implot_demo.cpp
    ${IMPLOT_DIR}/implot_items.cpp
)

add_executable(h3viewer
    ${IMGUI_SOURCES}
    ${IMPLOT_SOURCES}
    player.cpp
    player.h
    plots/kingdom_army_strength.cpp
    plots/kingdom_army_strength.h
    savefile_series.cpp
    savefile_series.h
    thieves_guild.cpp
    thieves_guild.h
    main.mm)

target_include_directories(h3viewer PRIVATE
    ${HOMM3TOOLS_APP_DIR}
    ${IMGUI_DIR}
    ${IMGUI_DIR}/backends
    ${IMPLOT_DIR}
    ${GLFW_DIR}/include
)

target_link_libraries(h3viewer PRIVATE
    "-framework Metal"
    "-framework MetalKit"
    "-framework Cocoa"
    "-framework IOKit"
    "-framework CoreVideo"
    "-framework QuartzCore"
    glfw
    homm3tools
)
