#include "Dron.hh"
#include <unistd.h>
#include <cmath>
const double predkosc_lotu = 0.3;
const double predkosc_obrotu = 1.5;
const int opoznienie = 16;

void Dron::rysuj()
{
    if(rodzic != nullptr)
    {
        UkladWsp temp=licz_do_globalnego();
        srodek = temp.get_srodek();
        orientacja = temp.get_orientacje();
        rodzic = nullptr;
    }
    if (obecne_id ==0 || poprzednie_id == -1)
    {
        for (auto i : kolekcja)
            i->rysuj();
        obecne_id = -1;
        poprzednie_id = 0;
    }
}


void Dron::usun()
{
    for (auto i : kolekcja)
    {
        i->usun();
    }
}


void Dron::lot_gora(double dystans)
{
    przenies_uklad(Wektor<3> ({0,0,dystans}));
    obecne_id = 0;
    rysuj();
    usun();
    
}

void Dron::lot_przod(double dystans)
{
    przenies_uklad(orientacja*Wektor<3> ({0,dystans,0}));
    obecne_id = 0;
    rysuj();
    usun();
}

void Dron::obrot_drona(double kat)
{
    obroc(Macierz<3>(kat, 'X'));
    
    obecne_id = 0;
    rysuj();
    usun();
}

void Dron::animacja(double lot_w_gore, double kat_obrotu, double dystans)
{
    double wysokosc=0;
    double dyst = 0;
    while (wysokosc < fabs(lot_w_gore))
    {
        wysokosc += predkosc_lotu;
        if (lot_w_gore > 0)
        {
            lot_gora(predkosc_lotu);
            obrot_wirnikow();
            std::this_thread::sleep_for(std::chrono::milliseconds(opoznienie)); //wgl nie lapie opoznienia
        }
        if (lot_w_gore < 0)
        {
            lot_gora(-predkosc_lotu);
            obrot_wirnikow();
            std::this_thread::sleep_for(std::chrono::milliseconds(opoznienie));
        }
    }
    while (dyst < fabs(dystans))
    {
        dyst += predkosc_lotu;
        if (dystans > 0)
        {
            lot_przod(predkosc_lotu);
            //obrot_wirnikow();
            std::this_thread::sleep_for(std::chrono::milliseconds(opoznienie));
        }
        if (dystans < 0)
        {
            lot_przod(-predkosc_lotu);
            obrot_wirnikow();
            std::this_thread::sleep_for(std::chrono::milliseconds(opoznienie));
        }
    }
    std::cout<<Macierz<3>(kat_obrotu, 'X')<<std::endl;
    for(int i=0; i<int(fabs(kat_obrotu)/predkosc_obrotu); i++)
    {
        if(kat_obrotu>0)
        {
            obrot_drona(predkosc_obrotu);
            
            //obrot_wirnikow();
            std::this_thread::sleep_for(std::chrono::milliseconds(opoznienie));
        }
        if(kat_obrotu<0)
        {
            obrot_drona(-predkosc_obrotu);
            obrot_wirnikow();
            std::this_thread::sleep_for(std::chrono::milliseconds(opoznienie));
        }
    }
    
}

void Dron::obrot_wirnikow()
{
    for (int i = 0; i<4; i++)
        wirniki[i].obroc(Macierz<3>(30, 'X'));
}

void Dron::wyswietl_srodek()
{
    std::cout << srodek;
}



