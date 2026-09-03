#include "gmsh_adapter.hpp"

#include <gmsh.h>

void generate_rectangle(const MeshConfig& config)
{
    gmsh::clear();
    gmsh::model::add("rectangle");

    const double h{config.mesh_size()};
    const double width{config.width()};
    const double height{config.height()};

    const int p1{gmsh::model::geo::addPoint(0.0, 0.0, 0.0, h)};
    const int p2{gmsh::model::geo::addPoint(width, 0.0, 0.0, h)};
    const int p3{gmsh::model::geo::addPoint(width, height, 0.0, h)};
    const int p4{gmsh::model::geo::addPoint(0.0, height, 0.0, h)};

    const int l1{gmsh::model::geo::addLine(p1, p2)};
    const int l2{gmsh::model::geo::addLine(p2, p3)};
    const int l3{gmsh::model::geo::addLine(p3, p4)};
    const int l4{gmsh::model::geo::addLine(p4, p1)};
    const int loop{gmsh::model::geo::addCurveLoop({l1, l2, l3, l4})};

    gmsh::model::geo::addPlaneSurface({loop});
    gmsh::model::geo::synchronize();
    gmsh::model::mesh::generate(2);
    gmsh::write(config.output());
}
