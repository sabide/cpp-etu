#ifndef __POLYNOME_HPP
#define __POLYNOME_HPP

#include <iostream>

class monome
{
public:
  monome(double coef=0, unsigned degre=0) : c(coef),d(degre) {}
  unsigned degre() const { return d; }
  double coef() const { return c; }
  double operator() (double x) const; // evaluation
  friend bool operator== (monome const &P, monome const &Q);
  friend bool operator!= (monome const &P, monome const &Q);
  // La classe monome ne comporte pas de champ de type pointeur qui pointerait vers une autre zone memoire. 
  // Il n'est donc pas necessaire de definir un destructeur et un constructeur par copie.
private:
  double c;
  unsigned d;
};


class polynome {

private:
  unsigned n;
  monome *data;

public:
  polynome (double coef=0., unsigned degre=0);//Constructeur par défaut
  
  //D'autres constructeurs
  polynome (double *coef, unsigned *degre, unsigned d);
  polynome (monome const &M);
  polynome (polynome const &P);//Constructeur de copie

  ~polynome (){ delete [] data; } //Destructeur
  
  unsigned degre() const {return n;}

  //Operateurs unaires
  polynome &operator= (polynome const &P);
  double operator() (double x) const;
  polynome operator- () const;

  // Operateurs binaires version méthodes globales
  friend polynome operator+ (polynome const &P, polynome const &Q);
  friend polynome operator- (polynome const &P, polynome const &Q);
  friend polynome operator* (polynome const &P, polynome const &Q);
  friend bool operator< (polynome const &P, polynome const &Q);
  friend bool operator== (polynome const &P, polynome const &Q);
  friend bool operator!= (polynome const &P, polynome const &Q);
  friend std::ostream &operator<< (std::ostream &o , polynome const &P);
};
#endif
