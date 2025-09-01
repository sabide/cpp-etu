cmake_minimum_required(VERSION 3.10)
project(DeriveeSeconde)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Trois exécutables indépendants
add_executable(derivee_pointers main_pointers.cpp)
add_executable(derivee_array main_array.cpp)
add_executable(derivee_vector main_vector.cpp)

