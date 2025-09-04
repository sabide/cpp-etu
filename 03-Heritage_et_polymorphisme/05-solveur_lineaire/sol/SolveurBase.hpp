#ifndef SOLVEURBASE_HPP
#define SOLVEURBASE_HPP

class SolveurBase {
protected:
    const double* A; // Pointeur vers la matrice A
    const double* b; // Pointeur vers le vecteur b
    double* x;       // Pointeur vers le vecteur solution x
    int n;           // Taille du système (taille des vecteurs et dimension de la matrice)

public:
    // Constructeur qui initialise les attributs
    SolveurBase(const double* A_, const double* b_, double* x_, int n_) 
        : A(A_), b(b_), x(x_), n(n_) {}

    // Méthode virtuelle pure pour résoudre le système linéaire
    virtual void solve() const = 0;

    // Destructeur virtuel
    virtual ~SolveurBase() {}
};

#endif // SOLVEURBASE_HPP

