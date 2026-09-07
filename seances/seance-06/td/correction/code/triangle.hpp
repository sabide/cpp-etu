#pragma once

#include "element.hpp"

class Triangle : public Element {
public:
    Triangle(int id, double area);
    double area() const override;

private:
    double area_;
};
