cmake_minimum_required(VERSION 3.23)
project(Lab2 C)

set(CMAKE_C_STANDARD 11)

add_executable(Lab2 main.c queue.c queue.h BreadthFirstSearch.c BreadthFirstSearch.h)
