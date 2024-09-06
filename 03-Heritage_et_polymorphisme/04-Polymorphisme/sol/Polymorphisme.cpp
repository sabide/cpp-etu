#include <iostream>
#include <cmath>

class FigureGeometrique {
public:
    virtual double calculerAire() const = 0; // Méthode virtuelle pure
    virtual ~FigureGeometrique() = default;  // Destructeur virtuel par défaut
};

class Triangle : public FigureGeometrique {
public:
    Triangle(double x1, double y1, double x2, double y2, double x3, double y3)
        : x1_(x1), y1_(y1), x2_(x2), y2_(y2), x3_(x3), y3_(y3) {}

    double calculerAire() const override {
        return 0.5 * std::abs(x1_ * (y2_ - y3_) + x2_ * (y3_ - y1_) + x3_ * (y1_ - y2_));
    }

private:
    double x1_, y1_, x2_, y2_, x3_, y3_;
};

class Quadrangle : public FigureGeometrique {
public:
    Quadrangle(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4)
        : x1_(x1), y1_(y1), x2_(x2), y2_(y2), x3_(x3), y3_(y3), x4_(x4), y4_(y4) {}

    double calculerAire() const override {
        // Diviser le quadrangle en deux triangles
        Triangle t1(x1_, y1_, x2_, y2_, x3_, y3_);
        Triangle t2(x1_, y1_, x3_, y3_, x4_, y4_);
        return t1.calculerAire() + t2.calculerAire();
    }

private:
    double x1_, y1_, x2_, y2_, x3_, y3_, x4_, y4_;
};

int main() {
    // Créer des objets pour un triangle et un quadrangle
    FigureGeometrique* figures[] = {
        new Triangle(0, 0, 1, 0, 0, 1),
        new Quadrangle(0, 0, 1, 0, 1, 1, 0, 1)
    };

    // Calculer et afficher l'aire de chaque figure
    for (const auto& figure : figures) {
        std::cout << "Aire: " << figure->calculerAire() << std::endl;
    }

    // Nettoyage de la mémoire
    for (auto& figure : figures) {
        delete figure;
    }

    return 0;
}