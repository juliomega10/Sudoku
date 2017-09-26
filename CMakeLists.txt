cmake_minimum_required(VERSION 3.8)
project(SudokuEd1)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES sudoku.c matrizSudoku.h)
add_executable(SudokuEd1 ${SOURCE_FILES} matrizSudoku.h)