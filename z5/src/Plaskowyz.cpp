#include "Plaskowyz.hh"
#include "Interfejs_dron.hh"

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
        if (wylosowane[i]>max_promien)
            max_promien = wylosowane[i];
        Wektor<3> wek ({wylosowane[i],0,0});
        wek = Macierz<3>(kat, 'x')*wek;
        temp.push_back(konwertuj(tmp.licz_do_poprzedniego(wek)));
        kat += przyrost_kata;
    }
    wierzcholki.push_back(temp);
    temp.clear();
    for (int i=0; i<il_wierz; i++)
    {
        Wektor<3> wek({wylosowane[i],0,wysokosc});
        wek = Macierz<3>(kat, 'X') * wek;
        temp.push_back(konwertuj(tmp.licz_do_poprzedniego(wek)));
        kat += przyrost_kata; //???
    }
    wierzcholki.push_back(temp);
    promien_ksztaltu = max_promien;
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

bool Plaskowyz::czy_nad(std::shared_ptr<Interfejs_dron> d)
{
    Wektor<3> temp = std::dynamic_pointer_cast<Interfejs_rysowania>(d)->wyswietl_srodek();
    double odleglosc = sqrt(pow(srodek[0]-temp[2], 2)+pow(srodek[1]-temp[1], 2));
    if (odleglosc <= this -> get_promien()+std::dynamic_pointer_cast<Interfejs_krajobrazu>(d)->get_promien())
        return true;
    return false;

}

bool Plaskowyz::czy_ladowac(std::shared_ptr<Interfejs_dron> d, double &wys_ladowania)
{
    double min_distance = 0;
    Wektor<3> t_vec = std::dynamic_pointer_cast<Interfejs_rysowania>(d)->wyswietl_srodek();
    for (ulong i=0; i < wierzcholki2.size(); i++){
        double a,b,c; //Ax+By+C=0
        double temp = 0;
        if (i == wierzcholki2.size()-1) {
            a = wierzcholki2[i][1] - wierzcholki2[0][1];
            b = wierzcholki2[0][0] - wierzcholki2[i][0];
            c = wierzcholki2[0][1]*wierzcholki2[i][0] - wierzcholki2[i][1]*wierzcholki2[0][0];
            temp = fabs(a*srodek[0]+b*srodek[1]+c)/ sqrt(pow(a,2)+pow(b,2));
            if (temp > min_distance)
                min_distance = temp;
        } else {
            a = wierzcholki2[i][1] - wierzcholki2[i+1][1];
            b = wierzcholki2[i+1][0] - wierzcholki2[i][0];
            c = wierzcholki2[i+1][1]*wierzcholki2[i][0] - wierzcholki2[i][1]*wierzcholki2[i+1][0];
            temp = fabs(a*srodek[0]+b*srodek[1]+c)/ sqrt(pow(a,2)+pow(b,2));
            if (temp > min_distance)
                min_distance = temp;
        }
    }
    if (min_distance > sqrt(pow(t_vec[0]-srodek[0],2)+pow(t_vec[1]-srodek[1],2))){
        wys_ladowania = t_vec[2]-wierzcholki2[0][2]-d->lad_na_pdst();
        return true;
    } else {
        return false;
    }
}

Wektor<3> Plaskowyz::wyswietl_srodek()
{
    return srodek;
}
