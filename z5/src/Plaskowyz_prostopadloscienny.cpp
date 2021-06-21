#include "Plaskowyz_prostopadloscienny.hh"
#include "Interfejs_dron.hh"

bool Plaskowyz_prost::czy_nad(std::shared_ptr<Interfejs_dron> d)
{
    std::vector<drawNS::Point3D> w = *((*this).get_wierzcholki());
    double r = std::dynamic_pointer_cast<Interfejs_krajobrazu>(d)->get_promien();
    Wektor<3> temp = std::dynamic_pointer_cast<Interfejs_rysowania>(d)->wyswietl_srodek();
    Wektor<2> C ({temp[0], temp[1]});
    Wektor<2> poziomy_wek({w[1][0]-w[0][0], w[1][1]-w[0][1]});
    Wektor<2> pionowy_wek ({w[3][0]-w[0][0], w[3][1]-w[0][1]});
    double dl_pozioma = poziomy_wek.dlugosc(); 
    double dl_pionowa = pionowy_wek.dlugosc();  
    poziomy_wek = poziomy_wek * (r/dl_pozioma);
    pionowy_wek = pionowy_wek * (r/dl_pionowa); 
    std::array<Wektor<2>, 4> nowe_wierz;
    for (int i=0; i<4; i++) 
    {
        nowe_wierz[i][0] = w[i][0];
        nowe_wierz[i][1] = w[i][1];
    }
    nowe_wierz[0] = nowe_wierz[0] - poziomy_wek - pionowy_wek;
    nowe_wierz[1] = nowe_wierz[1] + poziomy_wek - pionowy_wek;
    nowe_wierz[2] = nowe_wierz[2] + poziomy_wek + pionowy_wek;
    nowe_wierz[3] = nowe_wierz[3] - poziomy_wek + pionowy_wek;
    std::array<Wektor<2>, 4> wektory;

    if (poziomy_wek[0]>0 && poziomy_wek[1]>=0) {
        wektory[0]=nowe_wierz[0]; wektory[1]=nowe_wierz[1]; wektory[2]=nowe_wierz[2]; wektory[3]=nowe_wierz[3];
    } else if (poziomy_wek[0]<=0 && poziomy_wek[1]>0) {
        wektory[0]=nowe_wierz[3]; wektory[1]=nowe_wierz[0]; wektory[2]=nowe_wierz[1]; wektory[3]=nowe_wierz[2];
    } else if (poziomy_wek[0]<0 && poziomy_wek[1]<=0) {
        wektory[0]=nowe_wierz[2]; wektory[1]=nowe_wierz[3]; wektory[2]=nowe_wierz[0]; wektory[3]=nowe_wierz[1];
    } else if (poziomy_wek[0]>=0 && poziomy_wek[1]<0) {
        wektory[0]=nowe_wierz[1]; wektory[1]=nowe_wierz[2]; wektory[2]=nowe_wierz[3]; wektory[3]=nowe_wierz[0];
    } 
    double poziom1, poziom2, poziom3;
    double pion1, pion2, pion3;
    
    poziom1 = wektory[0][1] - wektory[1][1];
    poziom2 = wektory[1][0] - wektory[0][0];
    if (poziom2 == 0)
        poziom2 = 0.000000001;
    poziom3 = wektory[1][1]*wektory[0][0] - wektory[0][1]*wektory[1][0];
    
    pion1 = wektory[3][1] - wektory[0][1];
    pion2 = wektory[0][0] - wektory[3][0];
    if (pion2 == 0)
        pion2 = 0.0001;
    pion3 = wektory[0][1]*wektory[3][0] - wektory[3][1]*wektory[0][0];

    if (C[1] > -(poziom1*C[0]+poziom3)/poziom2 && fabs(poziom1*C[0]+poziom2*C[1]+poziom3)/sqrt(pow(poziom1,2)+pow(poziom2,2)) < (wektory[3]-wektory[0]).dlugosc()) {
        if (C[1] > -(pion1*C[0]+pion3)/pion2 && fabs(pion1*C[0]+pion2*C[1]+pion3)/sqrt(pow(pion1,2)+pow(pion2,2)) < (wektory[1]-wektory[0]).dlugosc()) {
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }

}

bool Plaskowyz_prost::czy_ladowac(std::shared_ptr<Interfejs_dron> d, double &wys_ladowania)
{
    std::vector<drawNS::Point3D> w = *((*this).get_wierzcholki());
    double r = std::dynamic_pointer_cast<Interfejs_krajobrazu>(d)->get_promien();
    Wektor<3> temp = std::dynamic_pointer_cast<Interfejs_rysowania>(d)->wyswietl_srodek();
    Wektor<2> C ({temp[0], temp[1]});
    Wektor<2> poziomy_wek({w[1][0]-w[0][0], w[1][1]-w[0][1]});
    Wektor<2> pionowy_wek ({w[3][0]-w[0][0], w[3][1]-w[0][1]});
    double dl_pozioma = poziomy_wek.dlugosc(); 
    double dl_pionowa = pionowy_wek.dlugosc();  
    poziomy_wek = poziomy_wek * (r/dl_pozioma);
    pionowy_wek = pionowy_wek * (r/dl_pionowa); 
    std::array<Wektor<2>, 4> nowe_wierz;
    for (int i=0; i<4; i++) 
    {
        nowe_wierz[i][0] = w[i][0];
        nowe_wierz[i][1] = w[i][1];
    }
    std::array<Wektor<2>, 4> wektory;

    if (poziomy_wek[0]>0 && poziomy_wek[1]>=0) {
        wektory[0]=nowe_wierz[0]; wektory[1]=nowe_wierz[1]; wektory[2]=nowe_wierz[2]; wektory[3]=nowe_wierz[3];
    } else if (poziomy_wek[0]<=0 && poziomy_wek[1]>0) {
        wektory[0]=nowe_wierz[3]; wektory[1]=nowe_wierz[0]; wektory[2]=nowe_wierz[1]; wektory[3]=nowe_wierz[2];
    } else if (poziomy_wek[0]<0 && poziomy_wek[1]<=0) {
        wektory[0]=nowe_wierz[2]; wektory[1]=nowe_wierz[3]; wektory[2]=nowe_wierz[0]; wektory[3]=nowe_wierz[1];
    } else if (poziomy_wek[0]>=0 && poziomy_wek[1]<0) {
        wektory[0]=nowe_wierz[1]; wektory[1]=nowe_wierz[2]; wektory[2]=nowe_wierz[3]; wektory[3]=nowe_wierz[0];
    } 
    double poziom1, poziom2, poziom3;
    double pion1, pion2, pion3;
    
    poziom1 = wektory[0][1] - wektory[1][1];
    poziom2 = wektory[1][0] - wektory[0][0];
    if (poziom2 == 0)
        poziom2 = 0.000000001;
    poziom3 = wektory[1][1]*wektory[0][0] - wektory[0][1]*wektory[1][0];
    
    pion1 = wektory[3][1] - wektory[0][1];
    pion2 = wektory[0][0] - wektory[3][0];
    if (pion2 == 0)
        pion2 = 0.0001;
    pion3 = wektory[0][1]*wektory[3][0] - wektory[3][1]*wektory[0][0];

    if (C[1] > -(poziom1*C[0]+poziom3)/poziom2 && fabs(poziom1*C[0]+poziom2*C[1]+poziom3)/sqrt(pow(poziom1,2)+pow(poziom2,2)) < (wektory[3]-wektory[0]).dlugosc()) {
        if (C[1] > -(pion1*C[0]+pion3)/pion2 && fabs(pion1*C[0]+pion2*C[1]+pion3)/sqrt(pow(pion1,2)+pow(pion2,2)) < (wektory[1]-wektory[0]).dlugosc()) {
            wys_ladowania = temp[2] -w[0][2] - d->lad_na_pdst();
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}

Wektor<3> Plaskowyz_prost::wyswietl_srodek()
{
    return srodek;
}
