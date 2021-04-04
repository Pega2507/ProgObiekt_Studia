//Aleksandra Machelak 259238
#include "LZespolona.hh"

/*
  Funkcja inicjujaca liczbe zespolona
  Argumenty:
    Liczba zespolona Skl1
  Zwraca:
    Liczbe zespolona Skl1 z a jako czesc rzeczywista
    i b jako czesc urojona.
*/
/*void Inicjalizuj(LZespolona & Skl1, double a, double b)
{
  re = a;
  im = b;
}*/
LZespolona::LZespolona(double a, double b)
{
  re = a;
  im = b;
}


/*!
 * Realizuje dodanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dodawania,
 *    Skl2 - drugi skladnik dodawania.
 * Zwraca:
 *    Sume dwoch skladnikow przekazanych jako parametry.
 */
LZespolona LZespolona::operator + (LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = re + Skl2.re;
  Wynik.im = im + Skl2.im;
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
LZespolona LZespolona::operator - (LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = re - Skl2.re;
  Wynik.im = im - Skl2.im;
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

LZespolona LZespolona::operator * (LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = re * Skl2.re - im * Skl2.im;
  Wynik.im = re * Skl2.im + im * Skl2.re;
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
LZespolona LZespolona::operator / (double a)
{
  LZespolona Wynik;

  Wynik.re = re / a;
  Wynik.im = im /a;
  return Wynik;
}

/*
  Tworzy modol liczby zespolonej podniesiony do kwadratu
  Argumenty:
    Skl1 - liczba zespolona
  Zwraca:
    modol Skl1 podniesiony do kwadratu
*/
/*double Modul2(LZespolona Skl1)
{
  return re*re + im*im;
} */

double LZespolona::Modul2()
{
  return re*re + im*im;
}

/*
  Tworzy sprzezenie liczby zespolonej zmieniajac znak
  czesci urojonej danej liczby
  Argumenty:
    Skl1 - liczba zespolona
  Zwraca:
    sprzezona liczbe Skl1
*/
LZespolona LZespolona::Sprzezenie()
{
  im = -im;
  return *this;
}

/*!
 * Realizuje dzielenie dwoch liczb zespolonych wedlug wzoru.
 * Argumenty:
 *    Skl1 - dzielnik,
 *    Skl2 - dzielna.
 * Zwraca:
 *    Iloraz dwoch skladnikow przekazanych jako parametry.
 */
LZespolona LZespolona::operator / (LZespolona Skl2)
{
  return *this*Skl2.Sprzezenie()/Skl2.Modul2();
}

/*
  Umożliwia spradzenie, czy liczby zespolone są sobie rowne
  Argumenty:
     Skl1 - pierwszy skladnik porownywania,
     Skl2 - drugi skladnik porownywania.
  Zwraca:
     Wartosc prawdziwa, gdy czesci uroone i rzeczywiste danej liczby sa rowne.
*/
bool LZespolona::operator == (LZespolona  Skl2)
{
  if ((re == Skl2.re) && (im == Skl2.im))
    return true;
  else
    return false;
}

bool LZespolona::operator != (LZespolona  Skl2)
{
  if ((re != Skl2.re) && (im != Skl2.im))
    return true;
  else
    return false;
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
  strm << "(" << L.get_re() << std::showpos << L.get_im() << std::noshowpos << "i)";
  return strm;
}

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
  double _re;
  double _im;
  strm >> znak;
  if (znak != '(')
    strm.setstate(std::ios_base::failbit);
  strm >> _re;
  strm >> _im;
  L.set_re(_re);
  L.set_im(_im);
  strm >> znak;
  if (znak != 'i')
    strm.setstate(std::ios_base::failbit);
  strm >> znak;
  if (znak != ')')
    strm.setstate(std::ios_base::failbit);

  return strm;
}
