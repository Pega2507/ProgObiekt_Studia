#ifndef POWIERZCHNIA_HH
#define POWIERZCHNIA_HH
#include "Uklad.hh"
#include "Interfejs_rysowania.hh"

class Plaska_pow : public Interfejs_rysowania
{
private:
    double wysokosc;
public:
    Plaska_pow();
    explicit Plaska_pow(double wys, drawNS::APIopenGL3D *_api) : wysokosc(wys) {api = _api;};
    void rysuj() override; 
    void usun() override;
    void wyswietl_srodek() override;
    drawNS::Point3D konwertuj(Wektor<3> W) const {return {W[0],W[1],W[2]};};
};

#endif