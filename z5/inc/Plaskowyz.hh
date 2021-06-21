#ifndef PLASKOWYZ_HH
#define PLASKOWYZ_HH
#include "Uklad.hh"
#include <vector>
#include <random>
#include "Interfejs_rysowania.hh"
#include "Interfejs_kraobrazu.hh"

class Plaskowyz : public UkladWsp, public Interfejs_rysowania, public Interfejs_krajobrazu
{
protected:
    std::vector<std::vector<drawNS::Point3D>> wierzcholki;
    double wysokosc;
    int min;
    int max;
    double max_promien = 0;
    std::vector<drawNS::Point3D> wierzcholki2;
public:
    Plaskowyz();
    Plaskowyz(const Wektor<3> &srodek, int _min, int _max, double wys, drawNS::APIopenGL3D *_api):
    UkladWsp(srodek, Macierz<3>(0, 'Z'), nullptr), wysokosc(wys), min(_min), max(_max) {api=_api; stworz_plaskowyz();};
    void stworz_plaskowyz();
    void rysuj() override;
    void usun() override;
    Wektor<3> wyswietl_srodek() override;
    bool czy_nad(std::shared_ptr<Interfejs_dron> d) override;
    bool czy_ladowac(std::shared_ptr<Interfejs_dron> d, double &wys_ladowania) override;

};

#endif