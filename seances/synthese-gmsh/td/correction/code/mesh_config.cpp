#include "mesh_config.hpp"

#include <iostream>
#include <stdexcept>
#include <utility>

namespace {
double positive(double value, const char* name)
{
    if (value <= 0.0) {
        throw std::invalid_argument{std::string{name} + " must be positive"};
    }
    return value;
}

std::string non_empty(std::string value)
{
    if (value.empty()) {
        throw std::invalid_argument{"output must not be empty"};
    }
    return value;
}
}

MeshConfig::MeshConfig(double width,
                       double height,
                       double mesh_size,
                       std::string output)
    : width_{positive(width, "width")},
      height_{positive(height, "height")},
      mesh_size_{positive(mesh_size, "mesh_size")},
      output_{non_empty(std::move(output))}
{}

double MeshConfig::width() const noexcept
{
    return width_;
}

double MeshConfig::height() const noexcept
{
    return height_;
}

double MeshConfig::mesh_size() const noexcept
{
    return mesh_size_;
}

const std::string& MeshConfig::output() const noexcept
{
    return output_;
}

void MeshConfig::set_mesh_size(double mesh_size)
{
    mesh_size_ = positive(mesh_size, "mesh_size");
}

void MeshConfig::set_output(std::string output)
{
    output_ = non_empty(std::move(output));
}

void refine(MeshConfig& config, double mesh_size)
{
    config.set_mesh_size(mesh_size);
}

void print_config(const MeshConfig& config)
{
    std::cout << config.output() << ": " << config.width() << " x "
              << config.height() << ", h = " << config.mesh_size() << '\n';
}
