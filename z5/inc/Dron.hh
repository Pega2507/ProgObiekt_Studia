#ifndef DRON_HH
#define DRON_HH

#include <iostream>
#include <array>
#include <vector>
#include "Uklad.hh"
#include "Kostka.hh"
#include "Graniastoslup.hh"
#include "Interfejs_dron.hh"
#include "Interfejs_rysowania.hh"
#include "Interfejs_kraobrazu.hh"

class Dron : protected UkladWsp, public Interfejs_dron, public Interfejs_rysowania, public Interfejs_krajobrazu
{
private:
    Kostka_dron cialo;
    std::array<Graniastoslup,4> wirniki;
    std::vector<Interfejs_rysowania*> kolekcja;
public:
    Dron();
    explicit Dron(const Wektor<3> &srodek, const Macierz<3> &orientacja, UkladWsp *rodzic, drawNS::APIopenGL3D *_api):
    UkladWsp(srodek, orientacja, rodzic), cialo(Wektor<3>({0,0,0}), Macierz<3>(), this, 3,4,2, _api), wirniki({
        Graniastoslup(Wektor<3> ({-2,-2,1}),Macierz<3> (),this,0.7,1.3, _api), Graniastoslup(Wektor<3> ({2,-2,1}),Macierz<3> (),this,0.7,1.3, _api),
        Graniastoslup(Wektor<3> ({2,2,1}),Macierz<3> (),this,0.7,1.3, _api), Graniastoslup(Wektor<3> ({-2,2,1}),Macierz<3> (),this,0.7,1.3, _api)
    }) {api = _api; dodaj_do_kolekcji(); promien_ksztaltu = 2.5;};

    void dodaj_do_kolekcji() {
        kolekcja.push_back(&cialo);
        kolekcja.push_back(&wirniki[0]);
        kolekcja.push_back(&wirniki[1]);
        kolekcja.push_back(&wirniki[2]);
        kolekcja.push_back(&wirniki[3]);
    }
    void rysuj() override;
    void usun() override;
    void lot_gora(double dystans) override;
    void lot_przod(double dystans) override;
    void obrot_drona(double kat) override;
    void obrot_wirnikow() override;
    void animacja(double lot_w_gore, double kat_obrotu, double dystant) override;
    Wektor<3> wyswietl_srodek() override;
    
    double lad_na_pdst() override {return 1;};
    bool czy_nad(std::shared_ptr<Interfejs_dron> d) override;
    bool czy_ladowac(std::shared_ptr<Interfejs_dron> d, double &wys_ladowania) override;
};



#endif