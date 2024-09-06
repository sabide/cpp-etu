#include <iostream>
#include "MatrixBase.hpp"
#include "MatrixCSR.hpp"
#include "MatrixDense.hpp"

// Fonction pour calculer le produit scalaire de deux vecteurs
template <typename T>
T dot(const std::vector<T>& a, const std::vector<T>& b) {
    assert(a.size() == b.size());
    T result = 0.0;
    for (size_t i = 0; i < a.size(); ++i) {
        result += a[i] * b[i];
    }
    return result;
}


template <typename Matrix, typename T>
std::vector<T> conjugate_gradient(const Matrix& A, const std::vector<T>& b, T tol = 1e-10) {
    int n = A.rows();
    std::vector<T> x(n, 0.0);
    std::vector<T> r = b;  // r = b - Ax, avec x initialisé à 0, donc r = b
    std::vector<T> p = r;
    T rs_old = dot(r, r);

    for (int i = 0; i < n; ++i) {
        std::vector<T> Ap = A * p;
        T alpha = rs_old / dot(p, Ap);

        for (int j = 0; j < n; ++j) {
            x[j] += alpha * p[j];
            r[j] -= alpha * Ap[j];
        }

        T rs_new = dot(r, r);
        if (std::sqrt(rs_new) < tol) {
            break;
        }

        for (int j = 0; j < n; ++j) {
            p[j] = r[j] + (rs_new / rs_old) * p[j];
        }
        rs_old = rs_new;
    }

    return x;
}



int main() {
    int n = 3;

    // Exemple avec une matrice dense
    DenseMatrix<double> A_dense(n, n);
    A_dense(0, 0) = 4.0; A_dense(0, 1) = 1.0; A_dense(0, 2) = 0.0;
    A_dense(1, 0) = 1.0; A_dense(1, 1) = 3.0; A_dense(1, 2) = 1.0;
    A_dense(2, 0) = 0.0; A_dense(2, 1) = 1.0; A_dense(2, 2) = 2.0;

    std::vector<double> b = {1.0, 2.0, 3.0};

    std::vector<double> x_dense = conjugate_gradient(A_dense, b);

    std::cout << "Solution x (dense):\n";
    for (double v : x_dense) {
        std::cout << v << " ";
    }
    std::cout << std::endl;

    // Exemple avec une matrice creuse (CSR)
    CSRMatrix<double> A_sparse(n, n);
    A_sparse.add_value(0, 0, 4.0);
    A_sparse.add_value(0, 1, 1.0);
    A_sparse.add_value(1, 0, 1.0);
    A_sparse.add_value(1, 1, 3.0);
    A_sparse.add_value(1, 2, 1.0);
    A_sparse.add_value(2, 1, 1.0);
    A_sparse.add_value(2, 2, 2.0);
    A_sparse.finalize();

    std::vector<double> x_sparse = conjugate_gradient(A_sparse, b);

    std::cout << "Solution x (sparse):\n";
    for (double v : x_sparse) {
        std::cout << v << " ";
    }
    std::cout << std::endl;

    return 0;
}

