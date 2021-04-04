#ifndef STATYSTYKA_HH
#define STATYSTYKA_HH

#include "BazaTestu.hh"
#include "WyrazenieZesp.hh"

class Statystyka 
{
private:
    int PytDobrze;
    int PytZle;
    int ZleWpis;
public:
    Statystyka();
    void WyswietlStat ();
    int DobraOdp ();
    int ZlaOdp ();
    LZespolona WpisywanieOdp(LZespolona Odpowiedz);
};



#endif