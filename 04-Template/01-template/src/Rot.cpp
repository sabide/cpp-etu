#include "Rot.hh"
#include <cmath>
 
// constructeur. On initialise les valeurs de _m 
Rot::Rot(double teta)
{
    _m[0][0] = cos(teta);
    _m[0][1] = -sin(teta);
    _m[1][0] = sin(teta);
    _m[1][1] = cos(teta);
}
 
// surcharge de l'opérateur (). On applique la matrice _m au point reçu en paramètre
Point2D Rot::operator() (const Point2D& pt) const
{
    Point2D res = {0,0};
    res.x = pt.x * _m[0][0] + pt.y * _m[0][1];
    res.y = pt.x * _m[1][0] + pt.y * _m[1][1];
    return res;
 
}
