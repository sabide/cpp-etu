# Exercice 1 : Projet mono-source avec CMake

L’objectif est de créer et compiler automatiquement un **projet C++ minimal** avec **CMake**, sans écrire directement la commande `g++`.

---

## Étapes à réaliser

1. **Créer l’arborescence du projet** :

   ```
   exercice1/
    ├── CMakeLists.txt   <-- fichier de configuration pour CMake
    └── main.cpp         <-- fichier source principal
   ```

2. **Écrire un programme C++ minimal** dans `main.cpp` qui affiche un message à l’écran.

3. **Configurer CMake** dans `CMakeLists.txt` :

   * Définir une version minimale de CMake,
   * Donner un nom au projet,
   * Spécifier le standard C++ à utiliser (par ex. C++11),
   * Déclarer un exécutable à partir du fichier source `main.cpp`.

4. **Compiler avec CMake** depuis un dossier séparé :

   ```bash
   mkdir build
   cd build
   cmake ..
   make
   ./mon_exe
   ```
 