#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH

#include <iostream>
/*!
 *  Plik zawiera definicje struktury LZesplona oraz zapowiedzi
 *  przeciazen operatorow arytmetycznych dzialajacych na tej 
 *  strukturze.
 */


/*!
 * Modeluje pojecie liczby zespolonej
 */
struct  LZespolona {
  double   re;    /*! Pole repezentuje czesc rzeczywista. */
  double   im;    /*! Pole repezentuje czesc urojona. */
};


/*
 * Dalej powinny pojawic sie zapowiedzi definicji przeciazen operatorow
 */

LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2);
LZespolona  operator - (LZespolona  Skl1,  LZespolona  Skl2);
LZespolona  operator * (LZespolona  Skl1,  LZespolona  Skl2);
LZespolona  operator / (LZespolona  Skl1,  double a);
double Modul2(LZespolona Skl1);
LZespolona Sprzezenie(LZespolona Skl1);
LZespolona  operator / (LZespolona  Skl1,  LZespolona Skl2);
std::ostream & operator << (std::ostream & strm, const LZespolona & L);
std::istream & operator >> (std::istream & strm, LZespolona & L);






#endif
