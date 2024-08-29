#include "Mesh.hpp"

int main() {
    // Lecture d'un maillage à partir d'un fichier


    

    Mesh mesh("square.msh");



    // Affichage des informations du maillage
//    mesh.printMeshInfo();

    // Accès direct aux nœuds et triangles
    const std::vector<Vertex>& nodes = mesh.getNodes();
    const std::vector<Simplex>& triangles = mesh.getTriangles();



    // Afficher les nœuds
    std::cout << "Nœuds:" << std::endl;
    for (const auto& node : nodes) {
        std::cout << node << std::endl;
    }

    // Afficher les triangles
    std::cout << "Triangles:" << std::endl;
    for (const auto& triangle : triangles) {
        std::cout << triangle << std::endl;
    }

    return 0;
}
