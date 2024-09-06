#ifndef __MYSORT_HPP__
#define __MYSORT_HPP__
#include<iostream>
using namespace std;

template<typename T>
void MySwap(T &T1, T&T2)
{
  T T3;
  T3 = T1;
  T1 = T2;
  T2 = T3;
}


template<typename T>
void MySort(T* tab, int n)
{
  for(int i=n-1;i>=1;i--)
    {
      for(int j=0;j<=i-1;j++){
	if (tab[j+1] < tab[j])
	  MySwap(tab[j+1], tab[j]);
      }
    }
}

// fonction non demandee dans le TP mais pratique a l'utilisation
template<typename T>
void affiche(T* t, int n)
{
  for(int i=0;i<n-1;i++)
    cout << t[i] << " ";
  cout << t[n-1] << endl;
}

#endif
