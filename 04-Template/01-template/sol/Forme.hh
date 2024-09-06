#ifndef __FORME_HH__
#define __FORME_HH__
 
#include <string>
#include "Rot.hh"
 
using namespace std;
 
class Forme
{
 public:
  virtual string to_str() const = 0;
  virtual void apply_rot(const Rot&) = 0;
};
 
#endif
