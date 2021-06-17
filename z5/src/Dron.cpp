#include "Dron.hh"
#include <unistd.h>
#define PREDKOSC_LOTU 0.3
#define PREDKOSC_OBROTU 2
#define OPOZNIENIE 0.016
#define OS 'Z'

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
    sleep (0.5);
    usun();
    sleep (0.5);
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
    obroc(Macierz<3>(kat, OS));
    obecne_id = 0;
    rysuj();
    usun();
}

void Dron::animacja(double lot_w_gore, double kat_obrotu, double dystans)
{
    double wysokosc=0;
    double dyst = 0;
    while (wysokosc <= fabs(lot_w_gore))
    {
        wysokosc += PREDKOSC_LOTU;
        if (lot_w_gore > 0)
        {
            lot_gora(PREDKOSC_LOTU);
            obrot_wirnikow();
            sleep(OPOZNIENIE);
        }
        if (lot_w_gore < 0)
        {
            lot_gora(-PREDKOSC_LOTU);
            obrot_wirnikow();
            sleep(OPOZNIENIE);
        }
    }
    while (dyst <= fabs(dystans))
    {
        dyst += PREDKOSC_LOTU;
        if (dystans > 0)
        {
            lot_przod(PREDKOSC_LOTU);
            obrot_wirnikow();
            sleep(OPOZNIENIE);
        }
        if (dystans < 0)
        {
            lot_przod(-PREDKOSC_LOTU);
            obrot_wirnikow();
            sleep(OPOZNIENIE);
        }
    }
    for(int i=0; i<=int(fabs(kat_obrotu)/PREDKOSC_OBROTU); i++)
    {
        if(kat_obrotu>0)
        {
            obrot_drona(PREDKOSC_OBROTU);
            obrot_wirnikow();
            sleep(OPOZNIENIE);
        }
        if(kat_obrotu<0)
        {
            obrot_drona(-PREDKOSC_OBROTU);
            obrot_wirnikow();
            sleep(OPOZNIENIE);
        }
    }
    
}

void Dron::obrot_wirnikow()
{
    for (int i = 0; i<4; i++)
        wirniki[i].obroc(Macierz<3>(30, 'Z'));
}

void Dron::wyswietl_srodek()
{
    std::cout << srodek;
}



