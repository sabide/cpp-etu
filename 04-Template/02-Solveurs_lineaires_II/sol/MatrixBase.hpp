#include <vector>
#include <iostream>
#include <cmath>
#include <cassert>

template <typename T>
class MatrixBase {
public:
    virtual ~MatrixBase() = default;

    // Multiplication matrice-vecteur purement virtuelle
    virtual std::vector<T> operator*(const std::vector<T>& x) const = 0;

    // Fonction pour accéder au nombre de lignes
    virtual int rows() const = 0;

    // Fonction pour accéder au nombre de colonnes
    virtual int cols() const = 0;
};

