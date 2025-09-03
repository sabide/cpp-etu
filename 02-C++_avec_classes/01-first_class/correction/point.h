#ifndef POINT_H
#define POINT_H

#include <iostream>
#include <cmath>

class Point {
private:
    double x, y;

public:
    // Constructeur par défaut
    Point();

    // Constructeur paramétré
    Point(double x, double y);

    // Constructeur de copie
    Point(const Point &p);

    // Getters (option 1 : retour par valeur)
    double getX() const;
    double getY() const;

    // Getters (option 2 : retour par référence modifiable)
    double &getX();
    double &getY();

    // Setters
    void setX(double newX);
    void setY(double newY);

    // Fonction amie
    friend double distance(const Point &a, const Point &b);

    // Méthode d'affichage utile
    void print() const;
};

#endif // POINT_H
