#ifndef CG_HPP
#define CG_HPP

#include "SolveurBase.hpp"
#include <cmath>
#include <iostream>

class CG : public SolveurBase {
private:
    double* r;  // Résidu
    double* p;  // Direction de recherche
    double* Ap; // A*p

public:
    // Constructeur qui alloue les vecteurs de travail
    CG(const double* A_, const double* b_, double* x_, int n_)
        : SolveurBase(A_, b_, x_, n_), r(new double[n]), p(new double[n]), Ap(new double[n]) {}

    // Destructeur pour libérer la mémoire
    ~CG() override {
        delete[] r;
        delete[] p;
        delete[] Ap;
    }

    void solve() const override {
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

