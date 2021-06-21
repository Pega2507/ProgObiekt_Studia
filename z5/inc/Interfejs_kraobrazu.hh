#ifndef INTERFEJS_KRAJ_HH
#define INTERFEJS_KRAJ_HH

#include "Interfejs_dron.hh"
class Interfejs_krajobrazu
{
protected:
    double promien_ksztaltu = 0;
public:
    double get_promien() const {return promien_ksztaltu;};
    virtual bool czy_nad(std::shared_ptr<Interfejs_dron> d) = 0;
    virtual bool czy_ladowac(std::shared_ptr<Interfejs_dron> d, double &wys_ladowania) = 0;
};


#endif