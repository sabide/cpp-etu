cmake_minimum_required(VERSION 3.10)
project(Exercice3)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Création d'une librairie statique (libfonctions.a)
add_library(fonctions STATIC fonctions.cpp)

# Création de l’exécutable
add_executable(mon_exe main.cpp)

# Lier l’exécutable avec la librairie
target_link_libraries(mon_exe PRIVATE fonctions)

