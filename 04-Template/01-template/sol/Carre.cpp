#include "Carre.hh"
 
Carre::Carre(Point2D* tPts)
{
  for(int i=0;i<4;i++)
    _pts[i] = tPts[i];
}
 
string Carre::to_str() const 
{
    string res = "CARRE\n";
    for (int i = 0; i<4; i++)
        res += to_string(_pts[i].x) + " " + to_string(_pts[i].y) + "\n";
    return res;
}
 
void Carre::apply_rot(const Rot& r)
{
    for (int i = 0; i<4; i++)
        _pts[i] = r(_pts[i]);
}
