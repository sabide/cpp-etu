#ifndef __MAT22_HH__
#define __MAT22_HH__
 
#include <iostream>
 
using namespace std;
 
/*
    Cette classe va nous permettre de manipuler des matrices 2x2
*/
class Mat22
{
    protected:                  //  Les données sont protected : accessible par une classe fille
        double _m[2][2];        // alloué statiquement ! pas de new[] -> pas de delete[] !
 
    public:
        Mat22();    //  constructeur par défaut, initialise toutes les valeurs à 0
 
        void setM(const double tab[2][2]);
        double* operator[](int i); // surcharge de l'opérateur []
 
        friend ostream& operator<<(ostream& o, Mat22& m);
};
 
#endif
