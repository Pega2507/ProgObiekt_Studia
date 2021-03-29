#ifndef BAZATESTU_HH
#define BAZATESTU_HH


#include "WyrazenieZesp.hh"
#include <fstream>


/*
 * Modeluje pojecie baze testu z zestawem pytan w tablicy
 * oraz informacji o maksymalnej ilosci pytan, jak
 * tez indeksem nastepnego pytania, ktore ma byc pobrane
 * z bazy.
 */
class BazaTestu {
private:
  WyrazenieZesp *wskTabTestu;   /* Wskaznik na tablice zawierajaca pytania testu */
  unsigned int IloscPytan;    /* Ilosc wszystkich pytan */
  unsigned int IndeksPytania; /* Numer pytania, ktore ma byc pobrane jako nastepne */
  std::fstream plik;
public:
  BazaTestu(std::nullptr_t name=nullptr, int a=0, int b=0);
  bool InicjalizujTest(const char*  sNazwaTestu);
  bool PobierzNastpnePytanie(WyrazenieZesp *wskWyr);
  void UstawTest(WyrazenieZesp *wskTabTestu, unsigned int IloscPytan);

};
 

#endif
