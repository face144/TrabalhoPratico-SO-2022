cmake_minimum_required(VERSION 3.23)
project(SOBay_Backend C)

set(CMAKE_C_STANDARD 23)

add_executable(SOBay_Backend main.c LoginHandler.c LoginHandler.h SOBay.c SOBay.h Comandos.c Comandos.h Promotor.c Promotor.h Itens.c Itens.h)
