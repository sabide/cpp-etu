#include "mesh_config.hpp"

#include <iostream>

void refine(MeshConfig& config, double mesh_size)
{
    config.mesh_size = mesh_size;
}

void print_config(const MeshConfig& config)
{
    std::cout << config.output << ": " << config.width << " x "
              << config.height << ", h = " << config.mesh_size << '\n';
}
