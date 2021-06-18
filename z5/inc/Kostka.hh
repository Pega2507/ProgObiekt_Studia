#ifndef KOSTKA_HH
#define KOSTKA_HH

#include "Uklad.hh"
#include "Interfejs_rysowania.hh"

class Kostka : public UkladWsp, public Interfejs_rysowania{ //do krajobrazow
private:
    double glebokosc; //x width
    double szerokosc; //y height
    double wysokosc; //z depth
public:
    explicit Kostka(const Wektor<3> &srodek, const Macierz<3> &orientacja, UkladWsp *rodzic, double gl, double szer, double wys, drawNS::APIopenGL3D *_api):
    UkladWsp(srodek, orientacja, rodzic), glebokosc(gl), szerokosc(szer), wysokosc(wys) {api = _api;};
    void rysuj() override; 
    void usun() override;
    void wyswietl_srodek() override;

};

class Kostka_dron : public UkladWsp, public Interfejs_rysowania{ //do drona, animowalne
private:
    double glebokosc;
    double szerokosc;
    double wysokosc;
public:
    explicit Kostka_dron(const Wektor<3> &srodek, const Macierz<3> &orientacja, UkladWsp *rodzic, double gl, double szer, double wys, drawNS::APIopenGL3D *_api):
    UkladWsp(srodek, orientacja, rodzic), glebokosc(gl), szerokosc(szer), wysokosc(gl) {api = _api;};
    void rysuj() override; 
    void usun() override;
    void wyswietl_srodek() override;

};


#endif