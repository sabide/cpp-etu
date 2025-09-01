cmake_minimum_required(VERSION 3.10)
project(Exercice2)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Création de l’exécutable à partir de plusieurs sources
add_executable(mon_exe main.cpp fonctions.cpp)

