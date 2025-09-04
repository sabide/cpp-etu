cmake_minimum_required(VERSION 3.10)

# Nom du projet
project(SolveursLineaires)

# Standard C++ requis
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Ajouter les fichiers sources
add_executable(SolveursLineaires
    main.cpp
    SolveurBase.hpp
    CG.hpp
    Jacobi.hpp
)

# Options de compilation (facultatif)
# add_compile_options(-Wall -Wextra -Wpedantic)

# Déclaration des include directories (facultatif)
# target_include_directories(SolveursLineaires PUBLIC ${PROJECT_SOURCE_DIR}/include)

