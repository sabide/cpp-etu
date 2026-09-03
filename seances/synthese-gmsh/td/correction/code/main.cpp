#include "gmsh_adapter.hpp"
#include "gmsh_session.hpp"
#include "mesh_config.hpp"

#include <cassert>

int main()
{
    GmshSession session;

    MeshConfig coarse{2.0, 1.0, 0.25, "coarse.msh"};
    MeshConfig fine{coarse};
    refine(fine, 0.08);
    fine.set_output("fine.msh");

    assert(coarse.mesh_size() == 0.25);
    assert(coarse.output() == "coarse.msh");
    assert(fine.mesh_size() == 0.08);
    assert(fine.output() == "fine.msh");

    print_config(coarse);
    print_config(fine);
    generate_rectangle(coarse);
    generate_rectangle(fine);
}
