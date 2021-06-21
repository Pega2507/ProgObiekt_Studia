#include "Plaska_powierzchnia.hh"
#include <vector>

#define WIELKOSC_OSI 30.0

void Plaska_pow::rysuj()
{
    std::vector<std::vector<drawNS::Point3D>> wierzcholki;
    std::vector<drawNS::Point3D> rzedy;
    for (int i = -(int)WIELKOSC_OSI; i <= (int)WIELKOSC_OSI; i+=3)
    {
        for (int j = -(int)WIELKOSC_OSI; j <= (int)WIELKOSC_OSI; j+=3)
            rzedy.push_back(konwertuj(Wektor<3>({(double)i,(double)j,wysokosc})));
        wierzcholki.push_back(rzedy);
        rzedy.clear();
    }
    obecne_id = api->draw_surface(wierzcholki, "green");
}

void Plaska_pow::usun()
{
    std::cout<<"Nie mozna usunac powierzchni!";
}

Wektor<3> Plaska_pow::wyswietl_srodek()
{
    std::cout <<"nie mam srodka";
    return Wektor<3> ({0,0,0});
}