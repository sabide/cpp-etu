# Classes et Fonctions Amies en C++ (1 heure)

## Objectifs
Vous allez implémenter une classe `Rectangle` en C++ avec deux attributs privés pour représenter la largeur et la hauteur du rectangle. Vous allez ensuite écrire une classe amie `RectangleUtils` qui fournira des méthodes pour calculer l'aire et le périmètre du rectangle en accédant directement aux attributs privés de `Rectangle`.

## 1. Définition de la Classe `Rectangle`

Créez une classe `Rectangle` avec les spécifications suivantes :

### Attributs
- **Privés**
  - `double width` : La largeur du rectangle.
  - `double height` : La hauteur du rectangle.

### Constructeurs
- Un **constructeur par défaut** qui initialise la largeur et la hauteur à 0.
- Un **constructeur paramétré** qui prend deux arguments pour initialiser la largeur et la hauteur.

### Méthodes
- **getWidth()** : Retourne la largeur du rectangle.
- **getHeight()** : Retourne la hauteur du rectangle.
- **setWidth(double w)** : Définit la largeur du rectangle.
- **setHeight(double h)** : Définit la hauteur du rectangle.

### Classe Amie
- Créez une classe amie `RectangleUtils` qui contiendra deux méthodes :
  - **calculateArea(const Rectangle&)** : Calcule et retourne l'aire du rectangle.
  - **calculatePerimeter(const Rectangle&)** : Calcule et retourne le périmètre du rectangle.

## 2. Implémentation de la Classe `Rectangle`

1. Implémentez la classe `Rectangle` dans des fichiers séparés (`rectangle.h` pour la déclaration et `rectangle.cpp` pour l'implémentation).

2. Implémentez les constructeurs par défaut et paramétré.

3. Implémentez les méthodes :
   - `getWidth()`, `getHeight()`, `setWidth(double w)`, et `setHeight(double h)`.

4. Déclarez et implémentez la classe amie `RectangleUtils` pour fournir les méthodes `calculateArea` et `calculatePerimeter`.

## 3. Exemple d'utilisation dans le `main`

Écrivez un programme dans `main.cpp` qui :

1. Crée un rectangle `rect1` en utilisant le constructeur par défaut.
2. Crée un rectangle `rect2` avec une largeur de 4.0 et une hauteur de 5.0 en utilisant le constructeur paramétré.
3. Affiche les dimensions du rectangle `rect2`.
4. Calcule et affiche l'aire de `rect2` en utilisant la méthode `calculateArea` de la classe amie `RectangleUtils`.
5. Calcule et affiche le périmètre de `rect2` en utilisant la méthode `calculatePerimeter` de la classe amie `RectangleUtils`.

## 5. Si vous avez un peu de temps

Pour approfondir vos connaissances :
- Ajoutez d'autres méthodes à la classe amie, comme une méthode pour redimensionner le rectangle.
- Implémentez une classe dérivée `Square` (carré) qui hérite de `Rectangle` et où la largeur et la hauteur sont toujours égales.
- Ajoutez des tests pour vérifier que la classe amie `RectangleUtils` fonctionne correctement avec des rectangles de différentes tailles.
