#include "polynome.hpp"


polynome::polynome (double coef, unsigned degre)// Constructeur qui cree un polynome reduit a un monome. C'est le constructeur par defaut (puisqu'il a ete declare avec des valeurs par defaut coef=0 et degre=0).
{
  n = degre;
  data = new monome[n+1];// On demande que le champ data ait une taille n+1, avec en particulier les monomes nuls
  for (unsigned i=0; i<n; i++)
	{
	  data[i] = monome(0,i);
	}
  data[n] = monome(coef,n);
}


polynome::polynome (monome const &M)// Constructeur qui convertit un monome en polynome
{
  n = M.degre();
  data = new monome[n+1];
  for (unsigned i=0; i<n; i++)
	{
	  data[i] = 0;
	}
  data[n] = M.coef();
}


polynome::polynome (double *coef, unsigned *degre, unsigned d)// Constructeur utilisant une liste des coeffcients
{
  n = degre[d-1];
  data = new monome[n+1];
  int j = 0;
  for (unsigned i=0; i<=n; i++)
	{
	  if (degre[j]==i)
		{
		  data[i] = monome(coef[j],i);
		  j++;
		}
	  else
		{
		  data[i] = monome(0,i);
		}
	}
}


polynome::polynome (polynome const &P)// Le constructeur par copie
{
  n = P.degre();
  data = new monome[n+1];
  for (unsigned i=0; i<=n; i++)
	{
	  data[i] = P.data[i];
	}
}


polynome &polynome::operator= (polynome const &P)// L'operateur d'affectation (qui doit etre redefini a la main, pour la meme raison que le destructeur et le constructeur par copie)
{
  if ((&P != this) && (n != P.n))
	{
	  n = P.n;
	  delete[] data;
	  data = new monome[n+1];
	}
  for (unsigned i=0; i<=n; i++)
	{
	  data[i] = P.data[i];
	}
  return *this;
}

 


double monome::operator() (double x) const // Operateur d'affectation pour les monomes
{
  double y = 1;
  for (unsigned i=0; i<d; i++)
	{
	  y *= x;
	}
  return c*y;
}


double polynome::operator() (double x) const // Operateur d'affectation pour les monomes
{
	//std::cout << " " << n<<" " <<i <<std::endl;
  double y=0;

  for (int i=n; i>=0; --i)
  //for (unsigned i=0; i<=n; i++)
	{
	  // Calcul par l'algorithme de Horner, qui ne necessite que n multiplication pour un polynome de degre n
	 // y = y*x + data[i].coef();

	  // Autre maniere, moins efficace, car elle necessite O(n^2) multiplication
	  //std::cout << " " << n<<" " <<i <<std::endl;
	  y += data[i](x);
	}
	

  return y;
}

polynome polynome::operator- () const // Operateur "-" unaire (-Q)
{
  polynome P(0.,n);
  for (unsigned i=0; i<=n; i++)
	{
	  P.data[i] = monome(-data[i].coef(), data[i].degre());
	}
  
  return P;//polynome(coefs, degres, n+1);
}

std::ostream &operator<< (std::ostream &o , polynome const &P)
{
  // Affichage d'un polynome. Les nombreux"if" servent a afficher le polynome de maniere esthetique
  // (par exemple afficher 2X - X^3 au lieu de 0 + 2X + 0X^2 + -1X^3)
  bool premier_terme = true;
  for (unsigned i=0; i<=P.degre(); i++)
	{
	  if (P.data[i].coef()!=0)// On n'affiche que les coefficients non nuls
		{
		  if (premier_terme)// Pas de caractere "+" devant le premier coefficient (ecrire 2X + 3X^2 au lieu de + 2X + 3X^2)
			{
			  o << P.data[i].coef();
			  premier_terme = false;
			}
		  else
			{
			  if (P.data[i].coef()>0)// Prise en compte du signe du coefficient (ecrire 1 - 2X plutot que 1 + -2X)
				{
				  o << "+ ";
				  if (P.data[i].coef()!=1)// On n'affiche pas les coefficients valant 1 (ecrire 1 + X plutot que 1 + 1X)
					{
					  o << P.data[i].coef();
					}
				}
			  else
				{
				  o << "- ";
				  if (-P.data[i].coef()!=1)
					{
					  o << -P.data[i].coef();
					}
				}
			}
		  if (i!=0)
			{
			  o << "x";
			}
		  if (i>1)
			{
			  o << "^" << P.data[i].degre();
			}
		  o << " ";
		}
	}
  
  return o;
}


polynome operator+ (polynome const &P, polynome const &Q)
{
  unsigned n = (P.n > Q.n)?P.n:Q.n;//Le max des deux degres
  
  polynome R(0., n);
  double coef_i;
  
  for (unsigned i=0; i<=n; i++)
	{
	  coef_i = 0;// Les deux tableaux P.data et Q.data n'ayant a priori pas la meme taille, on ne peut pas ecrire P.data[i] + Q.data[i]
	  if (i <= P.n)
		coef_i += P.data[i].coef();
	  if (i <= Q.n)
		coef_i += Q.data[i].coef();
	  R.data[i] = monome(coef_i,i);
	}
  return R;
}


polynome operator- (polynome const &P, polynome const &Q)// Operateur "-" binaire (P-Q)
{
  return P+(-Q); // On reutilise les fonctions deja programmees
}


polynome operator* (polynome const &P, polynome const &Q)
{
  // Le cas d'un produit nul est a traiter a part
  if ( (P.degre()==0 && P.data[0].coef()==0) || (Q.degre()==0 && Q.data[0].coef()==0) )
	{
	  return polynome();
	}
  
  unsigned n = P.degre()+Q.degre();
  polynome R(0., n);
  double coef_i;
  
  for (unsigned i=0; i<=n; i++)
	{
	  coef_i = 0;
	  for (unsigned j=0; j<=i; j++)
		{
		  if (j <= P.n && i-j <= Q.n)
			coef_i += P.data[j].coef() * Q.data[i-j].coef();
		}
	  R.data[i] = monome(coef_i,i);
	}
  return R;
}


bool operator< (polynome const &P, polynome const &Q)
{
  // On compare d'abord les degres
  if (P.degre()<Q.degre())
	{
	  return true;
	}
  else if (P.degre()>Q.degre())
	{
	  return false;
	}
  else
	{
	  // Si les degres sont les memes, on compare les coefficients dominants
	  return P.data[P.degre()].coef() < Q.data[Q.degre()].coef() ;
	}
  
}


bool operator== (monome const &P, monome const &Q)
{
  return (P.degre() == Q.degre()) && (P.coef() == Q.coef());
}


bool operator!= (monome const &P, monome const &Q)
{
  return !(P==Q);
}


bool operator== (polynome const &P, polynome const &Q)
{
  if (P.n != Q.n)
	return false;

  for (unsigned i=0; i<P.n; i++)
	if (P.data[i] != Q.data[i])
	  return false;

  return true;
  
}


bool operator!= (polynome const &P, polynome const &Q)
{
  return !(P==Q);
}


