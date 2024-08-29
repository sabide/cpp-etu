Voici un sujet avec correction en Markdown pour travailler sur la manipulation de maillages de triangles en 2D en C++.

## Sujet : Manipulation de Maillages de Triangles en 2D avec C++

### Objectif
L'objectif de cet exercice est de créer une classe en C++ permettant de manipuler un maillage composé de triangles en 2D. Vous devrez implémenter une classe `Mesh` qui permettra d'ajouter des points et des triangles, puis d'afficher les informations sur le maillage.

### Consignes

1. Créez une structure `Point` pour représenter un point en 2D avec des coordonnées `x` et `y`.
2. Créez une structure `Triangle` pour représenter un triangle défini par trois indices de sommets.
3. Implémentez une classe `Mesh` qui contient :
   - Un vecteur de `Point` pour stocker les sommets.
   - Un vecteur de `Triangle` pour stocker les triangles.
   - Une méthode `addVertex` pour ajouter un sommet au maillage.
   - Une méthode `addTriangle` pour ajouter un triangle au maillage.
   - Une méthode `printMesh` pour afficher les sommets et les triangles du maillage.

4. Dans le `main`, créez un maillage simple en ajoutant des sommets et des triangles, puis affichez le maillage.

### Exemple d'Exécution

Voici ce que votre programme devrait afficher :

```
Vertices:
0: (0, 0)
1: (1, 0)
2: (0, 1)
3: (1, 1)
Triangles:
0: (0, 1, 2)
1: (1, 3, 2)
```

---

## Correction

### Implémentation en C++

```cpp
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
```

### Explication

- **Point** : Structure qui représente un point 2D avec des coordonnées `x` et `y`.
- **Triangle** : Structure qui représente un triangle défini par trois indices de sommets.
- **Mesh** : Classe qui contient deux vecteurs, `vertices` pour les points et `triangles` pour les triangles, ainsi que des méthodes pour ajouter des points, ajouter des triangles, et afficher le maillage.
- **main** : Fonction principale qui crée un objet `Mesh`, ajoute des points et des triangles, puis affiche le maillage.

Ce code vous permet de manipuler un maillage de triangles en 2D et d'en visualiser la structure via la méthode `printMesh`.