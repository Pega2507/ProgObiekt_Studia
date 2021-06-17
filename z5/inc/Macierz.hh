#ifndef MACIERZ_HH
#define MACIERZ_HH

#include <iostream>
#include <cmath>
#include "Wektor.hh"

#define PI 3.14



template <int Wymiar>
class Macierz
{
private:
  std::vector<std::vector<double>> mac;

public:
  Wektor<Wymiar> operator*(const Wektor<Wymiar> &Punkt); //m.in obrot punktu
  Macierz<Wymiar> operator*(const Macierz<Wymiar> &Macierz2);
  Macierz();
  Macierz(double kat, char os);
  const double &operator()(int ind_x, int ind_y) const;
  double &operator()(int ind_x, int ind_y);
};


template <int Wymiar>
Macierz<Wymiar>::Macierz(double kat, char os)
{
  double rad = kat * PI / 180;
  if (Wymiar == 2)
  {
    mac.resize(2);
    for (int i = 0; i < 2; i++)
      mac[i].resize(2);
    mac[0][0] = cos(rad);
    mac[0][1] = -sin(rad);
    mac[1][0] = sin(rad);
    mac[1][1] = cos(rad);
  }
  if (Wymiar == 3)
  {
    mac.resize(3);
    for (int i = 0; i < 3; i++)
      mac[i].resize(3);
    if (os == 'x' || os == 'X')
    {
      mac[0][0] = cos(rad);
      mac[0][1] = -sin(rad);
      mac[0][2] = 0;
      mac[1][0] = sin(rad);
      mac[1][1] = cos(rad);
      mac[1][2] = 0;
      mac[2][0] = 0;
      mac[2][1] = 0;
      mac[2][2] = 1;
    }
    if (os == 'y' || os == 'Y')
    {
      mac[0][0] = cos(rad);
      mac[0][1] = 0;
      mac[0][2] = sin(rad);
      mac[1][0] = 0;
      mac[1][1] = 1;
      mac[1][2] = 0;
      mac[2][0] = -sin(rad);
      mac[2][1] = 0;
      mac[2][2] = cos(rad);
    }
    if (os == 'z' || os == 'Z')
    {
      mac[0][0] = 1;
      mac[0][1] = 0;
      mac[0][2] = 0;
      mac[1][0] = 0;
      mac[1][1] = cos(rad);
      mac[1][2] = -sin(rad);
      mac[2][0] = 0;
      mac[2][1] = sin(rad);
      mac[2][2] = cos(rad);
    }
    }
    else
      std::cerr<<"Niewlasciwy rozmiar macierzy obrotu"<<std::endl;

  
}

template <int Wymiar>
Macierz<Wymiar>::Macierz() 
{

  mac.resize(Wymiar);
  for (int i = 0; i < Wymiar; i++)
    mac[i].resize(Wymiar);
  for (int i = 0; i < Wymiar; i++)
  {
    for (int j = 0; j < Wymiar; j++)
      {
        if (i==j)
          mac[i][j] = 1;
        else
          mac[i][j] = 0;
      }
  }
}

template <int Wymiar>
Wektor<Wymiar> Macierz<Wymiar>::operator*(const Wektor<Wymiar> &Punkt)
{
  Wektor<Wymiar> Wynik;
  for (int i = 0; i < Wymiar; i++)
  {
    for (int j = 0; j < Wymiar; j++)
    {
      Wynik[i] = Wynik[i] + Punkt[j] * mac[i][j];
    }
  }
  return Wynik;
}

template <int Wymiar>
Macierz<Wymiar> Macierz<Wymiar>::operator*(const Macierz<Wymiar> &Macierz2)
{
  Macierz<Wymiar> Wynik;
  for (int i = 0; i < Wymiar; i++)
  {
    for (int j = 0; j < Wymiar; j++)
    {
      for (int k = 0; k < Wymiar; k++)
        Wynik(i,j) = Wynik(i,j) + mac[i][k] * Macierz2(k,j);
    }
  }
  return Wynik;
}

template <int Wymiar>
const double &Macierz<Wymiar>::operator()(int ind_x, int ind_y) const
{
  if (ind_x < 0 || ind_x > Wymiar|| ind_y < 0 || ind_y > Wymiar)
  {
    std::cerr << "Odwolanie poza pamiec!" << std::endl;
    exit(0);
  }
  else
    return mac[ind_x][ind_y];
}

template <int Wymiar>
double &Macierz<Wymiar>::operator()(int ind_x, int ind_y)
{
  if (ind_x < 0 || ind_x > Wymiar|| ind_y < 0 || ind_y > Wymiar)
  {
    std::cerr << "Odwolanie poza pamiec!" << std::endl;
    exit(0);
  }
  else
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
inline std::ostream &operator<<(std::ostream &Strm, const Macierz<Wymiar> &Mac)
{
  for (int i = 0; i < Wymiar; i++)
  {
    for (int j = 0; j < Wymiar; j++)
    {
      std::cout<< Mac(i,j) << "  ";
    }
    std::cout<<std::endl;
  }
  return Strm;
}

template class Macierz<3>;
template std::ostream &operator<<(std::ostream &Strm, const Macierz<3> &Mac);
#endif
