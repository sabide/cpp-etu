# Introduction aux Classes en C++ (1 heure)

**Objectif :** Cet exercice vise à introduire les concepts de base des classes en C++, notamment les constructeurs sous plusieurs formes, les attributs privés et publics, et les fonctions amies. Le contexte choisi est celui de la géométrie, où nous allons manipuler des points dans un plan cartésien.

## Contexte

Vous allez implémenter une classe `Point` en C++ qui représente un point dans un plan 2D avec des coordonnées \(x\) et \(y\). Cette classe doit permettre :
- La création d'objets `Point` avec différents constructeurs.
- La manipulation des attributs privés et publics, avec une alternative d'accès via des getters retournant des références.
- L'utilisation de fonctions amies pour accéder et modifier les attributs privés.

## 1. Définition de la Classe `Point`

Créez une classe `Point` avec les spécifications suivantes :

### Attributs
- **Privés :**
  - `double x` : Coordonnée en abscisse.
  - `double y` : Coordonnée en ordonnée.

- **Publics :**
  - Aucun.

### Constructeurs
- Un **constructeur par défaut** qui initialise les coordonnées du point à \( (0, 0) \).
- Un **constructeur paramétré** qui prend deux arguments pour initialiser \(x\) et \(y\).
- Un **constructeur de copie** qui initialise un point en le copiant d'un autre point.

### Méthodes
- **Getters et Setters :** Implémentez des méthodes publiques pour accéder et modifier les valeurs des attributs privés.
  - **Option 1 :** Implémentez les getters `getX()` et `getY()` qui retournent des copies des valeurs de `x` et `y`.
  - **Option 2 :** Implémentez les getters `getX()` et `getY()` qui retournent des références (`double&`) aux attributs `x` et `y`, permettant ainsi leur modification directe.

### Fonction Amie
- Une fonction amie `distance(const Point&, const Point&)` qui calcule la distance entre deux points.

## 2. Implémentation de la Classe `Point`

1. **Déclarez** et **implémentez** la classe `Point` dans des fichiers séparés (`point.h` pour la déclaration et `point.cpp` pour l'implémentation).

2. **Implémentez les constructeurs :**
   - Le constructeur par défaut.
   - Le constructeur paramétré.
   - Le constructeur de copie.

3. **Implémentez les méthodes :**
   - **Option 1 :** Les getters `getX()` et `getY()` retournent des copies des attributs.
   - **Option 2 :** Les getters `getX()` et `getY()` retournent des références aux attributs `x` et `y`, permettant leur modification directe.
   - Les setters `setX(double)` et `setY(double)` permettent de modifier les valeurs de `x` et `y`.

4. **Implémentez la fonction amie** `distance(const Point&, const Point&)`.

## 3. Exemple d'utilisation dans le `main`

Écrivez un programme dans `main.cpp` qui :

1. Crée un point `p1` en utilisant le constructeur par défaut.
2. Crée un point `p2` en utilisant le constructeur paramétré avec les coordonnées \(x = 3.0\) et \(y = 4.0\).
3. Affiche les coordonnées de `p1` et `p2`.
4. Modifie les coordonnées de `p1` pour \(x = 1.0\) et \(y = 2.0\).
   - **Option 1 :** Utilisez les setters pour modifier les coordonnées de `p1`.
   - **Option 2 :** Modifiez directement les valeurs de `p1` via les getters qui retournent des références.
5. Affiche la distance entre `p1` et `p2` en utilisant la fonction amie `distance`.
