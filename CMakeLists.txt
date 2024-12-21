cmake_minimum_required(VERSION 3.22)
project(VVPlayer VERSION 1.0)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_BUILD_TYPE "Release")

find_package(SDL2 REQUIRED)

set(VVPLAYER_MAIN main.cpp)

add_executable(VVPlayer ${VVPLAYER_MAIN})
target_link_libraries(VVPlayer SDL2::SDL2main)