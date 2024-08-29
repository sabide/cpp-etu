#include <iostream>
#include "polynome.hpp"

using namespace std;

int main(void)
{
  
  double coeff[] = {2, 4, -1, 0, 2};
  unsigned degre[] = {0, 2, 3, 5, 6};//on suppose le tableau ordonne


  cout << endl << "------------------------------------" << endl << endl;;
  
  polynome P(coeff, degre, 5);// P vaut 2 + 4X^2 - X^3 + 2X^6
  cout << "P :\t " << P << endl ;

  polynome Q(4, 2);// Q vaut 4X^2
  cout << "Q :\t " << Q << endl ;

  cout << "-Q :\t " << -Q << endl ;
  cout << "-P :\t " << -P << endl ;
  cout << "1+Q :\t " << 1+Q << endl ;
  cout << "P+Q :\t " << P+Q << endl ;
  
  cout << "Evaluation de P en 1 :\t " << P(1.) << endl ;
  cout << "Evaluation de Q en 1 :\t " << Q(1.) << endl ;
  cout << "P-Q :\t " << P-Q << endl ;
  cout << "Evaluation de P-Q en 1 :\t " << (P-Q)(1.) << endl ;

  cout << "Le carré de P :\t" << P*P << endl;
  
  cout << endl << "------------------------------------" << endl << endl;
  return 1;
  const polynome X(1., 1); // Le monome X
  
  P = (2 + X);
  Q = 4 + 4*X + X*X;
  cout << "(" <<P << ")^2 = " << Q << " ? :\t" << ((P*P==Q)?"Vrai":"Faux") << endl; // Test de l'operateur ==
  cout << "(" <<P << ") + 1 = " << Q << " ? :\t" << ((P+1==Q)?"Vrai":"Faux") << endl;

  cout << endl << "------------------------------------" << endl << endl;;

  
  P = 1 + X;
  cout << "Les puissances de 1+X" << endl << P << endl;
  for (int i=0; i<10; i++)
	{
	  P = P * (1+polynome(1.,1));
	  cout << P << endl;
	}
  return 0;
}
