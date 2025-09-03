cmake_minimum_required(VERSION 3.10)
project(PointExample LANGUAGES CXX)

# Standard C++
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Inclure le dossier courant pour trouver point.h

# Ajout de l'exécutable
add_executable( main
    main.cpp
    point.cpp
)

target_include_directories(main PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})


