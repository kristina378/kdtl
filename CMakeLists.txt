cmake_minimum_required(VERSION 3.28)
cmake_policy(SET CMP0048 NEW)
project(
    kdtl
    VERSION "1.0.0"
    LANGUAGES CXX
)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(main "main.cpp")
target_include_directories(main PRIVATE "include")
