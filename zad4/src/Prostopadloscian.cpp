#include "Prostopadloscian.hh"


/*
P- podstawa
S - sufit
np: PLD - podstawa lewy dolny
*/
Prostopadloscian::Prostopadloscian(Wektor3D PLD, Wektor3D PPD, Wektor3D PLG, Wektor3D PPG,
                         Wektor3D SLD, Wektor3D SPD, Wektor3D SLG, Wektor3D SPG)
{
    w.resize(8);
    w[0] = PLD;
    w[1] = PPD;
    w[2] = PPG;
    w[3] = PLG;
    w[4] = SLG;
    w[5] = SLD;
    w[6] = SPD;
    w[7] = SPG;
    
}

 
void Prostopadloscian   ::przesun( Wektor3D   &P)
{
  for (int i = 0; i < 8; i++)
  {
       w[i] = P + w[i];
  }
}

 
void Prostopadloscian::obroc(double kat,  std::string os)
{
     Macierz3x3 m(kat, os);
    for (int i = 0; i < 2; i++)
        w[i] = m * w[i];
}

 
const  Wektor3D & Prostopadloscian   ::operator[](int ind) const
{
    return w[ind];
}
 
 Wektor3D &Prostopadloscian   ::operator[](int ind)
{
    return w[ind];
}

 
void Prostopadloscian   ::WysWierzcholki()
{
    for (int i = 0; i < 8; i++)
    std::cout << w[i]<<std::endl;
}

 
bool Prostopadloscian   ::BokiRowne() //nie zrbione!
{
    double dlugoscA1, dlugoscA2, dlugoscB1, dlugoscB2;
    dlugoscA1 = sqrt(pow(w[0][0] - w[0][1], 2) + pow(w[0][0] - w[0][1], 2));
    dlugoscA2 = sqrt(pow(w[1][0] - w[1][1], 2) + pow(w[1][0] - w[1][1], 2));
    dlugoscB1 = sqrt(pow(w[0][0] - w[1][1], 2) + pow(w[0][0] - w[1][1], 2));
    dlugoscB2 = sqrt(pow(w[0][1] - w[1][0], 2) + pow(w[0][1] - w[1][0], 2));
    if ((dlugoscA1 == dlugoscA2) && (dlugoscB1 == dlugoscB2))
        return 1;
    else
        return 0;
    
}

 
