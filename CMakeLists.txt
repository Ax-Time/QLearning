cmake_minimum_required(VERSION 3.20)
project(QLearning C)

set(CMAKE_C_STANDARD 11)

add_executable(QLearning main.c qtable.h miscellaneous.h qtable.c miscellaneous.c simple_game.h simple_game.c)
