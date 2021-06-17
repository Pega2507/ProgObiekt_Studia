#ifndef GRAN_HH
#define GRAN_HH

#include "Uklad.hh"
#include "Interfejs_rysowania.hh"

class Graniastoslup : public UkladWsp, public Interfejs_rysowania{
private:
    double wysokosc;
    double promien;
public:
    Graniastoslup();
    explicit Graniastoslup(const Wektor<3> &srodek, const Macierz<3> &orientacja, UkladWsp *rodzic, double wys, double r, drawNS::APIopenGL3D *_api):
    UkladWsp(srodek, orientacja, rodzic), wysokosc(wys), promien(r) {api = _api;};
    void rysuj() override;
    void usun() override;
    void wyswietl_srodek();


};


#endif