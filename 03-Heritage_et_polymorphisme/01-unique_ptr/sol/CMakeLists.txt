cmake_minimum_required(VERSION 3.10)

# Nom du projet
project(VecteurMoyenne)

# Définir le standard C++ (C++11 minimum)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Ajouter les exécutables pour les deux versions
add_executable(VecteurBrut vecteur_brut.cpp)
add_executable(VecteurUniquePtr vecteur_unique_ptr.cpp)

