#ifndef WEKTOR2D_HH
#define WEKTOR2D_HH

#include <iostream>
#include <vector>
#include <math.h>

#define PI 3.14

/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */
class Wektor2D 
{
private:
  std::vector <double > xy;

public:
   Wektor2D operator +(const Wektor2D &arg2) ;   
   Wektor2D operator -(const Wektor2D &arg2) ; 
   Wektor2D operator *(double arg2);
   Wektor2D operator /(double arg2); 
   double operator *(const Wektor2D &arg2);
  Wektor2D ();
  Wektor2D (double x, double y);
  double &operator[] (int ind);
   const double &operator[] (int ind)const;
  };


/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 */
std::istream& operator >> (std::istream &Strm, Wektor2D &Wek);

/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 */
std::ostream& operator << (std::ostream &Strm, const Wektor2D &Wek);

#endif
