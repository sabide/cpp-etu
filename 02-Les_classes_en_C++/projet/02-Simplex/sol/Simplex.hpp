#include "R2.hpp"
class Vertex : public R2
{

private:
  int label_ ;
 public:
  Vertex() {label_=0;} 
  int & label(){ return label_;}
Vertex& operator= (R2 n) { x_=n.x();y_ =n.y(); label_=0; return *this; };
Vertex& operator= (Vertex& n) { x_=n.x();y_ =n.y(); label_=n.label(); return *this; };
friend std::ostream& operator << (std::ostream& f, const  Vertex & P );
friend std::istream& operator >>(std::istream& f,  Vertex & P);
};
std::ostream& operator <<(std::ostream& os, const  Vertex & P ) { 
    os << P.x() << ' ' << P.y()  << ' ' << P.label_ << ' ' ;
    return os; }

std::istream& operator >>(std::istream& is,  Vertex & P){ 
    is >>  P.x() >>  P.y() >> P.label_ ;
    return is;  
}

class Simplex {
private: 
  static const int nbv =3;            // nombre de sommets 
  Vertex vertices_[nbv];                    // liste de vertex
  
  double mes;                         // mesure de l'element
public:
  Simplex(){ } // constructeur par defaut
  Simplex(const Vertex n0,const Vertex n1,const Vertex n2){
    vertices_[0] = n0;
    vertices_[1] = n1;
    vertices_[2] = n2;
   } // constructeur par defaut
  void build(Vertex *v0,int * I,int offset=0)
  { // I array of vertex number  
//    for(int i=0; i < nbv; ++i) 
 //     vertex_[i] =  v0 + I[i] + offset;

   // mes = det(vertex_[0], vertex_[1], vertex_[2]) * 0.5; 
    assert(mes>0) ;
  } 

  void GradLambdaK(R2 G[3]) const
  {
    double K2 = mes*2; 
    G[0] = R2(vertices_[1],vertices_[2]).perp()/K2;
    G[1] = R2(vertices_[2],vertices_[0]).perp()/K2;
    G[2] = R2(vertices_[0],vertices_[1]).perp()/K2;
  }
  
  Vertex & operator[](int i) { assert(i>=0 && i < nbv); return (vertices_[i]); }

  const Vertex & operator[](int i) const { assert(i>=0 && i < nbv); return (vertices_[i]); }

};  

std::ostream& operator <<(std::ostream& os, const  Simplex & S ) { 
    os << S[0] << std::endl;
    os << S[1] << std::endl;
    os << S[2] << std::endl;
    return os; }