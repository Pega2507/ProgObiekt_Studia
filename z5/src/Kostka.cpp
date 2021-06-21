#include "Kostka.hh"
#include <vector>
using drawNS::Point3D;

void Kostka::rysuj()
{   
    double w = wysokosc/2;
    double sz = szerokosc/2;
    double g = glebokosc/2;
    UkladWsp tmp = licz_do_globalnego();
    std::vector<drawNS::Point3D> temp;
    std::vector<std::vector<Point3D>> wierzcholki;
        temp.push_back(konwertuj(licz_do_poprzedniego(Wektor<3>({-sz, -w, -g}))));
        temp.push_back(konwertuj(licz_do_poprzedniego(Wektor<3>({sz, -w, -g}))));
        temp.push_back(konwertuj(licz_do_poprzedniego(Wektor<3>({sz, w, -g}))));
        temp.push_back(konwertuj(licz_do_poprzedniego(Wektor<3>({-sz, w, -g}))));
        wierzcholki.push_back(temp);
        temp.clear();
        temp.push_back(konwertuj(licz_do_poprzedniego(Wektor<3>({-sz, -w, g}))));
        temp.push_back(konwertuj(licz_do_poprzedniego(Wektor<3>({sz, -w, g}))));
        temp.push_back(konwertuj(licz_do_poprzedniego(Wektor<3>({sz, w, g}))));
        temp.push_back(konwertuj(licz_do_poprzedniego(Wektor<3>({-sz, w, g}))));
        wierzcholki.push_back(temp);
        
    if (obecne_id == -1)
    { 
        obecne_id = api->draw_polyhedron(wierzcholki, "purple");
    }
}

void Kostka::usun()
{
    if(obecne_id != -1)
    {
        std::cout <<"Usuwam kostke"<<std::endl;
        api->erase_shape(obecne_id);
        obecne_id = -1;

    }
}

Wektor<3> Kostka::wyswietl_srodek()
{
    return srodek;
}

/******************************************************/

void Kostka_dron::rysuj()
{
    double w = wysokosc/2;
    double sz = szerokosc/2;
    double g = glebokosc/2;
    //UkladWsp tmp = licz_do_globalnego();
    std::vector<drawNS::Point3D> temp;
    std::vector<std::vector<Point3D>> wierzcholki;
        temp.push_back(konwertuj(licz_do_poprzedniego(Wektor<3>({-sz, -w, -g}))));
        temp.push_back(konwertuj(licz_do_poprzedniego(Wektor<3>({sz, -w, -g}))));
        temp.push_back(konwertuj(licz_do_poprzedniego(Wektor<3>({sz, w, -g}))));
        temp.push_back(konwertuj(licz_do_poprzedniego(Wektor<3>({-sz, w, -g}))));
        wierzcholki.push_back(temp);
        temp.clear();
        temp.push_back(konwertuj(licz_do_poprzedniego(Wektor<3>({-sz, -w, g}))));
        temp.push_back(konwertuj(licz_do_poprzedniego(Wektor<3>({sz, -w, g}))));
        temp.push_back(konwertuj(licz_do_poprzedniego(Wektor<3>({sz, w, g}))));
        temp.push_back(konwertuj(licz_do_poprzedniego(Wektor<3>({-sz, w, g}))));
        wierzcholki.push_back(temp);
    if (obecne_id == -1)
    {
        obecne_id = api->draw_polyhedron(wierzcholki, "blue");
    }
    else
    {
        poprzednie_id = obecne_id;
        obecne_id = api->draw_polyhedron(wierzcholki, "blue");
    }
}

void Kostka_dron::usun()
{
    if(poprzednie_id != -1)
    {
        api->erase_shape(poprzednie_id);
        poprzednie_id = -1;
    }
    else
    {
        api->erase_shape(obecne_id);
        obecne_id = -1;
    }
}

Wektor<3> Kostka_dron::wyswietl_srodek()
{
    return srodek;
}