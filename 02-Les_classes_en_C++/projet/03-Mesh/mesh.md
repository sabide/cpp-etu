# Implémentation de la classe `Mesh` avec lecture du maillage Gmsh (format MSH1)

## Objectif

L'objectif de cet exercice est d'implémenter une classe `Mesh` en C++ qui permet de lire, stocker, et manipuler un maillage 2D à partir d'un fichier Gmsh au format MSH1. Le maillage sera composé de nœuds (points) et de triangles (éléments). Vous utiliserez les classes `R2`, `Vertex`, et une routine externe fournie pour la lecture du fichier.

## Classes fournies

### Classe `R2`

La classe `R2` représente un vecteur 2D avec des coordonnées `x` et `y`. Elle inclut divers opérateurs pour manipuler les vecteurs 2D.

### Classe `Vertex`

La classe `Vertex` est une sous-classe de `R2` qui ajoute un label entier à chaque sommet.

```cpp
class Vertex : public R2 {
private:
    int label_;

public:
    Vertex() : label_(0) {}
    int& label() { return label_; }
    const int& label() const { return label_; }

    Vertex& operator=(R2 n) {
        x() = n.x();
        y() = n.y();
        label_ = 0;
        return *this;
    }

    Vertex& operator=(Vertex& n) {
        x() = n.x();
        y() = n.y();
        label_ = n.label();
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& os, const Vertex& P) {
        os << P.x() << ' ' << P.y() << ' ' << P.label();
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Vertex& P) {
        is >> P.x() >> P.y() >> P.label();
        return is;
    }
};
```

### Classe `Simplex`

La classe `Simplex` modélise un triangle à partir de trois sommets `Vertex`. Elle inclut des méthodes pour calculer des propriétés géométriques comme l'aire.

```cpp
class Simplex {
private:
    static const int nbv = 3;
    Vertex vertices_[nbv];

public:
    Simplex() {}
    Simplex(const Vertex& n0, const Vertex& n1, const Vertex& n2) {
        vertices_[0] = n0;
        vertices_[1] = n1;
        vertices_[2] = n2;
    }

    Vertex& operator[](int i) {
        assert(i >= 0 && i < nbv);
        return vertices_[i];
    }

    const Vertex& operator[](int i) const {
        assert(i >= 0 && i < nbv);
        return vertices_[i];
    }

    friend std::ostream& operator<<(std::ostream& os, const Simplex& S) {
        os << S[0] << std::endl;
        os << S[1] << std::endl;
        os << S[2] << std::endl;
        return os;
    }
};
```

## Spécifications de la classe `Mesh`

### Membres privés

- `std::vector<Vertex> nodes_` : un vecteur contenant les sommets du maillage.
- `std::vector<Simplex> triangles_` : un vecteur contenant les triangles du maillage.

### Constructeurs

1. **Constructeur par défaut :**
   ```cpp
   Mesh();
   ```
   Ce constructeur initialise un maillage vide.

2. **Constructeur avec lecture de fichier :**
   ```cpp
   Mesh(const std::string& filename);
   ```
   Ce constructeur initialise le maillage en lisant les données de nœuds et de triangles à partir d'un fichier Gmsh au format MSH1.

### Méthodes publiques

- **Lecture des données de maillage :**
  Implémentez une méthode pour lire les données d'un fichier et remplir les vecteurs `nodes_` et `triangles_` :
  ```cpp
  void readMesh(const std::string& filename);
  ```

- **Accès aux nœuds et aux triangles :**
  Implémentez des méthodes pour accéder aux nœuds et aux triangles du maillage :
  ```cpp
  const std::vector<Vertex>& getNodes() const;
  const std::vector<Simplex>& getTriangles() const;
  ```

- **Affichage des informations du maillage :**
  Implémentez une méthode pour afficher les informations sur les nœuds et les triangles :
  ```cpp
  void printMeshInfo() const;
  ```

## Routine de lecture du fichier Gmsh

Vous allez implémenter la méthode `readMesh` dans la classe `Mesh`, qui utilise une routine externe pour lire les sections `$NOD` et `$ELEM` d'un fichier `.msh` au format MSH1.

### Format du fichier de maillage MSH1

Un fichier `.msh` au format MSH1 contient deux sections principales :

1. **Section `$NOD`** :
   Cette section contient les coordonnées des nœuds, formatées comme suit :
   ```
   $NOD
   <nombre_de_nœuds>
   <index> <x> <y> <z>
   ...
   $ENDNOD
   ```

2. **Section `$ELEM`** :
   Cette section contient les triangles, formatés comme suit :
   ```
   $ELEM
   <nombre_d'éléments>
   <index> <type> <nombre_de_tags> <tag1> <tag2> ... <nœud1> <nœud2> <nœud3>
   ...
   $ENDELEM
   ```

### Exemple de fichier `maillage.msh`

```plaintext
$NOD
4
1 0.0 0.0 0.0
2 1.0 0.0 0.0
3 1.0 1.0 0.0
4 0.0 1.0 0.0
$ENDNOD
$ELEM
2
1 2 0 1 1 2 3
2 2 0 1 2 3 4
$ENDELEM
```

## Exemple d'utilisation

```cpp
int main() {
    // Lecture d'un maillage à partir d'un fichier Gmsh au format MSH1
    Mesh mesh("maillage.msh");

    // Affichage des informations du maillage
    mesh.printMeshInfo();

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
```

## Livrables

- Un fichier `Mesh.cpp` contenant l'implémentation de la classe `Mesh`.
- Un fichier `main.cpp` contenant le programme principal pour tester la classe `Mesh`.
- Un fichier `maillage.msh` contenant un exemple de maillage pour tester votre classe.
