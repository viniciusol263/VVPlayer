cmake_minimum_required(VERSION 3.22)
project(VVPlayer VERSION 1.0)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_BUILD_TYPE "Release")

find_package(SFML REQUIRED)

set(VVPLAYER_MAIN main.cpp)

set(VVPLAYER_SRCS VVPlayer.cpp
                  components/WindowManager/WindowManager.cpp)

add_executable(VVPlayer ${VVPLAYER_MAIN} ${VVPLAYER_SRCS})

target_include_directories(VVPlayer PUBLIC components
                                           components/WindowManager
                                           libs)   
target_link_libraries(VVPlayer sfml::sfml)