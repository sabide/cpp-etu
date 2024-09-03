#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle {
private:
    double width;
    double height;

public:
    Rectangle();                      // Constructeur par défaut
    Rectangle(double w, double h);    // Constructeur paramétré

    double getWidth() const;          // Getter pour la largeur
    double getHeight() const;         // Getter pour la hauteur
    void setWidth(double w);          // Setter pour la largeur
    void setHeight(double h);         // Setter pour la hauteur

    // Déclare la classe RectangleUtils comme une amie
    friend class RectangleUtils;
};

// Classe amie qui accède aux attributs privés de Rectangle
class RectangleUtils {
public:
    static double calculateArea(const Rectangle& rect);        // Calculer l'aire
    static double calculatePerimeter(const Rectangle& rect);   // Calculer le périmètre
};

#endif

