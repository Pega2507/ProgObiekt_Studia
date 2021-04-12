#include "Macierz2x2.hh"


  const Wektor2D  MacierzRot2D::operator * (const Wektor2D & Punkt) const
  {
      Wektor2D Wynik;
    Wynik[0] = Punkt[0] * mac[0][0] + Punkt[1] * mac[0][1];
    Wynik[1] = Punkt[0] * mac[1][0] + Punkt[1] * mac[1][1];
    return Wynik;
  }
  MacierzRot2D::MacierzRot2D (double kat)
  {
      double rad = kat * PI/180;
      mac.resize(2);
      for(int i=0; i<2; i++)
      mac[i].resize(2);
      mac[0][0] = cos(rad);
      mac [0][1] = - sin(rad);
     mac[1][0] = sin(rad);
     mac[1][1] = cos(rad);
  }

  const double & MacierzRot2D::operator()(int ind_x,int ind_y) const
  {
      return mac[ind_x][ind_y];
  }