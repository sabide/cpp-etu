#ifndef MESH_HPP
#define MESH_HPP

//#include "R2.hpp"
//#include "Vertex.hpp"
#include "Simplex.hpp"
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

class Mesh {
private:
    std::vector<Vertex> nodes_;
    std::vector<Simplex> triangles_;

public:
    // Constructeur par défaut
    Mesh() {}

    // Constructeur avec lecture de fichier
    Mesh(const std::string& filename) {
        readMesh(filename);
    }

void readMesh(const std::string& filename) {
        std::ifstream infile(filename);
        if (!infile.is_open()) {
            std::cerr << "Erreur lors de l'ouverture du fichier: " << filename << std::endl;
            return;
        }

        std::string line;
        bool readingNodes = false;
        bool readingElements = false;

        while (std::getline(infile, line)) {

            if (line == "$NOD") {
                readingNodes = true;
                int numNodes;
                infile >> numNodes; // Lire le nombre de nœuds
                nodes_.reserve(numNodes);
                continue;
            } else if (line == "$ENDNOD") {
                readingNodes = false;
            } else if (line == "$ELM") {
                readingElements = true;
                int numElements;
                infile >> numElements; // Lire le nombre d'éléments
                triangles_.reserve(numElements);
                continue;
            } else if (line == "$ENDELM") {
                readingElements = false;
            }

            if (readingNodes) {
                // Lecture des nœuds
                int index;
                R x, y;
                int label;
                infile >> index >> x >> y >> label;
                Vertex vertex;
                vertex.x() = x;
                vertex.y() = y;
                vertex.label() = label;
                nodes_.push_back(vertex);
            }

            if (readingElements) {
                // Lecture des triangles (éléments)
                int index, type, numTags;
                infile >> index >> type >> numTags;

                // Lire et ignorer les tags
                for (int i = 0; i < numTags; ++i) {
                    int tag;
                    infile >> tag;
                }

                if (type == 2) { // Type 2 correspond à un triangle
                    int n0, n1, n2;
                    infile >> n0 >> n1 >> n2;
                    std::cout << n0 << " "<< n1 << " " << n2 << std::endl;
                    // Les indices des triangles sont basés sur 1 dans le fichier
                    triangles_.emplace_back(nodes_[n0 - 1], nodes_[n1 - 1], nodes_[n2 - 1]);
                } else {
                    std::string skip;
                    std::getline(infile, skip); // Ignorer les autres types d'éléments
                }
            }
        }

        infile.close();
    }


    // Méthode pour obtenir les nœuds
    const std::vector<Vertex>& getNodes() const {
        return nodes_;
    }

    // Méthode pour obtenir les triangles
    const std::vector<Simplex>& getTriangles() const {
        return triangles_;
    }

    // Méthode pour afficher les informations du maillage
    void printMeshInfo() const {
        std::cout << "Nombre de nœuds: " << nodes_.size() << std::endl;
        std::cout << "Nombre de triangles: " << triangles_.size() << std::endl;
    }
};

#endif // MESH_HPP
