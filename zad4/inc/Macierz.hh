#ifndef MACIERZ_HH
#define MACIERZ_HH


#include <iostream>
#include "Wektor.hh"

/*!
 * \file
 * \brief Ten plik powinien zawierać definicję szablonu Macierz<>
 *
 * Ten plik powinien zawierać definicję szablonu Macierz<>.
 * W tym celu należy przerobić definicję klasy Macierz2x2.
 */




/*!
 * \brief  Krótki opis czego to jest szablon
 *
 *  Tutaj trzeba opisac szablon. Jakie pojecie on modeluje
 *  i jakie ma glowne cechy.
 */
template <int Wymiar>
class Macierz{
  private:
  std::vector <std::vector <double>> mac;
public:
  Wektor<Wymiar>  operator * (const Wektor<Wymiar> & Punkt); //m.in obrot punktu
  Wektor<Wymiar> operator* (const Macierz<Wymiar> &Macierz2);
  Macierz ();
  const double  &operator()(int ind_x,int ind_y) const; 
  
};

template <int Wymiar>
Wektor<Wymiar>  Macierz<Wymiar>::operator * (const Wektor<Wymiar> & Punkt)
  {
      Wektor<Wymiar> Wynik;
    for (int i = 0; i<Wymiar; i++)
    {
      for (int j = 0; j < Wymiar; j++)
      {
        Wynik[i] = Wynik[i] + Punkt[j]*mac[i][j];
      }
    }
    return Wynik;
  }

  template <int Wymiar>
Wektor<Wymiar>  Macierz<Wymiar>::operator * (const Macierz<Wymiar> & Macierz2)
  {
      Macierz<Wymiar> Wynik;
    for (int i = 0; i<Wymiar; i++)
    {
      for (int j = 0; j < Wymiar; j++)
      {
        for(int k=0; k<Wymiar; k++)
          Wynik[i][j] = Wynik[i][j] + mac[i][k] * Macierz2[k][j];
      }
    }
    return Wynik;
  }

  template <int Wymiar>
  Macierz<Wymiar>::Macierz ()
  {
   
      mac.resize(Wymiar);
      for(int i=0; i<Wymiar; i++)
      mac[i].resize(Wymiar);
       for(int i=0; i<Wymiar; i++)
        for(int j=0;j<Wymiar; j++)
      mac[i][j] = 0;

     
  }
template <int Wymiar>
  const double & Macierz<Wymiar>::operator()(int ind_x,int ind_y) const
  {
      return mac[ind_x][ind_y];
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
inline
std::ostream& operator << (std::ostream &Strm, const Macierz<Wymiar> &Wek)
{
  /*!
   * Zawartość powinna być przeróbką przeciążenia dla klasy Macierz2x2
   */
  return Strm;  
}


#endif
