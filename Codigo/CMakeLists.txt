cmake_minimum_required(VERSION 3.25)
project(Codigo C)

set(CMAKE_C_STANDARD 99)

add_executable(Codigo main.c Menu.c Menu.h Utils.c Utils.h Paragem.c Paragem.h Linha.c Linha.h Percurso.c Percurso.h)
