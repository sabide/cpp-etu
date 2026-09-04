#include "element.hpp"

Element::Element(int id)
    : id_{id}
{}

int Element::id() const
{
    return id_;
}

double Element::area() const
{
    return 0.0; // comportement provisoire à supprimer
}
