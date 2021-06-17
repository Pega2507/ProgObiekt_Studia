#include "Statystyka.hh"

Statystyka::Statystyka()
{
    PytDobrze = 0;
    PytZle = 0;
    ZleWpis = 0;
}

void Statystyka::WyswietlStat ()
{
    std::cout << "Poprawne odpowiedzi: " << PytDobrze<<std::endl;
    std::cout << "Niepoprawne odpowiedzi: " << PytZle<<std::endl;
    std::cout << "Procenty: " << PytDobrze * 100.0 / (PytDobrze + PytZle) <<"%"<<std::endl;
}

LZespolona Statystyka::WpisywanieOdp(LZespolona Odpowiedz)
{
    while(std::cin.fail() && ZleWpis < 2) 
    {
     std::cout <<"Zle wpisana liczba. Sprobuj ponownie: ";
     ZleWpis++;
     std::cin.clear();
     std::cin.ignore(1024, '\n');
     std::cin >> Odpowiedz;
    }
    ZleWpis = 0;
    return Odpowiedz;
    
}

int Statystyka::DobraOdp()
{
    PytDobrze++;
    return PytDobrze;
}

int Statystyka::ZlaOdp()
{
    PytZle++;
    return PytZle;
}