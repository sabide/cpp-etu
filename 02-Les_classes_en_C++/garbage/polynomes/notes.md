# tp sur les polynomes
Ce tp a pour vocation de voir la construction d'une classe 

## le concept à modéliser
un polynôme de degré $n$ est de la forme $P(x)=\sum^n_{i=0} a_i x^i$.

## données caractérisant ce concept
dans le répertoire Q1 -> main.cpp
   1- classe polynome avec coeffs_[5] pour poly degres 5.
   2- initialisation dans main.cpp

## méthode pour affichage d'un monome.
dans Q2 main.cpp on créera le fichier Polynome.cpp et polynome.h
   3- printMonome(ostream& os, double coeff, int deg):
      on souhaite afficher sour la forme : sign()*coeff x^deg
   4- void print(ostream& os)
   5- creér fonction void print(Polynome * const ptrPoly, ostream& os)
      commenter les différences entre méthodes et fonction globale.
   6- ajouter une méthode qui initiliase le polynome à zero (en utilisant le this)

## setter
   7-  ajouter une méthode setter pour : polynome& set(int d,double a);
       commenter l'intêret du retour polynome&.
   8- remarquer que la printMonome n'utilise aucum membre de polynome.
      on peut alors la déclarer en static.
      (interêt on ne passe pas le pointer this)
   9- instancier la classe polynome en constante et afficher un poly à l'écran.
      que remarquez-vous (il ne compile pas). (il faut déclarer alors print en const)

   10- créer une fonction débug void dbg(const string& nom,const polynom& ); qui affiche les monomes d'un polynome. Il faut la déclarer amie pour avoir accès au attribut de la classe dans le corps de la fonction dbg. Vérifier ce point.
   
Partie 2 construction destruction

1- afficher la valeur des coefficients sans avoir initialiser.
2- implémenter un constructeur dans paramètre qui initialise à zéro.
3- implémenter un constructeur avec paramètre polynome(c0,c1,c2,c3,c4)
4 - implémenter une fonction globale avec en argument un polynome passé par valeur.
    afficher ce polynome que remarquer vous? quelques conclusion faites vous.
     ajouter ce constructeur  
polynome(const polynome & q ){
    std::cout << " je passe par la " << std::endl;
  };
    quelques conclusion faites vous. (c'est notre cloneur)

5- maintenant il s'agit de modifier la classe polynome pour permettre de modéliser un polynome de degres quelconque. pour cela l'attribut coeff_ devient double* coeff_.

Partie 3
Les accesseurs et mutateurs sont importants pour vaoir accès à une classe.
   1- proposer un getter/setter retournant un des coeffs.  


