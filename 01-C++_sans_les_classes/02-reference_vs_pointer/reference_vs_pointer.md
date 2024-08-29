# Références et Pointeurs en C++ (30mn)

## Objectif 
Comprendre la différence entre les références et les pointeurs en C++ et leur utilisation dans le contexte des fonctions, notamment pour le retour de valeurs.

## Contexte 
Les références et les pointeurs sont deux mécanismes fondamentaux en C++ pour manipuler les adresses en mémoire. Les références permettent de créer un alias pour une variable, tandis que les pointeurs stockent explicitement l'adresse d'une variable. Ces deux concepts sont souvent utilisés pour passer des arguments aux fonctions et pour retourner des valeurs.

## Questions

1. **Déclaration et utilisation des références et des pointeurs**
   - Créez une variable entière `int a = 5;`.
   - Déclarez un pointeur `int* p` qui pointe sur `a` et une référence `int& r` qui fait référence à `a`.
   - Affichez les valeurs et les adresses en utilisant le pointeur et la référence pour illustrer leur lien avec la variable `a`.

2. **passage par référence et par pointeur aux fonctions**
   - Implémentez deux fonctions : `incrementByPointer(int* ptr)` et `incrementByReference(int& ref)` qui incrémentent la valeur d'une variable entière en utilisant respectivement un pointeur et une référence.
   - Appelez ces fonctions en passant `a` en argument, une fois par pointeur et une fois par référence, et observez les modifications.

3. **Retourner des références et des pointeurs depuis une fonction**
   - Créez une fonction `int* getPointerToElement(int arr[], int index)` qui retourne un pointeur vers un élément d'un tableau.
   - Créez une fonction `int& getReferenceToElement(int arr[], int index)` qui retourne une référence vers un élément d'un tableau.
   - Déclarez un tableau `int arr[5] = {1, 2, 3, 4, 5};`.
   - Utilisez les deux fonctions pour accéder au troisième élément du tableau et modifiez sa valeur via le pointeur et la référence retournés.

4. **Étude de cas : fonction retournant une Référence**
   - Implémentez une fonction `int& getMax(int& x, int& y)` qui retourne une référence vers le plus grand de deux entiers.
   - Testez la fonction en l'appelant avec deux variables et en utilisant la valeur retournée pour modifier directement la plus grande des deux variables.

5. **Questions de réflexion**
   - Quelle est la différence fondamentale entre une référence et un pointeur en termes de syntaxe et d'utilisation ?
   - Pourquoi est-il dangereux de retourner un pointeur ou une référence vers une variable locale d'une fonction ?
   - Dans quels cas spécifiques utiliseriez-vous une référence plutôt qu'un pointeur pour retourner une valeur depuis une fonction, et vice versa ?
