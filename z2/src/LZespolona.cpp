//Aleksandra Machelak 259238
#include "LZespolona.hh"

/* 
  Funkcja inicjujaca liczbe zespolona
  Argumenty:
    Liczba zespolona Skl1
  Zwraca:
    Liczbe zespolona Skl1 rowna 0
*/
void Inicjalizuj(LZespolona & Skl1)
{
  Skl1.re = 0;
  Skl1.im = 0;
}

/*!
 * Realizuje dodanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dodawania,
 *    Skl2 - drugi skladnik dodawania.
 * Zwraca:
 *    Sume dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re + Skl2.re;
  Wynik.im = Skl1.im + Skl2.im;
  return Wynik;
}

/*!
 * Realizuje odejmowanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik odejmowania,
 *    Skl2 - drugi skladnik odejmowania.
 * Zwraca:
 *    Roznice dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  operator - (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re - Skl2.re;
  Wynik.im = Skl1.im - Skl2.im;
  return Wynik;
}
/*!
 * Realizuje mnozenie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik mnozenia,
 *    Skl2 - drugi skladnik mnozenia.
 * Zwraca:
 *    Iloczyn dwoch skladnikow przekazanych jako parametry.
 */

LZespolona  operator * (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re * Skl2.re - Skl1.im * Skl2.im;
  Wynik.im = Skl1.re * Skl2.im + Skl1.im * Skl2.re;
  return Wynik;
}

/*!
 * Realizuje dzielenie liczby zespolonej przez liczbe rzeczywista.
 * Argumenty:
 *    Skl1 - dzielnik, liczba zespolona,
 *    a - dzielna, liczba rzeczywista.
 * Zwraca:
 *   Iloraz dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  operator / (LZespolona  Skl1,  double a)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re / a;
  Wynik.im = Skl1.im /a;
  return Wynik;
}

/*
  Tworzy modol liczby zespolonej podniesiony do kwadratu
  Argumenty:
    Skl1 - liczba zespolona
  Zwraca:
    modol Skl1 podniesiony do kwadratu
*/
double Modul2(LZespolona Skl1)
{
  return Skl1.re*Skl1.re + Skl1.im*Skl1.im;
}

/*
  Tworzy sprzezenie liczby zespolonej zmieniajac znak 
  czesci urojonej danej liczby
  Argumenty:
    Skl1 - liczba zespolona
  Zwraca:
    sprzezona liczbe Skl1
*/
LZespolona Sprzezenie(LZespolona Skl1)
{
  Skl1.im = -Skl1.im;
  return Skl1;
}

/*!
 * Realizuje dzielenie dwoch liczb zespolonych wedlug wzoru.
 * Argumenty:
 *    Skl1 - dzielnik,
 *    Skl2 - dzielna.
 * Zwraca:
 *    Iloraz dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  operator / (LZespolona  Skl1,  LZespolona Skl2)
{
  return Skl1*Sprzezenie(Skl2)/Modul2(Skl2);
}

/*
  Umożliwia poprawne wypisanie liczby zespolonej na strumieniu wyjscia.
  Argumenty: 
    strm - strumien wyjscia
    L - zapisywana liczba zespolona
  Zwraca:
    strumien wyjscia z liczba zespolona w postaci (x+yi) 
    (gdzie x to czesc rzeczywista a y - urojona)
*/
std::ostream & operator << (std::ostream & strm, const LZespolona & L)
{
  strm << "(" << L.re << std::showpos << L.im << std::noshowpos << "i)";
  return strm;
};

/*
  Umożliwia poprawne wpisanie liczby zespolonej do struktury.
  Argumenty: 
    strm - strumien wejscia
    L - zapisywana liczba zespolona
  Zwraca:
    strumien wejscia z liczba zespolona zapisana w strukturze L

*/
std::istream & operator >> (std::istream & strm, LZespolona & L)
{
  char znak;
  strm >> znak;
  if (znak != '(')
    strm.setstate(std::ios_base::failbit);
  strm >> L.re; 
  strm >> L.im;
  strm >> znak;
  if (znak != 'i')
    strm.setstate(std::ios_base::failbit);
  strm >> znak;
  if (znak != ')')
    strm.setstate(std::ios_base::failbit);

  return strm;
};
