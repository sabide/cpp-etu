#pragma once

#include "element.hpp"

class Quadrilateral : public Element {
public:
    Quadrilateral(int id, double area);
    double area() const override;

private:
    double area_;
};
