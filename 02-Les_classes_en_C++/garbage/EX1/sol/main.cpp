#include <iostream>
#include "point.h"

int main() {
    Point p1;                       // Utilisation du constructeur par défaut
    Point p2(3.0, 4.0);             // Utilisation du constructeur paramétré

    // Affichage des coordonnées initiales
    std::cout << "p1: (" << p1.getX() << ", " << p1.getY() << ")" << std::endl;
    std::cout << "p2: (" << p2.getX() << ", " << p2.getY() << ")" << std::endl;

    // Option 1 : Utilisation des setters pour modifier les coordonnées
    p1.setX(1.0);
    p1.setY(2.0);

    // Option 2 : Modification directe via les getters qui retournent des références
    // p1.getX() = 1.0;
    // p1.getY() = 2.0;

    // Affichage des nouvelles coordonnées et de la distance
    std::cout << "p1: (" << p1.getX() << ", " << p1.getY() << ")" << std::endl;
    std::cout << "Distance between p1 and p2: " << distance(p1, p2) << std::endl;

    return 0;
}

