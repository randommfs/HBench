cmake_minimum_required(VERSION 3.28)
project(HBench)

include_directories(src)
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

add_executable(tests test/main.cpp)