#include <iostream>
#include <iomanip>
#include <fstream>
#include "Wektor2D.hh"
#include "Macierz2x2.hh"
#include "Prostokat.hh"
#include "lacze_do_gnuplota.hh"

using namespace std;

#define DL_KROTKI_BOK 100
#define DL_DLUGI_BOK 150

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
void PrzykladZapisuWspolrzednychDoStrumienia(ostream &StrmWy, double Przesuniecie)
{
       //---------------------------------------------------------------
       // To tylko przyklad !!!
       // W programie nalezy uzywać pojęcia wektora, a nie oddzielnych
       // zmiennych do reprezentowania wspolrzednych!
       //
       double x1, y1, x2, y2, x3, y3, x4, y4;

       x1 = y1 = 10;
       x2 = x1 + DL_DLUGI_BOK;
       y2 = y1;
       x3 = x2;
       y3 = y2 + DL_KROTKI_BOK;
       x4 = x3 - DL_DLUGI_BOK;
       y4 = y3;

       StrmWy << setw(16) << fixed << setprecision(10) << x1 + Przesuniecie
              << setw(16) << fixed << setprecision(10) << y1 + Przesuniecie << endl;
       StrmWy << setw(16) << fixed << setprecision(10) << x2 + Przesuniecie
              << setw(16) << fixed << setprecision(10) << y2 + Przesuniecie << endl;
       StrmWy << setw(16) << fixed << setprecision(10) << x3 + Przesuniecie
              << setw(16) << fixed << setprecision(10) << y3 + Przesuniecie << endl;
       StrmWy << setw(16) << fixed << setprecision(10) << x4 + Przesuniecie
              << setw(16) << fixed << setprecision(10) << y4 + Przesuniecie << endl;
       StrmWy << setw(16) << fixed << setprecision(10) << x1 + Przesuniecie
              << setw(16) << fixed << setprecision(10) << y1 + Przesuniecie << endl;
       // Jeszcze raz zapisujemy pierwszy punkt,
       // aby gnuplot narysowal zamkniętą linię.
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
bool PrzykladZapisuWspolrzednychDoPliku(const char *sNazwaPliku, Prostokat Pr)
{
       ofstream StrmPlikowy;

       StrmPlikowy.open(sNazwaPliku);
       if (!StrmPlikowy.is_open())
       {
              cerr << ":(  Operacja otwarcia do zapisu \"" << sNazwaPliku << "\"" << endl
                   << ":(  nie powiodla sie." << endl;
              return false;
       }

       StrmPlikowy << Pr;
       StrmPlikowy << Pr(0, 0);

       StrmPlikowy.close();
       return !StrmPlikowy.fail();
}

/*
Funkcja wyswietlajaca opcje wyboru
*/
void WyswOpcje()
{
       cout << "o - obrot prostokata o zadany kat " << endl;
       cout << "p - przesuniecie prostokata o zadany wektor " << endl;
       cout << "w - wyswietlenie wspolrzednych wierzcholkow " << endl;
       cout << "m - wyswietl menu " << endl;
       cout << "k - koniec dzialania programu " << endl<< endl;
}

int main()
{
       // To tylko przykladowe definicje zmiennej
       PzG::LaczeDoGNUPlota Lacze; // Ta zmienna jest potrzebna do wizualizacji
                                   // rysunku prostokata
       Wektor2D Wektor;
       Wektor2D wierz[4];
       MacierzRot2D Macierz(30);
       char wybor;
       double kat, il_obrotow;

       //-------------------------------------------------------
       //  Wspolrzedne wierzcholkow beda zapisywane w pliku "prostokat.dat"
       //  Ponizsze metody powoduja, ze dane z pliku beda wizualizowane
       //  na dwa sposoby:
       //   1. Rysowane jako linia ciagl o grubosci 2 piksele
       //
       Lacze.DodajNazwePliku("prostokat.dat", PzG::RR_Ciagly, 2);
       //
       //   2. Rysowane jako zbior punktow reprezentowanych przez kwadraty,
       //      których połowa długości boku wynosi 2.
       //
       Lacze.DodajNazwePliku("prostokat.dat", PzG::RR_Punktowy, 2);
       //
       //  Ustawienie trybu rysowania 2D, tzn. rysowany zbiór punktów
       //  znajduje się na wspólnej płaszczyźnie. Z tego powodu powoduj
       //  jako wspolrzedne punktow podajemy tylko x,y.
       //
       Lacze.ZmienTrybRys(PzG::TR_2D);
       cout << "Podaj wierzcholki prostokata: " << endl;
       for (int i = 0; i < 4; i++)
              cin >> wierz[i];

       Prostokat Pr(wierz[0], wierz[1], wierz[3], wierz[2]);
       WyswOpcje();

       while (wybor != 'k')
       {
              if (Pr.BokiRowne() == 0)
              {
                     cerr<<"Boki prostokata nie sa rowne!!!"<<endl;
              }
              if (!PrzykladZapisuWspolrzednychDoPliku("prostokat.dat", Pr))
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
                     Pr.obroc(kat * il_obrotow);
                     break;
              case 'p':
                     cout << "Podaj wektor przesuniecia: ";
                     cin >> Wektor;
                     Pr.przesun(Wektor);
                     break;
              case 'w':
                     cout << "Wierzcholki prostokata: " << endl;
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
