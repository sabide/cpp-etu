#include <vector>
#include <iostream>

// Représentation d'un point 2D
struct Point {
    double x, y;

    Point(double x = 0, double y = 0) : x(x), y(y) {}
};

// Représentation d'un triangle par trois indices de sommets
struct Triangle {
    int v1, v2, v3;

    Triangle(int v1, int v2, int v3) : v1(v1), v2(v2), v3(v3) {}
};

// Classe Mesh pour manipuler le maillage de triangles en 2D
class Mesh {
public:
    // Vecteurs pour stocker les points et les triangles
    std::vector<Point> vertices;
    std::vector<Triangle> triangles;

    // Ajouter un sommet au maillage
    void addVertex(const Point& p) {
        vertices.push_back(p);
    }

    // Ajouter un triangle au maillage (en utilisant les indices des sommets)
    void addTriangle(int v1, int v2, int v3) {
        triangles.push_back(Triangle(v1, v2, v3));
    }

    // Afficher les informations sur le maillage
    void printMesh() const {
        std::cout << "Vertices:\n";
        for (size_t i = 0; i < vertices.size(); ++i) {
            std::cout << i << ": (" << vertices[i].x << ", " << vertices[i].y << ")\n";
        }

        std::cout << "Triangles:\n";
        for (size_t i = 0; i < triangles.size(); ++i) {
            std::cout << i << ": (" << triangles[i].v1 << ", " << triangles[i].v2 << ", " << triangles[i].v3 << ")\n";
        }
    }
};

int main() {
    // Exemple d'utilisation de la classe Mesh en 2D
    Mesh mesh;

    // Ajouter des sommets
    mesh.addVertex(Point(0, 0));
    mesh.addVertex(Point(1, 0));
    mesh.addVertex(Point(0, 1));
    mesh.addVertex(Point(1, 1));

    // Ajouter des triangles
    mesh.addTriangle(0, 1, 2);
    mesh.addTriangle(1, 3, 2);

    // Afficher le maillage
    mesh.printMesh();

    return 0;
}