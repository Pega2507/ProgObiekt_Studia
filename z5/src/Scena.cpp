#include "Scena.hh"
#include <algorithm>
using std::cout;
using std::cin;
using std::endl;

void Scena::dodaj_el_krajobrazu()
{ 
    cout << "Co chcesz dodac?"<<endl;
    cout << "1. Wzgoorze"<<endl;
    cout << "2. Plaskowyz"<<endl;
    cout << "3. Plaskowyz prostopadloscienny"<<endl;
    uint wybor;
    std::cout<< "Podaj swoj wybor: ";
    std::cin >> wybor;
    switch (wybor)
    {
    case 1:     //wzgorze
    {
        Wektor<3> t_sr;
        std::cout << "Podaj srodek: " <<endl;
        cin >> t_sr;
        t_sr[2]=-15;
        int min, max;
        double wysokosc;
        cout << "Podaj min, max i wysokosc: ";
        cin >> min >> max >> wysokosc;
        std::shared_ptr<Wzgorze> temp = std::make_shared<Wzgorze>(t_sr, wysokosc,min, max, api);
        kolekcja_krajobrazow.push_back(temp);
        kolekcja_narysowanych.push_back(temp);
        break;
    }
    case 2:     //plaskowyz
    {
        Wektor<3> t_sr;
        std::cout << "Podaj srodek: ";
        cin >> t_sr;
        t_sr[2]=-15;
        int min, max;
        double wysokosc;
        cout << "Podaj min, max i wysokosc: ";
        cin >> min >> max >> wysokosc;
        std::shared_ptr<Plaskowyz> temp = std::make_shared<Plaskowyz>(t_sr, wysokosc,min, max, api);
        kolekcja_krajobrazow.push_back(temp);
        kolekcja_narysowanych.push_back(temp);
        break;
    }
    case 3:     //plaskowyz prostopadloscienny
    {
        Wektor<3> t_sr;
        std::cout << "Podaj srodek: ";
        cin >> t_sr;
        t_sr[2]=-15;
        double szerokosc, glebokosc, wysokosc;
        cout << "Podaj szerokosc, glebokosc i wysokosc: ";
        cin >> szerokosc >> glebokosc >> wysokosc;
        std::shared_ptr<Plaskowyz_prost> temp = std::make_shared<Plaskowyz_prost>(t_sr, Macierz<3>(), nullptr, glebokosc, szerokosc, wysokosc, api);
        kolekcja_krajobrazow.push_back(temp);
        kolekcja_narysowanych.push_back(temp);
        break;
    }
    default:
    {
        cout<<"Niepoprawna opcja!"<<endl;
        break;
    }
    }

}


void Scena::usun_el_krajobrazu()
{   
    pokaz_el_krajobrazu();
    uint ind;
    cout << "Podaj id do usuniecia: ";
    cin >> ind;
    if (ind < kolekcja_krajobrazow.size() && !kolekcja_krajobrazow.empty() && !kolekcja_narysowanych.empty())
    {
        std::shared_ptr<Interfejs_krajobrazu> el_kraj = kolekcja_krajobrazow[ind];
        std::shared_ptr<Interfejs_rysowania> wsk_rys = std::dynamic_pointer_cast<Interfejs_rysowania>(el_kraj);
        wsk_rys->usun();
        kolekcja_narysowanych.erase(std::remove(kolekcja_narysowanych.begin(), kolekcja_narysowanych.end(),wsk_rys),kolekcja_narysowanych.end());
        kolekcja_krajobrazow.erase(kolekcja_krajobrazow.begin()+ind);
    }
}

void Scena::dodaj_drona()
{
    Wektor<3> t_sr;
    Macierz<3> t_or;
    std::shared_ptr<Dron> temp = std::make_shared<Dron>(t_sr, t_or, nullptr, api);
    kolekcja_dronow.push_back(temp);
    kolekcja_narysowanych.push_back(temp);

}
void Scena::usun_drona()
{
    pokaz_drony();
    uint ind;
    cout << "Podaj id do usuniecia: ";
    cin >> ind;
    if (ind < kolekcja_dronow.size() && !kolekcja_dronow.empty() && !kolekcja_narysowanych.empty())
    {
        std::shared_ptr<Interfejs_dron> el_dron = kolekcja_dronow[ind];
        std::shared_ptr<Interfejs_rysowania> wsk_rys = std::dynamic_pointer_cast<Interfejs_rysowania>(el_dron);
        wsk_rys->usun();
        kolekcja_narysowanych.erase(std::remove(kolekcja_narysowanych.begin(), kolekcja_narysowanych.end(),wsk_rys),kolekcja_narysowanych.end());
        kolekcja_dronow.erase(kolekcja_dronow.begin()+ind);
    }
}
void Scena::wybierz_drona()
{
    pokaz_drony();
    uint wybor;
    cout <<"wybierz drona: ";
    cin >> wybor;
    if (wybor > kolekcja_dronow.size())
    {
        cout <<"Niepoprawna opcja!";
    }
    else
    {
        aktywny_dron = kolekcja_dronow[wybor];
        cout <<"dron wybrany";
    }
    
    
}

void Scena::pokaz_el_krajobrazu()
{
    cout << "Elementy kraobrazu"<<endl;
    for (ulong j=0; j<kolekcja_krajobrazow.size(); j++) {
        cout<<"Srodek elementu: ";
        std::dynamic_pointer_cast<Interfejs_rysowania>(kolekcja_krajobrazow[j])->wyswietl_srodek();
        cout << std::endl;
    }
}
void Scena::pokaz_drony()
{
    for (ulong j=0; j<kolekcja_dronow.size(); j++) {
        cout<<"Srodek drona: ";
        std::dynamic_pointer_cast<Interfejs_rysowania>(kolekcja_dronow[j])->wyswietl_srodek();
        cout << std::endl;
    }
}