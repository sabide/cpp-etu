
# Introduction à CMake

CMake est un outil qui permet d’automatiser la compilation de projets C++.
Plutôt que d’écrire soi-même toutes les commandes `g++`, on décrit la structure du projet dans un fichier `CMakeLists.txt`, et CMake se charge de générer le système de build.

## Petit rappel historique

CMake a été créé au début des années 2000 par Kitware (la société derrière **VTK** et **ITK**) pour répondre à un besoin : gérer de gros projets multi-plateformes (Linux, Windows, Mac) sans écrire des scripts de compilation différents pour chaque système.
Aujourd’hui, CMake est l’un des outils de compilation les plus utilisés dans le monde C++ (notamment pour des projets comme **Qt**, **KDE**, **hdf5**).

Dans ce tutoriel, nous allons expérimenter CMake sur des cas très simples :
* compilation d’un seul fichier source,
* compilation d’un petit projet avec plusieurs fichiers.

L’idée est de montrer qu’il peut être utile d’investir un peu de temps dans l’automatisation de la compilation, même pour de petits projets.

## 1. Projet minimal

L'objectif est de compiler un seul fichier C++ (`main.cpp`) automatiquement avec CMake, sans écrire directement la commande `g++ main.cpp -o mon_exe`. La structure d’un projet minimal avec CMake ressemble à:
```
mon_projet/
 ├── CMakeLists.txt   <-- fichier de configuration pour CMake
 └── main.cpp         <-- fichier source principal
```
où
* `main.cpp` contient le code C++.
* `CMakeLists.txt` décrit comment compiler le projet.

Le fichier `main.cpp` est l'un des plus simplistes.

```cpp
#include <iostream>
using namespace std;

int main() {
    cout << "Hello CMake !" << endl;
    return 0;
}
```
Il est minimal, mais suffisant pour tester CMake.
Le point clef est le fichier `CMakeLists.txt`. 
Il contient les directives pour la générer un makefile (automatiser la compilation) 

```cmake
cmake_minimum_required(VERSION 3.10)   # version minimale de CMake requise
project(MonProjet)                     # nom du projet

set(CMAKE_CXX_STANDARD 11)             # standard C++ utilisé
set(CMAKE_CXX_STANDARD_REQUIRED True)  # obligation d'utiliser ce standard

add_executable(mon_exe main.cpp)       # création de l'exécutable "mon_exe"
```

Commentaires :

* `cmake_minimum_required` garantit une version compatible de CMake.
* `project` nomme le projet.
* `set` définit le standard du langage (ici C++11).
* `add_executable` dit à CMake de compiler `main.cpp` et de produire un exécutable `mon_exe`.
et enfin la dernière étape la **compilation**.
CMake sépare le code source et les fichiers de build. On procède en deux étapes :

```bash
mkdir build         # créer un dossier pour la compilation
cd build            # entrer dans ce dossier
cmake ..            # générer les fichiers de compilation à partir du CMakeLists.txt
make                # lancer la compilation
./mon_exe           # exécuter le programme
```

Explications :

* `mkdir build` : évite de mélanger sources et fichiers générés.
* `cmake ..` : dit à CMake de lire le `CMakeLists.txt` du dossier parent (`..`).
* `make` : compile en suivant les règles générées par CMake.
* `./mon_exe` : lance l’exécutable créé.


[exercice 1](./enonce/01/exercice-01.md)


## 2. Projet multi-sources

L’objectif est de compiler un petit projet constitué de plusieurs fichiers C++ (un programme principal et des fonctions séparées) avec CMake.
Cela permet de séparer le code en modules, ce qui rend le projet plus clair et maintenable.

---

### Arborescence du projet

```
mon_projet/
 ├── CMakeLists.txt   <-- fichier de configuration pour CMake
 ├── main.cpp         <-- programme principal
 ├── fonctions.cpp    <-- implémentation de fonctions
 └── fonctions.h      <-- déclarations (prototype des fonctions)
```

où :

* `main.cpp` contient le code principal qui appelle les fonctions,
* `fonctions.h` déclare les fonctions (interface),
* `fonctions.cpp` implémente les fonctions,
* `CMakeLists.txt` décrit comment compiler et lier les fichiers ensemble.

---

### Le fichier `fonctions.h`

```cpp
#ifndef FONCTIONS_H
#define FONCTIONS_H

int carre(int x);   // prototype de fonction

#endif
```

---

### Le fichier `fonctions.cpp`

```cpp
#include "fonctions.h"

int carre(int x) {
    return x * x;
}
```

---

### Le fichier `main.cpp`

```cpp
#include <iostream>
#include "fonctions.h"   // inclusion du fichier d’en-tête

using namespace std;

int main() {
    int n = 5;
    cout << "Le carré de " << n << " est " << carre(n) << endl;
    return 0;
}
```

---

### Le fichier `CMakeLists.txt`

```cmake
cmake_minimum_required(VERSION 3.10)   # version minimale de CMake
project(MonProjet)                     # nom du projet

set(CMAKE_CXX_STANDARD 11)             # standard utilisé
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(mon_exe main.cpp fonctions.cpp)
```

Commentaires :

* On ajoute simplement `fonctions.cpp` à la liste des fichiers nécessaires pour compiler l’exécutable.
* CMake s’occupe d’inclure automatiquement `fonctions.h` car il est référencé dans les sources.

---

### Compilation avec CMake

Les étapes restent identiques au projet mono-source :

```bash
mkdir build
cd build
cmake ..
make
./mon_exe
```

Explications :

* `cmake ..` lit le `CMakeLists.txt` et génère les règles de compilation,
* `make` compile les deux sources `main.cpp` et `fonctions.cpp`,
* `./mon_exe` exécute le programme qui utilise la fonction `carre`.


[exercice 2](./enonce/02/exercice-02.md)


## 3. Projet avec librairie statique

L’objectif est de montrer comment séparer les fonctions dans une librairie statique, puis les utiliser dans un programme principal.
Cela reflète la manière dont sont organisées de nombreuses bibliothèques C++ (STL, OpenCV, etc.).


### Arborescence du projet

```
mon_projet/
 ├── CMakeLists.txt   <-- fichier de configuration
 ├── main.cpp         <-- programme principal
 ├── fonctions.cpp    <-- implémentation
 └── fonctions.h      <-- interface (header)
```

Ici, `fonctions.cpp` sera compilé en une librairie statique `libfonctions.a`.
Le `main.cpp` sera ensuite compilé et lié à cette librairie.

---

### Le fichier `fonctions.h`

```cpp
#ifndef FONCTIONS_H
#define FONCTIONS_H

int carre(int x);

#endif
```

---

### Le fichier `fonctions.cpp`

```cpp
#include "fonctions.h"

int carre(int x) {
    return x * x;
}
```

---

###  Le fichier `main.cpp`

```cpp
#include <iostream>
#include "fonctions.h"

using namespace std;

int main() {
    int n = 7;
    cout << "Le carré de " << n << " est " << carre(n) << endl;
    return 0;
}
```

---

###  Le fichier `CMakeLists.txt`

```cmake
cmake_minimum_required(VERSION 3.10)
project(MonProjetLibrairie)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Déclaration de la librairie statique
add_library(fonctions STATIC fonctions.cpp)

# Création de l'exécutable
add_executable(mon_exe main.cpp)

# Lien de l'exécutable avec la librairie
target_link_libraries(mon_exe PRIVATE fonctions)
```

Commentaires :

* `add_library(fonctions STATIC fonctions.cpp)` → crée une librairie statique `libfonctions.a`.
* `add_executable(mon_exe main.cpp)` → définit l’exécutable principal.
* `target_link_libraries(mon_exe PRIVATE fonctions)` → dit à CMake de lier l’exécutable avec la librairie `fonctions`.

---

### Compilation avec CMake

Les étapes restent les mêmes :

```bash
mkdir build
cd build
cmake ..
make
./mon_exe
```

---

### conclusions

* Une **librairie statique** est un regroupement de fonctions compilées (fichier `.a`).
* Elle permet de séparer la compilation et de réutiliser du code dans plusieurs exécutables.
* CMake simplifie la gestion en unifiant la compilation de la librairie et de l’exécutable.

[exercice 3](./enonce/03/exercice-03.md)
