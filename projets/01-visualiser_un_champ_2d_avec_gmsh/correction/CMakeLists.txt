cmake_minimum_required(VERSION 3.10)
project(GmshExample LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Option : chemin vers l’installation de Gmsh (fourni en ligne de commande avec -Dgmsh_ROOT=...)
set(GMSH_ROOT "" CACHE PATH "Path to Gmsh installation")

# Si root fourni, l'ajouter dans la recherche
if(GMSH_ROOT)
    list(APPEND CMAKE_PREFIX_PATH "${GMSH_ROOT}")
endif()
# Chercher gmsh.h
find_path(GMSH_INCLUDE_DIR gmsh.h
    PATHS
        ${GMSH_ROOT}/include
        /usr/include
        /usr/local/include
)

# Chercher libgmsh
find_library(GMSH_LIBRARY gmsh
    PATHS
        ${gmsh_ROOT}/lib
        /usr/lib
        /usr/local/lib
)

if(NOT GMSH_INCLUDE_DIR OR NOT GMSH_LIBRARY)
    message(FATAL_ERROR "Could not find Gmsh (provide -DGMSH_ROOT=/path/to/gmsh)")
endif()

message(STATUS "Found gmsh include: ${GMSH_INCLUDE_DIR}")
message(STATUS "Found gmsh library: ${GMSH_LIBRARY}")

add_executable(main main.cpp)
target_include_directories(main PRIVATE ${GMSH_INCLUDE_DIR})
target_link_libraries(main PRIVATE ${GMSH_LIBRARY})

add_executable(plot_field plot_field.cpp)
target_include_directories(plot_field PRIVATE ${GMSH_INCLUDE_DIR})
target_link_libraries(plot_field PRIVATE ${GMSH_LIBRARY})

