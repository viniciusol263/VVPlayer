cmake_minimum_required(VERSION 3.22)
project(VVPlayer VERSION 1.0)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_BUILD_TYPE "Release")

set(VVPLAYER_MAIN main.cpp)

add_executable(VVPlayer ${VVPLAYER_MAIN})