#ifndef JACOBI_HPP
#define JACOBI_HPP

#include "SolveurBase.hpp"
#include <cmath>
#include <iostream>

class Jacobi : public SolveurBase {
private:
    double* xOld; // Stocke l'ancienne solution
    double* Ax;   // A*x

public:
    // Constructeur qui alloue les vecteurs de travail
    Jacobi(const double* A_, const double* b_, double* x_, int n_)
        : SolveurBase(A_, b_, x_, n_), xOld(new double[n]), Ax(new double[n]) {}

    // Destructeur pour libérer la mémoire
    ~Jacobi() override {
        delete[] xOld;
        delete[] Ax;
    }

    void solve() const override {
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
