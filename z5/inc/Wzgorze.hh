#ifndef WZGORZE_HH
#define WZGORZE_HH
#include "Uklad.hh"
#include "Interfejs_rysowania.hh"
#include "Interfejs_kraobrazu.hh"
#include <random>

class Wzgorze : public UkladWsp, public Interfejs_rysowania, public Interfejs_krajobrazu
{
protected:
    std::vector<std::vector<drawNS::Point3D>> wierzcholki;
    double wysokosc;
    int min;
    int max;
public:
    Wzgorze();
    Wzgorze(const Wektor<3> &srodek, int _min, int _max, double wys, drawNS::APIopenGL3D *_api):
    UkladWsp(srodek, Macierz<3>(0, 'Z'), nullptr), wysokosc(wys), min(_min), max(_max) {api=_api; stworz_wzgorze();};
    void stworz_wzgorze();
    void rysuj() override;
    void usun() override;
    void wyswietl_srodek() override;

    bool czy_nad() override;
    bool czy_ladowac() override;

};



#endif