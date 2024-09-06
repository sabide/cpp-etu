#ifndef __MYPAIRE_HPP__
#define __MYPAIRE_HPP__
 
#include <iostream>
 
using namespace std;
 
//  MyPaire est une classe template à deux types
template <typename T, typename U>
class MyPaire
{
    private:
        //  membres privés de la classe. On notera les types utilisés.
        T _k;
        U _v;
 
    public:
        MyPaire(){} //  1ere constructeur, écriture compacte. On notera la présence de {} obligatoire.
        MyPaire(T k, U v) : _k(k), _v(v) {} //  2eme constructeur, écriture compacte.
 
        bool operator<(const MyPaire& o) { return _v < o._v; }  //  surcharge de l'opérateur <
 
        friend ostream& operator<<(ostream &o, const MyPaire& p)    //  fonction amie permettant l'utilisation de cout << pour faciliter les affichages
        {
            o << p._k << " <---> " << p._v;
            return o;
        }
};
 
 
#endif

