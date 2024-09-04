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

// Fonction pour calculer le produit scalaire de deux vecteurs
double dotProduct(const double* v1, const double* v2, int n) {
    double result = 0.0;
    for (int i = 0; i < n; ++i) {
        result += v1[i] * v2[i];
    }
    return result;
}

// Fonction pour ajouter deux vecteurs
void vectorAdd(const double* v1, const double* v2, double* result, int n) {
    for (int i = 0; i < n; ++i) {
        result[i] = v1[i] + v2[i];
    }
}

// Fonction pour soustraire deux vecteurs
void vectorSubtract(const double* v1, const double* v2, double* result, int n) {
    for (int i = 0; i < n; ++i) {
        result[i] = v1[i] - v2[i];
    }
}

// Fonction pour multiplier un vecteur par un scalaire
void scalarMultiply(const double* v, double scalar, double* result, int n) {
    for (int i = 0; i < n; ++i) {
        result[i] = v[i] * scalar;
    }
}

// Implémentation de la méthode du gradient conjugué
void conjugateGradient(const double* A, const double* b, double* x, int n, int maxIterations = 1000, double tolerance = 1e-6) {
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

    for (int k = 0; k < maxIterations; ++k) {
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
         std::cout << std::sqrt(rsNew) << std::endl;
        // Vérification de la convergence
        if (std::sqrt(rsNew) < tolerance) {
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

    // Initialiser x à zéro
    double* x = new double[n];
    for (int i = 0; i < n; ++i) {
        x[i] = 0.0;
    }

    // Résoudre Ax = b avec la méthode du gradient conjugué
    conjugateGradient(A, b, x, n);

    // Afficher la solution x
    std::cout << "Solution x:" << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cout << x[i] << std::endl;
    }

    delete[] x;

    return 0;
}
