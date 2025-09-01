Parfait 👍 Voici un document **Markdown** qui présente la **correction complète** de l’exercice sur les tableaux et les différences finies, avec les trois variantes (pointeurs, `std::array`, `std::vector`) et un `CMakeLists.txt`.

---

````markdown
# Correction – Utilisation des tableaux pour les différences finies

## Objectif
On cherche à approximer numériquement la dérivée seconde d’une fonction en utilisant la méthode des différences finies.  
Trois implémentations sont proposées pour manipuler les tableaux en C++ :  
1. avec des **pointeurs bruts**,  
2. avec `std::array`,  
3. avec `std::vector`.  

---

## Rappel de la formule
Sur une grille \( x_i = i h, \, 0 \leq i \leq n, \, h = 1/n \),  
on approxime la dérivée seconde par :  

\[
f''(x_i) \approx \frac{f_{i+1} - 2 f_i + f_{i-1}}{h^2}, \quad 0 < i < n.
\]

La fonction test est :
\[
f(x) = -\frac{\sin(2\pi x)}{4\pi^2}, \quad f''(x) = \sin(2\pi x).
\]

---

## Version 1 : pointeurs (`main_pointers.cpp`)

```cpp
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

constexpr double PI = 3.141592653589793;

double f(double x) { return -sin(2.0 * PI * x) / (4.0 * PI * PI); }
double fpp_exact(double x) { return sin(2.0 * PI * x); }

int main() {
    int n = 100;
    double h = 1.0 / n;

    double* X = new double[n+1];
    double* F = new double[n+1];
    double* Fpp = new double[n+1];

    for (int i = 0; i <= n; i++) {
        X[i] = i * h;
        F[i] = f(X[i]);
    }
    for (int i = 1; i < n; i++) {
        Fpp[i] = (F[i+1] - 2*F[i] + F[i-1]) / (h*h);
    }

    double err_max = 0.0;
    for (int i = 1; i < n; i++) {
        err_max = max(err_max, fabs(Fpp[i] - fpp_exact(X[i])));
    }
    cout << "[Pointeurs] Erreur max = " << err_max << endl;

    delete[] X; delete[] F; delete[] Fpp;
    return 0;
}
````

✅ Avantages : contrôle fin de la mémoire.
❌ Inconvénients : risque de fuites mémoire, erreurs de segmentation.

---

## Version 2 : `std::array` (`main_array.cpp`)

```cpp
#include <iostream>
#include <cmath>
#include <array>
#include <algorithm>
using namespace std;

constexpr double PI = 3.141592653589793;
const int N = 100;

double f(double x) { return -sin(2.0 * PI * x) / (4.0 * PI * PI); }
double fpp_exact(double x) { return sin(2.0 * PI * x); }

int main() {
    constexpr double h = 1.0 / N;
    array<double, N+1> X{};
    array<double, N+1> F{};
    array<double, N+1> Fpp{};

    for (int i = 0; i <= N; i++) {
        X[i] = i * h;
        F[i] = f(X[i]);
    }
    for (int i = 1; i < N; i++) {
        Fpp[i] = (F[i+1] - 2*F[i] + F[i-1]) / (h*h);
    }

    double err_max = 0.0;
    for (int i = 1; i < N; i++) {
        err_max = max(err_max, fabs(Fpp[i] - fpp_exact(X[i])));
    }
    cout << "[std::array] Erreur max = " << err_max << endl;
    return 0;
}
```

✅ Avantages : sécurité accrue (pas de `delete[]` à gérer).
❌ Limité aux tailles **connues à la compilation**.

---

## Version 3 : `std::vector` (`main_vector.cpp`)

```cpp
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

constexpr double PI = 3.141592653589793;

double f(double x) { return -sin(2.0 * PI * x) / (4.0 * PI * PI); }
double fpp_exact(double x) { return sin(2.0 * PI * x); }

int main() {
    int n = 100;
    double h = 1.0 / n;

    vector<double> X(n+1), F(n+1), Fpp(n+1);

    for (int i = 0; i <= n; i++) {
        X[i] = i * h;
        F[i] = f(X[i]);
    }
    for (int i = 1; i < n; i++) {
        Fpp[i] = (F[i+1] - 2*F[i] + F[i-1]) / (h*h);
    }

    double err_max = 0.0;
    for (int i = 1; i < n; i++) {
        err_max = max(err_max, fabs(Fpp[i] - fpp_exact(X[i])));
    }
    cout << "[std::vector] Erreur max = " << err_max << endl;
    return 0;
}
```

✅ Avantages : taille dynamique, sécurité mémoire, souplesse.
❌ Légèrement plus coûteux que `std::array` ou pointeurs.

---

## Fichier `CMakeLists.txt`

```cmake
cmake_minimum_required(VERSION 3.10)
project(DeriveeSeconde)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(derivee_pointers main_pointers.cpp)
add_executable(derivee_array main_array.cpp)
add_executable(derivee_vector main_vector.cpp)
```

---

## Compilation et exécution

```bash
mkdir build
cd build
cmake ..
make
./derivee_pointers
./derivee_array
./derivee_vector
```

---

## Résultats attendus

Chacun des trois programmes affiche une **erreur maximale très faible** (de l’ordre de $10^{-3}$ à $10^{-4}$ pour $n=100$), ce qui confirme la bonne convergence de la méthode.

---

## Conclusion

* Les **pointeurs** donnent un contrôle total mais demandent une gestion manuelle de la mémoire.
* `std::array` apporte une meilleure sécurité et une lisibilité accrue, mais n’est pas flexible en taille.
* `std::vector` combine sécurité et flexibilité, et constitue le choix naturel en C++ moderne pour les calculs numériques.

```

---

👉 Veux-tu que je génère aussi une **version "énoncé + correction"** dans le **même fichier Markdown** (avec un sommaire Exercices / Corrections), pour que tes étudiants aient tout en un seul document ?
```

