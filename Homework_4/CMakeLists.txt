cmake_minimum_required(VERSION 3.14)
project(runHW4 C)

set(CMAKE_C_STANDARD 11)

include_directories(
        ${CMAKE_SOURCE_DIR}/../../NRs/ansi/other/
)

add_executable(
        runHW4
        main.c
        ${CMAKE_SOURCE_DIR}/../NRs/ansi/other/nrutil.c
        ${CMAKE_SOURCE_DIR}/../NRs/ansi/recipes/ran0.c
        ${CMAKE_SOURCE_DIR}/../NRs/ansi/recipes/ran1.c
        ${CMAKE_SOURCE_DIR}/../NRs/ansi/recipes/gasdev.c
)

target_link_libraries(runHW4 m)

