#include <iostream>
#include "BazaTestu.hh"
#include "Statystyka.hh"
using namespace std;




int main(int argc, char **argv)
{

  if (argc < 2) {
    cout << endl;
    cout << " Brak opcji okreslajacej rodzaj testu." << endl;
    cout << " Dopuszczalne nazwy to:  latwy, trudny." << endl;
    cout << endl;
    return 1;
  }

  BazaTestu Pytania;
  if (Pytania.InicjalizujTest(argv[1]) == false) {
    cerr << " Inicjalizacja testu nie powiodla sie." << endl;
    return 1;
  }

  cout << endl;
  cout << " Start testu arytmetyki zespolonej: " << argv[1] << endl;
  cout << endl;

  WyrazenieZesp WyrZ_PytanieTestowe;
  LZespolona Odpowiedz;
  Statystyka LiczbaOdp={0, 0, 0};
  
  while (Pytania.PobierzNastpnePytanie(WyrZ_PytanieTestowe)) 
  {
    Wyswietl(WyrZ_PytanieTestowe);
    cout << "Twoja odpowiedz: ";
    cin >> Odpowiedz;
    
    while(cin.fail() && LiczbaOdp.ZleWpis < 3) 
    {
     cout <<"Zle wpisana liczba. Sprobuj ponownie: ";
     LiczbaOdp.ZleWpis++;
     cin.clear();
     cin.ignore(1024, '\n');
     cin >> Odpowiedz;
    }

    if (Odpowiedz == Oblicz(WyrZ_PytanieTestowe))
    {
      cout <<"Odpowiedz prawidlowa!" <<endl;
      LiczbaOdp.PytDobrze++;
    }
    else
    {
      cout<<"Zle! Prawidlowa odpowiedz to " << Oblicz(WyrZ_PytanieTestowe)<<endl;
      LiczbaOdp.PytZle++;
    }
    


  }

  
  cout << endl;
  cout << " Koniec testu" << endl;
  WyswietlStat(LiczbaOdp);
  cout << endl;

}
