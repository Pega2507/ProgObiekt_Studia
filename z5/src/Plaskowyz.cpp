#include "Plaskowyz.hh"


void Plaskowyz::stworz_plaskowyz()
{
    std::vector<drawNS::Point3D> temp; //wierzcholki
    std::random_device losuj;
    std::default_random_engine generator(losuj());
    std::uniform_int_distribution<int> wierzcholki_ilosc(3,9);
    std::uniform_real_distribution<float> promien(min,max);
    int il_wierz = wierzcholki_ilosc(generator);
    double przyrost_kata = 360/il_wierz;
    double kat = 0;
    double wylosowane[9];
    UkladWsp tmp = licz_do_globalnego();

    for (int i=0; i<il_wierz; i++)
    {
        wylosowane[i] = promien(generator);
        Wektor<3> wek ({0,0,wylosowane[i]});
        wek = Macierz<3>(kat, 'Z')*wek;
        temp.push_back(konwertuj(tmp.licz_do_poprzedniego(wek)));
        kat += przyrost_kata;
    }
    wierzcholki.push_back(temp);
    temp.clear();
    for (int i=0; i<il_wierz; i++)
    {
        Wektor<3> wek({wylosowane[i],0,wysokosc});
        wek = Macierz<3>(kat, 'Z') * wek;
        temp.push_back(konwertuj(tmp.licz_do_poprzedniego(wek)));
        kat += przyrost_kata; //???
    }
    wierzcholki.push_back(temp);
}


void Plaskowyz::rysuj()
{
    if(obecne_id == -1)
    {
        obecne_id = api->draw_polyhedron(wierzcholki, "purple");

    }
}

void Plaskowyz::usun()
{
    std::cout<<"Usuwam plaskowyz"<<std::endl;
    api->erase_shape(obecne_id);
}

bool Plaskowyz::czy_nad()
{
    return true;
}

bool Plaskowyz::czy_ladowac()
{
    return true;
}

void Plaskowyz::wyswietl_srodek()
{
    std::cout<<srodek<<std::endl;
}
