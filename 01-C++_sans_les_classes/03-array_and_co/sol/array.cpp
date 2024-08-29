#include <iostream>
#include <array>
#include <cmath>

const int n = 100;
const double h = 1.0 / n;

int main() {
    // Déclaration des tableaux avec std::array
    std::array<double, n + 1> X;
    std::array<double, n + 1> F;
    std::array<double, n + 1> Fpp;  // Fpp pour F'' (dérivée seconde)
    
    // Initialisation des tableaux X et F
    for (int i = 0; i <= n; ++i) {
        X[i] = i * h;
        F[i] = -sin(2 * M_PI * X[i]) / (4 * M_PI * M_PI);
    }
    
    // Calcul de la dérivée seconde Fpp
    for (int i = 1; i < n; ++i) {
        Fpp[i] = (F[i + 1] - 2 * F[i] + F[i - 1]) / (h * h);
    }
    
    // Calcul de l'erreur maximale (en supposant une solution théorique)
    double maxError = 0.0;
    for (int i = 1; i < n; ++i) {
        double theoretical = -sin(2 * M_PI * X[i]);  // Exemple de solution théorique
        double error = fabs(Fpp[i] - theoretical);
        if (error > maxError) {
            maxError = error;
        }
    }
    
    std::cout << "Erreur maximale : " << maxError << std::endl;

    return 0;
}

