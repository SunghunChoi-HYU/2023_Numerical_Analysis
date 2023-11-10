cmake_minimum_required(VERSION 3.14)
project(runHW3_problem1_gaussj C)

set(CMAKE_C_STANDARD 11)

include_directories(
        ${CMAKE_SOURCE_DIR}/../../NRs/ansi/other/
)

add_executable(
        runHW3_problem1_gaussj
        problem1_gaussj.c
        ${CMAKE_SOURCE_DIR}/../../NRs/ansi/other/nrutil.c
        ${CMAKE_SOURCE_DIR}/../../NRs/ansi/recipes/gaussj.c
)
