#ifndef RYSOWANIE_HH
#define RYSOWANIE_HH

#include "OpenGL_API.hh"

class Interfejs_rysowania
{
protected:
   drawNS::APIopenGL3D * api;
    int obecne_id = -1;
    int poprzednie_id = -1;
public:
    virtual void rysuj() = 0;
    virtual void usun() = 0;
    virtual void wyswietl_srodek() = 0; 
};


#endif