cmake_minimum_required(VERSION 3.17)
project(newProjectOS C)

set(CMAKE_C_STANDARD 99)

add_executable(newProjectOS main.c utils.c utils.h functions.c functions.h ListeBlock.c ListeBlock.h)