cmake_minimum_required(VERSION 3.10)

# Nom du projet
project(RectangleExample)

# Spécifiez le standard C++ à utiliser
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Ajoutez les fichiers sources au projet
add_executable(RectangleExample main.cpp rectangle.cpp)

