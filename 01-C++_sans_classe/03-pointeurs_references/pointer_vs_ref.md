# Références et Pointeurs en C++ 

Ce td a pour objectif de vous aider à comprendre la différence entre les **références** et les **pointeurs** en C++, ainsi que leur utilisation dans les fonctions, notamment pour le **passage d’arguments** et le **retour de valeurs**.

## Contexte

En C++, les références et les pointeurs sont deux mécanismes fondamentaux pour manipuler la mémoire :

* Une **référence** est un alias d’une variable existante (elle ne peut pas être nulle et doit être initialisée à la déclaration).
* Un **pointeur** stocke l’adresse d’une variable et peut être redirigé vers une autre variable.

Ces deux outils sont largement utilisés pour :

* passer des arguments aux fonctions sans recopier les données,
* retourner des valeurs sans créer de copies.


## Questions

### 1. Déclaration et utilisation des références et des pointeurs

* Créez une variable entière `int a = 5;`.
* Déclarez un pointeur `int* p` qui pointe sur `a`.
* Déclarez une référence `int& r` qui fait référence à `a`.
* Affichez les **valeurs** et les **adresses** de `a`, `p` et `r` pour illustrer leur relation.

### 2. Passage par référence et par pointeur aux fonctions

* Implémentez deux fonctions :

  * `incrementByPointer(int* ptr)` qui incrémente la valeur pointée.
  * `incrementByReference(int& ref)` qui incrémente la valeur référencée.
* Testez-les en appelant chaque fonction sur la variable `a`.
* Comparez les résultats.



### 3. Retourner des références et des pointeurs depuis une fonction

* Implémentez :

  * `int* getPointerToElement(int arr[], int index)` qui retourne un pointeur vers un élément d’un tableau.
  * `int& getReferenceToElement(int arr[], int index)` qui retourne une référence vers un élément d’un tableau.
* Déclarez un tableau `int arr[5] = {1, 2, 3, 4, 5};`.
* Utilisez ces fonctions pour accéder au **troisième élément** et modifiez sa valeur via le pointeur puis via la référence.



### 4. Étude de cas : fonction retournant une référence

* Implémentez la fonction `int& getMax(int& x, int& y)` qui retourne une référence vers le plus grand des deux entiers.
* Testez la fonction en appelant `getMax` avec deux variables.
* Modifiez directement la plus grande variable à travers la référence retournée.


### 5. Questions de réflexion

* Quelle est la **différence fondamentale** entre une référence et un pointeur en termes de syntaxe et d’utilisation ?
* Pourquoi est-il **dangereux** de retourner un pointeur ou une référence vers une variable **locale** d’une fonction ?
* Dans quels cas précis utiliseriez-vous une **référence** plutôt qu’un **pointeur** pour retourner une valeur depuis une fonction, et inversement ?

