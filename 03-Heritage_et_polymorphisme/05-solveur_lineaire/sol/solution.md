Voici la solution pour l'implémentation de la classe de base `SolveurBase` et des classes dérivées `CG` et `Jacobi` en C++.

### Fichier `SolveurBase.hpp`

```cpp
#ifndef SOLVEURBASE_HPP
#define SOLVEURBASE_HPP

class SolveurBase {
public:
    // Méthode virtuelle pure pour résoudre le système linéaire
    virtual void solve(const double* A, const double* b, double* x, int n) const = 0;

    // Destructeur virtuel
    virtual ~SolveurBase() {}
};

#endif // SOLVEURBASE_HPP
```

### Fichier `CG.hpp`

```cpp
#ifndef CG_HPP
#define CG_HPP

#include "SolveurBase.hpp"
#include <cmath>
#include <iostream>
#include <cassert>

class CG : public SolveurBase {
public:
    void solve(const double* A, const double* b, double* x, int n) const override {
        double* r = new double[n];
        double* p = new double[n];
        double* Ap = new double[n];

        // Initialisation : r = b - A * x
        matVecMult(A, x, r, n);
        vectorSubtract(b, r, r, n);

        // p = r
        for (int i = 0; i < n; ++i) {
            p[i] = r[i];
        }

        double rsOld = dotProduct(r, r, n);

        for (int k = 0; k < 1000; ++k) {
            // Ap = A * p
            matVecMult(A, p, Ap, n);

            // alpha = rsOld / (p^T * Ap)
            double alpha = rsOld / dotProduct(p, Ap, n);

            // x = x + alpha * p
            for (int i = 0; i < n; ++i) {
                x[i] += alpha * p[i];
            }

            // r = r - alpha * Ap
            for (int i = 0; i < n; ++i) {
                r[i] -= alpha * Ap[i];
            }

            double rsNew = dotProduct(r, r, n);

            // Vérification de la convergence
            if (std::sqrt(rsNew) < 1e-6) {
                break;
            }

            // p = r + (rsNew / rsOld) * p
            for (int i = 0; i < n; ++i) {
                p[i] = r[i] + (rsNew / rsOld) * p[i];
            }

            rsOld = rsNew;
        }

        delete[] r;
        delete[] p;
        delete[] Ap;
    }

private:
    void matVecMult(const double* A, const double* x, double* result, int n) const {
        for (int i = 0; i < n; ++i) {
            result[i] = 0.0;
            for (int j = 0; j < n; ++j) {
                result[i] += A[i * n + j] * x[j];
            }
        }
    }

    double dotProduct(const double* v1, const double* v2, int n) const {
        double result = 0.0;
        for (int i = 0; i < n; ++i) {
            result += v1[i] * v2[i];
        }
        return result;
    }

    void vectorSubtract(const double* v1, const double* v2, double* result, int n) const {
        for (int i = 0; i < n; ++i) {
            result[i] = v1[i] - v2[i];
        }
    }
};

#endif // CG_HPP
```

### Fichier `Jacobi.hpp`

```cpp
#ifndef JACOBI_HPP
#define JACOBI_HPP

#include "SolveurBase.hpp"
#include <cmath>
#include <iostream>

class Jacobi : public SolveurBase {
public:
    void solve(const double* A, const double* b, double* x, int n) const override {
        double* xOld = new double[n];
        double* Ax = new double[n];

        for (int i = 0; i < n; ++i) {
            x[i] = 0.0;  // Initialisation de x à zéro
        }

        for (int k = 0; k < 1000; ++k) {
            // Copier x dans xOld
            for (int i = 0; i < n; ++i) {
                xOld[i] = x[i];
            }

            // Effectuer une itération de Jacobi
            for (int i = 0; i < n; ++i) {
                double sum = 0.0;
                for (int j = 0; j < n; ++j) {
                    if (i != j) {
                        sum += A[i * n + j] * xOld[j];
                    }
                }
                x[i] = (b[i] - sum) / A[i * n + i];
            }

            // Vérifier la convergence
            matVecMult(A, x, Ax, n);  // Calculer A * x
            double error = 0.0;
            for (int i = 0; i < n; ++i) {
                error += std::pow(Ax[i] - b[i], 2);
            }
            if (std::sqrt(error) < 1e-6) {
                break;
            }
        }

        delete[] xOld;
        delete[] Ax;
    }

private:
    void matVecMult(const double* A, const double* x, double* result, int n) const {
        for (int i = 0; i < n; ++i) {
            result[i] = 0.0;
            for (int j = 0; j < n; ++j) {
                result[i] += A[i * n + j] * x[j];
            }
        }
    }
};

#endif // JACOBI_HPP
```

### Fichier `main.cpp`

```cpp
#include "SolveurBase.hpp"
#include "CG.hpp"
#include "Jacobi.hpp"
#include <iostream>

int main() {
    // Exemple de matrice A 3x3 symétrique définie positive
    int n = 3;
    double A[] = {
        4, 1, 1,
        1, 3, 0,
        1, 0, 2
    };

    // Vecteur b
    double b[] = {1, 2, 3};

    // Vecteur solution x
    double x[n];

    // Résolution avec CG
    SolveurBase* solveur = new CG();
    solveur->solve(A, b, x, n);

    std::cout << "Solution avec CG:" << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cout << x[i] << std::endl;
    }

    delete solveur;

    // Résolution avec Jacobi
    solveur = new Jacobi();
    solveur->solve(A, b, x, n);

    std::cout << "Solution avec Jacobi:" << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cout << x[i] << std::endl;
    }

    delete solveur;

    return 0;
}
```

### Explication des classes

1. **Classe `SolveurBase`** :
   - Il s'agit d'une classe abstraite (virtuelle pure) qui définit une interface commune pour différents solveurs de systèmes linéaires via la méthode `solve`.

2. **Classe `CG`** :
   - Elle dérive de `SolveurBase` et implémente l'algorithme du gradient conjugué pour résoudre un système linéaire \( Ax = b \).
   - La méthode `solve` est responsable de la résolution en utilisant l'algorithme du gradient conjugué.

3. **Classe `Jacobi`** :
   - Elle dérive également de `SolveurBase` et implémente l'algorithme de Jacobi.
   - La méthode `solve` utilise l'algorithme de Jacobi pour résoudre le système \( Ax = b \).

4. **Programme principal (`main.cpp`)** :
   - Il teste les deux solveurs (`CG` et `Jacobi`) sur un exemple de système linéaire.
   - Les résultats des deux méthodes sont affichés, permettant de comparer les solutions obtenues.

Avec cette hiérarchie de classes, vous pouvez facilement étendre votre code en ajoutant de nouveaux solveurs en dérivant simplement de la classe `SolveurBase` et en implémentant la méthode `solve` pour chaque nouvelle méthode numérique.
