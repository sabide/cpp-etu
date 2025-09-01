# Exercice 3 : Projet avec librairie statique et CMake

L’objectif est de compiler un projet C++ où certaines fonctions sont regroupées dans une **librairie statique** (`.a`), puis utilisées par le programme principal.

---

## Étapes à réaliser

1. **Créer l’arborescence du projet** :

   ```
   exercice3/
    ├── CMakeLists.txt   <-- fichier de configuration pour CMake
    ├── main.cpp         <-- programme principal
    ├── fonctions.cpp    <-- implémentation des fonctions
    └── fonctions.h      <-- déclarations des fonctions
   ```

2. **Écrire un fichier d’en-tête** (`fonctions.h`) pour déclarer les prototypes des fonctions.

3. **Écrire un fichier d’implémentation** (`fonctions.cpp`) contenant le code de ces fonctions.

4. **Écrire un programme principal** (`main.cpp`) qui utilise ces fonctions.

5. **Configurer CMake** dans `CMakeLists.txt` pour :

   * définir la version minimale de CMake,
   * donner un nom au projet,
   * spécifier le standard C++ à utiliser (par ex. C++11),
   * créer une **librairie statique** à partir de `fonctions.cpp`,
   * créer un exécutable à partir de `main.cpp`,
   * lier l’exécutable avec la librairie statique.

6. **Compiler avec CMake** depuis un dossier séparé :

   ```bash
   mkdir build
   cd build
   cmake ..
   make
   ./mon_exe
   ```

---

## Savoir faire 

À la fin de l’exercice, vous devez :

* comprendre ce qu’est une **librairie statique** (`libXXX.a`),
* savoir séparer un projet en modules réutilisables,
* automatiser la compilation et l’édition de liens avec **CMake**.
