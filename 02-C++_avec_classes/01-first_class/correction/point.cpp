#include "point.h"

// Constructeur par défaut
Point::Point() : x(0.0), y(0.0) {}

// Constructeur paramétré
Point::Point(double x, double y) : x(x), y(y) {}

// Constructeur de copie
Point::Point(const Point &p) : x(p.x), y(p.y) {}

// Getters par valeur (const)
double Point::getX() const { return x; }
double Point::getY() const { return y; }

// Getters par référence (modifiable)
double &Point::getX() { return x; }
double &Point::getY() { return y; }

// Setters
void Point::setX(double newX) { x = newX; }
void Point::setY(double newY) { y = newY; }

// Fonction amie
double distance(const Point &a, const Point &b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return std::sqrt(dx * dx + dy * dy);
}

// Méthode d'affichage
void Point::print() const {
    std::cout << "(" << x << ", " << y << ")";
}

