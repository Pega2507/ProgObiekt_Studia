#include "Statystyka.hh"

void WyswietlStat (Statystyka LiczbaOdp)
{
    std::cout << "Poprawne odpowiedzi: " << LiczbaOdp.PytDobrze<<std::endl;
    std::cout << "Niepoprawne odpowiedzi: " << LiczbaOdp.PytZle<<std::endl;
    std::cout << "Procenty: " << LiczbaOdp.PytDobrze * 100.0 / (LiczbaOdp.PytDobrze + LiczbaOdp.PytZle) <<"%"<<std::endl;

}