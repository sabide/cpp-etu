#include <iostream>
#include <fstream>  // Pour écrire dans des fichiers
#include <cmath>

// Paramètres du modèle de Lotka-Volterra
const double alpha = 1.0;
const double beta = 0.1;
const double gamma = 1.5;
const double delta = 0.075;

// Fonction pour la méthode d'Euler explicite
void euler_explicit(double h, int n_steps, double x0, double y0, const std::string& filename) {
    double x = x0;
    double y = y0;

    std::ofstream file(filename);
    file << "# time,x,y\n";  // En-tête du fichier CSV

    for (int i = 0; i <= n_steps; ++i) {
        double t = i * h;
        file << t << " " << x << " " << y << "\n";

        double x_new = x + h * (alpha * x - beta * x * y);
        double y_new = y + h * (delta * x * y - gamma * y);

        x = x_new;
        y = y_new;
    }

    file.close();
}

// Fonction pour la méthode d'Euler implicite
void euler_implicit(double h, int n_steps, double x0, double y0, const std::string& filename) {
    double x = x0;
    double y = y0;

    std::ofstream file(filename);
    file << "time,x,y\n";  // En-tête du fichier CSV

    for (int i = 0; i <= n_steps; ++i) {
        double t = i * h;
        file << t << " " << x << " " << y << "\n";

        // Initialisation avec les valeurs précédentes
        double x_new = x;
        double y_new = y;

        // Méthode des points fixes (itération pour résoudre les équations implicites)
        for (int j = 0; j < 10; ++j) {
            x_new = x + h * (alpha * x_new - beta * x_new * y_new);
            y_new = y + h * (delta * x_new * y_new - gamma * y_new);
        }

        x = x_new;
        y = y_new;
    }

    file.close();
}

int main() {
    double h = 0.01;      // Pas de temps
    int n_steps = 100;    // Nombre de pas
    double x0 = 10.0;     // Population initiale des proies
    double y0 = 5.0;      // Population initiale des prédateurs

    // Résolution avec Euler explicite et sauvegarde dans un fichier CSV
    euler_explicit(h, n_steps, x0, y0, "euler_explicit.csv");

    // Résolution avec Euler implicite et sauvegarde dans un fichier CSV
    euler_implicit(h, n_steps, x0, y0, "euler_implicit.csv");

    return 0;
}

