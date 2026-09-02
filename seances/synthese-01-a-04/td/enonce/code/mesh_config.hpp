#ifndef MESH_CONFIG_HPP
#define MESH_CONFIG_HPP

#include <string>

// Point de départ du TD : cette structure publique sera transformée en classe.
struct MeshConfig {
    double width{1.0};
    double height{1.0};
    double mesh_size{0.2};
    std::string output{"mesh.msh"};
};

void refine(MeshConfig& config, double mesh_size);
void print_config(const MeshConfig& config);

#endif
