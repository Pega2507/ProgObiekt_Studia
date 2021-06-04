#ifndef DRON_HH
#define DRON_HH

#include <iostream>

class Dron : public UkladW
{
private:
    /* data */
public:
    
};

class Prostopadloscian : public UkladW
{
    double dlugosc;
    double szerokosc;
    double wysokosc;
 public:
    Prostopadloscian(double dl, double szer, double wys, Wektor<3> srodek, MacierzObr<3> orientacja,
        UkladW *rodzic);
};

#endif