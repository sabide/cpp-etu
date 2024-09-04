#include <iostream>
#include <cmath>
#include <cassert>

// Fonction pour multiplier une matrice pleine par un vecteur
void matVecMult(const double* A, const double* x, double* result, int n) {
    for (int i = 0; i < n; ++i) {
        result[i] = 0.0;
        for (int j = 0; j < n; ++j) {
            result[i] += A[i * n + j] * x[j];
        }
    }
}

// Implémentation de la méthode de Jacobi
void jacobi(const double* A, const double* b, double* x, int n, int maxIterations = 1000, double tolerance = 1e-6) {
    double* xOld = new double[n];
    double* Ax = new double[n];

    for (int i = 0; i < n; ++i) {
        x[i] = 0.0;  // Initialisation de x à zéro
    }

    for (int k = 0; k < maxIterations; ++k) {
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
        std::cout << std::sqrt(error) << std::endl;
        if (std::sqrt(error) < tolerance) {
            break;
        }
    }

    delete[] xOld;
    delete[] Ax;
}

int main() {
    // Exemple de matrice A 3x3
    int n = 3;
    double A[] = {
        4, 1, 1,
        1, 3, 0,
        1, 0, 2
    };

    // Vecteur b
    double b[] = {1, 2, 3};

    // Initialiser x à zéro
    double* x = new double[n];
    for (int i = 0; i < n; ++i) {
        x[i] = 0.0;
    }

    // Résoudre Ax = b avec la méthode de Jacobi
    jacobi(A, b, x, n);

    // Afficher la solution x
    std::cout << "Solution x:" << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cout << x[i] << std::endl;
    }

    delete[] x;

    return 0;
}
