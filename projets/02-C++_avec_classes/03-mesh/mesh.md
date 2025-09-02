# Maillages de triangles en 2D avec C++ (30mn)
Execercie très simple.... à faire le plus rapidement possible....
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