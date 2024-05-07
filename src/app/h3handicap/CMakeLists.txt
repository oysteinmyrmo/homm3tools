if(WIN32)
    project(h3handicap CXX)
endif()

set(H3HANDICAP_SOURCES
    handicap.cpp
)

add_executable(h3handicap ${H3HANDICAP_SOURCES})

install(TARGETS h3handicap)

include(release)
install_release_dir(h3handicap)
