cmake_minimum_required(VERSION 3.10)

# Nom du projet
project(HelloWorld LANGUAGES CXX)

# Version de C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Ajout de l'exécutable
add_executable(${PROJECT_NAME} main.cpp)
