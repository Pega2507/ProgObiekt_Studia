#ifndef PROSTOPADLOSCIAN_HH
#define PROSTOPADLOSCIAN_HH

#include <iostream>
#include "Wektor.hh"
#include "Wektor3D.hh"
#include "Macierz3x3.hh"



  //mogę tu od razu dać 3?
class Prostopadloscian {
private:
  std::vector< Wektor3D> w;

public:
Prostopadloscian(){};
  Prostopadloscian(Wektor3D PLD, Wektor3D PPD, Wektor3D PLG, Wektor3D PPG,
                   Wektor3D SLD, Wektor3D SPD, Wektor3D SLG, Wektor3D SPG);
  void przesun( Wektor3D   & P);
  void obroc (double kat,  std::string os);
  void WysWierzcholki();
  bool BokiRowne(); // zwraca 1 gdy boki sa rowne
  const  Wektor3D  &operator[](int ind) const; 
   Wektor3D  &operator[](int ind) ; 
};


std::ostream &operator<<(std::ostream &Strm, const Prostopadloscian    &Pr);

#endif
