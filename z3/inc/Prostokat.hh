#ifndef PROSTOKAT_HH
#define PROSTOKAT_HH

#include <iostream>
#include <cmath>
#include "Wektor2D.hh"
#include "Macierz2x2.hh"

/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */
class Prostokat {
private:
  std::vector<std::vector<Wektor2D>> w;

public:
Prostokat(){};
  Prostokat(Wektor2D LG, Wektor2D PG, Wektor2D LD, Wektor2D PD);
  void przesun( Wektor2D & P);
  void obroc (double kat);
  void WysWierzcholki();
  bool BokiRowne(); // zwraca 1 gdy boki sa rowne
  const Wektor2D  &operator()(int ind_x,int ind_y) const; 
  Wektor2D  &operator()(int ind_x,int ind_y) ; 

};


/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 */
std::ostream& operator << ( std::ostream &Strm, const Prostokat &Pr);


#endif
