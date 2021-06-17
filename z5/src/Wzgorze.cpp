#include "Wzgorze.hh"

void Wzgorze::stworz_wzgorze()
{
    std::vector<drawNS::Point3D> temp; //wierzcholki
    std::random_device losuj;
    std::default_random_engine generator(losuj());
    std::uniform_int_distribution<int> wierzcholki_ilosc(3,9);
    std::uniform_real_distribution<float> promien(min,max);
    int il_wierz = wierzcholki_ilosc(generator);
    double przyrost_kata = 360/il_wierz;
    double kat = 0;
    UkladWsp tmp = licz_do_globalnego();
    for (int i=0; i<il_wierz; i++)
    {
        double r = promien(generator);
        Wektor<3> wek ({r,0,0});
        wek = Macierz<3>(kat, 'Z')*wek;
        temp.push_back(konwertuj(tmp.licz_do_poprzedniego(wek)));
        kat += przyrost_kata;
    }
    wierzcholki.push_back(temp);
    temp.clear();
    for (int i=0; i<il_wierz; i++)
    {
        temp.push_back(konwertuj(tmp.licz_do_poprzedniego(Wektor<3>({0,0,wysokosc}))));
        kat += przyrost_kata; //???
    }
    wierzcholki.push_back(temp);
}



void Wzgorze::rysuj()
{
    if(obecne_id == -1)
    {
        obecne_id = api->draw_polyhedron(wierzcholki, "black");
    }
}

void Wzgorze::usun()
{
    std::cout<<"Usuwam Wzgorze"<<std::endl;
    api->erase_shape(obecne_id);
}

bool Wzgorze::czy_nad()
{
    return true;
}

bool Wzgorze::czy_ladowac()
{
    return true;
}

void Wzgorze::wyswietl_srodek()
{
    std::cout << srodek;
}