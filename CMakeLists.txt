cmake_minimum_required(VERSION 3.26)
project(SFMLproj)

set(CMAKE_CXX_STANDARD 23)

add_executable(SFMLproj main.cpp
        control.cpp
        control.h
        rules.cpp
        rules.h
        ship.cpp
        ship.h
        space_object.cpp
        space_object.h
        asteroid.cpp
        bullet.cpp)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/SFML/lib/cmake/SFML)
find_package(SFML COMPONENTS graphics window network audio REQUIRED)

include_directories(C:/SFML/include)
target_link_libraries(SFMLproj
        sfml-graphics
        sfml-window
        sfml-network
        sfml-audio)
