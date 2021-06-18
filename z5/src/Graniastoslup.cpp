#include "Graniastoslup.hh"
#include <cmath>

void Graniastoslup::rysuj()
{
    double R= promien/2;
    double w = wysokosc/2;
    double y = (promien*sqrt(3))/2;
    //UkladWsp = licz_do_globalnego();
    std::vector<std::vector<drawNS::Point3D>> wierzcholki {
        {konwertuj(licz_do_poprzedniego(Wektor<3>({-promien,0,-w}))),
        konwertuj(licz_do_poprzedniego(Wektor<3>({-R,-y,-w}))),
        konwertuj(licz_do_poprzedniego(Wektor<3>({R,-y,-w}))),
        konwertuj(licz_do_poprzedniego(Wektor<3>({promien,0,-w}))),
        konwertuj(licz_do_poprzedniego(Wektor<3>({R,y,-w}))),
        konwertuj(licz_do_poprzedniego(Wektor<3>({-R,y,-w})))
        },{konwertuj(licz_do_poprzedniego(Wektor<3>({-promien,0,w}))),
        konwertuj(licz_do_poprzedniego(Wektor<3>({-R,-y,w}))),
        konwertuj(licz_do_poprzedniego(Wektor<3>({R,-y,w}))),
        konwertuj(licz_do_poprzedniego(Wektor<3>({promien,0,w}))),
        konwertuj(licz_do_poprzedniego(Wektor<3>({R,y,w}))),
        konwertuj(licz_do_poprzedniego(Wektor<3>({-R,y,w})))
        },};
    if (obecne_id == -1)
    {
        obecne_id = api->draw_polyhedron(wierzcholki, "purple");
    }
    else
    {
        poprzednie_id = obecne_id;
        obecne_id = api->draw_polyhedron(wierzcholki, "purple");
    }
}

void Graniastoslup::usun()
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

void Graniastoslup::wyswietl_srodek()
{
    std::cout<<srodek<<std::endl;
}