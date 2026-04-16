cmake_minimum_required(VERSION 3.15...4.0.0)
project(cpp_experiments LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(experiments/timer)
add_subdirectory(experiments/scheduler)