#ifndef __CARRE_HH__
#define __CARRE_HH__
 
#include "Forme.hh"
#include "Point2D.hh"
 
class Carre : public Forme
{
    private:
        Point2D _pts[4];
 
    public:
        Carre(Point2D*);
        string to_str() const;
        void apply_rot(const Rot& r);
};
 
 
#endif
