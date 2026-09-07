#include "element.hpp"

Element::Element(int id)
    : id_{id}
{}

int Element::id() const
{
    return id_;
}
