#include <vector>
#include <iostream>
#include <cmath>
#include <cassert>

class CSRMatrix {
public:
    // Constructeurs
    CSRMatrix(int rows, int cols)
        : rows_(rows), cols_(cols) {
        row_ptrs_.resize(rows + 1, 0);
    }

    CSRMatrix(int rows, int cols, const std::vector<double>& values,
              const std::vector<int>& col_indices, const std::vector<int>& row_ptrs)
        : rows_(rows), cols_(cols), values_(values), col_indices_(col_indices), row_ptrs_(row_ptrs) {}

    // Méthode pour ajouter un élément
    void add_value(int row, int col, double value) {
        assert(row >= 0 && row < rows_);
        assert(col >= 0 && col < cols_);
        values_.push_back(value);
        col_indices_.push_back(col);
        row_ptrs_[row + 1]++;
    }

    // Finaliser la matrice après toutes les insertions
    void finalize() {
        for (int i = 1; i <= rows_; ++i) {
            row_ptrs_[i] += row_ptrs_[i - 1];
        }
    }

    // Surcharge de l'opérateur de multiplication avec un vecteur
    std::vector<double> operator*(const std::vector<double>& x) const {
        assert(cols_ == x.size());
        std::vector<double> result(rows_, 0.0);
        
        for (int i = 0; i < rows_; ++i) {
            for (int j = row_ptrs_[i]; j < row_ptrs_[i + 1]; ++j) {
                result[i] += values_[j] * x[col_indices_[j]];
            }
        }

        return result;
    }

    // Affichage de la matrice
    friend std::ostream& operator<<(std::ostream& os, const CSRMatrix& matrix) {
        os << "Values: ";
        for (double v : matrix.values_) {
            os << v << " ";
        }
        os << "\nColumn indices: ";
        for (int c : matrix.col_indices_) {
            os << c << " ";
        }
        os << "\nRow pointers: ";
        for (int r : matrix.row_ptrs_) {
            os << r << " ";
        }
        os << "\n";
        return os;
    }

private:
    int rows_, cols_;
    std::vector<double> values_;        // Valeurs non nulles
    std::vector<int> col_indices_;      // Indices des colonnes correspondantes
    std::vector<int> row_ptrs_;         // Pointeurs vers le début de chaque ligne
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
std::vector<double> conjugate_gradient(const CSRMatrix& A, const std::vector<double>& b, double tol = 1e-10) {
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
    // Exemple d'utilisation de CSRMatrix pour une matrice 3x3
    CSRMatrix A(3, 3);
    A.add_value(0, 0, 4.0);
    A.add_value(0, 1, 1.0);
    A.add_value(1, 0, 1.0);
    A.add_value(1, 1, 3.0);
    A.add_value(1, 2, 1.0);
    A.add_value(2, 1, 1.0);
    A.add_value(2, 2, 2.0);

    A.finalize();

    std::cout << "Matrice A:\n" << A << std::endl;

    std::vector<double> b = {1.0, 2.0, 3.0};

    std::vector<double> x = conjugate_gradient(A, b);

    std::cout << "Solution x:\n";
    for (double v : x) {
        std::cout << v << " ";
    }
    std::cout << std::endl;

    return 0;
}

