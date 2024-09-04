# Gestion d'un Zoo ...

## Objectif :
L'objectif de cet exercice est de comprendre le mécanisme d'héritage en C++, en particulier l'héritage multiple, ainsi que le fonctionnement des constructeurs et destructeurs dans une hiérarchie de classes. Vous allez créer une classe de base `Animal` et des classes dérivées pour différents types d'animaux, tout en introduisant des interfaces pour des comportements spécifiques comme voler ou nager. Vous utiliserez l'héritage multiple pour combiner ces comportements.

## Instruction à suivre

1. Créer une classe de base `Animal`
   - La classe `Animal` doit avoir un attribut `nom` pour stocker le nom de l'animal.
   - Déclarez un constructeur qui prend un nom en paramètre et affiche un message indiquant que l'animal a été créé.
   - Déclarez un destructeur qui affiche un message indiquant que l'animal est détruit.
   - Déclarez une méthode virtuelle pure `void parler() const = 0;`, que chaque classe dérivée devra implémenter.

2. Créer une interface `Volant`
   - Déclarez une méthode virtuelle pure `void voler() const = 0;` pour représenter la capacité de voler.

3. Créer une interface `Nageant`
   - Déclarez une méthode virtuelle pure `void nager() const = 0;` pour représenter la capacité de nager.

4. Créer une classe dérivée `Lion`
   - Héritez de la classe `Animal`.
   - Implémentez le constructeur pour le `Lion`, qui appelle le constructeur de la classe `Animal` pour initialiser le nom.
   - Implémentez la méthode `parler()` pour afficher un rugissement spécifique au lion.
   - Implémentez le destructeur pour afficher un message spécifique lorsque l'objet `Lion` est détruit.

5. Modifier la classe `Oiseau` pour qu'elle hérite de `Volant`
   - Implémentez la méthode `voler()` dans la classe `Oiseau`.
   - L'oiseau devrait pouvoir à la fois parler et voler.

6. Créer une nouvelle classe `Canard` qui hérite à la fois de `Oiseau` et de `Nageant` 
   - Implémentez la méthode `nager()` dans la classe `Canard`.
   - Le canard doit pouvoir parler, voler et nager.

7. Créer un programme principal `main` 
   - Créez des objets `Lion`, `Oiseau`, et `Canard`.
   - Faites-les parler, voler, et nager en utilisant les méthodes appropriées.
   - Observez l'ordre d'appel des constructeurs et des destructeurs lors de la création et la destruction des objets.

