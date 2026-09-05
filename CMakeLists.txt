cmake_minimum_required(VERSION 3.16)
project(SolitaireTis100Solver C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

include_directories(.)

add_executable(SolitaireTis100Solver
        main.c
        utils.c)
