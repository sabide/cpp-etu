#include "rectangle.h"

// Constructeur par défaut
Rectangle::Rectangle() : width(0), height(0) {}

// Constructeur paramétré
Rectangle::Rectangle(double w, double h) : width(w), height(h) {}

// Getter pour la largeur
double Rectangle::getWidth() const {
    return width;
}

// Getter pour la hauteur
double Rectangle::getHeight() const {
    return height;
}

// Setter pour la largeur
void Rectangle::setWidth(double w) {
    width = w;
}

// Setter pour la hauteur
void Rectangle::setHeight(double h) {
    height = h;
}

// Méthode de la classe amie pour calculer l'aire du rectangle
double RectangleUtils::calculateArea(const Rectangle& rect) {
    return rect.width * rect.height;
}

// Méthode de la classe amie pour calculer le périmètre du rectangle
double RectangleUtils::calculatePerimeter(const Rectangle& rect) {
    return 2 * (rect.width + rect.height);
}

