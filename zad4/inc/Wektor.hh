#ifndef WEKTOR_HH
#define WEKTOR_HH

#include <iostream>
#include <vector>
#include <math.h>
#include <string>

/*!
 * \file
 * \brief Ten plik powinien zawierać definicję szablonu Wektor<>
 *
 * Ten plik powinien zawierać definicję szablonu Wektor<>.
 * W tym celu należy przerobić definicję klasy Wektor<Wymiar>.
 */


/*!
 * \brief Krótki opis czego to jest szablon
 * 
 *  Tutaj trzeba opisac szablon. Jakie pojecie on modeluje
 *  i jakie ma glowne cechy.
 */
template <int Wymiar>
class Wektor {
 private:
  std::vector <double > xy;

public:
   Wektor<Wymiar> operator +(const Wektor<Wymiar> &arg2) ;   
   Wektor<Wymiar> operator -(const Wektor<Wymiar> &arg2) ; 
   Wektor<Wymiar> operator *(double arg2);
   Wektor<Wymiar> operator /(double arg2); 
   double operator *(const Wektor<Wymiar> &arg2);
  Wektor();
  Wektor (std::vector <double > _xy);
  double &operator[] (int ind);
   const double &operator[] (int ind)const;  
};

template <int Wymiar>
Wektor<Wymiar>::Wektor()
{
  for (int i = 0; i<Wymiar; i++)
    xy.push_back(0);
}

template <int Wymiar>
 Wektor<Wymiar>::Wektor (std::vector <double > _xy)
{
   for (int i = 0; i<Wymiar; i++)
    xy.push_back(_xy[i]);
}
template <int Wymiar>
 Wektor<Wymiar> Wektor<Wymiar>::operator+(const Wektor<Wymiar> &arg2) 
{
    Wektor<Wymiar> Wynik;
    for (int i = 0; i<Wymiar; i++)
   Wynik[i] = xy[i] + arg2[i];

    return Wynik;
}
template <int Wymiar>
 Wektor<Wymiar> Wektor<Wymiar>::operator-(const Wektor<Wymiar> &arg2) 
{
    Wektor<Wymiar> Wynik;
    for (int i = 0; i<Wymiar; i++)
   Wynik[i] = xy[i] - arg2[i];
    return Wynik;
}
template <int Wymiar>
Wektor<Wymiar> Wektor<Wymiar>::operator*(double arg2)
{
    Wektor<Wymiar> Wynik;
    for (int i = 0; i<Wymiar; i++)
   Wynik[i] = xy[i] * arg2;
    return Wynik;
}
template <int Wymiar>
Wektor<Wymiar> Wektor<Wymiar>::operator/(double arg2)
{
    Wektor<Wymiar> Wynik;
    for (int i = 0; i<Wymiar; i++)
   Wynik[i] = xy[i] / arg2;
    return Wynik;
}
template <int Wymiar>
double Wektor<Wymiar>::operator*(const Wektor<Wymiar> &arg2)
{
  double suma = 0;
  for (int i = 0; i<Wymiar; i++)
    suma+=xy[i] * arg2[i];
  return suma;
}
template <int Wymiar>
const double &Wektor<Wymiar>::operator[](int ind) const
{
    if (ind < 0 || ind > Wymiar)
        std::cerr << "Odwolanie poza pamiec!" << std::endl;
    return xy[ind];
}
template <int Wymiar>
double &Wektor<Wymiar>::operator[](int ind)
{
    if (ind < 0 || ind > Wymiar)
        std::cerr << "Odwolanie poza pamiec!" << std::endl;
    return xy[ind];
}


/*!
 * \brief Przeciążenie dla wyjścia musi także być szablonem
 *
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 */
template <int Wymiar>
std::istream& operator >> (std::istream &Strm, Wektor<Wymiar> &Wek)
{
  for (int i = 0; i < Wymiar; i++)
        Strm >> Wek[i];
  return Strm;
}

/*!
 * \brief Przeciążenie dla wejścia musi także być szablonem
 * 
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 */
template <int Wymiar>
std::ostream& operator << (std::ostream &Strm, const Wektor<Wymiar> &Wek)
{
  for (int i = 0; i < Wymiar; i++)
        Strm << Wek[i] << " ";

  return Strm;  
}

template class Wektor<3>;
template std::istream& operator >> (std::istream &Strm, Wektor<3> &Wek);
template std::ostream& operator << (std::ostream &Strm, const Wektor<3> &Wek);
#endif
