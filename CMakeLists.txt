cmake_minimum_required(VERSION 3.12)

project(MiniGame)

set(CMAKE_CXX_STANDARD 11)

find_package(SFML COMPONENTS system window graphics network audio REQUIRED)

add_executable(
    MiniGame
    MiniGame/MiniGame.cpp
    MiniGame/Engine/Utils.cpp
)

target_link_libraries(MiniGame sfml-system sfml-window sfml-network sfml-graphics sfml-audio)