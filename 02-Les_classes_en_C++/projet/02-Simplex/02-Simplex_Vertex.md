# Implémentation des classes pour les éléments finis

## Objectif

L'objectif de cet exercice est d'implémenter deux classes en C++ : `Vertex`, qui représente un sommet dans un espace 2D avec un label, et `Simplex`, qui modélise un triangle (simplex 2D) formé par trois sommets. Ces classes doivent inclure divers constructeurs, opérateurs et méthodes pour manipuler les sommets et les triangles.

## Spécifications de la classe `Vertex`

La classe `Vertex` est une sous-classe de `R2` qui hérite des fonctionnalités d'un vecteur 2D tout en ajoutant un label pour identifier le sommet.

### Membres privés

- `int label_` : un entier pour stocker le label du sommet.

### Constructeurs

1. **Constructeur par défaut :**
   ```cpp
   Vertex();
   ```
   Ce constructeur initialise le label à `0` et les coordonnées du sommet à `(0.0, 0.0)` via le constructeur de `R2`.

### Méthodes d'accès

- Accéder et modifier le label :
  ```cpp
  int& label();
  ```

### Opérateurs d'affectation

- **Affectation avec un vecteur `R2` :**
  ```cpp
  Vertex& operator=(R2 n);
  ```
  Ce constructeur copie les coordonnées du vecteur `R2` dans le sommet, tout en réinitialisant le label à `0`.

- **Affectation avec un autre `Vertex` :**
  ```cpp
  Vertex& operator=(Vertex& n);
  ```
  Ce constructeur copie les coordonnées et le label d'un autre sommet.

### Opérateurs d'entrée/sortie

- Implémentez les opérateurs pour afficher les informations sur le sommet et pour les lire depuis une entrée :
  ```cpp
  friend std::ostream& operator<<(std::ostream &f, const Vertex &P);
  friend std::istream& operator>>(std::istream &f, Vertex &P);
  ```

### Exemple d'utilisation

```cpp
int main() {
    Vertex v1;
    Vertex v2;
    std::cin >> v1 >> v2;
    std::cout << "Vertex 1: " << v1 << std::endl;
    std::cout << "Vertex 2: " << v2 << std::endl;
    
    return 0;
}
```

## Spécifications de la classe `Simplex`

La classe `Simplex` modélise un triangle (simplex 2D) formé par trois sommets de type `Vertex`.

### Membres privés

- `static const int nbv = 3` : un entier statique constant pour représenter le nombre de sommets du triangle.
- `Vertex vertices_[nbv]` : un tableau de trois sommets.
- `double mes` : la mesure (aire) du triangle.

### Constructeurs

1. **Constructeur par défaut :**
   ```cpp
   Simplex();
   ```
   Ce constructeur initialise un triangle vide.

2. **Constructeur avec trois sommets :**
   ```cpp
   Simplex(const Vertex n0, const Vertex n1, const Vertex n2);
   ```
   Ce constructeur initialise un triangle avec trois sommets donnés.

### Méthodes de calcul

- **Gradient des fonctions de base :**
  ```cpp
  void GradLambdaK(R2 G[3]) const;
  ```
  Cette méthode calcule les gradients des fonctions de base du triangle et les stocke dans un tableau `R2`.

### Opérateurs

- **Accès aux sommets du triangle :**
  ```cpp
  Vertex& operator[](int i);
  const Vertex& operator[](int i) const;
  ```

- **Opérateurs d'entrée/sortie :**
  Implémentez les opérateurs pour afficher les informations sur le triangle et pour les lire depuis une entrée :
  ```cpp
  friend std::ostream& operator<<(std::ostream &os, const Simplex &S);
  ```

### Exemple d'utilisation

```cpp
int main() {
    Vertex v1, v2, v3;
    std::cin >> v1 >> v2 >> v3;
    
    Simplex triangle(v1, v2, v3);
    std::cout << "Triangle:" << std::endl << triangle << std::endl;
    
    R2 gradients[3];
    triangle.GradLambdaK(gradients);
    
    std::cout << "Gradients:" << std::endl;
    for (int i = 0; i < 3; ++i) {
        std::cout << gradients[i] << std::endl;
    }
    
    return 0;
}
```

### Livrables

- Un fichier `Vertex.cpp` contenant l'implémentation de la classe `Vertex`.
- Un fichier `Simplex.cpp` contenant l'implémentation de la classe `Simplex`.
- Un fichier `main.cpp` contenant le programme principal pour tester les classes `Vertex` et `Simplex`.

---

Cet énoncé guide la création des classes `Vertex` et `Simplex`, tout en assurant que toutes les fonctionnalités de base sont bien couvertes. Il permet de manipuler des triangles en 2D de manière structurée, en utilisant les concepts de programmation orientée objet.