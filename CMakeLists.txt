cmake_minimum_required(VERSION 3.28)
project(HBench)
set(CMAKE_CXX_STANDARD 20)

include_directories(src)
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

add_executable(tests test/example.cpp)
add_compile_options(tests -ggdb3)
