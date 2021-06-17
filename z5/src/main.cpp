#include "Draw3D_api_interface.hh"
#include "Dron.hh"
#include "Graniastoslup.hh"
#include "Kostka.hh"
#include "Macierz.hh"
#include "OpenGL_API.hh"
#include "Plaskowyz.hh"
#include "Scena.hh"
#include "Uklad.hh"
#include "Wektor.hh"
#include "Wzgorze.hh"
#include <iostream>

using namespace std;
#define ROZMIAR_OSI 30.0

void wyswietl_menu()
{
    cout << "Menu:"<<endl;
    cout << "d - dodaje drona"<<endl;
    cout << "c - wybiera aktywnego drona"<<endl;
    cout << "s - wyswietla kolekcje elementow plaszczyzny"<<endl;
    cout << "z - wyswietla kolekcje dronow"<<endl;
    cout << "l - dodaje element krajobrazu"<<endl;
    cout << "e - usuwa drona lub el_krajobrazu"<<endl;
    cout << "a - animacja"<<endl;
    cout << "u - lec w gore"<<endl;
    cout << "f - lec do przodu"<<endl;
    cout << "o - obroc wokol osi Z"<<endl;
    cout << "w - wyswietl dane ilosciowe wektorow"<<endl;
    cout << "m - wyswietla menu"<<endl;
    cout << "k - konczy dzialanie programu"<<endl;
    cout << "Twoj wybor?: ";
}

int main(int argc, char **argv)
{
    auto * api = new drawNS::APIopenGL3D(-ROZMIAR_OSI,ROZMIAR_OSI,-ROZMIAR_OSI,ROZMIAR_OSI,-ROZMIAR_OSI,ROZMIAR_OSI,0,&argc,argv);
    
    Scena s(api);
    s.rysuj_wszystko();
    double wysokosc, kat, odleglosc;
    char wybor;
    wyswietl_menu();
    cin >> wybor;
    
    while (wybor != 'k')
    {
        switch(wybor)
        {
            case 'd':
                s.dodaj_drona();
                s.rysuj_wszystko();
                break;
            case 'c':
                s.wybierz_drona();
                break;
            case 's':
                s.pokaz_el_krajobrazu();
                break;
            case 'z':
                s.pokaz_drony();
                break;
            case 'l':
                s.dodaj_el_krajobrazu();
                s.rysuj_wszystko();
                break;
            case 'e':
                int w;
                cout<<"1 - usun drona, 2 - usun element krajobrazu: ";
                cin >> w;
                if (w == 1)
                    s.usun_drona();
                else if (w == 2)
                    s.usun_el_krajobrazu();
                break;
            case 'a':
                cout << "Podaj wysokosc wznoszenia: ";
                cin >> wysokosc;
                cout << "Podaj kat obrotu drona (w stopniach): ";
                cin >> kat;
                cout << "Podaj odleglosc lotu do przodu: ";
                cin >> odleglosc;
                s.animuj(wysokosc, kat, odleglosc);
                break;
            case 'u':
                cout << "Podaj wysokosc: ";
                cin >> wysokosc;
                s.animuj(wysokosc,0,0);
                break;
            case 'f':
                cout << "Podaj dystans: ";
                cin >> odleglosc;
                s.animuj(0,0,odleglosc);
                break;
            case 'o':
                cout << "Podaj kat obrotu: ";
                cin >> kat;
                s.animuj (0,kat,0);
                break;
            case 'm':
                wyswietl_menu();
                break;
            case 'w':
                Wektor<3>::wyswietl_info();
                break;
            case 'k':
                cout<<"Koniec na dziś!"<<endl;
                break;
            default:
                cout<<"Niepoprawna opcja!"<<endl;
                break;
        }

        cin>>wybor;
    }
    delete api;
    return 0;

}