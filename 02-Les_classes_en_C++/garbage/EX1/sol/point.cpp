#include "point.h"
#include <cmath>

// Constructeur par défaut
Point::Point() : x(0), y(0) {}

// Constructeur paramétré
Point::Point(double x, double y) : x(x), y(y) {}

// Constructeur de copie
Point::Point(const Point &p) : x(p.x), y(p.y) {}

// Option 1 : Getters qui retournent des copies
double Point::getX() const {
    return x;
}

double Point::getY() const {
    return y;
}

// Option 2 : Getters qui retournent des références
double& Point::getX() {
    return x;
}

double& Point::getY() {
    return y;
}

// Setters
void Point::setX(double x) {
    this->x = x;
}

void Point::setY(double y) {
    this->y = y;
}

// Fonction amie pour calculer la distance entre deux points
double distance(const Point &p1, const Point &p2) {
    return std::sqrt(std::pow(p2.x - p1.x, 2) + std::pow(p2.y - p1.y, 2));
}

