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
    SolveurBase* solveur = new CG(A, b, x, n);
    solveur->solve();

    std::cout << "Solution avec CG:" << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cout << x[i] << std::endl;
    }

    delete solveur;

    // Réinitialiser x à zéro
    for (int i = 0; i < n; ++i) {
        x[i] = 0.0;
    }

    // Résolution avec Jacobi
    solveur = new Jacobi(A, b, x, n);
    solveur->solve();

    std::cout << "Solution avec Jacobi:" << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cout << x[i] << std::endl;
    }

    delete solveur;

    return 0;
}

