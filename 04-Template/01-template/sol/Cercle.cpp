#include "Cercle.hh"
 
 // constructeur oublié dans l'énoncé
Cercle::Cercle(const Point2D& c, double r)
{
    _centre = c;
    _rayon = r;
}
 
string Cercle::to_str() const
{
    string res = "Je suis un cercle de centre ";
    res += to_string(_centre.x) + ";" + to_string(_centre.y);
    res += " et de rayon : " + to_string(_rayon);
    return res;
} 
 
 
void Cercle::apply_rot(const Rot& r)  // voir Rot.hh et Rot.cpp
{
    _centre = r(_centre);
}
