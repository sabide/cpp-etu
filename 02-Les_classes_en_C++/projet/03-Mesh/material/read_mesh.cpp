#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

struct Node {
    int id,label;
    double x, y;
};

struct Element {
    int id;
    std::vector<int> node_ids;
};

void readMshFile(const std::string &filename, std::vector<Node> &nodes, std::vector<Element> &elements) {
    std::ifstream infile(filename);
    std::string line;

    if (!infile.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    while (std::getline(infile, line)) {
        if (line == "$NOD") {
            int numNodes;
            infile >> numNodes;
            nodes.resize(numNodes);

            for (int i = 0; i < numNodes; ++i) {
                Node node;
                infile >> node.id >> node.x >> node.y >> node.label;
                nodes[i] = node;
            }
        } else if (line == "$ELM") {
            int numElements;
            infile >> numElements;

            for (int i = 0; i < numElements; ++i) {
                Element element;
                int element_type;
                infile >> element.id >> element_type;
                int trash;
                if (element_type == 2) {  // Type 2 corresponds to 3-node triangles
                    element.node_ids.resize(3);
                    infile >> trash >> trash >> trash ;
                    for (int j = 0; j < 3; ++j) {
                        infile >> element.node_ids[j];
                    }
                    elements.push_back(element);
                } else {
                    // Skip any elements that are not triangles
                    std::string skip;
                    std::getline(infile, skip);
                }
            }
        }
    }

    infile.close();
}

int main() {
    std::string filename = "square.msh";
    std::vector<Node> nodes;
    std::vector<Element> elements;

    readMshFile(filename, nodes, elements);

    // Afficher les nœuds
    std::cout << "Nodes:" << std::endl;
    for (const auto &node : nodes) {
        std::cout << "ID: " << node.id << ", X: " << node.x << ", Y: " << node.y << ", label: " << node.id << std::endl;
    }

    // Afficher les éléments
    std::cout << "Elements:" << std::endl;
    for (const auto &element : elements) {
        std::cout << "Element ID: " << element.id << ", Node IDs: ";
        for (const auto &node_id : element.node_ids) {
            std::cout << node_id << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
