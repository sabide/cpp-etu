# Introduction

Le but de ce projet est de construire un solveur de gradient conjugué
(CG) générique en utilisant la métaprogrammation template en C++. Vous
allez utiliser les implémentations existantes de matrices denses et
creuses (CSR) pour développer un solveur capable de résoudre des
systèmes linéaires $Ax = b$, où $A$ est représentée dans l'un des deux
formats.

## Objectifs

L'objectif de ce projet est de :

-   Comprendre et implémenter la métaprogrammation template en C++.

-   Généraliser les implémentations existantes de matrices denses et CSR
    pour les intégrer dans un solveur CG générique.

-   Tester et valider l'efficacité du solveur sur différentes instances
    de matrices.

## Implémentations Fournies

Les implémentations des matrices denses et CSR vous sont fournies. Vous
devez les généraliser à l'aide de templates pour construire un solveur
CG capable de travailler avec ces deux types de matrices.

### Classe `DenseMatrix`

```c++
template <typename T>
class DenseMatrix {
public:
    DenseMatrix(int rows, int cols)
        : rows_(rows), cols_(cols), data_(new T[rows * cols]()) {}

    ~DenseMatrix() {
        delete[] data_;
    }
    
    T operator()(int row, int col) const {
        assert(row >= 0 && row < rows_);
        assert(col >= 0 && col < cols_);
        return data_[row * cols_ + col];
    }

    T& operator()(int row, int col) {
        assert(row >= 0 && row < rows_);
        assert(col >= 0 && col < cols_);
        return data_[row * cols_ + col];
    }

    std::vector<T> operator*(const std::vector<T>& x) const {
        assert(cols_ == x.size());
        std::vector<T> result(rows_, 0.0);

        for (int i = 0; i < rows_; ++i) {
            for (int j = 0; j < cols_; ++j) {
                result[i] += (*this)(i, j) * x[j];
            }
        }

        return result;
    }

    int rows() const { return rows_; }
    int cols() const { return cols_; }

private:
    int rows_, cols_;
    T* data_;
};
```

### Classe `CSRMatrix`

```c++
template <typename T>
class CSRMatrix {
public:
    CSRMatrix(int rows, int cols)
        : rows_(rows), cols_(cols) {
        row_ptrs_.resize(rows + 1, 0);
    }

    void add_value(int row, int col, T value) {
        assert(row >= 0 && row < rows_);
        assert(col >= 0 && col < cols_);
        values_.push_back(value);
        col_indices_.push_back(col);
        row_ptrs_[row + 1]++;
    }

    void finalize() {
        for (int i = 1; i <= rows_; ++i) {
            row_ptrs_[i] += row_ptrs_[i - 1];
        }
    }

    std::vector<T> operator*(const std::vector<T>& x) const {
        assert(cols_ == x.size());
        std::vector<T> result(rows_, 0.0);

        for (int i = 0; i < rows_; ++i) {
            for (int j = row_ptrs_[i]; j < row_ptrs_[i + 1]; ++j) {
                result[i] += values_[j] * x[col_indices_[j]];
            }
        }

        return result;
    }

    int rows() const { return rows_; }
    int cols() const { return cols_; }

private:
    int rows_, cols_;
    std::vector<T> values_;
    std::vector<int> col_indices_;
    std::vector<int> row_ptrs_;
};
```

## Travail à Réaliser

### 1. Généralisation avec les Templates

Vous devez généraliser les deux classes `DenseMatrix` et `CSRMatrix` en
utilisant une interface commune basée sur les templates. Pour cela,
créez une classe abstraite `MatrixBase` qui définira l'interface commune
aux deux types de matrices.

```c++
template <typename T>
class MatrixBase {
public:
    virtual ~MatrixBase() = default;

    virtual std::vector<T> operator*(const std::vector<T>& x) const = 0;
    virtual int rows() const = 0;
    virtual int cols() const = 0;
};
```

Modifiez ensuite les classes `DenseMatrix` et `CSRMatrix` pour qu'elles
héritent de cette interface commune `MatrixBase`.

### 2. Implémentation du Solveur CG Générique

Implémentez un solveur CG générique en utilisant la métaprogrammation
template. Ce solveur doit être capable de résoudre des systèmes
linéaires pour n'importe quel type de matrice dérivé de `MatrixBase`.


### 3. Tests et Validation

Testez votre solveur avec les deux types de matrices fournis. Par
exemple, vous pouvez résoudre le système suivant :

$$\begin{pmatrix}
4 & 1 & 0 \\
1 & 3 & 1 \\
0 & 1 & 2 \\
\end{pmatrix}
\begin{pmatrix}
x_1 \\
x_2 \\
x_3 \\
\end{pmatrix}
=
\begin{pmatrix}
1 \\
2 \\
3 \\
\end{pmatrix}$$

Discutez les performances de votre solveur sur un système linéaire de plus grande taille.

## Livreables

Le projet doit être rendu sous forme de code source C++ compilable accompagné d'un 
rapport détaillant votre approche et une analyse des résultats obtenus.