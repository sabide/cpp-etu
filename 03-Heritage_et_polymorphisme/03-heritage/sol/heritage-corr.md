
# Solution

La solution comprend la création des classes `Animal`, `Lion`, `Oiseau`, et `Canard`, ainsi que des interfaces `Volant` et `Nageant`. L'implémentation démontrera comment l'héritage multiple est utilisé pour combiner différents comportements.

## Quelques explications
1. **Classe `Animal`** :
   - Le constructeur initialise le nom de l'animal et affiche un message indiquant que l'animal a été créé.
   - Le destructeur est virtuel, ce qui garantit que lorsqu'un objet dérivé est détruit via un pointeur de type `Animal`, le destructeur de la classe dérivée est appelé.
   - La méthode `parler()` est virtuelle pure, obligeant les classes dérivées à l'implémenter.

2. **Interfaces `Volant` et `Nageant`** :
   - Ces interfaces déclarent des méthodes pour représenter la capacité de voler et nager, respectivement.

3. **Classe `Lion`** :
   - Implémente la méthode `parler()` et hérite du comportement de base de `Animal`.

4. **Classe `Oiseau`** :
   - Hérite de `Animal` et de `Volant`, et implémente la méthode `voler()`.

5. **Classe `Canard`** :
   - Hérite de `Oiseau` et de `Nageant`, et implémente la méthode `nager()`. Le `Canard` peut ainsi parler, voler et nager.

6. **Programme principal `main`** :
   - Les objets sont créés et manipulés pour démontrer le polymorphisme et l'héritage multiple.

le code source se trouve la [zoo.cpp](./zoo.cpp)

# Explications complémetaires :

- **Création des Objets** : Les animaux `Simba` (Lion), `Tweety` (Oiseau), et `Donald` (Canard) sont créés dynamiquement et stockés dans un tableau de pointeurs `Animal`.
- **Utilisation de dynamic_cast** : Pour vérifier et appeler les méthodes `voler()` et `nager()` pour les animaux qui en ont la capacité.
- **Destruction des Objets** : Lorsqu'on appelle `delete` sur les pointeurs, les destructeurs des classes dérivées sont appelés, ce qui démontre le bon fonctionnement du destructeur virtuel.
