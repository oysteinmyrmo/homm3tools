if(WIN32)
    project(h3viewer CXX)
elseif(APPLE)
    project(h3viewer CXX OBJCXX OBJC)
endif()

include(FetchContent)

FetchContent_Declare(
    imgui
    GIT_REPOSITORY https://github.com/ocornut/imgui.git
    GIT_TAG        c71a50deb5ddf1ea386b91e60fa2e4a26d080074 # v1.87
)
FetchContent_Declare(
    glfw
    GIT_REPOSITORY https://github.com/glfw/glfw.git
    GIT_TAG        7d5a16ce714f0b5f4efa3262de22e4d948851525 # v3.3.6
)
FetchContent_Declare(
    implot
    GIT_REPOSITORY https://github.com/epezent/implot
    GIT_TAG        b47c8bacdbc78bc521691f70666f13924bb522ab # v0.13
)

FetchContent_MakeAvailable(imgui implot glfw)

set(IMGUI_SOURCES
    ${imgui_SOURCE_DIR}/imgui.cpp
    ${imgui_SOURCE_DIR}/imgui_demo.cpp
    ${imgui_SOURCE_DIR}/imgui_draw.cpp
    ${imgui_SOURCE_DIR}/imgui_tables.cpp
    ${imgui_SOURCE_DIR}/imgui_widgets.cpp
    ${imgui_SOURCE_DIR}/backends/imgui_impl_glfw.cpp
)

set(IMPLOT_SOURCES
    ${implot_SOURCE_DIR}/implot.cpp
    ${implot_SOURCE_DIR}/implot_demo.cpp
    ${implot_SOURCE_DIR}/implot_items.cpp
)

set(H3VIEWER_SOURCES
    draw_plots.cpp
    draw_plots.h
    savefile_series.cpp
    savefile_series.h
    thieves_guild.cpp
    thieves_guild.h
)

if(WIN32)
    list(APPEND IMGUI_SOURCES ${imgui_SOURCE_DIR}/backends/imgui_impl_opengl3.cpp)
    list(APPEND H3VIEWER_SOURCES main_opengl3.cpp)
elseif(APPLE)
    enable_language(OBJCXX)
    list(APPEND IMGUI_SOURCES ${imgui_SOURCE_DIR}/backends/imgui_impl_metal.mm)
    list(APPEND H3VIEWER_SOURCES main_metal.mm)
    set(CMAKE_OBJCXX_FLAGS "${CMAKE_OBJCXX_FLAGS} -ObjC++ -fobjc-weak -fobjc-arc")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fobjc-weak")
endif()

list(APPEND H3VIEWER_SOURCES ${IMGUI_SOURCES} ${IMPLOT_SOURCES})
add_executable(h3viewer ${H3VIEWER_SOURCES})

target_include_directories(h3viewer PRIVATE
    ${HOMM3TOOLS_APP_DIR}
    ${imgui_SOURCE_DIR}
    ${imgui_SOURCE_DIR}/backends
    ${implot_SOURCE_DIR}
    ${glfw_SOURCE_DIR}/include
)

target_link_libraries(h3viewer PUBLIC
    glfw
    homm3plots
)

if(WIN32)
    target_link_libraries(h3viewer PRIVATE
        opengl32.lib
        gdi32.lib
        shell32.lib
    )
elseif(APPLE)
    target_link_libraries(h3viewer PRIVATE
        "-framework Metal"
        "-framework MetalKit"
        "-framework Cocoa"
        "-framework IOKit"
        "-framework CoreVideo"
        "-framework QuartzCore"
    )
endif()

install(TARGETS h3viewer)

include(release)
install_release_dir(h3viewer)
