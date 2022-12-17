set(homm3plot_files
#    json.cpp
#    json.h
    player.cpp
    player.h
    plots.cpp
    plots.h
    plots/artifacts.cpp
    plots/artifacts.h
    plots/best_creature.cpp
    plots/best_creature.h
    plots/experience.cpp
    plots/experience.h
    plots/gold.cpp
    plots/gold.h
    plots/hero_count.cpp
    plots/hero_count.h
    plots/kingdom_army_strength.cpp
    plots/kingdom_army_strength.h
    plots/plot.cpp
    plots/plot.h
    plots/resources.cpp
    plots/resources.h
    plots/town_count.cpp
    plots/town_count.h
    savefile_series.cpp
    savefile_series.h
    settings.h
    settings.cpp
)

add_library(homm3plots STATIC ${homm3plot_files})
target_include_directories(homm3plots PUBLIC "${CMAKE_CURRENT_LIST_DIR}/..")
target_link_libraries(homm3plots PUBLIC homm3tools)





#include(FetchContent)
#
#FetchContent_Declare(
#    json_struct
#    GIT_REPOSITORY https://github.com/jorgen/json_struct
#    GIT_TAG        bb94319b1d63058d70dad45114a08950f6b0d977
#)
#
#FetchContent_MakeAvailable(json_struct)
#
#target_link_libraries(homm3plots PUBLIC homm3tools json_struct)
