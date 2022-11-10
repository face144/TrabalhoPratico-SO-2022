cmake_minimum_required(VERSION 3.23)
project(SOBay_Frontend C)

set(CMAKE_C_STANDARD 23)

add_executable(SOBay_Frontend main.c Comandos.c Comandos.h SOBay.c SOBay.h Interface.c Interface.h)
