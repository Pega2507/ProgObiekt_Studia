#ifndef PLASK_SZESCIENNY_HH
#define PLASK_SZESCIENNY_HH
#include "Kostka.hh"
#include "Interfejs_kraobrazu.hh"


class Plaskowyz_prost : public Kostka, public Interfejs_krajobrazu
{
public:
    Plaskowyz_prost();
   explicit Plaskowyz_prost(Wektor<3> srodek, const Macierz<3> &orientacja, UkladWsp *rodzic, double glebokosc, double szerokosc, double wysokosc, drawNS::APIopenGL3D *_api):
    Kostka(srodek + Wektor<3>({0,0, wysokosc/2}), orientacja, nullptr, glebokosc, szerokosc, wysokosc, _api) {};
    bool czy_nad(std::shared_ptr<Interfejs_dron> d) override;
    bool czy_ladowac(std::shared_ptr<Interfejs_dron> d, double &wys_ladowania) override;
    Wektor<3> wyswietl_srodek() override;
    
};

#endif