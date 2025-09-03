#include "point.h"
#include <iostream>

int main() {
    // 1. Crée un point p1 avec le constructeur par défaut
    Point p1;
    
    // 2. Crée un point p2 avec le constructeur paramétré
    Point p2(3.0, 4.0);

    // 3. Affiche les coordonnées
    std::cout << "p1 = "; p1.print(); std::cout << std::endl;
    std::cout << "p2 = "; p2.print(); std::cout << std::endl;

    // 4. Modifie p1
    // Option 1 : avec setters
    p1.setX(1.0);
    p1.setY(2.0);

    // Option 2 : via références
    // p1.getX() = 1.0;
    // p1.getY() = 2.0;

    std::cout << "p1 modifié = "; p1.print(); std::cout << std::endl;

    // 5. Distance entre p1 et p2
    std::cout << "Distance(p1, p2) = " << distance(p1, p2) << std::endl;

    return 0;
}
