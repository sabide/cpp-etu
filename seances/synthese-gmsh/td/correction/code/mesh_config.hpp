#ifndef MESH_CONFIG_HPP
#define MESH_CONFIG_HPP

#include <string>

class MeshConfig {
public:
    MeshConfig(double width,
               double height,
               double mesh_size,
               std::string output);

    double width() const noexcept;
    double height() const noexcept;
    double mesh_size() const noexcept;
    const std::string& output() const noexcept;

    void set_mesh_size(double mesh_size);
    void set_output(std::string output);

private:
    double width_;
    double height_;
    double mesh_size_;
    std::string output_;
};

void refine(MeshConfig& config, double mesh_size);
void print_config(const MeshConfig& config);

#endif
