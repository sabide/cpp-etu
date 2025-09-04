# Les classes virtuelles pures

## Objectif
L'objectif de cet exercice est de pratiquer les classes virtuelles pures en C++ dans le contexte simplifié du calcul d'aires de figures géométriques. Vous allez ainsi créer une classe de base abstraite pour représenter une figure géométrique, puis dériver des classes pour calculer l'aire de différentes formes, notamment les triangles et les quadrangles.

## Trame de développement du code

1. **Créer une classe de base abstraite `Element` :**
   - La classe `Element` doit avoir une méthode virtuelle pure `double Aire() const = 0;`.
   - Cette méthode sera utilisée pour calculer l'aire de la figure géométrique.
   - Incluez également un destructeur virtuel pour garantir une destruction correcte des objets dérivés.

2. **Créer une classe dérivée `Triangle` :**
   - Héritez de la classe `Element`.
   - Ajoutez des attributs pour les coordonnées des trois sommets du triangle (par exemple, `x1, y1`, `x2, y2`, `x3, y3`).
   - Implémentez la méthode `Aire` en utilisant la formule de l'aire d'un triangle :
     $$
     \text{Aire} = \frac{1}{2} \times \left| x_1(y_2 - y_3) + x_2(y_3 - y_1) + x_3(y_1 - y_2) \right|
     $$
3. **Créer une classe dérivée `Quadrangle` :**
   - Héritez de la classe `Element`.
   - Ajoutez des attributs pour les coordonnées des quatre sommets du quadrilatère (par exemple, `x1, y1`, `x2, y2`, `x3, y3`, `x4, y4`).
   - Implémentez la méthode `Aire` en divisant le quadrilatère en deux triangles et en additionnant leurs aires respectives.

4. **Créer un programme principal `main` :**
   - Créez des objets `Triangle` et `Quadrangle` avec des coordonnées spécifiques.
   - Utilisez un tableau de pointeurs à des objets `Element` pour stocker des triangles et des quadrangles.
   - Parcourez le tableau et calculez l'aire de chaque figure en utilisant le polymorphisme, en appelant `Aire` sur chaque élément.

