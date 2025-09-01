# Exercice 2 : Projet multi-sources avec CMake

L’objectif est de compiler automatiquement un projet C++ contenant plusieurs fichiers, en séparant le programme principal des fonctions auxiliaires.

## Étapes à réaliser

1. **Créer l’arborescence du projet** :

   ```
   exercice2/
    ├── CMakeLists.txt   <-- fichier de configuration pour CMake
    ├── main.cpp         <-- programme principal
    ├── fonctions.cpp    <-- implémentation des fonctions
    └── fonctions.h      <-- déclarations des fonctions
   ```

2. **Écrire un programme principal** (`main.cpp`) qui utilise une fonction définie ailleurs (par exemple une fonction mathématique).

3. **Définir les prototypes** des fonctions dans `fonctions.h`.

4. **Écrire l’implémentation** des fonctions dans `fonctions.cpp`.

5. **Configurer CMake** dans `CMakeLists.txt` :

   * Définir la version minimale de CMake,
   * Donner un nom au projet,
   * Spécifier le standard C++ à utiliser (ex. C++11),
   * Déclarer un exécutable à partir de `main.cpp` **et** `fonctions.cpp`.

6. **Compiler avec CMake** depuis un dossier séparé :

   ```bash
   mkdir build
   cd build
   cmake ..
   make
   ./mon_exe
   ```


## Savoir faire 

À la fin de l’exercice, vous devez :

* comprendre comment organiser un projet en plusieurs fichiers,
* utiliser un fichier **header** (`.h`) pour les déclarations,
* automatiser la compilation avec **CMake** même quand le projet contient plusieurs sources.
