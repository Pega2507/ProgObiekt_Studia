#ifndef INTER_DRON_HH
#define INTER_DRON_HH

class Interfejs_dron
{
public:
    virtual void obrot_wirnikow() = 0;
    virtual void lot_gora(double) = 0;
    virtual void lot_przod(double) = 0;
    virtual void obrot_drona(double) = 0;
    virtual void animacja(double,double,double) = 0;
    virtual double lad_na_pdst() = 0; //nie jestem pewna co to robi i po co to jest
};


#endif