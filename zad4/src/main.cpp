#include <iostream>
#include <iomanip>
#include <fstream>
#include "Wektor.hh"
#include "Wektor3D.hh"
#include "Macierz.hh"
#include "Macierz3x3.hh"
#include "Prostopadloscian.hh"
#include "lacze_do_gnuplota.hh"



using namespace std;

/*
 * Tu definiujemy pozostale funkcje.
 * Lepiej jednak stworzyc dodatkowy modul
 * i tam je umiescic. Ten przyklad pokazuje
 * jedynie absolutne minimum.
 */


#define DL_BOKU   50





/*!
 * Przyklad zapisu wspolrzednych zbioru punktow do strumienia wyjściowego.
 * Dane sa odpowiednio sformatowane, tzn. przyjęto notację stałoprzecinkową
 * z dokładnością do 10 miejsca po przecinku. Szerokość wyświetlanego pola 
 * to 16 miejsc, sposób wyrównywania - do prawej strony.
 * \param[in] StrmWy - strumien wyjsciowy, do ktorego maja zostac zapisane
 *                     kolejne wspolrzedne.
 * \param[in] Przesuniecie - ten parameter jest tylko po to, aby pokazać
 *                          mozliwosc zmiany wspolrzednych i prostokata
 *                          i zmiane jego polorzenia na okienku graficznym
 *                         rysownym przez gnuplota.
 * \retval true - gdy operacja zapisu powiodła się,
 * \retval false - w przypadku przeciwnym.
 */
void PrzykladZapisuWspolrzednychDoStrumienia( ostream&     StrmWy, 
                                              Prostopadloscian       Przesuniecie
                                            )
{

  StrmWy << Przesuniecie;
    StrmWy << Przesuniecie[0];
      StrmWy << Przesuniecie[1];
}



/*!
 * Przyklad zapisu wspolrzednych zbioru punktow do pliku, z ktorego
 * dane odczyta program gnuplot i narysuje je w swoim oknie graficznym.
 * \param[in] sNazwaPliku - nazwa pliku, do którego zostana zapisane
 *                          wspolrzędne punktów.
 * \param[in] Przesuniecie - ten parameter jest tylko po to, aby pokazać
 *                          mozliwosc zmiany wspolrzednych i prostokata
 *                          i zmiane jego polorzenia na okienku graficznym
 *                         rysownym przez gnuplota.
 * \retval true - gdy operacja zapisu powiodła się,
 * \retval false - w przypadku przeciwnym.
 */
bool PrzykladZapisuWspolrzednychDoPliku( const char  *sNazwaPliku,
                                         Prostopadloscian       Przesuniecie
                                       )
{
  ofstream  StrmPlikowy;

  StrmPlikowy.open(sNazwaPliku);
  if (!StrmPlikowy.is_open())  {
    cerr << ":(  Operacja otwarcia do zapisu \"" << sNazwaPliku << "\"" << endl
	 << ":(  nie powiodla sie." << endl;
    return false;
  }

  PrzykladZapisuWspolrzednychDoStrumienia(StrmPlikowy,Przesuniecie);

  StrmPlikowy.close();
  return !StrmPlikowy.fail();
}


void WyswOpcje()
{
       cout << "o - obrot bryly o zadany kat " << endl;
       cout << "t - powtorzenie poprzedniego obrotu " << endl;
       cout << "r - wyswietlenie macierzy obrotu " << endl;
       cout << "p - przesuniecie bryly o zadany wektor " << endl;
       cout << "w - wyswietlenie wspolrzednych wierzcholkow " << endl;
       cout << "s - sprawdzenie dlugosci przeciwleglych bokow " << endl;
       cout << "m - wyswietl menu " << endl;
       cout << "k - koniec dzialania programu " << endl<< endl;
}


int main()
{
  PzG::LaczeDoGNUPlota  Lacze;  // Ta zmienna jest potrzebna do wizualizacji
                                // rysunku prostokata
  char wybor;
  string os;
  double kat, il_obrotow;
  Wektor3D wierz[8];
  Macierz3x3 Macierz_obrotu;
   //-------------------------------------------------------
   //  Wspolrzedne wierzcholkow beda zapisywane w pliku "prostokat.dat"
   //  Ponizsze metody powoduja, ze dane z pliku beda wizualizowane
   //  na dwa sposoby:
   //   1. Rysowane jako linia ciagl o grubosci 2 piksele
   //
  Lacze.DodajNazwePliku("prostopadloscian.dat",PzG::RR_Ciagly,2);
   //
   //  Ustawienie trybu rysowania 3D, tzn. rysowany zbiór punktów
   //  znajduje się na wspólnej płaszczyźnie. Z tego powodu powoduj
   //  jako wspolrzedne punktow podajemy x,y,z.
   //
  Lacze.ZmienTrybRys(PzG::TR_3D);

   // Ustawienie zakresow poszczegolnych osi
  Lacze.UstawZakresY(-155,155);
  Lacze.UstawZakresX(-155,155);
  Lacze.UstawZakresZ(-155,155);

cout << "Podaj wierzcholki prostopadloscianu: " << endl;
for (int i = 0; i < 8; i++)
       cin >> wierz[i];

Prostopadloscian Pr (wierz[0], wierz[1], wierz[3], wierz[4], 
              wierz[6], wierz[7], wierz[4], wierz[5]);
Wektor3D wek;
  while (wybor != 'k')
       {
              if (Pr.BokiRowne() == 0)
              {
                     cerr<<"Boki prostopadloscianu nie sa rowne!!!"<<endl;
              }
              if (!PrzykladZapisuWspolrzednychDoPliku("prostopadloscian.dat", Pr))
                     return 1;
              Lacze.Rysuj();
              cout<<"Twoj wybor? (m-menu): ";
              cin >> wybor;
              switch (wybor)
              {
              case 'o':
                     cout << "Podaj kat (w stopniach) obrotu: ";
                     cin >> kat;
                     cout << "Ile razy obrocic prostokat?: ";
                     cin >> il_obrotow;
                     cout << "Podaj os obrotu: ";
                     cin >> os;
                     Pr.obroc(kat * il_obrotow, os);
                     break;
              case 't':
                     Pr.obroc(kat * il_obrotow, os);
                     break;
              case 'r':
                     cout << Macierz_obrotu;
                     break;
              case 'p':
                     cout << "Podaj wektor przesuniecia: ";
                     cin >> wek;
                     Pr.przesun(wek);
                     break;
              case 's':
                     cout<<"Sprawdzenie rownych bokow. "<<endl;
                     if(Pr.BokiRowne() == 1)
                            cout<<"Boki sa rowne"<<endl;
                     break;
              case 'w':
                     cout << "Wierzcholki prostopadloscianu: " << endl;
                     Pr.WysWierzcholki();
                     break;
              case 'm':
                     WyswOpcje();
                     break;
              default:
                     cout << "Niepoprawna opcja!" << endl;
                     break;
              }
       }
       cout << "Koniec programu" << endl;
}
