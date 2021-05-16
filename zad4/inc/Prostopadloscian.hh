#ifndef PROSTOPADLOSCIAN_HH
#define PROSTOPADLOSCIAN_HH

#include <iostream>
#include "Wektor.hh"
#include "Macierz.hh"



template <int Wymiar> //mogę tu od razu dać 3?
class Prostopadloscian {
private:
  std::vector<Wektor> w;

public:
Prostopadloscian(){};
  Prostopadloscian(Wektor<3> Wierzcholki);
  void przesun(Wektor<3> & P);
  void obroc (double kat, string os);
  void WysWierzcholki();
  bool BokiRowne(); // zwraca 1 gdy boki sa rowne
  const Wektor  &operator()(int ind) const; 
  Wektor  &operator()(int ind) ; 
};


template <int Wymiar>
Prostopadloscian<Wymiar>::Prostopadloscian(Wektor<3> Wierzcholki)
{
    w.resize(8);
    for (int i = 0; i <8 ; i++)
    {
        w[i]= Wierzcholki[i];
    }
    
}

template <int Wymiar>
void Prostopadloscian<Wymiar>::przesun(Wektor<3> &P)
{
  for (int i = 0; i < 8; i++)
  {
       w[i] = P + w[i];
  }
}

template <int Wymiar>
void Prostopadloscian<Wymiar>::obroc(double kat_stopnie, string os)
{
    Macierz m(kat_stopnie, os);
    for (int i = 0; i < 2; i++)
        w[i] = m * w[i];
}

template <int Wymiar>
const Wektor & Prostopadloscian<Wymiar>::operator()(int ind) const
{
    return w[ind];
}
template <int Wymiar>
Wektor &Prostopadloscian<Wymiar>::operator()(int ind)
{
    return w[ind];
}

template <int Wymiar>
void Prostopadloscian<Wymiar>::WysWierzcholki()
{
    for (int i = 0; i < 8; i++)
    std::cout << w[i]<<std::endl;
}

template <int Wymiar>
bool Prostopadloscian<Wymiar>::BokiRowne() //nie zrbione!
{
    double dlugoscA1, dlugoscA2, dlugoscB1, dlugoscB2;
    dlugoscA1 = sqrt(pow(w[0][0][0] - w[0][1][0], 2) + pow(w[0][0][1] - w[0][1][1], 2));
    dlugoscA2 = sqrt(pow(w[1][0][0] - w[1][1][0], 2) + pow(w[1][0][1] - w[1][1][1], 2));
    dlugoscB1 = sqrt(pow(w[0][0][0] - w[1][1][0], 2) + pow(w[0][0][1] - w[1][1][1], 2));
    dlugoscB2 = sqrt(pow(w[0][1][0] - w[1][0][0], 2) + pow(w[0][1][1] - w[1][0][1], 2));
    if ((dlugoscA1 == dlugoscA2) && (dlugoscB1 == dlugoscB2))
        return 1;
    else
        return 0;
    
}

template <int Wymiar>
std::ostream &operator<<(std::ostream &Strm, const Prostopadloscian<Wymiar> &Pr)
{
    for (int i = 0; i < 8; i++)
    {
            Strm << Pr(i) << std::endl;
    }
    return Strm;
}


#endif
