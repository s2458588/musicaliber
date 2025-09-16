cmake_minimum_required(VERSION 4.0.0)
project(musicaliber LANGUAGES CXX)

# set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ADD_LIBRARY(musicaliber main.cpp dir.h dir.cpp compare.cpp compare.h)
ADD_EXECUTABLE(run
main.cpp
dir.cpp
compare.cpp
)

TARGET_LINK_LIBRARIES(run musicaliber)

## TODO: Fix make "cannot find -musicaliber
