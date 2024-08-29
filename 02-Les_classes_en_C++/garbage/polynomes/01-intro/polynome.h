#ifndef POLYNOME_H
#define POLYNOME_H

#include <iostream>

class polynome {
private:
  double coeffs_[5] = {}; 
  
public:
  // Constructeur
  //polynome();
  // Méthodes pour afficher le monome et le polynome
  bool printMonome(std::ostream& os, double coeff, int deg) const ;
  void print(std::ostream& os) const;

  polynome(const polynome & q ){
    std::cout << " je passe par la " << std::endl;
  };
  polynome(double a0,double a1,double a2,double a3,double a4){
    coeffs_[0]=a0;
    coeffs_[1]=a1;
    coeffs_[2]=a2;
    coeffs_[3]=a3;
    coeffs_[4]=a4;
  };
   polynome()= default;
  // Méthode pour initialiser le polynome à zéro
  void initZero();
  polynome& set (int deg,double coeff){
    coeffs_[deg] = coeff ;
    return *this;
  }
};

#endif // POLYNOME_H

