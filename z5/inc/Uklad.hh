#ifndef UKLAD_HH
#define UKLAD_HH

#include "OpenGL_API.hh"
#include "Wektor.hh"
#include "Macierz.hh"
#include <vector>

class UkladWsp{
protected:
    UkladWsp *rodzic;
    Wektor<3> srodek;
    Macierz<3> orientacja;
public:
    UkladWsp(Wektor<3> polozenie, Macierz<3> _orientacja, UkladWsp *poprzedni)
        : rodzic(poprzedni), srodek(polozenie), orientacja(_orientacja) {};
    void przenies_uklad(const Wektor<3> &W) {srodek = srodek + W;};
    void obroc(const Macierz<3> &M) {orientacja = orientacja * M;};
    Wektor<3> licz_do_poprzedniego(Wektor<3> punkt);
    drawNS::Point3D konwertuj(Wektor<3> W) const {return {W[0],W[1],W[2]};};
    Wektor<3> get_srodek() const {return srodek;};
    Macierz<3> get_orientacje() const {return orientacja;};
    UkladWsp licz_do_globalnego();
};


#endif