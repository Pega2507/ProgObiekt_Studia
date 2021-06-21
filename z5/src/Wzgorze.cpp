#include "Wzgorze.hh"
#include "Interfejs_dron.hh"

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
        if (r > max_promien)
            max_promien = r;
        Wektor<3> wek ({r,0,0});
        wek = Macierz<3>(kat, 'X')*wek;
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
    promien_ksztaltu = max_promien;
}



void Wzgorze::rysuj()
{
    if(obecne_id == -1)
    {
        obecne_id = api->draw_polyhedron(wierzcholki, "purple");
    }
}

void Wzgorze::usun()
{
    std::cout<<"Usuwam Wzgorze"<<std::endl;
    api->erase_shape(obecne_id);
}

bool Wzgorze::czy_nad(std::shared_ptr<Interfejs_dron> d)
{
    Wektor<3> temp = std::dynamic_pointer_cast<Interfejs_rysowania>(d)->wyswietl_srodek();
    double odleglosc = sqrt(pow(srodek[0]-temp[2], 2)+pow(srodek[1]-temp[1], 2));
    if (odleglosc <= this -> get_promien()+std::dynamic_pointer_cast<Interfejs_krajobrazu>(d)->get_promien())
        return true;
    return false;

}

bool Wzgorze::czy_ladowac(std::shared_ptr<Interfejs_dron> d, double &wys_ladowania)
{
    return false;
}

Wektor<3> Wzgorze::wyswietl_srodek()
{
    return srodek;
}