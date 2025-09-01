cmake_minimum_required(VERSION 3.10)   # version minimale
project(Exercice1)                     # nom du projet

set(CMAKE_CXX_STANDARD 11)             # utiliser le standard C++11
set(CMAKE_CXX_STANDARD_REQUIRED True)  # obligatoire

add_executable(mon_exe main.cpp)       # compiler main.cpp en mon_exe

