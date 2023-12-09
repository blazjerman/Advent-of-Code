cmake_minimum_required(VERSION 3.27)

MATH(EXPR stack_size "80000 * 1024 * 1024") # 10000 Mb
set(CMAKE_EXE_LINKER_FLAGS "-Wl,--stack,${stack_size}")

project(untitled1 C)


set(CMAKE_C_STANDARD 11)



add_executable(


        main.c
        Day_1.c
        Day_2.c
        Day_3.c
        main.c
        Utility.c
        Day_4.c
        Day_5.c
        Day_6.c
)
