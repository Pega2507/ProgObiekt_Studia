#ifndef WEKTOR2D_HH
#define WEKTOR2D_HH

#include <iostream>
#include <vector>

/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */
class Wektor2D 
{
private:
  std::vector <double > xy;

public:
  const Wektor2D & operator +(const Wektor2D &arg2) const;   
  const Wektor2D & operator -(const Wektor2D &arg2) const; 
  const Wektor2D & operator *(double arg2) const;
  const Wektor2D & operator /(double arg2) const; 
  const Wektor2D & operator *(const Wektor2D &arg2) const;
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
