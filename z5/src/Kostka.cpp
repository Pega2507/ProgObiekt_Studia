#include "Kostka.hh"
#include <vector>
using drawNS::Point3D;

void Kostka::rysuj()
{
    double w = wysokosc/2;
    double sz = szerokosc/2;
    double g = glebokosc/2;
    std::vector<std::vector<Point3D>> wierzcholki {
        {konwertuj(licz_do_poprzedniego(Wektor<3>({-sz, -w, -g}))),
        konwertuj(licz_do_poprzedniego(Wektor<3>({sz, -w, -g}))),
        konwertuj(licz_do_poprzedniego(Wektor<3>({sz, w, -g}))),
        konwertuj(licz_do_poprzedniego(Wektor<3>({-sz, w, -g})))
        },{konwertuj(licz_do_poprzedniego(Wektor<3>({-sz, -w, -g}))),
        konwertuj(licz_do_poprzedniego(Wektor<3>({sz, -w, g}))),
        konwertuj(licz_do_poprzedniego(Wektor<3>({sz, w, g}))),
        konwertuj(licz_do_poprzedniego(Wektor<3>({-sz, w, g})))
        }};
    if (obecne_id == -1)
    {
        obecne_id = api->draw_polyhedron(wierzcholki, "black");
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

void Kostka::wyswietl_srodek()
{
    std::cout<<srodek<<std::endl;
}

/******************************************************/

void Kostka_dron::rysuj()
{
    double w = wysokosc/2;
    double sz = szerokosc/2;
    double g = glebokosc/2;
    std::vector<std::vector<Point3D>> wierzcholki {
        {konwertuj(licz_do_poprzedniego(Wektor<3>({-sz, -w, -g}))),
        konwertuj(licz_do_poprzedniego(Wektor<3>({sz, -w, -g}))),
        konwertuj(licz_do_poprzedniego(Wektor<3>({sz, w, -g}))),
        konwertuj(licz_do_poprzedniego(Wektor<3>({-sz, w, -g})))
        },{konwertuj(licz_do_poprzedniego(Wektor<3>({-sz, -w, -g}))),
        konwertuj(licz_do_poprzedniego(Wektor<3>({sz, -w, g}))),
        konwertuj(licz_do_poprzedniego(Wektor<3>({sz, w, g}))),
        konwertuj(licz_do_poprzedniego(Wektor<3>({-sz, w, g})))
        }};
    if (obecne_id == -1)
    {
        obecne_id = api->draw_polyhedron(wierzcholki, "black");
    }
    else
    {
        poprzednie_id = obecne_id;
        obecne_id = api->draw_polyhedron(wierzcholki, "black");
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

void Kostka_dron::wyswietl_srodek()
    {
        std::cout<<srodek<<std::endl;
    }