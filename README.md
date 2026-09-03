# Programmation C++ moderne — MAM4

Ce dépôt rassemble les supports du cours de programmation C++ moderne :
diapositives, sujets de TD/TP et codes de départ.

Le cours suit un même fil rouge, `IntArray`, afin de faire apparaître chaque
mécanisme C++ à partir d'un problème concret.

## Séances disponibles

| Séance | Question principale | Cours | TD | Correction |
|---|---|:---:|:---:|:---:|
| 1 — Du C au C++ moderne | Comment une signature exprime-t-elle l'intention ? | oui | oui | oui |
| 2 — Fonctions, bibliothèque et ressources | Pourquoi rapprocher données et opérations ? | oui | oui | oui |
| 3 — Classes, invariants et RAII | Comment rendre un objet responsable de son état et de sa ressource ? | oui | oui | oui |
| 4 — Copie, déplacement et opérateurs | Comment donner à `IntArray` un comportement de valeur ? | oui | oui | oui |
| 5 — Composition et héritage | Comment relier plusieurs types sans trahir leur sens ? | oui | oui | oui |
| 6 — Interfaces abstraites et polymorphisme dynamique | Comment choisir un comportement selon le type réel ? | oui | oui | oui |

Un TD de synthèse avec Gmsh est également disponible après les séances 1 à 4.

Les corrections apparaissent dans un répertoire `td/correction/`, sans
remplacer le code de départ. Les séances 5 et 6 contiennent aussi un petit
programme de démonstration dans `cours/demo_amphi.cpp`.

## Organisation d'une séance

Dans chaque séance, consultez :

- `cours/` pour le support et les éventuels exemples ;
- `td/enonce/` pour le sujet et le squelette à compléter ;
- `td/correction/` pour la solution et les tests après le travail personnel.

La synthèse Gmsh suit la même organisation dans `seances/synthese-gmsh/`.

## Utilisation

Cloner une première fois le dépôt :

```bash
git clone https://github.com/sabide/cpp-etu.git
cd cpp-etu
```

Récupérer ensuite les nouveaux supports :

```bash
git pull
```

Pour éviter les conflits lors d'une mise à jour, effectuez votre travail dans
une copie personnelle du répertoire `td/enonce/code/`.

## Compiler les exemples

Les exemples utilisent C++20 :

```bash
g++ -std=c++20 -Wall -Wextra -pedantic fichier.cpp
```

Dans les TD consacrés à la mémoire et à la durée de vie, conserver les
sanitizers actifs :

```bash
g++ -std=c++20 -Wall -Wextra -pedantic \
    -fsanitize=address,undefined -g \
    int_array.cpp main.cpp -o int_array
```

La plupart des répertoires de code possèdent également un `Makefile` :

```bash
make
```
