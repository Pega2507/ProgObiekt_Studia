#include <iostream>
#include <cstring>
#include <cassert>
#include "BazaTestu.hh"

using namespace std;


BazaTestu::BazaTestu ()
{
  wskTabTestu = 0;
  IloscPytan = 0;
  IndeksPytania = 0;
}

/*
 * Inicjalizuje test kojarzac zmienna dostepna poprzez wskaznik wskBazaTestu
 * z dana tablica wyrazen, ktora reprezentuje jeden z dwoch dopuszczalnych
 * testow.
 * Parametry:
 *    wskBazaTestu - wskaznik na zmienna reprezentujaca baze testu.
 *    sNazwaTestu  - wskaznik na napis wybranego typu testu.
 *
 * Warunki wstepne:
 *      - Parametr wskBazaTestu nie moze byc pustym wskaznikiem. Musi zawierac adres
 *        zmiennej reprezentujacej baze testu, ktora wczesniej zostal poprawnie
 *        zainicjalizowany poprzez wywolanie funkcji InicjalizujTest.
 *      - Parametr sNazwaTestu musi wskazywac na jedna z nazw tzn. "latwe" lub "trudne".
 *
 * Zwraca:
 *       true - gdy operacja sie powiedzie i test zostanie poprawnie
 *              zainicjalizowany,
 *       false - w przypadku przeciwnym.
 */

bool BazaTestu::InicjalizujTest(const char *sNazwaTestu )
{
  if (!strcmp(sNazwaTestu,"latwy")) {
    plik.open("latwy.dat",ios::in);
    return true;
  }
  if (!strcmp(sNazwaTestu,"trudny")) {
    plik.open("trudny.dat",ios::in);
    return true;
  }

  cerr << "Otwarcie testu '" << sNazwaTestu << "' nie powiodlo sie." << endl;
  return false;
}



/*!
 * Funkcja udostepnia nastepne pytania o ile jest odpowiednia ich ilosc.
 * Parametry:
 *       wskBazaTestu - wskaznik na zmienna reprezentujaca baze testu.
 *       wskWyrazenie - wskaznik na zmienna, do ktorej zostanie wpisane
 *                      kolejne wyrazenie z bazy testu.
 *
 * Warunki wstepne:
 *      - Parametr wskBazaTestu nie moze byc pustym wskaznikiem. Musi zawierac adres
 *        zmiennej reprezentujacej baze testu, ktora wczesniej zostal poprawnie
 *        zainicjalizowany poprzez wywolanie funkcji InicjalizujTest.
 *      - Parametr wskWyrazenie nie moze byc pustym wskaznikiem. Musi wskazywac na
 *        istniejaca zmienna.
 *
 * Zwraca:
 *       true - gdy operacja sie powiedzie i parametrowi *wskWyrazenie zostanie
 *              przypisane nowe wyrazenie zespolone z bazy,
 *       false - w przypadku przeciwnym.
 */
bool BazaTestu::PobierzNastpnePytanie(WyrazenieZesp *wskWyrazenie )
{
    while(1)
    {
    plik>>*wskWyrazenie;
    if(plik.eof())
        return false;
    if(plik.good())
        return true;
    plik.clear();
    plik.ignore(1024, '\n');
    }


  return true;
}
