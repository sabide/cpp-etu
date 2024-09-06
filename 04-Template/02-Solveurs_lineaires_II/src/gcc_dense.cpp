#include <vector>
#include <iostream>
#include <cmath>
#include <cassert>

class DenseMatrix {
public:
    // Constructeur
    DenseMatrix(int rows, int cols)
        : rows_(rows), cols_(cols), data_(new double[rows * cols]()) {}

    // Destructeur
    ~DenseMatrix() {
        delete[] data_;
    }

    // Accès à un élément (en lecture)
    double operator()(int row, int col) const {
        assert(row >= 0 && row < rows_);
        assert(col >= 0 && col < cols_);
        return data_[row * cols_ + col];
    }

    // Accès à un élément (en écriture)
    double& operator()(int row, int col) {
        assert(row >= 0 && row < rows_);
        assert(col >= 0 && col < cols_);
        return data_[row * cols_ + col];
    }

    // Surcharge de l'opérateur de multiplication avec un vecteur
    std::vector<double> operator*(const std::vector<double>& x) const {
        assert(cols_ == x.size());
        std::vector<double> result(rows_, 0.0);
        
        for (int i = 0; i < rows_; ++i) {
            for (int j = 0; j < cols_; ++j) {
                result[i] += (*this)(i, j) * x[j];
            }
        }

        return result;
    }

    // Affichage de la matrice
    friend std::ostream& operator<<(std::ostream& os, const DenseMatrix& matrix) {
        for (int i = 0; i < matrix.rows_; ++i) {
            for (int j = 0; j < matrix.cols_; ++j) {
                os << matrix(i, j) << " ";
            }
            os << std::endl;
        }
        return os;
    }

private:
    int rows_, cols_;
    double* data_; // Tableau unidimensionnel pour stocker les éléments de la matrice
};

// Fonction pour calculer le produit scalaire de deux vecteurs
double dot(const std::vector<double>& a, const std::vector<double>& b) {
    assert(a.size() == b.size());
    double result = 0.0;
    for (size_t i = 0; i < a.size(); ++i) {
        result += a[i] * b[i];
    }
    return result;
}

// Algorithme du Gradient Conjugué
std::vector<double> conjugate_gradient(const DenseMatrix& A, const std::vector<double>& b, double tol = 1e-10) {
    int n = b.size();
    std::vector<double> x(n, 0.0);
    std::vector<double> r = b;  // r = b - Ax, avec x initialisé à 0, donc r = b
    std::vector<double> p = r;
    double rs_old = dot(r, r);

    for (int i = 0; i < n; ++i) {
        std::vector<double> Ap = A * p;
        double alpha = rs_old / dot(p, Ap);

        for (int j = 0; j < n; ++j) {
            x[j] += alpha * p[j];
            r[j] -= alpha * Ap[j];
        }

        double rs_new = dot(r, r);
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

    // Déclaration et initialisation d'une matrice dense 3x3
    DenseMatrix A(n, n);
    A(0, 0) = 4.0; A(0, 1) = 1.0; A(0, 2) = 0.0;
    A(1, 0) = 1.0; A(1, 1) = 3.0; A(1, 2) = 1.0;
    A(2, 0) = 0.0; A(2, 1) = 1.0; A(2, 2) = 2.0;

    // Vecteur b
    std::vector<double> b = {1.0, 2.0, 3.0};

    // Vecteur x initialisé à zéro
    std::vector<double> x = conjugate_gradient(A, b);

    // Affichage du résultat
    std::cout << "Solution x:\n";
    for (double v : x) {
        std::cout << v << " ";
    }
    std::cout << std::endl;

    return 0;
}

