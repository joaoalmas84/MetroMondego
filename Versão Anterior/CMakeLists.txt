cmake_minimum_required(VERSION 3.25)
project(Codigo C)

set(CMAKE_C_STANDARD 99)

add_executable(Codigo main.c Paragem.c Paragem.h Linha.c Linha.h utils.h utils.c)
