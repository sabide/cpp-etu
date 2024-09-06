# Patrons de fonctions et de classes 

## Consignes:

Pour compiler et exécuter le code de l'exercice 1, on exécutera dans le terminal
```sh
g++ main_sort.cpp -o main_sort
./main_sort
```

Pour l'exercice 2, vous pouvez exécuter ce qui suit dans le terminal, afin de compiler uniquement le code de la classe *Cercle*:
```sh
g++ -c Cercle.cpp
```
Pour compiler la totalité du code et l'exécuter, taper:
```sh
g++ main.cpp Point2D.cpp Rot.cpp Mat22.cpp Cercle.cpp -o exo2
./exo2
```

# Exercice sur les fonctions et classes Template

On se propose d'implémenter un algorithme de tri sur des tableaux de
type générique. Pour cela, on va utiliser un des algorithmes de tri les
plus simples (loin d'être le plus performant !) appelé \"tri à bulle\".
Le pseudo code de cet algorithme est disponible dans le lien suivant
(c'est le 1er algo de la page): Source Wikipédia : <http://fr.wikipedia.org/wiki/Tri_à_bulles>

## Fonction `MySwap`

-   Pour cela, dans un fichier `MySort.hpp`, commencer à écrire une
    fonction patron `MySwap` sur un type générique T, prenant en
    paramètre deux références de ce type T, et échangeant leur valeur.

-   Tester dans une fonction `main` définie dans le fichier
    `main_sort.cpp`, sur au moins deux types.

## Fonction MySort

-   Ecrire une fonction `MySort` implémentant l'algorithme présenté dans
    le lien Wikipédia. Ce sera une fonction template sur un type
    générique T, prenant en paramètre un pointeur sur ce type, ainsi que
    la longueur de ce tableau (un entier).

-   Tester cette fonction de tri dans le fichier `main_sort.cpp` avec
    des tableaux de type divers : un tableau d'entiers, de réels et de
    chaînes de caractères `string` (pour les `string`, on ajoutera
    `#include\<string\>` au début du fichier contenant le `main`).

-   \[FACULTATIF\] Tester `MySort` sur la classe template `MyPaire` décrite en annexe, à la fin du sujet du TP.

# Héritage et polymorphisme

Récupérer sur Moodle, dans le dossier `src`, les fichiers `Mat22.cpp`,
`Mat22.hpp`, `Point2D.cpp`, `Point2D.hh`, `Rot.cpp` et `Rot.hh`.\
Ces fichiers contiennent la définition de la classe `Rot`, modélisant
les rotations dans $\mathbb{R}^²$ et qui s'utilise comme suit:

```c++
    const double PI = 3.141592653589793238463;
    Rot r(PI/4); // Rotation de PI/4  
    Point2D P = {1,0};  // Point dans R^2
    Point2D Q = r(P);   // on obtient Q = {sqrt(2)/2, sqrt(2)/2};
```
## La classe Forme

Nous allons déclarer une classe abstraite *Forme* de laquelle hériteront
les formes auxquelles nous appliquerons une matrice de rotation.

Dans un fichier `Forme.hh`, déclarer une classe `Forme`, qui ne
contiendra pas de données membres et qui contiendra les deux fonctions
**membres publiques virtuelles pures** suivantes (les fonctions membres
d'une classe abstraite ne peuvent être que virtuelles pures)

-   Une fonction `to_str` renvoyant une valeur de type `string` et ne
    prenant rien en paramètre.

-   Une fonction `apply_rot` ne renvoyant rien et prenant une référence
    constante sur un objet de type `Rot` en paramètre.

Comme la classe `Forme` ne contient que des fonctions virtuelles pures,
il n'y a pas de fonction à définir et par conséquent pas de fichier `.cpp`

## La classe Cercle

Dans un fichier `Cercle.hh`, déclarer une classe `Cercle` héritant
publiquement de la classe `Forme` déclarée lors de la question
précédente.\
Cette classe aura deux données membres privées :

-   Un objet de type `Point2D` appelé `centre_*`

-   Un double appelé `rayon_*`

Cette classe aura deux fonctions membres définissant les fonctions
virtuelles pures de la classe `Forme` et de même prototype que
celles-ci.

-   La fonction `to_str` devra renvoyer une chaîne de caractères
    décrivant le cercle

-   La fonction `apply_rot` appliquera une matrice de rotation reçue en
    paramètre à l'objet `centre_`, de type `Point2D`.

## La fonction main

-   Dans la fonction `main` du fichier `main.cpp`, déclarer une variable
    $v$ où $v$ est un tableau de 2 pointeurs sur `Forme`, comme suit:

```c++
Forme* v[2];
```
Le premier élément de $v$, $v[0]$ pointera vers un objet de type
`Cercle`, par exemple de centre (1, 0) et de rayon 2. Faire afficher 
cet élément de $v$ en utilisant la fonction `to_str` de la classe
`Forme`, puis appliquer à cet élément la matrice de rotation
correspondant à l'objet $r$ et le réafficher.\
Attention : Les éléments de $v$ sont des pointeurs ! Pour appeler
les fonctions membres des objets pointés, il faudra utiliser l'opérateur $\rightarrow$.


-   \[FACULTATIF\] Créer une classe *Carre*, ressemblant à la classe
    *Cercle* et héritant de *Forme*, possédant l'attribut privé *\_pts*,
    tableau de 4 *Point2D*, pour les sommets du carré.\
    $v[1]$ pointera alors vers un objet de type *Carre*, par exemple de
    centre (0.5, 0.5) et de côté 1. Faire le même traitement que pour
    $v[0]$.

# Annexe 

## Classe Template MyPaire (exercice 1)

Ce qui suit devra être écrit dans un fichier *MyPaire.hpp* (on rappelle
que pour les templates, les déclarations et définitions doivent être
écrites dans un unique fichier dont l'extension demandée est *.hpp*)\
La classe *MyPaire* est une classe template sur deux types $T$ et $U$.
La clé sera du type $T$ et la valeur sera du type $U$.\
Les paires sont des structures de données très utilisées lorsqu'on
souhaite associer une valeur à une clé. Cela permet, par exemple, de
créer des tableaux associatifs pour lesquels les valeurs ne sont plus
indexées par des entiers (comme c'est le cas dans les tableaux
classiques que nous connaissons déjà) mais par des clés dont le type est
libre.

-   Sa déclaration pourrait donc être la suivante :

        template <typename T, typename U> 
        class MyPaire { ....} ; 

-   Le couple clé/valeur sera déclaré en tant que données membres
    privées avec les types $T$ et $U$ respectivement.

-   Les fonctions publiques seront :

    -   Un constructeur ne prenant rien en paramètre et ne faisant rien.

    -   Un constructeur prenant deux paramètres, une clé de type $T$ et
        une valeur de type $U$.

    -   Une surcharge de l'opérateur $<$ permettant de savoir si un
        objet de type *MyPaire* reçu en paramètre (son type sera *const
        MyPaire*&) est plus grand que l'instance courante, au sens de
        leur valeur. Le type de la valeur de retour sera *bool*.

    -   Enfin une fonction amie surchargeant l'opérateur $<<$ afin de
        pouvoir afficher le couple clé/valeur de notre paire à l'aide de
        *cout*.
