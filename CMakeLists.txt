cmake_minimum_required(VERSION 3.8)
project(Sudoku)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        matrizSudoku.h
        sudoku.c)

add_executable(Sudoku ${SOURCE_FILES})