#ifndef __CERCLE_HH__
#define __CERCLE_HH__
 
#include "Forme.hh"
#include "Point2D.hh"
 
class Cercle : public Forme
{
    private:
        Point2D _centre;
        double _rayon;
 
    public:
        Cercle(const Point2D &, double); // constructeur oublié dans l'énoncé
        string to_str() const;
        void apply_rot(const Rot& r);
};
 
 
#endif
