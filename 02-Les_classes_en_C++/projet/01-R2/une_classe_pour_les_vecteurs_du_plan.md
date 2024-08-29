# Implémentation de la classe `R2` pour modéliser les vetceurs du plan

## Objectif

L'objectif de cet exercice est d'implémenter une classe `R2` qui représente un vecteur 2D dans un espace euclidien. La classe doit inclure divers constructeurs, opérateurs et méthodes utiles pour manipuler des vecteurs 2D. Cela va vous permetrre d'assimiler le cours sur les classes.

## Spécifications de la classe `R2`

Vous devez implémenter une classe nommée `R2` avec les caractéristiques suivantes :

### Membres privés

- `double x_` : coordonnée x du vecteur.
- `double y_` : coordonnée y du vecteur.

### Constructeurs

1. **Constructeur par défaut :**
   ```cpp
   R2();
   ```
   Ce constructeur initialise `x_` et `y_` à `0.0`.

2. **Constructeur avec deux arguments :**
   ```cpp
   R2(R x, R y);
   ```
   Ce constructeur initialise `x_` à `x` et `y_` à `y`.

3. **Constructeur avec deux vecteurs (vecteur AB) :**
   ```cpp
   R2(const R2 &a, const R2 &b);
   ```
   Ce constructeur crée le vecteur AB défini par les points `a` et `b`.

4. **Constructeur par copie :**
   ```cpp
   R2(const R2 &a);
   ```
   Ce constructeur copie les valeurs de `a` dans le nouveau vecteur. Il doit également afficher un message pour indiquer qu'il est utilisé.

### Opérateur d'affectation

- Implémentez l'opérateur `=` pour copier les valeurs d'un vecteur à un autre :
  ```cpp
  R2& operator=(const R2 &P);
  ```

### Méthodes d'accès

- Accéder et modifier les coordonnées :
  ```cpp
  R& x();
  R& y();
  const R& x() const;
  const R& y() const;
  ```

### Opérateurs d'affectation

- Implémentez les opérateurs `+=` et `-=` pour ajouter et soustraire un vecteur à l'autre :
  ```cpp
  R2& operator+=(const R2 &P);
  R2& operator-=(const R2 &P);
  ```

### Opérateurs binaires

- Implémentez les opérateurs suivants pour la manipulation des vecteurs :
  ```cpp
  R2 operator+(const R2 &P) const;
  R2 operator-(const R2 &P) const;
  R operator,(const R2 &P) const;  // produit scalaire
  R operator^(const R2 &P) const;  // produit mixte
  R2 operator*(R c) const;
  R2 operator/(R c) const;
  ```

### Opérateurs unaires

- Implémentez les opérateurs unaires pour le vecteur opposé et le vecteur orthogonal :
  ```cpp
  R2 operator-() const;
  const R2& operator+() const;
  R2 perp() const;
  ```

### Opérateurs d'indexation

- Implémentez les opérateurs `[]` et `()` pour accéder aux coordonnées en fonction de l'index :
  ```cpp
  R& operator[](int i);
  const R& operator[](int i) const;
  R& operator()(int i);
  const R& operator()(int i) const;
  ```

### Méthode utilitaire

- Implémentez une méthode pour calculer la norme du vecteur :
  ```cpp
  R norme() const;
  ```

### Membres statiques

- Ajoutez un membre statique pour la dimension :
  ```cpp
  static const int d = 2;
  ```

### Fonctions amies

- Implémentez les fonctions amies suivantes pour l'entrée/sortie des vecteurs et pour les opérations mathématiques externes :
  ```cpp
  friend std::ostream& operator<<(std::ostream &f, const R2 &P);
  friend std::istream& operator>>(std::istream &f, R2 &P);
  friend inline R2 operator*(R c, const R2 &P);
  friend inline R det(const R2 &A, const R2 &B, const R2 &C);
  ```

## Exigences supplémentaires

- Le code doit être bien structuré et inclure des commentaires expliquant chaque section de la classe.
- Vous devez inclure un programme principal (`main`) pour tester toutes les fonctionnalités de la classe `R2`.

### Exemple d'utilisation

```cpp
int main() {
    R2 a(1.0, 2.0);
    R2 b(3.0, 4.0);
    R2 c = a + b;
    
    std::cout << "a + b = " << c << std::endl;
    std::cout << "Norme de c = " << c.norme() << std::endl;
    
    return 0;
}
```

### Livrables

- Un fichier `R2.cpp` contenant l'implémentation de la classe `R2`.
- Un fichier `main.cpp` contenant le programme principal pour tester la classe.
