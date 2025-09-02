#include <gmsh.h>
#include <vector>
#include <cmath>
#include <iostream>

int main(int argc, char **argv) {
    gmsh::initialize(argc, argv);
    gmsh::model::add("carre");

    // Créer un carré 1x1
    double lc = 0.01;
    gmsh::model::geo::addPoint(0, 0, 0, lc, 1);
    gmsh::model::geo::addPoint(1, 0, 0, lc, 2);
    gmsh::model::geo::addPoint(1, 1, 0, lc, 3);
    gmsh::model::geo::addPoint(0, 1, 0, lc, 4);

    gmsh::model::geo::addLine(1, 2, 1);
    gmsh::model::geo::addLine(2, 3, 2);
    gmsh::model::geo::addLine(3, 4, 3);
    gmsh::model::geo::addLine(4, 1, 4);

    gmsh::model::geo::addCurveLoop({1, 2, 3, 4}, 1);
    gmsh::model::geo::addPlaneSurface({1}, 1);

    gmsh::model::geo::synchronize();
    gmsh::model::mesh::generate(2);

    // Récupérer tous les noeuds
    std::vector<std::size_t> nodeTags;
    std::vector<double> coord, param;
    gmsh::model::mesh::getNodes(nodeTags, coord, param);

    // Créer un champ scalaire f(x,y) = sin(pi x) * sin(pi y)
    std::vector<std::vector<double>> data;
    for(size_t i = 0; i < nodeTags.size(); ++i) {
        double x = coord[3*i];
        double y = coord[3*i+1];
        double val = std::sin(M_PI * x) * std::sin(M_PI * y);
        data.push_back({val}); // un vecteur par noeud
    }

    // Créer une vue et ajouter les données
    int viewTag = gmsh::view::add("MyField");
    gmsh::view::addModelData(viewTag, 0, "carre", "NodeData", nodeTags, data);

    // Lancer l'interface graphique
//    gmsh::fltk::run();
    //
    //    gmsh::write("champ.msh");
    gmsh::view::write(viewTag, "champ.msh");   // format .msh
    gmsh::view::write(viewTag, "champ.pos");   // format .pos Gmsh classique
    gmsh::finalize();
    return 0;
}
