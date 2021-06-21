#include "Scena.hh"
#include <algorithm>
using std::cout;
using std::cin;
using std::endl;

bool Scena::kolizja(double &dystans)
{
    std::vector<int> id_ksztaltow_bl_drona;
    std::shared_ptr<Interfejs_krajobrazu> ladowisko = std::dynamic_pointer_cast<Interfejs_krajobrazu> (aktywny_dron);
    for (uint i = 0; i<kolekcja_krajobrazow.size(); i++)
    {
        if (ladowisko != kolekcja_krajobrazow[i])
        {
            Wektor<3> temp1 = std::dynamic_pointer_cast<Interfejs_rysowania>(kolekcja_krajobrazow[i])->wyswietl_srodek();
            Wektor<3> temp2 = std::dynamic_pointer_cast<Interfejs_rysowania>(aktywny_dron)->wyswietl_srodek();
            double dyst = sqrt(pow(temp1[0]-temp2[0],2)+pow(temp1[1]-temp2[1],2));
            if (dyst < (kolekcja_krajobrazow[i]->get_promien()+ladowisko->get_promien()*1.2))
            {
                id_ksztaltow_bl_drona.push_back(i);
            }
                
        }
    }
    if (!id_ksztaltow_bl_drona.empty())
    {
        for (int i : id_ksztaltow_bl_drona)
        {
            if(!kolekcja_krajobrazow[i]->czy_nad(aktywny_dron))
                id_ksztaltow_bl_drona[i] = -1;
        }
        for (int i : id_ksztaltow_bl_drona)
        {
            if (i != -1)
            {
                if (!kolekcja_krajobrazow[i]->czy_ladowac(aktywny_dron, dystans))
                {
                     return false;
                }
                   
            }
        }
        return true;
        
    }
    else
    {
        dystans = std::dynamic_pointer_cast<Interfejs_rysowania>(aktywny_dron)->wyswietl_srodek()[2]+15-aktywny_dron->lad_na_pdst();
        return true;
    }
    
}


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
    cout << "Podaj srodek drona:";
    cin >> t_sr;
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
    cout <<"Aktywny dron to ten o srodku: ";
    std::dynamic_pointer_cast<Interfejs_rysowania>(aktywny_dron)->wyswietl_srodek();
    cout << endl<<"wybierz drona: ";
    cin >> wybor;
    if (wybor > kolekcja_dronow.size())
    {
        cout <<"Niepoprawna opcja!" << endl;
    }
    else
    {
        aktywny_dron = kolekcja_dronow[wybor-1];
        cout <<"dron wybrany"<<endl;
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