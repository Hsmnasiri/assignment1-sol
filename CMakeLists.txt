cmake_minimum_required(VERSION 3.24)
project(CSI2372_Assignment1 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(MSVC)
  add_compile_options(/W4 /permissive-)
else()
  add_compile_options(-Wall -Wextra -Wpedantic -Werror=return-type)
endif()

add_library(assignment_objs OBJECT
    src/scope_probe.cpp
    src/temp_file.cpp
    src/string_table.cpp
    src/config.cpp
)

target_include_directories(assignment_objs PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

enable_testing()

# Part A autograde test (2.5 pts)
add_executable(test_partA_scope_probe tests/test_partA_scope_probe.cpp $<TARGET_OBJECTS:assignment_objs>)
target_include_directories(test_partA_scope_probe PRIVATE include)
add_test(NAME PartA_scope_probe COMMAND test_partA_scope_probe)

# Build-only sanity (1.0 pt)
add_executable(test_build_only tests/test_build_only.cpp $<TARGET_OBJECTS:assignment_objs>)
target_include_directories(test_build_only PRIVATE include)
add_test(NAME Build_compile_only COMMAND test_build_only)
