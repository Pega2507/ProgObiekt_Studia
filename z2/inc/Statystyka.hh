#ifndef STATYSTYKA_HH
#define STATYSTYKA_HH

#include "BazaTestu.hh"
#include "WyrazenieZesp.hh"

struct Statystyka 
{
    int PytDobrze;
    int PytZle;
    int ZleWpis;
};

void WyswietlStat (Statystyka LiczbaOdp);

#endif