cmake_minimum_required(VERSION 3.8)
project(sem_2)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp funkce.h funkce.cpp out.h out.cpp calculation.cpp calcilation.h)
add_executable(sem_2 ${SOURCE_FILES})