cmake_minimum_required(VERSION 4.0.0)
project(musicaliber)

ADD_LIBRARY(musicaliber main.cpp dir.h dir.cpp)
ADD_EXECUTABLE(run main.cpp)
TARGET_LINK_LIBRARIES(run musicaliber)
