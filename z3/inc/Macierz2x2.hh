#ifndef MACIERZ2X2_HH
#define MACIERZ2X2_HH

#include <iostream>
#include "Wektor2D.hh"


/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */
class MacierzRot2D 
{
private:
  std::vector <std::vector <double>> mac;
public:
  const Wektor2D  operator * (const Wektor2D & Punkt) const; //m.in obrot punktu
  MacierzRot2D (double kat_stopnie);
  const double  &operator()(int ind_x,int ind_y) const; 

};


/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 *
 * Przeciążenie to może być użyteczne w trakcie debugowania programu.
 */
std::ostream& operator << (std::ostream &Strm, const MacierzRot2D &Mac);

#endif
