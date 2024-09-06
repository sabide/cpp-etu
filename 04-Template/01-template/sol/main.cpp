#include "Carre.hh"
#include "Cercle.hh"
#include <iostream>
 
// Pour compiler:
// g++ main.cpp Cercle.cpp Carre.cpp Rot.cpp Mat22.cpp Point2D.cpp
//
//
const double PI  =3.141592653589793238463;
 
int main()
{
    Rot r(PI/4);
    Point2D pt(1,0);
 
    cout << "Rotation r de pi/4" << endl << r << endl;
    cout << "Point2D pt (1,0)" << endl << pt << endl;
 
    cout << "r(r(pt) " << endl << r(r(pt)) << endl;
 
    Point2D pt1(0, 0);
    Point2D pt2(0, 1);
    Point2D pt3(1, 0);
    Point2D pt4(1, 1);
    Point2D v[4];
    v[0] = pt1;
    v[1] = pt2;
    v[2] = pt3;
    v[3] = pt4;
 
    Forme* vec[2];
    vec[0] = new Cercle(pt, 2);
    vec[1] = new Carre(v);
    
    cout << vec[0]->to_str() << endl;
    vec[0]->apply_rot(r);
    cout << "Après rotation r de pi/4:" << endl << vec[0]->to_str() << endl;
 
    cout << vec[1]->to_str() << endl;
    vec[1]->apply_rot(r);
    cout << "Après rotation r de pi/4:" << endl << vec[1]->to_str() << endl;

    for(int i=0;i<2;i++)
      delete vec[i];
}
