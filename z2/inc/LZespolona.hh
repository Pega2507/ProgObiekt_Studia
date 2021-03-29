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
 /*struct  LZespolona {
  double   re;
  double   im;
}; */

class LZespolona
{
private:
  double   re;    /*! Pole repezentuje czesc rzeczywista. */
  double   im;    /*! Pole repezentuje czesc urojona. */
public:
  LZespolona(double a=0, double b=0);
  LZespolona  operator + (LZespolona  Skl2);
  LZespolona  operator - (LZespolona  Skl2);
  LZespolona  operator * (LZespolona  Skl2);
  LZespolona  operator / (LZespolona  Skl2);
  LZespolona  operator / (double a);
  bool operator == (LZespolona  Skl2);
  bool operator != (LZespolona  Skl2);
  LZespolona Sprzezenie();
  double Modul2();
  const double get_re()const {return re;}
  const  double get_im()const {return im;}
  void set_re(double a){re=a;}
  void set_im(double b){ im=b;}
};

/*
 * Dalej powinny pojawic sie zapowiedzi definicji przeciazen operatorow
 */

/*void Inicjalizuj(LZespolona & Skl1, double a, double b);
LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2);
LZespolona  operator - (LZespolona  Skl1,  LZespolona  Skl2);
LZespolona  operator * (LZespolona  Skl1,  LZespolona  Skl2);
LZespolona  operator / (LZespolona  Skl1,  double a);
LZespolona Sprzezenie(LZespolona Skl1);
LZespolona  operator / (LZespolona  Skl1,  LZespolona Skl2);
*/
std::ostream & operator << (std::ostream & strm, const LZespolona & L);
std::istream & operator >> (std::istream & strm, LZespolona & L);


#endif
