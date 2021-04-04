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
  Statystyka LiczbaOdp;
  
  while (Pytania.PobierzNastpnePytanie(&WyrZ_PytanieTestowe)) 
  {
    WyrZ_PytanieTestowe.Wyswietl();
    cout << "Twoja odpowiedz: ";
    cin >> Odpowiedz;
    LiczbaOdp.WpisywanieOdp(Odpowiedz);

    cout << "Twoja odp: " <<Odpowiedz<<endl;


    if (Odpowiedz == WyrZ_PytanieTestowe.Oblicz())
    {
      cout <<"Odpowiedz prawidlowa!" <<endl;
      LiczbaOdp.DobraOdp();
    }
    else
    {
      cout<<"Zle! Prawidlowa odpowiedz to " << WyrZ_PytanieTestowe.Oblicz()<<endl;
      LiczbaOdp.ZlaOdp();
    }
    


  }

  
  cout << endl;
  cout << " Koniec testu" << endl;
  LiczbaOdp.WyswietlStat();
  cout << endl;

}
