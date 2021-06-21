#ifndef SCENA_HH
#define SCENA_HH
#include "Uklad.hh"
#include "Dron.hh"
#include "Wzgorze.hh"
#include "Plaskowyz.hh"
#include "Plaskowyz_prostopadloscienny.hh"
#include "Plaska_powierzchnia.hh"
#include <vector>
#include <memory>

using std::vector;
using std::shared_ptr;
using std::make_shared;

class Scena
{
protected:
    drawNS::APIopenGL3D *api;
    vector<shared_ptr<Interfejs_dron>> kolekcja_dronow;
    vector<shared_ptr<Interfejs_krajobrazu>> kolekcja_krajobrazow;
    vector<shared_ptr<Interfejs_rysowania>> kolekcja_narysowanych;
    shared_ptr<Interfejs_dron> aktywny_dron;
public:
   explicit Scena(drawNS::APIopenGL3D *_api)
   {
       api=_api;
       shared_ptr<Plaska_pow> pow = make_shared<Plaska_pow> (-15, _api);
       shared_ptr<Wzgorze> wzg = make_shared<Wzgorze> (Wektor<3>({10,15,-15}), 6, 8, 13, _api);
       shared_ptr<Plaskowyz> plas = make_shared<Plaskowyz> (Wektor<3>({-10, -15,-15}), 5,6,10, _api);
       shared_ptr<Plaskowyz_prost> plask_prost = make_shared<Plaskowyz_prost> (Wektor<3>({-15,15,-15}), Macierz<3>(0, 'Z'), nullptr, 9, 8, 7, _api);
       shared_ptr<Dron> dron1 = make_shared<Dron> (Wektor<3>({10,20,0}), Macierz<3>(0, 'X'), nullptr, _api);
       shared_ptr<Dron> dron2 = make_shared<Dron> (Wektor<3>({0,0,0}), Macierz<3>(0, 'X'), nullptr, _api);

        kolekcja_narysowanych.push_back(pow);
        kolekcja_narysowanych.push_back(wzg);
        kolekcja_narysowanych.push_back(plas);
        kolekcja_narysowanych.push_back(plask_prost);
        kolekcja_narysowanych.push_back(dron1);
        kolekcja_narysowanych.push_back(dron2);
        kolekcja_krajobrazow.push_back(wzg);
        kolekcja_krajobrazow.push_back(plas);
        kolekcja_krajobrazow.push_back(plask_prost);
        aktywny_dron =std::dynamic_pointer_cast<Interfejs_dron>(dron1);
        kolekcja_dronow.push_back(dron1);
        kolekcja_dronow.push_back(dron2);
   };

    void animuj(double wysokosc, double kat, double dystans)
    {
        if (aktywny_dron != nullptr)
        {
            aktywny_dron->animacja(wysokosc, kat, dystans);
        }
        double temp = 0;
        if (kolizja(temp))
        {
            aktywny_dron->animacja(-temp,0,0);
        }
        else
        {
            std::cout<<"Nie moge ladowac!"<<std::endl;
        }
        
    };

    void rysuj_wszystko()
    {
        for (auto i:kolekcja_narysowanych)
        {
            i->rysuj();
        }
    };
    void pokaz_el_krajobrazu();
    void dodaj_el_krajobrazu();
    void usun_el_krajobrazu();
    void pokaz_drony();
    void dodaj_drona();
    void usun_drona();
    void wybierz_drona();
    bool kolizja(double &dystans);
};



#endif