#include <iostream>
#include "rectangle.h"

int main() {
    Rectangle rect1;                       // constructeur par défaut
    Rectangle rect2(4.0, 5.0);             // constructeur paramétré

    // Affichage des dimensions du rectangle
    std::cout << "Rectangle 2: Width = " << rect2.getWidth() << ", Height = " << rect2.getHeight() << std::endl;

    // Calcul et affichage de l'aire du rectangle
    double area = RectangleUtils::calculateArea(rect2);
    std::cout << "Area of Rectangle 2: " << area << std::endl;

    // Calcul et affichage du périmètre du rectangle
    double perimeter = RectangleUtils::calculatePerimeter(rect2);
    std::cout << "Perimeter of Rectangle 2: " << perimeter << std::endl;

    return 0;
}

