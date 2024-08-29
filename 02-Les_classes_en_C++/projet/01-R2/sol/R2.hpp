#include <cmath>
#include <cassert>

#include <cstdlib> 
#include <iostream> 
typedef double R;

class R2 {
private:
    double x_,y_;  
public:  
  // les 3 constructeurs
  R2 () :x_(0.),y_(0.) {}  
  R2 (R x,R y) : x_(x),y_(y)  { }
  R2 (const R2 & a,const R2 & b):x_(b.x_-a.x_),y_(b.y_-a.y_)  {} // vec(ab)
  // le constucteur par defaut est inutile
  R2 (const R2 & a) : x_(a.x_) , y_(a.y_) { std::cout << "  const par copie " << std::endl;} 
  R2 ( R2 & a) : x_(a.x_) , y_(a.y_) { std::cout << "  const pas const  par copie " << std::endl; } 

  R2& operator=(const R2 & P)  {x_ = P.x_;y_ = P.y_;return *this;}

  R & x() {  return this->x_; }
  R & y() {  return this->y_; }
  const R & x() const {  return this->x_; }
  const R & y() const {  return this->y_; }

  // les autre operateur affectations
  R2 &  operator+=(const R2 & P) {x_ += P.x_;y_ += P.y_; return *this; }
  R2 &  operator-=(const R2 & P) {x_ -= P.x_;y_ -= P.y_; return *this; }
  // operateur binaire + - * , ^ /
  R2   operator+(const R2 & P)const {return R2(x_+P.x_,y_+P.y_);}
  R2   operator-(const R2 & P)const {return R2(x_-P.x_,y_-P.y_);}
  R    operator,(const R2 & P)const {return  x_*P.x_+y_*P.y_;} // produit scalaire
  R    operator^(const R2 & P)const {return  x_*P.y_-y_*P.x_;} // produit mixte
  R2   operator*(R c)const {return R2(x_*c,y_*c);}
  R2   operator/(R c)const {return R2(x_/c,y_/c);}
  // operateur unaire 
  R2   operator-()const  {return R2(-x_,-y_);} 
  const R2 &  operator+()const  {return *this;}
  R2   perp() const {return R2(-y_,x_);} // vecteur orthogonal

  // version qui peut modifie la class  via l'adresse de x ou y 
  R & operator[](int i) { if(i==0) return x_; else if (i==1) return y_; else {assert(0);exit(1);} ;}
  // version qui retourne une reference const qui ne modifie pas la class
  const R & operator[](int i) const { if(i==0) return x_; else if (i==1) return y_; else {assert(0);exit(1);} ;}
  // version qui peut modifie la class  via l'adresse de x ou y 
  R & operator()(int i) { if(i==1) return x_; else if (i==2) return y_; else {assert(0);abort();} ;}
  // version qui retourne une reference const qui ne modifie pas la class
  const R & operator()(int i) const { if(i==1) return x_; else if (i==2) return y_; else {assert(0);abort();} ;}
  R norme() const { return std::sqrt(x_*x_+y_*y_);}
  //  un variable globale dans la classe donc de nom R2::d 
  static const int  d=2;  // utilisation:  R2::d  (n'ajoute pas de memoire)
friend  std::ostream& operator <<(std::ostream& f, const R2 & P ) { f << P.x_ << ' ' << P.y_   ; return f; }
friend std::istream& operator >>(std::istream& f,  R2 & P) { f >>  P.x_ >>  P.y_  ; return f; }
friend inline R2 operator*(R c,const R2 & P);
};
inline R det(const R2 & A,const R2 & B,const R2 & C)
	{ return R2(A,B)^R2(A,C);}


inline R2 operator*(R c,const R2 & P) {return P*c;} 
//inline R2 perp(const R2 & P) { return R2(-P.y,P.x) ; }
//inline R2 Perp(const R2 & P) { return P.perp(); }  // autre ecriture  de la fonction perp

