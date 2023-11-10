cmake_minimum_required(VERSION 3.14)
project(runHW3_problem1_svdcmp C)

set(CMAKE_C_STANDARD 11)

include_directories(
        ${CMAKE_SOURCE_DIR}/../../NRs/ansi/other/
)

add_executable(
        runHW3_problem1_svdcmp
        problem1_svdcmp.c
        ${CMAKE_SOURCE_DIR}/../../NRs/ansi/other/nrutil.c
        ${CMAKE_SOURCE_DIR}/../../NRs/ansi/recipes/svdcmp.c
        ${CMAKE_SOURCE_DIR}/../../NRs/ansi/recipes/svbksb.c
        ${CMAKE_SOURCE_DIR}/../../NRs/ansi/recipes/pythag.c
)

target_link_libraries(runHW3_problem1_svdcmp m)
