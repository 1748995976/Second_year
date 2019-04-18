cmake_minimum_required(VERSION 3.12)
project(GameBaseOnSat C)

set(CMAKE_C_STANDARD 99)

add_executable(GameBaseOnSat main.c readandselect.h readandselect.c dpll.c dpll.h OutPutResult.h OutPutResult.c sudoku.h sudoku.c)