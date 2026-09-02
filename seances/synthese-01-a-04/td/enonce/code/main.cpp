#include "gmsh_adapter.hpp"
#include "mesh_config.hpp"

#include <gmsh.h>

int main()
{
    // Point de départ volontairement manuel, remplacé à l'étape 4.
    gmsh::initialize();

    MeshConfig config{};
    print_config(config);
    generate_rectangle(config);

    gmsh::finalize();
}
