cmake_minimum_required(VERSION 3.28)
project(CompetitiveProgramming)

set(PROJECT_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/src)

find_package(GTest REQUIRED)

enable_testing()

add_subdirectory(test)