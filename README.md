# Programmation C++ moderne — MAM4

Ce dépôt rassemble les supports étudiants du cours de programmation C++
moderne : diapositives, sujets de TD/TP, codes de départ et exemples montrés en
amphithéâtre.

Le cours suit un même fil rouge, `IntArray`, afin de faire apparaître chaque
mécanisme C++ à partir d'un problème concret.

## Séances disponibles

| Séance | Question principale | Cours | TD | Correction |
|---|---|:---:|:---:|:---:|
| 1 — Du C au C++ moderne | Comment une signature exprime-t-elle l'intention ? | oui | oui | à venir |
| 2 — Fonctions, bibliothèque et ressources | Pourquoi rapprocher données et opérations ? | oui | oui | à venir |

Les corrections sont ajoutées après les séances. Elles apparaîtront dans un
répertoire `td/correction/` sans remplacer le code de départ.

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
