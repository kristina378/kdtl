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

include(cmake/CPM.cmake)
CPMAddPackage("gh:catchorg/Catch2@3.7.1")

add_executable(main "main.cpp")
target_include_directories(main PRIVATE "include")

# Find and create target containing all the tests.
add_executable(tests)
# Find all .text.cpp files in the tests directory.
file(GLOB_RECURSE test_source_files ${PROJECT_SOURCE_DIR}/tests/ *.test.cpp)
# Add those files to the `tests` target.
target_sources(tests PRIVATE ${test_source_files})

# For debug purposes only, print the list of test files.
message(STATUS "test_source_files:")
foreach(item IN LISTS test_source_files)
    message(STATUS " - ${item}")
endforeach()

target_link_libraries(
    tests
PRIVATE
    Catch2::Catch2WithMain
)
target_include_directories(tests PRIVATE "include")

# Magic to make Catch2 play nice with CTest.
include(CTest)
list(APPEND CMAKE_MODULE_PATH ${Catch2_SOURCE_DIR}/extras)
include(Catch)
catch_discover_tests(tests)
