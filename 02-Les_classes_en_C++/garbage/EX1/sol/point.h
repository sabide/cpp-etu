#ifndef POINT_H
#define POINT_H

class Point {
private:
    double x, y;

public:
    Point();                          // Constructeur par défaut
    Point(double x, double y);        // Constructeur paramétré
    Point(const Point &p);            // Constructeur de copie

    // Option 1 : Getters qui retournent des copies
    double getX() const;              
    double getY() const;

    // Option 2 : Getters qui retournent des références
    double& getX();                   
    double& getY();

    void setX(double x);              // Setter pour x
    void setY(double y);              // Setter pour y

    friend double distance(const Point &p1, const Point &p2); // Fonction amie
};

#endif

