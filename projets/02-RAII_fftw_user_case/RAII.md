# Encapsulation de FFTW avec RAII

L’objectif de ce projet est de comprendre comment manipuler la **Transformée de Fourier Rapide** (FFT) en C++ en s’appuyant sur la bibliothèque **FFTW**, tout en respectant les bonnes pratiques modernes de programmation orientée objet, notamment l’idiome **RAII** (*Resource Acquisition Is Initialization*).

Nous allons écrire deux classes `FFT1D` et `FFT2D` qui encapsulent FFTW de manière sécurisée et intuitive. L’idée est de rendre l’utilisation de la FFT aussi simple qu’un appel à une méthode d’une classe C++, sans avoir à gérer manuellement les pointeurs ou les libérations de mémoire.


## Qu'est ce qu'une FFT

### FFT en 1D

La **transformée de Fourier discrète** (DFT) est un outil mathématique qui permet de représenter un signal périodique comme une somme de sinus et cosinus de fréquences différentes.

Pour un signal $f(x)$ discrétisé en $N$ points $f_j$, la DFT est définie par :

$$
\hat{f}_k = \sum_{j=0}^{N-1} f_j \, e^{-2i \pi j k / N}, \quad k=0,\dots,N-1
$$

La FFT (Fast Fourier Transform) est un **algorithme efficace** qui réduit la complexité de calcul de $O(N^2)$ à $O(N \log N)$.
En pratique, elle permet d’analyser rapidement le spectre fréquentiel d’un signal 1D, par exemple un son.



### FFT en 2D

La FFT peut être généralisée aux fonctions de deux variables $f(x,y)$. La formule devient :

$$
\hat{f}_{k,\ell} = \sum_{j=0}^{N_x-1} \sum_{m=0}^{N_y-1} f_{j,m} \, e^{-2i \pi (jk/N_x + m\ell/N_y)}
$$

Cela permet de décomposer une image 2D en une somme d’ondes planes de différentes fréquences spatiales.

* Les **basses fréquences** correspondent aux variations lentes (zones homogènes).
* Les **hautes fréquences** correspondent aux détails fins (bords, textures).

C’est ce principe qui est utilisé dans de nombreux algorithmes de **compression d’images** (par exemple JPEG repose sur une transformée de type cosinus discrète, proche de la FFT). En annulant ou réduisant certaines hautes fréquences, on peut obtenir une image plus compacte tout en conservant une bonne qualité visuelle.


## Votre travail

Vous allez implémenter deux classes :

* `FFT1D` : pour effectuer des FFT sur des signaux 1D.
* `FFT2D` : pour effectuer des FFT sur des champs bidimensionnels (par exemple des images).

Ces classes devront **gérer automatiquement les ressources FFTW** (allocation, plans, libération) grâce à RAII.

Un programme de test (`main.cpp`) permettra :

1. D’appliquer la FFT 1D à un signal sinusoidal et d’observer son spectre (deux pics).
2. D’appliquer la FFT 2D à une fonction périodique 2D, ou même à une image, pour observer la distribution fréquentielle.
3. D’esquisser une idée de **compression d’image** en supprimant une partie des hautes fréquences et en reconstruisant l’image.


## Organisation du projet

L’arborescence proposée est la suivante :

```
projet_fft/
 ├── CMakeLists.txt
 ├── include/
 │    ├── FFT1D.hpp
 │    └── FFT2D.hpp
 ├── src/
 │    ├── FFT1D.cpp
 │    ├── FFT2D.cpp
 │    └── main.cpp
 └── README.md
```

* `FFT1D.hpp` et `FFT2D.hpp` contiendront les définitions des classes.
* `FFT1D.cpp` et `FFT2D.cpp` contiendront leur implémentation.
* `main.cpp` servira à tester et illustrer les fonctionnalités.


## Compilation avec CMake

Un fichier `CMakeLists.txt` permettra de configurer le projet et de lier la bibliothèque FFTW :

```cmake
cmake_minimum_required(VERSION 3.10)
project(ProjetFFT CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(FFTW3 REQUIRED)

include_directories(include)

add_executable(projet_fft
    src/main.cpp
    src/FFT1D.cpp
    src/FFT2D.cpp
)

target_link_libraries(projet_fft PRIVATE FFTW3::fftw3 FFTW3::fftw3_threads)
```

---

## Perspectives

Avec ce projet, vous aurez manipulé :

* La programmation **orientée objet** en C++ (constructeurs, destructeurs, encapsulation).
* L’idiome **RAII** pour gérer des ressources externes (ici FFTW).
* La **FFT en 1D et 2D** appliquée à des signaux et des images.

En extension, vous pourriez :

* Charger une image en niveaux de gris, appliquer une FFT 2D, supprimer une partie des hautes fréquences, puis reconstruire l’image pour simuler une compression.
* Comparer le résultat visuel et la taille mémoire des fichiers.
