#include "Uklad.hh"

Wektor<3> UkladWsp::licz_do_poprzedniego(Wektor<3> punkt)
{
    Wektor<3> wynik = rodzic->get_srodek() + rodzic->get_orientacje()*(srodek+orientacja*punkt);
    return wynik;
}

UkladWsp UkladWsp::licz_do_globalnego()
{
    if (rodzic != nullptr)
    {
        UkladWsp temp = rodzic ->licz_do_globalnego();
        temp.przenies_uklad(srodek);
        temp.obroc(orientacja);
        return temp;
    }
    else
    {
        return *this; //zwraca globalny uklad
    }
    
}
